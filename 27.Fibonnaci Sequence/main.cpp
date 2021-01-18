/*
Challenge 27: Fibonnaci
#######################
Description:
Computes the input value of the Fibonnaci sequence.
Works for large values (up to 10 000).
*/

#include <iostream>
#include "read_write.h"
#include "longint.h"
#include "utilities.h"
#include "operations.h"
#include "fibonnaci.h"
#include <stdio.h>

using namespace std;

//Réalisation des tests

int main()
{
	//variables
  int n;
	LongInt Un;

	cout<<"What value of the Fibinnaci sequence do you want to compute ?\n";
	cin>>n;
	//Calcul du n-ième terme de la suite de fibonnaci
	cout<<"\033[1;32m\nFibonnaci: U(";
	cout<<n;
	cout<<") = \033[0m";
	Un = fibonnaci(n);
	AfficheLongInt(Un);
}