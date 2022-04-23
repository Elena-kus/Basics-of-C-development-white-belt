#include <iostream>
#include <numeric>
#include <string>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

class Rational {
public:
    Rational() {
       p=0;
       q=1;
    }

    Rational(int numerator, int denominator) {

    	if (denominator == 0) {    	
    		throw invalid_argument("Invalid argument");}
      
    	p = numerator;
    	q = denominator;
    }

    int Numerator() const {      
    	int a = p;
    	if ((q>0&&p>0) || (q>0&&p<0))
    		a = p/gcd(p,q);
    	if((q<0 && p >0) || (q<0 && p<0))
    		a = -p/gcd(p,q);

        return a;
    }

    int Denominator() const {      
      int b = q;
    	if (q<0)
        b = -q/gcd(p,q);
    	else
        b = q/gcd(p,q);

    	return b;
    }

  private:
    int p;
    int q;
};

bool operator==(const Rational& a, const Rational& b){

	if ((a.Numerator() == b.Numerator())&& a.Denominator() == b.Denominator())
		return true;
	else return false;
}

Rational operator-( const Rational& a, const Rational& b){
  
	return Rational(a.Numerator()*b.Denominator()-a.Denominator()*b.Numerator(),a.Denominator()*b.Denominator());
}

Rational operator+( const Rational& a, const Rational& b){
  
	return Rational(a.Numerator()*b.Denominator()+a.Denominator()*b.Numerator(),a.Denominator()*b.Denominator());
}

Rational operator*( const Rational& a, const Rational& b){

	return Rational(a.Numerator()*b.Numerator(),a.Denominator()*b.Denominator());
}

Rational operator/( const Rational& a, const Rational& b){

if(b.Numerator() == 0){
	throw domain_error("Division by zero"); }

	return Rational(a.Numerator()*b.Denominator(),a.Denominator()*b.Numerator());
}

ostream& operator<<(ostream &stream, const Rational& r){

	stream << r.Numerator()<<"/"<< r.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& r){

	int n, d;
	  char c;

	  if (stream) {
		  stream >> n >> c >> d;
	      if (stream) {
	          if (c == '/') {
	              r = Rational(n, d);
	          }
	         else {
	        stream.setstate(ios_base::failbit);
	          }
	      }
	  }

	return stream;
}

bool operator<(const Rational& a, const Rational& b){

	if (a.Numerator()*b.Denominator() < a.Denominator()*b.Numerator()) 
        return true;
     else return false;
}

int main() {

	Rational r1;
	Rational r2;
	char operation;

	try{cin >> r1;}
	catch (invalid_argument& ex){ cout << ex.what(); return 0;}

	cin>> operation;

	try{cin >> r2;}
	catch (invalid_argument& ex){ cout << ex.what(); return 0;}

	if(operation == '+')
		cout << r1 + r2 << endl;
	if(operation == '-')
		cout << r1 - r2 << endl;
	if(operation == '*')
		cout << r1 * r2 << endl;
	if(operation == '/'){
		try{cout << r1 / r2 << endl;}
		catch (domain_error& ex){cout << ex.what(); return 0;}
	} 
  
    return 0;
}
