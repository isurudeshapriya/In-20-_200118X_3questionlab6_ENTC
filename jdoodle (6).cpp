#include <iostream>
#include <chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    bool isEmpty() {
        return (top == nullptr);
    }
    bool isFull() {
        // Linked list implementation does not have a fixed size limit
        return false;
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else {
            return top->data;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    auto start_stack_linked = chrono::high_resolution_clock::now();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for (int i = 0; i < 5 ; i++){
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    auto end_stack_linked = chrono::high_resolution_clock::now();
    auto elapsed_stack_linked = chrono::duration_cast<chrono::microseconds>(end_stack_linked - start_stack_linked);
    cout <<"Time taken for execution operations of  stack implimented by using linked list: " << elapsed_stack_linked.count() << " microseconds" << endl;


    return 0;
}