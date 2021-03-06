#include "generator/generator.h"
#include "judge/judge.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BACK 2

int resultForGenerateTestCase;



//tabe clear ham benevis





int generateTestCase(){
    int result;
    //======================
    result = getTestsPath();
    if (result == BACK){
        return BACK;
    }
    //======================
    result = compile();
    if (result == BACK){
        return BACK;
    }
    
    
    //======================
    generate();
    return 1;
    
}

int judge(){
    if (resultForGenerateTestCase != 1)
    {
        printf("You have to generate codes first!");getchar();
        return 0;
    }
    
    int result;
    //======================
    result = compileJudge();
    if (result == BACK){
        return BACK;
    }
    //======================
    generateTestCaseJudge();
    //======================
    compare();
    //======================
    printResult();


    return 1;
}

int main() {
    while (1)
    {   
        
        system("cls");
        //menu
        printf("1 -> Generate test case\n2 -> Judge\n3 -> Exit\n");
        int choice;
        scanf("%d",&choice);getchar();

        switch (choice)
        {
        case 1:
            system("cls");
            resultForGenerateTestCase = generateTestCase();
            break;
        case 2:
            system("cls");
            judge();
            break;
        case 3:
            return 0;
        default:
            break;
        }
        
    }
    
    return 0;
}
