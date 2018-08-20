#include<iostream>
using namespace std;

const int num[] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};

int f(int x){
	int sum = 0;
	if (!x) return 6;
	while(x > 0){
		int a = x % 10;
		sum += num[a];
		x /= 10;
	}
	return sum;
}

int main()
{
	int n , ans = 0;
	cin >> n;
	n = n - 4;
	for(int i = 0; i <= 1111;i++){
		for(int j = 0;j <= 1111;j++){
			int sum = i + j;
			if(f(i) + f(j) + f(sum) == n)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
