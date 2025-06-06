#include<stdio.h>
#include<conio.h>
#define N 20

typedef struct node 
{
    int info;
    struct node *link;
} node;

void link(struct node *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
	{
        printf("%d -> ", a[i].info);
    }
    printf("NULL\n");
}
void traverse(node *start)
{
	node *ptr = start;
	while(ptr != NULL)
	{
		printf("\n%d ->",ptr -> info);
		ptr = ptr -> link;
	}
}
void main()
{
    struct node list[N];
    int n, i, choice;
    printf("enter 1 to create a link list\n");
    printf("enter 2 to traverse a link\n");
    printf("enter 3 to insert a node in linked list\n");
    printf("enter 0 to exit\n");
    scanf("%d",&choice);
	do{
    	switch(choice)
    	{
    	case 1:
	    printf("Enter the number of elements in the list: \n");
            scanf("%d", &n);
            printf("Enter the elements: \n");
            for(i = 0; i < n; i++) 
	    {
               scanf("%d", &list[i].info);
               list[i].link = NULL; // Initialize link to NULL
            }
            printf("Linked List: \n");
            link(list, n);
            break;
        case 2:
            traverse(list);
            break;
        default:
            printf("invalid choice");
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
      }while(choice!=0);
}

