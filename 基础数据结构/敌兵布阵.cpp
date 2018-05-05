#include<iostream>
#include<stdio.h>
#include<string.h>
#define L_son x<<1
#define R_son (x<<1) + 1
using namespace std;
const int maxn = 50005;

int tree[maxn<<2];
int arr[maxn] , ans = 0;

void built_tree(int x , int L ,int R){
	if(L == R){
		tree[x] = arr[L];
//		printf("tree[%d] = %d\n" , x , tree[x]);
		return ;
	}
	int mid = (L + R) / 2;
	built_tree(L_son , L , mid);
	built_tree(R_son , mid + 1 , R);
	tree[x] = tree[L_son] + tree[R_son];
//	printf("tree[%d] = %d\n" , x , tree[x]);
}

void Add(int x , int L , int R , int pos , int val){
	if(L == R){
		tree[x] += val;
//		printf("Addr - tree[%d] = %d\n" , x , tree[x]);
		return ;
	}
	int mid = (L + R) / 2;
	if(pos <= mid) Add(L_son , L , mid , pos , val);
	if(pos > mid ) Add(R_son , mid + 1 , R , pos , val);
	tree[x] = tree[L_son] + tree[R_son];
//	printf("Add - tree[%d] = %d\n" , x , tree[x]);
}

void Sub(int x , int L , int R , int pos , int val){
	if(L == R){
		tree[x] -= val;
//		printf("Subr - tree[%d] = %d\n" , x , tree[x]);
		return ;
	}
	int mid = (L + R) / 2;
	if(pos <= mid) Sub(L_son , L , mid , pos , val);
	if(pos > mid ) Sub(R_son , mid + 1 , R , pos , val);
	tree[x] = tree[L_son] + tree[R_son];
//	printf("Sub - tree[%d] = %d\n" , x , tree[x]);
}

void Query(int x , int L , int R , int  l ,int r){
	if(l <= L && R <= r){
		ans += tree[x];
		return ;
	}
	int mid = (L + R) / 2;
	if(l <= mid) Query(L_son , L , mid , l , r);
	if(r > mid ) Query(R_son , mid + 1 , R , l , r);
}
int main(){
	int T;
	scanf("%d" , &T);
	for(int i = 1;i <= T;i++){
		printf("Case %d:\n" , i);
		memset(tree , 0 , sizeof(tree));
		int n;
		scanf("%d" , &n);
		for(int i = 1;i <= n;i++) scanf("%d" , &arr[i]);
		built_tree(1 , 1 , n);
		char key[10];
		int cnt = 1;
		while(scanf("%s" , key) && cnt <= 40000){
			cnt++;
			if(!strcmp(key , "End"))break;
			int x , y ;
			scanf("%d %d" , &x , &y);
			if(!strcmp(key , "Add")) Add(1 , 1 , n , x , y);
			else if(!strcmp(key , "Sub")) Sub(1 , 1 , n , x , y);
			else if(!strcmp(key , "Query")){
				ans = 0;
				Query(1 , 1 , n , x , y);
				printf("%d\n" , ans);
			}
		}
	}
	return 0;
}
