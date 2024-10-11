#pragma once

#include <string>

class Spell {
private:
    std::string name;
    std::string level;
    std::string school;
    std::string castingTime;
    std::string range;
    std::string target;
    std::string components;
    std::string duration;
    std::string description;
    std::string upcast;

public:

    Spell();

    std::string getName() const;
    std::string getLevel() const;
    std::string getSchool() const;
    std::string getCastingTime() const;
    std::string getRange() const;
    std::string getTarget() const;
    std::string getComponents() const;
    std::string getDuration() const;
    std::string getDescription() const;
    std::string getUpcast() const;

    void setName(std::string& name);
    void setLevel(std::string& level);
    void setSchool(std::string& school);
    void setCastingTime(std::string& time);
    void setRange(std::string& range);
    void setTarget(std::string& target);
    void setComponents(std::string& components);
    void setDuration(std::string& duration);
    void setDescription(std::string& description);
    void setUpcast(std::string& upcast);
};
