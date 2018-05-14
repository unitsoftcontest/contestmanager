/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    FILE *oin = fopen("./1/test5.in", "w");
    fprintf(oin, "%d", rand() % 100 + 1);
    fclose(oin);
    FILE *in = fopen("./1/test5.in", "r");
    int n;
    fscanf(in, "%d", &n);
    fclose(in);
    FILE *out = fopen("./1/test5.out", "w");
    for(int i=1; i<=n; i++) {
        for(int k=0; k<i; k++) {
            for(int j=1; j<i; j++) fprintf(out, " ");
            fprintf(out, "*\n");
        }
    }
    fclose(out);
    return 0;
}
*/


#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int k=0; k<i; k++) {
            for(int j=1; j<i; j++) printf(" ");
            printf("*\n");
        }
    }
    return 0;
}
