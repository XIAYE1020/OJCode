#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int x = 0;x<T;x++){
		int N;
		cin>>N;
		list<int> listN;
		for(int i = 1; i <= N;i++){
			listN.push_back(i);
		}
		auto it = listN.begin();
		while(!listN.empty()){
			for(int i =1;i<3;i++){
				it++;
				if(it==listN.end()){
					it = listN.begin();
				}
			}
			cout<<*it<<' ';
			it = listN.erase(it);
			if(it==listN.end()){
				it = listN.begin();
			}
		}
		cout<<endl;
	}
	return 0;
}