#include<iostream>
#include<string>
using namespace std;
int N;
string code;

bool invo(string str1){
	for(int i = 0; i <= N-4; i++){
		if(str1[i]=='2'&&str1[i+1]=='0'&&str1[i+3]=='1'&&str1[i+4]=='2'){
			return true;
		}
	}
	return false;
}

string swapCode(string& str1, int i,int j){
	char temp = str1[j];
	str1[j] = str1[i];
	str1[i] = temp;
	return str1;
}

int backTrack(string path, int start, int swaptimes){
	if(invo(path)){
		return swaptimes;
	}
	
	for(int i = start+1;i<N;i++){
		path = swapCode(start,i);
		backTrack(path,start+1 ,swaptimes+1);
		path = swapCode(start,i);
	}
	return -1;
}

int main(){
	cin>>N;
	cin>>code;
	
	int ans;
	ans = backTrack(code,0,0);
	
	cout<<ans<<endl;
	
	return 0;
}