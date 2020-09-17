#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void password();
void heading();
void mainMenu();

int count = 1;

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

    getchar();
}