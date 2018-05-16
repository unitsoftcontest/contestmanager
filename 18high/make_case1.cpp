#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#define rn(x) (((long)rand() << 15) | rand()) % (x) + 1
using namespace std;
vector<int> friends;
int K, N, F, rel[909][909], visited[909];
bool solve(int cur) {
  if(friends.size() >= K) return true;
  for(int i = 1; i <= N; ++i) {
    if(!visited[i]) {
      bool flag = true;
      for(int j = 0; j < friends.size(); ++j) {
        if(!rel[i][friends[j]]) {
          flag = false;
          break;
        }
      }
      if(flag) {
        visited[i] = true;
        friends.push_back(i);
        if(solve(i)) return true;
      }
    }
  }
  return false;
}
int main() {
    srand(time(NULL));
    for(int te=1; te<6; te++) {
        friends.clear();
        N = K = F = 0;
        memset(rel, 0, sizeof(rel));
        memset(visited, 0, sizeof(visited));
        string ins = "./3/test" + to_string(te) + ".in";
        string ous = "./3/test" + to_string(te) + ".out";
        //FILE *oin = fopen(ins.c_str(), "w");
        //
        //fclose(oin);
        FILE *in = fopen(ins.c_str(), "r");
        fscanf(in, "%d %d %d", &K, &N, &F);
        for(int i = 1; i <= F; ++i) {
            int u, v;
            fscanf(in, "%d %d", &u, &v);
            rel[u][v] = rel[v][u] = 1;
        }
        fclose(in);
        FILE *out = fopen(ous.c_str(), "w");
        for(int i = 1; i <= N; ++i) {
            friends.clear();
            fill_n(visited, 909, false);
            visited[i] = 1;
            friends.push_back(i);
            if(solve(i)) {
                for(int j = 0; j < friends.size(); ++j) fprintf(out, "%d\n", friends[j]);
                goto at;
            }
        }
        fprintf(out, "-1");
        at:
            fclose(out);
    }
}
