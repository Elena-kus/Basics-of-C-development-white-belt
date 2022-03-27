#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

int a,b,q;
cin >> a >> b;
  
 if (a==b)
 cout << a;

 if (a>b){      
	q = a % b;

	if( q == 0 )  cout << b;      
	else {
		while(q!=0)
		{
		   q = a % b;
		   a = b;
		   b = q;
		}
	cout << a;
} else {
	q = b % a;
     
	if( q == 0 ) cout << a;
	else {       
		while(q!=0)
		{
		   q = b % a;
		   b = a;
		   a = q;
		}
	cout << b;
}
   
return 0;
}
