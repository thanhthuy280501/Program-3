#include "Member.h" // Include your Member class header

// Name:         Thuy Nguyen
// Program:      CSC 275 Program 3
// Due Date:     11/09/24
// Compiler:     Code Block
// This is the main program file, which provides the user interface and integrates the Book and Member classes.

// Function to read members from a file
void readMembersFromFile(const std::string& filename, Member*& members, int& memberCount) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    inFile >> memberCount; // Assuming the first line contains the number of members
    inFile.ignore(); // Ignore the newline after the number

    members = new Member[memberCount]; // Dynamically allocate memory

    for (int i = 0; i < memberCount; ++i) {
        std::string name;
        int id, borrowedCount;
        std::getline(inFile, name);
        inFile >> id >> borrowedCount;
        inFile.ignore(); // Ignore newline

        members[i] = Member(name, id);

        for (int j = 0; j < borrowedCount; ++j) {
            std::string title, author, isbn, publisher;
            std::getline(inFile, title);
            std::getline(inFile, author);
            std::getline(inFile, isbn);
            std::getline(inFile, publisher);
            Book borrowedBook(title, author, isbn, publisher);
            members[i].borrowBook(borrowedBook);
        }
    }

    inFile.close();
}

// Function to write members to a file
void writeMembersToFile(const std::string& filename, Member* members, int memberCount) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < memberCount; ++i) {
        outFile << members[i].getName() << '\n'
                << members[i].getId() << '\n'
                << members[i].getBorrowedCount() << '\n';

        for (const auto& book : members[i].getBorrowedBooks()) {
            outFile << book.getTitle() << '\n'
                    << book.getAuthor() << '\n'
                    << book.getISBN() << '\n'
                    << book.getPublisher() << '\n';
        }
    }

    outFile.close();
}

