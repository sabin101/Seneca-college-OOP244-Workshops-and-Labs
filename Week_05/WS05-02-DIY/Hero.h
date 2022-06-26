/*
*****************************************************************************
                              Hero.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_HERO_H
#define SDDS_HERO_H

#include "Power.h"
#include <iostream>

namespace sdds {
    class Hero {
    private:
        char hero_name[MAX_NAME_LENGTH];
        Power* powers;
        int number_of_powers;
        int power_level;

        // Receives a pointer to a power and adds the power to the array of powers for a hero
        int add_power(Power* power);

        // Deallocates dynamically allocated memory
        void deallocate();
    public:
        Hero();
        Hero(const char* name, Power* powerArray, int numberOfPowers);
        ~Hero();

        // Sets a Hero Object to empty state
        void setEmptyState();

        // Calculates the power level of a hero. Sum of rarity of all the heroes' powers multiplied by the total count of powers
        int calculatePowerLevel() const;

        // Display function that will send the information about a hero to ostream
        std::ostream& display(std::ostream& os=std::cout) const;

        // The power is added to the list of hero. Power level and power count should be updated too
        Hero& operator+=(Power& power);

        // Subtract an integer from the power level of your hero
        Hero& operator-=(const int& power);
    };

    // Return true if first hero power level is less than second hero power level
    bool operator<(const Hero& hero1, const Hero& hero2);

    // Return true if first hero power level is greater than second hero power level
    bool operator>(const Hero& hero1, const Hero& hero2);

    // Add the power to the hero and update the hero accordingly
    void operator>>(Power& power, Hero& hero);

    // Add the power to the hero and update the hero accordingly.
    void operator<<(Hero& hero, Power& power);

    // An insertion operator overload: to allow printing of a hero object
    std::ostream& operator<<(std::ostream& out, const Hero& hero);

};

#endif