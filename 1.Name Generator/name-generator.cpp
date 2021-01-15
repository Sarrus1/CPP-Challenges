/*
Challenge: Create a name generator
*/


#include <iostream>
#include <string>

using namespace std;

string g_consonents = "bcdfghjklmnpqrstvwxz";
string g_vowels = "aeiouy";


void Generator(string& StringToGenerate, int minlength=2)
{
	int iCount = 0;
	for (int i = 0; i <= rand() % 10 + minlength; i++)
	{
		if (iCount < 2 && rand() % 2+1 < 2)
		{
			StringToGenerate+=g_vowels[rand() % 6];
			iCount++;
		}
		else
		{
			StringToGenerate+=g_consonents[rand() % 20];
			iCount = 0;
		}
	}
}

int main()
{
	string sName, sSurname;

	//Set random seed to execution time for randomness
	srand (time(NULL));

	//Generate random letters for the name
	Generator(sName);

	//Generate random letters for the surname
	Generator(sSurname, 4);

	sName[0] = toupper(sName[0]);
	sSurname[0] = toupper(sSurname[0]);

	cout<<"\nName: "<<sName<<" Surname: "<<sSurname<<endl;
	return 0;
}
