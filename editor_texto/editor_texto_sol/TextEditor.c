#include "TextEditor.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct CharNode {
    char c;
    struct CharNode* prev;
    struct CharNode* next;
} CharNode;

struct TextEditor{
    CharNode* head;
    CharNode* cursor; // posição atual do cursor no texto
    CharNode* last_action_node; // afetado por uma inserção/remoção por ultimo
    int last_action; // 0 para inserção, 1 para remoção
};

TextEditor* create_text_editor() {
    TextEditor* editor = (TextEditor*)malloc(sizeof(TextEditor));
    if (!editor) return NULL;

    editor->head = NULL;
    editor->cursor = NULL;
    editor->last_action_node = NULL;
    editor->last_action = -1;

    return editor;
}

void insert_character(TextEditor* editor, char c) {
    CharNode* new_node = (CharNode*)malloc(sizeof(CharNode));
    if (!new_node) return;

    new_node->c = c;
    new_node->prev = new_node->next = NULL;

    if (editor->head == NULL || editor->cursor == NULL) {
        new_node->next = editor->head;
        if (editor->head != NULL) {
            editor->head->prev = new_node;
        }
        editor->head = new_node;
        editor->cursor = new_node;
    } else {
        new_node->next = editor->cursor->next;

        if (editor->cursor->next != NULL) {
            editor->cursor->next->prev = new_node;
        }

        new_node->prev = editor->cursor;
        editor->cursor->next = new_node;
        editor->cursor = new_node;
    }

    editor->last_action_node = new_node;
    editor->last_action = 0;
}


void remove_character(TextEditor* editor) {
    if (editor->cursor == NULL || editor->cursor->next == NULL) return;

    CharNode* to_remove = editor->cursor->next;

    if (to_remove == editor->head) {
        editor->head = to_remove->next;
    }
    if (to_remove->prev != NULL) {
        to_remove->prev->next = to_remove->next;
    }
    if (to_remove->next != NULL) {
        to_remove->next->prev = editor->cursor;
    }
    editor->cursor->next = to_remove->next;

    editor->last_action_node = to_remove;
    editor->last_action = 1;
}


void move_cursor_left(TextEditor* editor) {
    if (editor->cursor != NULL && editor->cursor->prev != NULL) {
        editor->cursor = editor->cursor->prev;
    }
}

void move_cursor_right(TextEditor* editor) {
    if (editor->cursor != NULL && editor->cursor->next != NULL) {
        editor->cursor = editor->cursor->next;
    } else if (editor->cursor == NULL && editor->head != NULL) {
        editor->cursor = editor->head;
    } else if (editor->cursor != NULL && editor->cursor->next == NULL) {
        insert_character(editor, ' ');
    }
}

void undo_last_action(TextEditor* editor) {
    if (editor->last_action_node == NULL) return;

    if (editor->last_action == 0) {
        remove_character(editor);
        editor->cursor = editor->last_action_node->prev;
    } else if (editor->last_action == 1) {
        CharNode* to_reinsert = editor->last_action_node;
        if (to_reinsert->prev) {
            to_reinsert->prev->next = to_reinsert;
        }
        if (to_reinsert->next) {
            to_reinsert->next->prev = to_reinsert;
        }
        if (to_reinsert->prev == NULL) {
            editor->head = to_reinsert;
        }
    }

    editor->last_action_node = NULL;
    editor->last_action = -1;
}

void display_text(TextEditor* editor) {
    CharNode* current = editor->head;
    while (current != NULL) {
        printf("%c", current->c);
        if (current == editor->cursor) {
            printf("|");
        }
        current = current->next;
    }
    if (editor->cursor == NULL) {
        printf("|");
    }
    printf("\n");
}

void free_text_editor(TextEditor* editor) {
    CharNode* current = editor->head;
    while (current != NULL) {
        CharNode* next = current->next;
        free(current);
        current = next;
    }
    free(editor);
}




