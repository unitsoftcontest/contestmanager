#include <bits/stdc++.h>
#define INT (((long long)1<<31) - 1)
#define rn(x) rand() % (x) + 1
#define brn(y) (((rand() << 15) | rand()) % (y))
using namespace std;
int ans;
int a, b, c;
int n, m;
void f(int k, int l, int cur)
{
    if(k > n || l > m) return;
    ans = max(ans, cur);
    f(k + 1, l, cur ^ b);
    f(k, l + 1, cur ^ c);
}
int main()
{
    srand((unsigned)time(NULL));
    FILE *oin = fopen("./5/test1.in", "w");
    fprintf(oin, "%lld %lld %lld\n", brn(INT), brn(INT), brn(INT));
    fprintf(oin, "%d %d", brn(INT), brn(INT));
    fclose(oin);
    FILE *in = fopen("./5/test1.in", "r");
    fscanf(in, "%d %d %d", &a, &b, &c);
    fscanf(in, "%d %d", &n, &m);
    n = min(1, n);
    m = min(1, m);
    fclose(in);
    FILE *out = fopen("./5/test1.out", "w");
    f(0, 0, a);
    fprintf(out, "%d", ans);
    fclose(out);
    return 0;
}
