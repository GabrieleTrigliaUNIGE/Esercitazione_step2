/*! @file CPolynomial.cpp
	@brief Implementation for polynomial functions 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	Un polinomio (classe Polynomial) è formalizzato come c0 + c1x + c2x2 + ……. 

	La classe deve quindi prevedere le seguenti variabili membro:  

	int degree 	per memorizzare il grado del polinomio  

	double* coeff 	per memorizzare i coefficienti, a partire da c0  
*/

#include "CPolynomial.h"

/**
 * @brief costruttore di default (polinomio non sensato)
 */
Polynomial::Polynomial() {
	degree=-1;
	coeff = NULL;
}


/**
 * @brief costruttore con tutti gil attributi per la classe Polynomial
 * @param coefficients array coi coefficienti (formato: c0+c1*x+ ...)
 * @param size dimensione dell'array
 */
Polynomial::Polynomial(const double* coefficients, int size) {
	degree = -1;
	coeff = NULL;
	SetPolynomial(coefficients,size);
}

/**
 * @brief distruttore per la classe Polynomial
 */
Polynomial::~Polynomial() {
    
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/**
 * @brief costruttore di copia per la classe Polynomial
 */
Polynomial::Polynomial(const Polynomial& p) {
	
	int i;
	
	if (p.coeff == NULL) {
		ErrorMessage("Costruttore di copia: l'oggetto da copiare non ha coefficienti");
		exit(-1);
	}
	degree = p.degree;
	coeff = new double[degree + 1];
	if (coeff == NULL) {
		ErrorMessage("Costruttore di copia: impossibile allocare memoria");
		exit(-1);
	}
	
    for (i=0;i<=degree;i++)
		coeff[i]= p.coeff[i];
}

/**
 * @brief Overload dell'operatore = per la classe Polynomial
 * @param p l'oggetto di tipo Polynomial da copiare
 * @return l'oggetto copiato
 */
Polynomial& Polynomial::operator=(const Polynomial& p) {
    
	int i; 
	
	if (this != &p) {
		if (coeff != NULL)
			delete coeff;
        degree = p.degree;
        coeff = new double[degree + 1];
		if (coeff == NULL) {
			ErrorMessage("Operatore = : impossibile allocare memoria");
			exit(-1);
		}
        for (i=0;i<=degree;i++)
			coeff[i]= p.coeff[i];
    }
    return *this;
}

/**
 * @brief Overload dell operatore == per la classe Polynomial
 * @param p oggetto di tipo Polynomial da confrontare
 * @return true se gli oggetti sono uguali, false altrimenti
 */
bool Polynomial::operator==(const Polynomial& p) {
	
	int i;
	
	if (degree != p.degree)
		return false;
	
	for (i=0; i<=degree; i++) {
		if (coeff[i] != p.coeff[i])
			return false;
	}
	
	return true;
	
}

/**
 * @brief imposta i coefficienti del polinomio
 * @param coefficients array coi coefficienti (formato: c0+c1*x+ ...)
 * @param size dimensione dell'array
 */
void Polynomial::SetPolynomial(const double* coefficients, int size) {
	
	int i=0;
	
	if (size < 1) {
		ErrorMessage("SetPolynomial: il grado del polinomio non può essere negativo");
		exit(-1);
	}
	
	if (coeff != NULL)
		Reset();
	
	degree = size - 1;
    coeff = new double[size]; // restituisce double* dove 
	if (coeff == NULL) {
		ErrorMessage("SetPolynomial: impossibile allocare memoria");
		exit(-1);
	}
	
	for (i=0; i<=degree; i++)
		coeff[i] = coefficients[i];
	
}

/**
 * @brief returns the value of the function, given an input
 * @param in the input
 * @return the value of the function
 */
double Polynomial::GetValue(double in) {
    int i;
	double x = in;
	double result = 0.0;
    
	if (degree == -1) {
		cout << "Polinopmio non inizializzato" << endl;
		return -1.;
	}
	
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "Nessun coefficiente inserito" << endl;
		return -1.;
	}

	result = coeff[0];
	for (i=1; i<=degree; i++) {
		result += coeff[i]*x;
		x *= in;			/* x^i */
	}
        
	return result;
}

/**
 * @brief resets the polynomial
 */ 
void Polynomial::Reset() {
	
	degree = -1; 
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/**
 * @brief scrive un error message 
 * @param string messaggio da stampare
 */
void Polynomial::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Polynomial --";
	cout << string << endl;

}

/**
 * @brief scrive un warning message
 * @param string messaggio da stampare
 */ 
void Polynomial::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Polynomial --";
	cout << string << endl;

}

/**
 * @brief fornisce lo stato dell'oggetto
 */ 
void Polynomial::Dump() {

	int i;
	
	if (degree == -1) {
		cout << "Polinopmio non inizializzato" << endl;
		return;
	}
	
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "Nessun coefficiente inserito" << endl;
		return;
	}
	
    for (i = 0; i <= degree; ++i) {
		if (coeff[i] != 0.) {
			cout << (coeff[i] > 0 && i > 0 ? " +" : " ") << coeff[i];
            if (i > 0) {
                cout << "x";
                if (i > 1) 
                    cout << "^" << i;
            }
        }
    }
	cout << endl;
}
