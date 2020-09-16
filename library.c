#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void password();
void heading();

int main()
{
    password();
}

void heading()
{
    printf("\n\n\t**************Library Management Software*************\n\n");
    // fflush(stdin);
        getchar();

}

void password()
{
    heading();

    char pass[]= "fahim";

    char ch[10];

    printf("\tEnter Password : ");
    scanf("%s", ch);
    if (strcmp(pass, ch)==0)
    {
        printf("\n\nLog in Successfully\n\n");
        printf("press any to ..... continue\n");
    }
    else
    {
        printf("\t try again\n");
        fflush(stdin);
        getchar();
        password();
    }
    


    fflush(stdin);
    getchar();

    // main menu 

    



}