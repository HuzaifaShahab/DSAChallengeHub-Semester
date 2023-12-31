#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>  // Added for transform for lowerCasing 
using namespace std;

int ascii = 220 ;
char star = ascii ;
// For Proper Segmentation's
void stars(){
	for (int i=0;i<60;i++)
	cout<<star;
	cout<<"\n\n";
}

// Structure to represent a word and its meaning
struct WordNode {
    string word;
    string meaning;
    WordNode* nextWord; // Pointer to the next word node
};

// Structure to represent an alphabet node
struct AlphabetNode {
    char alphabet;
    WordNode* nextWord; // Pointer to the first word node in the alphabet
    AlphabetNode* nextAlphabet; // Pointer to the next alphabet node
};

// Class to push the words & Meanings to Single Linked list class 
class SingleNode {
	public : 
	SingleNode * Head = nullptr;
	SingleNode * next ;
	string word , meaning ;
	
	public :
		SingleNode (){	
			next = nullptr ;
		}
		
		void insertInSingleLinkedList (string word , string meaning){
			
			SingleNode * newNode = new SingleNode() ;
			newNode->word = word ;
			newNode->meaning = meaning ;
			newNode -> next = Head ;
			Head = newNode ;
		}
		
		void searchInLinkedList (string word){
			SingleNode * currentNode = Head ;
			
			while (currentNode){
				if (currentNode->word == word){
					cout << "Word & their meaning in a single linked list." << "\n" ;
					return ;
				}
				currentNode = currentNode->next;
				if (!currentNode){
					cout << "Word & their meaning in a single linked list." << "\n" ;
					return ;
				}
			}
			cout << "Word & their meaning is'nt in the dictionary." << "\n" ;	
		}
		
void searchTimeSinglyLL(string word) {

	SingleNode * currentNode = Head ;
    double wordCount=0;
    double totalJumps=0;
	while (currentNode && currentNode->word != word) {
                wordCount++ ;
                totalJumps++;
                currentNode = currentNode->next ;
        }

    double averageSearchTime = (totalJumps) / wordCount;

    cout<<"Average Search Time (Singly LinkedList): "<<averageSearchTime<<endl;
}

		
void deletionInlinkedList(string word) {
    SingleNode* currentWord = Head;
    SingleNode * toDelete ;

    // Displaying warning
    cout << "Are you sure you want to delete the word | " << word << " | from Dictionary? (yes/no): ";
    char pick;
    cin >> pick;

    if (pick =='y'||pick=='Y') {
        // Check if the word is found
        if (!currentWord) {
            cout <<"Word not found in the dictionary: " <<word<<"\n";
            return ;
        }
        if (Head->word == word){
        	toDelete = Head ;
        	Head = currentWord->next ;
        	delete toDelete ;
        	return ;
		}
			 // Iterate through the linked list to find the word
		    while (currentWord && currentWord->next->word != word) {
		        currentWord = currentWord->next;
		    }
		    toDelete = currentWord->next ;
		    currentWord->next = currentWord->next->next ;
		      
        // Check if the first node is the one to be deleted
        cout << "Word '" << word << "' deleted successfully.\n";
        delete (toDelete);
    } else {
        cout << "You have cancelled Deletion" << "\n";
    }
}

void displayLinkedList (){
			SingleNode * currentNode = Head ;
//				if (!Head) {
//					cout << "No Words & Their Meanings Are There In Singly linkedlist"<<"\n";
//					return ;
//				}
			cout << "Word & their meanings in a single linked list" <<"\n" ;
			while (currentNode){
				cout << currentNode->word <<" : " <<currentNode->meaning << "\n\n" ;
				currentNode = currentNode->next ;
			}
		}
};

class Stack {
private:
    WordNode* top;
public:
    Stack() : top(nullptr) {}

    void push(string word, string meaning) {
        WordNode* newWord = new WordNode;
        newWord->word = word;
        newWord->meaning = meaning;

        if (!top) {
            top = newWord;
        } else {
            newWord->nextWord = top;
            top = newWord;
        }
    }

    void pop() {
        if (!isStackEmpty()) {
            WordNode* toDelete = top;
            top = top->nextWord;
            delete toDelete;
        } else {
            cout << "Stack is Empty" << "\n";
        }
    }

    WordNode* peek() {
        return top;
    }

    bool isStackEmpty() {
        return top == nullptr;
    }

