#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#define rn(x) (((long)rand() << 15) | rand()) % (x) + 1
using namespace std;
vector<pair<int, int> > Cost;
int N, canGo[101][101], isOkay[101], result;
int main() {
    srand(time(NULL));
    for(int te=1; te<5; te++) {
        Cost.clear();
        N = 0;
        memset(canGo, 0, sizeof(canGo));
        memset(isOkay, 0, sizeof(isOkay));
        result = 0;
        string ins = "./2/test" + to_string(te) + ".in";
        string ous = "./2/test" + to_string(te) + ".out";
        FILE *oin = fopen(ins.c_str(), "w");
        int n = rn(100);
        fprintf(oin, "%d\n", n);
        for(int i=0; i<n; i++)
            fprintf(oin, "%ld ", rn(10000));
        for(int i=0; i<n; i++) {
            fprintf(oin, "\n");
            for(int j=0; j<n; j++)
                fprintf(oin, "%d", (rand() % 2));
        }
        fclose(oin);
        FILE *in = fopen(ins.c_str(), "r");
        fscanf(in, "%d", &N);
        Cost.resize(N);
        for(int i = 0; i < N; ++i) {
            fscanf(in, "%d", &Cost[i].first);
            Cost[i].second = i;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                fscanf(in, "%1d", &canGo[i][j]);
            }
        }
        fclose(in);
        sort(Cost.begin(), Cost.end());
    	for(int k = 0; k < N; ++k) {
    		for(int i = 0; i < N; ++i) {
    			for(int j = 0; j < N; ++j) {
    				if(canGo[i][k] && canGo[k][j]) canGo[i][j] = 1;
    			}
    		}
    	}
    	for(int i = 0; i < N; ++i) {
    		int here = Cost[i].second;
    		if(!isOkay[here]) {
    			result += Cost[i].first;
    			isOkay[here] = 1;
    			for(int next = 0; next < N; ++next) {
    				if(canGo[here][next] && canGo[next][here]) isOkay[next] = 1;
    			}
    		}
    	}
        FILE *out = fopen(ous.c_str(), "w");
    	fprintf(out, "%d", result);
        fclose(out);
    }
}
