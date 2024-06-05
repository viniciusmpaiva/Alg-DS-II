#include "management.h"
int idx =0;
char indexStr[INDEXSTRMAXLEN];


static void insertSecundaryIndexFile(Book book, FILE* filePointer){
    fwrite(book.title,sizeof(book.title),1,filePointer);
    char isbnStr[ISBNSTRMAXLEN];
    sprintf(isbnStr,"%d",book.isbn);
    fwrite(isbnStr,sizeof(isbnStr),1,filePointer);
}

static void insertPrimaryIndexFile(Book book, FILE* filePointer){
    //key = isbn
    char isbnStr[ISBNSTRMAXLEN];
    sprintf(isbnStr,"%d",book.isbn);
    fwrite(isbnStr,sizeof(isbnStr),1,filePointer);
    int curIdx = (sizeof(book)+INDEXSTRMAXLEN) * idx;
    sprintf(indexStr,"%d",curIdx);
    fwrite(indexStr,sizeof(indexStr),1,filePointer);

}

static void insertDataFile(Book book, FILE* filePointer){
    int curIdx = (sizeof(book)+INDEXSTRMAXLEN) * idx;
    sprintf(indexStr,"%d",curIdx);
    fseek(filePointer,curIdx,SEEK_SET);
    fwrite(indexStr,sizeof(indexStr),1,filePointer);
    fwrite(&book,sizeof(Book),1,filePointer);
}


static int findBookIdx(char* title){
    Book bookAux;
    char isbnStr1[ISBNSTRMAXLEN];

    FILE* filePointerData = fopen(DATAFILENAME,"r");
    FILE* filePointerPrimaryIndex = fopen(PRIMARYINDEXFILENAME,"r");
    FILE* filePointerSecondaryIndex = fopen(SECONDARYINDEXFILENAME,"r");

    //Search in secondary index
    while(1){
        size_t titleRead = fread(&bookAux.title,sizeof(bookAux.title),1,filePointerSecondaryIndex);
        size_t keyRead = fread(&isbnStr1,sizeof(isbnStr1),1,filePointerSecondaryIndex);

        if(titleRead !=1 || keyRead !=1){
            break;
        }

        if(strcmp(bookAux.title,title)==0){
        
            break;
        }
    }

    //gets the key and search for the index in the primary index file
    char tempIdx[INDEXSTRMAXLEN];
    char isbnStr2[ISBNSTRMAXLEN];
    int num =0;

    while(1){        
        size_t isbnRead = fread(&isbnStr2,sizeof(isbnStr2),1,filePointerPrimaryIndex);
        size_t idxRead = fread(&tempIdx,sizeof(tempIdx),1,filePointerPrimaryIndex);
        
        if(idxRead!=1 || isbnRead !=1){
            printf("Deu o break");
            break;
        }
        if(strcmp(isbnStr1,isbnStr2) == 0){
            
            break;
        }

    }

    return atoi(tempIdx);
}
static Book searchBook(char* title, FILE* filePointerData, FILE* filePointerPrimaryIndex, FILE* filePointerSecondaryIndex){
    int intTempIdx = findBookIdx(title);
    Book bookAux;
    char tempIdx[INDEXSTRMAXLEN];
    fseek(filePointerData,intTempIdx,SEEK_SET);
    if(fread(&tempIdx,sizeof(tempIdx),1,filePointerData)!=1){
        printf("Erro na leitura do index");
    }
    if(fread(&bookAux,sizeof(bookAux),1,filePointerData)!=1){
        printf("Erro na leitura do livro");
    }

    // printf("Index = %s\n",tempIdx);
    // printf("Title = %s\n",bookAux.title);
    
    fclose(filePointerData);
    fclose(filePointerPrimaryIndex);
    fclose(filePointerSecondaryIndex);
    return bookAux;
}
static int isInCollection(Book book){
    FILE* filePointer = fopen(SECONDARYINDEXFILENAME,"r");
    char isbnStrAux[ISBNSTRMAXLEN];
    Book bookAux;
    while(1){
        size_t titleRead = fread(&bookAux.title,sizeof(bookAux.title),1,filePointer);
        size_t keyRead = fread(&isbnStrAux,sizeof(isbnStrAux),1,filePointer);
        // printf("Title = %s\n",bookAux.title);
        if(titleRead !=1){
            break;
        }
        if(strcmp(bookAux.title,book.title)==0){
            return 1;
        }
    }
    return 0;
}


