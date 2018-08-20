#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 110;
char mpt[maxn][maxn];
int c[maxn];
int n , k;
int ans = 0;
void dfs(int r , int step){
	if(step == k){
		ans++;
		return ;
	}
	if(r > n) return ;
	else{
		for(int i = 0;i <= n;i++){
			if(mpt[r][i] == '#' && !c[i]){
				c[i] = 1;
				dfs(r + 1 , step + 1);
				c[i] = 0;
			}
		}
		dfs(r + 1 , step);
	}
}
int main(){
	while(scanf("%d %d" , &n , &k) != EOF){
		if(n == k && k == -1)
			break;
		for(int i = 1;i <= n;i++){
			scanf("%s" , mpt[i] + 1);
		}
		ans = 0;
		dfs(1 , 0);
		cout << ans << endl;
	}
	return 0;
}
/*
5 4
##.#.
.#.##
#.#..
.#.##
..###
*/
