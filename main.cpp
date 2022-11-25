#include <iostream>
#include "accstat.h"
#include <cstring>
#include <fstream>
#include <algorithm>
#include <sys/stat.h>
#include "node.h"
#include "list.h"
#define EXT ".csv"

using namespace std;

void exitErrNoData()
{
    cerr << "Nessun dato e' stato inserito, chiusura del programma.\n";
    exit(EXIT_FAILURE);
}

void loadFile(string idata, List<AccStat> &list)
{
    ifstream ifs(idata, ifstream::in);
    while (ifs.good())
    {
        AccStat s;
        ifs >> s;
        Node<AccStat> *temp = new Node<AccStat>(s);
        list.insert(temp);
    }
    ifs.close();
    // writeToFile(idata, list);
}

// int parseDisplaySize(string str)
// {
//     if (uint8_t(str[0]) <= 57 && uint8_t(str[0]) >= 48)
//         return stoi(str.substr(0, 2));
//     if (uint8_t(str[2]) <= 57 && uint8_t(str[2]) >= 48)
//         return stoi(str.substr(2, 2));
//     return -1; // errsize
// }

inline bool fileExists(const string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

string sanitizeFileName(string str) // filename must contain ".txt"
{
    if (str.find(EXT) != string::npos)
        return str;
    return str + EXT;
}

int main()
{
    List<AccStat> masterAccList;
    string file;
    do
    {
        cout << "Inserisci nome file da ordinare: ";
        cin >> file;
        if (!fileExists(sanitizeFileName(file)))
            cerr << "File non trovato: \'" << sanitizeFileName(file) << "\'\n";
    } while (!fileExists(sanitizeFileName(file)));
    loadFile(sanitizeFileName(file), masterAccList);
    // masterAccList.print();

    string name;
    cout << "Inserisci nome per ricerca: ";
    std::getline(std::cin >> std::ws, name);
    double sum = 0;
    int count = 0;
    cout << "\n***********\n";
    for (Node<AccStat> *app = masterAccList.getHead(); app != NULL; app = app->getNext())
    {
        if (app->getValue().getDescription() == name)
        {
            cout << "Trovata corrispondenza con valore " << app->getValue().getAmount() << "\n";
            sum += app->getValue().getAmount();
            cout << "Subtotale: " << sum << "\n";
            ++count;
        }
    }
    cout << "***********\nSomma totale: " << sum << "\n";
    cout << "Numero transazioni: " << count << "\n";
}