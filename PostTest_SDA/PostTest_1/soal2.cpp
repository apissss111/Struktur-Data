#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah += matriks[i][i];           // diagonal utama
        jumlah += matriks[i][N - 1 - i];   // diagonal sekunder
    }

    // kalau N ganjil, elemen tengah dihitung 2x → kurangi sekali
    if (N % 2 == 1) jumlah -= matriks[N/2][N/2];

    cout << "Jumlah diagonal utama + diagonal sekunder = " << jumlah << endl;

    return 0;
}
