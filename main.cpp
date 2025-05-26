/*! @file main.cpp
    @brief test file
    @author Gabriele Triglia matr.: 6440314
    @author Alessio Marrazzo matr.: 6195070

    Interfaccia utente gestione funzioni
*/
#include <iostream>
#include "CFunction.h"
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
    int scelta;
    // int id; // SE DEFINISCO QUA id POSSO TOGLIERE LA RIDEFINIZIONE DELLO SCOPE NEL CASE
    // TEST
    // Function *f = new Exponential(2, 2, 3);
    // functionList.push_back(f);
    cout << "\t=== GESTIONE FUNZIONI ===\nBenvenuto.\n"
         << endl;

    do
    {
        print_menu();
        cout << "Inserisci scelta: \n>_ ";
        scelta = ins_checked_input_i();
        switch (scelta)
        {
        case 0:
        {
            cout << "\t=== Uscita programma ===\n"
                 << endl;
            cout << "Arrivederci." << endl;
            break;
        }

        case 1:
        {
            cout << "\t=== Stampa lista funzioni ===\n"
                 << endl;
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
            cout << "\t=== Seleziona una funzione da eliminare ===\n"
                 << endl;

            if (functionList.size() == 0)
            {
                cout << "Lista funzioni vuota: \nInserisci una funzione prima!\n"
                     << endl;
            }
            else
            {
                print_list(functionList);
                int id = inserisci_ID();

                if (elimina_funzione(functionList, id - 1))
                    cout << "funzione eliminata" << endl;
                else
                    cout << "funzione non eliminata" << endl;
            }
            break;
        }

        case 4:
        {
            cout << "\t=== Elimina tutte le funzioni ===\n"
                 << endl;
            functionList.clear();
            cout << "tutte le funzioni sono state eliminate\n"
                 << endl;
            break;
        }

        case 5:
        {
            cout << "\t=== Seleziona una funzione ===\n"
                 << endl;
            if (functionList.size() == 0)
            {
                cout << "Lista funzioni vuota: \nInserisci una funzione prima!\n"
                     << endl;
            }
            else
            {
                print_list(functionList);
                int id = inserisci_ID();
                valuta(functionList, id - 1);
            }
            break;
        }

        default:
        {
            cout << "\t=!= Scelta non valida =!=\n"
                 << endl;
            break;
        }
        }
    } while (scelta != 0);

    return 0;
}
