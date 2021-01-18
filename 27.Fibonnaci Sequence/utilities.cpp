/*
fichier utilitaires.cpp
contient
	- la fonction Convertir(entier)
	- la fonction inegaliteabs(n1,n2)
	- la fonction egalite(n1,n2)
*/

#include<iostream>
#include "read_write.h"
#include "longint.h"
#include <cstring>
#include <stdio.h>
#include <list>

using namespace std;


//Définition de la fonction Convertir
LongInt Convertir(int entier)
{
	//Variables
	LongInt a;
	int i;
	//Conversion de entier en chaine de caractère.
	//Cette méthode évite de devoir calculer des puissances de 10
	//pour calculer la décomposition en base 10 de entier.
	string s = to_string(entier);

	//Début
	//Définition du signe de l'LongInt.
	a.Negatif = (entier<0);

	//Calcul du nombre de chiffres de entier.
	int n = s.length();

	//Initialisation d'une chaine de caractère de la taille de la string s.
	char char_array[n + 1];
	
	//Copy de la string vers le tableau de charactères. 
	strcpy(char_array, s.c_str());

	//Affectation des valeurs de l'LongInt.
	for (i=1;i<n+1;i=i+1)
	{
		//Conversion des caractères en entier positifs ou nuls.
		//Le % 48 sert à traiter le cas où le chiffre est nul.
		a.Chiffres[i-1] = abs((char_array[n-i]-'0') % 48);
	}

	//Remplissage par des 0.
	for (i=n;i<MAXCHIFFRES;i=i+1)
	{
		a.Chiffres[i]=0;
	}
	return a;
}

//Définition de la fonction inegaliteabs.
bool inegaliteabs(LongInt n1, LongInt n2)
{
  //Variables
	int i_n1,i_n2,j;

	//Début
	//Calcul du premier indice correspondant à un chiffre non nul.
	i_n1=MAXCHIFFRES-1;
	i_n2=MAXCHIFFRES-1;
	while ((n1.Chiffres[i_n1]==0)&&(i_n1>0))
	{
		i_n1--;
	}
	while ((n2.Chiffres[i_n2]==0)&&(i_n2>0))
	{
		i_n2--;
	}

	//Test simple de l'inégalité si l'un a plus de chiffres que l'autre.
	if (i_n2 < i_n1)
	{
		return(false);
	}
	if (i_n2 > i_n1)
	{
		return(true);
	}
	
	//Test de l'inégalité si ils ont le même nombre de chiffres.
	for(j=i_n1; j>=0; j--)
	{
		if (n1.Chiffres[j]<n2.Chiffres[j])
		{
			return(true);
		}
		if (n1.Chiffres[j]>n2.Chiffres[j])
		{
			return(false);
		}
	}
	//Tous les chiffres sont égaux.
	return(true);
}

//Définition de la fonction egalite.
bool egalite(LongInt a, LongInt b)
{
  //Variables
	int i_a,i_b,j;

	//Début
	//Arrêt immédiat si ils ne sont pas du même signe.
	if (a.Negatif != b.Negatif)
	{
		return(false);
	}

	//Calcul du premier indice correspondant à un chiffre non nul.
	i_a=MAXCHIFFRES-1;
	i_b=MAXCHIFFRES-1;
	while ((a.Chiffres[i_a]==0)&&(i_a>0))
	{
		i_a--;
	}
	while ((b.Chiffres[i_b]==0)&&(i_b>0))
	{
		i_b--;
	}

	//Arrêt immédiat si ils n'ont pas le même nombre de chiffres.
	if (i_b < i_a)
	{
		return(false);
	}

	//Comparaison chiffre à chiffre. Arrêt si il en existe deux différents.
	for(j=i_a; j>=0; j--)
	{
			if (a.Chiffres[j]!=b.Chiffres[j])
			{
				return(false);
			}
	}
	return(true);
}