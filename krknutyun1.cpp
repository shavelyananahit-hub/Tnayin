#include <iostream>
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
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
             o=true;
             break;
        }
        }
    }
    if(o>0){
        cout<<"True";
    }else cout<<"False";
}