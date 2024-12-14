/******************************************************************************

                           This project about the.
                 BANKING SYSTEM (or) FINANCIL MANAGEMENT.
In this code i am using the file handling,structure,pointer,password protection 
data handling , functions ,i am use the json to store the custmer details

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main_exit;

float intrstcalculation(float t, float *amt, int r);

struct date {
    int month, day, year;
};
//structure to made 
struct {
    char name[60];
    int accno, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acctype[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add, upd, cheak, rem, transaction;

unsigned int sec = 0;
clock_t stopclock = CLOCKS_PER_SEC;

// Function prototypes
void closed();
void fordelay(int j);
void menu();
void newacc();
void edit();
void transact();
void see();
void erase();
void viewlist();
float intrstcalculation(float t, float *amt, int r);

// this is the main code to drive the code
int main() 
{
    char pass[15], password[15] = "dhanush@";
    int i = 0;
    printf("\n\n\tEnter the password to login:");
    scanf("%s", pass);
    if (strcmp(pass, password) == 0) 
    {
        printf("\n\nPassword match! Loading");
        sleep(2);
        menu();
    }
     else 
    {
        printf("\n\nWrong password !!!");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1) 
        {
            system("clear");
            main();
        } 
        else if (main_exit == 0)
         {
            closed();
        } 
        else 
        {
            printf("\nInvalid input!");
            goto login_try;
        }
    }
    return 0;
}
//the main menu used to choice that on which area to work
void menu() 
{
    int choice;
    printf("\033c");
    printf("\n\33[1;31m");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT");
    printf("\n\n\t\t\033[1;32mWELCOME TO THE MENU");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\n\t1.Create new account \n\t2.Update information of the existing account \n\t3.For transaction\n\t4.Check the details of an existing account \n\t5.Remove the existing account \n\t6.View customer list\n\t7.Exit\n\n\n\t\tEnter the choice:  ");
    scanf("%d", &choice);
    printf("\033c");
    switch (choice) 
    {
        case 1:
            newacc();
            break;
        case 2:
            edit();
            break;
        case 3:
            transact();
            break;
        case 4:
            see();
            break;
        case 5:
            erase();
            break;
        case 6:
            viewlist();
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
    }
}
//set the delay time because of the not to loss the data
void fordelay(int j)
 {
    while (sec < j) 
    {
        if (clock() > stopclock) 
        {
            stopclock += 100000;
            sec++;
        }
    }
}
//creating the new account 
void newacc()
 {
    FILE *ptr;
    ptr = fopen("record.dat", "a+");
    system("clear");
    printf("\t\t\t  ADD RECORD ");
    printf("\n\nEnter today's date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);

   printf("Enter the account number:");
   scanf("%d",&add.accno);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &cheak.accno, &cheak.name, &cheak.dob.month, &cheak.dob.day, &cheak.dob.year, &cheak.age, &cheak.address, &cheak.citizenship, &cheak.phone, &cheak.acctype, &cheak.amt, &cheak.deposit.month, &cheak.deposit.day, &cheak.deposit.year) != EOF) {
        if (cheak.accno == add.accno) 
        {
            printf("Account no. already in use!");
            fclose(ptr);
            goto add_invalid;
        
        }
    }
//cheack wheather the account number is pre existed
    add.accno = cheak.accno;
    printf("\nEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth (mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the address:");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s", add.citizenship);
    printf("\nEnter the phone number:");
    scanf("%lf", &add.phone);
    printf("\nType of account:\n\t #Saving \n\t #Current \n\t #Fixed (for 1 year)\n\t #Fixed 2(for 2 years) \n\t#Fixed 3(for 3 years) :\n");
    scanf("%s", add.acctype);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");

add_invalid:
    printf("\n\n\nEnter 1 to go to the main menu and '0' to exit \n");
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
        printf("\nInvalid input!");
        goto add_invalid;
    }
}
// edir function to edit some data in the pre exiting account
void edit() 
{
    int choice, test = 0;
    FILE *old, *newrec;
    int upd_accno;//this variable used to update the edited data
    old = fopen("record.dat", "r");
    newrec = fopen("newdata.dat", "w");
    printf("\nEnter the account no of the customer whose data you want to edit\n");
    scanf("%d", &upd_accno);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) {
        if (add.accno == upd_accno) 
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1. Address \n2. Phone\n\nEnter your choice\n");
            scanf("%d", &choice);

            if (choice == 1) 
            {
                printf("Enter the new address:");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("Changes saved!");
            } 
            else if (choice == 2) 
            {
                printf("Enter the new phone number:");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("Changes saved!");
            }
        }
         else 
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    fclose(old);          
    fclose(newrec);
                              //replaces the data old to newrec
    remove("record.dat");
    rename("newdata.dat", "record.dat");

    if (test != 1)
     {
        printf("\nRecord not found!!");
    edit_invalid:
        printf("\nEnter 0 to try again, 1 to return to the main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1) 
        {
            menu();
        } 
        else if (main_exit == 2) 
        {
            closed();
        } else if (main_exit == 0)
         {
            edit();
        } 
        else 
        {
            printf("\nInvalid!");
            goto edit_invalid;
        }
    } 
    else 
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);

        if (main_exit == 1) 
        {
            system("clear");
            menu();
        } 
        else 
        {
            closed();
        }
    }
}
//transation function use to track the account transaction details 
void transact() 
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("newdata.dat", "w");
    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.accno);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) {
        if (add.accno == transaction.accno)
         {
            test = 1;
            printf("\n\nWhich transaction would you like to do?\n1.Deposit\n2.Withdrawal\n\nEnter your choice:");
            scanf("%d", &choice);
//enter the choice 1 to deposit e the money
            if (choice == 1) 
            {
                printf("Enter the amount you want to deposit:$");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("Deposited successfully!");
            } 
            else 
            {
                printf("Enter the amount you want to withdraw:$");
                scanf("%f", &transaction.amt);

                if (transaction.amt > add.amt)
                 {
                    printf("Insufficient balance!");
                } 
                else 
                {
                    add.amt -= transaction.amt;
                    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                    printf("Withdrawn successfully!");
                }
            }
        } 
        else
         {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);

    remove("record.dat");
    rename("newdata.dat", "record.dat");

    if (test != 1)
    
     {
        printf("\nRecord not found!!");
    transact_invalid:
        printf("\nEnter 0 to try again, 1 to return to the main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1) 
        {
            menu();
        } 
        else if (main_exit == 2) 
        {
            closed();
        } 
        else if (main_exit == 0) 
        {
            transact();
        } 
        else 
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    } 
    else
     {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);

        if (main_exit == 1)
         {
            system("clear");
            menu();
        }
         else
         {
            closed();
        }
    }
}
// this function is used to calculate the rate of interest for the principle amount for the years
void see() 
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;

    ptr = fopen("record.dat", "r");
    printf("\nEnter the account no. of the customer:");
    scanf("%d", &upd.accno);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) {
        if (add.accno == upd.accno)
         {
            test = 1;
            printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited: $%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.accno, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acctype, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

            if ((strcmp(add.acctype, "fixed1") == 0) || (strcmp(add.acctype, "fixed2") == 0) || (strcmp(add.acctype, "fixed3") == 0)) {
                printf("Your money will be deposited for a fixed period of one year\n");

                time = 1.0;
                rate = 9;
                intrstcalculation(time, &add.amt, rate);
            }
        }
    }

    fclose(ptr);

    if (test != 1) 
    {
        printf("\nRecord not found!!");
    see_invalid:
        printf("\nEnter 0 to try again, 1 to return to the main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("clear");

        if (main_exit == 1)
         {
            menu();
        } 
        else if (main_exit == 2)
         {
            closed();
        } 
        else if (main_exit == 0) 
        {

            see();
        } 
        else
         {
            printf("\nInvalid!");
            goto see_invalid;
        }
    } 
    else
     {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);

        if (main_exit == 1)
         {
            system("clear");
            menu();
        } 
        else 
        {
            closed();
        }
    }
}
//this finction is used to calculate the rate of interest of the fixed deposit 
float intrstcalculation(float t, float *amt, int r)
 {
    float SI;
    SI = (*amt * t * r) / 100.0;
    *amt = *amt + SI;
    printf("\n\nThe interest is %f", SI);
    printf("\n\nThe total amount is %f", *amt);
    return 0;
}

void erase() 
{
    FILE *old, *newrec;
    int rem_accno;
    old = fopen("record.dat", "r");
    newrec = fopen("newdata.dat", "w");
    printf("\nEnter the account no. of the customer you want to delete:");
    scanf("%d", &rem_accno);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &rem.accno, &rem.name, &rem.dob.month, &rem.dob.day, &rem.dob.year, &rem.age, rem.address, rem.citizenship, &rem.phone, rem.acctype, &rem.amt, &rem.deposit.month, &rem.deposit.day, &rem.deposit.year) != EOF) {
        if (rem.accno != rem_accno)
         {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", rem.accno, rem.name, rem.dob.month, rem.dob.day, rem.dob.year, rem.age, rem.address, rem.citizenship, rem.phone, rem.acctype, rem.amt, rem.deposit.month, rem.deposit.day, rem.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("newdata.dat", "record.dat");
    printf("\nThe record is successfully deleted!\n");

erase_invalid:
    printf("\nEnter 0 to try again, 1 to return to the main menu and 2 to exit:");
    scanf("%d", &main_exit);

    if (main_exit == 1) 
    {
        system("clear");
        menu();
    } 
    else if (main_exit == 2)
     {
        closed();
    } 
    else if (main_exit == 0) 
    {
        erase();
    } 
    else 
    {
        printf("\nInvalid!");
        goto erase_invalid;
    }
}

void viewlist()
 {
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    printf("\nACC. NO.\t \t NAME\t\t\t ADDRESS \t\t\t PHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &add.accno, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acctype, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) {
        printf("\n%6d \t %-20s \t %-20s \t %.0lf", add.accno, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);

    if (test == 0)
     {
        system("clear");
        printf("\nNO RECORDS!!");
    }

viewlist_invalid:
    printf("\nEnter 0 to try again, 1 to return to the main menu and 2 to exit:");
    scanf("%d", &main_exit);

    if (main_exit == 1) 
    {
        system("clear");
        menu();
    } 
    else if (main_exit == 2)
     {
        closed();
    } 
    else if (main_exit == 0)
     {
        viewlist();
    } 
    else 
    {
        printf("\nInvalid!");
        goto viewlist_invalid;
    }
}

void closed()
 {
    printf("\n\n\n\nThis C Mini Project is developed by Dhanush v and DhanushGowda mv");
}
