#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#define pow dp*dp
#define high pow - dp + 1
#define LL long long
using namespace std;
int main (){
	int T , cas;
	LL int n;
	cas = 0;
	cin >> T;
	while(T--){
		cin >> n;
		LL dp = sqrt(n);
		if(pow != n) dp++;
	//	cout << "dp = " << dp << endl;
		if(n >  high && n <= pow){
			if(!(dp % 2))
				cout << "Case " << ++cas << ": " << dp << " " << dp - (n - pow + dp - 1) << endl;
			else
				cout << "Case " << ++cas << ": " << dp - (n - pow + dp - 1) << " " << dp << endl;
		}
		else if(n <= high && n > (dp - 1)*(dp - 1)){
			if(!(dp % 2))
				cout << "Case " << ++cas << ": " << dp - (high - n) << " " << dp << endl;
			else
				cout << "Case " << ++cas << ": " << dp << " " << dp - (high - n) << endl;
		}
	}
	return 0;
}
