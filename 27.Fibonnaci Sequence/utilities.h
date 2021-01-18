/*
fichier utilities.h
pour déclarer les fonctions de utilitaires.cpp
*/

#ifndef utilities_h
#define utilities_h
#include "utilities.h"

//fonction Convertir(n)
//convertit un entier en Entierlong
LongInt Convertir(int);

//fonction egalite
//retourne la valeur du test a==b;
bool egalite(LongInt, LongInt);

//fonction inegaliteabs
//retourne la valeur du test abs(n1)<=abs(n2)
bool inegaliteabs(LongInt, LongInt);

#endif
