/*! @file CPolynomial.h
	@brief A class for polynomial functions 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	Un polinomio (classe Polynomial) è formalizzato come c0 + c1x + c2x2 + ……. 

	La classe deve quindi prevedere le seguenti variabili membro:  

	int degree 	per memorizzare il grado del polinomio  

	double* coeff 	per memorizzare i coefficienti, a partire da c0
*/ 

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

/**
 * @class Polynomial
 * @brief Classe per le funzioni polinomio
 */
class Polynomial : public Function {
private:
    double* coeff;  											// puntatore ad array di double
    int degree; 												// grado del polinomio 

public:
	/// @name COSTRUTTORI e DISTRUTTORE
	/// @{
    Polynomial();  // costruttore di default 
	Polynomial(const double* coefficients, int size); 			// costruttore di default con passaggio di parametri 
    Polynomial(const Polynomial& p); 							// costruttore di copia 
    ~Polynomial();												// distruttore dei Polynomial
	/// @}

	/// @name OPERATORI 
	/// @{
    Polynomial& operator=(const Polynomial& p); 				// overload dell'operatore =
	bool operator==(const Polynomial& p); 						// overload dell'operatore ==
	/// @}

	void SetPolynomial(const double* coefficients, int size);	// SETTER per l'attributo
    double GetValue(double in);									// metodo che restituisce il valore del polinomio valutato in (in)
	
	void Reset();												// metodo per resettare l'oggetto

	/// @name DEBUG e SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 						// metodo che stampa gli errori
	void WarningMessage(const char *string);					// metodo che stampa i warning
	void Dump();												// metodo dump
	/// @}
};

#endif