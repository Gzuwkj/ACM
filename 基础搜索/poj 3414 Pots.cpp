#include<iostream>
#include<queue>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int step;
	int A_left;
	int B_left;
	int now_opear;
};
const char base[10][10] = {"0" , "FILL(1)" , "FILL(2)" , "DROP(1)" , "DROP(2)" , "POUR(1,2)" ,"POUR(2,1)"};
struct Point {
	int last , now ;
}p[1000][10];
const int maxn = 100 + 10;
int vis[maxn][maxn] = {0};
int A , B , C , last;
int num[1000];
void init(){
	for(int i = 0;i <= 1000;i++){
		for(int j = 0;j <= 9;j++)
		p[i][j] = {0 , 0};
	}
}
int bfs(){
	queue<node> q;
	node now = {0 , 0 , 0 , 0};
	node next;
	q.push(now);
	vis[0][0] = 1;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.A_left == C || now.B_left == C){
			last = now.now_opear;
			return now.step;
		}
		if(now.A_left != A && !vis[A][now.B_left]){
			vis[A][now.B_left] = 1;
			p[now.step + 1][1] = {now.now_opear , 1};
			next = {now.step + 1 , A , now.B_left , 1};
			q.push(next);
		}
		if(now.B_left != B && !vis[now.A_left][B]){
			vis[now.A_left][B] = 1;
			p[now.step + 1][2] = {now.now_opear , 2};
			next = {now.step + 1 , now.A_left , B , 2};
			q.push(next);
		}
		if(now.A_left != 0 && !vis[0][now.B_left]){
			vis[0][now.B_left] = 1;
			p[now.step + 1][3] = {now.now_opear , 3};
			next = {now.step + 1 , 0 , now.B_left , 3};
			q.push(next);
		}
		if(now.B_left != 0 && !vis[now.A_left][0]){
			vis[now.A_left][0] = 1;
			p[now.step + 1][4] = {now.now_opear , 4};
			next = {now.step + 1 , now.A_left , 0 , 4};
			q.push(next);
		}
		if(now.A_left != 0 && now.B_left != B && !vis[(now.A_left + now.B_left - B > 0 ? now.A_left + now.B_left - B : 0)][(now.A_left + now.B_left > B ? B : now.A_left + now.B_left)]){
			vis[(now.A_left + now.B_left - B > 0 ? now.A_left + now.B_left - B : 0)][(now.A_left + now.B_left > B ? B : now.A_left + now.B_left)] = 1;
			p[now.step + 1][5] = {now.now_opear , 5};
			next = {now.step + 1 , (now.A_left + now.B_left - B > 0 ? now.A_left + now.B_left - B : 0) , (now.A_left + now.B_left > B ? B : now.A_left + now.B_left) , 5};
			q.push(next);
		}
		if(now.A_left != A && now.B_left != 0 && !vis[(now.A_left + now.B_left > A ? A : now.A_left + now.B_left)][(now.A_left + now.B_left - A > 0 ? now.A_left + now.B_left - A : 0)]){
			vis[(now.A_left + now.B_left > A ? A : now.A_left + now.B_left)][(now.A_left + now.B_left - A > 0 ? now.A_left + now.B_left - A : 0)] = 1;
			p[now.step + 1][6] = {now.now_opear , 6};
			next = {now.step + 1 , (now.A_left + now.B_left > A ? A : now.A_left + now.B_left) , (now.A_left + now.B_left - A > 0 ? now.A_left + now.B_left - A : 0) , 6};
			q.push(next);
		}
	}
	return -1;
}

int main(){
	cin >> A >> B >> C;
	int ans = bfs();
	if(ans != -1){
		cout << ans << endl;
		for(int i = ans , c = ans;i > 0;i--){
			num[c--] = p[i][last].now;
			last = p[i][last].last;
		}
		for(int i = 1;i <= ans;i++)
			cout << base[num[i]] << endl;
	}
	else
		cout << "impossible" << endl;
	return 0;
}
