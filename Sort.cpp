using namespace std;

int main(){
  
  int n;
  cin >> n;
  vector<string> v;

  while(n>0)
  {
    string st;
    cin >> st;
    v.push_back(st);
    --n;
  }
  
  sort(v.begin(), v.end(), [](string i,string j){
      for(int c = 0; c < i.size(); ++c)
          i[c] = tolower(i[c]);
      for(int c = 0; c < j.size(); ++c)	
          j[c] = tolower(j[c]);	
          return (i<j);	});
  
    for(const auto& i : v)  
      cout << i << " ";

  return 0;

}
