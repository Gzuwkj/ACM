#include<stdio.h>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N , M , T;
const int maxn = 10 + 10;
struct Point{
	int x , y , z , step;
};
const int dir[4][2] = {1 , 0 , 0 , 1 , -1 , 0 , 0 , -1};
char mpt[2][maxn][maxn];
int vis[2][maxn][maxn];
int bfs(){
	queue<Point> q;
	vis[0][1][1] = 1;
	Point now = {1 , 1 , 0 , 0};
	Point next;
	q.push(now);
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(mpt[now.z][now.x][now.y] == 'P')
			return now.step;
		if(now.step + 1 > T) continue;
		for(int i = 0;i < 4;i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(next.x < 1 || next.y < 1 || next.x > N || next.y > M) continue;
			if(vis[now.z][next.x][next.y]) continue;
			if(mpt[now.z][next.x][next.y] == '*') continue;
			if(mpt[now.z][next.x][next.y] == '#'){
				if(mpt[!now.z][next.x][next.y] ==  'P') return now.step + 1;
				if(mpt[!now.z][next.x][next.y] ==  '.'){
					if(vis[!now.z][next.x][next.y]) continue;
					vis[now.z][next.x][next.y] = vis[!now.z][next.x][next.y] = now.step + 1;
					next = {next.x , next.y , !now.z , now.step + 1};
					q.push(next);
				}
			}
			else{
				next = {next.x , next.y , now.z , now.step + 1};
				vis[next.z][next.x][next.y] = now.step + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		memset(vis , 0 , sizeof(vis));
		scanf("%d %d %d" , &N , &M , &T);
		for(int i = 1;i <= N;i++)
			scanf("%s" , mpt[0][i] + 1);
		for(int i = 1;i <= N;i++)
			scanf("%s" , mpt[1][i] + 1);
		int ans = bfs();
		if(ans != -1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
