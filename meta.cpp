#include "meta.h"

Meta::Meta() {
    XP = 0;
}

// Getters
std::string Meta::getCharacterName() const {
    return characterName;
}

std::string Meta::getPlayerName() const {
    return playerName;
}

std::string Meta::getClassAndLevel() const {
    return classAndLevel;
}

std::string Meta::getRace() const {
    return race;
}

std::string Meta::getBackground() const {
    return background;
}

std::string Meta::getAlignment() const {
    return alignment;
}

unsigned int Meta::getXP() const {
    return XP;
}

// Setters
void Meta::setCharacterName(const std::string& name) {
    characterName = name;
}

void Meta::setPlayerName(const std::string& name) {
    playerName = name;
}

void Meta::setClassAndLevel(const std::string& cl) {
    classAndLevel = cl;
}

void Meta::setRace(const std::string& r) {
    race = r;
}

void Meta::setBackground(const std::string& bg) {
    background = bg;
}

void Meta::setAlignment(const std::string& align) {
    alignment = align;
}

void Meta::setXP(unsigned int xp) {
    XP = xp;
}

void Meta::incrementXP(unsigned int xp) {
    XP += xp;
}
