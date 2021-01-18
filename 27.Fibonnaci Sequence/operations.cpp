/*
fichier operations.cpp
contient
	- la fonction addition_memes_signes(n1,n2)
	- la fonction soustraction_memes_signes(n1,n2)
	- la fonction addition(n1,n2)
	- la fonction soustraction(n1,n2)
	- la fonction multiplication(n1,n2)
	- la fonction division(n1,n2)
*/

#include<iostream>
#include "read_write.h"
#include "longint.h"
#include "utilities.h"
#include <cstring>
#include <stdio.h>
#include <list>

using namespace std;

//Définition de la fonction addition_memes_signes
LongInt addition_memes_signes(LongInt n1, LongInt n2)
{
	//Variables
	LongInt n3=Convertir(0);
  int retenue,somme,i;

	//Début
	//Test si les entiers sont de même signe
  if (n1.Negatif != n2.Negatif)
  {
    cout<<"Les entierslongs doivent être de même signe.\n";
    return(n3);
  }
  n3.Negatif = n1.Negatif;
	//Algorithme d'addition classique
  retenue = 0;
  for(i=0;i<=MAXCHIFFRES-1;i++)
  {
    somme = n1.Chiffres[i]+n2.Chiffres[i]+retenue;
    retenue = int(somme>=10);
    n3.Chiffres[i]=somme-retenue*10;
  }
  return(n3);
}

//Définition de la fonction soustraction_memes_signes
LongInt soustraction_memes_signes(LongInt n1, LongInt n2)
{
	//Variables
  LongInt n3=Convertir(0);
  int retenue=0, dif,i;
	//Début
	//Test si les entiers sont de même signe
  if (n1.Negatif != n2.Negatif)
  {
		cout<<"Les entierslongs doivent être de même signe.\n";
    return(n3);
  }
	//Test si les entiers verifient n1|>=|n2|
	if (!inegaliteabs(n2,n1))
	{
		cout<<"Les entierslongs doivent vérifiés |n1|>=|n2|.\n";
    return(n3);
	}
	n3.Negatif = n1.Negatif;
	//Algorithme de soustraction classique
  for(i=0;i<MAXCHIFFRES;i++)
  {
		retenue = int(n1.Chiffres[i]<(n2.Chiffres[i]));
		dif = n1.Chiffres[i]-n2.Chiffres[i]+retenue*10;
		n3.Chiffres[i] = dif;
		n2.Chiffres[i+1] += retenue;
  }
  return(n3);
}

//Définition de la fonction addition
LongInt addition(LongInt n1, LongInt n2)
{
	//Début
	//Gestion de differents cas, suivant les signes de n1 et n2
	//pour utiliser addition_memes_signes correctement.
  if (n1.Negatif != n2.Negatif)
  {
		if (n1.Negatif)
		{
			if (inegaliteabs(n1,n2))
			{
			n1.Negatif = false;
			return(soustraction_memes_signes(n2,n1));
			}
			else
			{
			n2.Negatif = true;
			return(soustraction_memes_signes(n1,n2));
			}
		}
		else
		{
			if (inegaliteabs(n2,n1))
			{
			n2.Negatif = false;
			return(soustraction_memes_signes(n1,n2));
			}
			else
			{
			n1.Negatif = true;
			return(soustraction_memes_signes(n2,n1));
			}
		}
  }
	return(addition_memes_signes(n1,n2));
}

//Définition de la fonction soustraction
LongInt soustraction(LongInt n1, LongInt n2)
{
	//Variables
	LongInt n3;
	//Début
	//Gestion de differents cas, suivant les signes de n1 et n2
	//pour utiliser soustraction_memes_signes correctement.
  if (n1.Negatif != n2.Negatif)
  {
		if (n1.Negatif)
		{
			if (inegaliteabs(n1,n2))
			{
			n2.Negatif = true;
			}
		}
		else
		{
			n2.Negatif = false;
		}
		return(addition_memes_signes(n1,n2));
  }
	//Gestion du cas, où |n1|>=|n2| n'est pas vérifié
	//pour utiliser soustraction_memes_signes correctement.
	if (!(inegaliteabs(n2,n1)))
	{
		n3=soustraction_memes_signes(n2,n1);
		n3.Negatif = !n3.Negatif;
		return(n3);
	}
	return(soustraction_memes_signes(n1,n2));
}

