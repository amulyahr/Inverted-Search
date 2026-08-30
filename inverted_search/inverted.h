/*Name :AISHWARYA H S
Project name: Inverted Search
ID:int26001_053*/

#ifndef INVERTED_H
#define INVERTED_H

#define SUCCESS 0
#define FAILURE -1

typedef struct mainnode
{
	char word[50];
    int filecount;
    struct mainnode *mlink;
    struct subnode *slink;
}mnode;
typedef struct subnode
{
	int wordcount;
    char filename[100];
    struct subnode *slink;
}snode;
typedef struct hashtable
{
    char filename[100];
    struct hashtable *link;
}Slist;
int create_database(char *argv[], struct mainnode *arr[], int argc);
void display_database(struct mainnode *arr[]);
int search_database(struct mainnode *arr[]);
int save_database(struct mainnode *arr[]);
int update_database(struct mainnode *arr[]);
#endif
