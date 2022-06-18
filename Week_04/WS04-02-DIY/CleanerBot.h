/*
*****************************************************************************
                              CleanerBot.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 11 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CLEANERBOT_H_
#define SDDS_CLEANERBOT_H_

#define NORMAL_REPORT 1
#define WARNING_REPORT 2

namespace sdds {
    class CleanerBot {
    private:
        char* robot_location;
        double robot_battery;
        int robot_brush;
        bool robot_active;
    public:
        // Constructors
        CleanerBot();
        CleanerBot(const char* location, double battery, int brush, bool active);

        // Destructor
        ~CleanerBot();

        // To set the robot information
        void set(const char* location, double battery, int brush, bool active);

        // To set the robot location
        void setLocation(const char* location);

        // To set the robot active status (true or false)
        void setActive(bool status);

        // To return the robot location
        const char* getLocation() const;

        // To return the robot's remaining battery percentage
        double getBattery() const;

        // To return the number of brushes that the robot has
        int getBrush() const;

        // To return if a robot is active
        bool isActive() const;

        // To return if the robot information is valid
        bool isValid() const;

        // To display the information
        void display() const;

        // Sets all the values in the class to a safe empty state
        void setEmpty();

        // Deallocates all the dynamically allocated memory
        void deallocate();
    };

    // Displays the header for different kinds of reports
    void displayHeader(int reportType, int robotsToBeCharged = 0);

    // This will sort all the robots based on their available power in descending order
    void sort(CleanerBot* bot, short num_bots);

    // This will not change the outcome but is the correct signature of the report
    int report(CleanerBot* bot, short num_bots);
}

#endif