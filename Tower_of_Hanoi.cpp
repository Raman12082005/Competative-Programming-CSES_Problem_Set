#include<bits/stdc++.h>
using namespace std;
void th(int n, int s, int e, int a){
    // base case
    if(n==1){
        cout<<s<<" "<<e<<endl;
        return;
    }
    
    th(n-1, s, a, e);
    cout<<s<<" "<<e<<endl;
    th(n-1, a, e, s);
}
int main() {
	int n;
	cin>>n;
	
	cout<<(1<<n)-1<<endl;
	th(n, 1, 3, 2);
}