#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 10005;
struct c{
	int first , tail , distance;
} city[maxn];
int pre[maxn];

int Find(int x){
	return (pre[x] == x) ? x : pre[x] = Find(pre[x]);//用递归实现路径压缩，但递归层数过多会爆栈
}
int cmp(c a , c b){
	return a.distance < b.distance;
}
int main(){
	int N , M;
	while(scanf("%d" , &N) != EOF){
		if(!N) break;
		for(int i = 0;i <= N;i++)
			pre[i] = i;
		int m;
		m = N*(N - 1)/2;
		for(int i = 0;i < m;i++){
			scanf("%d%d%d" , &city[i].first , &city[i].tail , &city[i].distance);
			}
		sort(city , city + m , cmp);
		int total = 0;
		long long int sum = 0;
		for(int i = 0;i < m;i++){
			int prex = Find(city[i].first);
			int prey = Find(city[i].tail);
			if(prex != prey){
				pre[prey] = prex;
				sum += city[i].distance;
			}
		}
		printf("%lld\n" , sum);
	}
	return 0;
}
