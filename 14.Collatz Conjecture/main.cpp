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
#include "collatz.h"
#include <stdio.h>

using namespace std;

//Réalisation des tests

int main()
{
	//variables
  int n, iter;
	LongInt N;

	cout<<"What value of the Collatz sequence do you want to compute ?\n";
	cin>>n;
	N = Convertir(n);
	cout<<"\033[1;32m\nCollatz: U(";
	cout<<n;
	cout<<") = \033[0m";
	iter = collatz(N);
	cout<<iter<<endl;
}