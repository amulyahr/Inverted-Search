/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#include"inverted.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int choice;
    Slist *head=NULL;
    struct mainnode *arr[27]={NULL};
    if(argc<2)
    {
        printf("Usage: ./a.out file1.txt file2.txt ...\n");
        return FAILURE;
    }
    do
    {
        printf("1.Create Database\n");
        printf("2.Display Database\n");
        printf("3.Search Database\n");
        printf("4.save Datebase\n");
        printf("5.Update Database\n");
        printf("6.EXIT\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
            while (getchar() != '\n');
        switch (choice) 
        {
            case 1:
                create_database(argv,arr,argc);
                break;

            case 2:
                display_database(arr);
                break;

            case 3:
                search_database(arr);
                break;

            case 4:
                save_database(arr);
                break;

            case 5:          
                update_database(arr);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
    }

}while (choice != 6);
return SUCCESS;
}