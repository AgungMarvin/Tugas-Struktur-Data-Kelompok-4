#include <iostream>
#include <vector>

using namespace std;

/**
 * Nama: AgungMarvin
 * Tugas: Graph - Find if Path Exists (LeetCode 1971)
 * Metode: DFS (Depth First Search) Manual
 */

class SolusiGraph {
public:
    // Fungsi bantuan untuk menelusuri jalan (DFS)
    bool cekJalan(int nodeSekarang, int tujuan, vector<vector<int>>& adj, vector<bool>& dikunjungi) {
        // Jika sampai di titik tujuan, berarti ada jalan
        if (nodeSekarang == tujuan) return true;
        
        // Tandai titik ini sudah dilewati
        dikunjungi[nodeSekarang] = true;
        
        // Cek semua tetangganya
        for (int tetangga : adj[nodeSekarang]) {
            // Kalau tetangga belum dikunjungi, coba masuk ke sana
            if (!dikunjungi[tetangga]) {
                if (cekJalan(tetangga, tujuan, adj, dikunjungi)) return true;
            }
        }
        
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 1. Buat daftar tetangga (Adjacency List) secara manual
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 2. Siapkan catatan titik yang sudah dikunjungi biar tidak muter-muter (infinite loop)
        vector<bool> dikunjungi(n, false);
        
        // 3. Mulai cari jalan dari titik awal
        return cekJalan(source, destination, adj, dikunjungi);
    }
};

int main() {
    SolusiGraph sg;
    
    // Contoh sederhana: 3 titik, ada jalan 0-1 dan 1-2. Cari jalan dari 0 ke 2.
    int n = 3;
    vector<vector<int>> edges = {{0,1}, {1,2}};
    int source = 0;
    int destination = 2;
    
    if (sg.validPath(n, edges, source, destination)) {
        cout << "Hasil: Ada jalan dari " << source << " ke " << destination << endl;
    } else {
        cout << "Hasil: Tidak ada jalan." << endl;
    }
    
    return 0;
}
