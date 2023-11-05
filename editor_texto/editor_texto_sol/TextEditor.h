#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

typedef struct TextEditor TextEditor;

TextEditor* create_text_editor();
void insert_character(TextEditor* editor, char c);
void remove_character(TextEditor* editor);
void move_cursor_left(TextEditor* editor);
void move_cursor_right(TextEditor* editor);
void undo_last_action(TextEditor* editor);
void display_text(TextEditor* editor);
void free_text_editor(TextEditor* editor);

#endif