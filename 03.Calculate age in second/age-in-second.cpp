#include <iostream>

using namespace std;

int main()
{
  int iAge, Converted;

  cout<<"Please enter your age: \n";
  cin>>iAge;
  
  Converted = iAge * (365*24*60*60);

  printf("You are %i second old.\n", Converted);

  return 0; 
}