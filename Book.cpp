#include <iostream>
#include <fstream>
#include <string>
#include "Book.h" // Include your Book class header

// Function to read books from a file
void readBooksFromFile(const std::string& filename, Book*& books, int& bookCount) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    inFile >> bookCount; // Assuming the first line contains the number of books
    inFile.ignore(); // Ignore the newline after the number

    books = new Book[bookCount]; // Dynamically allocate memory

    for (int i = 0; i < bookCount; ++i) {
        std::string title, author, isbn, publisher;
        std::getline(inFile, title);
        std::getline(inFile, author);
        std::getline(inFile, isbn);
        std::getline(inFile, publisher);
        books[i] = Book(title, author, isbn, publisher);
    }

    inFile.close();
}

// Function to write books to a file
void writeBooksToFile(const std::string& filename, Book* books, int bookCount) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < bookCount; ++i) {
        outFile << books[i].getTitle() << '\n'
                << books[i].getAuthor() << '\n'
                << books[i].getISBN() << '\n'
                << books[i].getPublisher() << '\n';
    }

    outFile.close();
}

