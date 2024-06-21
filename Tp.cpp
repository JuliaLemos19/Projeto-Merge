#include <iostream>
#include <stdexcept>

using namespace std;

// Definição de uma classe de nó para a lista encadeada
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Definição da classe Stack usando uma lista encadeada
class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() : top(nullptr) {}

    // Verifica se a pilha está vazia
    bool isEmpty() {
        return top == nullptr;
    }

    // Adiciona um elemento no topo da pilha
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Remove e retorna o elemento do topo da pilha
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

    // Função auxiliar para desempilhar e exibir os valores em ordem decrescente
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
        cout << "Número " << i + 1 << ": ";
        cin >> num;

        // Garantir que o número seja maior que o anterior
        if (num <= previousNumber) {
            cout << "Erro: o número deve ser maior que " << previousNumber << ". Tente novamente." << endl;
            --i; // Decrementa i para repetir a entrada para este índice
            continue;
        }

        previousNumber = num;

        // Empilha o número na pilha correspondente (par ou ímpar)
        if (num % 2 == 0) {
            evenStack.push(num);
        } else {
            oddStack.push(num);
        }
    }

    // Exibe os números das pilhas em ordem decrescente
    cout << "Números pares em ordem decrescente: ";
    evenStack.displayDescending();

    cout << "Números ímpares em ordem decrescente: ";
    oddStack.displayDescending();

    return 0;
}
