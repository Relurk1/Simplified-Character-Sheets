#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <utility>

class Character {

    private:   
        uint8_t AC;
        uint8_t proficiency;
        uint8_t maxHP;
        uint8_t currentHP;
        uint8_t speed;
        uint8_t strength;
        uint8_t dexterity;
        uint8_t constitution;
        uint8_t intelligence;
        uint8_t wisdom;
        uint8_t charisma;
        std::map<std::string, std::pair<uint8_t*, uint8_t>> skillMap;
        std::map<std::string, std::pair<uint8_t*, uint8_t>> saveMap;
        std::string featuresAndTraits;

    public:
        Character();

        uint8_t getAC() const;
        uint8_t getProficiency() const;
        uint8_t getMaxHP() const;
        uint8_t getCurrentHP() const;
        uint8_t getSpeed() const;
        uint8_t getStat(std::string& code) const;
        uint8_t getSkill(std::string& code) const;
        uint8_t getSave(std::string& code) const;
        const std::string& getFeaturesAndTraits() const;

        void setAC(uint8_t);
        void setProficiency(uint8_t);
        void setMaxHP(uint8_t);
        void setCurrentHP(uint8_t);
        void setSpeed(uint8_t);
        void setStat(std::string& code, uint8_t stat);
        void setSkillProficiency(std::string& code, int prof);
        void setSaveProficiency(std::string& code, int prof);
        void setFeaturesAndTraits(std::string& feats);

    friend class Weapon;
    friend class Spellcasting;
};



