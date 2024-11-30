#pragma once

#include <ncurses.h>
#include <stdlib.h>

static const unsigned int MAX_SPELLS = 512;
static unsigned int NUM_SPELLS = 0;
static const unsigned int MAX_WEAPONS = 16;
static unsigned int NUM_WEAPONS = 0;

void createController(Character* character) {
    clear();
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
    for(int i=0; i<18; i++)
        character->skills[i] = 0;

    char skills[128];
    printw("Enter a space seperated list of all skills with proficiency\n");
    printw(">> ");
    getnstr(skills, sizeof(skills));
    manageSkillString(skills, character, 1);

    memset(skills, '\0', 128);
    printw("Enter a space seperated list of all saves with expertise\n");
    printw(">> ");
    getnstr(skills, sizeof(skills));
    manageSaveString(skills, character);

   printw("\nPress Enter to continue...\n>> ");
   getch();
   clear();
}

void loadController() {
    clear();
    printw("load\n");
    getch();
}

void addSpellController(Spell spells[512]) {
    clear();
    if(NUM_SPELLS >= MAX_SPELLS) {
        printw("No more spells can be added\n");
        getch();
        return;
    }
    printw("Add new spell\n");
    Spell spell;
    char buffer[128];
    char *endptr;

    printw("Enter the name of the spell\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    strncpy(spell.name, buffer, 63);
    spell.name[63] = '\0';
    memset(buffer, '\0', sizeof(buffer));

    printw("Enter the level of the spell (0 for cantrip)\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    long val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || val < 0 || val > 9) {
        printw("Invalid value for spell level, setting to 0");
        spell.level = 0;
    }
    else {
        spell.level = (int)val;
    }
    memset(buffer, '\0', sizeof(buffer));

    printw("Enter the components of the spell\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    strncpy(spell.components, buffer, 7);
    spell.components[7] = '\0';
    memset(buffer, '\0', sizeof(buffer));

    printw("Enter the range of the spell\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    strncpy(spell.range, buffer, 31);
    spell.range[31] = '\0';
    memset(buffer, '\0', sizeof(buffer));

    printw("Enter the description of the spell\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    strncpy(spell.description, buffer, 127);
    spell.description[127] = '\0';
    memset(buffer, '\0', sizeof(buffer));

    printw("Does the spell require an attack roll? (Y/n)\n");
    printw(">> ");
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    if(strcmp(buffer, "y") == 0 || strcmp(buffer, "Y") == 0 || strcmp(buffer, "yes") == 0 || strcmp(buffer, "Yes") == 0) {
        spell.attack = 1;
    }
    else if(strcmp(buffer, "no") == 0 || strcmp(buffer, "No") == 0 || strcmp(buffer, "no") == 0 || strcmp(buffer, "No") == 0) {
        spell.attack = 0;
    }
    else {
        printw("unable to parse selected option, setting option to false.\n");
    }
    memset(buffer, '\0', sizeof(buffer));

    spells[NUM_SPELLS] = spell;
    NUM_SPELLS += 1;

    clear();
}

void addWeaponController() {
    return;
}

void parseCommandController() {
    printw("command parsing coming soon\n");
    return;
}