/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#include "inverted.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int update_database(struct mainnode *arr[])
{
    FILE *fptr;
    char ch;

    char word[50];
    char filename[100];

    int index;
    int filecount;
    int wordcount;

    fptr = fopen("f1.txt", "r");

    if (fptr == NULL)
    {
        printf("INFO : Database file not found\n");
        return FAILURE;
    }

    while (fscanf(fptr, "#%d;%49[^;];%d;",
                  &index, word, &filecount) == 3)
    {
        struct mainnode *m_temp;
        struct mainnode *new_main;

        /* Create main node */
        new_main = malloc(sizeof(struct mainnode));

        if (new_main == NULL)
        {
            fclose(fptr);
            return FAILURE;
        }

        strcpy(new_main->word, word);
        new_main->filecount = filecount;
        new_main->mlink = NULL;
        new_main->slink = NULL;

        for (int i = 0; i < filecount; i++)
        {
            if (fscanf(fptr, "#%d;%99[^;];%d;",
                       &index, filename, &wordcount) != 3)
            {
                free(new_main);
                fclose(fptr);
                return FAILURE;
            }

            struct subnode *new_sub;
            struct subnode *s_temp;

            new_sub = malloc(sizeof(struct subnode));

            if (new_sub == NULL)
            {
                free(new_main);
                fclose(fptr);
                return FAILURE;
            }

            strcpy(new_sub->filename, filename);
            new_sub->wordcount = wordcount;
            new_sub->slink = NULL;

            /* Insert subnode */
            if (new_main->slink == NULL)
            {
                new_main->slink = new_sub;
            }
            else
            {
                s_temp = new_main->slink;

                while (s_temp->slink != NULL)
                {
                    s_temp = s_temp->slink;
                }

                s_temp->slink = new_sub;
            }
        }

        /* Insert mainnode into hash table */
        if (arr[index] == NULL)
        {
            arr[index] = new_main;
        }
        else
        {
            m_temp = arr[index];

            while (m_temp->mlink != NULL)
            {
                m_temp = m_temp->mlink;
            }

            m_temp->mlink = new_main;
        }
    }

    fclose(fptr);

    printf("INFO : Database updated successfully\n");
    printf("\n");

    return SUCCESS;
}