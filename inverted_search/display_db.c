/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#include"inverted.h"
#include<stdio.h>
void display_database(struct mainnode *arr[])
{
    struct mainnode *m_temp;
    struct subnode *s_temp;

    for(int i=0;i<27;i++)
    {
        m_temp=arr[i];
        while(m_temp!=NULL)
        {
            printf("[%d] %s %d ",i,m_temp->word,m_temp->filecount);
            s_temp=m_temp->slink;

            while(s_temp!=NULL)
            {
                printf(" %s %d",s_temp->filename,s_temp->wordcount);
                s_temp=s_temp->slink;
            }
            printf("\n");
            m_temp=m_temp->mlink;
        }
    }
    printf("\n");
}