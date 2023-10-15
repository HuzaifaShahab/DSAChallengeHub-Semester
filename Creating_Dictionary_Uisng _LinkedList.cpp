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

// Class to represent the dictionary
class Dictionary {
private:
    AlphabetNode* head; // Pointer to the head of the dictionary

public:
    // Constructor to initialize the dictionary
    Dictionary() {
        head = nullptr;
        
    }

    // Function to insert a word into the dictionary
    void insertWord(string word, string meaning) {
        // Convert the word to lowercase for case-insensitive comparison
        transform(word.begin(),word.end(),word.begin(),::tolower); //Converting word to lower Case

        char firstChar = word[0] ;
        AlphabetNode* currentAlphabet = findAlphabetNode(firstChar); //Will find you the node to insert


        // If the alphabet node doesn't exist, create a new one
        if (!currentAlphabet) {
            currentAlphabet = createAlphabetNode(firstChar);
        }

        // Insert the word into the linked list of words
        insertWordIntoAlphabet(currentAlphabet, word, meaning);
    }

  

public:
    // Function to find an alphabet node with the given character
    AlphabetNode* findAlphabetNode(char alphabet) {
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
    void displayDictionary() {
        AlphabetNode* currentAlphabet = head;

        while (currentAlphabet) {
            cout << "Words starting with '" << currentAlphabet->alphabet << "':\n";

            WordNode* currentWord = currentAlphabet->nextWord;

            while (currentWord) {
                cout << currentWord->word << ": " << currentWord->meaning << "\n";
                currentWord = currentWord->nextWord;
            }

            cout << "\n";
            currentAlphabet = currentAlphabet->nextAlphabet;
        }
    }

void searchForWord(string key) {
	transform(key.begin(),key.end(),key.begin(),::tolower); // Convert word to lowercase

    char firstChar = key[0] ;

    AlphabetNode* currentAlphabet = findAlphabetNode(firstChar) ;
    
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

    AlphabetNode* currentAlphabet = findAlphabetNode(firstChar) ;

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

};

int main() {
    // Create a dictionary
    Dictionary dictionary;

    
    dictionary.insertWord("Zebra","Ye chuttu he") ;
    dictionary.insertWord("Zebra","Ye chuttu he") ;
    dictionary.insertWord("age","19.5 he");
    dictionary.insertWord("banana", "hamza khan kela");
    dictionary.insertWord("cat", "aksa..r");
    dictionary.insertWord("dog", "barking");
    dictionary.insertWord("apple", "Ye Muje pxnd nhi");
    dictionary.insertWord("age", "Ye Muje pxnd nhi");
	dictionary.insertWord("ace", "Ye Muje pxnd nhi");    
	dictionary.searchForWord("apple") ;
	dictionary.deletionInWord("apple") ;
    // Display the dictionary
    dictionary.displayDictionary();

    return 0;
}