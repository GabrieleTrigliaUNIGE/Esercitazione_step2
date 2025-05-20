/*! @file main.cpp
	@brief test file 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	Implementazione menu gestione funzioni
*/

#include <iostream>
#include <vector>
#include "CFunction.h"
#include "menu.h"
using namespace std;

/**
 * @brief funzione stampa menù
 */
void print_menu() {
    cout << "\t\t\t==== MENU PRINCIPALE ====" << endl;
    cout << "0 - Esci dal menu" << endl;
    cout << "1 - Visualizza la lista delle funzioni" << endl;
    cout << "2 - Inserisci una funzione" << endl;
    cout << "3 - Elimina una funzione" << endl;
    cout << "4 - Elimina tutte le funzioni" << endl;
    cout << "5 - Seleziona una funzione" << endl;
    cout << "\t\t\t=========================" << endl;
}

void print_menu_funzioni() {
    cout << "\t\t\t==== MENU FUNZIONI ====" << endl;
    cout << "1 - POLINOMIO" << endl;
    cout << "2 - ESPONENZIALE" << endl;
    cout << "3 - LOGARITMO" << endl;
    cout << "\t\t\t=========================" << endl;
}

template <class T>
bool inserisci_funzione(T funct, vector<Function*> &array) {
    if(array.push_back(new T()))
        return true;
    else
        return false;
}