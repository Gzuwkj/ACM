#include<queue>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF 0x3f3f3f
using namespace std;

const int maxn = 105;
int mpt[maxn][maxn];
int dist[maxn] , vis[maxn];
int N , M;



void spfa(){
	queue<int>q;
	q.push(1);
	dist[1] = 0;
	memset(vis , 0 , sizeof(vis));
	while(!q.empty()){
		int now = q.front();
		q.pop();
		vis[now] = 0;
		for(int i = 1;i <= N;i++)
			if(dist[i] > dist[now] + mpt[now][i]){
				dist[i] = dist[now] + mpt[now][i];
				if(!vis[i]){
					q.push(i);
					vis[i] = 1;
				}
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
			spfa();
			printf("%d\n" , dist[N]);
	}
	return 0;
}
