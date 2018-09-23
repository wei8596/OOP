/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/12/04
	Purpose(目的):定義一個名為Vector2D的class,儲存二維向量的資訊,
				  並把* operator做overload,回傳兩向量的內積.
*/
#include <iostream>
using namespace std;

class Vector2D {
	public:
		void setXY(void);
		int operator *(const Vector2D& b);
	private:
		int x, y;
};

int main(void) {
	Vector2D A, B;
	
	//輸入vector A的components
	A.setXY();
	//輸入vector B的components
	B.setXY();
	//輸出內積結果
	cout << A * B << endl;
	
	return 0;
}

/**
	輸入並設定x,y向量.
*/
void Vector2D::setXY(void) {
	cin >> x >> y;
}

/**
	回傳二維向量內積的結果
	
	@param 要計算內積的第二個向量
	@return 內積的結果
*/
int Vector2D::operator *(const Vector2D& b) {
	return(x*b.x + y*b.y);
}