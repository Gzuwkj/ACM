#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int N , M;
const int maxn = 105;
int pre[maxn] ;

struct node{
	int beg , en , distanc;
}village[maxn];

int cmp(node a , node b){
	return a.distanc < b.distanc;
}

int Find(int x){
	return (pre[x] == x) ? x : pre[x] = Find(pre[x]);//�õݹ�ʵ��·��ѹ�������ݹ��������ᱬջ
}

int Find2(int x){//��ѭ��ʵ��·��ѹ��
	int root_x = x;
	while (pre[root_x] != root_x)//�����ѭ�����ҵ�x �ĸ��ڵ�
		root_x = pre[root_x];

	int now_x = x , temp;//�����ѭ����ʵ��·��ѹ��
	while (now_x != root_x){
		temp = pre[now_x];
		pre[now_x] = root_x;
		now_x = temp;
	}
	return root_x;
}

int main(){
 	while(scanf("%d%d" , &N , &M) != EOF){
		if(!N) break;
		for(int i = 0;i <= M; i++)
			pre[i] = i;
		for(int i = 0;i < N;i++)
			scanf("%d%d%d" , &village[i].beg , &village[i].en , &village[i].distanc);
		sort(village , village + N , cmp);
		int tot = 0;
		long long int sum = 0;
		for(int i = 0;i < N;i++){
			int prex = Find2(village[i].beg);
			int prey = Find2(village[i].en);
			if(prex != prey){
				pre[prey] = prex;
				sum += village[i].distanc;
				tot++;
			}
		}
		if(tot == M - 1) printf("%lld\n" , sum);
		else printf("?\n");
 	}
	return 0;
 }
