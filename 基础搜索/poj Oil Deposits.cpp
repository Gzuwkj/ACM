#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn = 100 + 10;
const int dir[8][2] = {1 , 0 , 0 , 1 , -1 , 0 , 0 , -1 , 1 , 1 , 1 , -1 , -1 , 1 , -1 , -1};
int vis[maxn][maxn];
char mpt[maxn][maxn];
int N , M , ans;
void dfs(int x , int y){
	vis[x][y] = 1;
	for(int i = 0;i < 8;i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(nx > 0 && nx <= N && ny > 0 && ny <= M && !vis[nx][ny] && mpt[nx][ny] != '*'){
			dfs(nx , ny);
		}
	}
}
int main(){
	while(scanf("%d %d" , &N , &M) != EOF){
		if(N == M && M == 0)
			break;
		memset(vis , 0 , sizeof(vis));
		for(int i = 1;i <= N;i++)
			scanf("%s" , mpt[i] + 1);
		ans = 0;
		for(int i = 1;i <= N;i++){
			for(int j = 1;j <= M;j++){
				if(mpt[i][j] == '@' && !vis[i][j])
					ans++ , dfs(i , j);
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}
