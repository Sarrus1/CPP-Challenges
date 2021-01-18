/*
fichier fibonnaci.cpp
contient
	- la fonction fibonnaci()
*/


#include<iostream>
#include "read_write.h"
#include "longint.h"
#include "utilities.h"
#include "operations.h"
#include <cstring>
#include <stdio.h>
#include <list>

using namespace std;


LongInt fibonnaci(int n)
{
	//Variables
	LongInt Un_2=Convertir(0), Un_1=Convertir(1), Un=Convertir(0);
	int i=0;
	//Début
	//Gestion des cas n=0 et n=1
	switch(n)
	{
		case 0:
			return(Un_2);
			break;
		case 1:
			return(Un_1);
			break;
	}
	//Calcul de Un
	for(i=2;i<=n;i++)
	{
		Un=addition(Un_2,Un_1);
		Un_2 = Un_1;
		Un_1 = Un;
	}
	return(Un);
}