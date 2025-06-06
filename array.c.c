#include<stdio.h>
#include<conio.h>
#define N 20

//to enter element in list
void inputArray(int *a, int n) {
    int i;
    printf("Enter elements to be inserted:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}
//To traverse elements
void traverse(int *a, int n) {
    int k;
    for(k = 0; k < n; k++) {
        printf("%d\n", a[k]);
    }
}
//to insert elements
void insert(int *a, int *n, int loc, int val) {
    int i = *n;
    while(i > loc) {
        a[i] = a[i - 1];
        i--;
    }
    a[loc] = val;
    *n = *n + 1;
}
//to delete elements
void deletex(int *a, int *k, int loc, int val){
	int i;
	val = a[loc];
	i = loc;
	while(i < *k){
		a[i] = a[i + 1];
		i++;
	}
	*k = *k - 1;
}


int main() {
    int list[N];
    int loc, val, n;
    int choice;
    printf("Enter 1 to input array\n");
    printf("Enter 2 to traverse\n");
    printf("Enter 3 to insert element\n");
    printf("Enter 4 to delete an element\n");
    printf("Enter 0 to exit\n");
    scanf("%d", &choice);
    do {
        switch(choice) {
            case 1:
                printf("Enter no. of elements to be inserted: ");
                scanf("%d", &n);
                inputArray(list, n);
                break;
            case 2:
                traverse(list, n);
                break;
            case 3:
                printf("Enter location where element is to be inserted: ");
                scanf("%d", &loc);
                printf("Enter the value to be entered in list: ");
                scanf("%d", &val);
                insert(list, &n, loc, val);
                break;
            case 4:
            	printf("enter the location where element is to be deleted\n");
            	scanf("%d",&loc);
            	deletex(list , &n, loc, val);
            	break;
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while(choice != 0);
    return 0;
}
