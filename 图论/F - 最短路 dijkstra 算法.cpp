#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF 0x3f3f3f
using namespace std;

const int maxn = 105;
int mpt[maxn][maxn];
int dist[maxn] , vis[maxn];
int N , M;
void dijkstra(){
	dist[1] = 0;
	memset(vis , 0 , sizeof(vis));
	for(int i = 1;i <= N;i++){
		int min_p = -1 , min_len = INF;
		for(int j = 1;j <= N;j++)
			if(min_len > dist[j] && !vis[j]){
				min_len = dist[j];
				min_p = j;
			}
		vis[min_p] = 1;
		if(min_p == -1) break;
		for(int j = 1;j <= N;j++)
			if(dist[j] > min_len + mpt[min_p][j] && !vis[j]){
				dist[j] = min_len + mpt[min_p][j];
			}
	}
}


int main(){
	while(scanf("%d%d" , &N , &M) != EOF){
		if(N == 0 && N == M) break;
		for(int i = 1;i <= N;i++){
			dist[i] = INF;
			for(int j = 1;j <= N;j++){
				if(i == j)mpt[i][j] = 0;
				else mpt[i][j] = INF;
			}
		}

		for(int i = 1;i <= M;i++){
				int x , y , w ;
				scanf("%d%d%d" , &x , &y , &w);
				if(w < mpt[x][y]){
					mpt[x][y] = w;
					mpt[y][x] = w;
				}
			}
			dijkstra();
			printf("%d\n" , dist[N]);
	}
	return 0;
}

