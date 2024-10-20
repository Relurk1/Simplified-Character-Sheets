#include <ncurses.h>
void startView() {
    printw("Select an option:\n");
    printw("\tEnter \'c\' to create a new character\n");
    printw("\tEnter \'l\' to load and existing character\n");
    printw("\tEnter \'q\' to quit\n\n");
    printw(">> ");
}