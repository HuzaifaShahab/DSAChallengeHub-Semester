#include <iostream>
#include <cstring>
#include <algorithm>  // Added for transform

using namespace std;

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
			cout << "Word & their meanings in a single linked list" <<"\n" ;
			SingleNode * currentNode = Head ;
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
	             sl.insertInSingleLinkedList(currentWord->word, currentWord->meaning) ;
	            currentWord = currentWord->nextWord;
	        }
	    }
}
};


// Class to represent the dictionary
class Dictionary {
public:
    AlphabetNode* head; // Pointer to the head of the dictionary - > Will be null at start
    
    // Constructor to initialize the dictionary
    Dictionary() {
        head = nullptr;    
    }

    // Function to insert a word into the dictionary
    void insertWordInDictionary(string word, string meaning) {
        // Convert the word to lowercase for case using algorithm library
        transform(word.begin(),word.end(),word.begin(),::tolower); //Converting word to lower Case

        char firstChar = word[0] ;
        AlphabetNode* currentAlphabet = findCorrectAlphabet(firstChar); //Will find you the node to insert


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

};

int main() {
    // Create a dictionary
    Dictionary dictionary;
    SingleNode sl ;
	Stack st ;
    
    dictionary.insertWordInDictionary("banana", "hamza khan kela");
    dictionary.insertWordInDictionary("cat", "aksa..r");
    dictionary.insertWordInDictionary("dog", "barking");
    dictionary.insertWordInDictionary("apple", "Ye Muje pxnd nhi");
    dictionary.insertWordInDictionary("age", "Ye Muje pxnd nhi");
	dictionary.insertWordInDictionary("ace", "Ye Muje pxnd nhi");  
	sl.deletionInlinkedList("dog") ;  
	dictionary.searchForWord("apple") ;
	dictionary.deletionInWord("apple") ;
	sl.searchInLinkedList("word") ;
    // Display the dictionary
    dictionary.displayDictionary(st) ;
    cout <<"\n\n" ;
    cout << "Displaying Elements At Stack" <<"\n" ;
    st.displayStack(sl) ;
    cout << "Words in single linked list" << endl ;
    sl.displayLinkedList() ;
    
    cout << "------------------------------" << endl;
    dictionary.displayThroughRecursion(dictionary.head) ;

return 1;
}