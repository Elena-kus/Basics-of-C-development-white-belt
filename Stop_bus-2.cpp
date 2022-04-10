#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main() {

	int q;
	cin >> q;

	map <int, set <string>> stop_bus;
	set <string> stops;

	for(int i=0;i<q;++i){

		int n;
		cin >> n;
		int k = 0;

		int map_size = stop_bus.size();

		for (int i =0; i<n;++i){
			string stop;
			cin >> stop;
			stops.insert(stop);}

		for(auto c:stop_bus){
			if (c.second == stops){
				cout << "Already exists for " << c.first << endl;
			}
			else ++k;
		}

		if(k==map_size){
			stop_bus[map_size+1] = stops;
			cout << "New bus " << map_size + 1 << endl;
		}

		stops.clear();
	}

	return 0;
}
