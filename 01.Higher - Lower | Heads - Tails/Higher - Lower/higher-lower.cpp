/*
Challenge 01: Higher/Lower game
#######################
Description:
A program that allows you to play Higher or Lower against the computer.
*/

#include <iostream>

using namespace std;

int main()
{
  //Set random seed to execution time for randomness
  srand (time(NULL));

  //Variables initialization
  int iNumberRange, iNumberguess, iRandNumber;

  cout<<"Choose a maximum number for the game: ";
  cin>>iNumberRange;

  //Generate the random number
  iRandNumber = rand() % iNumberRange + 1;
  
  //First guess input
  printf("Guess the number between 1 and %i \n", iNumberRange);
  cin>>iNumberguess;

  while (iNumberguess != iRandNumber)
  {
    if(iNumberguess>iRandNumber)
      cout<<"Wrong, the correct number is lower. Choose again: \n";
    else
      cout<<"Wrong, the correct number is higher. Choose again: \n";
    cin>>iNumberguess;
  }

  cout<<"Congratulations, you win! The correct number was "<<iRandNumber<<endl;
  return 0;
}