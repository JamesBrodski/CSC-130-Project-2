// Class: CSC 130-01
// Assignment: Radix Sort
// Author: James Brodski
// Date: 11/01/22

// The number of files that will be sorted
#define numfiles 5

// Allows programmer to print to the screen
#include <iostream>

// Allows the programmer to work with files
#include <fstream>

// Allows programmer to store files in strings
#include <sstream>

// Look here if unidentified objects are found
using namespace std;

class Entry {
    public:
        string key;
        string value;
};

// The functions responsible for the individual node of a linked list
class Node {

    public:

        // Stores the location of the next node as well as its value
        Node* next = 0;
        Entry entry;

        // Constructor that initializes value
        Node(string x, string y) {

            entry.key = x;
            entry.value = y;

        }

        // Returns 1 if linked list has a particular value and 0 otherwise
        bool Contains (string x) {

            // If the current node doesn't have the value, traverse the next node
            if (entry.key != x && next) return next->Contains(x);

            // Otherwise, return true
            if (entry.key == x) return true;

            // If it has completely traversed the linked list and not found the value
            return false;

        }

        // Prints the entire linked list from this node on
        void Print () {

            // Before we traverse further, print the value at current node
            cout << entry.key << ", ";

            // If there is no node after this, terminate the function
            if (!next) return;

            // Start printing the value at next node
            next->Print();

        }

};

class LinkedList {

    private:

        // Keeps track of the location of the head and tail
        Node *head = 0, *tail = 0;

    public:

        // Returns the author of the program
        string About() {

            return "James Brodski\n\n";

        }

        // Appends a node to the start of a linked list
        void AddHead(string a, string b) {
            
            // Temporarily create a pointer to help faciliate the addition of a new node
            Node* x = new Node(a, b);
            x->next = head;

            // First node inserted into the linked list will become tail as well
            if (!head) tail = x;
            
            head = x;

        }

        // Appends a node to the end of a linked list
        void AddTail(string a, string b) {

            // If the head does not exist yet, call the head function first
            if (!head) {
                
                AddHead(a, b);

            // If the head does exist,
            } else {

                // Temporarily create a pointer to help faciliate the addition of a new node
                Node* x = new Node(a, b);
                tail->next = x, tail = x;

            }

        }

        // Remove the head of a linked list
        string RemoveHead() {

            // Linked list is empty
            if (!head) return "";

            // store value of head because we will lose it once we do head=head->next
            Node* temp = head;

            // New head node is the next one
            head=head->next;

            // Linked list is not empty
            return temp->entry.key;

        }

        // Returns the value at the head
        string PeekHead() {

            // If it exists, return it
            if (head)
                return head->entry.key;

            // Otherwise, return empty string
            return "";

        }

        // return the status of the head which implies if it is empty
        bool IsEmpty () {

            return head;

        }

        bool Contains(string x) {

            // If the current node doesn't have the value, traverse the next node
            if (head->entry.key != x && head->next) return head->next->Contains(x);

            // Otherwise, return true
            if (head->entry.key == x) return true;

            // If it has completely traversed the linked list and not found the value
            return false;

        }

        // Responsible for printing the entire linked list
        void Print() {

            // If the linked list is empty, terminate the function
            if (!head) {
                cout << "The linked list is currently empty!\n";
                cout << "Try adding more nodes using the .AddHead() function\n\n";
                return;
            }
            
            // Before we traverse further, print the value at current node
            cout << head->entry.key << ", ";

            // If there is no node after this, terminate the function
            if (!head->next) return;

            // Start printing the value at next node
            head->next->Print();

        }

};

// Where the program begins
int main() {

    // Contains all filenames that will be used
    string filename[numfiles] = {"years.txt"/*, "pokemon.txt", "stooges.txt", "areacode.txt", "zipcodes.txt"*/};

    // Stores all of the text in all of the files
    string data[numfiles];
    
    // Store each file into the data array
    for (int i = 0; i < numfiles; i++) {

        // Open the file,
        ifstream file (filename[i]);

        // Grab the contents of the file and store in the array
        stringstream y;
        y << file.rdbuf();
        data[i] = y.str();
        
        // Close the file,
        file.close();
    }

    // Begin sorting the first text file
    LinkedList bucket[10];

    // The number of passes that will have to be done
    int k = stoi(data[0]);
    for (string d : data) {
        string s = data[0].substr(k-1, k);
    }
    
}