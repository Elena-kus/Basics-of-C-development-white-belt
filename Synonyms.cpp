#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main (){

  map<string, set<string>> synonyms;

  int q;
  cin >> q;

  for(int i=0;i<q;++i){

    string comanda;
    cin >> comanda;

      if(comanda == "ADD"){
        string s1, s2;
        cin >> s1 >> s2;
			
        synonyms[s1].insert(s2);
        synonyms[s2].insert(s1);
      }

      if(comanda == "COUNT"){

      string word;
      cin >> word;

      cout << synonyms[word].size() << endl;
      }
    
      if(comanda == "CHECK"){

      string word1, word2;
      cin>> word1 >> word2;

        if(synonyms[word1].count(word2)==1)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
  }
  return 0;
}
