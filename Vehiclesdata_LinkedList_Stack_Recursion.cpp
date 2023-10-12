#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    string carName;
    string carModel;
    int carManuYear;
    Node* next;

    Node(string name, string model, int manuYear) : carName(name), carModel(model), carManuYear(manuYear), next(nullptr) {}
};

// Stack class to implement stack operations
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(string name, string model, int manuYear) {
        Node* newNode = new Node(name, model, manuYear);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Display the stack data
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << "Car Name: " << temp->carName << " | Car Model: " << temp->carModel << " | Manufacturing Year: " << temp->carManuYear << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

// Linked list class to manage the vehicle data
class VehicleList {
public:
    Node* head;

public:
    VehicleList() : head(nullptr) {}

    // Insert a new vehicle at the beginning of the linked list
    void insert(string name, string model, int manuYear) {
        Node* newNode = new Node(name, model, manuYear);
        newNode->next = head;
        head = newNode;
    }

    // Display the linked list data
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Car Name: " << temp->carName << " | Car Model: " << temp->carModel << " | Manufacturing Year: " << temp->carManuYear << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the linked list data in reverse using a stack
    void displayReverse() {
        Stack stack;
        Node* temp = head;
        while (temp != nullptr) {
            stack.push(temp->carName, temp->carModel, temp->carManuYear);
            temp = temp->next;
        }
        stack.display();
    }

    // Display the linked list data in reverse using recursion
    void displayReverseRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }
        displayReverseRecursive(current->next);
        cout << "Car Name: " << current->carName << "| Car Model: " << current->carModel << " | Manufacturing Year: " << current->carManuYear << endl;
    }
};

int main() {
    VehicleList vehicleList;

    // Inserting data into the linked list
    vehicleList.insert("Toyota", "Camry", 2021);
    vehicleList.insert("Honda", "Civic", 2022);
    vehicleList.insert("Ford", "Mustang", 2020);

    cout << "Displaying Linked List Data:" << endl;
    vehicleList.display();

    cout << "Displaying Linked List Data in Reverse Using Stack:" << endl;
    vehicleList.displayReverse();

    cout << "Displaying Linked List Data in Reverse Using Recursion:" << endl;
    vehicleList.displayReverseRecursive(vehicleList.head);

    return 0;
}