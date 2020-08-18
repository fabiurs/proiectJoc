#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tic_tac_toe.h"

using namespace std;

char mat[3][3];
bool gameOver;
char castigator='O';
int i, completari[10], a, alegere;

void instructiuni_tic_tac_toe();
void afisare_tabla_joc();
void verifica_joc();
void introd_alegere_utilizator();
void introd_alegere_calculator();
void goleste_matrice();
void goleste_completari();
int tic_tac_toe()
{
    srand(time(0));
    gameOver=false;
    goleste_matrice();
    goleste_completari();
    instructiuni_tic_tac_toe();
    do
    {
        afisare_tabla_joc();
        introd_alegere_utilizator();
        verifica_joc();
        if(!gameOver)
            introd_alegere_calculator();
        verifica_joc();
    }while(!gameOver);
    afisare_tabla_joc();
    cout<<endl;
    if(castigator=='X')
        {
            cout<<" Felicitari ! Ati castigat ! "<<endl;
            system("pause>nul");
            return 2;
        }
    else if(castigator=='O')
        {
            cout<<" Din pacate ati pierdut "<<endl;
            system("pause>nul");
            return 1;
        }
    else
    {
        cout<<" Egalitate "<<endl;
        system("pause>nul");
        return 1;
    }

}
void instructiuni_tic_tac_toe()
{
    system("cls");
    cout<<endl;
    cout<<" X si O - Tic Tac Toe "<<endl;
    cout<<endl;
    cout<<" Pentru a introduce X intr-un anumit camp alegeti numarul corespunzator campului . "<<endl;
    cout<<" Considerati casutele astfel : "<<endl<<endl;
    cout<<" 7 | 8 | 9 "<<endl;
    cout<<" --|---|--"<<endl;
    cout<<" 4 | 5 | 6 "<<endl;
    cout<<" --|---|--"<<endl;
    cout<<" 1 | 2 | 3 "<<endl;
    cout<<endl<<" Pentru a continua apasati o tasta ";
    system("pause>nul");
}
void goleste_completari()
{
    int i;
    for(i=0; i<10; i++)
        completari[i]=0;
}
void goleste_matrice()
{
    int i, j;
    for(i=0; i<3; i++)
    {
         for(j=0; j<3; j++)
        {
            mat[i][j]=' ';
        }
    }
}

void verifica_joc()
{
    int c;
    c=0;
    for(i=1; i<10; i++)
    {
        if(completari[i]==1)
            c++;
    }
    if(c==9)
    {
        gameOver=true;
        castigator='E';
    }
    if((mat[0][0]==mat[1][1] and mat[1][1]==mat[2][2]) and mat[0][0]!=' ') //verificam diagonala principala
    {
        gameOver=true;
        if(mat[0][0]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[2][0]==mat[1][1] and mat[1][1]==mat[0][2] and mat[2][0]!=' ') // verificam diagonala secundara
    {
        gameOver=true;
        if(mat[2][0]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[0][0]==mat[0][1] and mat[0][1]==mat[0][2] and mat[0][0]!=' ') // verificam liniile
    {
        gameOver=true;
        if(mat[0][0]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[1][0]==mat[1][1] and mat[1][1]==mat[1][2] and mat[1][0]!=' ')
    {
        gameOver=true;
        if(mat[1][0]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[2][0]==mat[2][1] and mat[2][1]==mat[2][2] and mat[2][0]!=' ')
    {
        gameOver=true;
        if(mat[2][0]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[0][0]==mat[1][0] and mat[1][0]==mat[2][0] and mat[0][0]!=' ') // verificam coloanele
    {
        gameOver=true;
        if(mat[0][0]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[0][1]==mat[1][1] and mat[1][1]==mat[2][1] and mat[0][1]!=' ')
    {
        gameOver=true;
        if(mat[0][1]=='X')
            castigator='X';
        else
            castigator='O';
    }
    else if(mat[0][2]==mat[1][2] and mat[1][2]==mat[2][2] and mat[0][2]!=' ')
    {
        gameOver=true;
        if(mat[0][2]=='X')
            castigator='X';
        else
            castigator='O';
    }
}
void afisare_tabla_joc()
{
    int i_afisare, j_afisare;
    system("cls");
    cout<<endl;
    for(i_afisare=0; i_afisare<3; i_afisare++)
    {
        for(j_afisare=0; j_afisare<3; j_afisare++)
        {
            cout<<' '<<mat[i_afisare][j_afisare]<<' ';
            if(j_afisare!=2)
                cout<<'|';
        }
        cout<<endl;
        if(i_afisare!=2)
            cout<<" --|---|--";
        cout<<endl;
    }
}
void introd_alegere_utilizator()
{
    do
    {
        cin>>alegere;
        if(completari[alegere]==1)   // verificam daca pozitia aleasa nu este deja ocupata
        {
            cout<<" Alegere incorecta !   Introduceti o alta alegere"<<endl;
            cin>>alegere;
        }
    }while(completari[alegere]!=0);
    completari[alegere]=1;
    if(alegere==1)
        mat[2][0]='X';
    else if(alegere==2)
        mat[2][1]='X';
    else if(alegere==3)
        mat[2][2]='X';
    else if(alegere==4)
        mat[1][0]='X';
    else if(alegere==5)
        mat[1][1]='X';
    else if(alegere==6)
        mat[1][2]='X';
    else if(alegere==7)
        mat[0][0]='X';
    else if(alegere==8)
        mat[0][1]='X';
    else if(alegere==9)
        mat[0][2]='X';
}
void introd_alegere_calculator()
{
    do
    {
        a=rand()%9+1;
    }while(completari[a]!=0);   // verificam daca pozitia aleasa nu este deja ocupata
    completari[a]=1;
    if(a==1)
        mat[2][0]='O';
    else if(a==2)
        mat[2][1]='O';
    else if(a==3)
        mat[2][2]='O';
    else if(a==4)
        mat[1][0]='O';
    else if(a==5)
        mat[1][1]='O';
    else if(a==6)
        mat[1][2]='O';
    else if(a==7)
        mat[0][0]='O';
    else if(a==8)
        mat[0][1]='O';
    else if(a==9)
        mat[0][2]='O';
}

