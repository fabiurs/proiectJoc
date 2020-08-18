#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "hangman.h"
using namespace std;

extern int *puncte;

char cuvinte[8][15] = {"ciocolata",
                                    "dinozaur",
                                    "mancare",
                                    "masina",
                                    "abecedar",
                                    "pneumonie",
                                    "fotbal",
                                    "bibliografie"};

int caractere_ghicite[15], optiune, i_verificare, a_hg, lungime_cuvant, nr_incercari, c, f;
char cuvant[15], c_introdus , caractere_introduse[50];
bool jocTerminat, cuvantGhicit;

void afisare();
void verifica_aparitie(char d, char cv[] );
void pregateste_setari();
void sugestii_cuvant(int);
void completare_cu_0(int vct[], int lng);
void alegere_utilizator();
bool verifica_completat();
void litere_folosite();

int hangman()
{
    srand(time(0));
    jocTerminat=false;
    do
    {
        system("cls");
        cout<<endl;
        cout<<" Spanzuratoarea  - Hangman"<<endl<<endl;
        cout<<endl;
        cout<<" 1 -> Joc nou "<<endl;
        cout<<" 2 -> Inapoi"<<endl;
        cin>>optiune;
        if(optiune==1)
        {
            pregateste_setari();
            do
            {
                system("cls");
                afisare();
                litere_folosite();
                if(nr_incercari>8)
                {
                    sugestii_cuvant(a_hg);
                }
                if(verifica_completat()==true)
                    cuvantGhicit=true;
                if(!cuvantGhicit)
                {
                    alegere_utilizator();
                    verifica_aparitie(c_introdus, cuvant);
                }
            }while(!cuvantGhicit);
            system("cls");
            afisare();
            cout<<endl;
            cout<<" Felicitari! Ati gasit cuvantul !";
            if(nr_incercari>=10)
                cout<<" Se putea mai bine ! ";
            else
                cout<<" Foarte bine ! "<<endl<<endl;
            cout<<endl<<" Apasati o tasta pentru a continua :) "<<endl;
            system("pause>nul");
        }
        else if(optiune==2)
        {
            jocTerminat=true;
        }
        else
        {
            cout<<endl<<" Alegere incorecta ! "<<endl;
        }
    }while(!jocTerminat);
    if(nr_incercari>=10)
        return 1;
    else
        return 2;
}
void pregateste_setari()
{
    a_hg=rand()%8;
    strcpy(cuvant, cuvinte[a_hg]);
    lungime_cuvant=strlen(cuvant);
    nr_incercari=0;
    c=0;
    cuvantGhicit=false;
    completare_cu_0(caractere_ghicite, lungime_cuvant);
}
void afisare()
{
    cout<<endl;
    cout<<"  Cuvantul :       ";
    for(int i=0; i<lungime_cuvant; i++)
    {
        if(caractere_ghicite[i]==0)
        {
            cout<<"_ ";
        }
        else
        {
            cout<<cuvant[i]<<' ';
        }
    }
    cout<<endl<<endl;
    cout<<" Pana acum ati avut "<<nr_incercari<<" incercari"<<endl;
}
void verifica_aparitie(char c_introdus, char cuvant[])
{
    i_verificare=0;
    while(i_verificare<=lungime_cuvant)
    {
        if(cuvant[i_verificare]==c_introdus)
        {
            caractere_ghicite[i_verificare]=1;
        }
        i_verificare++;
    }
}
void sugestii_cuvant(int nr_ordine)
{
    cout<<" Sugestie cuvant :   ";
    switch(nr_ordine)
    {
    case 0:
        cout<<" Dulcele preferat al copiilor :) "<<endl;
        break;
    case 1:
        cout<<" Reptila gigant :)"<<endl;
        break;
    case 2:
        cout<<" Se prepara :)"<<endl;
        break;
    case 3:
        cout<<" Mijloc de transport :)"<<endl;
        break;
    case 4:
        cout<<" Carte de inceput :)"<<endl;
        break;
    case 5:
        cout<<" Infectie a plamanilor :)"<<endl;
        break;
    case 6:
        cout<<" Sport popular :)"<<endl;
        break;
    case 7:
        cout<<" Se ocupa cu studiul tipariturilor :)"<<endl;
        break;
    default:
        cout<<" "<<endl;
        break;
    }
}
void completare_cu_0(int vct[], int lng)
{
    int j;
    for(j=0; j<lng; j++)
        vct[j]=0;
}
void alegere_utilizator()
{
    cout<<endl<<" Introduceti litera "<<endl;
    cin>>c_introdus;
    nr_incercari++;
    cout<<endl;
}
bool verifica_completat()
{
    int h;
    for(h=0; h<lungime_cuvant; h++)
    {
        if(caractere_ghicite[h]==0)
            return false;
    }
    return true;
}
void litere_folosite()
{
    caractere_introduse[c]=c_introdus;
    c++;
    cout<<endl<<" Literele folosite sunt : ";
    for(f=0; f<c; f++)
        cout<<caractere_introduse[f]<<' ';
    cout<<endl<<endl;
}

