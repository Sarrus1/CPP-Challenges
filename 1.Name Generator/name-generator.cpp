#include <iostream>
#include <string>

using namespace std;

string g_consonents = "bcdfghjklmnpqrstvwxz";
string g_vowels = "aeiouy";

int main()
{
	string sName, sSurname;
	int iCount;

	//Set random seed to execution time for randomness
	srand (time(NULL));

	//Generate random letters for the name
	for (int i = 0; i <= rand() % 10 + 2; i++)
	{
		if (iCount < 2 && rand() % 2+1 < 2)
		{
			sName+=g_vowels[rand() % 6];
			iCount++;
		}
		else
		{
			sName+=g_consonents[rand() % 20];
			iCount = 0;
		}
	}

	iCount = 0;

	//Generate random letters for the surname
	for (int i = 0; i <= rand() % 10 + 4; i++)
	{
		if (iCount < 2 && rand() % 2+1 < 2)
		{
			sSurname+=g_vowels[rand() % 6];
			iCount++;
		}
		else
		{
			sSurname+=g_consonents[rand() % 20];
			iCount = 0;
		}
	}

	sName[0] = toupper(sName[0]);
	sSurname[0] = toupper(sSurname[0]);

	cout<<"\nName: "<<sName<<" Surname: "<<sSurname<<endl;
	return 0;
}