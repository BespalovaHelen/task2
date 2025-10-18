#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct WordNode {
    char* word;
    struct WordNode* next;
} WordNode;

WordNode* create_node(const char* word) {
    WordNode* new_node = (WordNode*)malloc(sizeof(WordNode));
    new_node->word = (char*)malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

void add_to_list(WordNode** head, const char* word) {
    WordNode* new_node = create_node(word);
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        WordNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(WordNode* head) {
    WordNode* current = head;
    while (current != NULL) {
        printf("%s", current->word);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void remove_matching_words(WordNode** head) {
    if (*head == NULL) return;
    
    WordNode* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    char* last_word = current->word;
    
    WordNode* prev = NULL;
    current = *head;
    
    while (current != NULL) {
        if (strcmp(current->word, last_word) == 0 && current->next != NULL) {
            if (prev == NULL) {
                *head = current->next;
                free(current->word);
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                free(current->word);
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}
\

int main() {
    char input[1000];
    WordNode* word_list = NULL;
    
    scanf("%999[^\n]",input);
    
    char* token = strtok(input, " \t");
    while (token != NULL) {
        add_to_list(&word_list, token);
        token = strtok(NULL, " \t");
    }
    
    remove_matching_words(&word_list);
    print_list(word_list);
    
    WordNode* current = word_list;
    while (current != NULL) {
        WordNode* temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }
    
    return 0;
}
