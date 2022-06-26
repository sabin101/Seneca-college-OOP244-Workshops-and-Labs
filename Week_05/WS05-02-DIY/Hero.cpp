/*
*****************************************************************************
                              Hero.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Hero.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    Hero::Hero() {
        setEmptyState();
    }

    Hero::Hero(const char* name, Power* powerArray, int numberOfPowers) {
        setEmptyState();
        strcpy(hero_name, name);
        number_of_powers = numberOfPowers;

        // Allocating dynamic memory for the powers array
        powers = new Power[number_of_powers];

        int i;
        for (i = 0; i < numberOfPowers; i++) {
            powers[i] = powerArray[i];
        }

        power_level = calculatePowerLevel();
    }

    Hero::~Hero() {
        deallocate();
    }

    // Sets a Hero Object to empty state
    void Hero::setEmptyState() {
        hero_name[0] = '\0';
        number_of_powers = 0;
        power_level = 0;
    }

    // Calculates the power level of a hero. Sum of rarity of all the heroes' powers multiplied by the total count of powers
    int Hero::calculatePowerLevel() const {
        int i, powerLevel, rarity = 0;
        for (i = 0; i < number_of_powers; i++) {
            rarity += powers[i].checkRarity();
        }
        powerLevel = (int) (rarity * number_of_powers);

        return powerLevel;
    }

    // Receives a pointer to a power and adds the power to the array of powers for a hero
    int Hero::add_power(Power* power) {
        // Creating a temporary array with one extra element and copying the items from powers array to the temporary one
        Power temp[number_of_powers + 1];
        int i;
        for (i = 0; i < number_of_powers; i++) {
            temp[i] = powers[i];
        }

        // Adding new power to temp array
        temp[number_of_powers] = *power;
        number_of_powers++;

        // Deallocating and reallocating memory for the powers array
        deallocate();
        powers = new Power[number_of_powers + 1];

        // Copying items from temp array to powers
        for (i = 0; i < number_of_powers + 1; i++) {
            powers[i] = temp[i];
        }

        // Calculating the power level
        power_level = calculatePowerLevel();
        return 1;
    }

    // Display function that will send the information about a hero to ostream
    std::ostream& Hero::display(std::ostream& os) const {
        os << "Name: " << hero_name << endl;
        displayDetails(powers, number_of_powers);
        os << "Power Level: " << power_level;

        return os;
    }

    // The power is added to the list of hero. Power level and power count should be updated too
    Hero& Hero::operator+=(Power& power) {
        add_power(&power);
        return *this;
    }

    // Subtract an integer from the power level of your hero
    Hero& Hero::operator-=(const int& power) {
        this->power_level -= power;
        return *this;
    }

    // Return true if first hero power level is less than second hero power level
    bool operator<(const Hero& hero1, const Hero& hero2) {
        return (hero1.calculatePowerLevel() < hero2.calculatePowerLevel());
    }

    // Return true if first hero power level is greater than second hero power level
    bool operator>(const Hero& hero1, const Hero& hero2) {
        return (hero1.calculatePowerLevel() > hero2.calculatePowerLevel());
    }

    // Add the power to the hero and update the hero accordingly
    void operator>>(Power& power, Hero& hero) {
        hero += power;
    }

    // Add the power to the hero and update the hero accordingly.
    void operator<<(Hero& hero, Power& power) {
        hero += power;
    }

    // An insertion operator overload: to allow printing of a hero object
    std::ostream& operator<<(std::ostream& out, const Hero& hero) {
        return hero.display(out);
    }

    // Deallocates dynamically allocated memory
    void Hero::deallocate() {
        delete[] powers;
    }
}