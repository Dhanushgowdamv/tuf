//worst fit
#include <stdio.h>
#include <conio.h>

void main() {
    char job[10][10];
    int time[10], avail, tem[10], temp[10];
    int safe[10];
    int ind = 1, i, j, q, n, t;
    
    clrscr();
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter name and time for job %d: ", i + 1);
        scanf("%s%d", &job[i], &time[i]);
    }
    
    printf("Enter the available resources: ");
    scanf("%d", &avail);
    
    for (i = 0; i < n; i++) {
        temp[i] = time[i];
        tem[i] = i;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;
            }
        }
    }

    printf("Safe sequence is: ");
    for (i = 0; i < n; i++) {
        q = tem[i];
        if (time[q] <= avail) {
            safe[ind] = tem[i];
            avail = avail - time[q];
            printf("%s ", job[safe[ind]]);
            ind++;
        } else {
            printf("No safe sequence\n");
            break;
        }
    }

    printf("\n");
    getch();
}


//single level directry
#include<stdio.h>
#include<string.h>

struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir;

void main() {
    int i, ch;
    char f[30];
    clrscr();
    dir.fcnt = 0;
    
    printf("\nEnter name of directory -- ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n\n1. CreateFile\t2. DeleteFile\t3. SearchFile\n4. Display Files\t5. Exit\nEnter your choice -- ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the name of the file -- ");
                scanf("%s", dir.fname[dir.fcnt]);
                dir.fcnt++;
                break;

            case 2:
                printf("\nEnter the name of the file -- ");
                scanf("%s", f);
                
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s is deleted", f);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                        break;
                    }
                }

                if (i == dir.fcnt)
                    printf("File %s not found", f);
                else
                    dir.fcnt--;

                break;

            case 3:
                printf("\nEnter the name of the file -- ");
                scanf("%s", f);

                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s is found", f);
                        break;
                    }
                }

                if (i == dir.fcnt)
                    printf("File %s not found", f);
                break;

            case 4:
                if (dir.fcnt == 0)
                    printf("\nDirectory Empty");
                else {
                    printf("\nThe Files are -- ");
                    for (i = 0; i < dir.fcnt; i++)
                        printf("\t %s", dir.fname[i]);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice");
        }

        getch();
    }
}
