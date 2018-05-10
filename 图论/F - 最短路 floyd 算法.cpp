#include<iostream>
#include<stdio.h>
#include<algorithm>
#define INF 0x3f3f3f
using namespace std;

const int maxn = 105;
int mpt[maxn][maxn];
int N , M;
void floyd(){
	for(int k = 1;k <= N;k++)
		for(int i = 1;i <= N;i++)
			for(int j = 1;j <= N;j++){
				mpt[i][j] = min(mpt[i][k] + mpt[k][j] , mpt[i][j] );
			}
}

int main(){
	while(scanf("%d%d" , &N , &M) != EOF){
		if(N == 0 && N == M) break;
		for(int i = 1;i <= N;i++)
			for(int j = 1;j <= N;j++){
				if(i == j)mpt[i][j] = 0;
				else mpt[i][j] = INF;
			}
		for(int i = 1;i <= M;i++){
				int x , y , w ;
				scanf("%d%d%d" , &x , &y , &w);
				if(w < mpt[x][y]){
					mpt[x][y] = w;
					mpt[y][x] = w;
				}
			}
			floyd();
			printf("%d\n" , mpt[1][N]);
	}
	return 0;
}
