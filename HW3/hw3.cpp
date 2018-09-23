/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/10/27
	Purpose(目的):寫一個sort函式,並利用call by reference,
				  功能為重新排列參數值.
*/
#include <iostream>
using namespace std;

void swapGreater(int& a, int& b);
void sort(int& a, int& b, int& c);
 
int main(void) {
	int a, b, c;
 
	cin >> a >> b >> c;
	sort(a, b, c);
	cout << "a = " << a << endl
		 << "b = " << b << endl
		 << "c = " << c << endl;
 
	return 0;
}

/**
	若a > b則交換兩數.
	
	@param 要比較的兩個整數
*/
void swapGreater(int& a, int& b) {
	if(a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
}

/**
	重新排列參數值,使得a < b < c
	
	@param 三個需要排列的整數
*/
void sort(int& a, int& b, int& c) {
	swapGreater(a, b);
	swapGreater(a, c);
	swapGreater(b, c);
}