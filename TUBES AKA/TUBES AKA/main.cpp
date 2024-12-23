#include <iostream>
#include <iomanip> // Untuk setprecision
#include <ctime>
#include <cstdlib> // Untuk rand() dan srand()
using namespace std;

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl; // Baris baru setiap 10 elemen
    }
    cout << endl;
}

// ===== Iteratif: Mencari Harga Termurah =====
int findMinIterative(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// ===== Rekursif: Mencari Harga Termurah =====
int findMinRecursive(int arr[], int size, int index = 0, int minVal = INT_MAX) {
    if (index == size) return minVal; // Basis rekursi
    if (arr[index] < minVal) minVal = arr[index];
    return findMinRecursive(arr, size, index + 1, minVal); // Panggilan rekursif
}

// ===== Program Utama =====
int main() {
    const int size = 300; // Ukuran array
    int prices[size];

    // Menghasilkan data harga kos secara acak dalam rentang 7 juta - 30 juta
    srand(time(0)); // Seed untuk random
    for (int i = 0; i < size; i++) {
        prices[i] = 7000000 + rand() % (30000000 - 7000000 + 1); // Rentang 7 juta - 30 juta
    }

    cout << "List Harga Kosan (300 data):\n";
    printArray(prices, size);

    // ==== Iteratif: Cari Harga Termurah ====
    clock_t start1 = clock();
    int minIterative = findMinIterative(prices, size);
    clock_t end1 = clock();

    cout << "\nIteratif - Harga Termurah: " << minIterative << endl;
    cout << "Waktu Eksekusi: "
         << fixed << setprecision(8) // Menampilkan dengan 8 digit desimal
         << (double)(end1 - start1) / CLOCKS_PER_SEC << " detik\n";

    // ==== Rekursif: Cari Harga Termurah ====
    clock_t start2 = clock();
    int minRecursive = findMinRecursive(prices, size);
    clock_t end2 = clock();

    cout << "\nRekursif - Harga Termurah: " << minRecursive << endl;
    cout << "Waktu Eksekusi: "
         << fixed << setprecision(8) // Menampilkan dengan 8 digit desimal
         << (double)(end2 - start2) / CLOCKS_PER_SEC << " detik\n";

    return 0;
}
