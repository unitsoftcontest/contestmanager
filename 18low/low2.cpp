#include <bits/stdc++.h>
#include <fstream>
using namespace std;
string t = "0123456789";
vector<int> spos;
int ans;
bool is_prime(int num)
{
    if(num <= 1) return false;
    for(int i=2; i*i <= num; i++)
        if(num % i == 0) return false;
    return true;
}
void prime(int cur, string str)
{
    if(cur == spos.size()) {
        ans += is_prime(atoi(str.c_str()));
        return;
    }
    for(int i=0; i<10; i++) {
        str[spos[cur]] = i + '0';
        prime(cur + 1, str);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    for(int te = 6; te < 7; te++) {
        ans = 0;
        spos.clear();
        string ins = "./2/test" + to_string(te) + ".in";
        string ous = "./2/test" + to_string(te) + ".out";
        ofstream inw;
        inw.open(ins.c_str());
        string s;
        int len = 6;
        int cnt = 0;
        inw<<"3****9";
        inw.close();
        s.clear();
        ifstream in;
        in.open(ins.c_str());
        in>>s;
        in.close();
        for(int i=0; i<s.size(); i++)
            if(s[i] == '*')
                spos.push_back(i);
        prime(0, s);
        ofstream out;
        out.open(ous.c_str());
        out<<ans;
        out.close();
    }
    return 0;
}
