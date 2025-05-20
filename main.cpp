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
    string scelta; // ATTENZIONE INPUT CONTROLLARE!!!  
    int scelta_i;
    string scelta_funzione; // fare funzione che controlla input
    int scelta_funzione_i;
    string conferma_s;
    string id_s;

    // TEST
    // Function *f = new Exponential(2, 2, 3);
    // functionList.push_back(f);

    do
    {
        print_menu();
        cout << "Inserisci scelta: ";
        cin >> scelta;
        scelta_i = stoi(scelta); // controllo input
        switch (scelta_i)
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
            cout << "Inserisci funzione" << endl;
            print_menu_funzioni();
            cout << "Inserisci scelta funzione: ";
            cin >> scelta_funzione;
            scelta_funzione_i = stoi(scelta_funzione); // contorllo input
            switch (scelta_funzione_i)
            { // MIGLIORARE CON FUNZIONE
            case 1:
            {

                cout << "=== Inserimento Polinomio ===" << endl;
                int grado;
                cout << "Inserire grado polinomio: ";  // controllo inputs
                cin >> grado;
                double *coeff = new double[grado + 1];
                if (coeff)
                {
                    for (int i = 0; i < grado + 1; i++)
                    {
                        cout << "Inserisci coefficiente grado " << i << endl;
                        cin >> coeff[i];
                    }

                    functionList.push_back(new Polynomial(coeff, grado + 1));
                } else {
                    cout << "FATAL: Impossibile allocare memoria";
                    exit(-1);
                }

                functionList.back()->Dump();
                cout << "Conferma? [0 -> no / 1 -> si]: "; // FARE FUNZIONE?
                cin >> conferma_s;
                int conferma = stoi(conferma_s);

                if (conferma != 1)
                    functionList.pop_back();

                delete coeff;
                break;
            }
            case 2:
            {
                cout << "=== Inserimento Esponenziale ===" << endl;
                double base, esponente, k;
                cout << "Inserisci base: ";
                cin >> base;
                cout << "Inserisci esponente: ";
                cin >> esponente;
                cout << "Inserisci coefficiente k: ";
                cin >> k;

                functionList.push_back(new Exponential(base, esponente, k));
                functionList.back()->Dump();

                cout << "Conferma? [0 -> no / 1 -> si]: "; // FARE FUNZIONE?
                cin >> conferma_s;
                int conferma = stoi(conferma_s);

                if (conferma != 1)
                    functionList.pop_back();

                break;
            }

            case 3:
            {
                cout << "=== Inserimento Logaritmo ===" << endl;
                double base, argomento;
                cout << "Inserisci base: ";
                cin >> base;
                cout << "Inserisci argomento: ";
                cin >> argomento;

                functionList.push_back(new Logarithmic(base, argomento));
                functionList.back()->Dump();

                cout << "Conferma? [0 -> no / 1 -> si]: "; // FARE FUNZIONE?
                cin >> conferma_s;
                int conferma = stoi(conferma_s);

                if (conferma != 1)
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
            cout << "Inserire ID: ";  // funzione ID
            cin >> id_s;
            int id = stoi(id_s);

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
            cout << "Inserire ID: ";  // fare funzione ID
            cin >> id_s;
            int id = stoi(id_s);
            valuta(functionList, id-1);
            break;
        }

        default:
        {
            cout << "Scelta non valida" << endl;
            break;
        }
        }
    } while (scelta_i != 0);

    return 0;
}
