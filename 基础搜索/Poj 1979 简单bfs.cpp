#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int w , h , ans = 0;
const int maxn= 20 + 10;
char mpt[maxn][maxn];
int vis[maxn][maxn];
struct Point {
	int x , y;
}S;
const int dir[4][2] = {1 , 0 , 0 , 1 , -1 , 0 , 0 , -1};
bool Check(Point now){
	if(now.x < 1 || now.y < 1 || now.x > h || now.y > w)
		return false;
	if(vis[now.x][now.y])
		return false;
	if(mpt[now.x][now.y] == '#')
		return false;
	return true;
}
void bfs(){
	queue<Point> q;
	q.push(S);
	vis[S.x][S.y] = 1;
	Point now , next;
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(int i = 0;i < 4;i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(Check(next)){
				ans++;
				vis[next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
}
int main(){
	while(scanf("%d %d" , &w , &h) != EOF){
		if(w == h && h == 0)
			break;
		memset(vis , 0 , sizeof(vis));
		for(int i = 1;i <= h;i++){
			scanf("%s" , mpt[i] + 1);
			for(int j = 1;j <= w;j++)
				if(mpt[i][j] == '@')
					S.x = i , S.y = j;
		}
		ans = 1;
		bfs();
		printf("%d\n" , ans);
	}
	return 0;
}