    void displayStack(SingleNode & sl) {
    	
        WordNode* currentWord = top;
		if (!top) cout << "Stack is empty" <<"\n" ;
		else {
	        while (currentWord) {
	            cout << currentWord->word << ": " << currentWord->meaning << "\n";
	             sl.insertInSingleLinkedList(currentWord->word, currentWord->meaning);
	            currentWord = currentWord->nextWord;
	        }
	    }
	    while (!isStackEmpty()) {
            pop();
        }
}
};

// Class to represent the Dictionary
class Dictionary {
public:
    AlphabetNode* head; // Pointer to the head of the dictionary -> Will be null at start
    
    // Constructor to initialize the dictionary
    Dictionary() {
        head = nullptr;    
    }

    // Function to insert a word into the dictionary
    void insertWordInDictionary(string word, string meaning) {
        // Convert the word to lowercase for case using algorithm library
        transform(word.begin(),word.end(),word.begin(),::tolower); // Converting word to lower Case

        char firstChar = word[0] ;
        AlphabetNode* currentAlphabet = findCorrectAlphabet(firstChar); // Will find you the node to insert


        // If the alphabet node doesn't exist, create a new one
        if (!currentAlphabet) {
            currentAlphabet = createAlphabetNode(firstChar);
        }

        // Insert the word into the linked list of words
        insertWordIntoAlphabet(currentAlphabet, word, meaning);
    }

  

public:
    // Function to find an alphabet node with the given character
    AlphabetNode* findCorrectAlphabet(char alphabet) {
        AlphabetNode* currentAlphabet = head;

        while (currentAlphabet) {
            if (currentAlphabet->alphabet == alphabet) {
                return currentAlphabet;
            }
            currentAlphabet = currentAlphabet->nextAlphabet;
        }

        return nullptr;
    }

    // Function to create a new alphabet node with the given character
    AlphabetNode* createAlphabetNode(char alphabet) {
        AlphabetNode* newAlphabet = new AlphabetNode;
        newAlphabet->alphabet = alphabet;
        newAlphabet->nextWord = nullptr;
        newAlphabet->nextAlphabet = nullptr;

        // Insert the new alphabet node at the correct position
        insertAlphabetNode(newAlphabet);

        return newAlphabet;
    }

    // Function to insert an alphabet node into the linked list of alphabets
void insertAlphabetNode(AlphabetNode* newAlphabet) {
        if (!head || head->alphabet > newAlphabet->alphabet) {
            // Insert at the beginning of the list
            newAlphabet->nextAlphabet = head;
            head = newAlphabet;
        } else {
            AlphabetNode* currentAlphabet = head;

            while (currentAlphabet->nextAlphabet && currentAlphabet->nextAlphabet->alphabet < newAlphabet->alphabet) {
                currentAlphabet = currentAlphabet->nextAlphabet;
            }

            // Insert at the end of the list
            newAlphabet->nextAlphabet = currentAlphabet->nextAlphabet;
            currentAlphabet->nextAlphabet = newAlphabet;
        }
    }

    // Function to insert a word node into the linked list of words for a given alphabet
   
void insertWordIntoAlphabet(AlphabetNode* currentAlphabet, string word, string meaning) {
    // Checking if  word already in the dictionary
    bool wordHe = false;  // Flag
    WordNode* heWord = nullptr;
    
    WordNode * current = currentAlphabet->nextWord ;

    while (current) { // Will out , When get nullptr.
      
	    if (current->word == word) {
            // Word already exists
            wordHe = true;
            heWord = current;
            break;
        }
	    current = current->nextWord;
    }

    if (wordHe) {
        cout << "Word already exists in the dictionary :\n";
        cout << heWord->word << ": " << heWord->meaning << "\n";
        cout << "Do you want to add this word again in dictionary? (yes/no): ";

        char pick;
        cin >> pick;

        if (pick == 'n' || pick == 'N') {
            cout << "Word'nt added.\n";
            return;    // Will return from this method.
        }else  cout << "Word added successfully.\n";
    }

    // Continue with the logic to insert the word with the repective alphabet.

    WordNode* newWord = new WordNode;
    newWord->word = word;
    newWord->meaning = meaning;
    newWord->nextWord = nullptr;

    if (!currentAlphabet->nextWord || currentAlphabet->nextWord->word > word) {
        // Insert at the beginning of the list
        newWord->nextWord = currentAlphabet->nextWord;
        currentAlphabet->nextWord = newWord;
    } else {
        WordNode* currentWord = currentAlphabet->nextWord;

        // Insert at the end of the list or at the correct position
        while (currentWord->nextWord && currentWord->nextWord->word < word) {
            currentWord = currentWord->nextWord;
        }

        // Insert at the correct position
        newWord->nextWord = currentWord->nextWord;
        currentWord->nextWord = newWord;
    }   
}

