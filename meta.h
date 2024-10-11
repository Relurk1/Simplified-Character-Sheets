#pragma once

#include <string>

class Meta {
private:
    std::string characterName;
    std::string playerName;
    std::string classAndLevel;
    std::string race;
    std::string background;
    std::string alignment;
    unsigned int XP;

public:

    Meta();

    std::string getCharacterName() const;
    std::string getPlayerName() const;
    std::string getClassAndLevel() const;
    std::string getRace() const;
    std::string getBackground() const;
    std::string getAlignment() const;
    unsigned int getXP() const;

    void setCharacterName(const std::string& name);
    void setPlayerName(const std::string& name);
    void setClassAndLevel(const std::string& cl);
    void setRace(const std::string& r);
    void setBackground(const std::string& bg);
    void setAlignment(const std::string& align);
    void setXP(unsigned int xp);

    void incrementXP(unsigned int xp);
};
