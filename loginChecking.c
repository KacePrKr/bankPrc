//
// Created by THESITM on 1/16/2023.
//
//
// Created by ncc on 05/01/2023.
//
#include "stdio.h"

struct rc{
    char note[200];
};
struct db{

    char id[10];
    char username[30];
    char email[30];
    char password[20];
    char phNumber[15];
    char address[100];
    char amount[15];


    struct rc transaction[100];
};

struct db database[100];

struct db loginINfo[1];

struct db wordCount[1];


int spaceCounter=0;
int userIndex=0;
int idIndex=0;
int uIndex=0;
int emIndex=0;
int pwdIndex=0;
int phIndex=0;
int addIndex=0;
int amIndex=0;
int user_tr_Index=0;
int noteIndex=0;

int flag=-1;

void loadingFromTXT_DB();
void outputtingAllUserData();
void loginChecking();
int wordCounting(char a,int index);
int main(){

    printf("Welcome to our XBank!\n");

    loadingFromTXT_DB();
    outputtingAllUserData();
    loginChecking();


    return 0;
}

void loadingFromTXT_DB(){

    FILE *fptr = fopen("7-db.txt","r");

    if(fptr==NULL){
        printf("File cannot open!\n");
    } else{

        char c =fgetc(fptr);

        while (!feof(fptr)){

            if(c!='\n'){

                if(c==' '){
                    spaceCounter++;
                    c = fgetc(fptr);
                }

                if(spaceCounter==0){

                    database[userIndex].id[idIndex]=c;
                    idIndex++;
                    c = fgetc(fptr);

                }else if(spaceCounter==1){

                    database[userIndex].username[uIndex]=c;
                    uIndex++;
                    c = fgetc(fptr);



                } else if(spaceCounter==2){


                    database[userIndex].email[emIndex]=c;
                    emIndex++;
                    c = fgetc(fptr);


                } else if(spaceCounter==3){


                    database[userIndex].password[pwdIndex] = c;
                    pwdIndex++;
                    c = fgetc(fptr);

                } else if(spaceCounter == 4){

                    database[userIndex].phNumber[phIndex]=c;
                    phIndex++;
                    c = fgetc(fptr);


                } else if(spaceCounter==5){

                    database[userIndex].address[addIndex]=c;
                    addIndex++;
                    c = fgetc(fptr);


                } else if(spaceCounter==6){

                    database[userIndex].amount[amIndex]=c;
                    amIndex++;
                    c = fgetc(fptr);


                } else{

                    database[userIndex].transaction[user_tr_Index].note[noteIndex]=c;

                    noteIndex++;
                    c = fgetc(fptr);


                }


            } else{

                userIndex++;
                spaceCounter=0;
                idIndex=0;
                uIndex=0;
                emIndex=0;
                pwdIndex=0;
                phIndex=0;
                addIndex=0;
                amIndex=0;
                noteIndex=0;

                /**/
                user_tr_Index++;
                c = fgetc(fptr);
            }

        }

    }

}

void outputtingAllUserData(){


    for(int i=0; i<userIndex ; i++){


        printf("%s%s%s%s%s%s%s%s\n",database[i].id,database[i].username,database[i].email,database[i].password,database[i].phNumber,database[i].address,database[i].amount,database[i].transaction[i].note);


    }


}


void loginChecking(){
    int allCharSame=0;
    printf("Enter your email:");
    scanf(" %[^\n]", &loginINfo[0].email);

    for(int i=0; i<userIndex ; i++){
        int firstData = wordCounting('f',i);
        int sData = wordCounting('s',i);
        printf(" first data : %d ^ sec data: %d\n",firstData,sData);

        if( firstData == sData){

            for(int x=0; x<firstData ; x++){

                if( database[i].email[x] == loginINfo[0].email[x] ){
                    allCharSame++;
                } else{
                    break;
                }
            }
            if( firstData == allCharSame && sData==allCharSame){
                flag = i;
                break;
            }
        }

    }

    if(flag!=-1){
        printf("We found User: %s\n",database[flag].username);
    } else{
        printf("Not found your user email:\n");
    }

}

int wordCounting( char a,int index){
    int wordCounter=0;
    if( a=='f'){
        for(int x=0; x<30 ; x++){
            if(database[index].email[x] != '\0'){
                wordCounter++;
            } else{


                break;
            }
        }
    } else{

        for(int x=0; x<30 ; x++){
            if(loginINfo[0].email[x] != '\0'){
                wordCounter++;
            } else{

                break;
            }
        }

    }

    return wordCounter;
}

