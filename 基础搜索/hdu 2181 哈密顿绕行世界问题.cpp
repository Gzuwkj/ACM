#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 30;
int m , ans = 0;
struct node{
	int next[5];
}mp[maxn];
int vis[maxn] = {0};
int temp[maxn];
void dfs(int str , int step){
	temp[step] = str;
	if(step == 20 && str == m){
		printf("%d: " , ++ans);
		for(int i = 0;i <= 20;i++)
			printf(" %d" , temp[i]);
		cout << endl;
	}
	if(step > 20) return;
	for(int i = 0;i < 3;i++){
		if(!vis[mp[str].next[i]]){
			vis[mp[str].next[i]] = 1;
			dfs(mp[str].next[i] , step + 1);
			vis[mp[str].next[i]] = 0;
		}
	}
}
int main(){
	for(int i = 1;i <= 20;i++)
		scanf("%d %d %d" , &mp[i].next[0] , &mp[i].next[1] , &mp[i].next[2]);
	memset(vis , 0 , sizeof(vis));
	while(scanf("%d" , &m) && m)
		dfs(m , 0);
	return 0;
}
