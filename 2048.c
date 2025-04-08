/*
    Resource: https://labex.io/tutorials/c-creating-a-2048-game-in-c-298825
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4
#define WIN_CONDITION 2048

void generateNumber(bool *isBoardZero, int (*board)[SIZE]){
    /*
    At start generates two numbers, at two different locations. 
    Continues to generate one number at a location which contains a zero, 
    after each movement.

    Args:
        - board: the boardstate

    Returns:
        - board: the board state
    */
    // X and Y cords
    int randX_1 = rand() % 4;
    int randY_1 = rand() % 4;
    int randX = rand() % 4;
    int randY = rand() % 4;
    int randX_2 = rand() % 4;
    int randY_2 = rand() % 4;

    // Make sure that pos generated is not the same
    do {
        randX_1 = rand() % 4;
        randY_1 = rand() % 4;
        randX = rand() % 4;
        randY = rand() % 4;
    } while (randX_1 == randX && randY_1 == randY);
    

    // Randomly generate two positions
    if (*isBoardZero){
        board[randX][randY] = 2;
        board[randX_1][randY_1] = 2;

        *isBoardZero = false;

    } // Randomly generate one position
    else {
        // Look through the board that is non-zero
        board[randX_1][randY_2] = 2;

    }
    

}

int moveBoard(int *direction, int (*board)[SIZE]){
    /*
    Takes the direction and moves all of the numbers in the board in a specific direction. 
    Iterates through the loop, checking for non-zero, if it finds a non-zero, it checks the row (or col) 

    Args:
        - int *direction: pointer to direction variable
        - int board: 2d array of the board

    Returns:
        - Board, with the updated board
    */
    int numberToBeMoved = 0;

    // Shifting Up
    if (*direction == 0){

        // Count forwards, start at [0][0]
        for (int row = 0; row < SIZE; row++){
            for (int col = 0; col < SIZE; col++){

                // Look for non zeros
                if (board[row][col] != 0){

                    // When non-zero is found, set it to numberToBeMoved
                    numberToBeMoved = board[row][col];

                    // Start from top, check if current row has 0
                    for (int row1 = 0; row1 < SIZE; row1++){

                        // When row has a 0
                        if (board[row1][col] == 0){

                            // Set the new position to be the value, set old position to 0
                            board[row1][col] = numberToBeMoved;
                            board[row][col] = 0;
                            break;

                        }
                    }

                }

            }
        }
        
    // Shifting Down
    } 
    else if(*direction == 1){

        // Count backwards instead, start at [SIZE][SIZE]
        for (int row = 3; row >= 0; row--){
            for (int col = 3; col >= 0; col--){

                // Look for non-zeros
                if (board[row][col] != 0){

                    // When non-zero is found, set it to numberToBeMoved
                    numberToBeMoved = board[row][col];
                    
                    // Starting from the bottom, check to see if current row has 0 
                    for (int row1 = 3; row1 >=0; row1--){
                        
                        // If row is zero
                        if (board[row1][col] == 0){

                            // Set the new position to be the value, set old position to 0
                            board[row1][col] = numberToBeMoved;
                            board[row][col] = 0;
                            break;
                        } 
                    }
                }
            }
        }

    } 
    // Shifting Left
    else if (*direction == 2){
        

    } 
    // Shifting Right
    else if (*direction == 3){

    } 
    else {
        printf("Unknown direction.\n");
    }

    return board;
};

int main(){
    int board[SIZE][SIZE] = {{0, 0, 0 ,0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int score = 0;
    int direction = 0;
    bool isBoardZero = true;

    while (1){
        generateNumber(&isBoardZero, board);

        // Output the Score and the board
        printf("Score: %d\n", score);
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                printf("%d\t", board[i][j]);
            }
            printf("\n");
        }

        // Get input
        printf("Enter the move direction (0-Up, 1-Down, 2-Left, 3-Right)\n");
        scanf("%d", &direction);

        // Move the board to the direction that was inputted
        moveBoard(&direction, board);
    }
}