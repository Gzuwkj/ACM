#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1000 + 10;
char mpt[maxn][maxn];
int fire[maxn][maxn];
int vis[maxn][maxn];
struct Point {
	int x , y , step;
};
int r , c;
const int dir[4][2] = {1 , 0 , 0 , 1 , -1 , 0 , 0 , -1};

queue<Point> f;
void f_bfs(){
	Point now , next;
	while(!f.empty()){
		now = f.front();
		f.pop();
		for(int i = 0;i < 4;i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(next.x >= 1 && next.y >= 1 && next.x <= r && next.y <= c && mpt[next.x][next.y] != '#'){
				if(fire[next.x][next.y] == INF){
					next.step = now.step + 1;
					fire[next.x][next.y] = now.step + 1;
					f.push(next);
				}
			}
		}
	}
}

int bfs(Point J){
	queue<Point> q;
	q.push(J);
	Point now , next;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.x == 1 || now.y == 1 || now.x == r || now.y == c)
			return now.step + 1;
		for(int i = 0;i < 4;i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(next.x >= 1 && next.y >= 1 && next.x <= r && next.y <= c && mpt[next.x][next.y] != '#'){
				if(!vis[next.x][next.y] && now.step + 1 < fire[next.x][next.y]){
					vis[next.x][next.y] = 1;
					next.step = now.step + 1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Point J , F;
		scanf("%d %d" , &r , &c);
		memset(vis , 0 , sizeof(vis));
		for(int i = 1;i <= r;i++)
			scanf("%s" , mpt[i] + 1);
		for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++){
			fire[i][j] = INF;
			if(mpt[i][j] == 'J'){
				vis[i][j] = 1;
				J = {i , j , 0};
			}
			if(mpt[i][j] == 'F'){
				F = {i , j , 0};
				fire[i][j] = 0;
				f.push(F);
			}
		}
		f_bfs();
		int ans = bfs(J);
		if(ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
