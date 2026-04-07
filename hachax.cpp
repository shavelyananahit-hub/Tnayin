#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n,k;
cout<<"Enter k = ";
cin>>k;

cout<<"Enter n = ";
cin>>n;

int nums[n];
cout<<"Enter nums[n] = ";
for(int i=0;i<n;i++)
cin>>nums[i];

    unordered_map<int,int> a;

    for(int i=0;i<n;i++){
        a[nums[i]]++;
    }

    for(int b=0;b<k;b++){
        int max=0;
        int num=0;

        for (auto d:a){
          if (d.second>max){
             max=d.second;
             num=d.first;
           }
         }

        cout<<num<<" ";
        
        a[num]=-1;
    }
}