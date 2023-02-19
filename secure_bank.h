//
// Created by ncc on 17/02/2023.
//

#ifndef NCC_ONLINE_SECURE_BANK_SECURE_BANK_H
#define NCC_ONLINE_SECURE_BANK_SECURE_BANK_H
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void login();
void rEgister();
int check_input(char option[2]);
int randFunction();
int emailChecking(char emailName);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int randFunction(){
    srand(time(NULL));
    (rand()%999999999)+100000000;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct databaseSturcture{
    int id[5];
    char userName[25];
    char password[25];
    char nrcNo[25];
    char citizens[25];
    char email[25];
    char phoneNumber[25];
    char accType[25];
    char address[25];
}userInfo[100];
int userNumber=1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void main_menu(){
    char option[2];

    int a=0;

    printf("Welcome to Swiss Secure Bank!\n");
    printf("Press 1 to Login!\n");
    printf("Press 2 to Register!\n");
    printf("Press 3 to Exit!:");
    scanf(" %[^\n]", &option[0]);

    int data = check_input(option);
    if( data == 49){
        login();
    } else if ( data == 50){
        rEgister();
    }else if ( data == 51){
        exit(2);
    } else{
        main_menu();
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void login(){

    FILE *fptr;
    fptr=fopen("userInfo.txt","r");
    int read = getc(fptr);


    int id;

    printf("Enter Your ID : ");
    scanf("%d",&id);

    printf("Enter Your Email : ");
    scanf(" %[^\n]", &userInfo[1].email[1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void rEgister(){


    FILE *fptr;

    while (1) {


        int randNumber;


        printf("Enter Your Name  : ");
        scanf(" %[^\n]",&userInfo[userNumber].userName[1]);

        printf("Enter Your Email : ");
        scanf(" %[^\n]",&userInfo[userNumber].email[1]);

        printf("Enter Your PhoneNumber  : ");
        scanf(" %[^\n]",&userInfo[userNumber].phoneNumber[1]);

        printf("Enter Your Country  : ");
        scanf(" %[^\n]",&userInfo[userNumber].citizens[1]);

        printf("Enter Your Address  : ");
        scanf(" %[^\n]",&userInfo[userNumber].address[1]);

        printf("Enter Your Account Type  : ");
        scanf(" %[^\n]",&userInfo[userNumber].accType[1]);

        printf("Enter Your NRC No : ");
        scanf(" %[^\n]",&userInfo[userNumber].nrcNo[1]);

        printf("Enter Your Password : ");
        scanf(" %[^\n]",&userInfo[userNumber].password[1]);

        fptr = fopen("userInfo.txt", "a");

        if (fptr == NULL) {
            printf("File Cannot Open!");
        } else {


         //   fprintf(fptr,"%s\t\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","ID","Name","Email","PhoneNumber","Country","Address","Acc Type","NRC No","Password");

            randNumber=randFunction();
            fprintf(fptr, "%d ",(rand()%999999999)+100000000);


            for (int i = 1; userInfo[userNumber].userName[i] != '\0'; i++) {
                fputc(userInfo[userNumber].userName[i], fptr);
            }

            //fprintf(fptr, "\t%s\t", "name234@xbank.user");
            fputc(' ', fptr);


            for (int i = 1; userInfo[userNumber].email[i] != '\0'; i++) {
                fputc(userInfo[userNumber].email[i], fptr);
            }

            fputc(' ', fptr);

            for (int i = 1; userInfo[userNumber].phoneNumber[i] != '\0'; i++) {
                fputc(userInfo[userNumber].phoneNumber[i], fptr);
            }

            fputc(' ', fptr);

            for (int i = 1; userInfo[userNumber].citizens[i] != '\0'; i++) {
                fputc(userInfo[userNumber].citizens[i], fptr);
            }

            fputc(' ', fptr);


            for (int i = 1; userInfo[userNumber].address[i] != '\0'; i++) {
                fputc(userInfo[userNumber].address[i], fptr);
            }

            fputc(' ', fptr);

            for (int i = 1; userInfo[userNumber].accType[i] != '\0'; i++) {
                fputc(userInfo[userNumber].accType[i], fptr);
            }

            fputc(' ', fptr);

            for (int i = 1; userInfo[userNumber].nrcNo[i] != '\0'; i++) {
                fputc(userInfo[userNumber].nrcNo[i], fptr);
            }

            fputc(' ', fptr);

            for (int i = 1; userInfo[userNumber].password[i] != '\0'; i++) {
                fputc(userInfo[userNumber].password[i], fptr);
            }

            fputc('\n', fptr);

            break;

        }
        userNumber++;
    }

    fclose(fptr);
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int check_input(char option[2]){
    if (option[0] >= 49 && option[1] == '\0' && option[0] <=57) {
        return option[0];
    } else{
        return -1;
    }
}
#endif //NCC_ONLINE_SECURE_BANK_SECURE_BANK_H



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int emailChecking(char emailName){

    char tempMail = userInfo[userNumber].email[1];

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
