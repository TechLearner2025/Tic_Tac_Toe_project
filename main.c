#include <stdio.h>

// Global variables for the game board and player scores
char board[3][3];
int playerXscore = 0;
int playerOscore = 0;

// Function to reset the board with empty spaces
void resetBoard()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            board[row][col] = ' ';
        }
    }
}

// Function to display the game board
void showBoard()
{
    printf("\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf(" %c ", board[row][col]);
            if (col < 2)
            {
                printf("│");  // Separating columns
            }
        }
        printf("\n");
        if (row < 2)
        {
            printf("═══╪═══╪═══\n");  // Updated row separator pattern
        }
    }
    printf("\n");
}

// Function to check if a player has won
char determineWinner()
{
    // Check rows for a win
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ')
        {
            return board[row][0];  // Return the winner's symbol
        }
    }

    // Check columns for a win
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ')
        {
            return board[0][col];
        }
    }

    // Check the main diagonal for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }

    // Check the opposite diagonal for a win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&  board[0][2] != ' ')
    {
        return board[0][2];
    }

    return ' ';  // No winner yet
}

// Function to check if the board is full
int boardIsFull()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == ' ')
            {
                return 0;  // Board is not full
            }
        }
    }
    return 1;  // Board is full
}

// Function to play a single game round
void startGame()
{
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ' ;
    int moveCount = 0;

    resetBoard();

    while (1)
    {
        showBoard();
        printf("Player %c, enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Adjust input for zero-based indexing
        row--;
        col--;

        // Validate move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Place the move on the board
        board[row][col] = currentPlayer;
        moveCount++;

        // Check if the player has won
        if (moveCount >= 5)
        {
            winner = determineWinner();
            if (winner != ' ')
            {
                showBoard();
                printf("Player %c wins! \n", winner);

                // Update the scoreboard
                if (winner == 'X')
                {
                    playerXscore++;
                }
                else
                {
                    playerOscore++;
                }
                break;
            }
        }

        // Check for a draw
        if (moveCount == 9)
        {
            showBoard();
            printf("It's a draw.\n");
            break;
        }

        // Switch turns
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Function to display the current score
void showScore()
{
    printf("\nCurrent Score:\n");
    printf("Player X: %d\n", playerXscore);
    printf("Player O: %d\n", playerOscore);
}

// Main function to control the game flow
int main()
{
    char playAgain;

    do
    {
        startGame();
        showScore();

        printf("you want to play again? press (y/n): ");
        scanf(" %c", &playAgain);
    }
    while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
