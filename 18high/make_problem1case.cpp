#include <bits/stdc++.h>
#define rn(x) ((int)rand() % (x)) + 1
#define all(x) x.begin(), x.end()
using namespace std;
set<string> ss;
void save_string(int cur, string s)
{
    ss.insert(s);
    if(cur == 20) return;
    s.push_back(cur + 'a');
    save_string(cur + 1, s);
    s.pop_back();
    save_string(cur + 1, s);
}
int main()
{
    srand(time(NULL));
    ss.insert("");
    save_string(0, "");
    ss.erase(ss.begin());
    vector<string> st;
    for(auto it : ss) st.push_back(it);
    for(int te=7; te<8; te++) {
        random_shuffle(all(st));
        string ins = "./1/test" + to_string(te) + ".in";
        string ous = "./1/test" + to_string(te) + ".out";
        ofstream infile(ins.c_str());
        auto n = rn(1000);
        infile<<n<<endl;
        for(int i=0; i<n; i++) {
            string pick = st[0];
            int picksize = pick.size();
            string p = pick;
            int lenp = max((rn(1000)), (int)p.size());
            while(p.size() < lenp) p.push_back(pick[(rand() % picksize)]);
            random_shuffle(all(p));
            infile<<p;
            if(i != n-1) infile<<" ";
        }
        infile.close();
        set<string> ans;
        ifstream inputfile(ins.c_str());
        inputfile>>n;
        cin.clear();
        while(n--) {
            string s;
            string str;
            inputfile>>s;
            vector<bool> alp(26, false);
            for(int i=0; i<s.size(); i++) {
                if(alp[s[i] - 'a']) continue;
                alp[s[i] - 'a'] = true;
                str.push_back(s[i]);
            }
            sort(all(str));
            ans.insert(str);
        }
        inputfile.close();
        ofstream out(ous.c_str());
        out<<ans.size();
        out.close();
    }
}
