#include<iostream>
using namespace std;
int f(int n)    //�ݹ��㷨
{
    if(n<4)
        return n; //��1��2��3�꣬��Ϊ1��2��3ͷ
    else
        return f(n-1)+f(n-3);  //��n��Ϊǰһ��ĺ�ǰ3������
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
						 f1=f2;  //f1����ǰ3��
						 f2=f3;  //f2����ǰ2��
						 f3=fn;  //f3����ǰ1��
					}
					cout<<fn<<endl;
			}
		}
	return 0;
}
