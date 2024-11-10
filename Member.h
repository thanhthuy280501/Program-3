// Name:         Thuy Nguyen
// Program:      CSC 275 Program 3
// Due Date:     11/09/24
// Compiler:     Code Block
// This is the main program file, which provides the user interface and integrates the Book and Member classes.
class Member {
private:
    std::string name;
    int id;
    Book* borrowedBooks; // Array of borrowed books
    int borrowedCount;

public:
    // Constructor, Copy Constructor, Assignment Operator, Destructor
    Member(const std::string& n, int i) : name(n), id(i), borrowedBooks(nullptr), borrowedCount(0) {}

    // Implement these functions similarly if borrowedBooks is dynamically allocated

    ~Member() {
        delete[] borrowedBooks; // Free the borrowed books array
    }

    // Other member functions...
};

