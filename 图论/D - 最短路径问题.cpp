#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF 0x3f3f3f
using namespace std;

const int maxn = 1005;

int vis[maxn];
int N , M , s , t;

struct node{
	int distence , consume;
}mpt[maxn][maxn];
node dist[maxn];
void dijkstra(){
	memset(vis , 0 , sizeof(vis));
	dist[s].distence = dist[s].consume = 0;
	for(int i = 1;i <= N;i++){
		int min_p = -1 , min_len = INF , consum;
		for(int j = 1;j <= N;j++){
			if(min_len > dist[j].distence && !vis[j]){
				min_len = dist[j].distence;
				consum = dist[j].consume;
				min_p = j;
			}
		}
		vis[min_p] = 1;
		for(int j = 1;j <= N;j++){
			if(dist[j].distence > min_len + mpt[min_p][j].distence && !vis[j]){
				dist[j].distence = min_len + mpt[min_p][j].distence;
				dist[j].consume = consum + mpt[min_p][j].consume;
			}
			if(dist[j].distence == min_len + mpt[min_p][j].distence && dist[j].consume > consum + mpt[min_p][j].consume)
				dist[j].consume = consum + mpt[min_p][j].consume;
		}
	}
}
int main(){
	while(scanf("%d%d" , &N , &M) != EOF){
		if(N == 0 && N == M) break;
		for(int i = 1;i <= N;i++){
			dist[i].distence = INF;
			dist[i].consume = INF;
			for(int j = 1;j <= N;j++){
				if(i == j) mpt[i][j].distence = mpt[i][j].consume = 0;
				else mpt[i][j].distence = mpt[i][j].consume = INF;
			}
		}

		for(int i = 1;i <= M;i++){
				int x , y , w , c;
				scanf("%d%d%d%d" , &x , &y , &w ,&c );
				if(w < mpt[x][y].distence){
					mpt[x][y].distence = w;
					mpt[y][x].distence = w;
					mpt[x][y].consume = c;
					mpt[y][x].consume = c;
				}
			}
			scanf("%d%d" , &s , &t);
			dijkstra();
			printf("%d %d\n" ,dist[t].distence , dist[t].consume);
	}
	return 0;
}
/*
5 6
1 3 1 2
2 3 1 3
2 5 2 5
3 5 7 9
1 4 2 3
4 5 2 4
*/
