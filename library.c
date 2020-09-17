#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void password();
void heading();
void mainMenu();
void addBook();

int count = 1;

struct BOOK_INFO
{
    int ID;
    char Name[20];
    char Author[20];
    int Quantity;
    int RackNo;
};

struct BOOK_INFO add;

FILE *fp;

int main()
{
    password();
}

void heading()
{
    printf("\n\n\t**************Library Management Software*************\n\n");
    // fflush(stdin);
    // getchar();
}

void password()
{
    heading();

    char pass[] = "fahim";

    char ch[10];

    printf("\tEnter Password : ");
    scanf("%s", ch);
    if (strcmp(pass, ch) == 0)
    {
        printf("\n\nLog in Successfully\n\n");
        printf("press any to ..... continue\n");
    }
    else
    {
        if (count == 3)
        {
            exit(1);
        }

        printf("\t try again\n");
        count++;
        fflush(stdin);
        getchar();
        password();
    }

    fflush(stdin);
    getchar();

    // main menu

    mainMenu();
}

void mainMenu()

{
    int choice;
    system("clear");

    printf("**************Main Menu ****************\n\n");

    printf("1. Add book\n");
    printf("2. View book list\n");
    printf("3. Search book\n");
    printf("4. Edit book\n");
    printf("5. Delete book\n");
    printf("6. Help\n");
    printf("7. Exit\n\n");

    printf("*********************************\n");

    printf("enter your choice : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        addBook();
    }
    else if (choice == 2)
    {
        //view Books
    }
    else if (choice == 3)
    {
        //search book
    }
    else if (choice == 4)
    {
        // edit book
    }
    else if (choice == 5)
    {
        //delete book
    }
    else if (choice == 6)
    {
        //help
    }
    else if (choice == 7)
    {
        exit(0);
    }

    else
    {
        printf("wrong choice\n try again \n");

        fflush(stdin);
        getchar();
        mainMenu();
        // mainMenu();
        // if (count==2)
        // {
        exit(0);
        // }
    }

    // getchar();
}

void addBook()
{
    int d, count = 0;
    system("clear");
    printf("***************Book Info *************\n\n");

    fp = fopen("books.txt", "ab+");

    printf("Enter ID: ");
    fflush(stdin);
    scanf("%d", &d);

    rewind(fp);

    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        if (d == add.ID)
        {
            printf("this book is already in library");
            count = 1;
        }
    }

    if (count == 1)
    {
        fflush(stdin);
        getchar();
        mainMenu();
    }

    add.ID = d;

    printf("Enter Name: ");
    fflush(stdin);
    scanf("%s", add.Name);

    printf("Enter Author: ");
    fflush(stdin);
    scanf("%s", add.Author);

    printf("enter quantity: ");
    fflush(stdin);
    scanf("%d", &add.Quantity);

    printf("Enter rack no: ");
    fflush(stdin);
    scanf("%d", &add.RackNo);

    fseek(fp, 0, SEEK_END);
    fwrite(&add, sizeof(add), 1, fp);

    fclose(fp);

    printf("ADD book successfully\n\n");

    fflush(stdin);
    getchar();

    mainMenu();
}