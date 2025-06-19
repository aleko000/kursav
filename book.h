#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    Book() : m_year(0) {}
    Book(int year, const std::string& author, const std::string& title) : m_year(0) {
        set(year, author, title);
    }
    void set(int year, const std::string& author, const std::string& title);
    int getYear() const { return m_year; }
    std::string getAuthor() const { return m_author; }
    std::string getTitle() const { return m_title; }
    bool operator == (const Book& op);
    friend std::ostream& operator << (std::ostream& os, const Book& b);
    friend std::istream& operator >> (std::istream& is, Book& b);
private:
    int m_year;
    std::string m_author, m_title;
};

void inputBook(Book& b);

#endif
