/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/09/30
	Purpose(目的):輸入一個數n,執行Babylonian演算法(計算平方根的方法)五次,
				 並輸出答案至小數點後兩位
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//n是要逼近其平方根的數字
	//guess為題目中的猜測
	//r為演算法中的變數
	double n, guess, r;

	cin >> n;

	//執行五次Babylonian 演算法(計算平方根)
	guess = n / 2.00;	//step 1 (initial guess)
	for(int i = 0; i < 5; i++)
	{
		r = n / guess;	//step 2
		guess = (guess + r) / 2.00;	//step 3
	}

	//輸出答案至小數點後兩位
	cout << setprecision(2) << fixed << guess << endl;

	return 0;
}