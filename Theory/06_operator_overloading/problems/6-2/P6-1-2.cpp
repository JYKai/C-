#include <iostream>
#include <cstring>
using namespace std;


class Book
{
private:
    char *title;
    char *isbn;
    int price;

public:
    Book(char *title, char *isbn, int price) : price(price)
    {
        this->title = new char[strlen(title) + 1];
        this->isbn = new char[strlen(isbn) + 1];
        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }
    void ShowBookInfo(void) const
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    Book& operator=(const Book& ref)
    {
        delete []title;
        delete []isbn;
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }

    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};


class EBook : public Book
{
private:
    char *DRMKey;

public:
    EBook(char *title, char *isbn, int price, char *DRMKey)
        : Book(title, isbn, price)
    {
        this->DRMKey = new char[strlen(DRMKey) + 1];
        strcpy(this->DRMKey, DRMKey);
    }
    void ShowBookInfo(void) const
    {
        Book::ShowBookInfo();
        cout << "인증키: " << DRMKey << endl << endl;
    }
    EBook& operator=(const EBook &ref)
    {
        Book::operator=(ref);
        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};


int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "adsgeasadsad");
    ebook.ShowBookInfo();

    book = ebook;
    book.ShowBookInfo();

    return 0;
}