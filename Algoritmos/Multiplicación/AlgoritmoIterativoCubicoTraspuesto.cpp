#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>   // Para medir el tiempo

using namespace std ; 


const int N = 1024; // Define el tamaño de las matrices

void transpose(int B[][N], int B_transposed[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B_transposed[j][i] = B[i][j];
        }
    }
}

void multiply(int A[][N], int B[][N], int C[][N]) {
    int B_transposed[N][N];
    transpose(B, B_transposed);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B_transposed[j][k];
            }
        }
    }
}

void print_matrix(int matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void loadMatrixFromFile(ifstream& file, int matrix[][N]) {
    string line;
    int i = 0;
    while (getline(file, line) && i < N) {
        stringstream ss(line);
        string number;
        int j = 0;
        while (getline(ss, number, ',') && j < N) {
            matrix[i][j] = stoi(number);
            j++;
        }
        i++;
    }
}

int main() {

    string inputFilename = "MatricesAleatorias.txt" ;
    ifstream inputFile(inputFilename);

    int A[N][N], B[N][N], C[N][N];

    loadMatrixFromFile(inputFile, A);

    loadMatrixFromFile(inputFile, B);

    auto start = chrono::high_resolution_clock::now() ;

    multiply(A, B, C);

	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> duration = end - start;

	cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;
    
    return 0;
}
