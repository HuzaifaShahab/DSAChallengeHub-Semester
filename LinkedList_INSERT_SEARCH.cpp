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
 
 void insertAtSpecificPostion (node *& head , int nodetoInsAft){
 	
 	if (head == nullptr && head->next == nullptr){
 		return ;
	 }
	 
	 node * temp = head ;
	 node * newNode = new node (45) ; 
	 
		  while (temp->next != nullptr){
		 	 if (temp->data == nodetoInsAft){
			 	 	newNode->next = temp->next ; 
			 	 	temp -> next = newNode ;	
			  }
			  temp = temp->next ;
		 }
 	
 }
 void display (node * Head){
 	node * temp = Head ;
		while (temp != nullptr){
	 		cout << temp->data << "      ";
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
void deletion (node * head,int value){
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
     	node * a ;
		node * b ; 
		int temp1 ;
	
		for (a = head ; a->next != nullptr ; a = a->next ){
			
			for (b = head->next ; b -> next!= nullptr ; b = b -> next ){
				
			     temp1 = b->data ;
				b -> data = a->data ;
				a->data = temp1 ;
				
			}
		}
//
//        node* current ;
//        node* nextNode ;
//        node * temp = head ;
//        5 4 1 2 3
//        while (temp->next != nullptr) {
//        		nextNode = temp->next ;
//        		current=head ;
//        		
//        	while (nextNode != nullptr){
//        		 if (current->data > nextNode->data) {
//                // Swap current and nextNode values
//	                int temp = current->data;
//	                current->data = nextNode->data;
//	                nextNode->data = temp;
//           }
//           		current = nextNode;   
//			    nextNode = nextNode->next;
//           	    
//            }
//             temp = temp->next;
//        }
}


int main () {
	node * Head = nullptr;
	
	insertAtHead (1,Head);
//		display (Head) ;
	insertAtHead (5,Head);
//		display (Head) ;
	insertAtHead (2,Head);
//		display (Head) ;
	insertAtTail (4,Head) ;
//		display (Head) ;
//	insertAtHead (3,Head);
//		display (Head) ;
	insertAtHead (3,Head);
		display(Head);
	insertAtSpecificPostion (Head , 5) ;
	
		bool found = searchInLinkedList (Head , 787) ;
	
		if (found) cout << "Key has been found in list" << endl ;
		else cout << "Key not in list!" << endl;
		
//	delition (Head,5) ;
//		display(Head);	
//	delitionInHead (Head);
	
//	sortingLinkedList (Head);	
		display(Head);
		
return 0 ;
 }