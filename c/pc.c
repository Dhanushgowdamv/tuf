#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//creating a structure
struct node{
    int sem,usn,phno;
    char name[20];
    char branch[20];
    struct node*link;
}*start;

void create(int,int,int,char[],char[]);
void disp();
void insertfront(int ,int,int,char[],char[]);
void deletefront();
void insertend(int,int,int,char[],char[]);
void deleteend();

//void create
void create(int un,int se,int ph,char na[20],char br[20]){
    struct node*q*tmp;
    tmp->usn=us;
    tmp->sem=se;
    tmp->phno=ph;
    strcpy(tmp->name=na);
    strcpy(tmp->branch=br);
    if(start=null){
        start=null;
    }
    else{
        q=start;
        while(q->link=null)
        {
            q=q->link;
        }
        q->link=tmp;
    }
}
//display function
void display(){
    struct node*q;
    if(start=NULL){
        printf("the list in empty");

    }
    {
        count++;
        printf("the usn")
    }
}