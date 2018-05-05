#include<iostream>
using namespace std;
int f(int n)    //递归算法
{
    if(n<4)
        return n; //第1，2，3年，各为1，2，3头
    else
        return f(n-1)+f(n-3);  //第n年为前一年的和前3年的相加
}
int main()
{
	int n;
	while(cin>>n && n){
		int f1 = 1,f2 = 2,f3 = 3,fn;
		if(n == 1)cout<<f1<<endl;
		else if(n == 2)cout<<f2<<endl;
		else if(n == 3)cout<<f3<<endl;
		else{
			 for(int i=4; i<= n; i++)
					{
						 fn=f3+f1;
						 f1=f2;  //f1代表前3年
						 f2=f3;  //f2代表前2年
						 f3=fn;  //f3代表前1年
					}
					cout<<fn<<endl;
			}
		}
	return 0;
}
