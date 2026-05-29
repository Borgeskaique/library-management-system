#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;

public:
    // Set book details
    void setBookDetails(string t, string a, string i, bool avail) {
        title = t;
        author = a;
        isbn = i;
        availability = avail;
    }

    // Display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "--------------------------" << endl;
    }

    // Borrow book (only if currently available)
    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    // Return book (only if currently borrowed)
    bool returnBook() {
        if (!availability) {
            availability = true;
            return true;
        }
        return false;
    }

    // Get ISBN
    string getISBN() {
        return isbn;
    }

    // Check availability
    bool isAvailable() {
        return availability;
    }
};

int main() {
    Book library[5];
    string inputISBN;
    bool found;
    int choice;

    // Initialize 5 books
    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "111", true);
    library[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "222", true);
    library[2].setBookDetails("1984", "George Orwell", "333", false);
    library[3].setBookDetails("Pride and Prejudice", "Jane Austen", "444", true);
    library[4].setBookDetails("Moby Dick", "Herman Melville", "555", true);

    cout << "=== Community Library System ===" << endl;

    // Menu loop: the menu is shown before AND after every option,
    // and the librarian exits by choosing option 4.
    do {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1) Display Books" << endl;
        cout << "2) Borrow Book" << endl;
        cout << "3) Return Book" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nBooks in Library:\n" << endl;
            for (int i = 0; i < 5; i++) {
                library[i].displayBookDetails();
            }
        }

        else if (choice == 2) {
            cout << "Enter ISBN of the book you want to borrow: ";
            cin >> inputISBN;

            found = false;

            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    found = true;

                    if (library[i].borrowBook()) {
                        cout << "Book borrowed successfully!" << endl;
                    } else {
                        cout << "Error: Book is currently unavailable." << endl;
                    }

                    break;
                }
            }

            if (!found) {
                cout << "Error: Book with ISBN " << inputISBN << " not found." << endl;
            }
        }

        else if (choice == 3) {
            cout << "Enter ISBN of the book you want to return: ";
            cin >> inputISBN;

            found = false;

            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    found = true;

                    if (library[i].returnBook()) {
                        cout << "Book returned successfully!" << endl;
                    } else {
                        cout << "Error: This book is already available." << endl;
                    }

                    break;
                }
            }

            if (!found) {
                cout << "Error: Book with ISBN " << inputISBN << " not found." << endl;
            }
        }

        else if (choice == 4) {
            cout << "Program exited successfully." << endl;
        }

        else {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
