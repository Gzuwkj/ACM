#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 100 + 10;
char S1[maxn] , S2[maxn];
char res[maxn * 2];
char re[maxn * 2];
char mid1[maxn] , mid2[maxn];
int l , ans ;
void dfs(int step){
	char re[maxn * 2];
	int who = 0;int al = 1;
	for(int i = 0 , c1 = 0 , c2 = 0;i < l * 2;i++){
		re[i] = (who ? mid1[c1++] : mid2[c2++]);
		if(re[i] != res[i])
			al = 0;
		who = !who;
	}
	if(al){
		ans = step;
		return;
	}
	al = 1;
	for(int i = 0;i < l;i++){
		mid1[i] = re[i];
		if(mid1[i] != S1[i])
			al = 0;
	}
	for(int i = l;i < l * 2;i++){
		mid2[i - l] = re[i];
		if(mid2[i] != S2[i])
			al = 0;
	}
	if(al){
		ans = -1;
		return;
	}
	dfs(step + 1);
}
int main(){
	int t;
	cin >> t;
	for(int k = 1;k <= t;k++){
		scanf("%d" , &l);
		scanf("%s" , S1);
		sscanf(S1 , "%s" , mid1);
		scanf("%s" , S2);
		sscanf(S2 , "%s" , mid2);
		scanf("%s" , res);
		ans = 0;
		dfs(1);
		cout << k << " " << ans << endl;
	}
	return 0;
}
