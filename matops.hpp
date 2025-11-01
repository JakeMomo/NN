//
// Created by jamorin on 25/10/25.
//

#ifndef MATMUL_H
#define MATMUL_H

#include <cstring>

// matrice de dimensions (nbLignes, nbColonnes)


template<typename T, int M, int N, int P>
void matMul(T const mat1[M][N], T const mat2[N][P], T res[M][P]) {
	memset(res, 0, M * P * sizeof(T));

	for (int outline=0 ; outline<M ; outline++) {
		for (int outcol=0 ; outcol<P ; outcol++) {
			for (int incol=0 ; incol<N ; incol++) {
				res[outline][outcol] +=
					mat1[outline][incol] * mat2[incol][outcol];
			}
		}
	}
}

template<typename T, int M, int N>
void matAdd(T const mat1[M][N], T const mat2[M][N], T res[M][N]) {
	for (int i=0 ; i<M ; i++) {
		for (int j=0 ; j<N ; j++) {
			res[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

template<typename T, int M, int N>
void matSub(T const mat1[M][N], T const mat2[M][N], T res[M][N]) {
	for (int i=0 ; i<M ; i++) {
		for (int j=0 ; j<N ; j++) {
			res[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

template<typename T, int size>
void vecAdd(T const vec1[size], T const vec2[size], T res[size]){
	for(int i=0 ; i<size ; i++) {
		res[i] = vec1[i] + vec2[i];
	}
}

template<typename T, int M, int N>
void matVecMul(T const mat[M][N], T const vec[N], T res [M]) {
	memset(res, 0, M * sizeof(T));
	for (int ligne=0 ; ligne<M ; ligne++) {
		for (int col = 0 ; col<N ; col++) {
			res[ligne] += mat[ligne][col] * vec[col];
		}
	}
}

#endif //MATMUL_H
