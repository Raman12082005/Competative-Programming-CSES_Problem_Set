#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	
	long long count = 0;
	long long sum = 1;
	long long factor = 5;
	
	while(sum){
	    sum = n/factor;
	    count += sum;
	    factor *= 5;
	}
	cout<<count;
}