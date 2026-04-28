#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Toko Sembako
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;

    // Constructor
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);
    if (head == nullptr) {
        newNode->next = newNode; // Menunjuk ke dirinya sendiri (Sirkuler)
        return newNode;
    }
    
    BarangNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

void tampilkanStokSembako(BarangNode* head) {
    // --- LENGKAPI KODE DI SINI ---
    if (head == nullptr) {
        cout << "Gudang kosong." << endl;
        return;
    } // pengecekan jika node belum ada

    BarangNode* temp = head; // untuk menyimpan dan memulai posisi awal node (head)
    do {
        cout << "- " << temp->namaBarang << ": " << temp->stok << endl; // menampilkan isi node yakni nama barang dan stok nya
        temp = temp->next; // untuk berpindah ke node selanjutnya
    } while (temp != head); // perulangan akan behrenti saat temp sudah kembali ke node awal (head)
    return;

    // -----------------------------
}

int main() {
    BarangNode* head = nullptr;
    
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);

    cout << "Daftar Stok Sembako:" << endl;
    tampilkanStokSembako(head); 
    return 0;
}