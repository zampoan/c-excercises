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
        // Iterate through the whole board for non-zeros
        for (int row = 0; row < SIZE; row++){    
            for (int col = 0; col < SIZE; col++){
                
                // Check for non-zero
                if (board[row][col] != 0){

                    // Store the value to be moved
                    numberToBeMoved = board[row][col];

                    // Check the cols, start from the end 
                    for (int row1 = SIZE - 1; row1 >= 0; row1--){


                        // Check for non-zero, if non zero go to next row, if zero
                        // that is the new location, once in new location, break
                        if (board[row1][col] == 0){

                            // Replace the value to be moved to the location
                            board[row1][col] = numberToBeMoved;

                            // replace its prev cords with 0
                            board[row][col] = 0;
                            break;

                        } else {
                            // do nothing
                        }

                    }
                }
            }
            printf("\n");
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
    int board[SIZE][SIZE] = {{9, 2, 0 ,0}, {3, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
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