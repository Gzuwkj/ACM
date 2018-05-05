#include<iostream>
using namespace std;

/*struct p{
	int a,b;
};
int ans = 0;
p s;

void dfs(int a){
	if(a == s.b){
		ans++;
		return;
	}
	else{
		if(a + 2 <= s.b)
			dfs(a + 2);
		if(a + 1 <= s.b)
			dfs(a + 1);
	}
}*/
int main()
{
	int k;
	cin>>k;
	long long ans[55] = {0};
		ans[1] = 1;
		ans[2] = 1;
		for( int i = 3;i <= 54;i++){
			ans[i] = ans[i - 1] + ans[i -2];
		}
	while(k--){
	/*	ans = 0;
		cin>>s.a>>s.b;
		dfs(s.a);
		cout<<ans<<endl;*/
		int a,b;
		cin>>a>>b;
		if(a == b) cout<<ans[0]<<endl;
		else cout<<ans[b - a + 1]<<endl;

	}
	return 0;
}
