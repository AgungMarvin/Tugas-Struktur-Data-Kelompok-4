#include <iostream>
using namespace std;

// Nama: Agung Marvin - Linked List Manual
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* balikList(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    // Membuat list manual 1->2->3->4->5
    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(3);
    h->next->next->next = new Node(4);
    h->next->next->next->next = new Node(5);

    // Proses balik
    h = balikList(h);

    // Cetak hasil
    while(h) { 
        cout << h->val << " "; 
        h = h->next; 
    }
    return 0;
}
