#include<iostream>
using namespace std ;

class Stack {

private:
	int * array ;
	int size ;
	int top = -1 ;
	
	public:
	
	Stack(int size){
		array = new int[size] ;	
	}
	
	void push (int element){
		if (size-top>1){
			
			array[++top] = element;
		}
		else{
			cout << "Stack Overflow" << endl ;	
		}
	}
	void pop (){
		if (top >= 0){
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

		if (top == -1) return true ;
		
		else  return false ;
	}
	
void displayStack (){
	
	if (isStackEmpty ()) {
			return ; 
		}
	else {	
	 cout << "Elements in stack" <<endl;
		
		for (int i=0 ; i<=top ; i++){
			cout <<" | " <<array[i] << " | " <<endl ;
			cout << "  ____" <<endl;
		}
		
	}
};
int main (){
	
	Stack stack(5) ;
	
	while (true) {
        cout << "Options Available :" << endl;
        cout << "1. Perform [ Push ]" << endl;
        cout << "2. Perform [ Pop ]" << endl;
        cout << "3. Perform [ Check if stack is empty ]" << endl;
        cout << "4. Perform [ Peek ]" << endl;
        cout << "5. Perform [ Display ]" << endl;
        cout << "6. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                if (stack.isStackEmpty()) {
                    cout << "Stack is empty" << endl;
                } 
				else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 4:
				stack.peek() ;
				break ;
			case 5:
				stack.displayStack() ;
				break ;
			case 6:
				return 0 ;
			default : 
				cout << "------------" << endl;			    
	}
	
  }
	return 0 ;
}