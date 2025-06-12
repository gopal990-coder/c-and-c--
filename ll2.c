//linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
};
//creating node as global variable
typedef struct node Node;
//Insert node at beggining
void insertbeg(Node **start, int val)
{
	Node *ptr = (Node *)malloc(sizeof(Node));
	if(ptr == NULL)
	{
		printf("memory allocation error");
		return;
	}
	ptr -> info = val;
	ptr -> link = *start;
	*start = ptr;
}
//Traverse link list
void traversell(Node *start) 
{
    Node *ptr;
    for(ptr = start; ptr != NULL; ptr = ptr->link) 
	{
        printf("%d ", ptr->info);
    }
    printf("\n");
}
//Delete link list node at beginning
void deletebeg(Node **start)
{
	Node *ptr;
	if(*start == NULL)
	{
	    printf("list is empty\n");
	    return;
	}
	ptr = *start;
	*start = ptr -> link;
	free(ptr);
}
//To search element in ll
Node *finda(Node *start, int val)
{
		Node *loc = NULL;
		Node *ptr;
		if(start == NULL)
		{
			printf("list is empty");
			return loc;
		}
		ptr = start;
		while(ptr != NULL)
		{
			if(ptr -> info == val)
			{
				loc = ptr;
                break;			
			}
		ptr = ptr -> link;
		}
	return loc;
}
//Insert after any node
void insertafter(Node **start, int val, int x)
{
	Node *new = (Node *)malloc(sizeof(Node));
	if(new == NULL)
	{
		printf("memory allocation error\n");
		return;
	}
	new -> info = x;
	Node *loc = finda(*start, val);
	if(loc != NULL)
	{
		new -> link = loc -> link;
		loc -> link = new;
	}
	else
	{
		new -> link = *start;
		*start = new;
	}
}
//Delete after any node
void deleteafter(Node **start,int val)
{
	if(*start == NULL)
	{
		printf("list is empty\n");
		return;
	}
	Node *loc = finda(*start, val);
	if(loc != NULL)
	{
	    Node *ptr = loc -> link;
		if(ptr != NULL)
	    {
			loc -> link = ptr -> link;
			free(ptr);
			printf("node deleted\n");
		}
		else
		{
			printf("no node to to delete after\n");
		}		
	} 
	else 
	{
        printf("Node with value %d not found\n", val);
    }
}
void main()
{
	Node *start = NULL;
	int val, insert;
	int choice;
	printf("enter 1 to insert a node at the beginning\n");
	printf("enter 2 to traverse a linked list\n");
	printf("enter 3 to delete a node from linked list\n");
	printf("enter 4 to search a value \n");
	printf("enter 5 to insert after any node\n");
	printf("enter 6 to delete after any node\n");
	printf("enter 0 to exit\n");
	printf("enter choice ");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
		case 1:
			printf("enter any number to insert it in the beggining of node ");
			scanf("%d",&val);
			insertbeg(&start, val);
			break;
		case 2:
            traversell(start);
            break;
        case 3:
        	deletebeg(&start);
            break;
        case 4:
        	printf("Enter the value to be searched: ");
            scanf("%d", &val);
            Node *loc = finda(start, val);
            if (loc != NULL) {
                printf("Node found with value %d\n", loc->info);
            }
            else {
                printf("Node not found\n");
            }
            break;
        case 5:
        	printf("enter value to insert after\n");
        	scanf("%d",&val);
        	printf("Enter the value to insert: ");
            scanf("%d", &insert);
            insertafter(&start, val, insert);
            break;
        case 6:
        	printf("enter value to delete after\n");
        	scanf("%d",&val);
        	deleteafter(&start, val);
        	break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    printf("\nenter choice ");
	scanf("%d",&choice);	
	}while(choice!=0);	
}
