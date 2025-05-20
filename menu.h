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

/**
 * @brief funzione stampa menù
 */
void print_menu();

/**
 * @brief funzione per la stampa dell'elenco delle funzioni
 */
void print_menu_funzioni();

/**
 * @brief funzione per la stampa del vettore delle funzioni
 * @param list vettore delle funzioni (per reference)
 */
void print_list(vector<Function*> &list);

/**
 * @brief funzione per l'eliminazione di una funzione
 * @param list vettore delle funzioni (per reference)
 * @return true se l'operazione è andata a buon fine, altrimenti false
 */
bool elimina_funzione(vector<Function*> &list, int id);

/**
 * @brief funzione che valuta una funzione dato un valore in input
 * @param list vettore delle funzioni (per reference)
 * @param id id della funzione da valutare
 * @return true se l'operazione è andata a buon fine, altrimenti false
 */
bool valuta(vector<Function*> &list, int id);

/**
 * @brief funzione che legge da tastiera un valore e ne controlla la validità
 * @return il valore validato, altrimenti NaN
 */
int inserisci_ID();

/**
 * @brief funzione che controlla la conferma di un'azione
 * @return 1 se conferma, 0 se non conferma, altrimenti NaN
 */
int conferma_scelta();

/**
 * @brief funzione che controlla la validità di un certo input preso da tastiera (int)
 * @return il valore di ingresso controllato, altrimenti NaN
 */
int ins_checked_input_i();

/**
 * @brief funzione che controlla la validità di un certo input preso da tastiera (double)
 * @return il valore di ingresso controllato, altrimenti NaN
 */
double ins_checked_input_d();

/**
 * @brief funzione che permette di aggiungere funzioni all'array di funzioni
 * @param list vettore delle funzioni (per reference)
 */
void inserimento_funzione(vector<Function*> &list);

// template <typename T>
// bool inserisci_funzione(T funct, vector<Function*> &array);

#endif /* MENU_H */
