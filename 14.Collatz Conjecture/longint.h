/*
File longint.h
Defines the LongInt struct
*/

#ifndef LONGINT_H
#define LONGINT_H

const int MAXCHIFFRES = 3000;

typedef int tabEnt[MAXCHIFFRES];

struct LongInt
{
    bool Negatif;
    tabEnt Chiffres;
};

#endif
