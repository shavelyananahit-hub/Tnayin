#include <iostream>
#include <cmath>
using namespace std;

double function(string f,double x) {
    if (f=="square") return x*x;
    if (f=="sin") return sin(x);
    if (f=="exp") return exp(x);
    if (f=="log") return log(x);
    return x;
}

double deriv(string f,double x) {
    if (f=="square") return 2*x;
    if (f=="sin") return cos(x);
    if (f=="exp") return exp(x);
    if (f=="log") return 1/x;
    return 1;
}

int main() {
    int n;
    cout<<"n = ";
    cin>>n;

    string f[n];
    cout<<"Functions: ";
    for (int i=0;i<n;i++) 
    cin>>f[i];

    double x;
    cout<<"x = ";
    cin>>x;

    double val[n];
    val[0]=x;

    for (int i=n-1,j=1;i>=0;i--,j++) {
        val[j]=function(f[i],val[j-1]);
    }

    double res=1;
    for (int i=0;i<n;i++) {
        res*=deriv(f[i],val[n-1-i]);
    }
    cout<<res;
}
