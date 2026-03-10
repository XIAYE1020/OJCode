#include<iostream>
#include<string>
#include<stack>
using namespace std;

int charToNum(char x){
	if(x=='+'||x=='-'){
		return 1;
	}else{// * /
		return 2;
	}
}

int strToNum(string x){
	int len = x.size();
	int sum=0;
	for(int i=0;i<len;i++){
		sum=sum*10+(x[i]-'0');
	}
	return sum;
}

bool symCmp(const char& a, const char& b){//compare a and b, who has the priority
	int aNum = charToNum(a);
	int bNum = charToNum(b);
	
	if(aNum>=bNum){//a is prior
		return true;
	}else{
		return false;
	}
}

int calculate(int num1,int num2,char sym){
	if(sym=='+'){
		return num1+num2;
	}
	if(sym=='-'){
		return num1-num2;
	}
	if(sym=='*'){
		return num1*num2;
	}
	if(sym=='/'){
		return num1/num2;
	}
	return 0;
}

int main(){
	string exp;
	while(cin>>exp){
		int len = exp.size();
		stack<int> numStack;
		stack<char> symStack;
		for(int i = 0; i < len; i++){
			if(exp[i]>='0'&&exp[i]<='9'){//is a nummber, push into numStack
				string fullNum;
				while(exp[i]>='0'&&exp[i]<='9'){
					fullNum+=exp[i];
					i++;
				}
				i--;
				int num = strToNum(fullNum);
				numStack.push(num);
			}else{//is a symble
			    while (!symStack.empty() && symCmp(symStack.top(), exp[i])) {
			        char tempSym = symStack.top();
			        symStack.pop();
			        int num2 = numStack.top();
			        numStack.pop();
			        int num1 = numStack.top();
			        numStack.pop();
			        numStack.push(calculate(num1, num2, tempSym));
			    }
			    symStack.push(exp[i]); 
			}
		}
		while(!symStack.empty()){
			char tempSym = symStack.top();
			symStack.pop();
			int num2 = numStack.top();
			numStack.pop();
			int num1 = numStack.top();
			numStack.pop();
			int numCal = calculate(num1,num2,tempSym);
			numStack.push(numCal);
		}
		cout<<numStack.top()<<endl;
	}
	return 0;
}