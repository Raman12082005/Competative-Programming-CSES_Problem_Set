#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    int fact = 1;
    while(n != 1){
        fact = fact * n;
        n--;
    }
    return fact;
}
int main(){
    string str = "";
    cin>>str;
    
    map<char, int> m;
    for(int i=0; i<str.size(); i++) m[str[i]]++;
    
    int permutation = factorial(str.size());
    str = "";
    for(auto it : m){
        permutation = permutation / factorial(it.second);
        for(int i=0; i<it.second; i++) str += it.first;
    }
    
    cout<<permutation<<endl;
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(), str.end()));
}