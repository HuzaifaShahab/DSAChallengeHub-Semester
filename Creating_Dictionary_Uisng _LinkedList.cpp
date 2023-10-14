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
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Change to lower Case

        char firstChar = word[0];
        AlphabetNode* currentAlphabet = findAlphabetNode(firstChar); // Will find you the node to insert


        // If the alphabet node doesn't exist, create a new one
        if (!currentAlphabet) {
            currentAlphabet = createAlphabetNode(firstChar);
        }

        // Insert the word into the linked list of words
        insertWordIntoAlphabet(currentAlphabet, word, meaning);
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

private:
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
    bool wordHe = false;
    WordNode* heWord = nullptr;

    while (currentAlphabet->nextWord) { // Will out , When get nullptr.
      
	    if (currentAlphabet->nextWord->word == word) {
            // Word already exists
            wordHe = true;
            heWord = currentAlphabet->nextWord;
            break;
        }
      
	    currentAlphabet = currentAlphabet->nextWord;
    }

    if (wordHe) {
        cout << "Word already exists in the dictionary :\n";
        cout << heWord->word << ": " << heWord->meaning << "\n";
        cout << "Do you want to add this word again in dictionary? (y/n): ";

        char choice;
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Word'nt added.\n";
            return;
        }
    }

    // Continue with the original logic to insert the word

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

    cout << "Word added successfully.\n";
}
};

int main() {
    // Create a dictionary
    Dictionary dictionary;

   
    // Insert some sample data

    dictionary.insertWord("Zebra","Ye chuttu he") ;
     dictionary.insertWord("apple", "Ye Muje pxnd nhi");
    dictionary.insertWord("age","19.5 he");
    dictionary.insertWord("banana", "hamza khan kela");
    dictionary.insertWord("cat", "aksa..r");
    dictionary.insertWord("dog", "barking");
    dictionary.insertWord("Huzaifa","Name of a person") ;

    // Display the dictionary
    dictionary.displayDictionary();

    return 0;
}