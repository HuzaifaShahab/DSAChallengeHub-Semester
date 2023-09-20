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
	
	cout << data <<" as Head in list"<<endl;
}

void insertAtTail (int data , node * &Head){
 	node * newNode = new node (data) ;
 	if (Head == nullptr){
 		Head = newNode ;
 		cout << data << " as Tail in list" <<endl ;
 		return ;
	 }
	 
	 node * temp = Head ; 
	 while (temp->next != nullptr){
	 	temp = temp->next ;
	 }
	 temp->next =  newNode ;	 
	 cout << data << " as Tail in list" << endl ;
 }
 
 bool searchInLinkedList (node * Head , int key){
 	node * temp = Head ;
 	cout << key << " is the key" <<endl;
	 	while (temp->next != nullptr){
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
	 
void delitionInHead (node * &head){
	if (head == nullptr){
		return ;
	}
	
	node * todelete = head ;
	cout << head->data << " Head Deleted !" <<endl ;
	head = head -> next ;
	
	delete todelete ;
	
}	 
void delition (node * head,int value){
	node * temp = head;
	// n-1
		while (temp->next->data != value){
			temp = temp -> next ;
		}
	
    node * todelete = temp->next ; // n
    cout << temp->next->data << " Deleted Succesfully !"<<endl ;
    temp->next = temp->next->next ;  // n+1
	 delete todelete ;
}

void sortingLinkedList (node * &head){
	node * temp = head ;
	while (temp->next = nullptr){
		node * t = temp->next ;
		
		if (temp->data > t->data){
			t->next = head ;
			temp -> next = t->next ; 
		}
		
			temp = temp->next ;
		
	}
}
int main (){
	node * Head = nullptr;
	
	insertAtHead (2,Head);
		display (Head) ;
	insertAtHead (5,Head);
		display (Head) ;
	insertAtHead (6,Head);
		display (Head) ;
	insertAtTail (5,Head) ;
		display (Head) ;
	insertAtHead (78,Head);
		display (Head) ;
	
		bool found = searchInLinkedList (Head , 787) ;
	
		if (found) cout << "Key has been found in list" << endl ;
		else cout << "Key not in list!" << endl;
		
	delition (Head,5) ;
		display(Head);	
	delitionInHead (Head);
		display(Head);
	sortingLinkedList (Head);	
		display(Head);
		
return 0 ;
}