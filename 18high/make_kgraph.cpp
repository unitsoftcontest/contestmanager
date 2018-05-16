#include <bits/stdc++.h>
#define rn(x) (((long)rand() << 15) | rand()) % (x) + 1
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
set<pair<int, int> > skg;
vector<pair<int, int> > kg;
vector<int> label;
int main()
{
    srand(time(NULL));
    for(int te = 2; te < 3; te++) {
        kg.clear();
        skg.clear();
        label.clear();
        string ins = "./3/test" + to_string(te) + ".in";
        FILE *in = fopen(ins.c_str(), "w");
        int n, k, f;
        n = 900;
        k = 60;
        f = 5600;
        // n = rn(900);
        // k = rn(60);
        // f = min((int)(rn(n * (n - 1) / 2)), 5600);
        int alpha = rn((n - k) / 10);
        fprintf(in, "%d %d %d\n", k, n, f);
        for(int i=0; i<=n; i++) label.push_back(i);
        random_shuffle(label.begin() + 1, label.end());
        vector<pair<int, int> > vec;
        for(int i=1; i<=n; i++)
            for(int j=i + 1; j<=n; j++)
                vec.push_back({i, j});
        random_shuffle(all(vec));
        for(int i=1; i<=k + alpha; i++)
            for(int j=i + 1; j<=k + alpha; j++)
                skg.insert({i, j});
        for(auto it : vec)
            if(skg.size() < f) skg.insert(it);
        for(auto it : skg) kg.push_back(it);
        random_shuffle(all(kg));
        for(auto t : kg) {
            if(rn(2) - 1) fprintf(in, "%d %d\n", label[t.x], label[t.y]);
            else fprintf(in, "%d %d\n", label[t.y], label[t.x]);
        }
        fclose(in);
    }
}
