/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/12/24
	Purpose(目的):編寫一個基於template的class實現item的集合.
*/
#include <iostream>
using namespace std;

template<typename T>
class Set {
	public:
		Set();	//constructor
		~Set();	//destructor
		bool in(T item);	//檢查item是否已在集合中
		void add(T item);	//增加一個新的item到集合中
		int getNum(void);	//取得集合中item的個數
	private:
		T *array;	//型態為T的array
		int size;	//array的大小(item個數)
};

int main(void) {
	int intNum, strNum, num;
	string str;
	Set<int> intSet;
	Set<string> strSet;
	
	//輸入integer個數與string個數
	cin >> intNum >> strNum;
	//讀入integers
	for(int i = 0; i < intNum; ++i) {
		cin >> num;
		//加到集合中
		intSet.add(num);
	}
	//輸出integer set的elements數量
	cout << intSet.getNum() << endl;
	
	//讀入strings
	for(int i = 0; i < strNum; ++i) {
		cin >> str;
		//加到集合中
		strSet.add(str);
	}
	//輸出string set的elements數量
	cout << strSet.getNum() << endl;
	return 0;
}

/**
	constructor,進行初始化.
*/
template<typename T>
Set<T>::Set() {
	size = 0;
}

/**
	destructor,釋放已分配的記憶體.
*/
template<typename T>
Set<T>::~Set() {
	delete[] array;
	array = NULL;
}

/**
	檢查item是否已在集合中.
	
	@param 型態為T的item
	@return true or false
*/
template<typename T>
bool Set<T>::in(T item) {
	for(int i = 0; i < size; ++i) {
		if(array[i] == item) {
			return true;
		}
	}
	return false;
}

/**
	增加一個新的item到集合中.
	
	@param 型態為T的item
*/
template<typename T>
void Set<T>::add(T item) {
	//檢查item是否已在集合中
	if(in(item) == false) {
		//記錄原始資訊
		T *temp = new T[size];
		int tempSize = size;
		for(int i = 0; i < tempSize; ++i) {
			temp[i] = array[i];
		}

		//size加1以增加新的item
		++size;
		//重新分配適當大小
		array = new T[size];
		//複製資料到新的array
		for(int i = 0; i < tempSize; ++i) {
			array[i] = temp[i];
		}
		//放入新的item
		array[size-1] = item;
		//釋放已分配的記憶體
		delete[] temp;
		temp = NULL;
	}
}

/**
	取得集合中item的個數.
	
	@return 集合中item的個數.
*/
template<typename T>
int Set<T>::getNum(void) {
	return size;
}