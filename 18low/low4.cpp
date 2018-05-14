#include <bits/stdc++.h>
#define rn(x) (((long)rand()<<15) | rand()) % (x) + 1
using namespace std;
int bit[1 + (1 << 20)];
int a;
int cnt;
int main()
{
    srand(time(NULL));
    for(int te=1; te<2; te++) {
        string ins = "./4/test" + to_string(te) + ".in";
        string ous = "./4/test" + to_string(te) + ".out";
        FILE *inw = fopen(ins.c_str(), "w");
        int n;
        n = 5000000;
        for(int i=0; i<n; i++) fprintf(inw, "%ld ", rn(1<<25));
        fclose(inw);
        FILE *in = fopen(ins.c_str(), "r");
        memset(bit, 0, sizeof(bit));
        cnt = 0;
        while(~fscanf(in, "%d", &a)) {
            int x = a / 32;
            int y = a % 32;
            if(bit[x] & (1 << y))
                continue;
            cnt++;
            bit[x] |= (1 << y);
        }
        fclose(in);
        FILE *out = fopen(ous.c_str(), "w");
        fprintf(out, "%d", cnt);
        fclose(out);
    }
    return 0;
}
