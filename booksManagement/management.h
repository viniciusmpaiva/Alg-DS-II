#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#define ISBNSTRMAXLEN 15
#define INDEXSTRMAXLEN 5
#define MAXBOOKS 200
#define SECONDARYINDEXFILENAME "booksSecondaryIndex.txt"
#define PRIMARYINDEXFILENAME "booksPrimaryIndex.txt"
#define DATAFILENAME "booksData.txt"

//A chave do indice primário será o isbn
//A chave do indice secundário será o nome do livro

typedef struct Book{
    int isbn;
    char title[100];
    char autor[100];
    int startYear;
    int endYear;
    char genre[50];
    char magazine[50];
    char publisher[50];
    int editionYear;
    int numOfVolumes;
} Book;

void addBook(Book book);
void readRegister(char* title);
void updateRegister(Book book,int option, char* newValue);
void deleteRegister(char* title);



#endif