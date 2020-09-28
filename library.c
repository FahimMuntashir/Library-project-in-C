#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void password();
void heading();
void mainMenu();
void addBook();
void viewBooks();
void searchBook();
void editBook();

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
        viewBooks();
    }
    else if (choice == 3)
    {
        searchBook();
    }
    else if (choice == 4)
    {
        editBook();
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

void viewBooks()
{

    int count = 0;

    system("clear");
    fflush(stdin);
    printf("\n\n ***************** View Books*****************\n\n");
    printf("Id\tName\tTuthor\tQuantity\tRack No\n\n\n");

    fp = fopen("books.txt", "rb");

    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        printf("%d", add.ID);
        printf("\t%s", add.Name);
        printf("\t%s", add.Author);
        printf("\t%d", add.Quantity);
        printf("\t%d\n", add.RackNo);

        count = count + add.Quantity;
    }
    printf("\n total books in the library : %d\n", count);
    printf("press any key .......\n");
    fflush(stdin);
    getchar();

    //    mainMenu();
}

void searchBook()
{
    int count, flag = 0;
    system("clear");
    printf("***********Search books**********\n\n");

    fp = fopen("books.txt", "rb");

    printf("enter ID: \n");
    scanf("%d", &count);

    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        if (count == add.ID)
        {
            printf("\n\n Book is found.....\n");
            printf("Id: %d\n", add.ID);
            printf("Id: %s\n", add.Name);
            printf("Id: %s\n", add.Author);
            printf("Id: %d\n", add.Quantity);
            printf("Id: %d\n", add.RackNo);

            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("id not found\n");
    }

    printf("press any key... \n ");
    fflush(stdin);
    getchar();

    mainMenu();
}

void editBook()
{
    int d;
    int count = 0;
    system("clear");

    printf("******************* edit book ************** \n\n");

    fp = fopen("books.txt", "rb+");

    printf("enter ID : \n");

    scanf("%d", &d);

    while (fread(&add, sizeof(add), 1, fp) == 1)

    {
        if (d == add.ID)
        {
            printf("Id is available");

            printf("ID: %d\n", add.ID);

            printf("enter new name: ");
            scanf("%s", add.Name);
            printf("enter new author: ");
            scanf("%s", add.Author);
            printf("enter new quantity: ");
            scanf("%d", &add.Quantity);
            printf("enter new rack no : ");
            scanf("%d", &add.RackNo);

            fseek(fp, ftell(fp) - sizeof(add), 0);
            fwrite(&add, sizeof(add), 1, fp);

            fclose(fp);

            count = 1;
            break;
        }
    }

    if (count = 0)
    {
        printf("id not match \n");
    }
    

    printf("press any key ........ \n");

    fflush(stdin);
    getchar();

    mainMenu();
}