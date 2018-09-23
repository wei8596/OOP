#include <iostream>

#define N 10

using namespace std;

void mysort(int a[], int size);

int main(void) {
	int num[N], i = 0;
	cout << "Enter a sequence of number that is less ten numbers: ";
	while(cin >> num[i]) {
		++i;
		if(i == N) break;
	}
	mysort(num, i);
	for(int k = 0; k < i; ++k) {
		cout << num[k] << " ";
	}
	cout << endl;
	
	return 0;
}

void mysort(int a[], int size) {
	int temp;
	for(int i = 0; i < size-1; ++i) {
		for(int j = i+1; j < size; ++j) {
			if(a[i] < a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}