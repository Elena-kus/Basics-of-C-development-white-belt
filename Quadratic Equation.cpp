#include <iostream>
#include <cmath>

using namespace std;

int main() {

double a, b, c;
cin >> a >> b >> c;

double d = b*b-4*a*c;

if(a == 0) // линейное уравнение
{
	if (b!=0)
	{
		double x1 = -c/b;
		cout << x1 << endl;
	}

} else if (d>0) // квадратное уравнение
{
	double x1 = (-b + sqrt(d))/(2*a);
	double x2 = (-b - sqrt(d))/(2*a);
	cout << x1 << " " << x2 << endl;
}
if (d==0)
{
	double x1 = -b/(2*a);
	cout << x1 << endl;
}
	
return 0;
}
