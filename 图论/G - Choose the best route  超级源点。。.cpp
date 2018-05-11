#include<iostream>
#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f
using namespace std;

const int maxn = 1005;
int dist[maxn];
int mpt[maxn][maxn];
int vis[maxn];
int N , M , T , s;
int dijkstra(){
	memset(vis , 0 , sizeof(vis));
	dist[0] = 0;
	for(int i = 0;i <= N;i++){
/*		for(int i = 0;i <= N;i++)
			cout << "dist[" << i << "] = " << dist[i] << endl;*/
		int min_p = -1;
		int min_len = INF;
		for(int j = 0;j <= N;j++){
			if(dist[j] < min_len && !vis[j]){
				min_len = dist[j];
				min_p = j;
			}
		}
//		cout << "min_p = " << min_p << endl;
		if(min_p == T) return dist[T];
		vis[min_p] = 1;
		for(int j = 0;j <= N;j++){
			if(dist[j] > min_len + mpt[min_p][j] && !vis[j]){
				dist[j] = min_len + mpt[min_p][j];
			}
		}
	}
	return -1;
}
 int main(){
 	while(scanf("%d%d%d" , &N , &M , &T) != EOF){
		for(int i = 0;i <= N;i++){
			dist[i] = INF;
			for(int j = 0;j <= N;j++){
				if(i == j) mpt[i][j] = 0;
				else mpt[i][j] = INF;
			}
		}
		for(int i = 0;i < M;i++){
			int x , y , w ;
			scanf("%d%d%d" , &x , &y , &w);
			if(w < mpt[x][y]){
				mpt[x][y] = w;
			}
		}
		scanf("%d" , &s);
		while(s--){
			int ww;
			scanf("%d" , &ww);
			mpt[0][ww] = 0;
		}
		int ans = dijkstra();
		printf("%d\n" , ans);
 	}
	return 0;
}
