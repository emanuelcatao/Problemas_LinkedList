#include <stdio.h>
#include <stdlib.h>
#include "TextEditor.h"

int main() {
    TextEditor* editor = create_text_editor();
    char command;
    char ch;

    while(1) {
        scanf(" %c", &command);
        switch(command) {
            case 'I': // Inserir
                scanf(" %c", &ch);
                insert_character(editor, ch);
                break;
            case 'R': // Remover
                remove_character(editor);
                break;
            case 'L': // Mover esquerda
                move_cursor_left(editor);
                break;
            case 'E': // Mover direita
                move_cursor_right(editor);
                break;
            case 'D': // Desfazer
                undo_last_action(editor);
                break;
            case 'S': // Sair
                free_text_editor(editor);
                printf("Saindo do editor...\n");
                return 0;
            default:
                printf("Comando desconhecido.\n");
        }
        display_text(editor);
    }
    
    return 0;
}
