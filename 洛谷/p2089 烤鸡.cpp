#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int ans;
int mp[10000][12];
void eme(int n , int * A , int cur){
	if(cur == 10){
		int sum = 0;
		for(int i = 0;i < 10;i++)
			sum += A[i];
		if(sum != n) return;
		for(int i = 0;i < cur;i++)
			mp[ans][i] = A[i];
		ans++;
		return;
	}
	for(int i = 1;i <= 3;i++){
		int sum = 0;
		for(int j = 0;j < cur;j++){
			sum += A[j];
		}
		if(sum + i > n)continue;
		A[cur] = i;
		eme(n , A , cur + 1);
	}
}
 int main(){
 	int n;
 	cin >> n;
	int A[15];
	if(n < 10){
		cout << "0" << endl;
		return 0;
	}
	memset(A , 0 , sizeof(A));
	ans = 0;
 	eme(n , A , 0);
 	cout << ans << endl;
 	for(int i = 0;i < ans;i++){
		for(int j = 0;j < 10;j++)
			cout << mp[i][j] << " ";
		cout << endl;
	}
	return 0;
 }
