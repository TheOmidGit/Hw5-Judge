#include "generator.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CODE_EXECUTED_SUCCESSFULLY 0
#define CODE_DID_NOT_EXECUTE 1
#define BACK 2


char mainCodeName[100];
int compile(){
    while (1){
        printf("Please enter main code name: ");
        gets(mainCodeName);
        if (strcmp("back",mainCodeName) == 0){
            system("cls");
            return BACK;
        }
        char arr[100];
        sprintf(arr,"gcc \"%s\" -o generator/generate",mainCodeName);
        int result;
        result = system(arr);
        if (result == 0){
            printf("Code Compiled Successfully\n");getchar();
            system("cls");
            return CODE_EXECUTED_SUCCESSFULLY;
        }
        else
        {
            printf("Your code had an error. Please try again\n");getchar();
            system("cls");
        }
    }
	
}


struct files
{
    char inputsPath[500],inputsNames[100][500];
};

struct files inputsAndFiles;
int getTestsPath(){
    
    while (1){
        printf("Enter the path of inputs: ");
        
        gets(inputsAndFiles.inputsPath);

        //back
        if (strcmp("back",inputsAndFiles.inputsPath) == 0){
                system("cls");
                return BACK;
        }

        char filesListCommand[1000];
        sprintf(filesListCommand,"dir /b \"%s\"",inputsAndFiles.inputsPath);

        int result;
        result = system(filesListCommand);
        if (result == CODE_DID_NOT_EXECUTE){
            printf("Please try again");getchar();
            fflush(stdin);
            system("cls");
            continue;
        }

        printf("\nIs the list of inputs correct?(y/n)");
        char yesOrNo[10];
        scanf("%s",yesOrNo);
        if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y'){

            sprintf(filesListCommand,"dir /b \"%s\" > outputsName.txt",inputsAndFiles.inputsPath);
            system(filesListCommand);

            //saving outputs to a file
            FILE* file;
            file = fopen("outputsName.txt","r");
            int i=0;
            while (fscanf(file,"%s",inputsAndFiles.inputsNames[i]) == 1)
            {
                i++;
            }
           fclose(file);
           fflush(stdin);
           system("cls");

           //mishe file output ham delete kard
           
            return CODE_EXECUTED_SUCCESSFULLY;
        }
        else if (yesOrNo[0] == 'n' || yesOrNo[0] == 'N'){
            fflush(stdin);
            system("cls");
            continue;
        }
        
        else{
            printf("You did not enter a correct character !");getchar();getchar();
            fflush(stdin);
            system("cls");
            continue;
        }
    }
    
}

//D:\Programs\Hw5-Judge-master\Test Cases\in

int generate(){
    int i =0;
    //delete previous files files
    system("del /f /q \"Test Cases\\out\"");

    //generating test cases
    while(inputsAndFiles.inputsNames[i][0]!='\0'){
        char generateCommand[1000];
        sprintf(generateCommand,"generator\\generate.exe <\"%s\\%s\">\"Test Cases\\out\\Output of %s\"",inputsAndFiles.inputsPath,inputsAndFiles.inputsNames[i],inputsAndFiles.inputsNames[i]);
        system(generateCommand);
        i++;
    }
    printf("Outputs generated\n");getchar();
    return 0;
}