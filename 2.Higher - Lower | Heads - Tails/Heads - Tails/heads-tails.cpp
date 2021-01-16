/*
Challenge 2: Heads or Tails game
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string sGuess;
  int iRand;
  //Set random seed to execution time for randomness
  srand (time(NULL));

  cout<<"heads or tails? \n";
  cin>>sGuess;

  while((sGuess.compare("heads") != 0)&&(sGuess.compare("tails") != 0))
  {
    cout<<"Input is incorrect, please type 'heads' or 'tails': \n";
    cin>>sGuess;
  }

  iRand = rand() % 2;
  if(iRand==0)
  {
    cout<<"Result was heads.";
    if(sGuess.compare("heads") == 0)
      cout<<"You win!"<<endl;
    else
      cout<<"You Loose!"<<endl;
  }
  else
  {
    cout<<"Result was tails. ";
    if(sGuess.compare("tails") == 0)
      cout<<"You win!"<<endl;
    else
      cout<<"You Loose!"<<endl;
  }
}