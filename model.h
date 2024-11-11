#pragma once

typedef struct {
    int STR;
    int DEX;
    int CON;
    int INT;
    int WIS;
    int CHA;
    int proficiency;
    int skills[17];
    int saves[6];
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
    NONE
} Skills;

const static struct {
    Skills      val;
    const char *str;
} skillConversion [] = {
    {ACRO, "ACRO"},
    {ANIM, "ANIM"},
    {ARCA, "ARC"},
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
    {RELI, "RELI"},
    {SLEI, "SLEI"},
    {STEA, "STEA"},
    {SURV, "SURV"}
};

char* parseSkillString(char* skills, Character* character, int proficiencyMultiplier) {
    char skill[5];
    for(int i=0; i<strlen(skills); i+=4) {
        memcpy(skill, &skills[i], 4);
        skill[4] = '\0';
    }
};
