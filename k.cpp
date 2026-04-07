#include <iostream>
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

 int count = 0;

    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=i;j<n;j++) {
            sum += nums[j];
            if(sum==k) {
                count++;
            }
        }
    }
    
cout<<count;
}