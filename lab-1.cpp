#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& title, const string& author) : title(title), author(author) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        cout << "Cărțile din librărie:\n";
        for (const Book& book : books) {
            cout << "Titlu: " << book.getTitle() << ", Autor: " << book.getAuthor() << "\n";
        }
    }
};

int main() {
    Library library;

    int numBooks;
    cout << "Introduceți numărul de cărți: ";
    cin >> numBooks;
    cin.ignore();

    for (int i = 0; i < numBooks; ++i) {
        string title, author;
        cout << "Introduceți titlul cărții " << i + 1 << ": ";
        getline(cin, title);
        cout << "Introduceți autorul cărții " << i + 1 << ": ";
        getline(cin, author);

        Book newBook(title, author);
        library.addBook(newBook);
    }

    library.displayBooks();

    return 0;
}
