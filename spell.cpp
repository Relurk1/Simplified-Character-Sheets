#include "spell.h"

Spell::Spell () {
    name = "";
    level = "";
    school = "";
    castingTime = "";
    range = "";
    target = "";
    components = "";
    duration = "";
    description = "";
    upcast = "";
}

// Getters
std::string Spell::getName() const {
    return name;
}

std::string Spell::getLevel() const {
    return level;
}

std::string Spell::getSchool() const {
    return school;
}

std::string Spell::getCastingTime() const {
    return castingTime;
}

std::string Spell::getRange() const {
    return range;
}

std::string Spell::getTarget() const {
    return target;
}

std::string Spell::getComponents() const {
    return components;
}

std::string Spell::getDuration() const {
    return duration;
}

std::string Spell::getDescription() const {
    return description;
}

std::string Spell::getUpcast() const {
    return upcast;
}

// Setters
void Spell::setName(std::string& name) {
    this->name = name;
}

void Spell::setLevel(std::string& level) {
    this->level = level;
}

void Spell::setSchool(std::string& school) {
    this->school = school;
}

void Spell::setCastingTime(std::string& time) {
    this->castingTime = time;
}

void Spell::setRange(std::string& range) {
    this->range = range;
}

void Spell::setTarget(std::string& target) {
    this->target = target;
}

void Spell::setComponents(std::string& components) {
    this->components = components;
}

void Spell::setDuration(std::string& duration) {
    this->duration = duration;
}

void Spell::setDescription(std::string& description) {
    this->description = description;
}

void Spell::setUpcast(std::string& upcast) {
    this->upcast = upcast;
}