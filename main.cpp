/*
Предметная область: Библиотека
Информационные объекты: Библиотека, Библиотекарь, Книги, Авторы, Посетитель
У книги может быть только один автор.
Посетитель посещает библиотеку с целью найти книгу по имени автора И/ИЛИ по названию книги.
Необходимо реализовать данный функционал, придерживаясь принципов DRY, KISS, YAGNI и Single Responsibility Principle
*/
#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
  string name;
  string author;

public:
  Book(const string name, const string author) {
    this->name = name;
    this->author = author;
  }
  const string &getName() const { return name; }

  const string &getAuthor() const { return author; }
};

class Library {
private:
  vector<Book> books;

public:
  explicit Library(vector<Book> Books) { books = Books; }

  ~Library() { books.clear(); }

  bool SearchBook(const Book &book) {
    string name = book.getName();
    string author = book.getAuthor();
    for (int i = 0; i < books.size(); i++) {
      if ((name == books[i].getName()) && (author == books[i].getAuthor())) {
        return true;
      }
    }
    return false;
  }

  bool SearchBookByName(string name) {
    for (int i = 0; i < books.size(); i++) {
      if (name == books[i].getName()) {
        return true;
      }
    }
    return false;
  }

  bool SearchBookByAuthor(string author) {
    for (int i = 0; i < books.size(); i++) {
      if (author == books[i].getAuthor()) {
        return true;
      }
    }
    return false;
  }
};

class Worker : public Library {
private:
  string name;

public:
  Worker(vector<Book> books, string name) : Library(books) { name = name; };

  void FindBook(string name, string author) {
    cout << name << " " << author << endl;
    if (SearchBook({name, author}) == true) {
      cout << "We have such book! Will you take this book" << endl;
    } else {
      cout << "Sorry we don't have such book" << endl;
    }
  }
  void FindBookByName(string name) {
    cout << name << endl;
    if (SearchBookByName(name) == true) {
      cout << "We have book with such name! Will you take this book" << endl;
    } else {
      cout << "Sorry we don't have such book" << endl;
    }
  }

  void FindBookByAuthor(string author) {
    cout << author << endl;
    if (SearchBookByAuthor(author) == true) {
      cout << "We have book such author! Will you take this book" << endl;
    } else {
      cout << "Sorry we don't have book such author" << endl;
    }
  }
};

int main() {
  Book b1{"Winnie-the-Pooh", "А.A. Milne"};
  Book b2{"Harry Potter and the Philosopher’s Stone", "J.K. Rowling"};
  Book b3{"Airport", "Arthur Hailey"};
  Book b4{"The Adventures of Sherlock Holmes", "Arthur Conan Doyle"};
  Book b5{"Three Men in a Boat", "Jerome K. Jerome"};
  Book b6{"Jane Eyre", "Charlotte Bronte"};
  Book b7{"Bridget Jones’ Diary", "Helen Fielding"};

  vector<Book> books = {b1, b2, b3, b4, b5, b6, b7};
  Library labrary(books);

  Worker Eva(books, "Eva");
  Eva.FindBook("Jane Eyre", "Charlotte Bronte");
  Eva.FindBook("To Kill a Mockingbird", "Harper Lee");
  Eva.FindBookByName("Winnie-the-Pooh");
  Eva.FindBookByName("Hitchhiker’s Guide to the Galaxy");

  std::cout << "Hello, World!" << std::endl;
  return 0;
}