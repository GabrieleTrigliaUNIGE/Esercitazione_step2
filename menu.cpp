/*! @file main.cpp
    @brief test file
    @author Gabriele Triglia matr.: 6440314
    @author Alessio Marrazzo matr.: 6195070

    Implementazione menu gestione funzioni
*/

#include <iostream>
#include <vector>
#include <string>
#include "CFunction.h"
#include "menu.h"
using namespace std;

/**
 * @brief funzione stampa menù
 */
void print_menu()
{
    cout << "\t\t\t==== MENU PRINCIPALE ====" << endl;
    cout << "0 - Esci dal menu" << endl;
    cout << "1 - Visualizza la lista delle funzioni" << endl;
    cout << "2 - Inserisci una funzione" << endl;
    cout << "3 - Elimina una funzione" << endl;
    cout << "4 - Elimina tutte le funzioni" << endl;
    cout << "5 - Seleziona una funzione" << endl;
    cout << "\t\t\t=========================" << endl;
}

void print_menu_funzioni()
{
    cout << "\t==== MENU FUNZIONI ====" << endl;
    cout << "1 - POLINOMIO" << endl;
    cout << "2 - ESPONENZIALE" << endl;
    cout << "3 - LOGARITMO" << endl;
    cout << "\t=========================" << endl;
}

void print_list(vector<Function *> &list)
{
    if (list.size() == 0)
    {
        cout << "Lista vuota" << endl;
        return;
    }

    for (int i = 0; i < list.size(); i++)
    {
        cout << i + 1 << ".\t";
        list.at(i)->Dump();
    }
}

bool elimina_funzione(vector<Function *> &list, int id)
{
    string conf_s;
    try
    {
        list.at(id)->Dump();
    }
    catch (const exception &e)
    {
        cerr << "Array out of bound: " << e.what() << '\n';
        return false;
    }

    cout << "Vuoi eliminare questa funzione? [0 -> no / 1 -> si]: ";
    cin >> conf_s;
    int conf = stoi(conf_s);
    bool ret;

    if (conf)
    {
        if (id >= 0 && id < list.size())
        {
            list.erase(list.begin() + id);
            ret = true;
        }
        else
        {
            cout << "ID funzione non corretto" << endl;
            ret = false;
        }
    }
    else
        ret = false;
    return ret;
}

bool valuta(vector<Function *> &list, int id)
{
    string value_s;
    try
    { // fare funzione print_element(int id);
        list.at(id)->Dump();
    }
    catch (const exception &e)
    {
        cerr << "Array out of bound: " << e.what() << '\n';
        return false;
    }

    if (id > 0 && id < list.size())
    {
        cout << "Inserire valore di x: ";
        cin >> value_s;
        double value = stod(value_s);
        cout << "Funzione valutata in x=" << value << " : " << list.at(id)->GetValue(value);
    }
    return true;
}

// template <class T>
// bool inserisci_funzione(T funct, vector<Function*> &array) {
//     if(array.push_back(new T()))
//         return true;
//     else
//         return false;
// }