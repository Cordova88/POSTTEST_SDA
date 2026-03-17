#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

void tampilarray(int* arr, int n) {
    int* ptr = arr;
    for (int i = 0; i < n; i++) {
        cout << "Angka: " << *ptr <<" | Alamat: " << ptr << endl;
        ptr++;
    }
}

int main(){
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: " << endl;
    tampilarray(arr, 7);

    reverseArray(arr, 7);

    cout << "\nArray setelah dibalik: " << endl;
    tampilarray(arr, 7);

    return 0;
}
