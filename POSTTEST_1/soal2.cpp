#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        getline(cin, mhs[i].nim);
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cout << endl;
        cin.ignore();
    }

    float ipkmax = 0;
    for (int i = 0; i < 5; i++) {
        if (mhs[i].ipk > ipkmax) {
            ipkmax = mhs[i].ipk;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:\n";
    for (int i = 0; i < 5; i++) {
        if (mhs[i].ipk == ipkmax) {
            cout << "Nama: " << mhs[i].nama << endl
            << "NIM: " << mhs[i].nim << endl
            << "ipk: " << mhs[i].ipk << endl;
        }
    }


    return 0;
}