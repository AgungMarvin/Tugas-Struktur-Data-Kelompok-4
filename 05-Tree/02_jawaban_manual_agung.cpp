#include <iostream>
using namespace std;

// Nama: Agung Marvin - Tree Manual
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int hitungDalam(Node* root) {
    if (root == NULL) return 0;
    int kiri = hitungDalam(root->left);
    int kanan = hitungDalam(root->right);
    return (kiri > kanan ? kiri : kanan) + 1;
}

int main() {
    Node* r = new Node(1);
    r->left = new Node(2);
    r->right = new Node(3);
    r->right->left = new Node(4); 
    cout << "Kedalaman pohon: " << hitungDalam(r) << endl;
    return 0;
}
