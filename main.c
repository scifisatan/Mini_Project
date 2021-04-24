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
void check_if_game_over():
void check_for_winner());
void check_if_tie());
void check_row();
void check_column();
void check_diag();



/*Main function*/
int main()
{
  system ("clear");
  current_player = player();
 
  while (game_still_going == 1)
    {
      handle_turn (current_player);

      check_for_winner ();
      check_if_tie ();

      flip_player();
    }
  if (winner == 'X' or winner == 'O')
    {
    printf ("%c won!", winner)}
  else
    {
    printf ("Tie")}
  return 0;
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
    display_board();
    return checks_player;
}


/*Tic Tac Toe Board*/
void display_board()
{
    printf("\n");
    printf(" %c | %c | %c \n",board[0],board[1],board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[3],board[4],board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[6],board[7],board[8]);

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
    printf("%c's turn\n",current_player);
    int check = 1;
    int position;
    while (check == 1)
    {
        printf("Choose a postiton from 1 to 9: ");
        scanf("%d", &position);
        position = position - 1;
        if (position > 8)
        {
            printf("Invalid Input");
        }

        else if (board[position] != '-')
        {
            printf("You can't go there");
        }

        else 
        {
            check = 0;        
        }
        board[position] = current_player;
        display_board();
    }
}
