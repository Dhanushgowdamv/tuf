#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Employee Data
struct employeeData {
    int SSN;
    char name[20];
    char dept[20];
    char designation[20];
    float sal;
    char PhNo[50];
    struct employeeData *prev;
    struct employeeData *next;
};

typedef struct employeeData employee;

// Global pointers to maintain DLL
employee *first = NULL;
employee *last = NULL;

// Function to create a new node
employee* createNode(int ssn, char *name, char *dept, char *designation, float sal, char *phNo) {
    employee *newNode = (employee*)malloc(sizeof(employee));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->SSN = ssn;
    strcpy(newNode->name, name);
    strcpy(newNode->dept, dept);
    strcpy(newNode->designation, designation);
    newNode->sal = sal;
    strcpy(newNode->PhNo, phNo);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertEnd(int ssn, char *name, char *dept, char *designation, float sal, char *phNo) {
    employee *newNode = createNode(ssn, name, dept, designation, sal, phNo);
    if (first == NULL) {
        first = last = newNode;
    } else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
}

// Function to display the DLL and count the number of nodes
void displayAndCount() {
    if (first == NULL) {
        printf("DLL is empty.\n");
        return;
    }

    employee *current = first;
    int count = 0;
    printf("Employee Data in DLL:\n");
    while (current != NULL) {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone Number: %s\n",
               current->SSN, current->name, current->dept, current->designation, current->sal, current->PhNo);
        current = current->next;
        count++;
    }
    printf("Total number of employees: %d\n", count);
}

// Function to insert node at the front
void insertFront(int ssn, char *name, char *dept, char *designation, float sal, char *phNo) {
    employee *newNode = createNode(ssn, name, dept, designation, sal, phNo);
    if (first == NULL) {
        first = last = newNode;
    } else {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
}

// Function to delete node at the end
void deleteEnd() {
    if (first == NULL) {
        printf("DLL is empty. Deletion failed.\n");
        return;
    } else if (first == last) {
        free(first);
        first = last = NULL;
        printf("Node deleted successfully.\n");
        return;
    }
    employee *temp = last->prev;
    temp->next = NULL;
    free(last);
    last = temp;
    printf("Node deleted successfully.\n");
}

// Function to delete node at the front
void deleteFront() {
    if (first == NULL) {
        printf("DLL is empty. Deletion failed.\n");
        return;
    } else if (first == last) {
        free(first);
        first = last = NULL;
        printf("Node deleted successfully.\n");
        return;
    }
    employee *temp = first->next;
    temp->prev = NULL;
    free(first);
    first = temp;
    printf("Node deleted successfully.\n");
}


int main() {
    int choice, n;
    while (1) {
        printf("\nMenu\n");
        printf("1. Create a list of N Employees\n");
        printf("2. Display and Count Employees\n");
        printf("3. Insertion at End\n");
        printf("4. Insertion at Front\n");
        printf("5. Deletion from End\n");
        printf("6. Deletion from Front\n");
        printf("7. Use DLL as Double Ended Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of employees to create: ");
                scanf("%d", &n);
                // Loop to get employee details and call insertEnd()
                for (int i = 0; i < n; i++) {
                    int ssn;
                    char name[20], dept[20], designation[20], phNo[50];
                    float sal;
                    printf("Enter SSN, Name, Dept, Designation, Salary, and Phone Number: ");
                    scanf("%d %s %s %s %f %s", &ssn, name, dept, designation, &sal, phNo);
                    insertEnd(ssn, name, dept, designation, sal, phNo);
                }
                break;
            case 2:
                displayAndCount();
                break;
            case 3:
                printf("Enter employee details to insert at end:\n");
                // Get employee details and call insertEnd()
                break;
            case 4:
                printf("Enter employee details to insert at front:\n");
                // Get employee details and call insertFront()
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                demoDoubleEndedQueue();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}
