#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mare_mic.h"
using namespace std;

int mare_mic()
{
    system("cls");
    int gresit=0,corect=0,prev,next;
    char alegere;
    prev=5;
    cout<<"Acesta este un simplu joc de ghicit."<<endl<<"Obiectivul jocului este de a ghici daca urmatorul numar este mai mare sau mai mic decat precedentul. "<<endl;
    cout<<"Vei incepe cu numarul 5. Nu poti face mai mult de 3 greseli asa ca alege intelept. "<<endl;
    cout<<"Este numarul mai mare(scrie H) sau mai mic(scrie L)?"<<endl;
    system("pause>nul");
    system("cls");
    cout<<"Alegerea ta este: "<<endl;
    do
    {
        srand(time(NULL));
        do
        {
            next=rand()%11;
        }while(next==prev);
        cin>>alegere;
        if(alegere=='H' or alegere=='h')
        {
            if(prev<next)
            {
                cout<<"Corect! Numarul era "<<next<<" Alege din nou. "<<endl;
                corect++;
            }
            else if(prev>next)
            {
                cout<<"Gresit! Numarul era "<<next<<" Alege din nou. "<<endl;
                gresit++;
            }
        }
        else if(alegere=='L' or alegere=='l')
        {
            if(prev>next)
        {
                cout<<"Corect! Numarul era "<<next<<" Alege din nou. "<<endl;
                corect++;
        }
            else if(prev<next)
            {
                cout<<"Gresit! Numarul era "<<next<<" Alege din nou. "<<endl;
                gresit++;
            }
        }
        else
            cout<<"Alegere incorecta"<<endl;
        prev=next;

    }while(gresit<3);
    cout<<"Ai facut 3 greseli. Jocul s-a sfarsit. ";
    cout<<"Ai avut "<<corect<<" raspunsuri corecte."<<endl<<"Felicitari!"<<endl<<endl;
    system("pause");
    if(corect<5)
        return 1;
    else if(corect<=10)
        return 2;
    else
        return 4;
}
