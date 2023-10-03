#include<iostream>
#include<stack>
using namespace std ;

class Stack {

private:
	int  * array ;
	int size ;
	int top=-1;
	
	public:
	
	Stack(int size){
		array = new int[size] ;	
	}
	
	void push (int element){
		if (size-top>1){
			top++;
			array[top] = element;
		}
		else{
			cout << "Stack Overflow" << endl ;	
		}
	}
	
	void pop (){
		if (top >= 1){
			array[top--];
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
			cout <<" | " <<array[i] << " | " <<endl ;
			cout << "____" <<endl;
		}
		
	}
};
int main (){
	
	Stack stack(5) ;
	stack.push(80);
	stack.push(89);
	stack.push(56) ;
	stack.push(6) ;


	cout <<"Stack Status : " <<stack.isStackEmpty () ;

	cout <<"Peek value is : "<<stack.peek() << endl;

	stack.pop () ;
	stack.displayStack () ;
}