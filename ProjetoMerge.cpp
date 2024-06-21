#include <iostream>
#include <stdexcept>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() : top(nullptr) {}

    
    bool isEmpty() {
        return top == nullptr;
    }

  
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

      int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    
    void displayDescending() {
        while (!isEmpty()) {
            cout << pop() << " ";
        }
        cout << endl;
    }
};

int main() {
    LinkedStack evenStack;
    LinkedStack oddStack;
    int previousNumber = -1;

    cout << "Digite 30 números inteiros em ordem crescente:" << endl;

    for (int i = 0; i < 30; ++i) {
        int num;
        cout << "Numero " << i + 1 << ": ";
        cin >> num;

       
        if (num <= previousNumber) {
            cout << "Erro: o número deve ser maior que " << previousNumber << ". Tente novamente." << endl;
            --i; 
            continue;
        }

        previousNumber = num;

       
        if (num % 2 == 0) {
            evenStack.push(num);
        } else {
            oddStack.push(num);
        }
    }

 
    cout << "Números pares em ordem decrescente: ";
    evenStack.displayDescending();

    cout << "Números ímpares em ordem decrescente: ";
    oddStack.displayDescending();

    return 0;
}