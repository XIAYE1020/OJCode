#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	string strAZ;
	while(cin>>strAZ){
		stack<int> stk;//a=0 b=1 c=2....z=25
		int i;
		int preMaxCh = -1;
		for(i = 0;i<26;i++){
			char curCh = strAZ[i];
			preMaxCh=max(preMaxCh,strAZ[i-1]-'a');
			
			if(stk.empty()){//stk is empty
				if(i!=0){
					for(int j = preMaxCh + 1;j<(curCh-'a');j++){
						stk.push(j);
					}
					continue;
				}else if(i==0){
					for(int j = 0;j<(curCh-'a');j++){
						stk.push(j);
					}
					continue;
				}

			}
			
			//stk isnt empty
			int topCh = stk.top();
			if (topCh > (curCh-'a')){
				break;
			}else if(topCh==(curCh-'a')){
				stk.pop();
				continue;
			}else{//topCh<curCh
				for(int j = preMaxCh + 1;j<(curCh-'a');j++){
					stk.push(j);
				}
			}
		}
		if(i==26){
			cout<<"yes"<<endl;
		}else{
			cout<< i <<"no"<<endl;
		}
	}
	return 0;
}