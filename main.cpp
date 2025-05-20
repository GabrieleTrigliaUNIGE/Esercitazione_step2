/*! @file main.cpp
    @brief test file
    @author Gabriele Triglia matr.: 6440314
    @author Alessio Marrazzo matr.: 6195070

    Interfaccia utente gestione funzioni
*/
#include <iostream>
#include "CFunction.h"
#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "menu.h"
#include <vector>

using namespace std;

/**
 * @brief main function
 * @return 0
 */
int main()
{
    vector<Function *> functionList;
    int scelta = 0; // ATTENZIONE INPUT CONTROLLARE!!!
    int scelta_funzione = 0;
    Function *f = new Exponential(2, 2, 3);

    functionList.push_back(f);

    print_menu();
    do
    {
        cout << "Inserisci scelta: ";
        cin >> scelta;
        switch (scelta)
        {
        case 0:
            cout << "Uscita programma" << endl;
            break;

        case 1:
            cout << "Stampa lista funzioni" << endl;
            for (int i = 0; i < functionList.size(); i++)
            {
                functionList.at(i)->Dump();
            }
            break;

        case 2:

            cout << "Inserisci funzione" << endl;
            print_menu_funzioni();
            cout << "Inserisci scelta funzione: ";
            cin >> scelta_funzione;
            switch (scelta_funzione)
            { // MIGLIORARE CON FUNZIONE
            case 1:

                cout << "=== Inserimento Polinomio ===" << endl;
                int grado;
                cout << "Inserire grado polinomio: ";
                cin >> grado;
                double *coeff = new double[grado + 1];
                for (int i = 0; i < grado + 1; i++)
                {
                    cout << "Inserisci coefficiente grado " << i << endl;
                    cin >> coeff[i];
                }

                functionList.push_back(new Polynomial(coeff, grado+1));

                functionList.back()->Dump();
                int conferma;
                cout << "Conferma? [0 -> no / 1 -> si]: ";
                cin >> conferma;

                if ( conferma != 1 )
                    functionList.pop_back();
                
                delete coeff;
                break;
            }

            break;

        case 3:
            cout << "Elimina una funzione" << endl;
            break;

        case 4:
            cout << "Elimina tutte le funzioni" << endl;
            break;

        case 5:
            cout << "Seleziona una funzione" << endl;
            break;

        default:
            cout << "Scelta non valida" << endl;
            break;
        }
    } while (scelta != 0);

    return 0;
}
