#include <iostream>
#include <ctime>
#include<cstdlib>
#include "ghiceste_numar.h"
using namespace std;

int ghiceste_numarul()
{
    system("cls");
    srand(time(0));
    int nr_random, nr_introdus, ghicit=0, nrincercari=0;
    nr_random=rand()%21;
    cout<<endl;
    cout<<" Ghiceste Numarul !"<<endl;
    cout<<" Numarul pe care trebuie sa il ghicesti apartine intervalului [ 0 , 20 ] "<<endl;
    do
    {
        cout<<"Introduceti o valoare."<<endl;
        cin>>nr_introdus;
        nrincercari++;
        if(nr_introdus==nr_random)
        {
            ghicit=1;
        }
        else if(nr_introdus<nr_random)
            {
                cout<<"Numarul este prea mic. Mai incearca!"<<endl;
            }
            else if(nr_introdus>nr_random)
                {
                    cout<<"Numarul este prea mare. Mai incearca!"<<endl;
                }
    }while(ghicit!=1);
    cout<<"Felicitari! Ati castigat!"<<endl;
    cout<<"Ati avut "<<nrincercari<<" incercari."<<endl;
    system("pause");
    if(nrincercari<10)
        return 2;
    else
        return 1;
}
