/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#include"inverted.h"
#include<stdio.h>
int save_database(struct mainnode *arr[])
{
    FILE *fptr;
    fptr=fopen("update.txt","w");
    if(fptr==NULL)
    return FAILURE;

    struct mainnode *mainnode;
    struct subnode *subnode;

    for(int i=0;i<27;i++)
    {
        mainnode=arr[i];
        while(mainnode!=NULL)
        {
           fprintf(fptr, "#%d;%s;%d;",i,mainnode->word,mainnode->filecount);

            subnode=mainnode->slink;

            while(subnode!=NULL)
            {
                fprintf(fptr, "%s;%d;",subnode->filename,subnode->wordcount);
                subnode=subnode->slink;
            }
              fprintf(fptr, "#\n");
            mainnode=mainnode->mlink;
        }
    }
    fclose(fptr);
    printf("INFO : Data saved successfully\n");
    printf("\n");
    return SUCCESS;
}