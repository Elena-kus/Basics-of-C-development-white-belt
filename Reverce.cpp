#include <iostream>
#include <vector>

using namespace std;

void Reverse (vector<int>& v){
    
    int tmp; 
    
    for(int i=0;i<v.size()/2;++i)
    {
        tmp = v[i];
        v[i] = v[v.size()-i -1];
        v[v.size()-i-1] = tmp;
    }
    
}

vector<int> Reversed(const vector<int>& v){
    vector<int> w;
    
    w=v;
    Reverse(w);
    
    return w;

}


int main(){
    
    vector<int> v;
    Reversed(v);
    
    return 0;
}