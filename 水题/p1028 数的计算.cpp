#include<iostream>
using namespace std;
int main(){
	int F[1005] = {1};
	F[1] = 1;
	F[2] = 2;
	for(int i = 3;i <= 1000 ;i++){
		F[i] = 1;
		for(int j = i / 2 ;j > 0;j--)
			F[i] += F[j];
	}
	int x;
	cin >> x;
	cout << F[x];
	return 0;
}
