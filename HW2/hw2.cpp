/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/10/18
	Purpose(目的):輸入十個整數,然後再輸入一個數(sum),
				  並在十個數中尋找是否有任一對總和為sum
*/
#include <iostream>
#include <algorithm>

using namespace std;

//設定陣列最大長度為10
#define N 10

int main(void) {
	//陣列存放10個整數
	int num[N];
	
	for(int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	
	//將陣列中的數由小到大排列
	sort(num, num+N);
	
	int sum;
	bool found = false;
	
	//輸入一個數(sum),並在陣列中尋找是否有任一對總和為sum
	cin >> sum;
	for(int i = 0; i < N-1; ++i) {
		for(int j = i+1; j < N; ++j) {
			//找到並輸出
			if(num[i]+num[j] == sum) {
				cout << num[i] << " " << num[j] << endl;
				found = true;
			}
		}
	}
	
	//未找到
	if(!found) {
		cout << "No pair found.\n";
	}
	
	return 0;
}