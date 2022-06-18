/*
*****************************************************************************
                              CleanerBot.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 11 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "CleanerBot.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
    CleanerBot::CleanerBot() {
        setEmpty();
    }

    CleanerBot::~CleanerBot() {
        deallocate();
    }

    CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active) {
        // Setting the robot information
        setEmpty();
        set(location, battery, brush, active);
    }

    // To set the robot information
    void CleanerBot::set(const char* location, double battery, int brush, bool active) {
        // Deallocating previous memory before assigning
        deallocate();

        // Setting the location
        setLocation(location);

        // Setting the status
        setActive(active);

        // Setting the battery
        if (battery >= 0 && battery <= 100) {
            robot_battery = battery;
        }

        // Setting the number of brushes
        if (brush >= 0) {
            robot_brush = brush;
        }
    }

    // To set the robot location
    void CleanerBot::setLocation(const char* location) {
        // Dynamically allocating memory for storing the location of the robot
        if (location != nullptr && location[0] != '\0') {
            robot_location = new char[strlen(location) + 1];
            strcpy(robot_location, location);
        }
    }

    // To set the robot active status (true or false)
    void CleanerBot::setActive(bool status) {
        // Assigning the status of the robot
        robot_active = status;
    }

    // To return the robot location
    const char* CleanerBot::getLocation() const {
        return robot_location;
    }

    // To return the robot's remaining battery percentage
    double CleanerBot::getBattery() const {
        return robot_battery;
    }

    // To return the number of brushes that the robot has
    int CleanerBot::getBrush() const {
        return robot_brush;
    }

    // To return if a robot is active
    bool CleanerBot::isActive() const {
        return robot_active;
    }

    // To return if the robot information is valid
    bool CleanerBot::isValid() const {
        return (robot_location && (robot_battery > 0 && robot_battery <= 100) && robot_brush >= 0);
    }

    // To display the information
    void CleanerBot::display() const {
        cout << "| ";
        cout.setf(ios::left);
        cout.width(10);
        cout << getLocation();
        cout.unsetf(ios::left);

        cout << " | ";
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << getBattery();
        cout.unsetf(ios::fixed);

        cout << " | ";
        cout.setf(ios::right);
        cout.width(18);
        cout << getBrush();
        cout.unsetf(ios::right);

        cout << " | ";
        cout.setf(ios::left);
        cout.width(6);
        if (isActive()) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << " |";
        cout.unsetf(ios::left);
        cout << endl;
    }

    // Sets all the values in the class to a safe empty state
    void CleanerBot::setEmpty() {
        robot_location = nullptr;
        robot_battery = 0.0;
        robot_brush = 0;
        robot_active = false;
    }

    // Deallocates all the dynamically allocated memory
    void CleanerBot::deallocate() {
        delete[] robot_location;
        robot_location = nullptr;
    }

    // Displays the header for different kinds of reports
    void displayHeader(int reportType, int robotsToBeCharged) {
        if (reportType == 1) {
            cout << "         ------ Cleaner Bots Report -----" << endl;
            cout << "     ---------------------------------------" << endl;
            cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
            cout << "|------------+---------+--------------------+--------|" << endl;
        }
        else if (reportType == 2) {
            cout << "|====================================================|" << endl;
            cout << "| LOW BATTERY WARNING:                               |" << endl;
            cout << "|====================================================|" << endl;
            cout << "| Number of robots to be charged: " << robotsToBeCharged << "                  |" << endl;
            cout << "| Sorting robots based on their available power:     |" << endl;
            cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
            cout << "|------------+---------+--------------------+--------|" << endl;
        }
        else {
            cout << "ERROR: Incorrect report type passed to the function" << endl;
        }
    }

    // This will sort all the robots based on their available power in descending order
    void sort(CleanerBot* bot, short num_bots) {
        int i, j;
        for (i = 0; i < num_bots; i++) {
            for (j = 1; j < num_bots; j++) {
                if (bot[j].getBattery() > bot[j - 1].getBattery()) {
                    CleanerBot temp_bot(bot[j].getLocation(), bot[j].getBattery(), bot[j].getBrush(), bot[j].isActive());
                    bot[j].set(bot[j - 1].getLocation(), bot[j - 1].getBattery(), bot[j - 1].getBrush(), bot[j - 1].isActive());
                    bot[j - 1].set(temp_bot.getLocation(), temp_bot.getBattery(), temp_bot.getBrush(), temp_bot.isActive());
                }
            }
        }
    }

    // This will not change the outcome but is the correct signature of the report
    int report(CleanerBot* bot, short num_bots) {
        int i, robotsToBeCharged = 0;
        // Display robots normally
        displayHeader(1);
        for (i = 0; i < num_bots; i++) {
            if (bot[i].isValid()) {
                bot[i].display();

                if (bot[i].getBattery() < 30) {
                    robotsToBeCharged++;
                }
            }
        }
        cout << endl;

        // Display robots if any one of them have less than 30% battery
        if (robotsToBeCharged > 0) {
            displayHeader(2, robotsToBeCharged);
            sort(bot, num_bots);
            for (i = 0; i < num_bots; i++) {
                if (bot[i].isValid()) {
                    bot[i].display();
                }
            }
        }

        cout << "|====================================================|" << endl;
        return 1;
    }
}