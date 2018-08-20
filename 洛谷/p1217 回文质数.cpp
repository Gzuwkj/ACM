#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

char buf[10];
bool vis[100000001] = {false};
//优化：先枚举出质数，再从中找回文数。
int is_palindrome(int x){
	sprintf(buf , "%d" , x);
		int n = strlen(buf);
		for(int  j = 0;j < (n + 1) / 2; j++)
			if(buf[j] != buf[n - 1 - j])
				return 0;
	return 1;
}
int main(){
	int a , b ;
	cin >> a >> b;
	if(b > 10000000) b = 10000000;
	for(int i = 2;i < b / 2;i++){
		if(vis[i])continue;
		for(int j = 2;j * i <= b;j++)
			vis[i * j] = true;
	}
	if(a % 2 == 0) a += 1;
	for(int i = a;i <= b;i += 2){
		if(!vis[i] && is_palindrome(i))
			cout << i << endl;
	}
	return 0;
}
