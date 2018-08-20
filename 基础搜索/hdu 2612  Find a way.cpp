#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f
#include<stdio.h>
using namespace std;
const int maxn = 200 + 10;
int n , m;
char mpt[maxn][maxn];
int Y[maxn][maxn];
int M[maxn][maxn];
struct Point {
	int x , y , step , if_M;
};
const int dir[4][2] = {1 , 0 , 0 , 1 , -1 , 0 , 0 , -1};
queue<Point> q;
void bfs(){
	Point now , next;
	while(!q.empty()){
		now = q.front();
	//	cout << now.x << " " << now.y << endl;
		q.pop();
		if(mpt[now.x][now.y] == '@'){
			if(now.if_M)
				M[now.x][now.y] = min(M[now.x][now.y] , now.step);
			else
				Y[now.x][now.y] = min(Y[now.x][now.y] , now.step);
		}
		for(int i = 0;i < 4;i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(next.x >= 1 && next.y >= 1 && next.x <= n && next.y <= m && mpt[next.x][next.y] != '#'){
			//	cout << "*1" << endl;
				if(now.if_M && M[next.x][next.y] == INF){
			//		cout << "*2" << endl;
					next.step = now.step + 1;
					next.if_M = now.if_M;
					M[next.x][next.y] = next.step;
					q.push(next);
				}
				else if((!now.if_M) && Y[next.x][next.y] == INF){
			//		cout << "*3" << endl;
					next.step = now.step + 1;
					next.if_M = now.if_M;
					Y[next.x][next.y] = next.step;
					q.push(next);
				}
			}
		}
	}
}
int main(){
	while(scanf("%d %d" , &n , &m) != EOF){
		for(int i = 1;i <= n;i++){
			scanf("%s" , mpt[i] + 1);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				M[i][j] = INF;
				Y[i][j] = INF;
				if(mpt[i][j] == 'Y'){
					Point a = {i , j , 0 , 0};
					Y[i][j] = 0;
					q.push(a);
				}
				if(mpt[i][j] == 'M'){
					Point a = {i , j , 0 , 1};
					M[i][j] = 0;
					q.push(a);
				}
			}
		}
		bfs();
	/*	for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				printf("%010d " , Y[i][j]);
			}
			cout << endl;
		}
		cout << endl;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				printf("%010d " , M[i][j]);
			}
			cout << endl;
		}
		cout << endl;*/
		int ans = INF;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				if(mpt[i][j] == '@')
					ans = min(ans , (M[i][j] + Y[i][j]));
		cout << ans * 11 << endl;
	}
	return 0;
}
