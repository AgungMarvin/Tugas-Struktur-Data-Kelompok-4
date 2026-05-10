#include <iostream>
#include <queue>
using namespace std;

// Nama: Agung Marvin - Queue Manual
queue<int> q;

void push_manual(int x) {
    int s = q.size();
    q.push(x);
    for (int i = 0; i < s; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    push_manual(10);
    push_manual(20);
    push_manual(30);
    cout << "Data paling atas (Top): " << q.front() << endl; 
    return 0;
}
