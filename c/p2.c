#include <stdio.h>
#include<stdlib.h>
#define MAX 20
int top=-1;
int a[MAX];
void push();
void pop();
void palinderome();
void display();

//main functyuon
void main(){
    int ch;
    while(1){
        printf("1.puch\n 2.pop\n 3.display\n 4.cheak it is palindrome\n enter the choice");
        scanf("%d",&ch);

    switch(ch){
        case 1:{
            push();
            break;
        }
        case 2:{
            pop();
            break;
        }
        case 3:{
            display();
            break;
        }
        case 4:{
            palinderome();
            break;
        }
        default:
        exit(0);
      }

   }
}

//push operation
void push()
{
    int item;
    if(top>=MAX)
    {
        printf("/nthe stack is overflow");
    }
    else
    {
        top+=1;
        printf("enter the elements into the stack");
        scanf("%d",&item);
        a[top]=item;
    }
}

//pop operation
void pop(){
    int item;
    if(top<=0){
        printf("the stack is in under flow/t");
    }
    else{
        item=a[top];
        top=-1;
        printf("the value is deleted ",item);
    }
}

//display function
void display(){
     if(top<=0){
        printf("the stack is in under flow");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("\n%d",a[i]);

        }
    }
}

//check for palindroem
void palinderome(){
    int i,temp=top;
        if(top!=-1){
            for(i=0;i<=top/2;i++)
                if(a[i]!=a[temp--]){
                    printf("the noyt");
                    return ;
                }
                printf("yes");
            }
            return ;
        }


