#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstdio>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <fstream>
#include <cstdarg>

int char_to_int(char* s)
{
    if (s == nullptr) return 0;
    int res = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

MyLibrary::MyLibrary(ostream& output_stream) : output_stream(output_stream)
{
    this->books_number = -1;
    books = nullptr;
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int* books) : output_stream(output_stream)
{
    this->books_number = books_number;
    this->books = new int[books_number];
    for (int i = 0; i < books_number; i++)
    {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int min, int max) : output_stream(output_stream)
{
    this->books_number = books_number;
    srand(time(NULL));
    books = new int[books_number];
    for (int i = 0; i < books_number; i++)
    {
        int random = rand() % max + min;
        books[i] = random;
    }
}

MyLibrary::MyLibrary(ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    int nr = 0;
    for (int i = 0; i < strlen(books_values); i++)
    {
        if (books_values[i] == ';') nr++;
    }
    this->books_number = nr + 1;
    books = new int[books_number];
    char* numar;
    char books2[500];
    strcpy(books2, books_values);
    numar = strtok(books2, ";");
    int i = 0;
    while (numar != NULL)
    {
        this->books[i] = char_to_int(numar);
        i++;
        numar = strtok(NULL, ";");
    }
}

MyLibrary::MyLibrary(ostream& output_stream, int books_count, ...) : output_stream(output_stream)
{
    this->books_number = books_count;
    books = new int[books_number];
    va_list arg;
    va_start(arg, books_count);
    for (int i = 0; i < books_number; i++)
    {
        this->books[i] = va_arg(arg, int);
    }
    va_end(arg);
}

void MyLibrary::print_books()
{
    output_stream << "Found " << books_number << " books" << endl;
    for (int i = 0; i < books_number; i++)
        output_stream << "Book: " << i << " " << books[i] << endl;
}

MyLibrary::~MyLibrary()
{
    delete[] books;
}

void MyLibrary::update_books_id_by_index(int book_index, int book_id)
{
    if (book_index < books_number)
        this->books[book_index] = book_id;
}

int MyLibrary::get_book_index_by_id(int id)
{
    if (books_number <= id) return -1;
    
    return books[id];
}
