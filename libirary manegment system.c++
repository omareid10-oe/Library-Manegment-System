#include <iostream>
#include <string>
using namespace std;

class book {
    string title;
    string author;
    bool isBorrowed;

public:
    book() {
        title = "";
        author = "";
        isBorrowed = false;
    }

    void setBook(string bTitle, string bAuthor) {
        title = bTitle;
        author = bAuthor;
        isBorrowed = false;
    }

    void getBook() {
        cout << "Title: " << title << " | Author: " << author 
             << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
    }

    void borrowBook() {
        if (isBorrowed) {
            cout << "Error: Book is already borrowed!\n";
        } else {
            isBorrowed = true;
            cout << "Book borrowed successfully!\n";
        }
    }

    void returnBook() {
        if (!isBorrowed) {
            cout << "Error: Book was not borrowed!\n";
        } else {
            isBorrowed = false;
            cout << "Book returned successfully!\n";
        }
    }
};

void displayLibraryMenu() {
    cout << "Choose an option:\n";
    cout << "1. Borrow Book\n";
    cout << "2. Return Book\n";
    cout << "3. View Book Details\n";
    cout << "4. Exit\n";
}

int main() {
    cout << "========== Welcome to Library Management System ============\n";
    string title, author;

    cout << "Enter Book Title and Author Name:\n";
    cin >> title >> author;

    book b1;
    b1.setBook(title, author);
    b1.getBook();

    while (true) {
        displayLibraryMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            b1.borrowBook();
            break;
        case 2:
            b1.returnBook();
            break;
        case 3:
            b1.getBook();
            break;
        case 4:
            cout << "Exiting Library System......\n";
            break;
        }

        if (choice == 4) break;
        cout << "=======================\n";
    }

    return 0;
}