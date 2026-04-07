#include <iostream>
using namespace std;

bool anagram(char a[],char b[]) {
    int count1[26];
    int count2[26];

    for(int i=0;i<26;i++) count1[i]=0;
    for(int i=0; i < 26; i++) count2[i]=0;

    int i=0;
    while(a[i] !='\0') {
        count1[a[i]-'a']++;
        i++;
    }

    i=0;
    while(b[i] !='\0') {
     count2[b[i]-'a']++;
      i++;
    }

    for(int j=0;j<26;j++) {
        if(count1[j] != count2[j])
        return false;
    }

    return true;
}

int main() {
    int n=6;
    char strs[n][10]={"eat","tea","tan","ate","nat","bat"};
    
    bool xmb[n];

    for(int i=0;i<n;i++) xmb[i]=false;

    for(int i=0;i<n;i++) {
        if(xmb[i]>0) continue;

        cout<<"[";
        cout<<strs[i];
        xmb[i]=true;

        for(int j=i+1;j<n;j++) {
            if(xmb[j]==0 && anagram(strs[i],strs[j])) {
                cout << "," << strs[j];
                xmb[j] = true;
            }
        }

        cout<<"] ";
    }
    
    return 0;
}