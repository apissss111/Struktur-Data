#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL; // penting di DLL

// NIM saya 099
const int JUMLAH_AWAL = 99;
const int POSISI_SISIP = 10;

// Buat node baru
Node* buatNode(string nama, string tipe) {
    Node* baru = new Node;
    baru->namaItem = nama;
    baru->jumlah = JUMLAH_AWAL;
    baru->tipe = tipe;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

// Tambah item di akhir
void tambahItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);
    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << ".\n";
}

// Sisipkan item sesuai posisi
void sisipkanItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);

    if (head == NULL || POSISI_SISIP == 1) {
        baru->next = head;
        if (head != NULL) head->prev = baru;
        head = baru;
        if (tail == NULL) tail = baru;
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
    if (temp->next != NULL) temp->next->prev = baru;
    else tail = baru; // kalau disisip di akhir
    temp->next = baru;
    baru->prev = temp;

    cout << "Item \"" << nama << "\" disisipkan di posisi " << POSISI_SISIP << ".\n";
}

// Hapus item terakhir
void hapusItemTerakhir() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    if (head == tail) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = tail = NULL;
        return;
    }

    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Node* hapus = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete hapus;
}

// Gunakan item
void gunakanItem(string nama) {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp->namaItem == nama) {
            temp->jumlah--;
            cout << "Item \"" << nama << "\" digunakan. Sisa: " << temp->jumlah << ".\n";

            if (temp->jumlah == 0) {
                cout << "Item \"" << nama << "\" habis dan dihapus dari inventory.\n";

                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                if (temp->prev != NULL) temp->prev->next = temp->next;
                if (temp->next != NULL) temp->next->prev = temp->prev;

                delete temp;
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Item \"" << nama << "\" tidak ditemukan!\n";
}

// Traversal dari depan
void tampilkanInventory() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n===== INVENTORY (Depan -> Belakang) =====\n";
    Node* temp = head;
    int i = 1;
    while (temp != NULL) {
        cout << i++ << ". " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "=========================================\n";
}

// Traversal dari belakang
void tampilkanInventoryMundur() {
    if (tail == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n===== INVENTORY (Belakang -> Depan) =====\n";
    Node* temp = tail;
    int i = 1;
    while (temp != NULL) {
        cout << i++ << ". " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->prev;
    }
    cout << "=========================================\n";
}

// Cari detail item berdasarkan ID (urutan) atau nama
void cariItem() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "Cari berdasarkan (1 = ID, 2 = Nama): ";
    int opsi;
    cin >> opsi;

    if (opsi == 1) {
        int id;
        cout << "Masukkan ID item: ";
        cin >> id;

        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            if (i == id) {
                cout << "Detail Item ke-" << id << ":\n";
                cout << "Nama   : " << temp->namaItem << "\n";
                cout << "Jumlah : " << temp->jumlah << "\n";
                cout << "Tipe   : " << temp->tipe << "\n";
                return;
            }
            temp = temp->next;
            i++;
        }
        cout << "Item dengan ID " << id << " tidak ditemukan!\n";
    } else if (opsi == 2) {
        string nama;
        cout << "Masukkan nama item: ";
        cin >> nama;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->namaItem == nama) {
                cout << "Detail Item \"" << nama << "\":\n";
                cout << "Nama   : " << temp->namaItem << "\n";
                cout << "Jumlah : " << temp->jumlah << "\n";
                cout << "Tipe   : " << temp->tipe << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Item \"" << nama << "\" tidak ditemukan!\n";
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

int main() {
    int pilihan;
    string nama, tipe;

    do {
        cout << "\n+-----------------------------------------+\n";
        cout << "|      GAME INVENTORY MANAGEMENT (DLL)    |\n";
        cout << "|   Muhammad Taufiqul Hafizh - 099        |\n";
        cout << "+-----------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                     |\n";
        cout << "| 2. Sisipkan Item                        |\n";
        cout << "| 3. Hapus Item Terakhir                  |\n";
        cout << "| 4. Gunakan Item                         |\n";
        cout << "| 5. Tampilkan Inventory (Depan->Belakang)|\n";
        cout << "| 6. Tampilkan Inventory (Belakang->Depan)|\n";
        cout << "| 7. Cari Item (ID/Nama)                  |\n";
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
            case 6:
                tampilkanInventoryMundur();
                break;
            case 7:
                cariItem();
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
