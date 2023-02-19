//
// Created by KacePrKr on 1/16/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define SIZE 100

int check_input(char option[2]);

struct admin_view{
    char userInformation[SIZE];
};

struct forUser{
    int id[5];
    char userName[5];
    char nrcNo[5];
    char citizens[5];
    char email[5];
    int phoneNumber[5];
    char accType[5];
    char address;
}userInfo[SIZE];

int login_Account(){
    printf("Login");
}

int bank_info(){
    printf("Our Policy");
}

int creatAccount(){

    FILE *fptr;

    printf("Enter Your Name  : ");
    scanf(" %[^\n]",&userInfo[1].userName[1]);

//    printf("Enter Your Email : ");
//    scanf_s(" %[^\n]",&userInfo[1].email[1]);

    fptr = fopen("userInfo.txt","a");

    if(fptr==NULL){
        printf("File Cannot Open!");
    }else {

//        fprintf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s","ID","Name","UserName","Mail");

            int index = 101;
            fprintf(fptr, "%d\t:\t",index);


            for (int i = 1; userInfo[1].userName[i] != '\0'; i++) {
                fputc(userInfo[1].userName[i], fptr);

            }

            fprintf(fptr, "\t:\t%s\t", "name234@xbank.user");
            fputc('\n\n', fptr);


            printf("Data are Stored");


    }

    fclose(fptr);
}


void welcomeBank() {
    char option[2];

    printf("\n\n==================================\n");
    printf("        WELCOME TO OUR BANK      \n");
    printf("==================================\n\n");

    printf("Press 1 to Create Account : \n");
    printf("Press 2 to Login  Account : \n");
    printf("Press 3 to Exit Account   : ");
    scanf_s(" %c", &option[0]);
    int data = check_input(option);
    if (data == 49) {
        creatAccount();
    } else if (data == 50) {
        login_Account();
    } else if (data == 51) {
        exit(2);
    } else {
        welcomeBank();
    }

}


int check_input(char option[2]){
        if (option[0] >= 49 && option[1] == '\0' && option[0] <=57) {
            return option[0];
        } else{
            return -1;
        }
    }

//    switch (option) {
//        case 'a':
//            if(option=='a' || option=='\0') {
//                printf("\nCREATE YOUR ACCOUNT .....\n");
//                creatAccount();
//                break;
//            } else{
//                welcomeBank();
//            }
//
//        case 'b \0':
//            printf("\nLOGIN YOUR ACCOUNT");
//            break;
//
//        case 'c \0':
//            printf("\nEXIT YOUR ACCOUNT");
//            break;
//
//        default:
//            printf("Something Wrong!");
//            welcomeBank();
//            break;
//    }



int main(){

    welcomeBank();

    return  0;
}