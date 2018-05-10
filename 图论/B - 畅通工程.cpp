#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int maxn = 1005;
struct c{
	int first , tail;
} city[maxn];
int pre[maxn];

int Find(int x){
	return (pre[x] == x) ? x : pre[x] = Find(pre[x]);
}
int main(){
	int N , M;
	while(scanf("%d" , &N) != EOF){
		if(!N) break;
		scanf("%d", &M);
		for(int i = 0;i <= N;i++)
			pre[i] = i;

		for(int i = 1;i <= M;i++)
			scanf("%d%d" , &city[i].first , &city[i].tail);

		int total = 0;
		for(int i = 1;i <= M;i++){
			int prex = Find(city[i].first);
			int prey = Find(city[i].tail);
			if(prex != prey){
				pre[prey] = prex;
				total++;
			}
		}
		printf("%d\n" , N - 1 - total);
	}
	return 0;
}
