/*
fichier operations.h
pour déclarer les fonctions de operations.cpp
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "operations.h"

//fonction addition_memes_signes(n1,n2)
//additionne deux entiers longs de même signes
LongInt addition_memes_signes(LongInt, LongInt);

//fonction soustraction_memes_signes(n1,n2)
//soustrait deux entiers longs de même signes tels que |n1|>=|n2|
LongInt soustraction_memes_signes(LongInt, LongInt);

//fonction addition(n1,n2)
//additionne deux entiers longs
LongInt addition(LongInt, LongInt);

//fonction soustraction(n1,n2)
//soustrait deux entiers longs
LongInt soustraction(LongInt, LongInt);

//fonction multiplication(n1,n2)
//multiplie deux entiers longs
LongInt multiplication(LongInt, LongInt);

//fonction division(n1,n2)
//divise n1 par n2
LongInt division(LongInt, LongInt);
#endif
