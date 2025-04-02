/*
Resource: https://www.w3resource.com/c-programming-exercises/linked_list/index.php
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           // Data of node
    struct Node *next;  // Address of next node
} *head, *tail, *newNode, *temp;                // pointer to starting node

void createNodes(int *numberOfNodes){
    /*  
        Create the number of nodes based of numberOfNodes
    */ 
    // Step 1: Allocate memory
    head = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = NULL;
    tail = head;

    // Step 2: Loop to create remaining nodes
    for(int i = 1; i < *numberOfNodes + 1; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = 11 + i;
        newNode->next = NULL;
        
        // Link previous node to new node
        tail->next = newNode;
        
        // Move tail to newNode
        tail = newNode;
    }

    // Display the nodes
    temp = head;
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void q1(){
    int numberOfNodes = 0;
    printf("How many nodes: \n");
    scanf("%d", &numberOfNodes);

    createNodes(&numberOfNodes);
}

int main(){
    q1();
}