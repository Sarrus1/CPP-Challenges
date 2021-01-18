/*
fichier lit_ecrit.cpp
contient
	- l'action AfficheLongInt(a)
	- la fonction LitLongInt
*/

//inclusion de fichiers entetes

#include <iostream> //pour cout et cin
using namespace std;

#include <cstring> // pour strlen
//#include <ctype.h> // pour toascii

#include "longint.h" //pour le type LongInt

#include "read_write.h" /* facultatif : permet de verifier que les types
des parametres dans les prototypes sont bien les memes que dans les
actions/fonctions correspondantes*/

//fonction AfficheLongInt(n)
//affiche sur l'ecran un LongInt
void AfficheLongInt(LongInt a)
{
    //variables
    int i,j;
    // debut

    // signe
    if (a.Negatif)
    {
	   cout <<"-";
    }
    // Chiffres
    /* on recherche le 1er chiffre non nul (ou le chiffre des unites dans le cas
    d'un entier nul*/
    i=MAXCHIFFRES-1;
    while ((a.Chiffres[i]==0)&&(i>0))
    {
    	i=i-1;
    }
    /*on ecrit les Chiffres "utiles"*/
    for(j=i;j>=0;j=j-1)
    {
    	cout << a.Chiffres[j];
    }
    cout << endl;
    // fin
}

//fonction LitLongInt
//lit au clavier un LongInt
LongInt LitLongInt()
{
    //variables
    char Nb[MAXCHIFFRES+1];
    LongInt a;
    int i,l;

    // debut
    cin >> Nb;
    a.Negatif = (Nb[0]=='-');
    l=strlen(Nb);
    if ((a.Negatif)||(Nb[0]=='+'))
    {
    	//on decale le caractere de fin de chaine d'un indice a gauche
    	for(i=0;i<l;i=i+1)
    	{
    		Nb[i]=Nb[i+1];
    	}
    	l=strlen(Nb);
    }
    for (i=0;i<l;i=i+1)
    {
    	a.Chiffres[i] = toascii(Nb[l-1-i])-toascii('0');
    }
    // on complete par des 0
    for (i=l;i<MAXCHIFFRES;i=i+1)
    {
    	a.Chiffres[i]=0;
    }
    return a;
    // fin
}
