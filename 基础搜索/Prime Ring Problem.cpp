#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
int n,num[20+5],vis[20+5];
bool adjust_p(int x){
    if(x==2) return true;  
    else if(x==1||x%2==0) return false;  
    else {
		for(int i=3;i<=x-1;i++)  
        	if(x%i==0)  
        		return false; 
	} 
    return true;
}
void dfs(int step){
	if(step>n&&adjust_p(num[1]+num[n])){
		for(int i = 1;i <= n-1;i++)
			cout<<num[i]<<" ";
		cout<<num[n]<<endl;
	}
	else{
		for(int i = 2;i <= n;i++){
			num[step]=i;
			if(adjust_p(num[step]+num[step-1])&&vis[i]==0){
				vis[i]=1;  step++;
				dfs(step); 
				vis[i]=0;  step--;	
			}
		}
	}	
}
int main(){
	int c=1;
	while(cin>>n){
		cout<<"Case "<<c<<" :"<<endl;
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		num[1]=1;
		dfs(2);
		cout<<endl;
		c++;
	}
	return 0;
} 
