//
// Created by jamorin on 25/10/25.
//

#ifndef MATMUL_H
#define MATMUL_H

#include <cstring>

// matrice de dimensions (nbLignes, nbColonnes)


template<typename T, int M, int N, int P>
void matMul(T* const mat1_p, T* const mat2_p, T* res_p) {
	// mat1 (M lignes, N colonnes)
	// mat2 (N lignes, P colonnes)
	// mat3 (M lignes, P colonnes)
	float (*mat1)[N] = (float (*)[N]) mat1_p;
	float (*mat2)[P] = (float (*)[P]) mat2_p;
	float (*res)[P] = (float (*)[P]) res_p;

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
void matAdd(T* const mat1_p, T* const mat2_p, T* res_p) {
	// mat1 (M lignes, N colonnes)
	// mat2 (N lignes, N colonnes)
	// mat3 (M lignes, N colonnes)
	float (*mat1)[N] = (float (*)[N]) mat1_p;
	float (*mat2)[N] = (float (*)[N]) mat2_p;
	float (*res)[N] = (float (*)[N]) res_p;

	for (int i=0 ; i<M ; i++) {
		for (int j=0 ; j<N ; j++) {
			res[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

template<typename T, int M, int N>
void matSub(T* const mat1_p, T* const mat2_p, T* res_p) {
	// mat1 (M lignes, N colonnes)
	// mat2 (N lignes, N colonnes)
	// mat3 (M lignes, N colonnes)
	float (*mat1)[N] = (float (*)[N]) mat1_p;
	float (*mat2)[N] = (float (*)[N]) mat2_p;
	float (*res)[N] = (float (*)[N]) res_p;

	for (int i=0 ; i<M ; i++) {
		for (int j=0 ; j<N ; j++) {
			res[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

template<typename T, int M, int N>
void matSub(T* mat1_p, T* const mat2_p) {
	// mat1 (M lignes, N colonnes)
	// mat2 (N lignes, N colonnes)
	// mat3 (M lignes, N colonnes)
	float (*mat1)[N] = (float (*)[N]) mat1_p;
	float (*mat2)[N] = (float (*)[N]) mat2_p;

	for (int i=0 ; i<M ; i++) {
		for (int j=0 ; j<N ; j++) {
			mat1[i][j] -= mat2[i][j];
		}
	}
}

template<typename T, int size>
void vecAdd(T const vec1[size], T const vec2[size], T res[size]){
	for(int i=0 ; i<size ; i++) {
		res[i] = vec1[i] + vec2[i];
	}
}

template<typename T, int size>
void vecAcc(T vec1[size], T const vec2[size]){
	for(int i=0 ; i<size ; i++) {
		vec1[i] += vec2[i];
	}
}

template<typename T, int M, int N>
void matVecMul(T* const mat_p, T const vec[N], T res [M]) {
	float (*mat)[N] = (float (*)[N]) mat_p;

	memset(res, 0, M * sizeof(T));
	for (int ligne=0 ; ligne<M ; ligne++) {
		for (int col = 0 ; col<N ; col++) {
			res[ligne] += mat[ligne][col] * vec[col];
		}
	}
}

#endif //MATMUL_H
