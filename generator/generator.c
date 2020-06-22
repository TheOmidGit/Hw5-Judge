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
        printf("Please enter main code path(Press \'d\' for the default path): ");
        gets(mainCodeName);

        if (strcmp("back",mainCodeName) == 0){
            system("cls");
            return BACK;
        }
        //=====================================
        if (strcmp("d",mainCodeName) == 0){
            strcpy(mainCodeName,"generator\\C file\\*.c");
            system("cls");
        }
        //=====================================
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
            printf("Your code has an error. Please try again\n");getchar();
            system("cls");
        }
    }
	
}



void removeBackSlashN(int index){
    int j;
    for (j=0;inputsAndFiles.inputsNames[index][0]!='\0';j++){
        if (inputsAndFiles.inputsNames[index][j] == '\n'){
            inputsAndFiles.inputsNames[index][j] = '\0';
            break;
        }
    }
}


int getTestsPath(){
    
    while (1){
        printf("Enter the path of inputs(Press \'d\' for the default path): ");
        gets(inputsAndFiles.inputsPath);

        //back
        if (strcmp("back",inputsAndFiles.inputsPath) == 0){
            system("cls");
            return BACK;
        }
        //=====================================
        if (strcmp("d",inputsAndFiles.inputsPath) == 0){
            strcpy(inputsAndFiles.inputsPath,"generator\\inputs");
            system("cls");
        }
        //=====================================


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

            //saving outputs to a file and then remove it
            FILE* file;
            file = fopen("outputsName.txt","r");
            int i=0;
            while (fgets(inputsAndFiles.inputsNames[i],100,file))
            {
                removeBackSlashN(i);
                i++;
            }
           fclose(file);
           system("del outputsName.txt");

           fflush(stdin);
           system("cls");
           
            return CODE_EXECUTED_SUCCESSFULLY;
        }
        else if (yesOrNo[0] == 'n' || yesOrNo[0] == 'N'){
            fflush(stdin);
            system("cls");
            continue;
        }
        //=====================================
        else{
            printf("You did not enter a correct character !");
            fflush(stdin);
            getchar();
            system("cls");
            continue;
        }
        //=====================================
    }
    
}


int generate(){
    int i =0;
    //delete previous output files
    system("del /f /q \"Output\\Main output\"");

    //generating test cases
    while(inputsAndFiles.inputsNames[i][0]!='\0'){
        char generateCommand[1000];
        sprintf(generateCommand,"generator\\generate.exe <\"%s\\%s\">\"Output\\Main output\\Output of %s\"",inputsAndFiles.inputsPath,inputsAndFiles.inputsNames[i],inputsAndFiles.inputsNames[i]);
        system(generateCommand);
        i++;
    }
    printf("Outputs generated in \"Output\\Main output\" folder.\nPress enter to continue");getchar();
    return 0;
}