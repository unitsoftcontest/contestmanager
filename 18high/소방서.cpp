#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > Cost;
int N, canGo[101][101], isOkay[101], result;
int main() {
	scanf("%d", &N);
	Cost.resize(N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", &Cost[i].first);
		Cost[i].second = i;
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%1d", &canGo[i][j]);
		}
	}
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
	printf("%d", result);
}
