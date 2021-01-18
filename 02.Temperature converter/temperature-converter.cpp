/*
Challenge 02: Temperature converter
#######################
Description:
Convert between the 3 main temperatures units
*/

#include <iostream>
#include <string>

using namespace std;

float CelsiustoFahrenheit(float fTempInCelsius)
{
  return (9*fTempInCelsius+160)/5;
}

float FahrenheittoCelsius(float fTempInFahrenheit)
{
  return (5*fTempInFahrenheit-160)/9;
}

int main()
{
  string sInitialTemp, sOutputTemp;
  float fInitialTemperature, fOutputTemperature;

  cout<<"What's the unit of your initial temperature?\n"
  <<"K for Kelvin\n"
  <<"C for Celsius\n"
  <<"F for Fahrenheit\n";
  cin>>sInitialTemp;

  while((sInitialTemp.compare("K") != 0)&&(sInitialTemp.compare("C") != 0)&&(sInitialTemp.compare("F") != 0))
  {
    cout<<"Input is incorrect, please type 'K', 'C' or 'F': \n";
    cin>>sInitialTemp;
  }

  cout<<"What temperature do you want to convert?\n";
  cin>>fInitialTemperature;

  cout<<"What's the unit of your output temperature?\n"
  <<"K for Kelvin\n"
  <<"C for Celsius\n"
  <<"F for Fahrenheit\n";
  cin>>sOutputTemp;

  while((sOutputTemp.compare("K") != 0)&&(sOutputTemp.compare("C") != 0)&&(sOutputTemp.compare("F") != 0))
  {
    cout<<"Input is incorrect, please type 'K', 'C' or 'F': \n";
    cin>>sOutputTemp;
  }

  if(sOutputTemp.compare(sInitialTemp) == 0)
  {
    cout<<"Input unit and output unit are the same."<<endl;
    return 0;
  }

  if(sInitialTemp.compare("C") == 0)
  {
    if(sOutputTemp.compare("K") == 0)
      fOutputTemperature = fInitialTemperature + 273.15;
    else
      fOutputTemperature = CelsiustoFahrenheit(fInitialTemperature);
  }
  else if(sInitialTemp.compare("K") == 0)
  {
    if(sOutputTemp.compare("C") == 0)
      fOutputTemperature = fInitialTemperature - 273.15;
    else
      fOutputTemperature = CelsiustoFahrenheit(fInitialTemperature-273.15);
  }
  else
  {
    fOutputTemperature = FahrenheittoCelsius(fInitialTemperature);
    if(sOutputTemp.compare("K") == 0)
      fOutputTemperature += 273.15;
  }

  cout<<fInitialTemperature<<sInitialTemp<<" = "<<fOutputTemperature<<sOutputTemp<<endl;
  return 0;
}