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
#include <unistd.h>

using namespace std;


int collatz(LongInt N)
{
	LongInt out = Convertir(1),
		test2 = Convertir(2),
		test3 = Convertir(3);
	int iter = 0;
	while(!egalite(N, out))
	{
		if(N.Chiffres[0]%2==0)
			N = division(N, test2);
		else
			N = addition(multiplication(N, test3), out);
		iter++;
	}
	return iter;
}