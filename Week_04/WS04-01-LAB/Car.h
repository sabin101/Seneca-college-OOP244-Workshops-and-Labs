/*
*****************************************************************************
                              Car.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 09 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

namespace sdds {
    class Car {
    private:
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;

        // Resets the values for all member variables by setting type, brand, and model to nullptr and setting the year, code, and price to 0.
        void resetInfo();
    public:
        // Constructors
        Car();
        Car(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);

        // Destructor
        ~Car();

        // Setters
        void setType(const char* type);
        void setBrand(const char* brand);
        void setModel(const char* model);
        void setYear(int year);
        void setCode(int code);
        void setPrice(double price);

        // This method will first deallocate all the allocated memory and then sets the attributes to the corresponding arguments exactly like the 6 argument constructor.
        Car& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

        // This method prints the values of all the member variables on the screen.
        void printInfo() const;

        // This method returns whether all member variables have valid values or not based on the criteria stated at the Private Member Variables.
        bool isValid() const;

        // This function is to check whether the type, make, brand and year of an object of Car are equal to another object of this class.
        bool isSimilarTo(const Car& car) const;

        // Deallocates all the dynamically allocated memory
        void deallocate();
    };

    // Check whether there are duplicate entries in the entire inventory.
    bool has_similar(const Car car[], const int num_cars);

    // Check whether there are duplicate entries in the entire inventory.
    bool has_invalid(const Car car[], const int num_cars);

    // Print an array of valid Cars and ignore the invalid Cars.
    void print(const Car car[], const int num_cars);
}

#endif  // SDDS_CAR_H_