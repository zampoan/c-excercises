/*
    Resource: https://labex.io/tutorials/c-creating-a-2048-game-in-c-298825
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define WIN_CONDITION 2048

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
    int board[SIZE][SIZE] = {{0, 2, 0 ,0}, {0, 3, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int score = 0;
    int direction = 0;

    while (1){

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