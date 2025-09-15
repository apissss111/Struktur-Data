#include <iostream>
using namespace std;

// nim saya ganjil
void balikArray(int *arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + (n - 1 - i));
        *(arr + (n - 1 - i)) = temp;
    }
}

int main() {
    const int N = 7;
    int arr[N];

    // isi dengan kelipatan 3
    for (int i = 0; i < N; i++) {
        arr[i] = 3 * (i + 1);
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    balikArray(arr, N);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
