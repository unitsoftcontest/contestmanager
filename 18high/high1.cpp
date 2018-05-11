#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
int n;
set<string> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin.clear();
    while(n--) {
        string s;
        string str;
        cin>>s;
        vector<bool> alp(26, false);
        for(int i=0; i<s.size(); i++) {
            if(alp[s[i] - 'a']) continue;
            alp[s[i] - 'a'] = true;
            str.push_back(s[i]);
        }
        sort(all(str));
        ans.insert(str);
    }
    cout<<ans.size();
    return 0;
}
