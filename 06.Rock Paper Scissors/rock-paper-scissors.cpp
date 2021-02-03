/*
Challenge 06: Play rock paper scissors
#######################
Description:
Play rock paper scissors against the computer
*/

#include <iostream>

using namespace std;

int main()
{
	srand (time(NULL));
	int iRand = rand() % 3 +1,
		iChoice;

	cout<<"Choose something :\n";
	cout<<"1. Rock\n2. Paper\n3. Scissors"<<endl;
	cin>>iChoice;
	while(!(iChoice == 1 || iChoice == 2 || iChoice == 3))
	{
		cout<<"Wrong selection, pick again\n";
		cout<<"1. Rock\n2. Paper\n3. Scissors"<<endl;
	}
	if(iRand==iChoice)
		cout<<"Tie"<<endl;
	else
	{
		if(abs(iChoice-iRand)==1)
		{
			if(iChoice>iRand)
				cout<<"You won!"<<endl;
			else
				cout<<"You lost!"<<endl;
		}
		else
		{
			if(iChoice>iRand)
				cout<<"You lost!"<<endl;
			else
				cout<<"You won!"<<endl;
		}
	}
	cout<<"The computer picked ";
	switch(iRand)
	{
		case(1): cout<<"Rock"<<endl; break;
		case(2): cout<<"Paper"<<endl; break;
		case(3): cout<<"Scissors"<<endl; break;
	}
  return 0; 
}