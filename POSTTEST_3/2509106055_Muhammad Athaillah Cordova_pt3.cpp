#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

struct antrian{
    int id;
    string nama;
    string keperluan;
};

struct riwayat{
    int id;
    string nama;
    string keperluan;
};

const int MAXQUEUE = 25;
antrian QPasien[MAXQUEUE];
int front = 0;
int rear = -1;
riwayat RiwayatPasien[MAXQUEUE];
int top = -1;

bool isFull() {
    return rear == MAXQUEUE - 1;
}

bool isEmpty() {
    return front > rear;
}

bool isRiwayatFull() {
    return top >= MAXQUEUE - 1;
}

bool isRiwayatEmpty() {
    return top < 0;
}

void push(int id, string nama, string keperluan);

const int MAX = 100;
Hewan dataHewan[MAX];
int jumlah = 0;

void pause() {
    cout << "\nTekan Enter tombol untuk melanjutkan...";
    getche();
    cout << endl;
}

void swapPtr(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void swapRef(Hewan &a, Hewan &b) {
    Hewan temp = a;
    a = b;
    b = temp;
}

void geserQ(antrian *arr, int &rear) {
    for(int i = 0; i < rear; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    rear--;
}

void enqueue(int id, string nama, string keperluan) {
    if(isFull()) {
        cout << "Antrian penuh!\n";
        return;
    }

    rear++;
    QPasien[rear].id = id;
    QPasien[rear].nama = nama;
    QPasien[rear].keperluan = keperluan;
    cout << "Pasien dengan ID " << id << " dan nama " << nama << " berhasil masuk antrian.\n";
}

void dequeue() {
    if(isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "Memanggil pasien:\n";
    cout << "ID: " << QPasien[front].id << endl;
    cout << "Nama: " << QPasien[front].nama << endl;

    push(QPasien[front].id, QPasien[front].nama, QPasien[front].keperluan);

    geserQ(QPasien, rear);
}

void peekAntrian() {
    if(isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Pasien Selanjutnya: \n";
    cout << "ID: " << QPasien[front].id << endl;
    cout << "Nama: " << QPasien[front].nama << endl;
}

void peekRiwayat() {
    if(isRiwayatEmpty()) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "\nRiwayat Pasien Terakhir:\n";
    cout << "ID: " << RiwayatPasien[top].id << endl;
    cout << "Nama: " << RiwayatPasien[top].nama << endl;
    cout << "keperluan: " << RiwayatPasien[top].keperluan << endl;
}

void pop() {
    if(top == -1) {
        cout << "riwayat Kosong\n";
        return;
    }
    cout << "Menghapus riwayat pasien:\n";
    cout << RiwayatPasien[top].nama << endl;
    top--;
}

void push(int id, string nama, string keperluan) {
    if(isRiwayatFull()) {
        cout << "Riwayat penuh! Tidak dapat menyimpan riwayat pasien.\n";
        return;
    }
    top++;
    RiwayatPasien[top].id = id;
    RiwayatPasien[top].nama = nama;
    RiwayatPasien[top].keperluan = keperluan;
}

void tampilAntrian(antrian *arr,int f, int r) {
    if(isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== Antrian Pasien ===\n";
    for(int i = front; i <= r; i++) {
        cout << "ID: " << (arr+i)->id << endl;
        cout << "Nama: " << (arr+i)->nama << endl;
        cout << "keperluan: " << (arr+i)->keperluan << endl;
        cout << "-------------------------\n";
    }
    peekAntrian();
}

void tampilRiwayat(riwayat *arr, int t) {
    if(top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== Riwayat Pasien ===\n";
    for(int i = 0; i <= top; i++) {
        cout << "ID: " << (arr+i)->id << endl;
        cout << "Nama: " << (arr+i)->nama << endl;
        cout << "keperluan: " << (arr+i)->keperluan << endl;
        cout << "-------------------------\n";
    }
    peekRiwayat();
}

void tampil(Hewan *arr, int n) {
    cout << endl;
    cout << "============================================================\n";
    cout << "|" << setw(2) << left << "No" << " | " 
        << setw(2) << left << "ID " << " | "
        << setw(15) << left << "Nama " << " | "
        << setw(15) << left << "Jenis " << " | "
        << setw(10) << left << "Harga " << " | " << endl;
    cout << "|----------------------------------------------------------|\n";
    for(int i = 0; i < n; i++) {
        cout << "|" << setw(2) << left << i+1 << " | "
            << setw(2) << left << (arr+i)->id << " | "
            << setw(15) << left << (arr+i)->nama << " | "
            << setw(15) << left << (arr+i)->jenis << " | "
            << setw(10) << left << (arr+i)->harga << " | " << endl;
        }
        cout << "============================================================\n";
        pause();
}

void tambah() {
    cout << "\nMasukkan data hewan baru:\n";
    cout << "ID: "; cin >> dataHewan[jumlah].id;
    cin.ignore();
    cout << "Nama: "; getline(cin,dataHewan[jumlah].nama);
    cout << "Jenis: "; cin >> dataHewan[jumlah].jenis;
    cout << "Harga: "; cin >> dataHewan[jumlah].harga;
    jumlah++;
    cout << "\nHewan berhasil ditambahkan.\n";
    pause();
}

void Linear(string key) {
    Hewan *p = dataHewan;
    bool ketemu = false;

    for(int i = 0; i < jumlah; i++) {
        if((p+i)->nama == key) {
            cout << "\nDitemukan!\n";
            cout << "ID: " << (p+i)->id << endl;
            cout << "Nama: " << (p+i)->nama << endl;
            cout << "Jenis: " << (p+i)->jenis << endl;
            cout << "Harga: " << (p+i)->harga << endl;
            ketemu = true;
            pause();
        }
    }

    // proses iterasi Linear Search
    // 1. index dimulai dari 0
    // 2. ambil data menggunakanm pointer (p+i)
    // 3. bandingkan nama dengan key 
    // 4. jika cocok maka tampilkan data
    // 5. jika tidak cocok maka lanjut ke index selanjut nya
    // 6. ulangi sampai semua data di cek
    
    if(!ketemu){
    cout << "Hewan Tidak ditemukan\n";
    pause();
    }
}

int Fibonnaci(int x) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        if (dataHewan[i].id < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (dataHewan[i].id > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i;
    }

    if (fibMMm1 && dataHewan[offset+1].id == x)
        return offset+1;

    return -1;
}

void bubbleSort() {
    for(int i = 0; i < jumlah-1; i++) {
        for(int j = 0; j < jumlah-i-1; j++) {
            if(dataHewan[j].nama > dataHewan[j+1].nama) {
                swapPtr(&dataHewan[j], &dataHewan[j+1]);
            }
        }
    }
    cout << "Berhasil diurutkan berdasarkan nama (A-Z)!\n";
    pause();
}

void selectionSort() {
    for(int i = 0; i < jumlah-1; i++) {
        int min = i;
        for(int j = i+1; j < jumlah; j++) {
            if(dataHewan[j].harga < dataHewan[min].harga)
                min = j;
        }
        swapPtr(&dataHewan[i], &dataHewan[min]);
    }
    cout << "Berhasil diurutkan berdasarkan harga!\n";
    pause();
}

int main() {
    dataHewan[0] = {101, "Garfield", "Kucing", 500000};
    dataHewan[1] = {102, "Oggy", "Kucing", 700000};
    dataHewan[2] = {103, "Krypto", "Anjing", 300000};
    dataHewan[3] = {104, "Scooby-Doo", "Anjing", 400000};
    dataHewan[4] = {105, "Courage", "Anjing", 200000};
    dataHewan[5] = {106, "Puss in Boots", "Kucing", 600000};
    dataHewan[6] = {107, "Bugs Bunny", "Kelinci", 350000};
    jumlah = 7;
    int pilih;

    cout << "\nSelamat Datang di PAWCARE\n";
    pause();

    do {
        cout << "\n=== MENU PAWCARE ===\n";
        cout << "1. Tambah Hewan\n";
        cout << "2. Tampil Hewan\n";
        cout << "3. Cari Nama Hewan (Linear)\n";
        cout << "4. Cari ID Hewan (Fibonacci)\n";
        cout << "5. Sort Nama Hewan (Bubble)\n";
        cout << "6. Sort Harga Hewan (Selection)\n";
        cout << "7. Enqueue Antrian Pasien\n";
        cout << "8. Dequeue Antrian Pasien\n";
        cout << "9. Hapus Riwayat Pasien (pop)\n";
        cout << "10.Tampil Antrian Pasien\n";
        cout << "11.Tampil Riwayat Pasien\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:{
            tambah();
        }
        break;

        case 2:{
            tampil(dataHewan, jumlah);
        }
        break;

        case 3:{
            string nama;
            cout << "\nMasukkan nama: ";
            cin.ignore();
            getline (cin,nama);
            Linear(nama);
        }
        break;

        case 4:{
            int id;
            cout << "\nMasukkan ID: ";
            cin >> id;
            cout << endl;
            int hasil = Fibonnaci(id);
            if(hasil != -1){
                cout << "Ditemukan!" << endl; 
                cout << "Nama: " <<dataHewan[hasil].nama << endl; 
                cout << "Jenis: " << dataHewan[hasil].jenis << endl;
                cout << "Harga: " <<  dataHewan[hasil].harga << endl;
                pause();
            }
            else {
                cout << "\nTidak ditemukan\n";
                pause();
            }
        }
        break;

        case 5:{
            bubbleSort();
        }
        break;

        case 6:{
            selectionSort();
        }    
        break;

        case 7:{
            int id;
            string nama;
            string keperluan;
            cout << "\nMasukkan ID Pasien: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan Nama Pasien: ";
            getline(cin, nama);
            cout << "Masukkan Keperluan: ";
            getline(cin, keperluan);
            enqueue(id, nama, keperluan);
            pause();
        }
        break;

        case 8:{
            dequeue();
            pause();
        }
        break;

        case 9:{
            pop();
            pause();
        }
        break;

        case 10:{
            tampilAntrian(QPasien, front, rear);
            pause();
        }
        break;

        case 11:{
            tampilRiwayat(RiwayatPasien, top);
            pause();
        }
        break;

        case 0:
        break;

        
        default:
        cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        pause();
        break;
        }

    } while(pilih != 0);
    cout << "\nTerima kasih, Datang Kembali!\n";

    return 0;
}