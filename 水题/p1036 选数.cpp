#include<iostream>
#include<math.h>
using namespace std;
const int maxn = 25;
int num[maxn];
int vis[maxn];
int n , k , ans = 0 , sum = 0;
int is_prime (int x){
	if(x == 1) return 0;
	if(x == 2) return 1;
	for(int i = 2;i <= sqrt(x) ; i++){
		if(x % i == 0)
			return 0;
	}
	return 1;
}
void dfs (int dp , int start){
	if(dp >= k){
		cout << sum << endl;
		if(is_prime(sum))
			ans++;
		return;
	}
	for(int i = start + 1; i < n;i++)
		if(vis[i] != 0){
			vis[i] = 0;
			sum += num[i];
			dfs(dp + 1 , i);
			sum -= num[i];
			vis[i] = 1;
		}
}
int main()
{
	memset (vis , 1 , sizeof(vis));
	cin >> n >> k;
	for (int i = 0; i < n;i++) cin >> num[i];
	for (int i = 0; i < n;i++){
		sum += num[i];
		vis[i] = 0;
		dfs(1 , 0);
		sum -= num[i];
	}
	cout << ans << endl;
	return 0;
}
