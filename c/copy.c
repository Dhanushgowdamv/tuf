
//this program regarding about the banking transction finanicial mangament
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int i,j;
int main_exit;
void closed();
void fordelay(int j);
void menu();
void newacc();
void edit();
void transcat();
void see();
void erase();
void viewlist();

struct date{
    int month,day,year;

}
struct {
    char name[60];
    int accno,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acctype[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
}add,upd,cheak,rem,transaction;

unsigned int sec=0;
clock_t stopclock =CLOCK_PER_SEC;

//main drive code
void main(){
    char pass[15],password[15]="dhanush@";
    int i=0;
    printf("\n\n\t enter the password to login:");
    printf("\033[8m");
    scanf("%s",pass);
    printf("\033c");
    if(strcmp(pass,password)==0){
        printf("\n\n password match! Loading");
        sysytem("clear");
        fordelay(5);
        menu();
    }
    printf("\033c");
    printf("\n\n wrong password !!!");
    login_try:
    printf("\n Enter the 1 to try again and 0 to exit:");
    scanf("%d",&main_exit);
    if(main_exit==1)
    {
        system("clear");
        main();

    }
    else if(main_exit==0)
    {
        closed();
    }
}
}

void menu(){
    int choice;
    printf("\033c");
    system("clear");
    printf("\n");
    printf("\33[1;31m");
    printf("\n\n\t\t\t CUSTOMER ACCOUNT BANKING MANAGEMENT");
    printf("\n\n\\t\t      \033[1;32m WELCOME TO THE MENU");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\n\n\t\t 1.Create new account \n\t2.update information of the existing account \n\t3.For transation\n\t4.cheak the details existing account \n\t5.Remove the existing account \n\t6.view custmer list\n\t7.exit\n\n\n\t\t Enter the choice :  ");
    scanf("%d",&choice);
    system("clear");
    printf("\033c");
    switch (choice)
    {
    case 1:newacc();
        /* code */
        break;
    case 2:edit();
        /* code */
        break;
    case 3:transcat();
          break;
    case 4:see();
          break;
    case 5:erase();
          break;
    case 6:viewlist();
          break;
    case 7:exit(0);
          break;
    default:
        break;
    }
}
void fordelay(int j)
{
    while(sec<j)
    {
    if(clock()>stopclock)
    {
    stopclock+=1000000;
    printf(".");
    fflush(stdout);
    sec++;

    }
    }

}

