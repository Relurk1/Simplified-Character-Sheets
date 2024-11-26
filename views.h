#pragma once

#include <ncurses.h>
#include "model.h"
#include "controller.h"

void startView() {
    printw("Select an option:\n");
    printw("\tEnter \'c\' to create a new character\n");
    printw("\tEnter \'l\' to load and existing character\n");
    printw("\tEnter \'q\' to quit\n\n");
    printw(">> ");
    refresh();
}

void setupView(Character* character) {
    printw("Character Setup:\n\n");
    printw("\t -All ability scores must be in the range 1-20\n");
    printw("\t -Proficiency bonus must be in the range 2-6\n");
    printw("\t -Skills and saves can have proficiencies set by referencing their 4 character code\n");
    printw("\t -All proficiency multipliers must be in the range 0-2\n\n");
    refresh();
    createController(character);
}

void mainView() {
    clear();
    printw("Main Menu:\n\n");
    printw("\t Enter \'1\' to add a new spell\n");
    printw("\t Enter \'2\' to add a new weapon\n");
    printw("\t Enter \'3\' to quit\n");
    printw("\n>>");
    refresh();
    
    char buffer[16];
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    if(strcmp(buffer, "1") == 0) {
        addSpellController();
        mainView();
    }
    else if(strcmp(buffer, "2") == 0) {
        addWeaponController();
        mainView();
    }
    else if(strcmp(buffer, "3") == 0) {
        return;
    }
    else {
        parseCommandController();
        return;
        //mainView();
    }
}