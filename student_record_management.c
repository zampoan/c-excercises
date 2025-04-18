#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Record {
    char studentName[20];
    int classID;
    float percentage;
    struct Record* next;
};

// Head = start of linked list, tail = end of
struct Record * head = NULL;
struct Record * tail = NULL;

void startMenu(){
    printf("\n=====STUDENT DATABASE MANAGEMENT SYSTEM=====\n\n\n");
    printf("\t1. Add Student Record\n");
    printf("\t2. Show Student Records\n");
    printf("\t3. Search Student\n");
    printf("\t4. Delete Record\n");
    printf("\t5. Exit\n");
    printf("\t----------------------\n");
}

struct Record* newRecord(char* studentName, int classID, float percentage){
    // Function to create a newRecord
    struct Record* temp = (struct Record*)malloc(sizeof(struct Record));
    if (temp == NULL){
        printf("Memory allocated failed.\n");
        exit(1);
    }

    strcpy(temp->studentName, studentName);
    temp->classID = classID;
    temp->percentage = percentage;
    temp->next = NULL;

    return temp;
}

void displayRecord(){
    if (head == NULL){
        printf("No records available.\n");
        return;
    }
    struct Record * current = head;
    while (current != NULL){
        printf("Name: %s\n", current->studentName);
        printf("Class ID: %d\n", current->classID);
        printf("Percentage: %.2f\n", current->percentage);
        current = current->next;
    }
}

void addStudentInfoMenu(){
    char studentName[20];
    int classID;
    float percentage;

    // Get the info
    printf("\n======ADD STUDENT INFO======\n\n");
    printf("Enter name: ");
    scanf("%19s", studentName);

    printf("\nEnter Class ID: ");
    scanf("%d", &classID);

    printf("\nEnter Percentage: ");
    scanf("%f", &percentage);
    
    // Create and Store record based off info
    struct Record* student = newRecord(studentName, classID, percentage);

    if (head == NULL){
        head = student;
        tail = student;
    } else {
        tail->next = student;
        tail = student;
    }
}

int main(){
    bool exit = false;
    struct Record * student;
    int option = 0;

    while(!exit){  
        // Loop to run whole system
        startMenu();
        scanf("%d", &option);

        if (option == 1){
            // Add a student record
            addStudentInfoMenu();

        } else if(option == 2){
            // Show Student Record
            displayRecord(student);
            //free(student);

        } else if (option == 3){
            // Search a student record

        } else if (option == 4){
            // Delete a record
        
        } else if (option == 5) {
            // Exit
            exit = true;

        } else {
            printf("Invalid option. Try again.");
        };
    }

    // Free allocated memory before exiting
    struct Record* current = head;
    while (current != NULL){
        struct Record* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}