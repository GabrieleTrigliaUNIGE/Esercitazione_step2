/*! @file CLogarithmic.h
	@brief A class for logarithmic functions 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	La funzione logaritmica (classe Logarithmic) è formalizzata come  k×logbx, con b > 0 
    La classe deve quindi prevedere le seguenti variabili membro:  

    double b_coeff  	per memorizzare la base b del logaritmo
    double k_coeff	    per memorizzare il coefficiente k
*/
#ifndef LOGARITHMIC_H
#define LOGARITHMIC_H
#include "CFunction.h"

/**
 * @class Logarithmic
 * @brief A class for logarithmic functions
 */
class Logarithmic : public Function {
private:
    double b_coeff;                                             // per memorizzare la base b
    double k_coeff;                                             // per memorizzare il coefficiente k

public:

    /// @name COSTRUTTORI e DISTRUTTORE 
	/// @{
    Logarithmic();                                              // costruttore di default della classe Logarithmic
    Logarithmic(Logarithmic& other);                            // costruttore di copia della classe Logarithmic
    Logarithmic(double b, double k);                            // costruttori con tutti gli attributi della classe Logarithmic
    ~Logarithmic();                                             // distruttore della classe Logarithmic
    /// @}

    /// @name OPERATORI
	/// @{
    Logarithmic& operator=(const Logarithmic& other);           // overload dell'operatore =
    bool operator==(const Logarithmic& other);                  // overload dell'operatore ==
    /// @}

    void SetLogarithmic(double b, double k);                    // metodo setter che imposta i coefficienti della logaritmica
    double GetValue(double in);                                 // metodo che restutuisce il valore di una logaritmica dato un lavore (in) in input

    void Reset();
    
    /// @name DEBUG e SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 						// metodo che stampa gli errori
	void WarningMessage(const char *string);					// metodo che stampa i warning
	void Dump();												// metodo dump
	/// @}
};

#endif /* LOGARITHMIC_H */

