#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

struct LineNode {
    char line[MAX_LINE_LENGTH];
    struct LineNode* next;
};

void addLine(struct LineNode** head, char* line) {
    struct LineNode* newNode = (struct LineNode*)malloc(sizeof(struct LineNode));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->line, line, MAX_LINE_LENGTH);
    newNode->next = *head;
    *head = newNode;
}

// void printLastLines(struct LineNode* head, int n) {
//     if (!head) {
//         printf("No lines to print.\n");
//         return;
//     }

//     int count = 0;
//     struct LineNode* temp = head;

//     while (temp) {
//         count++;
//         temp = temp->next;
//     }

//     n = (n > count) ? count : n;

//     int start = count - n;
//     temp = head;

//     for (int i = 0; i < start; i++) {
//         temp = temp->next;
//     }

//     while (temp) {
//         printf("%s", temp->line);
//         temp = temp->next;
//     }
// }

void freeList(struct LineNode* head) {
    while (head) {
        struct LineNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void showlist(struct LineNode* head){
    struct LineNode* curr = head;
    while(curr)
    {
         printf("%s", curr->line);
        curr= curr->next;
    }
}

void print_diff(struct LineNode* head,int n){
    if(n>1)
        {print_diff(head->next,n-1);
        printf("%s",head->line);}
    else
        return;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <n> <filename>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid value of n. Please provide a positive integer.\n");
        return 1;
    }

    FILE* file = fopen(argv[2], "r");
    if (!file) {
        perror("File open error");
        return 1;
    }

    struct LineNode* head = NULL;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        addLine(&head, line);
    }

    fclose(file);

    // showlist(head);
    print_diff(head,n);
    //printf("%s","\n\n");
    // printLastLines(head, n);

    freeList(head);

    return 0;
}
