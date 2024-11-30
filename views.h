#pragma once

#include <ncurses.h>
#include "model.h"
#include "controller.h"

void startView();
void setupView(Character* character);
void mainView(Character* character, Spell* spells, Weapon* weapons);
void spellListView(Spell* spells);
void weaponListView(Weapon* weapons);

void startView() {
    printw("Select an option:\n");
    printw("\tEnter \'c\' to create a new character\n");
    printw("\tEnter \'l\' to load an existing character\n");
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

void mainView(Character* character, Spell* spells, Weapon* weapons) {
    printw("Main Menu:\n\n");
    printw("\t Enter \'1\' to add a new spell\n");
    printw("\t Enter \'2\' to add a new weapon\n");
    printw("\t Enter \'3\' to view all spells\n");
    printw("\t Enter \'4\' to view all weapons\n");

    printw("\n\t Enter \'e\' to export character data to file\n");
    printw("\t Enter \'q\' to quit\n");
    printw("\n>> ");
    refresh();
    
    char buffer[16];
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    if(strcmp(buffer, "1") == 0) {
        addSpellController(spells);
        mainView(character, spells, weapons);
    }
    else if(strcmp(buffer, "2") == 0) {
        addWeaponController(weapons);
        mainView(character, spells, weapons);
    }
    else if(strcmp(buffer, "3") == 0) {
        spellListView(spells);
        mainView(character, spells, weapons);
    }
    else if(strcmp(buffer, "4") == 0) {
        weaponListView(weapons);
        mainView(character, spells, weapons);
    }
    else if(strcmp(buffer, "e") == 0) {
        return;
        //exportData();
    }
    else if(strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
        return;
    }
    else {
        parseCommandController();
        mainView(character, spells, weapons);
    }
}

void spellListView(Spell* spells) {
    clear();
    if(NUM_SPELLS == 0) {
        printw("No spells saved\n");
        printw("\nPress enter to continue...\n>> ");
        getch();
        clear();
        return;
    }
    for(unsigned int i=0; i<NUM_SPELLS; i++) {
        printw("ID: %d\n", i);
        printw("%s: level %d spell\n", spells[i].name, spells[i].level);
        printw("Components: %s\n", spells[i].components);
        printw("Range: %s\n", spells[i].range);
        printw("%s\n\n", spells[i].description);
    }
    printw("\nPress enter to continue...\n>> ");
    getch();
    clear();
}

void weaponListView(Weapon* weapons) {
    clear();
    if(NUM_WEAPONS == 0) {
        printw("No weapons saved\n");
        printw("\nPress enter to continue...\n>> ");
        getch();
        clear();
        return;
    }
    for(unsigned int i=0; i<NUM_WEAPONS; i++) {
        printw("ID: %d\n", i);
        printw("%s: %s %s damage\n\n", weapons[i].name, weapons[i].damage, weapons[i].damageType);

    }
    printw("\nPress enter to continue...\n>> ");
    getch();
    clear();
}