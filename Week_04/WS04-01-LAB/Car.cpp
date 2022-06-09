/*
*****************************************************************************
                              Car.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 09 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Car.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
    Car::Car() {
        // By default, set everything to nullptr and 0
        resetInfo();
    }

    Car::~Car() {
        // Destructor deallocates the memory
        deallocate();
    }

    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price) {
        // Setting the values if the validation passes using setters
        setType(type);
        setBrand(brand);
        setModel(model);
        setYear(year);
        setCode(code);
        setPrice(price);

        // If the values that are set are not valid, reset all of them (set them to empty state)
        if (!(isValid())) {
            resetInfo();
        }
    }

    // Resets the values for all member variables by setting type, brand, and model to nullptr and setting the year, code, and price to 0.
    void Car::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }

    // Setters
    // Setting the type
    void Car::setType(const char* type) {
        if (type != nullptr && type[0] != '\0') {
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
        }
    }

    // Setting the brand
    void Car::setBrand(const char* brand) {
        if (brand != nullptr && brand[0] != '\0') {
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
        }
    }

    // Setting the model
    void Car::setModel(const char* model) {
        if (model != nullptr && model[0] != '\0') {
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
        }
    }

    // Setting the year
    void Car::setYear(int year) {
        if (year >= 1990) {
            m_year = year;
        }
    }

    // Setting the code
    void Car::setCode(int code) {
        if (code > 99 && code < 1000) {
            m_code = code;
        }
    }

    // Setting the price
    void Car::setPrice(double price) {
        if (price > 0) {
            m_price = price;
        }
    }

    // This method will first deallocate all the allocated memory and then sets the attributes to the corresponding arguments exactly like the 6 argument constructor.
    Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        // Deallocates all the dynamically allocated memory earlier
        deallocate();

        // Setting all the values using setters
        if ((type != nullptr && type[0] != '\0') && (brand != nullptr && brand[0] != '\0') && (model != nullptr && model[0] != '\0') && (year >= 1990) && (price > 0)  && (code > 99 && code < 1000)) {
            setType(type);
            setBrand(brand);
            setModel(model);
            setYear(year);
            setCode(code);
            setPrice(price);
        }

        return *this;
    }

    // This method prints the values of all the member variables on the screen.
    void Car::printInfo() const {
        cout.setf(ios::left);

        cout << "| ";
        cout.width(10);
        cout << m_type;

        cout << " | ";
        cout.width(16);
        cout << m_brand;

        cout << " | ";
        cout.width(16);
        cout << m_model;

        cout << " | ";
        cout << m_year << " |  ";

        cout << m_code << " |  ";
        cout.unsetf(ios::left);

        cout.width(8);
        cout.setf(ios::fixed);
        cout.setf(ios::right);
        cout.precision(2);
        cout << m_price << " |";
        cout.unsetf(ios::right);
        cout.unsetf(ios::fixed);
        cout << "\n";
    }

    // This method returns whether all member variables have valid values or not based on the criteria stated at the Private Member Variables.
    bool Car::isValid() const {
        bool result = false;
        // Checking if all the members are valid
        if ((m_type != nullptr && m_type[0] != '\0') && (m_brand != nullptr && m_brand[0] != '\0') && (m_model != nullptr && m_model[0] != '\0') && (m_year >= 1990) && (m_price > 0)  && (m_code > 99 && m_code < 1000)) {
            result = true;
        }

        return result;
    }

    // This function is to check whether the type, make, brand and year of an object of Car are equal to another object of this class.
    bool Car::isSimilarTo(const Car& car) const {
        bool result = false;
        // Comparing the current object to the argument
        if ((strcmp(m_type, car.m_type) == 0) && (strcmp(m_model, car.m_model) == 0)  && (strcmp(m_brand, car.m_brand) == 0) && (m_year == car.m_year)) {
            result = true;
        }

        return result;
    }

    // Deallocates all the dynamically allocated memory
    void Car::deallocate() {
        delete[] m_type;
        m_type = nullptr;

        delete[] m_model;
        m_model = nullptr;

        delete[] m_brand;
        m_brand = nullptr;
    }

    // Check whether there are duplicate entries in the entire inventory.
    bool has_similar(const Car car[], const int num_cars) {
        int i, j, flag = 1;
        bool result = false;
        for (i = 0; i < num_cars && flag == 1; i++) {
            for (j = i + 1; j < num_cars && flag == 1; j++){
                if (car[i].isValid() && car[j].isValid() && (car[i].isSimilarTo(car[j]))){
                    flag = 0;
                    result = true;
                }
            }
        }

        return result;
    }

    // It returns true if it finds an invalid Car in the car array, otherwise it returns false;
    bool has_invalid(const Car car[], const int num_cars) {
        bool result = false;
        int flag = 1, i;

        // Checking if any car instance in the array is invalid
        for (i = 0; i < num_cars && flag == 1; i++) {
            if (!car[i].isValid()) {
                result = true;
                flag = 0;
            }
        }

        return result;
    }

    // Print an array of valid Cars and ignore the invalid Cars.
    void print(const Car car[], const int num_cars) {
        int i;
        for (i = 0; i < num_cars; i++) {
            if (car[i].isValid()) {
                car[i].printInfo();
            }
        }
    }
}