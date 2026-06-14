#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    int userId;
    std::string name;
    std::vector<int> borrowedBooks;

public:
    User();
    User(int id, std::string n);

    int getUserId() const;
    std::string getName() const;
    std::vector<int> getBorrowedBooks() const;

    void borrowBook(int bookId);
    void returnBook(int bookId);

    std::string serialize() const;
    static User deserialize(const std::string& data);
};

#endif