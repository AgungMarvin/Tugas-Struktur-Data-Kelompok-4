#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
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
