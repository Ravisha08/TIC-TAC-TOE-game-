#include <stdio.h>
#include <conio.h>

char sq[10] = { 'j', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' }; // globally declared variable 

void TTTgrid(); // declaration 
int TTTwin();  // declaration 



void TTTgrid()       // definition                              
{                                 
         
    printf("\n\n\t                 ~ **********            TIC TAC TOE            ********** ~ \n\n");

    printf("                        Player 1 (X)  \t  \t                         Player 2 (O)\n\n\n");


    printf("                                                    |     |     \n");
    printf("                                                 %c  |  %c  |  %c \n", sq[1], sq[2], sq[3]);

    printf("                                               _____|_____|_____\n");
    printf("                                                    |     |     \n");

    printf("                                                 %c  |  %c  |  %c \n", sq[4], sq[5], sq[6]);

    printf("                                               _____|_____|_____\n");
    printf("                                                    |     |     \n");

    printf("                                                 %c  |  %c  |  %c \n", sq[7], sq[8], sq[9]);

    printf("                                                    |     |     \n\n");
}

int TTTwin()    // winning conditions (definition)
{
    if (sq[1] == sq[2] && sq[2] == sq[3])
        return 1;
        
    else if (sq[4] == sq[5] && sq[5] == sq[6])
        return 1;
        
    else if (sq[7] == sq[8] && sq[8] == sq[9])
        return 1;
    
    else if (sq[1] == sq[4] && sq[4] == sq[7])
        return 1;
        
    else if (sq[2] == sq[5] && sq[5] == sq[8])   
        return 1;
        
    else if (sq[3] == sq[6] && sq[6] == sq[9])
        return 1;
        
    else if (sq[1] == sq[5] && sq[5] == sq[9])
        return 1;
        
    else if (sq[3] == sq[5] && sq[5] == sq[7])
        return 1;
        
    else if (sq[1] != 'a' && sq[2] != 'b' && sq[3] != 'c' &&
        sq[4] != 'd' && sq[5] != 'e' && sq[6] != 'f' && sq[7] 
        != 'g' && sq[8] != 'h' && sq[9] != 'i')

        return 0;
    else
        return  - 1;
}


int main()
{
    int player = 1, i;
    char choice ;

    char mark;
    do
    {
        TTTgrid(); // calling 
        player = (player % 2) ? 1 : 2; // ternary operator used

        printf("PLAYER --> %d,  ENTER A LETTER  :  ", player );
        scanf("%c", &choice);

        mark = (player == 1) ? 'X' : 'O'; // ternary operator used

        if (choice == 'a' && sq[1] == 'a')
            sq[1] = mark;
            
        else if (choice == 'b' && sq[2] == 'b')
            sq[2] = mark;
            
        else if (choice == 'c' && sq[3] == 'c')
            sq[3] = mark;
            
        else if (choice == 'd' && sq[4] == 'd')
            sq[4] = mark;
            
        else if (choice == 'e' && sq[5] == 'e')
            sq[5] = mark;
            
        else if (choice == 'f' && sq[6] == 'f')
            sq[6] = mark;
            
        else if (choice == 'g' && sq[7] == 'g')
            sq[7] = mark;
            
        else if (choice == 'h' && sq[8] == 'h')
            sq[8] = mark;
            
        else if (choice == 'i' && sq[9] =='i')
            sq[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = TTTwin(); // calling 

        player++;
    }while (i ==  - 1);
    
    TTTgrid(); //calling 
    
    if (i == 1)
        printf("==>\a ***********      Player %d win        *************** ", --player);
    else
        printf("==>\a~~~~~~~~~~         Game draw            ~~~~~~~~~~~");

    getch();

    return 0;
}
