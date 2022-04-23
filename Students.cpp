#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Students{

	string name;
	string last_name;
	int day;
	int month;
	int year;

};

int main() {

	vector <Students> list_students;
	Students s;

	int N;
	cin >> N;

	for(int i=0;i<N;++i) {    
	cin >> s.name >> s.last_name >> s.day >> s.month >> s.year;
	list_students.push_back(s);
        }

	int M;
	cin >> M;
	string comanda;
	int number;

	for (int i=0; i<M;++i) {
		cin >> comanda >> number;

		if( number > N || number <= 0 || number >10000  ){
			cout << "bad request"<< endl;
			continue;	}
    
		if (comanda == "name"){
			cout << list_students[number-1].name << " "
			<< list_students[number-1].last_name << endl;}

		else if(comanda == "date"){

			cout << list_students[number-1].day << "."
           << list_students[number-1].month << "."
           << list_students[number-1].year << endl;}
    
		else cout << "bad request" << endl;
	}

	return 0;
}
