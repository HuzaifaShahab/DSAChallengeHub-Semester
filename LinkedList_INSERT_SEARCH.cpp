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
	 		cout << temp->data << " --> ";
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
	
    cout << "Sorting linked list..." << endl; // Print a message to indicate we're sorting.

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

void traverseLinkedList (node * head) {
	cout << "Traversing Linked List...." ;
	
	node * temp = head ;
	cout<<endl;
	while (temp->next != nullptr){
		cout <<temp->data << " --> " ;
		temp = temp->next ;
	}
	cout<<temp->data ;
	cout<<" --> null" ;
}

void midpointFind (node * &head){
	node * fast , *slow ;
	slow = head ;
	fast = head ;
//	cout <<"Hello" ; 
	while (fast->next != nullptr){
		slow = slow->next ;
		fast = fast->next->next ;
		
	}
	cout <<"Midpoint is : " << slow->data ;
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
	
	sortingLinkedList (Head);	
		display(Head);
	traverseLinkedList(Head) ;
	midpointFind (Head) ;
		
return 0 ;
 }