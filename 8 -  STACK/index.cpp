#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    int *arr;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == size - 1; }

    void push(int data) {
        if (isFull()) {
            cout << "\nStack Overflow! Cannot push " << data << ".\n";
            return;
        }
        arr[++top] = data;
        cout << data << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack is Empty! Nothing to pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    int getTop() {
        if (isEmpty()) {
            cout << "\nStack is Empty!\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "\nStack is Empty!\n";
            return;
        }
        cout << "\nStack elements (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            if (i == top)
                cout << "[Top] " << arr[i] << "\n";
            else
                cout << "      " << arr[i] << "\n";
        }
        cout << "\n";
    }

    int getSecondLargest() {
        if (top < 1) {
            cout << "\nNot enough elements to find second largest.\n";
            return -1;
        }
        int largest = arr[0], second = arr[0];
        for (int i = 1; i <= top; i++) {
            if (arr[i] > largest) {
                second = largest;
                largest = arr[i];
            } else if (arr[i] > second && arr[i] != largest) {
                second = arr[i];
            }
        }
        return second;
    }
};

int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;
    Stack s(n);

    int choice, val;
    do {
        cout << "\n==============================\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Second Largest\n0. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                val = s.getTop();
                if (val != -1) cout << "Top element: " << val << "\n";
                break;
            case 4:
                s.display();
                break;
            case 5:
                val = s.getSecondLargest();
                if (val != -1) cout << "Second Largest element: " << val << "\n";
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 0);

    return 0;
}
