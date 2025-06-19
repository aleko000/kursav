#include "book.h"
#include <iostream>

void Book::set(int year, const std::string& author, const std::string& title) {
    m_year = year;
    m_author = author;
    m_title = title;
}

bool Book::operator == (const Book& op) {
    return m_year == op.m_year &&
        m_author == op.m_author &&
        m_title == op.m_title;
}

std::ostream& operator << (std::ostream& os, const Book& b) {
    return os
        << b.m_author << std::endl
        << b.m_title << std::endl
        << b.m_year << std::endl;
}

std::istream& operator >> (std::istream& is, Book& b) {
    std::string au, ti;
    int yr;
    getline(is, au);
    getline(is, ti);
    is >> yr;
    is.ignore();
    b.set(yr, au, ti);
    return is;
}

void inputBook(Book& b) {
    std::string au, ti;
    int yr;
    std::cout << "Ввод данных о книге\n" << "~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Автор      : ";
    getline(std::cin, au);
    std::cout << "Название   : ";
    getline(std::cin, ti);
    std::cout << "Год издания: ";
    std::cin >> yr;
    std::cin.ignore();
    b.set(yr, au, ti);
}
