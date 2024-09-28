#include "character.h"

Character::Character() {
    AC = 10;
    proficiency = 10;
    maxHP = 10;
    currentHP = 10;
    speed = 30;
    strength = 10;
    dexterity = 10;
    constitution = 10;
    intelligence = 10;
    wisdom = 10;
    charisma = 10;
    featuresAndTraits = "";

    skillMap[std::string("athl")] = std::pair<uint8_t*,uint8_t>(&strength, 0);
    skillMap[std::string("acro")] = std::pair<uint8_t*,uint8_t>(&dexterity, 0);
    skillMap[std::string("slei")] = std::pair<uint8_t*,uint8_t>(&dexterity, 0);
    skillMap[std::string("stea")] = std::pair<uint8_t*,uint8_t>(&dexterity, 0);
    skillMap[std::string("arca")] = std::pair<uint8_t*,uint8_t>(&intelligence, 0);
    skillMap[std::string("hist")] = std::pair<uint8_t*,uint8_t>(&intelligence, 0);
    skillMap[std::string("inve")] = std::pair<uint8_t*,uint8_t>(&intelligence, 0);
    skillMap[std::string("natu")] = std::pair<uint8_t*,uint8_t>(&intelligence, 0);
    skillMap[std::string("reli")] = std::pair<uint8_t*,uint8_t>(&intelligence, 0);
    skillMap[std::string("anim")] = std::pair<uint8_t*,uint8_t>(&wisdom, 0);
    skillMap[std::string("insi")] = std::pair<uint8_t*,uint8_t>(&wisdom, 0);
    skillMap[std::string("medi")] = std::pair<uint8_t*,uint8_t>(&wisdom, 0);
    skillMap[std::string("perc")] = std::pair<uint8_t*,uint8_t>(&wisdom, 0);
    skillMap[std::string("surv")] = std::pair<uint8_t*,uint8_t>(&wisdom, 0);
    skillMap[std::string("dece")] = std::pair<uint8_t*,uint8_t>(&charisma, 0);
    skillMap[std::string("inti")] = std::pair<uint8_t*,uint8_t>(&charisma, 0);
    skillMap[std::string("perf")] = std::pair<uint8_t*,uint8_t>(&charisma, 0);
    skillMap[std::string("pers")] = std::pair<uint8_t*,uint8_t>(&charisma, 0);

    saveMap[std::string("str")] = std::pair<uint8_t*, uint8_t>(&strength, 0);
    saveMap[std::string("dex")] = std::pair<uint8_t*, uint8_t>(&strength, 0);
    saveMap[std::string("con")] = std::pair<uint8_t*, uint8_t>(&strength, 0);
    saveMap[std::string("int")] = std::pair<uint8_t*, uint8_t>(&strength, 0);
    saveMap[std::string("wis")] = std::pair<uint8_t*, uint8_t>(&strength, 0);
    saveMap[std::string("cha")] = std::pair<uint8_t*, uint8_t>(&strength, 0);
}

uint8_t Character::getAC() const { return AC; }
uint8_t Character::getProficiency() const { return proficiency; }
uint8_t Character::getMaxHP() const { return maxHP; }
uint8_t Character::getCurrentHP() const { return currentHP; }
uint8_t Character::getSpeed() const { return speed; }
//FIXME - get rid of this stupid placeholder
uint8_t Character::getStat(std::string& code) const {
    return 0;
}