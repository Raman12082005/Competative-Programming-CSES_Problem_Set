#include<bits/stdc++.h>
using namespace std;
int main(){
    string s, pattern;
    cin>>s>>pattern;

    int n = s.size(), m = pattern.size();
    int len =0;
    int i = 1;
    vector<int> lps(m, 0);
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }

    int txtidx = 0;
    int patidx = 0;
    int occurrences = 0;
    while(txtidx < n){
        // if character matches
        if(s[txtidx] == pattern[patidx]){
            txtidx++;
            patidx++;
        }
        if(patidx == m){
            occurrences++;

            // continue search for the next match
            patidx = lps[patidx-1];
        }
        // Mismatch after some matches
        else if(txtidx < n && s[txtidx] != pattern[patidx]){
            if(patidx != 0){
                patidx = lps[patidx-1];
            }
            else{
                txtidx++;
            }
        }
    }

    cout<<occurrences<<endl;
    return 0;
}