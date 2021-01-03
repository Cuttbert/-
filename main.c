#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
    char ISBN[11];
    char author[20];
    char title[100];
    int year;
    int pages;
};

struct book str2book(char* s)
{
    char *p = strtok(s,"*");
    struct book tmp;

    strcpy(tmp.ISBN,p);

    p = strtok(NULL,"*");
    strcpy(tmp.author,p);

    p = strtok(NULL,"*");
    strcpy(tmp.title,p);

    p = strtok(NULL,"*");
    tmp.year = atoi(p);

    p = strtok(NULL,"*");
    tmp.pages = atoi(p);

    return tmp;
};

void printbook(struct book b)
{
    printf("ISBN: %s\n",b.ISBN);
    printf("Author: %s\n",b.author);
    printf("Title: %s\n",b.title);
    printf("Year: %i\n",b.year);
    printf("Pages: %i\n\n",b.pages);

};

int main()
{
    FILE *fp;
    char str[256];

    if ((fp=fopen("lib.txt", "r") )==NULL)
    {
        printf("Cannot open file.\n");
        exit (1);
    }
    while(!feof (fp))
    {
        if (fgets(str, 256, fp))
        {
            struct book bk = str2book(str);
            if (strstr(bk.title,"C "))
                printbook(bk);
        }
    }
    fclose(fp);
    return 0;
};
