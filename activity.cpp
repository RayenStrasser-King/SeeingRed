#include <iostream>
#include <vector>
#include "activity.h"

using namespace std;

Book* addBook()
{
        string title;
        int year;
        cout<<"Please enter the title of the new book."<<endl;
        getline (cin, title);
        cout<<"Please enter the year of the new book."<<endl;
        cin>>year;
        Book* ptr = new Book(title, year);
        cin.ignore();
        return ptr;
}

void displayBooks(vector<Book*> books)
{
        for (int i = 0; i <books.size(); i++)
        {
                cout<<"index = " << i << " TITLE = " <<books[i]->getTitle()<<endl;
                cout<<"index = " << i << " YEAR  = " <<books[i]->getYear()<<endl;
        }
}
vector<Book*> switchBooks (vector<Book*> books, int a, int b)
{
        Book* temp = books[a];
        books[a] = books[b];
        books[b] = temp;

        return books;
}


string Book::getTitle()
{
 return title;
}

int Book::getYear()
{
        return year;
}
