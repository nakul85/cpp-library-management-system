#include "Library.h"
#include <iostream>
#include <fstream>

using namespace std;

void Library::addBook() {
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "\nBook added successfully!\n";
}

void Library::displayBooks() {
    if (books.empty()) {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n===== BOOK LIST =====\n";

    for (const auto& book : books) {
        cout << "ID: " << book.getBookId()
             << "\nTitle: " << book.getTitle()
             << "\nAuthor: " << book.getAuthor()
             << "\nStatus: "
             << (book.getAvailability() ? "Available" : "Borrowed")
             << "\n----------------------\n";
    }
}

void Library::searchBook() {
    string title;

    cin.ignore();
    cout << "\nEnter book title to search: ";
    getline(cin, title);

    for (const auto& book : books) {
        if (book.getTitle() == title) {
            cout << "\nBook Found!\n";
            cout << "ID: " << book.getBookId() << endl;
            cout << "Author: " << book.getAuthor() << endl;
            cout << "Status: "
                 << (book.getAvailability() ? "Available" : "Borrowed")
                 << endl;
            return;
        }
    }

    cout << "\nBook not found.\n";
}

void Library::registerUser() {
    int id;
    string name;

    cout << "\nEnter User ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter User Name: ";
    getline(cin, name);

    users.push_back(User(id, name));

    cout << "\nUser registered successfully!\n";
}

void Library::displayUsers() {
    if (users.empty()) {
        cout << "\nNo users registered.\n";
        return;
    }

    cout << "\n===== USER LIST =====\n";

    for (const auto& user : users) {
        cout << "ID: " << user.getUserId()
             << "\nName: " << user.getName()
             << "\nBorrowed Books: ";

        vector<int> borrowed = user.getBorrowedBooks();

        if (borrowed.empty()) {
            cout << "None";
        } else {
            for (int id : borrowed) {
                cout << id << " ";
            }
        }

        cout << "\n----------------------\n";
    }
}

void Library::borrowBook() {
    int userId, bookId;

    cout << "\nEnter User ID: ";
    cin >> userId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    User* foundUser = nullptr;
    Book* foundBook = nullptr;

    for (auto& user : users) {
        if (user.getUserId() == userId) {
            foundUser = &user;
            break;
        }
    }

    for (auto& book : books) {
        if (book.getBookId() == bookId) {
            foundBook = &book;
            break;
        }
    }

    if (foundUser && foundBook && foundBook->getAvailability()) {
        foundUser->borrowBook(bookId);
        foundBook->setAvailability(false);

        cout << "\nBook borrowed successfully!\n";
    } else {
        cout << "\nBorrow operation failed.\n";
    }
}

void Library::returnBook() {
    int userId, bookId;

    cout << "\nEnter User ID: ";
    cin >> userId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    User* foundUser = nullptr;
    Book* foundBook = nullptr;

    for (auto& user : users) {
        if (user.getUserId() == userId) {
            foundUser = &user;
            break;
        }
    }

    for (auto& book : books) {
        if (book.getBookId() == bookId) {
            foundBook = &book;
            break;
        }
    }

    if (foundUser && foundBook) {
        foundUser->returnBook(bookId);
        foundBook->setAvailability(true);

        cout << "\nBook returned successfully!\n";
    } else {
        cout << "\nReturn operation failed.\n";
    }
}

void Library::saveBooks() {
    ofstream file("books.txt");

    for (const auto& book : books) {
        file << book.serialize() << endl;
    }

    file.close();
}

void Library::loadBooks() {
    ifstream file("books.txt");

    string line;

    while (getline(file, line)) {
        books.push_back(Book::deserialize(line));
    }

    file.close();
}

void Library::saveUsers() {
    ofstream file("users.txt");

    for (const auto& user : users) {
        file << user.serialize() << endl;
    }

    file.close();
}

void Library::loadUsers() {
    ifstream file("users.txt");

    string line;

    while (getline(file, line)) {
        users.push_back(User::deserialize(line));
    }

    file.close();
}