#include "judge.h"
#include "../generator/generator.h"
// define your functions and global variables here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CODE_EXECUTED_SUCCESSFULLY 0
#define CODE_DID_NOT_EXECUTE 1
#define BACK 2


char mainCodeName[100];
int compileJudge(){
    while (1){
        printf("Please enter main code name: ");
        gets(mainCodeName);
        if (strcmp("back",mainCodeName) == 0){
            system("cls");
            return BACK;
        }
        char arr[100];
        sprintf(arr,"gcc \"%s\" -o judge/testCode",mainCodeName);
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


int generateTestCaseJudge(){
    int i;
    system("del /f /q \"Output\\judge output\"");
    for(i=0;inputsAndFiles.inputsNames[i][0]!='\0';i++){
        char generateCommand[200];
        sprintf(generateCommand,"judge\\testCode.exe <\"%s\\%s\">\"Output/judge output/Judge output of %s\"",inputsAndFiles.inputsPath,inputsAndFiles.inputsNames[i],inputsAndFiles.inputsNames[i]);
        system(generateCommand);

    }
    printf("Outputs saved into a folder");getchar();
    system("cls");
    return 1;
    
}

/* ouput of system using "fc"
-1 – Your syntax is incorrect.
0 – Both files are identical.
1 – The files are different.
2 – At least one of the files can’t be found.
*/
int compare(){
    int i;
    int result;
    
    for ( i = 0; inputsAndFiles.inputsNames[i][0]!='\0';i++)
    {
        char compareCommand [200];
        sprintf(compareCommand,"fc \"Output\\Main output\\Output of %s\" \"Output\\judge output\\Judge output of %s\"",inputsAndFiles.inputsNames[i],inputsAndFiles.inputsNames[i]);
        
        result = system(compareCommand);
        
        if (result == 0){
            resultOfJudge[i] = '0';
        }
        else
        {
            resultOfJudge[i] = '1';
        }
        
        
        system("cls");
    }

    return 1;
}

void printResult(){
    int i;
    for ( i = 0; resultOfJudge[i]!='\0';i++){
        //printf("hi");getchar();
        if (resultOfJudge[i] == '0'){
            printf("Test Case \"%s\":\n\tAccepted!\n",inputsAndFiles.inputsNames[i]);
        }
        else if (resultOfJudge[i] == '1')
        {
           printf("Test Case \"%s\":\n\tWrong Answer!\n",inputsAndFiles.inputsNames[i]);
        }
        
    }
    getchar();system("cls");
    

}




