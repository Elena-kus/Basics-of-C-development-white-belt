#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
  
  for (const auto& item : names) {
    if (item.first <= year)
      name = item.second;
    else
      break;
  }
  return name;;
}

class Person {
public:

Person (const string& name, const string &so_name, const int& year){
		first_names[year] = name;
		last_names[year] = so_name;
		b_day = year;
}
  
  void ChangeFirstName(int year, const string& first_name) {
      if ( year >= first_names.begin()->first )
        first_names[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
      if ( year >= last_names.begin()->first)
        last_names[year] = last_name;
  }

  string GetFullName(int year) const {

    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    if (first_name.empty() && last_name.empty())
      return "Incognito";
    else if (first_name.empty()) 
         return last_name + " with unknown first name";
         else if (last_name.empty()) 
              return first_name + " with unknown last name";
              else
              return first_name + " " + last_name;
  }
  
  string GetFullNameWithHistory(int year) const {
    
   const string first_name = FindAllNameByYear(first_names, year);
   const string last_name = FindAllNameByYear(last_names, year);
    
   if (first_name.empty() && last_name.empty())
     return "No person";	    
    else if (first_name.empty())
          return last_name + " with unknown first name";
         else if (last_name.empty()) {
	            return first_name + " with unknown last name";
              else
              return first_name + " " + last_name;
  }
  
  private:
    map<int, string> first_names;
    map<int, string> last_names;
    int b_day;
};

int main() {

  Person person("Polina", "Sergeeva", 1960);
	
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1900, "Evgenia");
  person.ChangeLastName(1900, "Sokolova");
  person.ChangeLastName(1910, "Sokolova");
  person.ChangeFirstName(1920, "Evgenia");
  person.ChangeLastName(1930, "Sokolova");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}
