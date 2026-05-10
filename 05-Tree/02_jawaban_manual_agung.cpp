#include <iostream>
#include <algorithm> // Untuk fungsi max

using namespace std;

/**
 * Nama: AgungMarvin
 * Tugas: Maximum Depth of Binary Tree (LeetCode 104)
 * Deskripsi: Mencari tinggi pohon menggunakan rekursi sederhana.
 */

// Struktur Node Pohon
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolusiTree {
public:
    int maxDepth(TreeNode* root) {
        // 1. Kondisi Berhenti: Jika pohonnya kosong, tingginya 0
        if (root == NULL) {
            return 0;
        }
        
        // 2. Cari tinggi di cabang sebelah kiri secara rekursif
        int kiri = maxDepth(root->left);
        
        // 3. Cari tinggi di cabang sebelah kanan secara rekursif
        int kanan = maxDepth(root->right);
        
        // 4. Ambil yang paling tinggi di antara keduanya, lalu tambah 1 (hitung dirinya sendiri)
        return max(kiri, kanan) + 1;
    }
};

int main() {
    // Membuat pohon contoh:
    //      3
    //     / \
    //    9  20
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    
    SolusiTree st;
    cout << "Kedalaman Maksimal Pohon: " << st.maxDepth(root) << endl;
    
    return 0;
}
