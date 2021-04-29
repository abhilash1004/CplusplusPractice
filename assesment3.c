#include<stdio.h>
struct book
{
    char title[20];
    char author[20];
    int pages;
    float price;
};

int main()
{
    struct book b[100];
    int n,i;
    printf("Enter number of books\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        printf("Enter the details of %d th book \n",i+1);
        printf("enter the title of book\n");
        gets(b[i].title);
        printf("enter the authors name\n");
        gets(b[i].author);
        printf("Enter the no of pages\n");
        scanf("%d",&b[i].pages);
        printf("Enter the price of book\n");
        scanf("%f",&b[i].price);
    }
    printf("Details of the books\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t",b[i].title);
        printf("%s\t",b[i].author);
        printf("%d\t",b[i].pages);
        printf("%f\n",b[i].price);
    }
    return 0;
}
