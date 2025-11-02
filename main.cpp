#include <iostream>
#include "matops.hpp"
#include "Layer.hpp"
#include <iomanip>
#include "activation.hpp"
#include "utils.hpp"
#include <cstring>
#include "Dense.hpp"

using namespace std;

template<typename T, int line, int col>
void printMat(T* const mat) {
	for (int i=0 ; i<line ; i++) {
		for (int j=0 ; j<col ; j++) {
			cout << fixed << setprecision(10) << mat[i * col +j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T, int line>
void printVec(T const mat[line]) {
	for (int i=0 ; i<line ; i++) {
		cout << fixed << setprecision(10) << mat[i] << " ";
		cout << endl;
	}
	cout << endl;
}

	template <typename T, int sizeIn, int nbNeurones1, int nbNeurones2>
void deltaRule3(T const input[sizeIn], T const output[nbNeurones2], T const target[nbNeurones2], T const poids2[nbNeurones2][nbNeurones1], T const intermediaire[nbNeurones1], T taux, T correction[nbNeurones1][sizeIn])
{
	memset(correction, 0, nbNeurones1 * sizeIn * sizeof(T));
    double dE1 =  (output[0] - target[0]) * (output[0] * (1 - output[0])) * poids2[0][0] ;
	double dE2 = (output[1] - target[1]) * (output[1] * (1 - output[1])) * poids2[1][0];
	double dE = dE1 + dE2;
	correction [0][0] = taux * dE * (intermediaire[0] * (1 - intermediaire[0])) * input[0];
	correction [0][1] = taux * dE * (intermediaire[0] * (1 - intermediaire[0])) * input[1];
	correction [1][0] = taux * dE * (intermediaire[1] * (1 - intermediaire[1])) * input[0];
	correction [1][1] = taux * dE * (intermediaire[1] * (1 - intermediaire[1])) * input[1];
}


int main() {
	float mat1[] = {0.1,0.3,0.2,0.4};
	float mat2[] = {0.5,0.6,0.7,0.8};
	float biais1[] = {0.25,0.25};
	float biais2[] = {0.35,0.35};
	float input[] = {0.1,0.5};
	float res1[2];
	float res2[2];
	float target[2] = {0.05, 0.95};
	float delta[2][2];

	Dense<float, 2,2> layer1(mat1, biais1, new Sigmoid<float>());
	Dense<float, 2,2> layer2(mat2, biais2, new Sigmoid<float>());

	layer1.forward(input, res1);
	printVec<float, 2>(res1);
	layer2.forward(res1, res2);
	printVec<float, 2>(res2);

	layer2.backward(res1, res2, target, 0.6);
	printMat<float,2,2>(layer2.poids);


	return 0;
}
