/*! @file main.cpp
    @brief test file
    @author Gabriele Triglia matr.: 6440314
    @author Alessio Marrazzo matr.: 6195070

    Interfaccia utente gestione funzioni
*/
#include <iostream>
#include <cstdlib>
#include "CFunction.h"
#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "menu.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @brief main function
 * @return 0
 */
int main()
{
    vector<Function *> functionList;
    int scelta;
    // TEST
    // Function *f = new Exponential(2, 2, 3);
    // functionList.push_back(f);

    do
    {
        print_menu();
        cout << "Inserisci scelta: ";
        scelta = ins_checked_input_i(); // controllo input
        switch (scelta)
        {
        case 0:
        {
            cout << "Uscita programma" << endl;
            break;
        }  

        case 1:
        {
            cout << "Stampa lista funzioni" << endl;
            print_list(functionList);
            break;
        }
            
        case 2:
        {
            int scelta_funzione_i;
            cout << "Inserisci funzione" << endl;
            print_menu_funzioni();
            cout << "Inserisci scelta funzione: ";
            scelta_funzione_i = ins_checked_input_i();
            switch (scelta_funzione_i)
            {
            case 1:
            {

                cout << "=== Inserimento Polinomio ===" << endl;
                int grado;
                cout << "Inserire grado polinomio: ";
                grado = ins_checked_input_i();
                double *coeff = new double[grado + 1];
                if (coeff)
                {
                    for (int i = 0; i < grado + 1; i++)
                    {
                        cout << "Inserisci coefficiente grado " << i << endl;
                        coeff[i] = ins_checked_input_d();
                    }

                    functionList.push_back(new Polynomial(coeff, grado + 1));
                } else {
                    cout << "FATAL: Impossibile allocare memoria";
                    exit(-1);
                }

                functionList.back()->Dump();

                if (conferma_scelta() != 1)
                    functionList.pop_back();

                delete coeff;
                break;
            }
            case 2:
            {
                double base, esponente, k;
                cout << "=== Inserimento Esponenziale ===" << endl;
                cout << "Inserisci base: ";
                base = ins_checked_input_d();
                cout << "Inserisci esponente: ";
                esponente = ins_checked_input_d();
                cout << "Inserisci coefficiente k: ";
                k = ins_checked_input_d();

                functionList.push_back(new Exponential(base, esponente, k));
                functionList.back()->Dump();

                if (conferma_scelta() != 1)
                    functionList.pop_back();

                break;
            }

            case 3:
            {
                double base, argomento;
                cout << "=== Inserimento Logaritmo ===" << endl;
                cout << "Inserisci base: ";
                base = ins_checked_input_d();
                cout << "Inserisci argomento: ";
                argomento = ins_checked_input_d();

                functionList.push_back(new Logarithmic(base, argomento));
                functionList.back()->Dump();

                if (conferma_scelta() != 1)
                    functionList.pop_back();
                break;
            }
            }

            break;
        }
        case 3:
        {
            cout << "Seleziona una funzione da eliminare" << endl;
            print_list(functionList);
            int id = inserisci_ID();

            if (elimina_funzione(functionList, id-1))
                cout << "funzione eliminata" << endl;       
            else
                cout << "funzione non eliminata" << endl;
            break;
        }

        case 4:
        {
            cout << "Elimina tutte le funzioni" << endl;
            functionList.clear();
            break;
        }

        case 5:
        {
            cout << "\n\t=== Seleziona una funzione ===" << endl;
            print_list(functionList);
            int id = inserisci_ID();
            valuta(functionList, id-1);
            break;
        }

        default:
        {
            cout << "Scelta non valida" << endl;
            break;
        }
        }
    } while (scelta != 0);

    return 0;
}
