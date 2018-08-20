#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct Point{
	int z , y , x , step;
}now , next , E;
const int dir[6][3] = {{1 , 0 , 0}  , {-1 , 0 , 0}  , {0 , 1 , 0} , {0 , -1 , 0} , {0 , 0 , 1} , {0 , 0 , -1}};
const int maxn = 40;
int vis[maxn][maxn][maxn];
char mpt[maxn][maxn][maxn];
int L , R , C , ans = 0;


bool Check(Point temp){
	if(temp.x < 1 || temp.x > C || temp.y < 1 || temp.y > R || temp.z < 1 || temp.z > L)
		return false;
	if(vis[temp.z][temp.y][temp.x])
		return false;
	if(mpt[temp.z][temp.y][temp.x] == '#')
		return false;
	return true;
}
int bfs(){
	queue<Point> q;
	q.push(now);
	vis[now.z][now.y][now.x] = 1;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.x == E.x && now.y == E.y && now.z == E.z){
			return now.step;
		}
		for(int i = 0;i < 6;i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			next.z = now.z + dir[i][2];
			if(Check(next)){
				vis[next.z][next.y][next.x] = 1;
				next.step = now.step + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main(){
	while(scanf("%d %d %d" , &L , &R , &C) != EOF){
		if(L == R && R == C && C == 0)
			break;
		memset(vis , 0 , sizeof(vis));
		for(int i = 1;i <= L;i++){
			for(int j = 1;j <= R;j++){
				for(int k = 1;k <= C;k++){
					cin >> mpt[i][j][k];
					if(mpt[i][j][k] == 'S')
						now = {i , j , k , 0};
					if(mpt[i][j][k] == 'E')
						E = {i , j , k , 0};
				}
			}
		}
		ans = bfs();
		if(ans != -1)
			printf("Escaped in %d minute(s).\n" , ans);
		else
			cout << "Trapped!" << endl;
	}
	return 0;
}
