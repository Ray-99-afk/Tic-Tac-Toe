#include <stdio.h>

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};

void gameBoard(void);
int checkWin(void);

int main(void) {
    int player = 1, choice, status = -1;
    char mark;

    gameBoard();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter a number: ", player);
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            printf("Invalid input\n");
            continue;
        }

        if (choice < 1 || choice > 9) {
            printf("Invalid Move\n");
            continue;
        }

        if (board[choice] == 'X' || board[choice] == 'O') {
            printf("Cell already taken\n");
            continue;
        }

        board[choice] = mark;  
        gameBoard();

        status = checkWin();    

        if (status == 1) {
            printf("==>\aPlayer %d wins\n", player);
            break;
        } else if (status == 0) {
            printf("==>\aGame draw\n");
            break;
        }

        player++;
    }

    return 0;
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

int checkWin(){
    if(board[1]==board[2] && board[2]==board[3]) return 1;
    if(board[4]==board[5] && board[5]==board[6]) return 1;
    if(board[7]==board[8] && board[8]==board[9]) return 1;
    if(board[1]==board[4] && board[4]==board[7]) return 1;
    if(board[2]==board[5] && board[5]==board[8]) return 1;
    if(board[3]==board[6] && board[6]==board[9]) return 1;
    if(board[1]==board[5] && board[5]==board[9]) return 1;
    if(board[3]==board[5] && board[5]==board[7]) return 1;

    int count = 0;
    for(int i = 1; i <= 9; i++){   
        if(board[i] == 'X' || board[i] == 'O') count++;
    }

    if(count == 9) return 0; 
    return -1;               
}
