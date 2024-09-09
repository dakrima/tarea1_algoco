
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // de esta biblioteca saco sort
#include <chrono>   // Para medir el tiempo

using namespace std;

int main() {

    string inputFilename = "DatosOrdenadosAsc.txt"; // nombre del archivo que estoy leyendo
    
    ifstream inputFile(inputFilename);

    vector<int> numbers;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string number;
        while (getline(ss, number, ',')) {
            numbers.push_back(stoi(number));
        }
    }

    auto start = chrono::high_resolution_clock::now() ;

    sort(numbers.begin(), numbers.end());  // ordenamiento de los numeros usando sort

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    inputFile.close();

    return 0;
}
