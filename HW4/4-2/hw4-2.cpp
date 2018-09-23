/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/12/04
	Purpose(目的):輸入第一個Subscriber的資訊,再輸入第二個Subscriber的名稱.
				  將第一個Subscriber assigned給第二個Subscriber,
				  然後reset第一個Subscriber,輸出兩個Subscriber的資訊.
*/
#include <iostream>
#include <string>
using namespace std;

class Subscriber {
	public:
		Subscriber();  //constructor
		~Subscriber(); //destructor
		void setName(void);
		void setChannel(void);
		string getName(void);
		void output(void);	//輸出名稱及訂閱頻道資訊
		void reset(void);
		void operator =(const Subscriber& a);
	private:
		string name;		//Subscriber的名稱
		int numChannels;	//Subscriber訂閱的頻道數
		string *channelList;//Subscriber訂閱的頻道名稱(dynamic array)
};

int main(void) {
	Subscriber A, B;
	
	//輸入第一個Subscriber的資訊
	A.setName();
	A.setChannel();	
	//輸入第二個Subscriber的名稱
	B.setName();
	
	//將第一個Subscriber assigned給第二個Subscriber
	B = A;	
	//reset第一個Subscriber
	A.reset();
	
	//輸出兩個Subscriber的資訊
	A.output();
	cout << endl;
	B.output();
	
	return 0;
}

/**
	constructor,進行初始化.
*/
Subscriber::Subscriber() {
	name.clear();
	numChannels = 0;
	channelList = NULL;
}

/**
	destructor,釋放已分配的記憶體.
*/
Subscriber::~Subscriber() {
	delete [] channelList;
	channelList = NULL;
}

/**
	輸入並設定Subscriber的名稱.
*/
void Subscriber::setName(void) {
	cin >> name;
}

/**
	輸入並設定Subscriber的訂閱頻道資訊.
*/
void Subscriber::setChannel(void) {
	cin >> numChannels;
	//動態分配記憶體
	channelList = new string[numChannels];
	for(int i = 0; i < numChannels; ++i) {
		cin >> channelList[i];
	}
}

/**
	回傳Subscriber的名稱.
	
	@return Subscriber的名稱
*/
string Subscriber::getName(void) {
	return name;
}

/**
	輸出名稱及訂閱頻道資訊.
*/
void Subscriber::output(void) {
	cout << getName() << ":\n"
		 << "numChannels: " << numChannels << endl
		 << "channelList:\n";
	for(int i = 0; i < numChannels; ++i) {
		cout << channelList[i] << endl;
	}
}

/**
	重設訂閱頻道資訊.
*/
void Subscriber::reset(void) {
	//訂閱頻道數設為0
	numChannels = 0;
	//訂閱頻道名稱設為空
	delete [] channelList;
	channelList = NULL;
}

/**
	overloaded assignment operator,
	複製訂閱頻道資訊
	
	@param 在等號右邊的運算元
*/
void Subscriber::operator =(const Subscriber& a) {
	numChannels = a.numChannels;
	channelList = new string[numChannels];
	for(int i = 0; i < numChannels; ++i) {
		channelList[i] = a.channelList[i];
	}
}