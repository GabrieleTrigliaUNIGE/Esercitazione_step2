/*! @file CExponential.h
	@brief A class for exponential functions 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070
    
	La funzione esponenziale (classe Exponential) è formalizzata come  k×bcx, con b > 0 
    La classe deve quindi prevedere le seguenti variabili membro:  

    double b_coeff  	per memorizzare la base b  
    double  k_coeff	per memorizzare il coefficiente k
    double  c_coeff	per memorizzare il coefficiente c 
*/
#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H
#include "CFunction.h"

/**
 * @class Exponential
 * @brief A class for exponential functions
 */
class Exponential : public Function{
private:
    double b_coeff;                                             // per memorizzare la base b
    double k_coeff;                                             // per memorizzare il coefficiente k
    double c_coeff;                                             // per memorizzare il coefficiente c

public:

    /// @name COSTRUTTORI e DISTRUTTORE 
	/// @{
    Exponential();                                              // costruttore di default
    Exponential(Exponential& other);                            // costruttore di copia
    Exponential(double b, double k, double c);                  // costruttore con tutti gli attributi
    ~Exponential();
    /// @}

    /// @name OPERATORI
	/// @{
    Exponential& operator=(const Exponential& other);           // overload dell'operatore =
    bool operator==(const Exponential& other);                  // overload dell'operatore ==
    /// @}

    void SetExponential(double b, double k, double c);          // metodo setter che imposta i coefficienti per l'esponenziale
    double GetValue(double in);                                 // metodo che valuta l'esponenziale in un valore (in) dato in input

    void Reset();
    
    /// @name DEBUG e SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 						// metodo che stampa gli errori
	void WarningMessage(const char *string);					// metodo che stampa i warning
	void Dump();												// metodo dump
	/// @}
};

#endif /* EXPONENTIAL_H */
