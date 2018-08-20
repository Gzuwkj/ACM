#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int A , B , C , num[10];
	cin >> A >> B >> C;
	int a = (987 / C) * A + 1 , flag = 0;
	for(int i = 123; i <= a;i++){
		if(i % A != 0) continue;
		int x = i , cnt = 1;
		while(x > 0){ num[cnt++] = x % 10; x /= 10; }
		x = B * (i / A);
		while(x > 0){ num[cnt++] = x % 10; x /= 10; }
		x = C * (i / A);
		while(x > 0){ num[cnt++] = x % 10; x /= 10; }
		sort (num + 1, num + 10);
		cnt = 10;
		while(num[--cnt] == cnt)
			if(cnt == 1){
				flag = 1;
				cout << i << " " << (i / A) * B << " " << (i / A) * C << endl;
			}
	}
	if (!flag) cout << "No!!!" << endl;
	return 0;
}
