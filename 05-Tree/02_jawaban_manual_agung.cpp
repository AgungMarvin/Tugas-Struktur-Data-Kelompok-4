#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

int hitungDalam(Node* root) {
    if (root == NULL) return 0;
    int kiri = hitungDalam(root->left);
    int kanan = hitungDalam(root->right);
    if (kiri > kanan) return kiri + 1;
    else return kanan + 1;
}
