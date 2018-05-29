#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
template <class T1>
class Double_end_queue{
	public:
		const int length;
		int now_element_number;
		T1 * str;
		Double_end_queue(int len);
		~Double_end_queue();
		bool Push_Front(T1 element);
		bool Push_Back(T1 element);
		bool Pop_Front();
		bool Pop_Back();
		T1 Front();
		T1 Back();
};
template <class T1>
Double_end_queue<T1>::Double_end_queue(int len):length(len) , now_element_number(0){
	if(len == 0)
		str = NULL;
	else
		str = new T1[len];
}
template <class T1>
Double_end_queue<T1>::~Double_end_queue(){ if(str) delete []str;}
template <class T1>
bool Double_end_queue<T1>::Push_Front(T1 element){
	if(now_element_number < length){
		for(int i = now_element_number;i > 0;i--)
			str[i] = str[i - 1];
		str[0] = element;
		now_element_number++;
		return true;
	}
	return false;
}
template <class T1>
bool Double_end_queue<T1>::Push_Back(T1 element){
	if(now_element_number < length){
		str[now_element_number] = element;
		now_element_number++;
		return true;
	}
	return false;
}
template <class T1>
T1 Double_end_queue<T1>::Front(){
	return str[0];
}
template <class T1>
T1 Double_end_queue<T1>::Back(){
	return str[now_element_number - 1];
}
template <class T1>
bool Double_end_queue<T1>::Pop_Front(){
	if(now_element_number == 1){
		now_element_number--;
		return true;
	}
	else if(now_element_number){
		for(int i = 0;i < now_element_number - 1;i++)
			str[i] = str[i + 1];
		now_element_number--;
		return true;
	}
	return false;
}
template <class T1>
bool Double_end_queue<T1>::Pop_Back(){
	if(now_element_number){
		str[now_element_number - 1] = 0;
		now_element_number--;
		return true;
	}
	return false;
}
int main(){
	int T  , len , M;
	while(scanf("%d" , &T) != EOF){
		for(int i = 1;i <= T;i++){
			cout << "Case " << i << ":" << endl;
			scanf("%d%d" , &len , &M);
			Double_end_queue<int>q(len);
			for(int j = 0;j < M;j++){
				char key[15];
				int s;
				scanf("%s" , key);
				if(!strcmp(key , "pushLeft")){
					scanf("%d" , &s);
					if(q.Push_Front(s))
						cout << "Pushed in left: " << q.Front() << endl;
					else
						cout << "The queue is full" << endl;
				}
				else if(!strcmp(key , "pushRight")){
					scanf("%d" , &s);
					if(q.Push_Back(s))
						cout << "Pushed in right: " << q.Back() << endl;
					else
						cout << "The queue is full" << endl;
				}
				else if(!strcmp(key , "popLeft")){
					int a = q.Front();
					if(q.Pop_Front())
						cout << "Popped from left: " << a << endl;
					else
						cout << "The queue is empty" << endl;
				}
				else if(!strcmp(key , "ls"))
					cout << q.now_element_number << endl;
				else {
					int a = q.Back();
					if(q.Pop_Back())
						cout << "Popped from right: " << a << endl;
					else
						cout << "The queue is empty" << endl;
				}
			}
		}
	}
	return 0;
}
