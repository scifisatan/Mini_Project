/*Importing Required Library*/
#include <stdio.h>

/*Declaring Global Variables*/
char board[9] = {'-', '-', '-',
                 '-', '-', '-',
                 '-', '-', '-'};

/*Calling all the user defined functions*/
void start();           // Prints starting guide
char player();          // Lets  player to choose X or O
void display_board();   // Tic-Tac-Toe Board
void handle_turn(char); // Lets player to pick position
int check_for_winner(); // Checks if someone won
int check_if_tie();     // Checks if there's a tie

int main()
{
    start();
    char current_player = player();
    display_board();

    while (1 == 1)
    {
        printf("%c's turn\n", current_player);
        handle_turn(current_player);
        display_board();
        if (check_if_tie() == 1)
        {
            printf("\nTie!!!");
            return 0;
        }
        if (check_for_winner() == 1)
        {
            printf("\n%c won!", current_player);
            return 0;
        }
        current_player = (current_player == 'O') ? 'X' : 'O'; //changes player's turn
    }
}

void start()
{
    printf("-------------------TIC TAC TOE---------------------");
    printf("\n             Let' start the game.\n");
    printf("The positions that will be used in this game are here: \n");
    printf("                   1 | 2 | 3 \n");
    printf("                  ---|---|---\n");
    printf("                   4 | 5 | 6 \n");~
    printf("                  ---|---|---\n");
    printf("                   7 | 8 | 9 \n\n");
}

char player()
{
    char checks_player;
    printf("Player 1!! \nWhat do you want to choose? (X/O) ");
    scanf(" %c", &checks_player);

    if (checks_player == 'x')
        return 'X';
    else if (checks_player == 'o')
        return 'O';
    else if ((checks_player == 'O') || (checks_player == 'X'))
        return checks_player;

    printf("Invalid Input!!\n");
    printf("Try Again!!\n\n");
    player();
}

void display_board()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[6], board[7], board[8]);
}

void handle_turn(char xo)
{
    int position;
    printf("Choose a postiton from 1 to 9: ");
    fflush(stdin);
    scanf("%d", &position);

    if (position < 10 && board[position - 1] == '-')
        board[position - 1] = xo;

    else
    {
        if (position > 9)
            printf("Invalid Input\n");
        else if (board[position - 1] != '-')
            printf("You can't go there\n");
        handle_turn(xo);
    }
}

int check_for_winner()
{
    /**/ if ((board[0] == board[1]) && (board[0] == board[2]) && (board[0] != '-'))
        return 1;
    else if ((board[3] == board[4]) && (board[3] == board[5]) && (board[3] != '-'))
        return 1;
    else if ((board[6] == board[7]) && (board[6] == board[8]) && (board[6] != '-'))
        return 1;
    else if ((board[0] == board[3]) && (board[0] == board[6]) && (board[0] != '-'))
        return 1;
    else if ((board[1] == board[4]) && (board[1] == board[7]) && (board[1] != '-'))
        return 1;
    else if ((board[2] == board[5]) && (board[2] == board[8]) && (board[2] != '-'))
        return 1;
    else if ((board[0] == board[4]) && (board[0] == board[8]) && (board[0] != '-'))
        return 1;
    else if ((board[2] == board[4]) && (board[2] == board[6]) && (board[2] != '-'))
        return 1;
}

int check_if_tie()
{
    int tie = 0;
    for (int i = 0; i < 9; i++)
        if ('-' != board[i])
            tie++;
    if (tie == 9)
        return 1;
    else
        return 0;
}
