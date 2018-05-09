#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 5005;
struct apple{
	int hight , consume;
} tree[maxn];

int cmp(apple a , apple b){
	return a.consume < b.consume;
}
int main()
{
	int a , b , n , s , tot = 0;
	cin >> n >> s >> a >> b;
	for(int i = 0;i < n;i++) cin >> tree[i].hight >> tree[i].consume;
	sort(tree , tree + n , cmp);
	for(int i = 0;i < n;i++){
		if(b + a >= tree[i].hight && s >= tree[i].consume && s){
			tot++;
			s -= tree[i].consume;
		}
	}
	cout << tot << endl;
	return 0;
}
