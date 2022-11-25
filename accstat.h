#include <fstream>
#include <string>
using std::cout;
using std::endl;

class AccStat
{
private:
    std::string type;
    std::string product;
    std::string startdate;
    std::string compdate;
    std::string description;
    double amount;
    double fee;
    std::string currency;
    std::string state;
    double balance;

public:
    // constructors
    AccStat(std::string _type, std::string _product, std::string _start_date, std::string _comp_date, std::string _description, double _amount, double _fee, std::string _currency,
            std::string _state, double _balance) : type(_type), product(_product), startdate(_start_date), compdate(_comp_date), amount(_amount), fee(_fee),
                                                   currency(_currency), state(_state), balance(_balance) {}
    AccStat() : AccStat("undefined", "undefined", "undefined", "undefined", "undefined", 0, 0, "undefined", "undefined", 0) {}

    std::string getType()
    {
        return this->type;
    }
    std::string getProduct()
    {
        return this->product;
    }
    std::string getStartdate()
    {
        return this->startdate;
    }
    std::string getCompdate()
    {
        return this->compdate;
    }
    std::string getDescription()
    {
        return this->description;
    }
    double getAmount()
    {
        return this->amount;
    }
    double getFee()
    {
        return this->fee;
    }
    std::string getCurrency()
    {
        return this->currency;
    }
    std::string getState()
    {
        return this->state;
    }
    double getBalance()
    {
        return this->balance;
    }

    void setType(std::string _type)
    {
        this->type = _type;
    }
    void setProduct(std::string _product)
    {
        this->product = _product;
    }
    void setStartdate(std::string _startdate)
    {
        this->startdate = _startdate;
    }
    void setCompdate(std::string _compdate)
    {
        this->compdate = _compdate;
    }
    void setDescription(std::string _description)
    {
        this->description = _description;
    }
    void setAmount(double _amount)
    {
        this->amount = _amount;
    }
    void setFee(double _fee)
    {
        this->fee = _fee;
    }
    void setCurrency(std::string _currency)
    {
        this->currency = _currency;
    }
    void setState(std::string _state)
    {
        this->state = _state;
    }
    void setBalance(double _balance)
    {
        this->balance = _balance;
    }

    // friend ostream &operator<<(ostream &out, const AccStat &app)
    // {
    //     out << "EAN: " << app.ean << ", ";
    //     out << "MARCA: " << app.brand << ", ";
    //     out << "MODELLO: " << app.model << ", ";
    //     out << "SCART: ";
    //     if (app.scart)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "API: ";
    //     if (app.api)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "API_APERTE: ";
    //     if (app.apio)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "TERRESTRE: ";
    //     if (app.terrestrial)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "DVB-T2: ";
    //     if (app.t2)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "HEVC: ";
    //     if (app.hevc)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "SATELLITARE: ";
    //     if (app.satellite)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     out << ", ";
    //     out << "VIA_CAVO: ";
    //     if (app.cable)
    //         out << "SI";
    //     else
    //         out << "NO";
    //     return out;
    // }
    // bool isTrue(std::string k)
    // {
    //     if (k == "n/a" || k == "NO")
    //         return 0;
    //     return 1;
    // }

    friend std::istream &operator>>(std::istream &in, AccStat &p)
    {
        std::string type;
        std::string product;
        std::string startdate;
        std::string compdate;
        std::string description;
        std::string amount; // to double
        std::string fee;    // to double
        std::string currency;
        std::string state;
        std::string balance; // to double

        getline(in, type, ',');
        getline(in, product, ',');
        getline(in, startdate, ',');
        getline(in, compdate, ',');
        getline(in, description, ',');
        getline(in, amount, ',');
        getline(in, fee, ',');
        getline(in, currency, ',');
        getline(in, state, ',');
        getline(in, balance, '\n');

        // cout << balance << endl;

        p.setType(type);
        p.setProduct(product);
        p.setStartdate(startdate);
        p.setCompdate(compdate);
        p.setDescription(description);
        p.setAmount(stod(amount));
        p.setFee(stod(fee));
        p.setCurrency(currency);
        p.setState(state);
        p.setBalance(stod(balance));

        return in;
    }
    // bool operator==(const AccStat &s) const
    // {
    //     return this->product == s.model;
    // }
};