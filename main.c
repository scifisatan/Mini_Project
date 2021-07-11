/*Importing Required Library*/
#include <stdio.h>
#include <unistd.h>


/*Declaring Global Variables*/
int tie = 0;
char winner;
char current_player;
int game_still_going = 1;
char board[9] = {'-', '-', '-',
                 '-', '-', '-',
                 '-', '-', '-'};
                    

/*Calling all the user defined functions*/
char player(); //lets  player to choose X or O
void display_board(); // Tic-Tac-Toe Board
void handle_turn(); // Lets player to pick position
void check_for_winner(); // Checks if someone won
void check_if_tie(); // Checks if there's a tie


/*Main function*/
int main()
{
  printf("-------------------TIC TAC TOE---------------------");
  printf("\n             Let' start the game.\n");
  printf("The positions that will be used in this game are here: \n");
  printf(" 1 | 2 | 3 \n");
  printf("---|---|---\n");
  printf(" 4 | 5 | 6 \n");
  printf("---|---|---\n");
  printf(" 7 | 8 | 9 \n\n");
  
  current_player = player();
  display_board(); 

  while (game_still_going == 1)
    {
      printf("%c's turn\n",current_player);
      handle_turn ();
      display_board();
      check_if_tie();
      check_for_winner();
      winner = current_player;// Assumes current player as winner if game ends
      current_player = (current_player=='O')?'X':'O'; //flips player
    }

  if (tie == 1)
  {
      printf("Tie");
  }
  else 
  {
      printf("%c won!", winner);
  }
  return 0;
}


/*Lets the first player to choose  between X and O*/
char player() //use recursive funtion for optimization
{
    char checks_player;
    printf("Player 1!! \nWhat do you want to choose? (X/O) ");
    scanf(" %c",&checks_player);

    if(checks_player == 'x') return 'X';
    else if(checks_player == 'o') return 'O';
    else if((checks_player == 'O')|| (checks_player == 'X')) return checks_player; 
    
    printf("Invalid Input!!\n");
    printf("Try Again!!\n\n");
    player();
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


void handle_turn()
{ 
    int position;
    printf("Choose a postiton from 1 to 9: ");
    fflush(stdin);
    scanf("%d", &position);

    if (position < 10 && board[position-1] == '-')
    {
        board[position-1] = current_player; 
    }
    else 
    { 
        if (position>9) printf("Invalid Input\n");
        else if (board[position-1] != '-') printf("You can't go there\n");
        handle_turn();   
    }  
}

/*Checks for winner*/
void check_for_winner()
{
  /**/ if((board[0]==board[1])&&(board[0]==board[2])&&(board[0]!='-')) game_still_going = 0;
  else if((board[3]==board[4])&&(board[3]==board[5])&&(board[3]!='-')) game_still_going = 0;
  else if((board[6]==board[7])&&(board[6]==board[8])&&(board[6]!='-')) game_still_going = 0;
  else if((board[0]==board[3])&&(board[0]==board[6])&&(board[0]!='-')) game_still_going = 0;
  else if((board[1]==board[4])&&(board[1]==board[7])&&(board[1]!='-')) game_still_going = 0;
  else if((board[2]==board[5])&&(board[2]==board[8])&&(board[2]!='-')) game_still_going = 0;
  else if((board[0]==board[4])&&(board[0]==board[8])&&(board[0]!='-')) game_still_going = 0;
  else if((board[2]==board[4])&&(board[2]==board[6])&&(board[2]!='-')) game_still_going = 0;
}

/*Checks if tie*/                  
void check_if_tie()
{ 
  tie = 0;
  for(int i = 0; i < 9; i++)
  {
      if ('-'!=board[i]) tie++;
  }
  if (tie == 9)
  {
    game_still_going = 0;
    tie = 1;
  }
}
