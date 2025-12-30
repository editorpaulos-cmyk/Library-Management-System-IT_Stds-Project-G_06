#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Book structure
struct Book {
    int bookID;
    string title;
    string author;
    bool isBorrowed;
    string borrowerName;
};

// Library Manager class
class LibraryManager {
private:
    vector<Book> books;

public:
    void addBook() {
        Book b;
        cout << "\nADD NEW BOOK\n";
        cout << "-----------------------------\n";
        cout << "Book ID: ";
        cin >> b.bookID;
        cin.ignore();
        cout << "Title: ";
        getline(cin, b.title);
        cout << "Author: ";
        getline(cin, b.author);

        b.isBorrowed = false;
        b.borrowerName = "None";
        books.push_back(b);

        cout << "Book successfully added.\n";
    }

    void borrowBook() {
        int id;
        cout << "\nBORROW BOOK\n";
        cout << "-----------------------------\n";
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < books.size(); i++) {
            if (books[i].bookID == id) {
                if (!books[i].isBorrowed) {
                    cout << "Borrower Name: ";
                    getline(cin, books[i].borrowerName);
                    books[i].isBorrowed = true;
                    cout << "Book borrowed successfully.\n";
                } else {
                    cout << "Book already borrowed by "
                         << books[i].borrowerName << ".\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "\nRETURN BOOK\n";
        cout << "-----------------------------\n";
        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].bookID == id) {
                if (books[i].isBorrowed) {
                    books[i].isBorrowed = false;
                    books[i].borrowerName = "None";
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not borrowed.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void viewBooks() {
        cout << "\nLIBRARY BOOK LIST\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << left << setw(8) << "ID"
             << setw(22) << "Title"
             << setw(18) << "Author"
             << setw(12) << "Status"
             << setw(15) << "Borrower" << endl;
        cout << "--------------------------------------------------------------------------\n";

        if (books.size() == 0) {
            cout << "No books available in the library.\n";
            return;
        }

        for (int i = 0; i < books.size(); i++) {
            cout << left << setw(8) << books[i].bookID
                 << setw(22) << books[i].title
                 << setw(18) << books[i].author
                 << setw(12) << (books[i].isBorrowed ? "Borrowed" : "Available")
                 << setw(15) << books[i].borrowerName << endl;
        }
    }
};

int main() {
    LibraryManager library;
    int choice;

    do {
        cout << "\n=============================================\n";
        cout << "      SMART LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=============================================\n";
        cout << "1. Add New Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. View All Books\n";
        cout << "5. Exit\n";
        cout << "---------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.borrowBook(); break;
            case 3: library.returnBook(); break;
            case 4: library.viewBooks(); break;
            case 5: cout << "\nThank you for using the library system.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

/*
	by 2nd year students of the Institute of Technology, Department of Information Technology, Group 6.
	Developed by:

		1, Paulos Aschenaki
		2, Tadiwos Getaneh
		3, Sador Kebede
		4, Atsede Aschalew
		5, Eyerus Adino
*/
