#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define L_son x<<1
#define R_son (x<<1) + 1

const int maxn = 200000 + 5;
int tree[maxn<<2];
int arr[maxn];
int n , m , ans;

void built_tree(int x , int l , int r){
	if(l == r){
		tree[x] = arr[l];
		return ;
	}
	int mid = (l + r) / 2;
	built_tree(L_son , l , mid);
	built_tree(R_son , mid + 1,r);
	tree[x] = max(tree[L_son] , tree[R_son]);
}


void update(int x , int l , int r , int point , int val){
	if( l >= r ){
		tree[x] = val;
		return;
	}
	int mid = ( l + r )/ 2;
	if(point <= mid) update(L_son , l , mid , point , val);
	if(point > mid ) update(R_son , mid + 1 , r , point , val);
	tree[x] = max(tree[L_son] , tree[R_son]);
}


void inquiry(int x , int  l , int r , int L , int R ){
	if(L <= l &&  R >= r){
		ans = max(ans , tree[x]);
		return ;
	}
	int mid = (l + r) / 2;
	if(L <= mid) inquiry(L_son , l , mid , L , R);
	if(R > mid ) inquiry(R_son , mid + 1 , r ,  L , R);
}

int main(){
	while(scanf("%d%d",&n , &m) != EOF){
		for(int i = 1;i <= n;i++)scanf("%d",&arr[i]);
		built_tree(1 , 1 , n);
		while(m--){
			ans = 0;
			char key;
			int a , b;
			scanf("%s" , &key);
			scanf("%d%d",&a , &b);
			if(key == 'U'){
				update(1 , 1 , n , a , b);
			}
			else {
				inquiry(1 , 1 , n , a , b);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
