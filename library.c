#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define TRIES 3

void password();
void heading();
void mainMenu();
int addBook();
void viewBooks();
int searchBook();
int editBook();
void deleteBook();
void help();
void exitProg();

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
FILE *file2;

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

    int count = 1;
    char pass[] = "fahim";
    char ch[10];

    printf("\tEnter Password : \n");

    gets(ch);

    while(strcmp(ch, pass) != 0)
    {
        count++;

        if (count > TRIES)
        {
            exit(1);
        }

        printf("\t try again\n");
        gets(ch);
    }

    printf("\n\nLog in Successfully\n\n"
           "press any to ..... continue\n");

    getchar();

    // main menu
    mainMenu();
}

void mainMenu()
{
    int choice = 0;
    system("clear");

    while(1)
    {

        printf("**************Main Menu ****************\n\n");

        printf("1. Add book\n"
               "2. View book list\n"
               "3. Search book\n"
               "4. Edit book\n"
               "5. Delete book\n"
               "6. Help\n"
               "7. Exit\n\n");

        printf("*********************************\n");

        printf("enter your choice : ");
        scanf("%d", &choice);
        getchar();


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
            deleteBook();
        }
        else if (choice == 6)
        {
            help();
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            printf("wrong choice\n try again \n");
        }
    }
    exitProg();
}

int addBook()
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
            return 0;
        }
    }

    add.ID = d;

    printf("Enter Name: ");
    fflush(stdin);
    scanf("%s", add.Name);

    printf("Enter Author: ");
    fflush(stdin);
    scanf("%s", add.Author);

    printf("Enter quantity: ");
    fflush(stdin);
    scanf("%d", &add.Quantity);

    printf("Enter Rack-no: ");
    fflush(stdin);
    scanf("%d", &add.RackNo);

    fseek(fp, 0, SEEK_END);
    fwrite(&add, sizeof(add), 1, fp);

    fclose(fp);

    printf("Book ADDED successfully\n\n");

    return 0;
}

void viewBooks()
{
    int count = 0;

    system("clear");
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
    fclose(fp);
    printf("\n\nTotal books in the library : %d\n", count);
    printf("\npress any key .......\n");

    getchar();
}

int searchBook()
{
    int count;
    system("clear");
    printf("***********Search books**********\n\n");

    fp = fopen("books.txt", "rb");

    printf("Enter ID: \n");
    scanf("%d", &count);
    getchar();

    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        if (count == add.ID)
        {
            printf("\nBook is found.....\n");
            printf("Id: %d\n", add.ID);
            printf("Name: %s\n", add.Name);
            printf("Author: %s\n", add.Author);
            printf("Quantity: %d\n", add.Quantity);
            printf("Rack no: %d\n\n", add.RackNo);

            printf("\nPress any key... \n ");
            getchar();

            return 0;
        }
    }

    printf("ID not found\n");
    printf("\nPress any key... \n ");
    getchar();

    return 0;
}

int editBook()
{
    int d;
    int count = 0;
    system("clear");

    printf("******************* Edit book ************** \n\n");

    fp = fopen("books.txt", "rb+");

    printf("Enter ID : \n");

    scanf("%d", &d);
    getchar();

    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        if (d == add.ID)
        {
            printf("Id is available\n\n");

            printf("ID: %d\n", add.ID);

            printf("Enter new name: ");
            scanf("%s", add.Name);
            printf("Enter new author: ");
            scanf("%s", add.Author);
            printf("Enter new quantity: ");
            scanf("%d", &add.Quantity);
            getchar();
            printf("Enter new rack no : ");
            scanf("%d", &add.RackNo);
            getchar();

            fseek(fp, ftell(fp) - sizeof(add), 0);
            fwrite(&add, sizeof(add), 1, fp);

            fclose(fp);

            printf("\n\nPress any key ........ \n");
            getchar();
            return 0;
        }
    }

    printf("id not match \n");
    printf("\n\nPress any key ........ \n");
    getchar();

    return 0;
}

void deleteBook()
{
    int d, count = 0;

    system("clear");
    printf("************* delete books ************** \n\n");

    printf("Enter Id for delete : ");
    scanf("%d", &d);
    getchar();

    fp = fopen("books.txt", "rb+");

    rewind(fp);

    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        if (d == add.ID)
        {
            printf("Book is available\n\n");

            printf(" Book name : %s\n", add.Name);
            printf("Rack no : %d\n", add.RackNo);

            count = 1;
        }
    }

    if (count == 0)
    {
        printf("Book not found \n");
    }
    else
    {


        file2 = fopen("text.txt", "wb+");

        rewind(fp);

        while (fread(&add, sizeof(add), 1, fp) == 1)
        {
            if (d != add.ID)
            {
                fseek(file2, ftell(file2) - sizeof(add), 0);
                fwrite(&add, sizeof(add), 1, file2);
            }
        }
        fclose(fp);
        fclose(file2);

        remove("books.txt");
        rename("text.txt", "books.txt");

        fp = fopen("books.txt", "rb");
        fclose(fp);
    }

    printf("press any key /..... \n");
    fflush(stdin);
    getchar();

}

void help()
{
    system("clear");

    printf("\n\n");
    printf("this is a simple library projects\n");
    printf("the password is <fahim>\n");
    printf("you can add books, edit books and delete books \n\n");
    printf("thank you very much for visiting \n\n");
}

void exitProg()
{
    system("clear");
    printf("Thank you  !!\n\n");
    printf("wait.......\n");

    sleep(2);

    exit(0);
}
