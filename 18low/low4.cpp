#include <bits/stdc++.h>
using namespace std;
int bit[1 + (1 << 20)];
int a;
int cnt;
int main()
{
    while(~scanf("%d", &a)) {
        int x = a / 32;
        int y = a % 32;
        if(bit[x] & (1 << y))
            continue;
        cnt++;
        bit[x] |= (1 << y);
    }
    cout<<cnt;
    return 0;
}
