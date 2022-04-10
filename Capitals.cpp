#include <iostream>
#include <map>
using namespace std;

int main() {

 int q;
 cin >> q;

 string comanda;

 map <string, string > s;

 for (int i=0; i<q;i++){

  cin >> comanda;

  if(comanda=="CHANGE_CAPITAL"){
      
    string countr, new_capital;
    cin>> country >> new_capital;
    
    if(s.count(country)==1){				
        if(s[country]==new_capital)
          cout << "Country " << country << " hasn't changed its capital" << endl;
        else {
          cout << "Country " <<country<< " has changed its capital from " << s[country] <<
          " to " << new_capital << endl;
          s[country] = new_capital;
        }
    } else{ s[country] = new_capital;
           cout << "Introduce new country " << country  <<" with capital "<< new_capital << endl; }
  }
   
    if(comanda=="RENAME"){
      
      string old_country_name, string new_country_name;
      cin >> old_country_name >> new_country_name;
      
        if(new_country_name==old_country_name || s.count(old_country_name)==0 || s.count(new_country_name)==1)
          cout << "Incorrect rename, skip" << endl;
        else {
          cout << "Country " << old_country_name << " with capital " << s[old_country_name] << 
           " has been renamed to " << new_country_name << endl;
          string country = s[old_country_name];
          s.erase(old_country_name);
          s[new_country_name] = country;
        }
    }
   
   if(comanda=="ABOUT"){
     string country;
     cin >> country;
     
       if(s.count(country)==0)
         cout << "Country " << country <<" doesn't exist"<<endl
       else
         cout << "Country " << country <<"  has capital " << s[country]<< endl;
   }
   
   if(comanda=="DUMP"){
     
     if(s.empty())
       cout << "There are no countries in the world" << endl;
     else{
       for( auto item: s )
         cout << item.first <<"/" << item.second << " ":
       
       cout << endl;
     }
   }
 }
	return 0;
}
