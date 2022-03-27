#include <iostream>

using namespace std;

int Factorial(int n){
    
    int result  = 1;
    
for (int i=1; i<=n; i++){
    result *=i; }
    
    return result;    
}

int main(){
    
    int x;
    cin >> x;
    
    if(x>0)
    cout << Factorial(x);
    else 
    cout << 1;
    
return 0;
}