//Définition de la fonction multiplication
//Définition d'une variable globale pour ne pas faire déborder la pile.
//Si la variable est définie localement, la pile saute pour des valeurs de
//MAXCHIFFRES de l'ordre de 1000
static LongInt produits[MAXCHIFFRES+1]={Convertir(0)};
LongInt multiplication(LongInt n1, LongInt n2)
{
	//Variables
  LongInt n3=Convertir(0);
  int retenue=0,produit,i,j,i_n1=MAXCHIFFRES-1,i_n2=MAXCHIFFRES-1;

	//Début
	//Calcul du premier indice correspondant à un chiffre non nul.
	while ((n1.Chiffres[i_n1]==0)&&(i_n1>0))
	{
		i_n1--;
	}
	while ((n2.Chiffres[i_n2]==0)&&(i_n2>0))
	{
		i_n2--;
	}
	
	//Traitement du cas où les entiers sont trop grands pour être multipliés.
	//Ce test évite un débordement d'indice.
	if(i_n1+i_n2>MAXCHIFFRES)
	{
		cout<<"Les entierslongs sont trop grands.\n";
		return(n3);
	}
	
	//Test pour déterminer le signe du résultat.
	if (n1.Negatif != n2.Negatif)
  {
    n3.Negatif = true;
  }
	
	//Algorithme de multiplication classique.
	//Calcul de chaque produit, terme à terme.
  for(i=0;i<=MAXCHIFFRES-1;i++)
  {
		for(j=0;j<=MAXCHIFFRES-1;j++)
		{
			produit = n1.Chiffres[i]*n2.Chiffres[j]+retenue;
			retenue = produit/10;
			n3.Chiffres[j+i]=produit-retenue*10;
		}
		produits[i]= n3;
		n3 = Convertir(0);
  }

	//Addition de tous les termes calculés précédements.
	for(i=0; i<=MAXCHIFFRES-1;i++)
	{
		n3 = addition(n3, produits[i]);
	}
  return(n3);
}


//Définition de la fonction division
LongInt division(LongInt n1, LongInt n2)
{
	//Variables
  LongInt n3=Convertir(0), temp=Convertir(0),temp_old=Convertir(0), dividende=Convertir(0), diviseur, reste=Convertir(0), quotient=Convertir(0), k_long=Convertir(0);
  int retenue=0,produit,i=0,j,k_int=1,p=0, i_div=0,i_n1=MAXCHIFFRES-1,i_n2=MAXCHIFFRES-1;

	//Arret immédiat si n1<n2
	if(!inegaliteabs(n2, n1))
	{
		return(n3);
	}

	//Arret immédiat si il y a division par 0.
	if(egalite(n2, Convertir(0)))
	{
		cout<<"Division par 0!";
		return(n3);
	}

	//Détermination du signe du résultat.
	if (n1.Negatif != n2.Negatif)
	{
		n3.Negatif = true;
	}
	//Algorithme d'Euclide pour la division euclidienne.
	while(!inegaliteabs(n1, n2))
	{
		//Calcul du premier indice correspondant à un chiffre non nul	
		while ((n1.Chiffres[i_n1]==0)&&(i_n1>0))
		{
			i_n1--;
		}
		while ((n2.Chiffres[i_n2]==0)&&(i_n2>0))
		{
			i_n2--;
		}

		//Calcul du dividende.
		while((inegaliteabs(dividende, n2))&&(i<=i_n1))
		{
			for(j=i_n1-i;j<=i_n1;j++)
			{
				dividende.Chiffres[j-i_n1+i] = n1.Chiffres[j];
			}
			i++;
		}
		diviseur = n2;
		
		//Détermination du signe du résultat.
		if (n1.Negatif != n2.Negatif)
		{
			n3.Negatif = true;
		}

		//Calcul du diviseur.
		while(inegaliteabs(multiplication(diviseur, k_long), dividende))
		{
			k_int++;
			k_long = Convertir(k_int);
		}
		diviseur = multiplication(diviseur, Convertir(k_int-1));

		//Calcul du reste.
		while ((diviseur.Chiffres[i_div]==0)&&(i_div>0))
		{
			i_div--;
		}
		reste = soustraction(dividende, diviseur);

		//Calcul de la nouvelle valeur de n1 pour la prochaine itération.
		temp = diviseur;
		while(inegaliteabs(temp, n1))
		{
			temp_old = temp;
			temp = multiplication(temp, Convertir(10));
		}
		n1 = soustraction(n1, temp_old);

		//Décalage des indices du quotient.
		for(i=1;i<=p;i++)
		{
			quotient.Chiffres[i] = quotient.Chiffres[i-1];
		}
		quotient.Chiffres[0] = (k_int-1);
		
		//Préparation des variables pour la nouvelle itération.
		p++;
		k_int=0;
		i=0;
		dividende=Convertir(0);
	}
  return(quotient);
}