#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    
    vector <vector<string> > spisok_del(31);
    
    int q;
    cin >> q;
    
    string comanda;    
    int month = 0; // текущий месяц
    
    for (int i=0; i<q;++i){
        
        cin >> comanda;
        
        if(comanda == "ADD"){ // назначаем дело на к-ый день месяца
             
            int k; 
            string delo;
            cin >> k >> delo;
            
            spisok_del[k-1].push_back(delo);           
        }
        
        if(comanda == "DUMP"){ // выводим все дела, запланированный на к-ый день месяца
            
            int k; 
            cin >> k;
            
            cout << spisok_del[k-1].size(); 
            
            for(int i=0; i<spisok_del[k-1].size();++i)
            cout << " " << spisok_del[k-1][i];
             
            cout << endl;        
        }
    
        if( comanda == "NEXT"){  //переходим на следующий месяц          
       
        ++month;
        
        if (month==12) month=0;
        
        if (month==1){                
            spisok_del[27].insert(spisok_del[27].end(),spisok_del[28].begin(), spisok_del[28].end());
`           spisok_del[27].insert(spisok_del[27].end(),spisok_del[29].begin(), spisok_del[29].end());
            spisok_del[27].insert(spisok_del[27].end(),spisok_del[30].begin(), spisok_del[30].end());                
            spisok_del.resize(28);           
        }        
        else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {                          
            spisok_del.resize(31);                
            } else {
            spisok_del[29].insert(spisok_del[29].end(),spisok_del[30].begin(), spisok_del[30].end());                
            spisok_del.resize(30);
            } 
        }        
   }  
    
   return 0;
}
