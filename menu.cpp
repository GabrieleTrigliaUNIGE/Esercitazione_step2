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
#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "menu.h"
#include <climits>
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

/**
 * @brief funzione per la stampa dell'elenco delle funzioni
 */
void print_menu_funzioni()
{
    cout << "\t==== MENU FUNZIONI ====" << endl;
    cout << "1 - POLINOMIO" << endl;
    cout << "2 - ESPONENZIALE" << endl;
    cout << "3 - LOGARITMO" << endl;
    cout << "\t=========================" << endl;
}

/**
 * @brief funzione per la stampa del vettore delle funzioni
 * @param list vettore delle funzioni (per reference)
 */
void print_list(vector<Function *> &list)
{
    if (list.size() == 0)
    {
        cout << "Lista vuota" << endl;
        return;
    }

    for (int i = 0; i < (int)list.size(); i++)
    {
        cout << i + 1 << ".  ";
        list.at(i)->Dump();
    }
}

/**
 * @brief funzione per l'eliminazione di una funzione
 * @param list vettore delle funzioni (per reference)
 * @return true se l'operazione è andata a buon fine, altrimenti false
 */
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
        if (id >= 0 && id < (int)list.size())
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

/**
 * @brief funzione che valuta una funzione dato un valore in input
 * @param list vettore delle funzioni (per reference)
 * @param id id della funzione da valutare
 * @return true se l'operazione è andata a buon fine, altrimenti false
 */
bool valuta(vector<Function *> &list, int id)
{
    string value_s;
    try
    { // fare funzione print_element(int id);
        list.at(id)->Dump();
    }
    catch (const exception &e)
    {
        cerr << "Array out of bound: Elemento non esistente";
        return false;
    }

    if (id >= 0 && id < (int)list.size())
    {
        cout << "Inserire valore di x: ";
        cin >> value_s;
        double value = stod(value_s);
        cout << "Funzione valutata in x=" << value << " : " << list.at(id)->GetValue(value) << endl;
    }
    return true;
}

/**
 * @brief funzione che legge da tastiera un valore e ne controlla la validità
 * @return il valore validato, altrimenti NaN
 */
int inserisci_ID()
{
    string id_s;
    cout << "Inserire ID: ";
    cin >> id_s;
    try
    {
        return stoi(id_s);
    }
    catch (const exception &e)
    {
        cerr << "ERROR: " << e.what() << " --> Valore non valido\n";
        return (int)NAN;
    }
}

/**
 * @brief funzione che controlla la conferma di un'azione
 * @return 1 se conferma, 0 se non conferma, altrimenti NaN
 */
int conferma_scelta()
{
    string conferma;
    cout << "Conferma? [0 -> no / 1 -> si]: "; // FARE FUNZIONE?
    cin >> conferma;
    try
    {
        return stoi(conferma);
    }
    catch (const exception &e)
    {
        cerr << "ERROR: " << e.what() << " --> Valore non valido\n";
        return (int)NAN;
    }
}

/**
 * @brief funzione che controlla la validità di un certo input preso da tastiera (int)
 * @return il valore di ingresso controllato, altrimenti NaN
 */
int ins_checked_input_i()
{
    string input;
    cin >> input;
    try
    {
        return stoi(input);
    }
    catch (const exception &e)
    {
        cerr << "ERROR: " << e.what() << " --> Valore non valido\n";
        return INT_MIN;
    }
}

/**
 * @brief funzione che controlla la validità di un certo input preso da tastiera (double)
 * @return il valore di ingresso controllato, altrimenti NaN
 */
double ins_checked_input_d()
{
    string input;
    cin >> input;
    try
    {
        return stod(input);
    }
    catch (const exception &e)
    {
        cerr << "ERROR: " << e.what() << " --> Valore non valido\n";
        return NAN;
    }
}

/**
 * @brief funzione che permette di aggiungere funzioni all'array di funzioni
 * @param list vettore delle funzioni (per reference)
 */
void inserimento_funzione(vector<Function *> &list)
{
    int scelta_funzione_i;
    cout << "Inserisci funzione" << endl;
    print_menu_funzioni();
    cout << "Inserisci scelta funzione: ";
    scelta_funzione_i = ins_checked_input_i();
    switch (scelta_funzione_i)
    {
    case 1:
    {

        cout << "=== Inserimento Polinomio ===" << endl;
        int grado;
        cout << "Inserire grado polinomio: ";
        grado = ins_checked_input_i();
        try
        {
            double *coeff = new double[grado + 1];

            for (int i = 0; i < grado + 1; i++)
            {
                cout << "Inserisci coefficiente grado " << i << endl;
                coeff[i] = ins_checked_input_d();
            }

            list.push_back(new Polynomial(coeff, grado + 1));

            list.back()->Dump();

            if (conferma_scelta() != 1)
                list.pop_back();

            delete coeff;
        }
        catch (const exception &e)
        {
            cout << "Errore allocazione: annulamento creazione Polinomio";
        }
        break;
    }
    case 2:
    {
        double base, esponente, k;
        cout << "=== Inserimento Esponenziale ===" << endl;
        cout << "Inserisci base: ";
        base = ins_checked_input_d();
        cout << "Inserisci esponente: ";
        esponente = ins_checked_input_d();
        cout << "Inserisci coefficiente k: ";
        k = ins_checked_input_d();

        list.push_back(new Exponential(base, esponente, k));
        list.back()->Dump();

        if (conferma_scelta() != 1)
            list.pop_back();

        break;
    }

    case 3:
    {
        double base, argomento;
        cout << "=== Inserimento Logaritmo ===" << endl;
        cout << "Inserisci base: ";
        base = ins_checked_input_d();
        cout << "Inserisci argomento: ";
        argomento = ins_checked_input_d();

        list.push_back(new Logarithmic(base, argomento));
        list.back()->Dump();

        if (conferma_scelta() != 1)
            list.pop_back();
        break;
    }

    default:
        cout << "Scelta non valida" << endl;
    }
}

// template <class T>
// bool inserisci_funzione(T funct, vector<Function*> &array) {
//     if(array.push_back(new T()))
//         return true;
//     else
//         return false;
// }
