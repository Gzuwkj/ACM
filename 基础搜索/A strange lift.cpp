#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int K[200+5],vis[200+5]={0},dir[2]={-1,1};
int N,A,B;
struct fl{
	int floor,min_count;
};
int bfs(){
	queue<fl>q;
	fl s1={A,0},s2;
	vis[s1.floor] = 1;
	q.push(s1);
	while(!q.empty()){
		s1 = q.front();
		if(s1.floor == B){
			cout << s1.min_count << endl;
			return 0;
		}
		else{
			for(int i = 0 ;i < 2;i++){
				s2.floor = s1.floor + (dir[i] * K[s1.floor]);
				if(s2.floor > 0 && s2.floor <= N && !vis[s2.floor]){
					vis[s2.floor] = 1;
					s2.min_count = s1.min_count + 1;
					q.push(s2);
				}
			}
		}
		q.pop();
	}
	return -1;
}
int main(){
	while(cin>>N && N){
		cin>>A>>B;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= N;i++){
		cin>>K[i];
		}
		int p = bfs();
		if(p)cout<<p<<endl;
	}
	return 0;
}
