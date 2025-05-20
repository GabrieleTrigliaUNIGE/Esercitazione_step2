/*! @file main.cpp
	@brief test file 
	@author Gabriele Triglia matr.: 6440314
	@author Alessio Marrazzo matr.: 6195070

	Details.
*/
#include <iostream>
#include "CFunction.h"
#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"

using namespace std;

/**
 * @brief main function
 * @return 0
 */
int main()
{
    cout << "FILE DI TEST" << endl;

    double cf1[7]={2.0,1.5,0,0,0,0,-1.0};
	double cf2[4]={-2.0,1.5,2.5,3.5};
    double cf3[3]={1.,2.,1.};
	
	Polynomial p0;
	Polynomial p1(cf1,7);
	Polynomial p2(cf2,4);
	Polynomial p3=p1;
    Function *f1 = new Polynomial(cf3, 3);

    Exponential e1(2,2,4);
    Exponential e2(0,3,4);
    Function *f2 = new Exponential(3,5,6);

    Logarithmic l1(2,2);
    Logarithmic l2(6,3);
    Function *f3 = new Logarithmic(3,5);
	
    cout << "\n\t\t\t--- INIZIO TEST POLINOMIO ---" << endl;
    cout << "Dump p0: ";
	p0.Dump();
    cout << "Dump p1: ";
	p1.Dump();
    cout << "Dump p2: ";
	p2.Dump();
    cout << "Dump p3: ";
	p3.Dump();
    cout << "Dump f1: ";
    f1->Dump();
	
    cout << "p0 == p1 ?: ";
	if (p0==p1) {
        cout << "vero" << endl;
    } else {
        cout << "falso" << endl;
    }

    cout << "p1 == p3 ?: ";
	if (p3==p1) {
        cout << "vero" << endl;
    } else {
        cout << "falso" << endl;
    }

    cout << "p3(5) = " << p3.GetValue(1.) << endl;
    
	p1.Reset(); 
    cout << "TEST reset p1: ";
	p1.Dump();
    // ERRORE CONTROLLARE ESISTENZA POLINOMIO IN GetValue(); --> cout << "p1(5) = " << p1.GetValue(1.) << endl; FATTO!!!

    cout << "\n\t\t\t--- FINE TEST POLINOMIO ---" << endl;
    cout << "\t\t\t--- INIZIO TEST ESPONENZIALE ---\n" << endl;

    cout << "Dump e1: ";
    e1.Dump();
    cout << "Dump e2: ";
    e2.Dump();
    cout << "Dump f2: ";
    f2->Dump();

    cout << "e1(1)=" << e1.GetValue(1) << endl;
    cout << "e2(1)=" << e2.GetValue(1) << endl;

    e2 = e1;

    e2.Dump();

    cout << "e1 == e2 ?: ";
    if (e1 == e2) { 
        cout << "vero" << endl;
    }
    
    cout << "e2(1)=" << e2.GetValue(1) << endl;

    e1.Reset(); 
    cout << "TEST reset e1: ";
	e1.Dump();

    cout << "\n\t\t\t--- FINE TEST ESPONENZIALE ---" << endl;
    cout << "\t\t\t--- INIZIO TEST LOGARITMO ---\n" << endl;

    cout << "Dump l1: ";
    l1.Dump();
    cout << "Dump l2: ";
    l2.Dump();
    cout << "Dump f3: ";
    f3->Dump();

    cout << "l1(3)=" << l1.GetValue(3) << endl;
    cout << "l2(3)=" << l2.GetValue(3) << endl;

    l2 = l1;

    l2.Dump();

    cout << "l1 == l2 ?: ";
    if (l1 == l2) { 
        cout << "vero" << endl;
    }
    
    cout << "l2(3)=" << l2.GetValue(3) << endl;

    l1.Reset(); 
    cout << "TEST reset e1: ";
	l1.Dump();

    cout << "\n\t\t\t--- FINE TEST LOGARITMO ---" << endl;
    cout << "\t\t\t--- FİNE FILE TEST ---\n" << endl;
    
    delete f1;
    delete f2;
    delete f3;
    return 0;
}
