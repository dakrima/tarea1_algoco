
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>     // Para medir el tiempo

using namespace std;

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

    int n = numbers.size();

    auto start = chrono::high_resolution_clock::now() ;

    quickSort(numbers, 0, n - 1);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    inputFile.close();
    
    return 0;
}
