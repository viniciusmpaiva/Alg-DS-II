#include "management.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    Book book1;
    book1.isbn = 123456;
    book1.startYear=1024;
    strcpy(book1.autor,"J.R.R. Tolkien");
    strcpy(book1.title,"The Lord of the Rings");
    book1.editionYear=2019;
    book1.endYear=2019;
    strcpy(book1.genre,"Fantasy");
    strcpy(book1.magazine,"The Hobbit");
    strcpy(book1.publisher,"HarperCollins");
    book1.numOfVolumes=3;
    addBook(book1);
    readRegister(book1.title);
    Book book2;
    book2.isbn =7891011;
    strcpy(book2.title,"The Songs of Ice and Fire");
    book2.startYear=1996;
    book2.endYear=2011;
    strcpy(book2.autor,"George R. R. Martin");
    strcpy(book2.genre,"Fantasy");
    strcpy(book2.magazine,"A Song of Ice and Fire");
    strcpy(book2.publisher,"Bantam Spectra");
    book2.editionYear=2011;
    book2.numOfVolumes=5;
    addBook(book2);
    updateRegister(book2,1,"The Songs of Ice and Fire: A Song of Ice and Fire");
    updateRegister(book2,8,"2001");
    // readRegister(book2.title);

    readRegister(book2.title);

    // printf("Book Management System\n");
    // while(1){
    //     printf("1- Add Register\n");
    //     printf("2- Read Register\n");
    //     printf("3- Update Register\n");
    //     printf("=============================================\n");
    //     printf("Select an option:\n");
    //     int option;
    //     scanf("%d",&option);
    //     switch(option){
    //         case 1:
    //             clearInputBuffer();
    //             printf("What is the title of the book you want to add?\n");
    //             char title[100];
    //             fgets(title,100,stdin);


    //             printf("What is the autor of the book you want to add?\n");
    //             char autor[100];
    //             fgets(autor,100,stdin);


    //             printf("What is the start year of the book you want to add?\n");
    //             int startYear;
    //             scanf("%d",&startYear);

    //             clearInputBuffer();

    //             printf("What is the end year of the book you want to add?\n");
    //             int endYear;
    //             scanf("%d",&endYear);

    //             clearInputBuffer();
                
    //             printf("What is the genre of the book you want to add?\n");
    //             char genre[50];
    //             // scanf("%s",genre);
    //             fgets(genre,50,stdin);


    //             printf("What is the magazine of the book you want to add?\n");
    //             char magazine[50];
    //             // scanf("%s",magazine);
    //             fgets(magazine,50,stdin);


    //             printf("What is the publisher of the book you want to add?\n");
    //             char publisher[50];
    //             // scanf("%s",publisher);
    //             fgets(publisher,50,stdin);


    //             printf("What is the edition year of the book you want to add?\n");
    //             int editionYear;
    //             scanf("%d",&editionYear);

    //             clearInputBuffer();

    //             printf("What is the number of volumes of the book you want to add?\n");
    //             int numOfVolumes;
    //             scanf("%d",&numOfVolumes);

    //             clearInputBuffer();

    //             printf("What is the isbn of the book you want to add?\n");
    //             int isbn;
    //             scanf("%d",&isbn);

    //             clearInputBuffer();

    //             Book book;
    //             book.isbn = isbn;
    //             book.startYear=startYear;
    //             strcpy(book.autor,autor);
    //             strcpy(book.title,title);
    //             book.editionYear=editionYear;
    //             book.endYear=endYear;
    //             strcpy(book.genre,genre);
    //             strcpy(book.magazine,magazine);
    //             strcpy(book.publisher,publisher);
    //             book.numOfVolumes=numOfVolumes;
    //             addBook(book);
    //             break;
    //         case 2:
    //             break;
    //         case 3:
    //             printf("What is the title of the book you want to update?\n");
    //             scanf("%s",title); 
    //             readRegister(title);
    //             int updateOption =0;
    //             while(updateOption!=11){
    //                 printf("What information do you want to update?\n");
    //                 printf("1- Title\n");
    //                 printf("2- Autor\n");
    //                 printf("3- Start Year\n");
    //                 printf("4- End Year\n");
    //                 printf("5- Genre\n");
    //                 printf("6- Magazine\n");
    //                 printf("7- Publisher\n");
    //                 printf("8- Edition Year\n");
    //                 printf("9- Number of Volumes\n");
    //                 printf("10- ISBN\n");
    //                 printf("11- Exit\n");
    //                 scanf("%d",&updateOption);
    //                 switch(updateOption){
    //                     case 1:
    //                         printf("What is the new title?\n");
    //                         char newTitle[100];
    //                         scanf("%s",newTitle);
    //                         updateRegister(title,1,newTitle);
    //                         break;
    //                     case 2:
    //                         printf("What is the new autor?\n");
    //                         char newAutor[100];
    //                         scanf("%s",newAutor);
    //                         updateRegister(title,2,newAutor);
    //                         break;
    //                     case 3:
    //                         printf("What is the new start year?\n");
    //                         int newStartYear;
    //                         scanf("%d",&newStartYear);
    //                         char newStartYearStr[5];
    //                         updateRegister(title,3,&newStartYear);
    //                         break;
    //                     case 4:
    //                         printf("What is the new end year?\n");
    //                         int newEndYear;
    //                         scanf("%d",&newEndYear);
    //                         updateRegister(title,4,&newEndYear);
    //                         break;
    //                     case 5:
    //                         printf("What is the new genre?\n");
    //                         char newGenre[50];
    //                         scanf("%s",newGenre);
    //                         updateRegister(title,5,newGenre);
    //                         break;
    //                     case 6:
    //                         printf("What is the new magazine?\n");
    //                         char newMagazine[50];
    //                         scanf("%s",newMagazine);
    //                         updateRegister(title,6,newMagazine);
    //                         break;
    //                     case 7:
    //                         printf("What is the new publisher?\n");
    //                         char newPublisher[50];
    //                         scanf("%s",newPublisher);
    //                         updateRegister(title,7,newPublisher);
    //                         break;
    //                     case 8:
    //                         printf("What is the new edition year?\n");
    //                         int newEditionYear;
    //                         scanf("%d",&newEditionYear);
    //                         updateRegister(title,8,&newEditionYear);
    //                         break;
    //                     case 9:
    //                         printf("What is the new number of volumes?\n");
    //                         int newNumOfVolumes;
    //                         scanf("%d",&newNumOfVolumes);
    //                         updateRegister(title,9,&newNumOfVolumes);
    //                         break;
    //                     case 10:
    //                         printf("What is the new isbn?\n");
    //                         int newIsbn;
    //                         scanf("%d",&newIsbn);
    //                         updateRegister(title,10,&newIsbn);
    //                         break;
    //                     case 11:
    //                         break;
    //                 }
    //             }
                
    //     }

    // }
}