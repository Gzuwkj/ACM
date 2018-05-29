#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stack>
#include<string>
using namespace std;
int main(){
	int T;
	cin >> T;
	for(int i = 1;i <= T;i++){
		printf("Case %d:\n" , i);
		stack<string>a;
		stack<string>b;
		a.push("http://www.lightoj.com/");
		char key[10];
		while(1){
			scanf("%s" , key);
			if(!strcmp(key , "VISIT")){
				string temp;
				cin >> temp;
				while(!b.empty()) b.pop();
				a.push(temp);
				cout << a.top() << endl;
			}
			else if(!strcmp(key , "BACK")){
				if(a.size() == 1){
					cout << "Ignored" << endl;
					continue;
				}
				string temp = a.top();
				a.pop();
				b.push(temp);
				cout << a.top() << endl;
			}
			else if(!strcmp(key , "FORWARD")){
				if(b.empty()){
					cout << "Ignored" << endl;
					continue;
				}
				string temp = b.top();
				b.pop();
				a.push(temp);
				cout << a.top() << endl;
			}
			else break;
		}
	}
	return 0;
}
