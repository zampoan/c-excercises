#include <stdio.h>
#include <stdlib.h>

int generateNumber(){
    int randX = rand() % 4;
    int randY = rand() % 4;

    printf("X: %d | Y: %d\n", randX, randY);
    return 1;
}


int main(){
    int number = 1;

    while (number < 100){
        generateNumber();
        number += 1;
    }

}
