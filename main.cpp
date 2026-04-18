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

    // Borrow book
    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    // Return book
    void returnBook() {
        availability = true;
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

    // Initialize 5 books
    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "111", true);
    library[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "222", true);
    library[2].setBookDetails("1984", "George Orwell", "333", false);
    library[3].setBookDetails("Pride and Prejudice", "Jane Austen", "444", true);
    library[4].setBookDetails("Moby Dick", "Herman Melville", "555", true);

    cout << "=== Community Library System ===" << endl;

    while (true) {
        cout << "\nAvailable Books in Library:\n" << endl;

        for (int i = 0; i < 5; i++) {
            library[i].displayBookDetails();
        }

        cout << "Enter ISBN of the book you want to borrow (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program terminated." << endl;
            break;
        }

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

    return 0;
}
