#include <bits/stdc++.h>
using namespace std;
int n, space;
int main()
{
    srand(time(NULL));
    FILE *oin = fopen("./2/test5.in", "w");
    fprintf(oin, "%d", rand() % 10 + 1);
    fclose(oin);
    FILE *in = fopen("./2/test5.in", "r");
    fscanf(in, "%d", &n);
    fclose(in);
    FILE *out = fopen("./2/test5.out", "w");
    for(int i=1; i<=n; i++) {
        for(int j=0; j<space; j++) fprintf(out, " ");
        for(int j=0; j<i; j++)
            fprintf(out, "*");
        fprintf(out, "\n");
        space += i - 1;
    }
    fclose(out);
    return 0;
}
