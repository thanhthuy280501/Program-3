#include <cstring>
// Name:         Thuy Nguyen
// Program:      CSC 275 Program 3
// Due Date:     11/09/24
// Compiler:     Code Block
// This is the main program file, which provides the user interface and integrates the Book and Member classes.

class Book {
private:
    char* title;
    char* author;
    char* isbn;
    char* publisher;

public:
    // Constructor
    Book(const std::string& t, const std::string& a, const std::string& i, const std::string& p) {
        title = new char[t.length() + 1];
        strcpy(title, t.c_str());

        author = new char[a.length() + 1];
        strcpy(author, a.c_str());

        isbn = new char[i.length() + 1];
        strcpy(isbn, i.c_str());

        publisher = new char[p.length() + 1];
        strcpy(publisher, p.c_str());
    }

    // Copy Constructor
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        isbn = new char[strlen(other.isbn) + 1];
        strcpy(isbn, other.isbn);

        publisher = new char[strlen(other.publisher) + 1];
        strcpy(publisher, other.publisher);
    }

    // Assignment Operator
    Book& operator=(const Book& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }

        // Clean up existing data
        delete[] title;
        delete[] author;
        delete[] isbn;
        delete[] publisher;

        // Allocate and copy new data
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        isbn = new char[strlen(other.isbn) + 1];
        strcpy(isbn, other.isbn);

        publisher = new char[strlen(other.publisher) + 1];
        strcpy(publisher, other.publisher);

        return *this;
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] isbn;
        delete[] publisher;
    }

    // Other member functions...
};

