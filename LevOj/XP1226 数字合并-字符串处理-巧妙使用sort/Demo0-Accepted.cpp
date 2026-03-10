#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool myComparation(const string& a, const string& b){
	return a+b>b+a;
}

int main(){
	int n;//amount of the input numbers
	while(cin>>n){
		if(n == 0){
			cout << '0';
			return 0;
		}
		vector<string> nums(n);//to store the input numbers
		for(int i = 0;i < n;i++){//input numbers
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end(), myComparation);
		for(int i = 0;i<n;i++){
			cout << nums[i];
		}
		cout<<endl;
	} 
	return 0;
}