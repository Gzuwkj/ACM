#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
const int maxn = 100;
struct node{
	int l , w;
}block[maxn];
int dp[maxn];
int cmp(node a , node b){
	if(a.l > b.l)
		return 1;
	else if(a.l == b.l)
		return a.w > b.w;
	else
		return 0;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;i++){
			int x , y;
			scanf("%d %d" , &x , &y);
			block[i].l = x > y ? x : y;
			block[i].w = x + y - block[i].l;
		}
		sort(block , block + n , cmp);
		memset(dp , 0 , sizeof(dp));
		for(int i = 0;i < n;i++){
			dp[i] = 1;
			for(int j = 0;j < i;j++){
				if(block[i].l < block[j].l && block[i].w < block[j].w){
					dp[i] = max(dp[i] , dp[j] + 1); // 最长子序列方程：每一次都要去前面的数中寻找可以加上去的位置的dp来进行比较！
				}
			}
		}
		int ans = 0;
		for(int i = 0;i < n;i++)
			ans = max(ans , dp[i]);
		cout << ans << endl;
	}
	return 0;
}
