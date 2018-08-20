#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 200 + 10;
struct node{
	int len , wei;
	int high;
}block[maxn];
int dp[maxn];
int cmp(node a , node b){
	if(a.len > b.len)
		return 1;
	else if(a.len == b.len)
		return a.wei > b.wei;
	else
		return 0;
}
int main(){
	int n , k = 1;
	while(scanf("%d" , &n) != EOF && n){
		int x , y , z , c = 0;
		for(int i = 0;i < n;i++){
			scanf("%d %d %d" , &x , &y , &z);
			block[c].len = x , block[c].wei = y , block[c++].high = z;
			block[c].len = y , block[c].wei = x , block[c++].high = z;
			block[c].len = z , block[c].wei = x , block[c++].high = y;
			block[c].len = x , block[c].wei = z , block[c++].high = y;
			block[c].len = y , block[c].wei = z , block[c++].high = x;
			block[c].len = z , block[c].wei = y , block[c++].high = x;
		}
		sort(block , block + c , cmp);
		memset(dp , 0 , sizeof(dp));
		for(int i = 0;i < c;i++){
			dp[i] = block[i].high;
			for(int j = 0;j < i;j++){
				if(block[i].len < block[j].len && block[i].wei < block[j].wei)
					dp[i] = max(dp[i] , dp[j] + block[i].high);
			}
		}
		int ans = 0;
		for(int i = 0;i < c;i++)
			ans = max(ans , dp[i]);
		printf("Case %d: maximum height = " , k++);
		cout << ans << endl;
	}
	return 0;
}
