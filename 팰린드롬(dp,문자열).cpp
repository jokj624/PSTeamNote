
#include <iostream>
using namespace std;
int dp[2001][2001];
int arr[2001];
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		dp[i][i] = 1;
	}
	for(int i=1; i<n; i++){
		if(arr[i]==arr[i+1])	dp[i][i+1] = 1;
	}
	for(int k=3; k<=n; k++){
		for(int i=0; i<=n-k+1; i++){
			int j=k+i-1;
			if(arr[i]==arr[j] && dp[i+1][j-1]==1){
				dp[i][j] = 1;
			}
		}
	}
	int m; 
	cin >> m;
	while(m--){
		int s, e;
		scanf("%d %d", &s, &e);
		if(arr[s]!=arr[e])	printf("0\n");
		else	printf("%d\n", dp[s][e]);
	}
}