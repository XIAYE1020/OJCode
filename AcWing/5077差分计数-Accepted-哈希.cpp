#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
	int n,x;
	while(cin>>n>>x){
		vector<int> list(n);
		unordered_map<int,int> hashmap;
		hashmap.reserve(n);
		for(int i = 0;i<n;i++){
			cin>>list[i];
			hashmap[list[i]]++;
		}
		
		long long count = 0;
		
		for(int i = 0;i<n;i++){
			auto it = hashmap.find(list[i]-x);
			if(it!=hashmap.end()){
				count+=it->second;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}