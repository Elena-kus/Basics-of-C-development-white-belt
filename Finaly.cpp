#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <exception>
#include <algorithm>

using namespace std;

class Date {

public:

  int GetYear() const { return year; }
  int GetMonth() const {	return month; }
  int GetDay() const { 	return day; }

  void SetYear( int y)  { year = y; }
  void SetMonth( int m) { month = m; }
  void SetDay (int d) { day = d; }

private:
   int year;
   int month;
   int day;
};

Date ParseDate(const string& data){
  
	Date date;

	stringstream stream(data);
	int y, m, d;
	char c, f;

	if (stream) {
	  stream >> y >> c >> m >> f >> d;

	if (stream)
        if (c != '-' || f != '-' || stream.peek() != -1)
	    throw invalid_argument("Wrong date format: " + data);				
	else  throw invalid_argument("Wrong date format: " + data);	
  
       }

	if(m > 12 || m <1)
	throw invalid_argument("Month value is invalid: " + to_string(m));
	if(d > 31 || d <1)
	throw invalid_argument("Day value is invalid: " + to_string(d));

	date.SetYear(y);
	date.SetMonth(m);
	date.SetDay(d);

	return date;
}

bool operator<(const Date& lhs, const Date& rhs){

  bool t;

  if(lhs.GetYear()< rhs.GetYear())
      t =  true;
  else t =  false;
  
  if(lhs.GetYear()== rhs.GetYear()){
    if(lhs.GetMonth()< rhs.GetMonth())
      t= true;
	  else t = false;
    
    if(lhs.GetMonth() == rhs.GetMonth()){
      if(lhs.GetDay()< lhs.GetDay())
        t= true;
      else t = false;
    }
  }
  return t;
}

class Database {

public:

 map <Date,vector<string>> GetMape() const {return db;}

  void AddEvent(const Date& date, const string& event){

		  if(find(db[date].begin(), db[date].end(), event) == db[date].end()){
			  db[date].push_back(event);
			  sort(db[date].begin(), db[date].end());
		  }
  }
  
  bool DeleteEvent(const Date& date, const string& event){

	  bool t;

	  if(find(db[date].begin(), db[date].end(), event) != db[date].end()){
		
		  db[date].erase(find(db[date].begin(),db[date].end(),event));
		  t = true;

	  } else t = false;

	  return t;
  }

  int  DeleteDate(const Date& date){

	  int N = db[date].size();
	  db[date].resize(0);

	  return N;
  }

 void Find(const Date& date) {

	 sort(db[date].begin(), db[date].end());

	 for(auto c : db[date]){
		 cout << c << endl;
	 }
 }

  void Print() const{
	  for (auto a: db){
      for (string b: a.second )	{
        if(a.first.GetYear()>=0){
          cout << setfill('0');
          cout<< setw(4)<<a.first.GetYear()<<'-'<< setw(2)<< a.first.GetMonth() <<"-"
          << setw(2) <<a.first.GetDay() <<' '<< b << endl;}
      }
    }
  }
  private:
  map <Date,vector<string>> db;
};

int main() {

  Database db;

 try{

  string command;
   
   while (getline(cin, command)){
     
     stringstream stream(command);
     string dodo, data, action;
     
     if (stream) {
       stream >> dodo >> data >> action; }
     
     if(dodo == "Print" && action == "" && data == "")
       db.Print();
     else if((dodo == "Del" || dodo == "Find") && (action == "")){
       
        Date d = ParseDate(data);
       
        if (dodo == "Del")
           cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
       
         if (dodo == "Find")
          db.Find(d);
     
     } else if ((dodo == "Add" || dodo == "Del") && (action != "" && data!= "")){
       
         Date d = ParseDate(data);
       
          if (dodo == "Add")
            db.AddEvent(d, action);
       
          if (dodo == "Del"){
          
           if(db.DeleteEvent(d, action)) cout <<"Deleted successfully" << endl;
              else cout << "Event not found"<< endl;          
          }
     } else if (dodo !="") cout << "Unknown command: "<< dodo << endl; 
     
     return 0;
   }
 }
  catch (invalid_argument& ex) cout << ex.what();
  
  return 0;
}
