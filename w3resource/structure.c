#include <string.h>
#include <stdio.h>
void q1(){
    struct Student {
        char name[30];
        int age;
        int totalMarks;
    };
    
    struct Student s1;
    struct Student s2;

    strcpy(s1.name, "Ben");
    strcpy(s2.name, "Jerry");
    s1.age = 20;
    s2.age = 21;
    s1.totalMarks = 96;
    s2.totalMarks = 57;

    printf("Student 1 name: %s\n", s1.name);
    printf("Student 1 age: %d\n", s1.age);

    printf("Student 2 name: %s\n", s2.name);
    printf("Student 2 age: %d\n", s2.age);
    
    int averageMarks = (s1.totalMarks + s2.totalMarks) / 2;
    printf("Average Marks: %d", averageMarks);
    
}

void q5(){
    struct Employee {
        int employeeID;
        char name[30];
        int salary;
    };

    struct Employee employee1;
    
    printf("Employee ID: \n");
    scanf("%d", &employee1.employeeID);
    printf("Employee 1 name: \n");
    scanf("%s", &employee1.name);
    printf("Employee salary: \n");
    scanf("%d", &employee1.salary);

    printf("Employee 1 id: %d\n Employee 1 name: %s\n Employee 1 salary: %d\n", employee1.employeeID, employee1.name, employee1.salary);
}

void q7(){

}

typedef struct Complex {
    float real;
    float imaginary;
} Complex;

void q8(){
    Complex c1;
    Complex c2;

    printf("Enter Real and Complex number for c1: \n");
    scanf("%f %f", &c1.real, &c1.imaginary);
    printf("Enter Real and Complex number for c2: \n");
    scanf("%f %f", &c2.real, &c2.imaginary);

    add(&c1, &c2);

}

void add(const Complex *c1, const Complex *c2 ){
    float realAddition = c1->real + c2->real;
    float imaginaryAddition = c1->imaginary + c2->imaginary;

    printf("%f+%fi \n", realAddition, imaginaryAddition);
}

void q9(){
    int x = 5;
    int *ptr = (int *) malloc(x * sizeof(int));
    
    for (int i = 0; i < x; i++){
        printf("%d\n", ptr[i]);
    }

}

void swapNumbers(int * n1, int * n2, int *n3);

void q11(){
    int n1, n2, n3;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    printf("Before: \n");
    printf("n1: %d | n2: %d | n3: %d\n", n1, n2, n3);
    swapNumbers(&n1, &n2, &n3);
    printf("After: \n");
    printf("n1: %d | n2: %d | n3: %d\n", n1, n2, n3);

}

void swapNumbers(int * n1, int * n2, int *n3){
    /*
    How the numbers are swapped
    n1 -> n2
    n2 -> n3
    n3 -> n1
    */
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = *n3;
    *n3 = temp;
}

void factorial(int * number);

void q12(){
    int input;
    printf("input number:\n");
    scanf("%d", &input);
    factorial(&input);
};

void factorial(int * number){
    int result = 1;
    for (*number; *number>0; (*number)--){
        printf("%d | %d \n", *number, result);
        result = *number * result;
    }
    printf("%d", result);
}

void q13(){
    char constants = {'a', 'e', 'i', 'o', 'u'};
    char word = "game";
    
}

int main(){
    q12();      
    return 0;   
}