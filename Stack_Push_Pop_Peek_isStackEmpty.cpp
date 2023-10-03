#include<iostream>
using namespace std ;

class Stack {
	int * array ;
	int length ;
	int top = -1 ;
	
	public :
	Stack (int length){
		this->length = length ;
		array = new int[length] ;	
	}
	
	void push (int element){
		if (length - top > 1){
			top++ ;
			array[top] = element ;
		}
		else{
			cout << "Stack Overflow" <<endl;	
		}
	}
	
	void pop (){
		if (top >= 1){
			array[top--] ;
		}
		else{
			cout << "Stack is empty" << endl;
		}
	}
	
	int peek (){
		return array[top] ;
}
	bool isStackEmpty (){
		if (top <= -1){
			return true ;
		}
		else  return false ;
	}
	
	void displayStack (){
		cout << "Elements in stack" <<endl;
		for (int i=0 ; i<=top ; i++){
			cout << array[i] << " " ;
		}
	}
};
int main (){
	Stack stack(5) ;
	stack.push(8);
	stack.push(89);
	stack.push(56) ;
	stack.push(6) ;
	cout << endl;
	cout << stack.isStackEmpty () ;
	cout << endl ;
	cout << stack.peek () ;
	cout << endl;
	stack.pop () ;
	stack.displayStack () ;
}