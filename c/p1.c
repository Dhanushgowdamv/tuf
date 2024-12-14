#include<stdio.h>
#include<stdlib.h>
#include<string.>
#include<ctype.h>
#define MAX 7
typedef struct{
char*dayname;
int*date;
char*activity;
} daytype;

void fnread(daytype*);
void fndisp(daytype*);
void fnfree(daytype*);
daytype*fncreatecal();

int main(){
daytype*weekcal=fncreatecal();
fnread(weelcal);
fndisp(weekcal);
fnfree(weekcal);
return 0;
}
//create the

daytype=fncreatecal(){
daytype*calender=(daytype*)malloc(MAX*sizeof(daytype);
for(int i=0;i<=MAX;i++){
  calender[i].dayname=NULL;
  calender[i].date=0;
  calender[i].activty=NULL;

}
return calender;
}

//read from the calender
void read(daytype*calender){
char ch;
for(int i=0;i<MAX;i++){
    printf("do you want to ente yhe details ofth %d[Y/N]",i+1);
    scanf("%c",&ch);
    getchar();

    if(tolower(ch)=='n')
        continue;

    //this is for day name
    printf("dayname:");
    char namebuf[50];
    scanf("%s",namebuf);
    calender[i].dayname=strdup(namebuf);

    //this is for date
    printf("date");
    scanf"%d",&calender[i].date);

    //this is for the activity
    printf("activity");
    char activitybuf[100];
    scanf("s",activitybuf);
    calender[i].activity=strdup(activitybuf);
    printf("n");
    getchar();
}

}

//display function
void fndisp(daytype*calender)
{

    printf("n week activity");
    for(int i=0;i<MAX;i++){
        printf("day %d:n",i+1);
        if(calender[i].date==0){
            printf("no activity n");
            continue;

        }
        printf("dayname:%sn",calender[i],dayname);
        printf("date:%dn",calender[i],date);
        printf("dayname:%sn",calender[i],activity);
    }
}

//free the unused memory
void free(daytype*calender){
for(int i=0;i<MAX;i++){
free(calender[i].dayname);
free(calender[i].activity);
}
free(calender);
}
