#include <stdio.h>
#define N 20

void inputArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }
}

void traverse(int *a, int n) {
    for (int k = 0; k < n; k++) {
        printf("%d\n", a[k]);
    }
}

void insert(int *a, int *n, int loc, int val) {
    if (*n >= N || loc < 0 || loc > *n) {
        printf("Invalid location or array full.\n");
        return;
    }
    for (int i = *n; i > loc; i--) {
        a[i] = a[i - 1];
    }
    a[loc] = val;
    (*n)++;
}

void deletex(int *a, int *n, int loc) {
    if (*n <= 0 || loc < 0 || loc >= *n) {
        printf("Invalid location or array empty.\n");
        return;
    }
    for (int i = loc; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

int main() {
    int list[N];
    int loc, val, n = 0;
    int choice;
    do {
        printf("Enter 1 to input array\n");
        printf("Enter 2 to traverse\n");
        printf("Enter 3 to insert element\n");
        printf("Enter 4 to delete an element\n");
        printf("Enter 0 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter no. of elements to be inserted: ");
                scanf("%d", &n);
                if (n > N) {
                    printf("Maximum allowed is %d.\n", N);
                    n = N;
                }
                inputArray(list, n);
                break;
            case 2:
                traverse(list, n);
                break;
            case 3:
                printf("Enter location (0-%d): ", n);
                scanf("%d", &loc);
                printf("Enter the value: ");
                scanf("%d", &val);
                insert(list, &n, loc, val);
                break;
            case 4:
                printf("Enter location to delete (0-%d): ", n - 1);
                scanf("%d", &loc);
                deletex(list, &n, loc);
                break;
        }
    } while (choice != 0);
    return 0;
}

