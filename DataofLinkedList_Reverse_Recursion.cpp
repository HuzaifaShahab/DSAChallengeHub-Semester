#include <iostream>
using namespace std ;
struct Node {
	int data ;
	Node * next ;
	Node (int data){
		this->data = data ;
		this->next = nullptr ; 
	}
};

void insertAtHead (Node * Head , int data){
	Node *newNode = new Node (data) ;
	newNode->next = Head ;
	Head = newNode ;
}

void insertAtTail (Node * Head , int data){
	if (!Head){
		Node *newNode = new Node (data) ;
		Head = newNode ;
	}else {
		Node * temp ;
		temp = Head ;
		Node* newNode = new Node (data) ;
		while (temp->next!=nullptr){
			temp=temp->next ;
		}
		temp->next = newNode ;
		newNode->next = nullptr ;
	}
	
}

void Display (Node * Head){
	Node * temp = Head ;
	cout<<"Hello" ;
	while (temp->next != nullptr){
		cout << temp->data << " -- > ";
		temp = temp->next ;
	}
	cout << " null" <<endl ;
}
int main (){
	Node * Head  = nullptr;
	insertAtHead(Head,56) ;
	insertAtHead(Head,61) ;
	insertAtHead(Head,44) ;
	insertAtTail(Head,77) ;
	insertAtTail(Head,99) ;
	
	Display (Head) ;

}