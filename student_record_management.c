#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void startMenu(){
    printf("=====STUDENT DATABASE MANAGEMENT SYSTEM=====\n\n\n");
    printf("\t1. Add Student Record\n");
    printf("\t2. Show Student Records\n");
    printf("\t3. Search Student\n");
    printf("\t4. Delete Record\n");
    printf("\t5. Exit\n");
    printf("\t----------------------\n");
}

void addStudentInfoMenu(){
    char studentName[20];
    int classID;
    float percentage;

    // Get the info
    printf("======ADD STUDENT INFO======\n\n");
    printf("Enter name: ");
    scanf("%s", studentName);

    printf("\nEnter Class ID: ");
    scanf("%d", &classID);

    printf("\nEnter Percentage: ");
    scanf("%f", &percentage);
    
    // Create record based off info
    struct Record* student = newRecord(studentName, classID, percentage);
}

struct Record {
    char studentName[20];
    int classID;
    float percentage;
    struct Record* next;
};

struct Record* newRecord(char studentName, int classID, float percentage){
    // Function to create a newRecord
    struct Record* temp = (struct Record*)malloc(sizeof(struct Record));
    temp->studentName = studentName;
    temp->classID = classID;
    temp->percentage = percentage;
    temp->next = NULL;
}

int main(){
    bool exit = false;
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
}