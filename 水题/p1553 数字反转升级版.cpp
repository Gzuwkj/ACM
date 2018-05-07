#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char s[25];
	cin >> s;
	int n = strlen(s) , point = 0;
	for (int i = 0; i < n ;i++){
		if ('0' <= s[i] && s[i] <= '9')
			point++;
		else break;
	}
	int p = point;
	while (s[--p] == '0' && p > 0);
	for (int i = p ; i >= 0;i--)
		cout << s[i];
	if(point == n) return 0;
	else if (point == n - 1) {cout << s[point] ; return 0;}
	else {
		cout << s[point];
		while (s[++point] == '0' && point < n - 1);
		while (s[--n] == '0' && n > point);
		for(int i = n ;i >= point;i--)
			cout << s[i];
	}
	return 0;
}
