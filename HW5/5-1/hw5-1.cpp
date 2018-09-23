/**
	Author(作者):范真瑋
	Version(版本):1.0
	Date(日期):2017/12/24
	Purpose(目的):Graph為基本class,增加BarGraph和LineGraph作為Graph的衍生class.
				  每個class都包含成員函式erase和draw.
				  每個成員函式輸出訊息告知正在調用什麼函式以及當前調用對象屬於哪個class.
				  需把基本class的draw function宣告為virtual function.
*/
#include <iostream>
using namespace std;

//基本class Graph
class Graph {
	 public:
		/**
			輸出erase訊息.
		*/
		void erase(void) {
			cout << "Graph erase\n";
		}
		/**
			宣告為virtual function.
		*/
		virtual void draw(void) {

		}
};

//衍生class BarGraph
class BarGraph : public Graph {
	public:
		/**
			輸出BarGraph draw訊息.
		*/
		void draw(void) {
			cout << "BarGraph draw\n";
		}
};

//衍生class LineGraph
class LineGraph : public Graph {
	public:
		/**
			輸出LineGraph draw訊息.
		*/
		void draw(void) {
			cout << "LineGraph draw\n";
		}
};

using std::cout;
int main(void) {
	BarGraph bar;
	Graph *gb = &bar;
	cout <<
		"Derived class BarGraph object calling draw() and erase().\n";
	gb->draw();
	gb->erase();

	LineGraph line;
	Graph *gl = &line;
	cout <<
		"\nDerived class LineGraph object calling draw() and erase().\n";
	gl->draw();
	gl->erase();
	return 0;
}