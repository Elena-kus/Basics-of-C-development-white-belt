#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {

int n;
cin >> n;
vector<int> r;
  
while(n >= 2)
{
	if (n%2 == 0)
	  r.push_back(0);
	else r.push_back(1);
	  n = n / 2;
}
  
r.push_back(1);

for( int i=r.size()-1;i>=0;--i)
	cout << r[i];

  return 0;
}
