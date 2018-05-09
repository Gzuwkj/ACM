#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 20000;
int vis[maxn];
int main(){
	int n;
	cin >> n; // ´ò±í³öÆæ¼££¡£¡£¡
	memset(vis , 1, sizeof(vis));
	for(int i = 2;i <= 10000 ; i++){
		if(!vis[i]) continue;
		if(vis[i])
			for(int j = 2;j * i <= 20000;j++)
				vis[i*j] = 0;
	}
	int flag = 0;
	for(int i = 2; i < n;i++){
		if(!vis[i]) continue;
		for(int j = 2;j <= n - i && n - i - j> 1;j++){
			if(!vis[j]) continue;
			if(vis[n - i - j]){
				cout << i << " " << j << " " << n - i - j << endl;
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	return 0;
}
