#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, D[16][1 << 16], W[16][16];
int solve(int here, int status) {
	if(status == (1 << N) - 1) return W[here][0] ? W[here][0] : 1e9;
	int &ret = D[here][status];
	if(ret) return ret;
	ret = 1e9;
	for(int i = 0; i < N; ++i) {
		if(status & (1 << i) || !W[here][i]) continue;
		ret = min(ret, solve(i, status | (1 << i)) + W[here][i]);
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d", &W[i][j]);
		}
	}
	printf("%d", solve(0, 1));
}
