#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.c"
#include "decrypt.c"
char filename[100];
void textfiled(char* user)
{

printf("\n\nDo you wish to Encrypt/Decrypt/Input Data (1/2/3)\n");
int a,c,d;
scanf("%d",&a);
switch(a)
{
    case 3:
         printf("\nEnter the data you wish to encrypt!\nReminder:If the text format is too large you can directly access the file which has your unique username through the computer.\nIncase the text you want to encrypt consist lesser than 100 characters than you can choose to continue\n Press 0 to Continue\n Press 1 to exit\n");
         scanf("%d",&c);
         if(c==1)
            exit(1);
         else if(c==0)
         {
             char data[100];
             printf("\nEnter the data you wish to encrypt:\n");
             fflush(stdin);
             gets(data);

            sprintf(filename,"%s.txt",user);
             FILE *fp;
           fp=fopen(filename,"a");

           fputs(data,fp);
         }
           printf("\nData Obtained Successfully!");
           exit(1);
           break;
    case 1:

            sprintf(filename,"%s.txt",user);
        encrypt(filename);
        printf("The File is Encrypted Successfully");
        exit(1);
        break;

    case 2:

            sprintf(filename,"%s.txt",user);
        decrypt(filename);
        printf("The File is Decrypted Successfully");
        exit(1);
        break;

     }
    }


int main() {
    char username[50];
    char password[50];
    char regusername[50];
    char fileregusername[50];
    char regpassword[50];
    char conpassword[50];
    char file_username[50];
    char file_password[50];
    int login_successful = 0;

    FILE *fp,*fpp,*fpu;
    printf("Welcome to the ENCRYPTOR/DECRYPTOR i.e ENDE ! \n\t\txxxxxxxx\nDeveloped By Susan Adhikari and Slok Regmi\n\n");
    printf ("Do you want you LOGIN or REGISTER?(L/R)\n");
char lr = getchar ();
if ((lr == 'L') || (lr == 'l')){
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    printf("\nEnter Username\n");
   scanf ("%s",username);
   printf("\nEnter Password\n");
   scanf("%s",password);

    while (fscanf(fp, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            login_successful = 1;
            break;
        }
    }

    fclose(fp);
if (login_successful) {
        printf("Login successful.");
        //going to the USD function first wala
        textfiled(username);
    } else {
        printf("Invalid Username or Password.");
    }
}

else if((lr == 'R') || (lr == 'r'))
{
    fpu = fopen("user.txt","a+");
    fpp = fopen("log.txt","a+");
    if (fpp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    usern:
    printf("Enter the username:\n");
           char file_ppp;
    scanf("%s",regusername);
    while(fscanf(fpu,"%s",fileregusername) != EOF)
    {
        if(strcmp(fileregusername,regusername)==0)
        {
            printf("\nThe Username is taken, Please enter again:\n");
            goto usern;
        }
    }


            passn:
            printf("\nEnter Password\n");
            scanf("%s",regpassword);
            printf("\nConfirm Password\n");
            scanf("%s",conpassword);
            if (strcmp(regpassword,conpassword) != 0)
            {
                printf("\nPassword doesnot match!");
                goto passn;
            }

        fprintf(fpu,"\n%s",regusername);
        fprintf(fpp,"\n%s %s",regusername,regpassword);
        printf("\nUsername and Password has been successfully added!\nExecute Again to login\n");

        fclose(fpp);
}
else
{
    printf("\nInvalid Input");
}
remove ("temp.txt");
    return 0;
}
