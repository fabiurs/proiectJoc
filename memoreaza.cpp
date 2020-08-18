#include <iostream>
#include <ctime>
#include <cstdlib>
#include "memoreaza.h"
using namespace std;
int V[11],S[11];

int memoreaza()
{
    int n,x,i,j,nr,scor,m,t;
    nr=0;
    t=0;
    scor=0;
    m=1;
    srand(time(0));
    system("cls");
    cout<<" Introduceti nivelul de dificultate:"<<endl;
    cout<<"1. Usor "<<endl;
    cout<<"2. Mediu "<<endl;
    cout<<"3. Greu "<<endl;
    cin>>x;
    if(x==1)
    {
        cout<<" Numerele sunt : "<<endl;
        for(i=1;i<=5;i++)
        {
            n=rand()%1000;
            V[i]=n;
            cout<<V[i]<<' ';
        }
        cout<<endl;

        cout<<"Introduceti valoarea 1 daca ati memorat numerele"<<endl;
        cin>>t;
        if(t==1)
            system("cls");
        cout<<"Introduceti numerele afisate anterior pentru a va testa memoria"<<endl;
        for(j=1;j<=5;j++)
        {
            cin>>nr;
            S[j]=nr;
            for(m=1;m<=10;m++)
            {
                if(V[m]==S[j])
                {
                    scor++;
                }
            }
        }
        cout<<"Ati reusit sa memorati"<<' '<<scor<<' '<<"numere";

    }
    if(x==2)
    {
        cout<<" Numerele sunt : "<<endl;
         for(i=1;i<=7;i++)
        {
            n=rand()%1000;
            V[i]=n;
            cout<<V[i]<<' ';
        }
        cout<<endl;
        cout<<"Introduceti valoarea 1 daca ati memorat numerele"<<endl;
        cin>>t;
        if(t==1)
            system("cls");
        cout<<"Introduceti numerele in aceeasi ordine pentru a va testa memoria"<<endl;
        for(j=1;j<=7;j++)
        {
            cin>>nr;
            S[j]=nr;
            for(m=1;m<=7;m++)
            {
                if(V[m]==S[j])
                {
                    scor++;

                }
            }
        }
        cout<<"Ati reusit sa memorati"<<' '<<scor<<' '<<"numere";

    }
    if(x==3)
    {
        cout<<" Numerele sunt : "<<endl;
         for(i=1;i<=10;i++)
        {
            n=rand()%1000;
            V[i]=n;
            cout<<V[i]<<' ';
        }
        cout<<endl;

        cout<<"Introduceti valoarea 1 daca ati memorat numerele"<<endl;
        cin>>t;
        if(t==1)
            system("cls");
        cout<<"Introduceti numerele in aceeasi ordine pentru a va testa memoria"<<endl;
        for(j=1;j<=10;j++)
        {
            cin>>nr;
            S[j]=nr;
            for(m=1;m<=10;m++)
            {
                if(V[m]==S[j])
                {
                    scor++;

                }
            }

        }
        cout<<"Ati reusit sa memorati"<<' '<<scor<<' '<<"numere";
    }
    system("pause");
    return scor;
}
