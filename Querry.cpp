#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int q; 
    cin >> q;
    vector <bool> worry;
        
    for(int i=0; i<q;++i){
        
        string s;
        cin >> s;
      
        if (s == "WORRY_COUNT"){ //кол-во беспокоящихся в очереди
            
            int worry_count = 0;
          
            for(int i=0;i<worry.size();++i){
                if(worry[i])
                ++worry_count;
            }          
            cout << worry_count << endl;        
        }
        else{   
             
        int k;
        cin >> k;  
            
        if(s=="COME") // добавляем (или убираем) людей в конец очереди
           worry.resize(worry.size()+k,0);
            
        if(s=="QUIET") // к-ый человек - успокоившийся
            worry[k] = 0;
            
        if(s=="WORRY") // к-ый человек - беспокоющийся
            worry[k]= 1;        
        }                 
    }    
return 0;
}
