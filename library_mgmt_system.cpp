#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

Book* head = nullptr;

// Function to add a book to the linked list
void addBook(int id, string title, string author) {
    Book* newBook = new Book{id, title, author, nullptr};
    if (!head) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newBook;
    }
    cout << "Book added successfully.\n";
}

// Function to display all books
void displayBooks() {
    Book* temp = head;
    if (!temp) {
        cout << "No books available.\n";
        return;
    }
    cout << "Book List:\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << endl;
        temp = temp->next;
    }
}

// Function to search for a book by title
void searchBook(string title) {
    Book* temp = head;
    while (temp) {
        if (temp->title == title) {
            cout << "Book found - ID: " << temp->id << ", Author: " << temp->author << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Book not found.\n";
}

// Function to save books to a file
void saveToFile() {
    ofstream out("library.txt");
    Book* temp = head;
    while (temp) {
        out << temp->id << "," << temp->title << "," << temp->author << endl;
        temp = temp->next;
    }
    out.close();
    cout << "Books saved to file.\n";
}

// Function to load books from a file
void loadFromFile() {
    ifstream in("library.txt");
    if (!in) {
        cout << "File not found.\n";
        return;
    }
    int id;
    string title, author, line;
    while (getline(in, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.rfind(",");
        id = stoi(line.substr(0, pos1));
        title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        author = line.substr(pos2 + 1);
        addBook(id, title, author);
    }
    in.close();
    cout << "Books loaded from file.\n";
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n1. Add Book\n2. Display Books\n3. Search Book\n4. Save & Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: "; cin >> id; cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Author: "; getline(cin, author);
            addBook(id, title, author);
        } else if (choice == 2) {
            displayBooks();
        } else if (choice == 3) {
            string title;
            cout << "Enter Title to Search: "; getline(cin, title);
            searchBook(title);
        } else if (choice == 4) {
            saveToFile();
        }
    } while (choice != 4);

    return 0;
}
