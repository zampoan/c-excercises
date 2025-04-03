/*
Resource: https://www.w3resource.com/c-programming-exercises/linked_list/index.php
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           // Data of node
    struct Node *next;  // Address of next node
} *head = NULL, *tail = NULL, *tempNode; // pointer to starting node, pointer to end node, pointer to temp node which alternates between end node

void createNodes(int *numberOfNodes){
    /*  
        Create the number of nodes based of numberOfNodes
    */ 
    if (*numberOfNodes <= 0){
        printf("Invalid number of nodes.\n");
        return;
    }

    for(int i = 0; i < *numberOfNodes; i++){
        tempNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Input data for node:");
        scanf("%d", &tempNode->data);

        tempNode->next = NULL;

        // Do the first node, if no address in first node
        if (head == NULL){
            // Put data into first node
            head = tail = tempNode;

        } // Do other nodes if first node is occupied
        else {
            tail->next = tempNode;
            tail = tempNode;

        }
    }
}

void displayNodes(){
    struct Node *current = head;

    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void q1(){
    int numberOfNodes = 0;
    printf("How many nodes: \n");
    scanf("%d", &numberOfNodes);

    createNodes(&numberOfNodes);
    displayNodes();
}

int main(){
    q1();
}