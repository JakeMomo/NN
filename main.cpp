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
void printMat(T const mat[line][col]) {
	for (int i=0 ; i<line ; i++) {
		for (int j=0 ; j<col ; j++) {
			cout << fixed << setprecision(10) << mat[i][j] << " ";
		}
		cout << std::endl;
	}
}
template<typename T, int line>
void printVec(T const mat[line]) {
	for (int i=0 ; i<line ; i++) {
		cout << fixed << setprecision(10) << mat[i] << " ";
		cout << std::endl;
	}
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
	double poids1[2][2] = {{.15,.20}, {.25,.30}};
	double poids2[2][2] = {{.40,.45},{.5,.55}};

	double biais1[2] = {0.35,0.35};
	double biais2[2] = {0.6,0.6};

	double input1[2] = {0.05, 0.10};
	double intermediaire1[2];
	double intermediaire2[2];
	double intermediaire3[2];
	double output[2];
	double target[2] = {0.01, 0.99};
	double delta[2][2];
	double delta2[2][2];
	double taux = 0.5;

	Sigmoid<float> s;
	cout << s.eval(2) << endl;
	cout << 1/(1+exp(-2)) << endl;

	layer<double,2,2>(poids1, biais1, input1, intermediaire1);
	sigmoid<double, 2>(intermediaire1, intermediaire2);

	layer<double,2,2>(poids2, biais2, intermediaire2, intermediaire3);
	sigmoid<double, 2>(intermediaire3, output);

	double correction[2][2];
	deltaRule3<double,2,2,2>(input1, output, target, poids2, intermediaire2, taux, correction);

	matSub<double,2,2>(poids1, correction, poids1);
	printMat<double,2,2>(poids1);

	Dense<double,2,2>* test = new Dense<double, 2, 2>(poids1, biais1, new Sigmoid<double>());



	return 0;
}
