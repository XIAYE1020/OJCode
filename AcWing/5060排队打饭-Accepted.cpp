#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct student{
	int id;
	long long arrive;//the time he arrive
	long long time;//time to get food
	long long wait;//the time he can wait
}student;

bool myCompare(const student& a, const student& b){//FIFO
	return a.arrive<b.arrive;
}

int main(){
	int n;//n students
	cin>>n;
	if(n==0){
		return 0;
	}
	vector<student> StudentList(n);
	vector<long long> StartTime(n,-2);

	for(int i = 0;i<n;i++){
		StudentList[i].id=i;//record the origin order
		cin>>StudentList[i].arrive>>StudentList[i].time>>StudentList[i].wait;//input
	}
	
	sort(StudentList.begin(),StudentList.end(),myCompare);//sort from first to last by the time of arrival
	
//	for(int i = 0;i<n;i++){
//		cout<<StudentList[i].id<<StudentList[i].arrive<<StudentList[i].time<<StudentList[i].wait<<endl;//record the origin order
//	}
	
	long long time = 1;
	for(int i = 0;i<n;i++){//from first to last by the time of arrival
		if(time<=StudentList[i].arrive){//its No.i student's turn
			StartTime[StudentList[i].id] = StudentList[i].arrive;
			time = StudentList[i].arrive + StudentList[i].time;
		}else if(time<=(StudentList[i].arrive+StudentList[i].wait)){
			StartTime[StudentList[i].id] = time;
			time = time+StudentList[i].time;
		}else if(time>(StudentList[i].arrive+StudentList[i].wait)){
			StartTime[StudentList[i].id] = -1;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<StartTime[i]<<' ';
	}
	cout<<endl;
	return 0;
}