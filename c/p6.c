//linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int usn, sem, phno;
    char name[20];
    char branch[20];
    struct node *link;
} *start;

void create(int, int, int, char[], char[]);
void disp();
void insertfront(int, int, int, char[], char[]);
void deletefront();
void insertend(int, int, int, char[], char[]);
void deleteend();

int main() {
    int ch, n, i, m, a, pos;
    int usn, sem, phno;
    char name[20], branch[20];
    start = NULL;
    
    do {
        printf("\n\nMENU\n\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT FRONT\n");
        printf("4.DELETE FRONT\n");
        printf("5.INSERT END\n");
        printf("6.DELETE END\n");
        printf("7.EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nEnter the number of students: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("\nEnter USN: ");
                    scanf("%d", &usn);
                    printf("Enter Name: ");
                    scanf("%s", name);
                    printf("Enter Branch: ");
                    scanf("%s", branch);
                    printf("Enter Semester: ");
                    scanf("%d", &sem);
                    printf("Enter Phone number: ");
                    scanf("%d", &phno);
                    create(usn, sem, phno, name, branch);
                }
                break;
            case 2:
                disp();
                break;
            case 3:
                printf("\nEnter USN: ");
                scanf("%d", &usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Branch: ");
                scanf("%s", branch);
                printf("Enter Semester: ");
                scanf("%d", &sem);
                printf("Enter Phone number: ");
                scanf("%d", &phno);
                insertfront(usn, sem, phno, name, branch);
                break;
            case 4:
                deletefront();
                break;
            case 5:
                printf("\nEnter USN: ");
                scanf("%d", &usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Branch: ");
                scanf("%s", branch);
                printf("Enter Semester: ");
                scanf("%d", &sem);
                printf("Enter Phone number: ");
                scanf("%d", &phno);
                insertend(usn, sem, phno, name, branch);
                break;
            case 6:
                deleteend();
                break;
            case 7:
                exit(0);
        }
    } while (ch != 7);

    return 0;
}

void create(int us, int se, int ph, char na[], char br[]) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->usn = us;
    tmp->sem = se;
    tmp->phno = ph;
    strcpy(tmp->name, na);
    strcpy(tmp->branch, br);
    tmp->link = NULL;
    if (start == NULL) {
        start = tmp;
    } else {
        struct node *q = start;
        while (q->link != NULL) {
            q = q->link;
        }
        q->link = tmp;
    }
}

void disp() {
    struct node *q = start;
    int count = 0;
    if (start == NULL) {
        printf("\n\nList is empty\n");
    } else {
        while (q != NULL) {
            count++;
            printf("\nUSN: %d", q->usn);
            printf("\nSEM: %d", q->sem);
            printf("\nPHNO: %d", q->phno);
            printf("\nNAME: %s", q->name);
            printf("\nBRANCH: %s\n", q->branch);
            q = q->link;
        }
        printf("\nTotal number of students = %d\n", count);
    }
}

void insertfront(int us, int se, int ph, char na[], char br[]) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->usn = us;
    tmp->sem = se;
    tmp->phno = ph;
    strcpy(tmp->name, na);
    strcpy(tmp->branch, br);
    tmp->link = start;
    start = tmp;
}

void deletefront() {
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node *tmp = start;
        start = start->link;
        free(tmp);
        printf("\nElement deleted successfully\n");
    }
}

void deleteend() {
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node *temp = start;
        struct node *t;
        if (start->link == NULL) {
            free(start);
            start = NULL;
        } else {
            while (temp->link != NULL) {
                t = temp;
                temp = temp->link;
            }
            free(t->link);
            t->link = NULL;
        }
        printf("\nElement deleted successfully\n");
    }
}
