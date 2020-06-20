#include "generator/generator.h"
#include "judge/judge.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BACK 2

int generateTestCase(){
    int result;
    //======================
    result = compile();
    if (result == BACK){
        return BACK;
    }
    //======================
    result = getTestsPath();
    if (result == BACK){
        return BACK;
    }
    //======================
    generate();
    return 1;
    
}

int judge(){
    int result;
    result = system("FC \"output1.txt\" \"output2.txt\"");
    printf("%d",result);getchar();
}

int main() {
    while (1)
    {   
        int result;
        system("cls");
        //menu
        printf("1 -> Generate test case\n2 -> Judge\n3 -> Exit\n");
        int choice;
        scanf("%d",&choice);getchar();

        switch (choice)
        {
        case 1:
            system("cls");
            generateTestCase();
            break;
        case 2:
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
