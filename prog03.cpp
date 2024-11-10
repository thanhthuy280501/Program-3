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

    return 0;
}

