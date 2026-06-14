#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    bool isAvailable;

public:
    Book();
    Book(int id, std::string t, std::string a, bool available = true);

    int getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getAvailability() const;

    void setAvailability(bool available);

    std::string serialize() const;
    static Book deserialize(const std::string& data);
};

#endif