#include <iostream>
#include "matops.hpp"
#include <iomanip>

using namespace std;

template<typename T, int line, int col>
void printMat(T const mat[line][col]) {
	for (int i=0 ; i<line ; i++) {
		for (int j=0 ; j<col ; j++) {
			cout << fixed << setprecision(3) << mat[i][j] << " ";
		}
		cout << std::endl;
	}
}
template<typename T, int line>
void printMat(T const mat[line]) {
	for (int i=0 ; i<line ; i++) {
		cout << fixed << setprecision(3) << mat[i] << " ";
		cout << std::endl;
	}
}


int main() {
	int mat1[3][2] = {{1,2},{3,4}, {5,6}};
	int mat2[2][3] = {{1,1,0}, {0,1,1}};
	int res[3][3];
	int res2[3][3];
	int ones[3][3];
	for (int i=0 ; i<3 ; i++) {
		for (int j=0 ; j<3 ; j++) {
			ones[i][j] = 1;
		}
	}
	printMat<int,3,3>(ones);
cout << endl;
	matmul<int,3,2,3>(mat1, mat2, res);
	matadd<int,3,3>(res, ones, res2);

	printMat<int,3,2>(mat1);
	cout << endl;
	printMat<int,2,3>(mat2);
	cout << endl;
	printMat<int,3,3>(res);
	cout << endl;
	printMat<int,3,3>(res2);
	cout << endl;

	int vec[3] = {1,2,3};
	int vec2[3];
	matvec<int, 3,3>(res2, vec, vec2);
	printMat<int,3>(vec2);
	cout << endl;

	return 0;
}