/*Importing Required Library*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*Calling all the user defined functions*/
char player();
void display_board();


/*Declaring Global Variables*/
char winner;
char current_player;
char board[9] = {
                    '-', '-', '-',
                    '-', '-', '-',
                    '-', '-', '-'
                };


/*Main function*/
int main()
{
  system ("clear");
  current_player = player();
  display_board();    
 
}


/*Lets the first player to choose  between X and O*/
char player()
{
    char checks_player;
    int is_input_valid = 0;

    while(is_input_valid == 0)
    {
        printf("Player 1!! \nWhat do you want to choose? (X/O) ");
        scanf(" %c",&checks_player);
        if(checks_player == 'x')
        {
            checks_player = 'X';
            is_input_valid = 1;
        }
        else if(checks_player == 'o')
        {
            checks_player = 'O';
            is_input_valid=1;
        }
        else if((checks_player == 'O')|| (checks_player == 'X'))
        {
            is_input_valid = 1;
        }
        else
        {
            sleep(0.5);
            printf("Invalid Input!!\n");
            sleep(1);
            printf("Try Again...\n\n");
            sleep(1);
        }
    }
    return checks_player;
}


/*Tic Tac Toe Board*/
void display_board()
{
    printf(" %c | %c | %c \n",board[0],board[1],board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[3],board[4],board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[6],board[7],board[8]);

}
