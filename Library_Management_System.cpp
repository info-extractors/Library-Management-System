#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book() {}

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    int getId() {
        return id;
    }

    string getTitle() {
        return title;
    }

    bool isIssued() {
        return issued;
    }

    void issueBook() {
        issued = true;
    }

    void returnBook() {
        issued = false;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: ";

        if (issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << "\n----------------------\n";
    }

    string serialize() {
        return to_string(id) + "|" + title + "|" + author + "|" + to_string(issued);
    }

    void setIssued(bool val) {
        issued = val;
    }

    string getAuthor() {
        return author;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        for (auto &book : books) {
            book.display();
        }
    }

    void searchBook() {
        string title;

        cin.ignore();

        cout << "Enter title to search: ";
        getline(cin, title);

        bool found = false;

        for (auto &book : books) {
            if (book.getTitle() == title) {
                book.display();
                found = true;
            }
        }

        if (!found)
            cout << "Book not found.\n";
    }

    void issueBook() {
        int id;

        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.getId() == id) {

                if (book.isIssued()) {
                    cout << "Book already issued.\n";
                    return;
                }

                book.issueBook();
                cout << "Book issued successfully.\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;

        cout << "Enter Book ID to return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.getId() == id) {

                if (!book.isIssued()) {
                    cout << "Book was not issued.\n";
                    return;
                }

                book.returnBook();
                cout << "Book returned successfully.\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void saveToFile() {
        ofstream file("data.txt");

        for (auto &book : books) {
            file << book.serialize() << endl;
        }

        file.close();

        cout << "Data saved successfully.\n";
    }
};

int main() {

    Library lib;

    int choice;

    while (true) {

        cout << "\n===== Library Management System =====\n";

        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Save Data\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            lib.searchBook();
            break;

        case 4:
            lib.issueBook();
            break;

        case 5:
            lib.returnBook();
            break;

        case 6:
            lib.saveToFile();
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
