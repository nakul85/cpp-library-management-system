#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook();
    void displayBooks();
    void searchBook();

    void registerUser();
    void displayUsers();

    void borrowBook();
    void returnBook();

    void saveBooks();
    void loadBooks();

    void saveUsers();
    void loadUsers();
};

#endif