#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 205;
int k[maxn];
int vis[maxn];
int N , S , T , cnt;
struct node{
	int floor , step;
	node(int x , int y):floor(x) , step(y){}
};

int bfs(){
	memset(vis , 0 , sizeof(vis));
	queue<node>q;
	node now(S , 0);
	q.push(now);
	vis[S] = 1;
	while(!q.empty()){
		now = q.front();
 //		cout << "now_floor = " << now.floor << endl;
		if(now.floor == T) return now.step;
		q.pop();
		vis[now.floor] = 1;
		for(int i = -1;i <= 1;i += 2){
			int next_floor = now.floor + i * k[now.floor];
			if(next_floor > 0 && next_floor <= N && !vis[next_floor]){
				node temp(next_floor , now.step + 1);
				vis[next_floor] = 1;
				q.push(temp);
			}
		}
	}
	return -1;
}

int main(){
	while(scanf("%d" , &N) != EOF){
		if(!N) break;
		scanf("%d%d" , &S , &T);
		for(int i = 1;i <= N;i++)
			scanf("%d" , &k[i]);
		cnt = 0;
		int ans = bfs();
		printf("%d\n" , ans);
	}
	return 0;
}
