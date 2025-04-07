#include <stdio.h>
#include <stdlib.h>

int main(){
    int board[4][4] = {{0, 0, 0 ,0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int count = 16;

    for (int row = 3; row >= 0; row--){
        for (int col = 3; col >= 0; col--){

            board[row][col] = count;
            count = count - 1;

            printf("%d ", board[row][col]);
        }
    }

}
