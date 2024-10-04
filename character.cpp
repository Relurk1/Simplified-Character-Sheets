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

//Getters

uint8_t Character::getAC() const { return AC; }
uint8_t Character::getProficiency() const { return proficiency; }
uint8_t Character::getMaxHP() const { return maxHP; }
uint8_t Character::getCurrentHP() const { return currentHP; }
uint8_t Character::getSpeed() const { return speed; }
const std::string& Character::getFeaturesAndTraits() const {return featuresAndTraits;}

uint8_t Character::getStat(std::string& code) const {
    if(code.compare("str") == 0) 
        return strength;
    else if(code.compare("dex") == 0)
        return dexterity;
    else if(code.compare("con") == 0)
        return constitution;
    else if(code.compare("int") == 0)
        return intelligence;
    else if(code.compare("cha") == 0)
        return charisma;
    else
        return -1;
}

int8_t Character::getSkill(std::string& code) const {
    if(skillMap.count(code) != 0) {
        std::pair<uint8_t*, uint8_t> skill = skillMap.find(code)->second;
        return ((*skill.first-10)/2) + proficiency*skill.second;
    }
    else {
        return -1;
    }
}

int8_t Character::getSave(std::string& code) const {
    if(saveMap.count(code) != 0) {
        std::pair<uint8_t*, uint8_t> save = saveMap.find(code)->second;
        return ((*save.first-10)/2) + proficiency*save.second;
    }
    else {
        return -1;
    }
}

//Setters

void Character::setAC(uint8_t ac) {AC = ac;}
void Character::setProficiency(uint8_t prof) {proficiency = prof;}
void Character::setMaxHP(uint8_t mhp) {maxHP = mhp;}
void Character::setCurrentHP(uint8_t chp) {currentHP = chp;}
void Character::setSpeed(uint8_t spd) {speed = spd;}

void Character::setStat(std::string& code, uint8_t stat) {
    if(stat > 20)
        return;
    if(code.compare("str") == 0) 
        strength = stat;
    else if(code.compare("dex") == 0)
        dexterity = stat;
    else if(code.compare("con") == 0)
        constitution = stat;
    else if(code.compare("int") == 0)
        intelligence = stat;
    else if(code.compare("cha") == 0)
        charisma = stat;
}

void Character::setSkillProficiency(std::string& code, uint8_t prof) {
    if(skillMap.count(code) == 0 || prof > 2)
        return;
    skillMap.find(code)->second.second = prof;
}

void Character::setSaveProficiency(std::string& code, uint8_t prof) {
    if(saveMap.count(code) == 0 || prof > 2)
        return;
    saveMap.find(code)->second.second = prof;
}

void Character::setFeaturesAndTraits(std::string& feats) {
    featuresAndTraits.clear();
    featuresAndTraits = feats;
}
