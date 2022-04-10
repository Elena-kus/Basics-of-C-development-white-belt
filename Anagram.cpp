#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map <char,int> BuildCharCounters ( string s ){

  map <char, int> later_count;

  for (const char& i:s)
    ++ later_count[i]; 

  return later_count;
}

int main() {

	int N;
	cin >> N;
  
	for (int i=0;i<N;i++){
    
	string word1, word2;
	cin >> word1 >> word2;
    
	map <char, int> s1;
	map <char, int> s2;

	s1 = BuildCharCounters(word1);
	s2 = BuildCharCounters(word2);

	if(s1==s2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	}
  
	return 0;
}
