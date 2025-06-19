#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Library {
public:
    typedef std::vector<Book> Bookcase;

    Library() {}
    void append(const Book& book);
    bool remove(const Book& book);
    Bookcase::iterator findByTitle(const std::string& title, Bookcase::iterator from);
    Bookcase::iterator findByAuthor(const std::string& author, Bookcase::iterator from);
    Bookcase::iterator findByYear(int year, Bookcase::iterator from);
    Bookcase::iterator nextBook(Bookcase::iterator from);
    Bookcase::iterator begin() { return m_bc.begin(); }
    Bookcase::iterator end() { return m_bc.end(); }
    size_t getBookCount() const { return m_bc.size(); }

    bool saveToFile(const std::string& filename);
    bool loadFromFile(const std::string& filename);
protected:
    Bookcase m_bc;
};

class ExtendedLibrary : public Library {
public:
    void sortByAuthor();
    void sortByYear();
    Bookcase::iterator findByPartialTitle(const std::string& partialTitle, Bookcase::iterator from);
};

#endif
