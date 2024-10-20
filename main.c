#include <stdio.h>
#include <string.h>
#include "views.h"

void createController() {
    refresh();
    printw("create\n");
    getch();
}

void loadController() {
    refresh();
    printw("load\n");
    getch();
}

int main() {

    initscr();

    startView();
    char buffer[16];
    getnstr(buffer, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    while(strcmp(buffer, "q") != 0 && strcmp(buffer, "quit") != 0) {
        if(strcmp(buffer, "c") == 0 || strcmp(buffer, "create") == 0) {
            createController();
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

    endwin();

    return 0;
};