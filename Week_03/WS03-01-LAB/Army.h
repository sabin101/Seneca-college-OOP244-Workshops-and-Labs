/*
*****************************************************************************
                              Army.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 02 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

namespace sdds {
    const int MAX_NAME_LEN = 50;

    // Creating an Army class
    class Army {
    private:
        char nationality[MAX_NAME_LEN];
        int noOfUnits;
        double power;

    public:
        // Initializes the Army object to a safe empty state
        void setEmpty();

        // Initializes an Army object
        void createArmy(const char* country, double pow, int troops);

        // Updates the Army
        void updateUnits(int troops);

        // This query returns the nationality of an Army
        const char* checkNationality() const;

        // This query returns the number of units in an Army
        int checkCapacity() const;

        // This query returns the power of an Army.
        double checkPower() const;

        // This query returns true if the Army object is in a safe empty state
        bool isEmpty() const;

        // This function returns true if the Army has more power than the incoming Army
        bool isStrongerThan(const Army& army) const;
    };

    // This function will force both armies to fight
    void battle( Army& arm1, Army& arm2);

    // This function sends the information about an Army array to standard output if the object holds valid data values
    void displayDetails(const Army* armies, int size);
}

#endif //SDDS_ARMY_H
