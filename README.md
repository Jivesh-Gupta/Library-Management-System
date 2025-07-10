# 📚 Library Management System in C++

A console-based project developed in **C++** to manage a library system using **linked lists** and **file handling** for data persistence. This project supports adding, displaying, and searching books, with data saved to a file.

---

## ✅ Features

- Add new books with ID, title, and author
- Display all available books
- Search for a book by title
- Delete existing book by title
- Save book records to file (`library.txt`)
- Load existing records on startup

---

## 🧠 Technologies Used

- C++ (with structs and pointers)
- Standard Template Library (STL)
- File handling with `fstream`
- Linked List for in-memory data
- Console input/output

---

## 🔍 Project Structure

```cpp
struct Book {
    int id;
    string title;
    string author;
    Book* next;
};
