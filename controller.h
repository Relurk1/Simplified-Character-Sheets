#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include "views.h"

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
        character->Str = 10;
    }
    else {
        character->Str = (int)val;
    }

    printw("Enter DEX score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting DEX to 10. This can be changed later\n\n");
        character->Dex = 10;
    }
    else {
        character->Dex = (int)val;
    }

    printw("Enter CON score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting CON to 10. This can be changed later\n\n");
        character->Con = 10;
    }
    else {
        character->Con = (int)val;
    }

    printw("Enter INT score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting INT to 10. This can be changed later\n\n");
        character->Int = 10;
    }
    else {
        character->Int = (int)val;
    }

    printw("Enter WIS score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting WIS to 10. This can be changed later\n\n");
        character->Wis = 10;
    }
    else {
        character->Wis = (int)val;
    }

    printw("Enter CHA score\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 20) {
        printw("Invalid input, setting CHA to 10. This can be changed later\n\n");
        character->Cha = 10;
    }
    else {
        character->Cha = (int)val;
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

    printw("Press enter to continue...\n>> ");
    getch();

    clear();
    for(int i=0; i<17; i++)
        character->skills[i] = 0;

    char skills[128];
    printw("Enter a space seperated list of all skills with proficiency\n");
    printw(">> ");
    getnstr(skills, sizeof(skills));
    manageSkillString(skills, character, 1);

    memset(skills, '\0', 128);
    printw("Enter a space seperated list of all skills with expertise\n");
    printw(">> ");
    getnstr(skills, sizeof(skills));
    manageSaveString(skills, character);

    getch();
}

void loadController() {
    clear();
    printw("load\n");
    getch();
}