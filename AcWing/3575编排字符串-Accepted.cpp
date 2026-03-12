#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){
	list<string> strList;
	string curStr;
	int listCount = 0;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>curStr;
		listCount++;
		strList.push_front(curStr);
		while(listCount>4){
			strList.pop_back();
			listCount--;
		}
		int num = 0;
		for(auto it = strList.begin();it!=strList.end();it++){
			num++;
			cout<<num<<"="<<*it<<' ';
		}
		cout<<endl;
	}
	return 0;
//	while(cin>>curStr){
//		listCount++;
//		strList.push_front(curStr);
//		while(listCount>n){
//			strList.pop_back();
//			listCount--;
//		}
//		int num = 0;
//		for(auto it = strList.begin();it!=strList.end();it++){
//			num++;
//			cout<<num<<"="<<*it<<' ';
//		}
//		cout<<endl;
//	}
}