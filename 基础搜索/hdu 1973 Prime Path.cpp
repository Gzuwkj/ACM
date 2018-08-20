#include<iostream>
#include<queue>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
int n , m , ans = 0;
int prime[10000 + 10] = {1};
int vis[10000 + 10];
struct node{
	int x , step;
};
bool i_a(int a , char * b , int c){
	int k = 0;
	while(a > 0){
		b[k++] = (char)(a % 10 + '0');
		a /= 10;
	}
	return true;
}
int if_equal(char * a , char * b){
 	int cnt = 0;
	for(int i = 0;i < strlen(a);i++)
		if(a[i] == b[i])
			cnt++;
	return cnt;
 }
int bfs(){
	queue<node> q;
	node now = {n , 0};
	node next;
	q.push(now);
	char buff1[10] , buff2[10];
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.x == m)
			return now.step;
		i_a(now.x , buff2 , 10);
		for(int i = 1000;i <= 9999;i++){
			if(prime[i] && !vis[i]){
				i_a(i , buff1 , 10);
				if(if_equal(buff1 , buff2) == 3){
					vis[i] = 1;
					next = {i , now.step + 1};
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main(){
	memset(prime , 1 , sizeof(prime));
	for(int i = 1;i <= 9999;i++){
		if(!prime[i]) continue;
		if(i == 1) prime[i] = 0;
		else
			for(int j = 2;j * i <= 9999;j++)
				prime[j * i] = 0;
	}
	int t;
	cin >> t;
	while(t--){
		memset(vis , 0 , sizeof(vis));
		scanf("%d %d" , &n , &m);
		ans = bfs();
		cout << ans << endl;
	}
	return 0;
}
