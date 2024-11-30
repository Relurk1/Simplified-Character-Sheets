#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "views.h"
#include "model.h"
#include "controller.h"


int main() {

    Character character;
    Spell spells[MAX_SPELLS];
    Weapon weapons[MAX_WEAPONS];
    //Weapon weapons[16];

    initscr();

    startView();
    char buffer[16];
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    while(strcmp(buffer, "q") != 0 && strcmp(buffer, "quit") != 0) {
        if(strcmp(buffer, "c") == 0 || strcmp(buffer, "create") == 0) {
            setupView(&character);
            break;
        }
        else if (strcmp(buffer, "l") == 0 || strcmp(buffer, "load") == 0) {
            loadController();
            break;
        }
        printw("Unkown command %s \n", buffer);
        printw(">> ");
        memset(buffer, '\0', sizeof(buffer));
        getnstr(buffer, sizeof(buffer));
        buffer[sizeof(buffer)-1] = '\0';
    }
    if(strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
        endwin();
        return 0;
    }

    mainView(&character, spells, weapons);

    endwin();

    return 0;
};