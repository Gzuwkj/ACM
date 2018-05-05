#include<stdio.h>
#include<iostream>
#include<string.h>
#define L_son x<<1
#define R_son (x<<1) + 1
using namespace std;
const int maxn = 100005;
int tree[maxn<<2] , lazy[maxn<<2];//创建数组，tree数组和延迟数组。
int N , Q;

void built_tree(int x , int L , int R){//建数函数，不解释。
	if(L == R){
		tree[x] = 1;
//		printf("tree[%d] = %d\n" , x , tree[x]);
		return ;
	}
	int mid = (L + R) / 2;
	built_tree(L_son , L , mid);
	built_tree(R_son , mid + 1 ,R);
	tree[x] = tree[L_son] + tree[R_son];
//	printf("tree[%d] = %d\n" , x , tree[x]);
}
void push_down(int x , int L , int R){//延时操作。
	if(lazy[x] != 0){//一开始延时数组是全为0的，如果这个判断成立，说明在前面的更新中更新到了这个节点
		lazy[L_son] = lazy[x];
		lazy[R_son] = lazy[x];
//		printf("lazy[%d] = %d \nlazy[L_son %d] = %d \nlazy[R_son %d] = %d \n" , x ,lazy[x] , L_son , lazy[L_son] , R_son , lazy[R_son]);
		lazy[x] = 0;
		int mid = (L + R) / 2;
		tree[L_son] = (mid - L + 1) * lazy[L_son];
		tree[R_son] = (R - mid) * lazy[R_son];
//		printf("lazy - tree[L_son %d] = %d\n" , L_son , tree[L_son]);
//		printf("lazy - tree[R_son %d] = %d\n" , R_son , tree[R_son]);

	}
}
void update(int x , int L , int R , int U_L , int U_R , int val){
	if(U_L <= L && R <= U_R){
		tree[x] = (R - L + 1) * val;
//		printf("2 . tree[%d] = %d\n" , x , tree[x]);
		lazy[x] = val;
//		printf("lazy[%d] = %d\n" , x , lazy[x]);
		return;
	}
	push_down(x , L , R);
	int mid = (L + R) / 2;
	if(U_L <= mid) update(L_son , L , mid , U_L , U_R , val);
	if(U_R > mid ) update(R_son , mid + 1 , R , U_L , U_R , val);
	tree[x] = tree[L_son] + tree[R_son];
//	printf("1 . tree[%d] = %d\n" , x , tree[x]);
}

int main(){
	int n , cas = 0;
	scanf("%d" ,&n);
	for(int i = 1 ;i <= n;i++){
		memset(tree , 0 , sizeof(tree));
		memset(lazy , 0 , sizeof(lazy));
		scanf("%d" ,&N);
		built_tree(1 , 1 , N);
		scanf("%d" , &Q);
		while(Q--){
			int x , y , z;
			scanf("%d%d%d" , &x , &y, &z);
			update(1 , 1 , N , x , y , z);
		}
		printf("Case %d: The total value of the hook is %d.\n" , i , tree[1]);
	}
	return 0;
}
