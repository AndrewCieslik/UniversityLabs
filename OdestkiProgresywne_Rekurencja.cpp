#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

double odsetkiProgresywne( double kwota, double lbDni, double odsetkiZaDzien )
{
    if (lbDni == 0) 
	{
        return 0;
    }
    double dzienneOdsetki = kwota * odsetkiZaDzien / 100;
	    
    double odsetki = dzienneOdsetki + odsetkiProgresywne(kwota + dzienneOdsetki, lbDni - 1, odsetkiZaDzien);
    
	return odsetki;		
}


int main()
{
  double odsetki;

  // Test 1
  odsetki = odsetkiProgresywne( 1000, 4, 3 );   
  if(trunc(odsetki*100)/100 == 125.50)
    cout << "\nTest 1: OK";
  else
  {
  	cout << "\nTest1: " << odsetki;
    cout << "\nTest 1: Blad";
  }
  	
  // Test 2
  odsetki = odsetkiProgresywne( 1000, 10, 3 );
  if(trunc(odsetki*100)/100  == 343.91)
    cout << "\nTest 2: OK";
  else
  {
  	cout << "\nTest2: " << odsetki;
    cout << "\nTest 2: Blad";
  }
   	
  // Test 3
  odsetki = odsetkiProgresywne( 1000, 2, 3 );
  if(trunc(odsetki*100)/100  == 60.9)
    cout << "\nTest 3: OK";
  else
  {
  	cout << "\nTest3: " << odsetki;
    cout << "\nTest 3: Blad";
  }
    
  // Test 4
  odsetki = odsetkiProgresywne( 2000, 10, 5 );
  if(trunc(odsetki*100)/100  == 1257.78)
    cout << "\nTest 4: OK";
  else
  {
  	cout << "\nTest4: " << odsetki;
    cout << "\nTest 4: Blad";
  }
    

  return EXIT_SUCCESS;
}
