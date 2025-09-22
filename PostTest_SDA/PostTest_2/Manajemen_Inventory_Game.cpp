#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

Node* head = NULL;

// NIM saya 099
const int JUMLAH_AWAL = 99;
const int POSISI_SISIP = 10;

// Fungsi buat node baru
Node* buatNode(string nama, string tipe) {
    Node* baru = new Node;
    baru->namaItem = nama;
    baru->jumlah = JUMLAH_AWAL; 
    baru->tipe = tipe;
    baru->next = NULL;
    return baru;
}

// Tambah item di akhir
void tambahItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);
    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << ".\n";
}

// Sisipkan item sesuai posisi
void sisipkanItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);

    if (head == NULL || POSISI_SISIP == 1) {
        baru->next = head;
        head = baru;
        cout << "Item \"" << nama << "\" disisipkan di posisi awal.\n";
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp->next != NULL && count < POSISI_SISIP - 1) {
        temp = temp->next;
        count++;
    }

    baru->next = temp->next;
    temp->next = baru;
    cout << "Item \"" << nama << "\" disisipkan di posisi " << POSISI_SISIP << ".\n";
}

// MHapus item terakhir
void hapusItemTerakhir() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    if (head->next == NULL) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = NULL;
}

// Gunakan item (paling kompleks)
void gunakanItem(string nama) {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->namaItem == nama) {
            temp->jumlah--;
            cout << "Item \"" << nama << "\" digunakan. Sisa: " << temp->jumlah << ".\n";

            if (temp->jumlah == 0) {
                cout << "Item \"" << nama << "\" habis dan dihapus dari inventory.\n";
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Item \"" << nama << "\" tidak ditemukan!\n";
}

// Tampilkan semua inventory
void tampilkanInventory() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n===== INVENTORY GAME =====\n";
    Node* temp = head;
    int i = 1;
    while (temp != NULL) {
        cout << i++ << ". " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "==========================\n";
}

int main() {
    int pilihan;
    string nama, tipe;

    do {
        cout << "\n+-----------------------------------------+\n";
        cout << "|      GAME INVENTORY MANAGEMENT          |\n";
        cout << "|   Muhammad Taufiqul Hafizh - 099        |\n";
        cout << "+-----------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                     |\n";
        cout << "| 2. Sisipkan Item                        |\n";
        cout << "| 3. Hapus Item Terakhir                  |\n";
        cout << "| 4. Gunakan Item                         |\n";
        cout << "| 5. Tampilkan Inventory                  |\n";
        cout << "| 0. Keluar                               |\n";
        cout << "+-----------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                cin >> nama;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                tambahItem(nama, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                cin >> nama;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                sisipkanItem(nama, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                cin >> nama;
                gunakanItem(nama);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
