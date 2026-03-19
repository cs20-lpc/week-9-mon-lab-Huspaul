#include "LinkedQueue.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printQueue(LinkedQueue<T> q) {
    while (!q.isEmpty()) {
        cout << q.front() << ' ';
        q.dequeue();
    }
    cout << '\n';
}

int main() {
    cout << "=== int queue tests ===\n";
    LinkedQueue<int> intQ;

    cout << "Initially empty: " << (intQ.isEmpty() ? "true" : "false") << '\n';
    cout << "Initial length: " << intQ.getLength() << '\n';

    try {
        cout << intQ.front() << '\n';
    }
    catch (string& e) {
        cout << "front() on empty queue: " << e << '\n';
    }

    try {
        cout << intQ.back() << '\n';
    }
    catch (string& e) {
        cout << "back() on empty queue: " << e << '\n';
    }

    try {
        intQ.dequeue();
    }
    catch (string& e) {
        cout << "dequeue() on empty queue: " << e << '\n';
    }

    intQ.enqueue(10);
    intQ.enqueue(20);
    intQ.enqueue(30);

    cout << "After enqueue 10,20,30 -> length: " << intQ.getLength()
         << ", front: " << intQ.front()
         << ", back: " << intQ.back() << '\n';

    intQ.dequeue();
    cout << "After one dequeue -> length: " << intQ.getLength()
         << ", front: " << intQ.front()
         << ", back: " << intQ.back() << '\n';

    LinkedQueue<int> intCopy(intQ);
    cout << "Copy-constructed queue contents: ";
    printQueue(intCopy);

    LinkedQueue<int> intAssigned;
    intAssigned.enqueue(999);
    intAssigned = intQ;
    cout << "Assigned queue contents: ";
    printQueue(intAssigned);

    intQ.clear();
    cout << "After clear -> empty: " << (intQ.isEmpty() ? "true" : "false")
         << ", length: " << intQ.getLength() << '\n';

    cout << "\n=== string queue tests ===\n";
    LinkedQueue<string> strQ;
    strQ.enqueue("alpha");
    strQ.enqueue("beta");
    strQ.enqueue("gamma");

    cout << "String queue front/back: " << strQ.front() << " / " << strQ.back() << '\n';
    cout << "String queue contents in FIFO order: ";
    printQueue(strQ);
    cout << "String queue empty after print copy: " << (strQ.isEmpty() ? "true" : "false") << '\n';

    return 0;
}
