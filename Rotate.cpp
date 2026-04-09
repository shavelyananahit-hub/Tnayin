#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"n = ";
    cin>>n;

    int a[n][n]; 
    cout<<"Matrix: "<<endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }

    for (int i=0;i<n;i++) {
        int l=0,r=n-1;
        while (l<r){
            int temp=a[i][l];
            a[i][l]=a[i][r];
            a[i][r]=temp;
            l++;
            r--;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }
}
