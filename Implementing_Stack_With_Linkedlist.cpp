#include<iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
   
    Node(int n)
    {
        this->data = n;
        this->next = nullptr;
    }
};
 
class Stack {
    Node* top;
 
public:
    Stack() { 
	top = nullptr;
	 }
 
    void push(int data)
    {
        Node* newNode = new Node(data);
        newNode->data = data ;
        newNode->next = top;
 		top = newNode;
    }
 
    bool isStackEmpty()
    {
        return top == nullptr; // Will return flag value either true or false
    }
 
    int peek()
    {
        if (isStackEmpty())
        cout << "Stack is empty" <<endl;
            return -1;
        else
            return top->data;
    }
 
    void pop()
    {
        Node* temp;
        if (top == nullptr) {
            cout << "\nStack Is Empty" << endl;
            return ;
        }
        else {
            temp = top;
            top = top->next; // It will give address of top having next field
            delete(temp); // Will free the memory
        }
    }
 
void displayStack()
    {
        Node* head;
 
        if (top == NULL) {
            cout << "\nStack Is Empty"<<endl;
           return ;
        }
        else {
            head = top;
            while (head != NULL) {
                cout << head->data << " --> ";
                head = head->next ;
            }
            cout <<endl;
        }
    }
};
 

int main()
{
    
    Stack stack;

 
 while (true) {
        cout << "Options Available :" << endl;
        cout << "1. Perform [ Push ]" << endl;
        cout << "2. Perform [ Pop ]" << endl;
        cout << "3. Perform [ Check if stack is empty ]" << endl;
        cout << "4. Perform [ Peek ]" << endl;
        cout << "5. Perform [ Display ]" << endl;
        cout << "6. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                if (stack.isStackEmpty()) {
                    cout << "Stack is empty" << endl;
                } 
				else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 4:
				cout<<stack.peek() ;
				break ;
			case 5:
				stack.displayStack() ;
				break ;
			case 6:
				return 0 ;
			default : 
				cout << "------------" << endl;			    
	}
	
  }
	return 0 ;
}