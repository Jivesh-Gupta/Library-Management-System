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

void addBook(int id, string title, string author) {
    Book* newBook = new Book{id, title, author, nullptr};
    if (!head) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newBook;
    }
    cout << "Book added successfully!\n";
}

void displayBooks() {
    Book* temp = head;
    cout << "\n--- Book List ---\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << endl;
        temp = temp->next;
    }
}

void searchBook(string query) {
    Book* temp = head;
    bool found = false;
    while (temp) {
        if (temp->title == query) {
            cout << "\nBook Found:\nID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) cout << "\nBook not found.\n";
}

void deleteBook(string query) {
    Book* temp = head;
    Book* prev = nullptr;
    while (temp) {
        if (temp->title == query) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
            cout << "\nBook deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\nBook not found to delete.\n";
}

void saveToFile() {
    ofstream file("library.txt");
    Book* temp = head;
    while (temp) {
        file << temp->id << "," << temp->title << "," << temp->author << endl;
        temp = temp->next;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("library.txt");
    string line, title, author;
    int id;
    while (getline(file, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.rfind(',');
        id = stoi(line.substr(0, p1));
        title = line.substr(p1 + 1, p2 - p1 - 1);
        author = line.substr(p2 + 1);
        addBook(id, title, author);
    }
    file.close();
}

int main() {
    loadFromFile();
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Save & Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            addBook(id, title, author);
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            cout << "Enter title to search: ";
            getline(cin, title);
            searchBook(title);
            break;
        case 4:
            cout << "Enter title to delete: ";
            getline(cin, title);
            deleteBook(title);
            break;
        case 5:
            saveToFile();
            cout << "Data saved. Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
