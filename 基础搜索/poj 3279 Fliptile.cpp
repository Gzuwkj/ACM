#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int m , n;
const int maxn = 15 + 10;
int mpt[maxn][maxn];
int ans[maxn][maxn];
int click[maxn][maxn];
int cnt = INF;
const int dir[5][2] = {0 , 0 , 1 , 0 , 0 , 1 , -1 , 0 , 0 , -1};
int turn(int x , int y){
	int ret = mpt[x][y];
	for(int i = 0;i < 5;i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(xx >= 1 && xx <= m && yy >= 1 && yy <= n)
			ret += click[xx][yy];
	}
	return (ret % 2);
}
int dfs(){
	for(int i = 2;i <= m;i++)
		for(int j = 1;j <= n;j++)
			if(turn(i - 1 , j))
				click[i][j] = 1;
	for(int i = 1;i <= n;i++)
		if(turn(m , i)) return -1;
	int ret = 0;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
			if(click[i][j]) ret++;
	return ret;
}
int main(){
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d" , &mpt[i][j]);
	int flag = 0;
	for(int i = 0;i < (1 << n);i++){//二进制枚举！！！
		memset(click , 0 , sizeof(click));
		for(int j = 0;j < n;j++)
			click[1][j + 1] = (i >> j) & 1;
		int c = dfs();
		if(c == -1) continue;
		else if(c < cnt){
			cnt = c;
			flag = 1;
			memcpy(ans , click , sizeof(click));
		}
	}
	if(flag){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= n;j++)
				printf("%d " , ans[i][j]);
			printf("\n");
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;
	return 0;
}