  // Function to display the entire dictionary
void displayDictionary(Stack & st) {
   	
    AlphabetNode* currentAlphabet = head;
	cout <<"\n\n" ;
    while (currentAlphabet) {
        cout << "Words starting with '" << currentAlphabet->alphabet << "':\n";

        WordNode* currentWord = currentAlphabet->nextWord ;
		
        while (currentWord) {
            cout << currentWord->word << ": " << currentWord->meaning << "\n";

            // Add a call to push the word and meaning onto the stack
            st.push(currentWord->word, currentWord->meaning);
           

            currentWord = currentWord->nextWord;
        }

        cout << "\n";
        currentAlphabet = currentAlphabet->nextAlphabet;
    }
}

void searchForWord(string key) {
	transform(key.begin(),key.end(),key.begin(),::tolower); // Convert word to lowercase

    char firstChar = key[0] ;

    AlphabetNode* currentAlphabet = findCorrectAlphabet(firstChar) ;
    
    WordNode * currentWord = currentAlphabet->nextWord ;
    
   if (!currentAlphabet) {
        cout << "The word with the first alphabet isn't in the Dictionary" << "\n" ;
        return;
    }
    
    while (currentWord) {	
            if (currentWord->word == key) {
                cout << "The Word is in the dictionary: " << key << "\n";
                return;
            }
            if (!currentWord->nextWord) {  // If last word is in list or not.
                if (currentWord->word == key) {
                    cout << "The Word is in the dictionary: " << key << "\n";
                    return;
                }
            }
            currentWord = currentWord->nextWord ;
        }
        cout << "Word : " <<currentWord->word<<" is'nt in the dictionary."<<"\n" ;
}

void deletionInWord(string word) {
    
	transform(word.begin(),word.end(),word.begin(),::tolower); // Convert word to lowercase

    char firstChar = word[0];

    AlphabetNode* currentAlphabet = findCorrectAlphabet(firstChar) ;

    if (!currentAlphabet) {
        cout << "The word with the first alphabet isn't in the Dictionary" << "\n" ;
        return;
    }
    if(!currentAlphabet->nextWord) {
    	cout << "Word not found in the Dictionary: " << word << "\n";
    	return ;
	}

    WordNode* currentWord = currentAlphabet->nextWord;
    WordNode* prevPosition = nullptr;

    // Using previous to get n-1 node -> to delete the n node
    while (currentWord && currentWord->word != word) {
        prevPosition = currentWord;
        currentWord = currentWord->nextWord;
    }
    
// If word == noAddress -> Not exist

    if (currentWord==nullptr) { 
        cout << "Word not found in the Dictionary: " << word << "\n";
        return;
    }

    // Displaying warning 
    cout << "Are you sure you want to delete the word | " << word << " | from Dictionary? (yes/no): ";
    char pick;
    cin >> pick;

    if (pick == 'y' || pick == 'Y') {

// This validation is for , when you have only one word for the respective Alphabet.        
       
	    if (prevPosition == nullptr)   currentAlphabet->nextWord = currentWord->nextWord;
       
	    else prevPosition->nextWord = currentWord->nextWord;
        

        cout << "Word '" << word << "' deleted successfully.\n";
        
		delete (currentWord);
    } 
	
	else cout << "You Don't want to delete, Right!'\n";  
}

void displayThroughRecursion (AlphabetNode * currentAlphabet){
	
	if (!currentAlphabet) {
		return ;
	}
	
// Recursive Call's
	displayThroughRecursion(currentAlphabet->nextAlphabet) ;
	
		cout << "Alphabet is : '" <<currentAlphabet->alphabet<< "'" <<"\n" ;
	
	WordNode * currentWord = currentAlphabet->nextWord ;
	
	while (currentWord){
			cout << currentWord->word <<" : "<<currentWord->meaning << "\n" ;
			currentWord = currentWord->nextWord ;
	}
}


void searchTimeDictionary(string word) {
    AlphabetNode* currentAlphabet = head;
    double totalJumps = 0; 
    double wordCount = 0 ;   

    while (currentAlphabet) {
        
		WordNode* currentWord = currentAlphabet->nextWord;
        
	    while (currentWord && currentWord->word != word) {
                currentWord = currentWord->nextWord;
                wordCount++ ;
                totalJumps++;
        }
        currentAlphabet = currentAlphabet->nextAlphabet;
    }

    double averageSearchTime = (totalJumps) / wordCount;

    cout<<"Average Search Time (Digital Dictionary): "<<averageSearchTime<<endl;
}

};

