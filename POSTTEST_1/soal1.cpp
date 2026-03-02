#include <iostream>
using namespace std;


int findmin(int A[], int n, int &index) {
    int min = A[0];
    index = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            index = i;
        }
    }
    return min;
}

int main() {
    int A[8] = {10, 11 ,2, 3, 5, 8, 13, 21};
    int index;

    int minimum = findmin(A, 8, index);

    cout << endl;
    cout << "Nilai Minimum nya adalah " << minimum << " dan berada di index " << index << endl;
    cout << endl;
}

/*
Kompleksitass findmin :
jumlah iterasi loop = n - 1

best case :
Tmin(n) = n -1 
Big O = O(n)

worst case :
Tmax(n) = 2(n - 1)
Big O = O(n)
*/