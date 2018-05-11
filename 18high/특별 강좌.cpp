#include <cstdio>
#include <vector>
#include <algorithm>
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
	scanf("%d %d %d", &K, &N, &F);
	for(int i = 1; i <= F; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		rel[u][v] = rel[v][u] = 1;
	}
	for(int i = 1; i <= N; ++i) {
		friends.clear();
		fill_n(visited, 909, false);
		visited[i] = 1;
		friends.push_back(i);
		if(solve(i)) {
			for(int j = 0; j < friends.size(); ++j) printf("%d\n", friends[j]);
			return 0;
		}
	}
	printf("-1");
}
