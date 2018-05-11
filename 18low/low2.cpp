#include <bits/stdc++.h>
using namespace std;
int n, space;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<space; j++) cout<<" ";
        for(int j=0; j<i; j++)
            cout<<"*";
        cout<<"\n";
        space += i - 1;
    }
    return 0;
}
