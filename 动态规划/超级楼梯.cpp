#include<iostream>
using namespace std;
int main()
{
	long long ans[10010] = {0};
	int n;
	cin>>n;
	ans[1] = 2;
	ans[2] = 7;
	for(int i = 3;i <= 10000;i++){
			ans[i] = ans[i - 1] + 4*(i - 1) + 1;
		}
	while(n--){
		int a;
		cin>>a;
		cout<<ans[a]<<endl;
	}
	return 0;
}
