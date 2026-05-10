#include <iostream>

using namespace std;

/**
 * Nama: AgungMarvin
 * Tugas: Implementasi Reverse Linked List
 */

// Struktur Node standar
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solusi {
public:
    // Fungsi untuk membalikkan urutan list
    Node* balikkanList(Node* head) {
        Node* sebelumnya = NULL;
        Node* sekarang = head;
        Node* berikutnya = NULL;

        while (sekarang != NULL) {
            // Simpan alamat node selanjutnya dulu
            berikutnya = sekarang->next;

            // Balikkan arah pointer ke node sebelumnya
            sekarang->next = sebelumnya;

            // Geser posisi ke node berikutnya
            sebelumnya = sekarang;
            sekarang = berikutnya;
        }

        return sebelumnya;
    }
};

// Untuk menampilkan isi list di terminal
void cetakList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Contoh input: 1 -> 2 -> 3
    Node* kepala = new Node(1);
    kepala->next = new Node(2);
    kepala->next->next = new Node(3);

    cout << "List Awal: ";
    cetakList(kepala);

    Solusi s;
    kepala = s.balikkanList(kepala);

    cout << "List Setelah Dibalik: ";
    cetakList(kepala);

    return 0;
}
