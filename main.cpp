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
        scelta = ins_checked_input_i();
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
            inserimento_funzione(functionList);
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
