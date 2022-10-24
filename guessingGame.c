#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

//The game sequence
void playGame(int actualNumber, int maxNumber){

    int input;
    char flush;//checking for char in buffer

    printf("\n");

    //play game
    do{
        printf("Please enter your guess (1 - %d): ", maxNumber);
        if(scanf("%d", &input) != 1){//input validation
            scanf("%c", &flush);
            if(flush != 'q')
                printf("Please enter a number...\n");
            
        }
        else{//comparing numbers
            if(input > actualNumber)
                printf("%d is too high!\n", input);
            else if(input < actualNumber)
                printf("%d is too low!\n", input);
        }

    }while(input != actualNumber && flush != 'q');
    
    if(flush == 'q')//quit sequence
        printf("Returnig to main menu...\n");
    else//win sequence
        printf("You got it!\n");
}


int main(void){


    srand(time(NULL));

    const int MAXLIMIT = 10;
    int maxNumber = MAXLIMIT;
    int actualNumber; 
    int option;

    printf("\n****** Guessing Game *******\n\n");


    do{
        printf("\nPlease pick from the following options:\n\n");
        printf("1- Play game\n");
        printf("2- Change Max Number\n");
        printf("3- Exit\n");
        printf("Selection: ");
        scanf("%d", &option);

        //menu
        switch (option)
        {
        case 1://setting up game
            actualNumber = rand() % (maxNumber - 1) + 2;
            //printf("ACTUAL: %d", actualNumber); //for testing
            playGame(actualNumber, maxNumber);
            break;
        case 2://changing the high
            printf("\nWhat do you want to change the max number to?");
            do{
                printf("\nEnter a number in the range of 2-10:  ");
                scanf("%d", &maxNumber);
            }while(maxNumber > MAXLIMIT || maxNumber < 2);

            printf("\nMax number successfully changed to %d!\n", maxNumber);
            break;
        
        default:
            break;
        }
    }while(option != 3);

    printf("\n\n***Thanks for playing!***\nExiting....");
}

