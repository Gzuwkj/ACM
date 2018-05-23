#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
bool is_leapyear(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
char* is_week(int now){
	if(now == 0) return "Sunday";
	if(now == 1) return "Monday";
	if(now == 2) return "Tuesday";
	if(now == 3) return "Wednesday";
	if(now == 4) return "Thursday";
	if(now == 5) return "Friday";
	if(now == 6) return "Saturday";
}
int month[13] = {0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 ,31};
int main(){
	int now;
	while(scanf("%d" , &now) != EOF){
		if(now == -1) break;
		now++;
		int week = 6 , now_month = 1 , now_year = 2000;
		while(true){
			int flag = 1;
			for(int i = 1;i <= 12;i++){
				if(now - month[i] > 0){
					now -= month[i];
					week = (week + month[i]) % 7;
					now_month = i % 12 + 1;
				}
				else{
					flag = 0;
					break;
				}
			}
			if(flag){
				if(is_leapyear(++now_year)) month[2] = 29;
				else month[2] = 28;
			}
			else break;
		}
		week = (week + now - 1) % 7;
		printf("%d-%02d-%02d %s\n" , now_year , now_month , now , is_week(week));
		month[2] = 29;
	}
	return 0;
}
