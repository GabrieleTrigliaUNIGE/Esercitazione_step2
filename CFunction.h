/*! @file CFunction.h
	@brief Classe base per la gestione di funzioni a una variabile (function object)
	@author Gabriele Triglia matr.: 6440314 
    @author Alessio Marrazzo matr.: 6195070
*/ 

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/**
 * @class Function
 * @brief Classe Astratta per l'implementazione delle funzioni
 */
class Function {

public:  
	/// @name COSTRUTTORI e DISTRUTTORE
	/// @{
    Function(){};														// costruttore di default della generica funzione
    virtual ~Function(){};												// distruttore della generica funzione
	/// @}

	/// @name GETTERS
	/// @{
	virtual double GetValue(double in)=0;								// metodo che restituisce il valore di una generica funzione dato un valore in input
	/// @}

	/// @name DEBUG 
	/// @{
	virtual void Dump()=0;												// metodo che stampa lo stato di una funzione
    virtual void ErrorMessage(const char *string)=0; 					// metodo che stampa gli errori
	virtual void WarningMessage(const char *string)=0;					// metodo che stampa i warning
	/// @}
};

#endif
