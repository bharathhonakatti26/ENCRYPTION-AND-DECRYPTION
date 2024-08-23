#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

int create_encrypted_file (){

    int number_of_letters; 
    int create_encrypted_file_prototype;

    printf("\n\t\t\tExpected Number of Letters(int) : ");
    scanf("%d" , &number_of_letters);
    
    char sentences[number_of_letters];

    printf("\n\t\t\tEnter the text : ");
    scanf("%s" , sentences);

    srand(time(NULL));
    create_encrypted_file_prototype = rand()% 9000 + 1000 ;
    printf("\n\t\t\t\tThis is Your File Prototype : %d " , create_encrypted_file_prototype );
    printf("\n\t\t\t***** Successfully created Encrypted File *****\n");
    printf("\n\t\t***************************************************************\n");

    FILE *ftr;
    char filename[5];
    sprintf(filename , "%d.bin" , create_encrypted_file_prototype);

    ftr = fopen(filename , "wb");
    if (ftr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fwrite(sentences , sizeof(int) , sizeof(sentences)/sizeof(int) , ftr);
    fclose(ftr);

    return 0;

}

int edit_encrypted_file(){

    int number_of_letters; 
    int edit_encrypted_file_prototype;
    
    printf("\n\t\t\tEnter Encrypted File prototype : ");
    scanf("%d" , &edit_encrypted_file_prototype);

    printf("\n\t\t\tExpected Number of Letters(int) : ");
    scanf("%d" , &number_of_letters);

    char sentences[number_of_letters];
    printf("\n\t\t\tEnter the text : ");
    scanf("%s" , sentences);

    printf("\n\t\t\t***** Successfully Edited Encrypted File *****");
    printf("\n\t\t***************************************************************\n");

    FILE *edit_file_content;
    char filename[5];
    sprintf(filename , "%d.bin" , edit_encrypted_file_prototype);

    edit_file_content = fopen(filename , "ab");
    if (edit_file_content == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fwrite(sentences , sizeof(int) , sizeof(sentences)/sizeof(int) , edit_file_content);    
    fclose(edit_file_content);

    return 0;

}

int main_encryption (){
    int choice;

    do
    {
        
        while (1){

            printf("\n\t\t\t\tSELECT OPTION\n\n");
            printf("\t\t\t1.Create a New Encryption File\n");
            printf("\t\t\t2.Edit Encrypted File\n");
            printf("\t\t\t0. Back \n");
            printf("\n");
            printf("\tEnter your choice : ");
            if (scanf("%d", &choice) != 1) {
                
                printf("\t\tWrong Entry! Please enter the correct option.\n\n");
                while (getchar() != '\n');
                continue;
            }
            if (choice < 0 || choice > 3) { 
                printf("\t\tWrong Entry! Please enter the correct option.\n\n");
                continue;
            }

            break;
        }

        switch (choice)
        {
        case 1:
            create_encrypted_file();
            break;

        case 2:
            edit_encrypted_file();
            break;

        }


    } while(choice != 0);

    return 0;

}

int decryption(){

    int file_prototype;
    printf("\n\t\t\tEnter the file prototype number to read : ");
    scanf("%d", &file_prototype);

    char filename[10];
    sprintf(filename, "%d.bin", file_prototype);

    FILE *ftr;
    ftr = fopen(filename, "rb");
    if (ftr == NULL) {
        printf("\n\t\t\tAnalysing Encrypted File");
        sleep(2);
        printf("\n\t\t\tThere is no encrypted file for this prototype");
        printf("\n\t\t\tPlease Check the file prototype ");
        return 1;
    }

    printf("\n\t\t\tFile found successfully");
    sleep(2);
    printf("\n\t\t\tAnalysing Encrypted File");
    sleep(2);
    printf("\n\t\t\tDecrypting .... ");
    sleep(2);

    char buffer[100]; 
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, ftr); 

    buffer[bytesRead] = '\0'; 
    fclose(ftr);

    printf("\n\t\t***************************************************************\n");
    printf("\n\t\t\tDecrypted text : %s\n", buffer);
    sleep(3);
    printf("\n\t\t\t***** Successfully Decrypted File *****");
    printf("\n\t\t***************************************************************\n");

    return 0;

}

int main(){

    int choice;

    do
    {
        while (1){

            printf("\n\t\t\t\tSELECT OPTION\n\n");
            printf("\t\t\t1.Encryption File\n");
            printf("\t\t\t2.Decryption File\n");
            printf("\t\t\t0. Back \n");
            printf("\n");
            printf("\tEnter your choice : ");
            if (scanf("%d", &choice) != 1) {
                
                printf("\t\tWrong Entry! Please enter the correct option.\n\n");
                while (getchar() != '\n'); 
                continue;
            }
            if (choice < 0 || choice > 3) { 
                printf("\t\tWrong Entry! Please enter the correct option.\n\n");
                continue;
            }
            break;
            }

        switch (choice)
        {
        case 1:
            main_encryption();
            break;

        case 2:
            decryption();
            break;

        }

    }while (choice != 0);

    return 0;
}

