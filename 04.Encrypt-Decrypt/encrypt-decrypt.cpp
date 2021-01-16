/*
Challenge 04: Encrypt-Decrypt
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string sInput;
  int iChoice;
  
  cout<<"What would you like to do?\n1. Encrypt\n2. Decrypt\n";
  cin>>iChoice;

  while(iChoice != 1 && iChoice != 2)
  {
    cout<<"Wrong option. What would you like to do?\n1. Encrypt\n2. Decrypt\n";
    cin>>iChoice; 
  }

  cout<<"Please input the string you wish to process:\n";
  cin.ignore();
  getline(cin, sInput);

  switch(iChoice)
  {
    case 1:
      for(int i = 0; i<sInput.size(); i++)
        sInput[i] = sInput[i] + 2;
        
      break;
    case 2:
      for(int i = 0; i<sInput.size(); i++)
        sInput[i] = sInput[i] - 2;
      break;
  }
  cout<<"The processed string is: \n"<<sInput<<endl;
  return 0;
}