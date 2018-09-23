#include <iostream>

#define SIZE 3

using namespace std;

class Matrix{
	public:
		Matrix();
		void input(void);
		void output(void);
		friend Matrix operator +(const Matrix& a, const Matrix& b);
	private:
		int mat[SIZE][SIZE];
};

int main(void) {
	Matrix matA, matB, matC;
	cout << "Enter 3*3 numbers for matA: ";
	matA.input();
	cout << "Enter 3*3 numbers for matB: ";
	matB.input();
	
	matC = matA + matB;
	cout << "matA:\n";
	matA.output();
	cout << "matB:\n";
	matB.output();
	cout << "matC = matA + matB:\n";
	matC.output();
	
	return 0;
}

Matrix::Matrix() {
	for(int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			mat[i][j] = -1;
		}
	}
}

void Matrix::input(void) {
	for(int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			cin >> mat[i][j];
		}
	}
}

void Matrix::output(void) {
	for(int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix operator +(const Matrix& a, const Matrix& b) {
	Matrix c;
	for(int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		}
	}
	return c;
}