#include <iostream>
#include <climits>

using namespace std;

class StackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    void push(int element) {
        if (nextIndex == capacity) {
            cout << "Stack full " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main() {
    StackUsingArray myStack(5); // Creating a stack with a capacity of 5

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Current stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    cout << "Pop: " << myStack.pop() << endl;
    cout << "Pop: " << myStack.pop() << endl;

    cout << "Current stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    myStack.push(40);
    myStack.push(50);

    cout << "Current stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    myStack.push(60); // This will print "Stack full" because the capacity is exceeded

    return 0;
}
