#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,x;
	while(cin>>n>>x){
		vector<int> list(n);
		for(int i = 0;i<n;i++){
			cin>>list[i];
		}
		
		int count = 0;
		
		sort(list.begin(),list.end());
		
		for(int i = 0;i<n;i++){
			for(int j = n-1;j>=0;j--){
				if(list[i]-list[j]==x){
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}