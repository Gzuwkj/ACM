#include<string>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
string temp(32 , 0);
string goal(32 , 0);
struct node{
	string status;
	int step;
};
/* 思路 ， 由于每一次都是从所有数里面选出4个来填空，所以可以采用bfs，采用map标记，进行判重，也可以使用hash判重*/
void Move (string &t , int val){
	for(int i = 0;i < 32;i++)
	if(t[i] == val){
	//	cout << "*" << endl;
		t[i] = 0;
		return ;
	}
}
int bfs(){
	queue<node> q;
	node now , next;
	now = {temp , 0};
	map<string , int> mp;
	int mpcnt = 1;
	mp[temp] = mpcnt++;
	q.push(now);
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.status == goal)
			return now.step;
		for(int i = 0;i < 32;i++){
			if(now.status[i] == 0 && now.status[i - 1] != 0 && now.status[i - 1] % 10 != 7){
				next = now;
				Move(next.status , now.status[i - 1] + 1);
				next.status[i] = now.status[i - 1] + 1;
				if(mp.find(next.status) == mp.end()){
					next.step++;
					mp[next.status] = mpcnt++;
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main(){
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 7;j++)
			goal[i * 8 + j] = (i + 1) *10 + j + 1;
	int t , x;
	cin >> t;
	while(t--){
		for(int i = 0;i < 4;i++){
			temp[i * 8] = (i + 1) * 10 + 1;
			for(int j = 1;j < 8;j++){
				scanf("%d" , &x);
				if(x % 10 == 1) temp[i * 8 + j] = 0;
				else temp[i * 8 + j] = x;
			}
		}
		printf("%d\n" , bfs());
	}

	return 0;
}
