#include "Book.h"
#include <sstream>

Book::Book() {
    bookId = 0;
    title = "";
    author = "";
    isAvailable = true;
}

Book::Book(int id, std::string t, std::string a, bool available) {
    bookId = id;
    title = t;
    author = a;
    isAvailable = available;
}

int Book::getBookId() const {
    return bookId;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

std::string Book::serialize() const {
    return std::to_string(bookId) + "|" +
           title + "|" +
           author + "|" +
           std::to_string(isAvailable);
}

Book Book::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string token;

    int id;
    std::string title;
    std::string author;
    bool available;

    getline(ss, token, '|');
    id = stoi(token);

    getline(ss, title, '|');
    getline(ss, author, '|');

    getline(ss, token, '|');
    available = stoi(token);

    return Book(id, title, author, available);
}