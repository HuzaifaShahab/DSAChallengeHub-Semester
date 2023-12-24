 #include <iostream>
using namespace std ;

class node {
public :
    int data ;
    node * next ;
public : 
    node (int data){  // Parametrized Constructor
        this->data = data ;
        this->next = nullptr ;
    }
};

// Initializing LinkedList with a new node

void initializeLinkedList (node * &head , int data){
    node * temp = head ;
    if (temp == nullptr){ // Will Initialized the linkedList
        node *newNode = new node (data) ;
        newNode->next = head ;
        head = newNode ;
        cout << "\nlinked List has been initialized...\n\n";
    }else {
        cout << "\nAlready initialized !\n\n" ;
    }
}

// Inserting a node at the beginning (Head)

void insertAtHead (int data , node * &Head){

    node * newNode = new node (data); // Node created on Heap memory
    newNode->next = Head ;
    Head = newNode ;

    cout << endl << data <<" as Head in list"<<endl;
}

// Inserting a node at the end (Tail)

void insertAtTail (int data , node * &Head){
    node * newNode = new node (data) ;

    if (Head == nullptr){
        Head = newNode ;
        cout << endl << data << " inserted in list" <<endl ;
        return ;
    }

    node * temp = Head ;

    while (temp->next != nullptr){
        temp = temp->next ;
    }
    	temp->next =  newNode ;
    	cout << endl <<data << " as Tail in list" << endl ;
}

// Inserting a node at any specific position choose by a user

void insertAtSpecificPosition (node *& head , int nodeToInsAft){

    if (head == nullptr){
        cout << "\nNode inserted in list successfully...\n\n";
        return ;
    }
    int value ;
    node * temp = head ;
    cout << "Input Data for new node" <<endl;
        cin >> value ;
    node * newNode = new node (value) ;

    while (temp->next != nullptr){ // Will Traverse Till Last
        if (temp->data == nodeToInsAft){
            newNode->next = temp->next ;
            temp -> next = newNode ;
        }
        temp = temp->next;
    }
    	cout << "\nNode inserted in list successfully...\n\n";
}

// Will search the respective key in the linked list

bool searchInLinkedList (node * &Head,int key){
    node * temp = Head ;
    cout << key << " is the key to search for." <<endl;
    while (temp->next != nullptr){
        if (temp->data == key)
            return true ;
        temp = temp-> next ;
    }
    if(temp->data == key) return true ;
    // Otherwise 
        return false ;

}

//Will Showcase all nodes in linked list

void display (node * Head){
    node * temp = Head ;
    cout<<endl ;
    while (temp != nullptr){
        cout << temp->data << " --> ";
        temp = temp->next ;
    }
    cout << "null\n\n" << endl ;
}

// If User Specifically want to delete the head of linked list

void deletionInHead (node * &head){
    if (head == nullptr){
        return ;
    }
    node * todelete = head ;
    cout << head->data << " Head Deleted !\n\n" <<endl ;
    head = head -> next ;

    delete todelete ;

}

// Deleting a specific node from linked list

void deletion (node * head, int value){
    node * temp = head;
    node * toDeleteHead ;

    if (head == nullptr){
        cout << "\nNo node found\n\n" ;
        return ;}

    else if (head->next == nullptr){
        cout<<head->data << " Deleted Successfully" ;
        toDeleteHead = head ;
    }

// n-1
    while (temp->next->data != value){  // Will give us n-1
        temp = temp -> next ;
    }

    node * toDelete = temp->next ; // n
    cout << temp->next->data << " Deleted Successfully !\n\n"<<endl ;
    temp->next = temp->next->next ;  // n+1
    delete toDelete ;
    delete toDeleteHead ;
}

// Sorted LinkedList using concept of Bubble sort

void sortingLinkedList (node * &head){

    cout << "\nSorted linked list\n" << endl ;

    if (head == nullptr) {
        cout << "No nodes found to sort" << endl;
        return ;
    }

    bool flag;
    node* temp;
    node* last = nullptr;

    do {
        flag = false;
        temp = head;
        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                // swappinng using third variable
                int current = temp->data;
                temp->data = temp->next->data;
                temp->next->data = current;
                flag = true;
            }
            temp = temp->next;
        }
        last = temp; // For starting loop again and again  to sort out our linked list
    } while (flag);
}

// Traversing Linked List

void traverseLinkedList (node * head) {
    cout << "\nTraversing Linked List\n" ;

    node * temp = head ;
    cout<<endl;
    while (temp != nullptr){
        cout <<temp->data << " --> " ;
        temp = temp->next ;
    }
    cout<<" --> null" ;
}   

// Code To find midpoint in a Linkedlist

node * midpointFind (node * &head){
    node * fast , *slow ;
    slow = head ;
    fast = head ;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next ;
        fast = fast->next->next ;
    }
   return slow ;
}

// Merging Two Halves of linked list.

node * mergeLinkedList(node*left , node*right){
	
	if (left == nullptr) return right ;
	
	if (right = nullptr) return left ;
	
	node * dummyNode = new node (-1) ;
	node * temp = dummyNode ;
	
	while (left != nullptr && right != nullptr){
			
			if (left->data < right->data){
				temp->next = left ;
				temp = left ;
				left = left->next ;	
			}
			else {
				temp->next = right ;
				temp = right ;
				right = right->next ;
			}
	}


	while (left != nullptr){
		temp->next = left ;
		temp = left ;
		left = left->next ;	
	}
	while (right != nullptr){
		temp->next = right ;
		temp = right ;
		right = right->next ;
	}
		dummyNode = dummyNode->next ;
	
	return dummyNode ;
}

// Sorting Through Merge Sort

node * mergeSort (node*&head){
	if (head == nullptr || head->next == nullptr){
		return head;
	}
	
//	Now to find mid point of a linked List 

	node * mid = midpointFind(head) ;
	
		node * left = head; 
		node * right = mid->next ;
		mid->next = nullptr ;
		
//		Now by recursive calls going to sort Linked List

	left = mergeSort(left);
	right = mergeSort(right);
	
	node * final = mergeLinkedList (left,right);
 return final ;


int main () {

    node * Head = nullptr;
    int choice = 0 ;
    do {

        cout << "\nWith which operation you want to go ? \n" << endl;

        cout << "  1.  Initialize an empty linked list" << endl ;
        cout << "  2.  Insert a node at the beginning" << endl ;
        cout << "  3.  Insert a node at the end" << endl ;
        cout << "  4.  Insert a node at a given position" << endl ;
        cout << "  5.  Delete a specific node" << endl ;
        cout << "  6.  Search for specific node" << endl ;
        cout << "  7.  Sort the Linked list using Bubble Sort" << endl ;
    	cout << "  8.  Sort the Linked list using Merge Sort" << endl ;
        cout << "  9.  Print the elements of the linked list" << endl ;
        cout << "  10. Exit\n" << endl ;

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
            insertAtSpecificPosition(Head, nodeToInsAft) ;
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
            cout << "Linked list Successfully Sorted through Bubble Sort" << endl;
        }
        else if (choice == 8){
        	sortingLinkedList(Head) ;
            node * final = mergeSort(Head) ;
            display(final);

        else if (choice == 9){
            cout << "\nPrinting the elements of the linked list" << endl;
            display(Head) ;
        }
        else if (choice == 10){
            cout << "\nThanks, Have a nice day." << endl;
        }

    }while (choice!=10);

    return 0 ;
}
}