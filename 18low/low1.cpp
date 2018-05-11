#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int k=0; k<i; k++) {
            for(int j=1; j<i; j++) cout<<" ";
            cout<<"*\n";
        }
    }
    return 0;
}
