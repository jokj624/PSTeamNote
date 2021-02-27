#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501];
int dp[501][501];
int n;
int solve(int x, int y) {
 	int dx[4] = {1, -1, 0, 0};
 	int dy[4] = {0, 0, 1, -1};
 	if (dp[x][y]) {
 		return dp[x][y];
 	}
 	dp[x][y] = 1;
 	for (int i = 0; i < 4; i++) {
 		int nextx = x + dx[i];
 		int nexty = y + dy[i];
 		if (nextx >= 0 && nexty >= 0 && nexty < n && nextx < n) {
 			if (arr[x][y] < arr[nextx][nexty]) {
 				dp[x][y] = max(dp[x][y], solve(nextx, nexty)+1);
 			}
 		}
 	}
 	return dp[x][y];
}
int main() {
 	scanf("%d", &n);
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < n; j++) {
 			scanf("%d", &arr[i][j]);
		}
 	}
 	int ans = 0;
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < n; j++) {
 			ans = max(ans, solve(i, j));
 		}
 	}
 	printf("%d\n", ans);
 	return 0;
}