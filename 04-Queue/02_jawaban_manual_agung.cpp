#include <iostream>
#include <queue>

using namespace std;

/**
 * Nama: AgungMarvin
 * Tugas: Implementasi Stack menggunakan Queue (LeetCode 225)
 * Deskripsi: Menggunakan satu queue dan memutar isinya agar elemen terbaru selalu di depan.
 */

class MyStack {
private:
    queue<int> antrean;

public:
    MyStack() {
        // Konstruktor kosong
    }
    
    // Fungsi Masuk (Push)
    void push(int x) {
        // 1. Masukkan elemen baru ke antrean
        antrean.push(x);
        
        // 2. Putar antrean: pindahkan elemen lama ke belakang elemen baru
        // supaya elemen yang baru masuk tadi ada di paling depan (posisi top)
        int ukuran = antrean.size();
        for (int i = 0; i < ukuran - 1; i++) {
            antrean.push(antrean.front());
            antrean.pop();
        }
    }
    
    // Fungsi Keluar (Pop)
    int pop() {
        int hasil = antrean.front();
        antrean.pop();
        return hasil;
    }
    
    // Lihat elemen paling atas (Top)
    int top() {
        return antrean.front();
    }
    
    // Cek apakah kosong
    bool empty() {
        return antrean.empty();
    }
};

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    
    cout << "Elemen teratas: " << s.top() << endl; // Harus 20
    cout << "Hapus elemen: " << s.pop() << endl;  // Menghapus 20
    cout << "Elemen teratas sekarang: " << s.top() << endl; // Harus 10
    
    return 0;
}