//creating a new account
void newacc() 
{
    FILE *ptr;  // Corrected FILE type declaration
    ptr = fopen("record.dat", "a+");
    system("clear");
    printf("\t\t\t  ADD RECORD ");
    printf("\n\n Enter today date (mm/dd/yyyy) :");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);

    printf("Enter the account number :");

    while (fscanf(ptr, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 
    {
        if (cheak.accno == add.accno) 
        {
            printf("Account no. already in use!");
            fclose(ptr);
            goto add_invalid;
        }
    }

    add.accno = cheak.accno;
    printf("\n Enter the name:");
    scanf("%s", add.name);
    printf("\n Enter the date of birth (mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\n Enter the age:");
    scanf("%d", &add.age);
    printf("\n Enter the address:");
    scanf("%s", add.address);
    printf("\n Enter the citizenship number:");
    scanf("%s", add.citizenship);
    printf("\n Enter the phone number:");
    scanf("%lf", &add.phone);
    printf("\n Type of account:\n\t #Saving \n\t #Current \n\t #Fixed (for 1 year)\n\t #Fixed 2(for 2 years) \n\t#Fixed 3(for 3 years) :\n");
    scanf("%s", add.acctype);

    fprintf(ptr, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\n Account created successfully!");

add_invalid:
    printf("\n\n\n\t Enter 1 to go to the main menu and '0' to exit \n");
    scanf("%d", &main_exit);
    system("clear");

    if (main_exit == 1) 
    {
        menu();
    } 
    else if (main_exit == 0) 
    {
        closed();
    } 
    else 
    {
        printf("\n Invalid input!");
        goto add_invalid;
    }
}

//in this function use to edit the personal details

void edit()
 {
    int choice, test = 0;
    FILE *old, *newrec;
    // Corrected variable declaration
    int upd_accno;
    old = fopen("record.dat", "r");
    newrec = fopen("newdata.dat", "w");
    printf("\n enter the account no of the customer whose data want to edit\n");
    scanf("%d", &upd_accno);

    while (fscanf(old, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n ", &add.accno, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) {
        // Removed unnecessary semicolon
        if (add.accno == upd_accno)
         {
            test = 1;
            printf("\n which information want to change ??:\n 1. address \n 2. phone number\n\n Enter your choice: \n");
            scanf("%d", &choice);
            system("clear");
            if (choice == 1) 
            {
                printf("Enter the Address :");
                scanf("%s", upd.address);
                // Corrected fprintf statement
                fprintf(newrec, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, &add.dob.day, &add.dob.year, &add.age, upd.address, add.citizenship, add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
                system("clear");
                printf("changes saved !");
            } 
            else if (choice == 2) 
            {
                printf("enter the new number :");
                scanf("%lf", &upd.phone);
                // Corrected fprintf statement
                fprintf(newrec, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &upd.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
                system("clear");
                printf("change saved !!");
            } 
            else
             {
                // Corrected fprintf statement
                fprintf(newrec, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
            }
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    // Corrected file name in rename function
    rename("newdata.dat", "record.dat");

    if (test != 1) {
        system("clear");
        printf("\n the new record is not found !!!!");
        edit_Invalid:
        printf("\n Enter the 0 to try again 1 to return to the main menu\n");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1) {
            menu();
        } else if (main_exit == 2) {
            closed();
        } else {
            printf("\n Invalid ");
            goto edit_Invalid;
        }
    } else {
        printf("\n\n\n Enter the 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1) {
            menu();
        } else {
            closed();
        }
    }
}

//this function is used to tarcking the transation history
void transcat()
{
    int choice,test=0;
    FILE*old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the accuncount no.of the costomer :");
    scanf("%d",&transaction.accno);
        while (fscanf(old, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 
{
    if(add.accno==transaction.accno)
    {
        test =1;
        if(strcmp(add.acctype,"fixed1")==0||strcmp(add.acctype,"fixed2")==0||strcmp(add.acctype,"fixed3")==0)
        {
            printf("you cannot deposit or withdraw the cash in th efixed account\n");
            syatem("clear");
            menu();
        }
        printf("\n\n Do you want to\n1.deposit\n2.withdraw\n3");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n Wenter the amounr you want to deposit : $$\n");
            scanf("%f",&transaction.amt);
            add.amt+=transaction.amt;
            fprintf(newrec, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, &add.dob.day, &add.dob.year, &add.age, upd.address, add.citizenship, add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
            printf("\n\n the amount deposited is successfully !!");

        }
     else if(choice==2)
     {
        printf("\n Enter the amount you want to withdraw from the account \n");
        scanf("%d",&transaction.amt);
        add.amt-=transaction.amt;
        fprintf(newrec, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, &add.dob.day, &add.dob.year, &add.age, upd.address, add.citizenship, add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
        printf("\n\n the amount is sucessfully withdraw");
     }
    }
    else
    {
        fprintf(newrec, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, &add.dob.day, &add.dob.year, &add.age, upd.address, add.citizenship, add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
        
    }

}
fclose(old);
fclose(newrec);
remove("record.dat");
rename("newdata.dat", "record.dat");

if(test!=1)
{
    printf("\n\n Record not found !!");
    transcat_invalid;
    printf("\n\n\n Enter 0 or try again 1 to return the main menu and 2 exit('0) \n");
    scanf("%d",&main_exit);
    system("clear");
    if(main_exit==0)
    {
        transcat();
    }
    else if(main_exit==1)
    {
        menu();
    }
    else if(main_exit==2)
    {
        closed();
    }
    else{
        printf("\n Invalid !!");
        goto transcat_invalid;
    }
}
else
{
    printf("\n Enter the 1 to go to the main menu and 0 to exit :");
    scanf("%d",&main_exit);
    system("clear");
    if(main_exit==1)
    {
        menu();

    }
    else if(main_exit==0)
    {
        closed()
    }
  }
}

//cheak the existency of the account in the bank
void see()
{
FILE *ptr;
int test=0,rate;
int choice;
float time;
float intrst;
ptr=fopen("record.dat","r");
printf("do you want to cheak by \n1.Account no\n2.Name \n enter the choice: !!");
scanf("%d",&choice);
if(choice==1)
{
    printf("Enter the account number :");
    scanf("%d",&check.accno);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 
     {
     if(add.accno==check.accno)
{
    system("clear");
    test=1;
    printf("\n Account no. :%d \n Name :%s \n DOB:%d%d%d \n Age: %d\n Address: %d\n citizenship NO: %s \n Phone Number:%.0lf\n type of the account :%d \n Account deposited : $%.2f\n Date of Deposit :%d/`ud/%d \n\n  ",&add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
    if(strcmp(add.acc_type,"fixed1"==0)||strcmp(add.acc_type,"fixed2"==0)||strcmp(add.acc_type,"fixed3"==0))
    {
        printf("\n\n you will not get any interest  ")
      }
    }
  }
}
else if(choice==2)
{
    printf("\n enter tghe name :");
    scanf("%s",&cheak.name);
     while (fscanf(ptr, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 
{
    if(strcmp(add.name,check.name)==0)
    {
        system("clear");
        test=1;
            printf("\n Account no. :%d \n Name :%s \n DOB:%d%d%d \n Age: %d\n Address: %d\n citizenship NO: %s \n Phone Number:%.0lf\n type of the account :%d \n Account deposited : $%.2f\n Date of Deposit :%d/`ud/%d \n\n  ",&add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);

        if(strcmp(add.acc_type,"fixed1"==0)||strcmp(add.acc_type,"fixed2"==0)||strcmp(add.acc_type,"fixed3"==0))
    {
        printf("\n\n you will not get any interest  ")
      }

    }
}
}
fclose(ptr);
if(test!=1)
{
    system("clear");
    printf("\n record not found !! ");
    see_invalid :
    printf("\n Enter the 0 to try again ,1 returmn to the main menu adm 2 to exit(): \n");
    scanf("%d",&main_exit);
    system("clear");
    if(main_exit==1)
    {
        menu();
    }
    else if(main_exit==2)
    {
        closed();
    }
    else if(main_exit==0)
    {
        see();
    }
    else{
          system("clear");
          printf("\n Invalid !! ");
          goto see_invalid ;
    }

}
else
{
    printf("\n Enter 1 to go to the main menu and 0 exit(0) \n ");
    scanf("%d",&main_exit);
}
if(main_exit==1)
{
  system("clear");
  menu();
}
else
{
    system("clear");
    closed();

}
}


//erase function for the replacement the record newlyadded
void erase ()
{
    __FILE__*old *newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no of the custmer you wnat to erase\n");
    scanf("%d",&rem.accno);
         while (fscanf(old, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 
    {
        if(add.accno!=rem.accno)
        {
                 fprintf(newrec "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 

        }
        else
        {
            test++;
            pritnf("\n record deleted sucessfully!\n\n")
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
    {
        printf("\n remove not found!!\n\n");
        erase_invalid:
        printf("\n Enter the 0to try again  1 to go to the mainmenu");
        scanf("%d",&main_exit);
        if(main_exit==1)
        {
            menu();

        }
        else if(main_exit==2)
        {
            closed();
        }
        else if(main_exit==0)
        {
            erase();

        }
        else
        {
            printf("\n Invalid !!\n");
            goto erase_invalid:

        }
        }
        else
        {
            printf("\n Enter the 1 to go the main menu and 0 to exit :");
            scanf("%d",&main_exit);
            system("clear");
            if(main_exit==1)
            {
                menu();

            }
            else
            {
              closed();
        }
    }
}

// viewing the list
void viewlist()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    syatem("clear");
    printf("\n ACC.number\t NAME\t\tADDRESS\t\tPHONE NUMBER\t");
          while (fscanf(view, "%d %s %d/%d/%d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) 
    {
        printf("\n%6d\t %s\t\t %s\t\t %.0lf",add.accno,add.name,add.address,add.phone);
        test++;

    }
    fclose(view);
    if(test==0)
    {
        syatem("clear");
        printf("\n NO RECORDS!!\n");

    }
    viewlist_invalid:
    printf(("\n\n Enter teh 1 to go to the main menu and 0 to exit"));
    scanf("%d",&main_exit);
    system("clear");
    if(main_exit==1){
        menu();
    }
    else if(main_exit==0){
        closed();
    }
    else{
        printf("\n INvalid!\n");
        goto viewlist_invalid;

    }
}

void closed(){
    syatem("clear");
    printf("\n\n===this is a mini Project developed by the Dhanush v and DhanushGowda mv====");
}