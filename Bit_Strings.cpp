#include<bits/stdc++.h>
using namespace std;
long long Mod = 1e9+7;

int power(long long base, long long expo){
    long long result = 1;
    while(expo){
        if(expo & 1){
            result = (base * result) % Mod;
        }
        base = (base * base) % Mod;
        expo = expo>>1;
    }
    return result;
}
int main() {
	int n;
	cin>>n;
	
	cout<<power(2, n);
}