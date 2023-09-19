#include <iostream>
using namespace std ;

class node {
	public :
		int data ;
		node * next ;
		
		node (int data){
			this->data = data ;
			this->next = nullptr ;
		}
};

void insertAtHead (int data , node * &Head){

	node * newNode = new node (data);
	newNode->next = Head ;
	Head = newNode ;
}

void insertAtTail (int data , node * &Head){
 	node * newNode = new node (data) ;
 	if (Head == nullptr){
 		Head = newNode ;
 		return ;
	 }
	 
	 node * temp = Head ; 
	 while (temp->next != nullptr){
	 	temp = temp->next ;
	 }
	 temp->next =  newNode ;	 
 }
 
 bool searchInLinkedList (node * Head , int key){
 	node * temp = Head ;
	 	while (temp->next != key){
	 		if (temp->data == key) return true ;
	 		temp = temp-> next ;
		 }
			 return false ;
 }
 void display (node * Head){
 	node * temp = Head ;
		while (temp != nullptr){
	 		cout << temp->data << "->" ;
	 		temp = temp->next ;
		 }
		    cout << "null" << endl ;
	 }								
	 
int main (){
	node * Head = nullptr;
	
	insertAtHead (2,Head);
	insertAtHead (5,Head);
	insertAtHead (6,Head);
		display (Head) ;
	insertAtTail (5,Head) ;
	insertAtHead (78,Head);
		display (Head) ;
	bool found = searchInLinkedList (Head , 6) ;
	
		if (found) cout << "Key has been found in list" ;
		else cout << "Key not in list!" ;
		
		
return 0 ;
}