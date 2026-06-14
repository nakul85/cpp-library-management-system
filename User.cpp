#include "User.h"
#include <sstream>
#include <algorithm>

User::User() {
    userId = 0;
    name = "";
}

User::User(int id, std::string n) {
    userId = id;
    name = n;
}

int User::getUserId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}

std::vector<int> User::getBorrowedBooks() const {
    return borrowedBooks;
}

void User::borrowBook(int bookId) {
    borrowedBooks.push_back(bookId);
}

void User::returnBook(int bookId) {
    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookId),
        borrowedBooks.end()
    );
}

std::string User::serialize() const {
    std::string result = std::to_string(userId) + "|" + name + "|";

    for (size_t i = 0; i < borrowedBooks.size(); i++) {
        result += std::to_string(borrowedBooks[i]);

        if (i != borrowedBooks.size() - 1) {
            result += ",";
        }
    }

    return result;
}

User User::deserialize(const std::string& data) {
    std::stringstream ss(data);

    std::string token;

    getline(ss, token, '|');
    int id = stoi(token);

    getline(ss, token, '|');
    std::string name = token;

    User user(id, name);

    getline(ss, token);

    std::stringstream books(token);

    while (getline(books, token, ',')) {
        if (!token.empty()) {
            user.borrowBook(stoi(token));
        }
    }

    return user;
}