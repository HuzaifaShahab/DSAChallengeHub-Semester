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

// Initializing LinkedList with a new node

void initializeLinkedList (node * &head , int data){
	node * temp = head ;
		if (temp == nullptr){
			node *newNode = new node (data) ; 
			newNode->next = head ;
			head = newNode ;
			cout << "linked List has been initialized...";
		}else {
			cout << "Already initialized !" ;
		}			
}

// Inserting a node at the beginning (Head)

void insertAtHead (int data , node * &Head){

	node * newNode = new node (data);
	newNode->next = Head ;
	Head = newNode ;
	
	cout << data <<" as Head in list"<<endl;
}

// Inserting a node at the end (Tail)

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
 
// Inserting a node at any specific position choose by a user

 void insertAtSpecificPostion (node *& head , int nodetoInsAft){
 	
 	if (head == nullptr && head->next == nullptr){
 		return ;
	 }
	 
	 node * temp = head ;
	 node * newNode = new node (nodetoInsAft) ; 
	 
	 while (temp->next != nullptr){
		 if (temp->data == nodetoInsAft){
	 	 	newNode->next = temp->next ; 
		 	temp -> next = newNode ;	
			}
		    temp = temp->next ;
		 }	
 }
 
 bool searchInLinkedList (node * Head,int key){
 	node * temp = Head ;
 	cout << key << " is the key" <<endl;
	 	while (temp->next != nullptr){
	 		if (temp->data == key) 
			 return true ;
	 		temp = temp-> next ;
		 }
		 return false ;
			
 }
 
 
 void display (node * Head){
 	node * temp = Head ;
		while (temp != nullptr){
	 		cout << temp->data << " --> ";
	 		temp = temp->next ;
		 }
		    cout << "null" << endl ;
	 }				

// If User Specifically want to delete the head of linked list
	 
void deletionInHead (node * &head){
	if (head == nullptr){
		return ;
	}
	
	node * todelete = head ;
	cout << head->data << " Head Deleted !" <<endl ;
	head = head -> next ;
	
	delete todelete ;
	
}	

// Deleting a specific node from linked list
 
void deletion (node * head, int value){
	node * temp = head;
	if (head == nullptr){
		cout << "No node found" ;
		return ;
	}
	// n-1
		while (temp->next->data != value){
			temp = temp -> next ;
		}
	
	    node * todelete = temp->next ; // n
	    cout << temp->next->data << " Deleted Succesfully !"<<endl ;
	    temp->next = temp->next->next ;  // n+1
		 delete todelete ;
}

// Sorted LinkedList using concept of Bubble sort

void sortingLinkedList (node * &head){
	
    cout << "Sorted linked list" << endl ; 

    if (head == nullptr) {
        cout << "No nodes found in the linked list to be sorted" << endl;
        return ; 
    } 

    bool swapped; 
    node* temp; 
    node* last = nullptr; 

	    do {
	        swapped = false; 
	        temp = head; 
	        while (temp->next != last) { 
	            if (temp->data > temp->next->data) {
	                // Swap data between two  nodes.
	                int current = temp->data;
	                temp->data = temp->next->data;
	                temp->next->data = current;
	                swapped = true; 
	            }
	            temp = temp->next; 
	        }
	        last = temp; 
	    } while (swapped); 
}

// Traversing Linked List

void traverseLinkedList (node * head) {
	cout << "Traversing Linked List" ;
	
	node * temp = head ;
	cout<<endl;
	while (temp->next != nullptr){
		cout <<temp->data << " --> " ;
		temp = temp->next ;
	}
	cout<<temp->data ;
	cout<<" --> null" ;
}

// Code To find midpoint in a Linkedlist

void midpointFind (node * &head){
	node * fast , *slow ;
	slow = head ;
	fast = head ;
	
		while (fast != nullptr && fast->next != nullptr){
			slow = slow->next ;
			fast = fast->next->next ;
			
		}
		cout <<endl<<"Midpoint is : " << slow->data ;
}


int main () {
	
	node * Head = nullptr;
	int choice = 0 ;
	do {
		 
		cout << "\nWith which operation you want to go ? \n" << endl;
		
		cout << "  1. Initialize an empty linked list" << endl ;
		cout << "  2. Insert a node at the beginning" << endl ;
		cout << "  3. Insert a node at the end" << endl ;
		cout << "  4. Insert a node at a given position" << endl ;
		cout << "  5. Delete a specific node" << endl ;
        cout << "  6. Search for specific node" << endl ;
		cout << "  7. Sort the Linked list" << endl ;
		cout << "  8. Print the elements of the linked list" << endl ;
		cout << "  9. Exit\n" << endl ; 
		
		cout << "Select particular serial No. for operation (1 - 9)" << endl ;
		cin >> choice ;
		
		if (choice == 1){
				cout << "Input element with which you want to initialize Link.list" << endl;
				int val_ ;
				cin>>val_ ;
				initializeLinkedList(Head,val_) ;
		}
		else if (choice == 2){
				cout << "Input data to insert a node at the beginning" << endl;
				int val ;
				cin>>val ;
				insertAtHead(val,Head) ;
				
		}
		else if (choice == 3){
				  cout << "Input data to insert a node at the end" << endl;
				int val1 ;
				cin>>val1 ;
				insertAtTail(val1,Head) ;
		}
		else if (choice == 4){
				 cout << "Input specific position to insert a node after it" << endl;
				int nodeToInsAft ;
				cin>>nodeToInsAft ;
				insertAtSpecificPostion(Head,nodeToInsAft) ;
		}
		else if (choice == 5){
			cout << "Input node data to delete permanently" << endl;
				int val2;
				cin>>val2 ;
				deletion(Head,val2) ;
		}
		else if (choice == 6){
				 cout << "Input Key to search for node" << endl;
				int Key;
			    cin>>Key ;
			    
				bool flag = searchInLinkedList(Head,Key) ;
					if(flag) cout<<"Key Has Been Found"<<endl; 
					else cout <<"Key not found" <<endl;
		}
		else if (choice == 7){
				sortingLinkedList(Head) ;
				cout << "Linked list Successfully Sorted" << endl;
		}
		else if (choice == 8){
				 cout << "\nPrinting the elements of the linked list" << endl;
				display(Head) ;
		}
		else if (choice == 9){
				cout << "\nThanks, Have a nice day." << endl;
		}
			
	}while (choice!=9);
		
return 0 ;
 }