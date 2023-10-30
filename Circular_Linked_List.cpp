#include <iostream>
using namespace std ;

class List {
	public :
		int data ;
		List * next ;
		
		List (int data){
			this->data = data ;
			this->next = nullptr ;
		}
};

void addInHead (List*&Head,int data){

 if (Head == nullptr) {
		List * newNode = new List(data) ;
		Head = newNode ;
		return ;
 }
	List * temp ;
	temp = Head ;
	
	while (temp->next != Head){
		temp = temp->next ;
	}
	
	List *newNode = new List(data) ;
	temp->next = newNode ;
	
	
	
	
	newNode -> next = Head ;
	Head = newNode ; 
}

void insertInTail (List*&Head , int data){
	if (Head == nullptr){
		List* newNode = new List(data) ;
		Head = newNode ;
		newNode ->next = Head ;
		return ;
	}
	
	List * temp ;
	temp = Head ;
	

		while (temp->next != Head){
			temp = temp->next ;
		}
		
		List *newNode = new List(data) ;
		temp->next = newNode ;
		newNode->next = Head ;
}

void traverse (List * Head){
	List * temp ;
	temp = Head ;
	
	do {
		cout << temp->data << "-->" ;
		temp = temp->next ;
	}while (temp!=Head);
	cout << " null"<<endl ;
}

void deletion(List*& Head, int value) {
    if (Head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    List* temp = Head;
    List* toDelete = nullptr;

    if (temp->data == value) {
        toDelete = Head;

        if (Head->next == Head) {
            // Only one element in the list, set Head to nullptr
            Head = nullptr;
        } else {
            // Move Head to the next node
            Head = Head->next;
        }

        // Update the last node's next to the new Head
        List* lastNode = Head;
        while (lastNode->next != toDelete)
            lastNode = lastNode->next;
        lastNode->next = Head;

        cout << toDelete->data << " Deleted Successfully." << endl;
        delete toDelete;
        return;
    }

    // Find the node to delete and update the previous node's next pointer
    while (temp->next != Head && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == Head) {
        cout << "Value not found in the list." << endl;
    } else {
        toDelete = temp->next;
        temp->next = temp->next->next;
        cout << toDelete->data << " Deleted Successfully." << endl;
        delete toDelete;
    }
}

int main (){
	List * Head = nullptr ;
	
	insertInTail(Head,77) ;
	insertInTail(Head,44) ;
	traverse(Head) ;
	
	addInHead(Head,89) ;
	addInHead(Head,97);
	addInHead(Head,88);
	addInHead(Head,97) ;
	deletion(Head,97);
	traverse (Head) ;
}
