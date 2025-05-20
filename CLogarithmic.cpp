/*! @file CLogarithmic.h
	@brief A class for logarithmic functions 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	La funzione logaritmica (classe Logarithmic) è formalizzata come  k×logbx, con b > 0 
    La classe deve quindi prevedere le seguenti variabili membro:  

    double b_coeff  	per memorizzare la base b del logaritmo
    double k_coeff	    per memorizzare il coefficiente k
*/
#include "CLogarithmic.h"
#include <iostream>
#include <cmath>
/**
 * @brief Costruttore della classe Logarithmic
 */
Logarithmic::Logarithmic() {
    Reset();
}

/**
 * @brief costruttore con tutti gli attributi
 * @param b base della funzione logaritmo
 * @param k coefficiente k della funzione logaritmo
 * @param c coefficiente c della funzione logaritmo
 */
Logarithmic::Logarithmic(double b, double k) {
    Reset();
    SetLogarithmic(b,k);
}

/**
 * @brief Costruttore di copia della classe Logarithmic
 * @param other oggetto Logarithmic da copiare
 */
Logarithmic::Logarithmic(Logarithmic& other) {

    if (other.b_coeff <= 0){
        ErrorMessage("CopyContructor: La base non può essere negativa o nulla");
        return;
    } 

    SetLogarithmic(other.b_coeff, other.k_coeff);

}

/**
 * @brief Distruttore della classe Logarithmic
 */
Logarithmic::~Logarithmic(){
    Reset();
}

/**
 * @brief Overload dell operatore = per la classe Logarithmic
 * @param other oggetto di tipo Logarithmic da copiare
 * @return l'oggetto Logarithmic copiato
 */
Logarithmic& Logarithmic::operator=(const Logarithmic& other){

    if (this != &other)
    {
        SetLogarithmic(other.b_coeff, other.k_coeff);
    }
    return *this;

}

/**
 * @brief Overload dell operatore == per la classe Logarithmic
 * @param other oggetto di tipo Logarithmic da confrontare
 * @return true se gli oggetti sono uguali, false altrimenti
 */
bool Logarithmic::operator==(const Logarithmic& other) {

    if(b_coeff != other.b_coeff || k_coeff != other.k_coeff)
        return false;
    else
        return true;

}

/**
 * @brief Funzione per resettare i coefficienti della funzione logaritmo
 */
void Logarithmic::Reset(){

    b_coeff=0;
    k_coeff=0;

}

/**
 * @brief Metodo Setter per impostare una funzione logaritmo
 * @param b base della funzione logaritmo
 * @param k coefficiente k della funzione logaritmo
 * @param c coefficiente c della funzione logaritmo
 */
void Logarithmic::SetLogarithmic(double b, double k) {

    if (b > 0) {
        b_coeff = b;
    } else {
        ErrorMessage("SetLogarithmic: La base non puo essere negativa o nulla");
        return;
    }
    k_coeff = k;

}

/**
 * @brief Funzione per stampare il valore della funzione logaritmo dato un valore in input
 * @param in valore in input
 * @return il valore della funzione logaritmo
 */
double Logarithmic::GetValue(double in) {

    if (b_coeff > 0)
    {
        return k_coeff*(log(in)/log(b_coeff));
    } else {
        ErrorMessage("GetValue: La base non puo essere negativa o nulla");
        return NAN;
    }
    
}

/**
 * @brief scrive un error message 
 * @param string messaggio da stampare
 */
void Logarithmic::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Logarithmic --";
	cout << string << endl;

}

/**
 * @brief scrive un warning message
 * @param string messaggio da stampare
 */
void Logarithmic::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Logarithmic --";
	cout << string << endl;

}

/**
 * @brief fornisce lo stato dell'oggetto
 */ 
void Logarithmic::Dump() {

    if(b_coeff > 0) {
        std::cout << "Dump: " << k_coeff << "*log" << b_coeff << "(x)" << std::endl;
    } else {
        std::cout << "Dump: Errore: Logaritmo a base negativa o nulla" << std::endl;
    }

}

