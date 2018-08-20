#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int cur_left[3] , step;
};
int Full[3];
const int maxn = 101 + 10;
int vis[maxn][maxn][maxn];
const int dir[6][2] = {1 , 0 , 0 , 1 , 1 , 2 , 2 , 1 , 2 , 0 , 0 , 2};
bool check(node now){
	if(now.cur_left[0] == now.cur_left[1] && now.cur_left[0] + now.cur_left[1] == Full[0])
		return true;
	if(now.cur_left[0] == now.cur_left[2] && now.cur_left[0] + now.cur_left[2] == Full[0])
		return true;
	if(now.cur_left[1] == now.cur_left[2] && now.cur_left[1] + now.cur_left[2] == Full[0])
		return true;
	return false;
}
void turn(int &a , int &b , int F){
	 int tb = a + b > F ? F : a + b;
	 a = a + b > F ? a + b - F : 0;
	 b = tb;
}
int bfs(){
	queue<node> q;
	node now = {Full[0] , 0 , 0 , 0};
	memset(vis , 0 , sizeof(vis));
	vis[Full[0]][0][0] = 1;
	node next;

	q.push(now);
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(check(now))
			return now.step;
		for(int i = 0;i < 6;i++){
			next = now;
			turn(next.cur_left[dir[i][0]] , next.cur_left[dir[i][1]] , Full[dir[i][1]]);
			if(!vis[next.cur_left[0]][next.cur_left[1]][next.cur_left[2]]){
				vis[next.cur_left[0]][next.cur_left[1]][next.cur_left[2]] = 1;
				next.step++;
				q.push(next);
			}
		}
	}
	return -1;
}
int main(){
	while(scanf("%d %d %d" , &Full[0] , &Full[1] , &Full[2]) != EOF){
		if(Full[0] == Full[1] && Full[1] == Full[2] && Full[2] == 0)
			break;
		int ans = bfs();
		if(ans != -1)
			cout << ans << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
