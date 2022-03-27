#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom( string s){
    
for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            return 0;
        }
    }         
   return 1;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    
    vector<string> result;
    
    for(int i=0; i< words.size();++i){
        if((IsPalindrom(words[i]))&& words[i].size()>=minLength)
        result.push_back(words[i]);
    }
    
    return result;
}

int main(){
    
    int minLenght;
    string s;
    cin >> minLenght;
    getline(cin,s);
    vector<string> words;
    
    string w;
    
    for(int i=0; i< s.size();i++)
    {
       if(s[i]==' '){
            words.push_back(w);
            w = "";
        }
        else {
            w +=s[i];
            }
    }
    words.push_back(w);
    
    vector<string> result = PalindromFilter(words, minLenght);
      
    for(int i=0;i<result.size();++i)
    cout << result[i]<<endl;
    
}
