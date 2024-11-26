#pragma once

#include <stdlib.h>

typedef struct {
    int Str;
    int Dex;
    int Con;
    int Int;
    int Wis;
    int Cha;
    int proficiency;
    int skills[18];
    int saves[6];
    int spellAbility;
} Character;

typedef enum {
    ACRO,
    ANIM,
    ARCA,
    ATHL,
    DECE,
    HIST,
    INSI,
    INTI,
    INVE,
    MEDI,
    NATU,
    PERC,
    PERF,
    PERS,
    RELI,
    SLEI,
    STEA,
    SURV,
    NONESKL
} Skills;

static const struct {
    Skills      val;
    const char *str;
} skillConversion [] = {
    {ACRO, "ACRO"},
    {ANIM, "ANIM"},
    {ARCA, "ARCA"},
    {ATHL, "ATHL"},
    {DECE, "DECE"},
    {HIST, "HIST"},
    {INSI, "INSI"},
    {INTI, "INTI"},
    {INVE, "INVE"},
    {MEDI, "MEDI"},
    {NATU, "NATU"},
    {PERC, "PERC"},
    {PERF, "PERF"},
    {PERS, "PERS"},
    {RELI, "RELI"},
    {SLEI, "SLEI"},
    {STEA, "STEA"},
    {SURV, "SURV"}
};

Skills skillStrToEnum (const char *str) {
    unsigned int i;
    for (i=0; i<sizeof(skillConversion)/sizeof(skillConversion[0]); i++)
        if (!strcmp (str, skillConversion[i].str))
            return skillConversion[i].val;    
    return NONESKL;
}

typedef enum {
    STR,
    DEX,
    CON,
    INT,
    WIS,
    CHA,
    NONESAV
} Saves;

static const struct {
    Saves      val;
    const char *str;
} saveConversion [] = {
    {STR, "STR"},
    {DEX, "DEX"},
    {CON, "CON"},
    {INT, "INT"},
    {WIS, "WIS"},
    {CHA, "CHA"},
};

Saves saveStrToEnum (const char *str) {
    unsigned int i;
    for (i=0; i<sizeof(saveConversion)/sizeof(saveConversion[0]); i++)
        if (!strcmp (str, saveConversion[i].str))
            return saveConversion[i].val;    
    return NONESAV;
}

void manageSkillString(const char* skills, Character* character, int proficiencyMultiplier) {
    char* formattedString = (char*)malloc(strlen(skills));
    memset(formattedString, '\0', strlen(skills));
    unsigned int formatPos = 0;
    for(unsigned int i=0; i<strlen(skills); i++) {
        if(skills[i] >= 97 && skills[i] <= 122) {
            formattedString[formatPos] = skills[i] - 32;
            ++formatPos;
        }
        else if(skills[i] >= 65 && skills[i] <= 90) {
            formattedString[formatPos] = skills[i];
            ++formatPos;
        }
    }
    printw("\n");
    char skill[5];
    for(unsigned int i=0; i<strlen(formattedString)-1; i+=4) {
        memcpy(skill, &formattedString[i], 4);
        skill[4] = '\0';
        Skills skl = skillStrToEnum(skill);
        if(skl == NONESKL)
            printw("Invalid Skill %s\n", skill);
        else {
            character->skills[skl] = proficiencyMultiplier;
            if(proficiencyMultiplier == 1)
                printw("Proficiency marked for skill %s\n", skill);
            else
                printw("Expertise marked for skill %s\n", skill);
        }
        refresh();
    }
    printw("\n");
    free(formattedString);
    formattedString = NULL;

};

void manageSaveString(const char* saves, Character* character) {
    char* formattedString = (char*)malloc(strlen(saves));
    memset(formattedString, '\0', strlen(saves));
    unsigned int formatPos = 0;
    for(unsigned int i=0; i<strlen(saves); i++) {
        if(saves[i] >= 97 && saves[i] <= 122) {
            formattedString[formatPos] = saves[i] - 32;
            ++formatPos;
        }
        else if(saves[i] >= 65 && saves[i] <= 90) {
            formattedString[formatPos] = saves[i];
            ++formatPos;
        }
    }
    printw("\n");
    char save[4];
    for(unsigned int i=0; i<strlen(formattedString)-1; i+=3) {
        memcpy(save, &formattedString[i], 3);
        save[3] = '\0';
        Saves skl = saveStrToEnum(save);
        if(skl == NONESAV)
            printw("Invalid Save %s\n", save);
        else {
            character->skills[skl] = 1;
            printw("Save %s marked as proficient\n", save);
        }
        refresh();
    }
    printw("\n");
    free(formattedString);
    formattedString = NULL;
};

typedef struct {
    char name[64];
    int level;
    char components[8];
    char range[32];
    char description[128]; 
    bool attack;
} Spell;

