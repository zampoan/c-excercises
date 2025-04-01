#include <stdio.h>

void q1(){
    int m = 10;
    int n, o;
    int *z = &m;
    printf(" Pointer : Show the basic declaration of pointer : \n");
    printf("-------------------------------------------------------  \n");
    printf("Here is m=%d, n and o are two integer variable and *z is an integer   \n", m);
    printf("z stores the address of m = %d\n", z);
    printf("*z stores the value of m = %d\n", *z);
    printf("&m is the address of m = %d\n", &m);
    printf("&n stores the address of n =%d\n ", &n);
}

void q2(){
    int m = 29;
    int *z = &m;

    int *ab = &m;

    printf("Address of m: %d\n", &m);
    printf("Value of m: %d\n", *z);

    printf("Address of ab: %d\n", ab);
    printf("Content of pointer ab: %d\n", *ab);

    m = 34;
    printf("Address of pointer ab: %d\n", ab);
    printf("Content of ab: %d\n", *ab);

    *ab = 7;
    printf("Address of m: %d\n", &m);
    printf("Value of m: %d\n", m);

}

void q3(){
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    int *p1 = &m;
    float *p2 = &fx;
    char *p3 = &cht;

    printf("Address of %d \n Address of %d \n Address of %d\n", &m, &fx, &cht);
    printf("Value of m: %d \n Value of fx: %f \n Value of cht: %c \n", *p1, *p2, *p3);
}

void q4(){
    int first, second, result, *ptr1, *ptr2;
    printf("Input first number: \n");
    scanf("%d", &first);
    printf("Input second number: \n");
    scanf("%d", &second);

    ptr1 = &first;
    ptr2 = &second;

    result = *ptr1 + *ptr2;
    printf("Output: %d\n", result);

}

int addition(int *ptr1, int *ptr2){
    return *ptr1 + *ptr2;
}

void q5(){
    int first, second, output;
    printf("Input first number: \n");
    scanf("%d", &first);
    printf("Input second number: \n");
    scanf("%d", &second);
    output = addition(&first, &second);
    printf("Output: %d\n", output);
} 

void q6(){
    int first = 32, second = 26, *ptr1, *ptr2;
    ptr1 = &first;
    ptr2 = &second;

    if (*ptr1 > *ptr2){
        printf("Ptr1 is bigger");
    } else {
        printf("Ptr2 is bigger");
    }
}

void permutation(char * string, int * leftIndex, int * rightIndex){
    // *string gives a single character, so we use string
    if (string[*leftIndex] == string[*rightIndex]){
        printf("%s", string);

    } else {
        // leftIndex is 0, rightIndex is 3
        for (int i = *leftIndex; i <= *rightIndex; i++ ){
            
        }

    }
}

void q8(){
    char permuteString[] = "dbcd";
    int leftIndex = 0, rightIndex = 3;
    
    // Pass by reference
    permutation(&permuteString, &leftIndex, &rightIndex);


}

void q9(){
    int 
    
}

int main(){
    q9();
    return 0;
}