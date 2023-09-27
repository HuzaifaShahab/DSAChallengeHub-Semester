#include <iostream>
using namespace std ;

void passingArray (int * &array , int size){
	for (int i=0;i<size;i++){
		cout << *array + i <<"  " ;
	}
}
int main (){
	int size = 0;
	cout << "Input Size of an array" << endl;
	cin >> size ;
	
	int * array = new int [size] ;
	
	for (int i=0;i<size;i++){
		cout << "Input Element at index : [ "<<i<<" ]" <<endl;
		cin >> array[i] ;
	}
	
	 passingArray (array , size) ;
	
	delete [] array ;
}