//
//  main.c
//  我的通讯录
//
//  Created by 焦欢欢 on 2017/2/6.
//  Copyright © 2017年 jiaohh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACT_NUM 1000
#define FileName "Address_book.dat"

typedef struct contact
{
    char name[20];
    char cellphone[12];
}contact;//define contact struct

void ShowMenu();
void Add(FILE * DataBase,contact *contacts,int * Actual_Num);
void Delete();
void Find();
void Update();
void ShowAll(int * Actual_Num,contact *contacts);
void Initial(int * Actual_Num,contact *contacts,FILE * DataBase);
void GetChoice(int * Actual_Num,FILE * DataBase,contact *contacts);

int main(int argc, const char * argv[])
{
    //6 functions needed
    //add a new contact
    //detlet a contact
    //find a contact
    //update a contact
    //show all the contacts
    //exit
    
    //variables declaration
    contact contacts[MAX_CONTACT_NUM];
    int Actual_Num=0;
    FILE * DataBase=NULL;
    
    //main program body
    Initial(&Actual_Num,contacts,DataBase);
    printf("Welcome to my ADDRESSBOOK\n");
    while(1)
    {
        ShowMenu();
        GetChoice(&Actual_Num,DataBase,contacts);
    }
    return 0;
}

void ShowMenu()
{
    printf("\n1.add\n");
    printf("2.detlet\n");
    printf("3.find\n");
    printf("4.modify\n");
    printf("5.show all\n");
    printf("6.quit\n");
    return;
}//show the menu.

void GetChoice(int * Actual_Num,FILE * DataBase,contact *contacts)
{
    char SN[2];
    printf("\ninput a function number: ");
    scanf("%s",SN);
    SN[1]='\0';
    if (((int)SN[0]-48<=6)&&((int)SN[0]-48>=1))
    {
        switch ((int)SN[0]-48)
        {
            case 1:
                Add(DataBase,contacts,Actual_Num);
                break;
            case 2:
                Delete();
                break;
            case 3:
                Find();
                break;
            case 4:
                Update();
                break;
            case 5:
                ShowAll(Actual_Num,contacts);
                break;
            case 6:
                exit(0);
        }//switch to the right function.
    }
    else
    {
        printf("\ninvalid NO.\n");
    }
}//get the number chosen by user.

void Add(FILE * DataBase,contact *contacts,int * Actual_Num)
{
    printf("\nadd a new contact\n");
    printf("name: ");
    scanf("%s",(contacts+*Actual_Num)->name);
    printf("cellphone:");
    scanf("%s",(contacts+*Actual_Num)->cellphone);
    *Actual_Num+=1;
    DataBase=fopen(FileName, "wb");
    fwrite(Actual_Num, sizeof(*Actual_Num), 1, DataBase);
    for (int i=0; i<*Actual_Num; i++)
    {
        fwrite(contacts+i, sizeof(contact), 1, DataBase);
    }
    fclose(DataBase);
}//add a n new contact

void Delete()
{
    printf("\ndelete an exist contact\n");
}//delete an exist contact

void Find()
{
    printf("\nfind a certain contact\n");
}//find a certain contact

void Update()
{
    printf("\nupdate an exist contact\n");
}//update an exist contact

void ShowAll(int * Actual_Num,contact *contacts)
{
    printf("\nshow all the contacts\n");
    if (*Actual_Num==0)
    {
        printf("\nNo contact!\n");
    }
    else
    {
        printf("\nname\t\tcellphone\n");
        for (int i=0; i<*Actual_Num; i++)
        {
            printf("%s\t\t%s\n",(contacts+i)->name,(contacts+i)->cellphone);
        }
        printf("\nTHE END\n");
    }
}//show all the contacts

void Initial(int * Actual_Num,contact *contacts,FILE * DataBase)
{
    
    DataBase=fopen(FileName, "rb");
    if (DataBase==NULL)
    {
        DataBase=fopen(FileName, "wb");
        fwrite(Actual_Num, sizeof(*Actual_Num), 1, DataBase);
        fclose(DataBase);
        return;
    }
    else
    {
        fread(Actual_Num, sizeof(*Actual_Num), 1, DataBase);
        for (int i=0; i<*Actual_Num; i++)
        {
            fread(contacts+i, sizeof(contact), 1, DataBase);
        }
        
    }
    fclose(DataBase);
}


