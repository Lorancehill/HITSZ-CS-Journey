#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createList(int arr[], int n){
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n ; i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode -> data = arr[i];
        newNode -> next = NULL;
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head){
    Node* p = head;
    while (p != NULL){
        printf("%d ->", p ->data);
        p = p -> next;
    }
    printf("NULL\n");
}

void deleteNode (Node** head, int val){
    Node* current = *head, *prev = NULL;
    if (current != NULL && current -> data == val){
        *head = current -> next;
        free(current);
        return;
    }
    while (current != NULL && current -> data != val){
        prev = current;
        current = current -> next;

    }
    if (current == NULL) return;
    prev -> next = current -> next;
    free(current);
}

void saveToFile(Node* head, const char* filename){
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return;

    Node* p = head;
    while (p != NULL){
        fwrite(&(p -> data), sizeof(int), 1, fp);
        p = p -> next;
    }
    fclose(fp);
}

Node* loadFromFile(const char* filename){
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return NULL;
    Node *head = NULL, *tail = NULL;
    int tempData;
    while(fread(&tempData,sizeof(int), i, fp) == 1){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode -> data = tempData;
        newNode -> next = NULL;
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    fclose(filename);
    return head;
}