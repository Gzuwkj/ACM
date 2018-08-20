#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#include<string.h>

using namespace std;
char key[15];
char article[1000005];

int main(){
	gets(key);
	gets(article);
	printf("%s\n" , key);
	printf("%s\n" , article);
	int len2 = strlen(article);
	for(int i = 1 ;i < len2 ; i++){
		article[i] = tolower(article[i]);
		}
	int j = 0;
	for(int i = 0;i < strlen(key);i++){
		if(isalpha(key[i])){
			key[j] = tolower(key[i]);
			j++;
			}
		}
	key[j] = '\0';
	for(int i = len2 ; i > 0;i--)
		article[i] = article[i - 1];
	article[0] = ' ';
	printf("%s\n" , article);
	char * p = article;
	int len = strlen(key) , cnt = 0 , min_l = 0xffff;
	while((p = strstr(p , key)) != NULL){
		int len3 = strlen(p);
		int u = len2 - len3;
		cout<<"len2 = "<<len2<<" len3 = "<<len3<<endl;
		if(article[u] == ' ' && (p[len] == ' ' || p[len] == '\0')){
			if(min_l > u) min_l = u;
			cnt++;
			}
		p = p + len;
	}
	if(cnt)
		cout<<cnt<<" "<<min_l<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
