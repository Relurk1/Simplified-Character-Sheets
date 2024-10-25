#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include "views.h"
#include "model.h"

void createController(Character* character) {
    clear();
    setupView();
    char buffer[16];
    char *endptr;

    printw("Enter STR score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    long val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting STR to 10. This can be changed later\n\n");
        character->STR = 10;
    }
    else {
        character->STR = (int)val;
    }

    printw("Enter DEX score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting DEX to 10. This can be changed later\n\n");
        character->DEX = 10;
    }
    else {
        character->DEX = (int)val;
    }

    printw("Enter CON score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting CON to 10. This can be changed later\n\n");
        character->CON = 10;
    }
    else {
        character->CON = (int)val;
    }

    printw("Enter INT score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting INT to 10. This can be changed later\n\n");
        character->INT = 10;
    }
    else {
        character->INT = (int)val;
    }

    printw("Enter WIS score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting WIS to 10. This can be changed later\n\n");
        character->WIS = 10;
    }
    else {
        character->WIS = (int)val;
    }

    printw("Enter CHA score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting CHA to 10. This can be changed later\n\n");
        character->CHA = 10;
    }
    else {
        character->CHA = (int)val;
    }

    printw("\nEnter Proficiency Bonus\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 2 || val > 6) {
        printw("Invalid input, setting Proficiency Bonus to 2. This can be changed later\n\n");
        character->proficiency = 2;
    }
    else {
        character->proficiency = (int)val;
    }

    getch();
}

void loadController() {
    clear();
    printw("load\n");
    getch();
}