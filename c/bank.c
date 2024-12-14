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
