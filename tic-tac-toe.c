#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct 
{
    int player1,player2,draw;
}score;

score s={0,0,0};

void clear_screen();
void print_board(char board[3][3]);
int check_win(char board[3][3],char player);
int check_draw(char board[3][3]);
void play_game();
void player_move(char board[3][3],char player);

int main()
{
    srand(time(0));
    int choice;
    do
    {
        play_game();
        printf("\nDo you want to play again? (1 for yes, 2 for no): ");
        scanf("%d",&choice);
    }while(choice==1);
    printf("\nThank you for playing! ");

    return 0;
}

void clear_screen()
{
    #ifdef _Win32
        system("cls");
    #else
        system("clear");
    #endif
}
void  print_board(char board[3][3])
{
    int i,j;
    clear_screen();
    printf("Score - X=%d  0=%d  Draw=%d",s.player1,s.player2,s.draw);

    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<2)
            {
                printf("|");
            }
        }
        if(i<2)
        {
            printf("\n---+---+---");
        }
    }
      
}

int check_win(char board[3][3],char player)
{
    int i;
    for(i=0;i<3;i++)
    {
        if((board[i][0]==player && board[i][1]==player && board[i][2]==player)
        || (board[0][i]==player && board[1][i]==player && board[2][i]==player))
        {
            return 1;
        }
    }

    if((board[0][0]==player && board[1][1]==player && board[2][2]==player) 
    || (board[0][2]==player && board[1][1]==player && board[2][0]==player))
    {
        return 1;
    }

    return 0;
}

int check_draw(char board[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void play_game()
{
    char board[3][3]={
        {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}
    };
    char current_player;
    print_board(board);
    current_player=(rand()%2==0) ? 'X':'0'; 
    while(1)
    {     
        if(current_player=='X')
        {
            player1_move(board,'X');
            print_board(board); 
            if(check_win(board,'X'))
            {
                s.player1++;
                print_board(board); 
                printf("\nCongratulations! Player X won!! ");
                break;
            }
            current_player='0';
        }

        else
        {
            player2_move(board,'0');
            print_board(board); 
            if(check_win(board,'0'))
            {
                s.player2++;
                print_board(board); 
                printf("\nnCongratulations! Player 0 won!!");
                break;
            }
            current_player='X';
        }

        if(check_draw(board))
        {
            s.draw++;
            printf("\nIt's a draw!");  
            break;
        }
    }
}

void player_move(char board[3][3],char player)
{
    int row,col;
    do
    {
        printf("\nPlayer %c's turn",player);
        printf("\nEnter row and column(1-3): ");
        scanf("%d%d",&row,&col);
        row--,col--;
    } while (row<0 || col<0 || row>2 || col>2 || board[row][col] !=' ');
    board[row][col]=player;  
}
