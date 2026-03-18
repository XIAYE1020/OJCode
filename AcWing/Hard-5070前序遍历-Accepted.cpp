#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> PostOrder;
vector<int> InOrder;
unordered_map<int, int> InPos;

int findLstPre(int PostLeft,int PostRight,int InLeft,int InRight){
	int root = PostOrder[PostRight];
	int rootInPos = InPos[root];
	
	int RightLen = InRight - rootInPos;
	int LeftLen = rootInPos-InLeft;
	
	if(RightLen>0){//DFS right tree
		int nextInLeft = rootInPos+1;
		int nextPostLeft = PostRight - RightLen; 
		return findLstPre(nextPostLeft, PostRight-1, nextInLeft, InRight);
	}else if(LeftLen>0){//DFS left tree
		int nextInRight = rootInPos -1;
		int nextInLeft = InLeft;
		int nextPostRight = PostLeft+LeftLen-1;
		int nextPostLeft = PostLeft;
		return findLstPre(nextPostLeft,nextPostRight,nextInLeft,nextInRight);
	}else{
		return root;
	}
}

int main(){
	int N;
	cin>>N;

	PostOrder.resize(N+1);
	InOrder.resize(N+1);
	
	for(int i = 1;i<=N;i++){
		cin>>PostOrder[i];
	}
	
	for(int i = 1;i<N+1;i++){
		cin>>InOrder[i];
		InPos[InOrder[i]] = i;
	}
	
	int ans = findLstPre(1,N,1,N);
	cout<<ans<<endl;
	return 0;
}