int main() {
    // Initialize your data structures and objects
    Dictionary dictionary;
    SingleNode sl;
    Stack st;

    int choice;

    do {
        // Display Menu
        cout << setw(40) << "-> Digital-Dictionary <-" << endl;
        
        stars() ;
        cout << "1 . Insert Word & It's Meaning in the Dictionary" << endl;
        cout << "2 . Search for Word in the Dictionary" << endl;
        cout << "3 . Delete Word from Dictionary" << endl;
        cout << "4 . Display Whole Dictionary In Alphabetical Order" << endl;
        cout << "5 . Display All Words & Their Meanings Push At Stack" << endl;
        cout << "6 . Display Words & Thier Meanings Through Recursion" << endl<<endl;
        stars();
        cout<<"--------------------Question 2---------------------"<<endl;
        cout << "7 . Insert Words & Thier Meanings in Single Linked List"  << endl;
        cout << "8 . Search Words & Thier Meanings in Single Linked List" << endl;
        cout << "9 . Delete Words & Thier Meanings in Single Linked List" << endl;
        cout << "10. show   Words & Thier Meanings in Single Linked List" << endl;
        cout << "11. Search Time in Single Linked List" << endl;
        cout << "12. Search Time in Digital Dictionary" << endl;
        cout << "13. Exit" << endl;
        stars();
        cout << "Enter your choice: ";
        cin >> choice;
        
		cout<<"\n\n";
        // Perform operations based on user choice
        switch (choice) {
            case 1: {
                string word, meaning;
                cout << "Input word: ";
                cin >> word;
                cout << "Input meaning: ";
                cin.ignore();  
                getline(cin, meaning);
                dictionary.insertWordInDictionary(word, meaning);
                break;
            }
            case 2: {
                string word;
                cout << "Input word to search: ";
                cin >> word;
                dictionary.searchForWord(word);
                break;
            }
            case 3: {
                string word;
                cout << "Input word to delete: ";
                cin >> word;
                dictionary.deletionInWord(word);
                break;
            }
            case 4: {
                cout << "Displaying Dictionary In Alphabetical Order :" << endl;
                dictionary.displayDictionary(st);
                cin.ignore();  
                break;
            }
            case 5: {
            	cout << "Displaying Words & Their Meanings Push At Stack" << endl;
                st.displayStack(sl);
                cin.ignore();
                break;
            }
            case 6: {
            	cout << "Displaying Words & Thier Meanings Through Recursion" << endl;
                dictionary.displayThroughRecursion(dictionary.head);
                break;
            }
            case 7: {
                string word, meaning;
                cout << "Input word: " ;
                cin >> word ;
                cout << "Input meaning: " ;
                cin.ignore() ;  
                getline(cin, meaning) ;
                sl.insertInSingleLinkedList(word, meaning);
             
                break ;
            }
            case 8: {
                string word;
                cout << "Input word to search: ";
                cin >> word;
                sl.searchInLinkedList(word); 
                break;
            }
            case 9: {
                string word;
                cout << "Input word to delete: ";
                cin >> word;
                sl.deletionInlinkedList(word) ;
                
                break;
            }
            case 10: {
                cout << "Displaying Words & Thier Meanings in Singly LinkedList" << endl;
                sl.displayLinkedList();
                
                break;
            }
             case 11: {
                cout << "Search Time In Singly LinkedList" << endl;
                string word;
                cout << "Input word for search time: ";
                cin >> word;
               dictionary.searchTimeDictionary(word) ;
                
                break;
            }
             case 12: {
                cout << "Search Time In Digital Dictionary" << endl;
                string word;
                cout << "Input word for search time: ";
                cin >> word;
                sl.searchTimeSinglyLL(word);
                
                break;
            }
            case 13: {
                cout << "Exit" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 11);
    	return 0 ;
}