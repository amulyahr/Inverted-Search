/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#include"inverted.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int search_database(struct mainnode *arr[])
{
     char word[50];
    int index;

    printf("Enter the word to search: ");
    scanf("%49s", word);

    /* Find hash index using first character */
      if (isalpha((unsigned char)word[0]))
    {
        index = tolower((unsigned char)word[0]) - 'a';
    }
    else
    {
        index = 26;
    }

    struct mainnode *m_temp = arr[index];

    /* Search the word in main node */
    while (m_temp != NULL)
    {
        if (strcmp(m_temp->word, word) == 0)
        {
            struct subnode *s_temp = m_temp->slink;

            /* Print file name and word count */
            while (s_temp != NULL)
            {
                printf("Word %s is present %d times in %s\n",
                       m_temp->word,
                       s_temp->wordcount,
                       s_temp->filename);

                s_temp = s_temp->slink;
            }
            printf("\n");

            return SUCCESS;
        }

        m_temp = m_temp->mlink;
    }
    printf("Word %s is not present in the database\n", word);
    printf("\n");

    return FAILURE;
}