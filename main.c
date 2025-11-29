#include <stdio.h>
#include <conio.h>

void gameBoard();

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};

void main () {
    int player = 1,choice;
    char mark = (player == 1) ? 'X' : 'O';

    scanf("%d", &choice);
    if(choice<1 || choice>9){
        printf("Invalid Move");
    }
    board[choice] = mark;

    gameBoard();
}

void gameBoard(){
printf("----------TIC TAC TOE----------\n");    
printf("            |     |                 \n");
printf("    %c       |  %c  |      %c          \n", board[1], board[2], board[3]);
printf("__ __ __ __ |_ _ _| __ __ __ __      \n");
printf("            |     |                 \n");
printf("    %c       |  %c  |      %c          \n", board[4], board[5], board[6]);
printf("__ __ __ __ |_ _ _| __ __ __ __      \n");
printf("            |     |                 \n");
printf("    %c       |  %c  |      %c          \n", board[7], board[8], board[9]);
printf("            |     |                 \n");
}
