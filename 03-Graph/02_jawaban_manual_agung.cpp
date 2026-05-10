#include <iostream>
#include <vector>
using namespace std;

// Nama: Agung Marvin - Graph Manual
vector<int> adj[100];
bool visit[100];

bool adaJalan(int s, int d) {
    if (s == d) return true;
    visit[s] = true;
    for (int t : adj[s]) {
        if (!visit[t]) {
            if (adaJalan(t, d)) return true;
        }
    }
    return false;
}

int main() {
    // Hubungkan angka 0 ke 1, dan 1 ke 2
    adj[0].push_back(1); 
    adj[1].push_back(2); 
    
    // Cek apakah ada jalan dari 0 ke 2
    cout << "Hasil: " << adaJalan(0, 2) << endl;
    return 0;
}
