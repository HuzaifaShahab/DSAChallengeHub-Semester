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

void deletion (List*Head , int value){
	List * temp , * toDelete ;
	temp = Head ;
	while (temp->next->data != value){
		temp = temp->next ;
	}
	toDelete = temp->next ;
	cout << temp->next->data <<"  Deleted Successfully...." << endl;
	temp->next = temp->next->next ;


	delete toDelete ;
	
}
int main (){
	List * Head = nullptr ;
	
	insertInTail(Head,77) ;
	insertInTail(Head,44) ;
	traverse(Head) ;
	
	addInHead(Head,89) ;
	addInHead(Head,97);
	addInHead(Head,88);
	deletion(Head,44) ;
	traverse (Head) ;
}
