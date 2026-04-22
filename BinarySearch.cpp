#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x){

    if(left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if(arr[mid] == x)
        return mid;

    if(x < arr[mid])
        return binarySearch(arr, left, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, right, x);
}

int main(){

    int n;
    cout << "Enter size. ";
    cin >> n;

    int arr[n];

    cout << "Enter array. " << endl;
    for(int i= 0; i<n; i++)
        cin >> arr[i];

    int x;
    cout << "Enter number. ";
    cin >> x;

    int result = binarySearch(arr, 0, n-1, x);

    if(result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;
}