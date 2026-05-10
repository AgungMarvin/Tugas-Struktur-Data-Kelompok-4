#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * Nama: AgungMarvin
 * Tugas Bagian 4: Code Sendiri (Manual Solution)
 * Soal: Valid Parentheses (C++)
 */

bool isValid(string s) {
    stack<char> tumpukan;

    for (char karakter : s) {
        // Jika ketemu kurung buka, masukkan ke tumpukan (push)
        if (karakter == '(' || karakter == '{' || karakter == '[') {
            tumpukan.push(karakter);
        } 
        else {
            // Jika ada kurung tutup tapi tumpukan kosong, berarti salah
            if (tumpukan.empty()) {
                return false;
            }

            char atas = tumpukan.top(); // Lihat elemen paling atas
            
            // Cek apakah pasangannya cocok secara manual
            if (karakter == ')' && atas == '(') {
                tumpukan.pop();
            } else if (karakter == '}' && atas == '{') {
                tumpukan.pop();
            } else if (karakter == ']' && atas == '[') {
                tumpukan.pop();
            } else {
                // Jika tidak ada yang cocok, berarti tidak valid
                return false;
            }
        }
    }

    // Jika di akhir tumpukan kosong, berarti semua punya pasangan
    return tumpukan.empty();
}

int main() {
    string input = "()[]{}";
    if (isValid(input)) {
        cout << "Hasil: Valid (True)" << endl;
    } else {
        cout << "Hasil: Tidak Valid (False)" << endl;
    }
    return 0;
}