void addBook(Book book){
    FILE *filePointerData = fopen("booksData.txt","a");
    FILE *filePointerPrimaryIndex = fopen("booksPrimaryIndex.txt","a");
    FILE *filePointerSecondaryIndex = fopen("booksSecondaryIndex.txt","a");
    if(isInCollection(book)){
        printf("Book already in collection\n");
        return;
    }
    insertDataFile(book,filePointerData);
    insertPrimaryIndexFile(book,filePointerPrimaryIndex);
    insertSecundaryIndexFile(book,filePointerSecondaryIndex);
    idx++;
    fclose(filePointerData);
    fclose(filePointerPrimaryIndex);
    fclose(filePointerSecondaryIndex);
}




void readRegister(char* title){
    FILE* filePointerData = fopen("booksData.txt","r");
    FILE* filePointerPrimaryIndex = fopen("booksPrimaryIndex.txt","r");
    FILE* filePointerSecondaryIndex = fopen("booksSecondaryIndex.txt","r");
    Book bookAux;
    strcpy(bookAux.title,title);
    if(!isInCollection(bookAux)){
        printf("Book not in collection\n");
        return;
    };
    bookAux = searchBook(title,filePointerData,filePointerPrimaryIndex,filePointerSecondaryIndex); 
    printf("Title: %s\n",bookAux.title);
    printf("Autor: %s\n",bookAux.autor);
    printf("Start Year: %d\n",bookAux.startYear);
    printf("End Year: %d\n",bookAux.endYear);
    printf("Genre: %s\n",bookAux.genre);
    printf("Magazine: %s\n",bookAux.magazine);
    printf("Publisher: %s\n",bookAux.publisher);
    printf("Edition Year: %d\n",bookAux.editionYear);
    printf("Number of Volumes: %d\n",bookAux.numOfVolumes);
    printf("isbn: %d\n",bookAux.isbn);
    printf("======================================\n");

}

void updateRegister(Book book,int option, char* newValue){
    FILE* filePointerData = fopen("booksData.txt","r+b");
    if(!isInCollection(book)){
        printf("Book not in collection\n");
        return;
    };

    int intBookIdx = findBookIdx(book.title);
    fseek(filePointerData,intBookIdx,SEEK_SET);

    if(option == 1){
        strcpy(book.title,newValue);
    }else if(option == 2){
        strcpy(book.autor,newValue);
    }else if(option == 3){
        book.startYear = atoi(newValue);
    }else if(option == 4){
        book.endYear = atoi(newValue);
    }else if(option == 5){
        strcpy(book.genre,newValue);
    }else if(option == 6){
        strcpy(book.magazine,newValue);
    }else if(option == 7){
        strcpy(book.publisher,newValue);
    }else if(option == 8){
        book.editionYear = atoi(newValue);
    }else if(option == 9){
        book.numOfVolumes = atoi(newValue);
    }
    char tempIdx[INDEXSTRMAXLEN];
    fread(&tempIdx,sizeof(tempIdx),1,filePointerData);
    fwrite(&book,sizeof(Book),1,filePointerData);
    fclose(filePointerData);
}

void deleteRegister(char *title){
    int delIdx = findBookIdx(title);
    FILE* filePointerData = fopen(DATAFILENAME,"r+b");
    FILE* filePointerPrimaryIndex = fopen(PRIMARYINDEXFILENAME,"r+b");
    FILE* filePointerSecondaryIndex = fopen(SECONDARYINDEXFILENAME,"r+b");
    fseek(filePointerData,delIdx,SEEK_SET);
    
}