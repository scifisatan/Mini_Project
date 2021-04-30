/*Importing Required Library*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*------------------------------------*/

/*Declaring Global Variables*/
char winner;
char current_player;
int game_still_going = 0;
char board[9] = {
                    '-', '-', '-',
                    '-', '-', '-',
                    '-', '-', '-'
                };

/*------------------------------------*/

/*Calling all the user defined functions*/
char player(); //lets  player to choose X or O
void display_board(); // Tic-Tac-Toe Board
void handle_turn(char current_player); // Lets player to pick position
void flip_player(); // Changes turn
void check_for_winner(char current_player); // Checks if someone won
void check_if_tie(); // Checks if there's a tie
void check_row(char current_player); //Checks each row for win
void check_column(char current_player); //Checks each column for win
void check_diag(char current_player); //Checks each diag for win

/*------------------------------------*/

/*Main function*/
int main()
{
  system ("clear");
  printf("-------------------TIC TAC TOE---------------------");
  sleep(0.5);
  printf("\n             Let' start the game.\n");
  sleep(1);
  printf("The positions that will be used in this game are here: \n");
  printf(" 1 | 2 | 3 \n");
  printf("---|---|---\n");
  printf(" 4 | 5 | 6 \n");
  printf("---|---|---\n");
  printf(" 7 | 8 | 9 \n\n");
  current_player = player();
 
  while (game_still_going == 0)
    {
      handle_turn (current_player);
      check_if_tie();
      check_for_winner(current_player);
      flip_player();
    }
  if (winner == 'X' || winner == 'O')
    {
    printf("%c won!", winner);
    }
  else
    {
    printf("Tie");
    }
  return 0;
}

/*------------------------------------*/

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

/*------------------------------------*/

/*Tic Tac Toe Board*/
void display_board()
{
    system ("clear");
    printf("\n");
    printf(" %c | %c | %c \n",board[0],board[1],board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[3],board[4],board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[6],board[7],board[8]);

}

/*------------------------------------*/

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

/*------------------------------------*/

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
            board[position] = current_player;      
        }
        
        display_board();
    }
}

/*------------------------------------*/

void check_for_winner(char current_player)
{
  check_row (current_player);
  check_column (current_player);
  check_diag (current_player);
  if (game_still_going == 1)
  {
    winner = current_player;
  }
  
}

/*------------------------------------*/

void check_row(char current_player)
{

  if((board[0]==board[1])&&(board[0]==board[2])&&(board[0]!='-'))
  {
    game_still_going = 1;
  }
  else if((board[3]==board[4])&&(board[3]==board[5])&&(board[3]!='-'))
  {
    game_still_going = 1;
  }
  else if((board[6]==board[7])&&(board[6]==board[8])&&(board[6]!='-'))
  {
    game_still_going = 1;
  }
}

/*------------------------------------*/

void check_column(char current_player)
{
    if((board[0]==board[3])&&(board[0]==board[6])&&(board[0]!='-'))
  {
    game_still_going = 1;
  }
  else if((board[1]==board[4])&&(board[1]==board[7])&&(board[1]!='-'))
  {
    game_still_going = 1;
  }
  else if((board[2]==board[5])&&(board[2]==board[8])&&(board[2]!='-'))
  {
    game_still_going = 1;
  }
}

/*------------------------------------*/

void check_diag(char current_player)
{
    if((board[0]==board[4])&&(board[0]==board[8])&&(board[0]!='-'))
  {
    game_still_going = 1;
  }
  else if((board[2]==board[4])&&(board[2]==board[6])&&(board[2]!='-'))
  {
    game_still_going = 1;
  }

}

/*------------------------------------*/
                      
void check_if_tie()
{
  if ((board[0]!='-')&&(board[1]!='-')&&(board[2]!='-')&(board[3]!='-')&&(board[4]!='-')&&(board[5]!='-')&&(board[6]!='-')&&(board[7]!='-')&&(board[8]!='-'))
  {
    game_still_going = 1;
  }
}

/*------------------------------------*/
