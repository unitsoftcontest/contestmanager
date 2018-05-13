#include <bits/stdc++.h>
#define N 300
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr_dir;
int span[N][N];
int n;
void fill_span(int rx, int ry, int &num)
{
    int dir = 0;
    int v = 1;
    int x = rx, y = ry;
    while(v <= (n / 3)*(n / 3)) {
        span[x][y] = num++;
        v++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < rx || nx >= rx + (n / 3) || ny < ry || ny >= ry + (n / 3) || span[nx][ny])
            dir = (dir + 1) % 4;
        x += dx[dir];
        y += dy[dir];
    }
}
int main()
{
    srand(time(NULL));
    int te = 1;
    FILE *oin = fopen("./3/test4.in", "w");
    fprintf(oin, "%d", 3 *(rand() % 3 + 1));
    fclose(oin);
    FILE *in = fopen("./3/test4.in", "r");
    fscanf(in, "%d", &n);
    fclose(in);
    int cnt = 1;
    int chk[3][3] = {0, };
    int x = 0, y = 0;
    int v = 1;
    while(cnt <= 9) {
        chk[x][y] = cnt++;
        int nx = x + dx[arr_dir];
        int ny = y + dy[arr_dir];
        fill_span(x*(n / 3), y*(n / 3), v);
        if(nx < 0 || nx > 2 || ny < 0 || ny > 2 || chk[nx][ny])
            arr_dir = (arr_dir + 1) % 4;
        x += dx[arr_dir];
        y += dy[arr_dir];
    }
    FILE *out = fopen("./3/test4.out", "w");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            fprintf(out, "%6d", span[i][j]);
        }
        fprintf(out, "\n");
    }
    fclose(out);
    return 0;
}
