#include <iostream>
#include <string>
using namespace std;

string sum(string a, string b) {
    string result = "";
    
    int i=a.length()-1;
    int j=b.length()-1;
    int d=0;

    while(i >= 0 || j >= 0 || d >0) {
        int tivA=(i>=0)?a[i]-'0':0;
        int tivB=(j>=0)?b[j]-'0':0;
        
        int s=tivA+tivB+d;
        result=char(s%10+'0')+result;
        d=s/10;

        i--;
        j--;
    }

    return result;
}

int main(){
    string a,b;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;

    cout<<"Sum = "<<sum(a,b);

    return 0;
}