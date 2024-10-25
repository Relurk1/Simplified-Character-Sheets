#pragma once

#include <ncurses.h>
void startView() {
    printw("Select an option:\n");
    printw("\tEnter \'c\' to create a new character\n");
    printw("\tEnter \'l\' to load and existing character\n");
    printw("\tEnter \'q\' to quit\n\n");
    printw(">> ");
    refresh();
}

void setupView() {
    printw("Character Setup:\n\n");
    printw("\t -All ability scores must be in the range 1-20\n");
    printw("\t -Proficiency bonus must be in the range 2-6\n");
    printw("\t -Skills and saves can have proficiencies set by referencing their 4 character code\n");
    printw("\t -All proficiency multipliers must be in the range 0-2\n\n");
    refresh();
}