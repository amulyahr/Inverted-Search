/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#include "inverted.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int create_database(char *argv[], struct mainnode *arr[], int argc)
{
    FILE *fptr;
    char word[50];

    /* Process every input file */
    for (int i = 1; i < argc; i++)
    {
        fptr = fopen(argv[i], "r");

        if (fptr == NULL)
        {
            printf("INFO : Unable to open %s\n", argv[i]);
            continue;
        }

        /* Read word by word */
        while (fscanf(fptr, "%49s", word) == 1)
        {
            int index;

            /* Calculate hash index */
            if(isalpha(word[0]))
            {
            index = tolower(word[0]) - 'a';
            }
            else
            {
                index=26;
            }

            struct mainnode *m_temp = arr[index];

            /* Search for the word */
            while (m_temp != NULL)
            {
                if (strcmp(m_temp->word, word) == 0)
                {
                    break;
                }

                m_temp = m_temp->mlink;
            }

            /* Word does not exist */
            if (m_temp == NULL)
            {
                /* Create main node */
                struct mainnode *new_main;

                new_main = malloc(sizeof(struct mainnode));

                if (new_main == NULL)
                {
                    fclose(fptr);
                    return FAILURE;
                }

                strcpy(new_main->word, word);
                new_main->filecount = 1;
                new_main->mlink = NULL;
                new_main->slink = NULL;

                /* Create sub node */
                struct subnode *new_sub;

                new_sub = malloc(sizeof(struct subnode));

                if (new_sub == NULL)
                {
                    free(new_main);
                    fclose(fptr);
                    return FAILURE;
                }

                strcpy(new_sub->filename, argv[i]);
                new_sub->wordcount = 1;
                new_sub->slink = NULL;

                new_main->slink = new_sub;

                /* Insert main node into hash table */
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
            else
            {
                /* Word already exists */

                struct subnode *s_temp = m_temp->slink;

                /* Search for current file */
                while (s_temp != NULL)
                {
                    if (strcmp(s_temp->filename, argv[i]) == 0)
                    {
                        break;
                    }

                    s_temp = s_temp->slink;
                }

                /* Word exists in current file */
                if (s_temp != NULL)
                {
                    s_temp->wordcount++;
                }
                else
                {
                    /* Word exists but not in current file */

                    struct subnode *new_sub;

                    new_sub = malloc(sizeof(struct subnode));

                    if (new_sub == NULL)
                    {
                        fclose(fptr);
                        return FAILURE;
                    }

                    strcpy(new_sub->filename, argv[i]);
                    new_sub->wordcount = 1;
                    new_sub->slink = NULL;

                    /* Insert new subnode */
                    s_temp = m_temp->slink;

                    while (s_temp->slink != NULL)
                    {
                        s_temp = s_temp->slink;
                    }

                    s_temp->slink = new_sub;

                    /* Increase file count */
                    m_temp->filecount++;
                }
            }
        }

        fclose(fptr);
    }

    printf("INFO : Database created successfully\n");
    printf("\n");

    return SUCCESS;
}