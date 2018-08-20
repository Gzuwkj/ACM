#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(){
	string word;
	int cnt[30] = {0} , maxn = 0;
	for(int k = 0;k < 4;k++){
		getline(cin , word);
		int n = word.size();
		for (int i = 0; i < n ;i++)
			if (isalpha(word[i])){
				int a = word[i] - 'A';
				cnt[a]++;
				if(cnt[a] > maxn) maxn = cnt[a];
			}
	}
	for(int i = maxn; i > 0;i--){
		for(int j = 0 ; j < 26 ; j++ ){
			if(cnt[j] >= i) cout<<"* ";
			else cout<<"  ";
		}
		cout<<endl;
	}
	cout << "A";
	for(int i = 1; i < 26;i++)
		cout << " " << (char)('A' + i) ;
	cout<<endl;
	return 0;
}
