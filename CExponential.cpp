/*! @file CExponential.cpp
	@brief Implementazione delle funzione esponenziale 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	La funzione esponenziale (classe Exponential) è formalizzata come  k×b^cx, con b > 0 
    La classe deve quindi prevedere le seguenti variabili membro:  

    double b_coeff  	per memorizzare la base b  
    double k_coeff	    per memorizzare il coefficiente k
    double c_coeff	    per memorizzare il coefficiente c
*/
#include "CExponential.h"
#include <iostream>
#include <cmath>
/**
 * @brief Costruttore della classe Exponential
 */
Exponential::Exponential() {
    Reset();
}

/**
 * @brief costruttore con tutti gli attributi
 * @param b base della funzione esponenziale
 * @param k coefficiente k della funzione esponenziale
 * @param c coefficiente c della funzione esponenziale
 */
Exponential::Exponential(double b, double k, double c) {
    Reset();
    SetExponential(b,k,c);
}

/**
 * @brief Costruttore di copia della classe Exponential
 * @param other oggetto Exponential da copiare
 */
Exponential::Exponential(Exponential& other) {

    if (other.b_coeff <= 0){
        ErrorMessage("CopyContructor: La base non può essere negativa o nulla");
        return;
    } 

    SetExponential(other.b_coeff, other.k_coeff, other.c_coeff);

}

/**
 * @brief Distruttore della classe Exponential
 */
Exponential::~Exponential(){
    Reset();
}

/**
 * @brief Overload dell operatore = per la classe Exponential
 * @param other oggetto di tipo Exponential da copiare
 * @return l'oggetto Exponential copiato
 */
Exponential& Exponential::operator=(const Exponential& other){

    if (this != &other)
    {
        SetExponential(other.b_coeff, other.k_coeff, other.c_coeff);
    }
    return *this;

}

/**
 * @brief Overload dell operatore == per la classe Exponential
 * @param other oggetto di tipo Exponential da confrontare
 * @return true se gli oggetti sono uguali, false altrimenti
 */
bool Exponential::operator==(const Exponential& other) {

    if(b_coeff != other.b_coeff || k_coeff != other.k_coeff || c_coeff != other.c_coeff)
        return false;
    else
        return true;

}

/**
 * @brief Funzione per resettare i coefficienti della funzione esponenziale
 */
void Exponential::Reset(){

    b_coeff=0;
    k_coeff=0;
    c_coeff=0;

}

/**
 * @brief Metodo Setter per impostare una funzione esponenziale
 * @param b base della funzione esponenziale
 * @param k coefficiente k della funzione esponenziale
 * @param c coefficiente c della funzione esponenziale
 */
void Exponential::SetExponential(double b, double k, double c) {

    if (b > 0) {
        b_coeff = b;
    } else {
        ErrorMessage("SetExponential: La base non puo essere negativa o nulla");
        return;
    }
    k_coeff = k;
    c_coeff = c;

}

/**
 * @brief Funzione per stampare il valore della funzione esponenziale dato un valore in input
 * @param in valore in input
 * @return il valore della funzione esponenziale
 */
double Exponential::GetValue(double in) {

    if (b_coeff > 0)
        return k_coeff * (pow(b_coeff, c_coeff*in));
    else
        return NAN; 
    
}

/**
 * @brief scrive un error message 
 * @param string messaggio da stampare
 */
void Exponential::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Exponential --";
	cout << string << endl;

}

/**
 * @brief scrive un warning message
 * @param string messaggio da stampare
 */
void Exponential::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Exponential --";
	cout << string << endl;

}

/**
 * @brief fornisce lo stato dell'oggeto
 */ 
void Exponential::Dump() {

    if(b_coeff > 0) {
        std::cout << "Dump: " << k_coeff << "*" << b_coeff << "^" << c_coeff << "x" << std::endl;
    } else {
        std::cout << "Dump: Esponenziale non inizializzato o con base negativa o nulla" << std::endl;
    }

}