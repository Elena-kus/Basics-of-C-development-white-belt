#include<iostream>
#include<vector>

using namespace std;

int main(){
     
    int n;
    cin >> n;
    
    vector<int> temp(n);
    
    for(int i=0;i<n;++i)
       cin >> temp[i];
           
    int sr_znach = 0;
    
    for(int i=0;i<temp.size();++i)
      sr_znach +=temp[i];
    
    sr_znach /= temp.size();
    
    int k = 0;
    
    for(int i=0;i<temp.size();++i){
        if(temp[i]>sr_znach)
        ++k;
    }
    
    cout << k <<endl;
    
    for(int i=0;i<temp.size();++i){
        if(temp[i]>sr_znach)
            cout << i << " ";
        }

return 0;
}
