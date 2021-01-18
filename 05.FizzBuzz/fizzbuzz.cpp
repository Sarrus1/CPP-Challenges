/*
Challenge 05: FizzBuzz
#######################
Description:
If the input number is a multiple of 3, print Fizz.
If the input number is a multiple of 5, print Buzz.
If the input number is a multiple of 3 and 5, print FizzBuzz.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int iValue;
  string sOutput = "";

  cout<<"What value do you want to test ?\n";
  cin>>iValue;

  if(iValue%3==0)
    sOutput += "Fizz";
  if(iValue%5==0)
    sOutput += "Buzz";
  
  cout<<sOutput<<endl;
}