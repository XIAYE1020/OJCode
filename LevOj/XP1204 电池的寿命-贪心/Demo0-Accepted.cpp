#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		
		int BatterySum = 0;
		int BatteryMax = 0;
		
		vector<int> battery(N,0);
		for(int i = 0; i < N;i++){
			cin >> battery[i];
			BatterySum += battery[i];
			BatteryMax = max(BatteryMax,battery[i]);
		}
		
		if(BatterySum - BatteryMax >= BatteryMax){
			cout << fixed << setprecision(1) << float(BatterySum) / 2.0 << endl;
		}else{
			cout << fixed << setprecision(1) << float(BatterySum - BatteryMax) << endl;
		}
	}
	return 0;
}