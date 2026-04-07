#include <iostream>
#include <map>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter n = ";
    cin>>n;
    
    int a[n];
    cout<<"Enter a[i] = ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    bool o=false;

    map<int, int> m;

    for(int i=0;i<n;i++){
        m[a[i]]++;

        if(m[a[i]]==2){
            o=true;
            break;
        }
    }

   if(o>0){
        cout<<"True";
    }else cout<<"False";
}