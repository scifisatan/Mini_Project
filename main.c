/*Importing Required Library*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*Declaring Global Variables*/
char winner;
char current_player;
int game_still_going = 1;
char board[9] = {
                    '-', '-', '-',
                    '-', '-', '-',
                    '-', '-', '-'
                };


/*Calling all the user defined functions*/
char player();
void display_board();
void handle_turn(char current_player);
void flip_player();



/*Main function*/
int main()
{
  system ("clear");
  current_player = player();
 
  while (game_still_going == 1)
    {
      handle_turn (current_player);


    flip_player();
    }  
    return 0;
 
}


/*Lets the first player to choose  between X and O*/
char player()
{
    char checks_player;
    int is_input_valid = 0;

    while(is_input_valid == 0)
    {
        printff("Player 1!! \nWhat do you want to choose? (X/O) ");
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
            printff("Invalid Input!!\n");
            sleep(1);
            printff("Try Again...\n\n");
            sleep(1);
        }
      

    }
    return checks_player;
}


/*Tic Tac Toe Board*/
void display_board()
{
    printff(" %c | %c | %c \n",board[0],board[1],board[2]);
    printff("---|---|---\n");
    printff(" %c | %c | %c \n",board[3],board[4],board[5]);
    printff("---|---|---\n");
    printff(" %c | %c | %c \n",board[6],board[7],board[8]);

}

void flip_player()
{
  if (current_player == 'X')
    {
        current_player = 'O';
    }

  else if (current_player == 'O')
    {
      current_player = 'X';
    }
}

void handle_turn(char current_player)
{
    printff("%c's turn\n",current_player);
    int check = 1;
    int position;
    while (check == 1)
    {
        printff("Choose a postiton from 1 to 9: ");
        scanf("%d", position);
        if (position > 9)
        {
            printff("Invalid Input");
        }

        else if (board[position] != '-')
        {
            printff("You can't go there");
        }

        else 
        {
            check = 0;        
        }
        board[position] = current_player;
        display_board();
    }
}
