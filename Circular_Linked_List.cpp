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
		List newNode = new List(data) ;
		Head = newNode ;
		return ;
 }
	List * temp ;
	temp = Head ;
	
	while (temp->next != Head){
		temp = temp->next ;
	}
	
	List newNode = new List(data) ;
	temp->next = newNode ;
	newNode -> next = head ;
	head = newNode ; 
}

void insertInTail (List*&Head , int data){
	if (tail == nullptr){
		List newNode = new List(data) ;
		Head = newNode ;
		newNode ->next = Head ;
		return ;
	}
	
	List * temp ;
	temp = Head ;
	
	while (temp->next!=nullptr){
		temp = temp->next ;
	}
	temp->next = Head ;

		while (temp->next != Head){
			temp = temp->next ;
		}
		List newNode = new List(data) ;
		temp->next = newNode ;
		newNode->next = Head ;
}

void traverse (List & Head){
	List * temp ;
	temp = Head ;
	
	do {
		cout << temp->data << "-->" ;
		temp++ ;
	}while (temp!=Head);
}
int main (){
	List * Head = nullptr ;
	
}