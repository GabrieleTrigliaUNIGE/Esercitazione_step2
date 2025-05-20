/*! @file main.cpp
	@brief test file 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	Libreria menu gestione funzioni
*/

#include <iostream>
#include <vector>
#include "CFunction.h"
#ifndef MENU_H
#define MENU_H
using namespace std;

void print_menu();
void print_menu_funzioni();

template <typename T>
bool inserisci_funzione(T funct, vector<Function*> &array);

#endif /* MENU_H */
