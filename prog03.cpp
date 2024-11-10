#include <iostream>
#include "Book.h"
#include "Member.h"

// Include or implement the I/O functions here or include a header file with these functions

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " libraryIn.txt libraryOut.txt memberIn.txt memberOut.txt" << std::endl;
        return 1;
    }

    // Command-line arguments for file names
    std::string libraryInFile = argv[1];
    std::string libraryOutFile = argv[2];
    std::string memberInFile = argv[3];
    std::string memberOutFile = argv[4];

    // Dynamic arrays for Books and Members
    Book* library = nullptr;
    Member* members = nullptr;
    int bookCount = 0, memberCount = 0;

    // Load data from files
    readBooksFromFile(libraryInFile, library, bookCount);
    readMembersFromFile(memberInFile, members, memberCount);

    // Program logic (commands and interactions)

    // Save data to files before exiting
    writeBooksToFile(libraryOutFile, library, bookCount);
    writeMembersToFile(memberOutFile, members, memberCount);

    // Clean up dynamically allocated memory
    delete[] library;
    delete[] members;

    
int recursiveBinarySearch(Book* books, int left, int right, const std::string& isbn) {
    if (left > right) {
        return -1; // Base case: not found
    }

    int mid = left + (right - left) / 2;

    if (books[mid].getISBN() == isbn) {
        return mid; // Found
    } else if (books[mid].getISBN() > isbn) {
        return recursiveBinarySearch(books, left, mid - 1, isbn); // Search left
    } else {
        return recursiveBinarySearch(books, mid + 1, right, isbn); // Search right
    }
}
void sortBooksByISBN(Book* books, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                std::swap(books[j], books[j + 1]);
            }
        }
    }
}

    return 0;
}

