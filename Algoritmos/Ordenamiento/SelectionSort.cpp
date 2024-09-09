
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>     // Para medir el tiempo

using namespace std;

// Function for Selection sort
void selectionSort(int arr[], int n)
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program

int main()
{

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

    int size = numbers.size();
    int* array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = numbers[i];
    }

    int n = size ;

    auto start = chrono::high_resolution_clock::now() ;

    selectionSort(array, n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    delete[] array;
    inputFile.close();

    return 0;
}

// This is code is contributed by rathbhupendra
