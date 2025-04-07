#include <stdio.h>

void fixedSizedArr(){
    int arr[5];
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    int idx = 0;
    int newElement = 44;

    printf("Before: \n");
    for (int i = 0; i < arrLength; i++){
        printf("%d\n", arr[i]);
    }

    if (idx < arrLength){
        arr[idx] = newElement;
    }

    printf("After: \n");
    for (int i = 0; i < arrLength; i++){
        printf("%d\n", arr[i]);
    }
}


int main(){
    fixedSizedArr();
}
