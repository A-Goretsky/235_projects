//Anton Goretsky
//CS 235
//Project 1
//Implementation of the GeniusBar class

#include <iostream>
#include <string>
#include "GeniusBar.hpp"

using std::string;
using std::cout;
using std::endl;

//Default Constructor
GeniusBar::GeniusBar() {
    current_wait_time_ = 0;
    number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
    number_of_customers_ = 0;
}

//Add waiting customer method
//Precondition of acceptable number of customers.
//Act, else return false.
bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
    if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
        genius_bar_[number_of_customers_] = new_customer;
        number_of_customers_++;
        current_wait_time_ += WAIT_TIME_INCREMENT;
        new_customer.updateWaitTime(current_wait_time_);
        return true;
    }
    else {
        return false;
    }
}

//Assign genius to customer method
//Precondition of waiting customers with an available genius.
//Act, else return false.
bool GeniusBar::assignGeniusToCustomer() {
    if ((number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)) {
        number_of_customers_--;
        number_of_available_geniuses_--;
        return true;
    }
    else {
        return false;
    }
}

//Release genius method
//Simply return genius to pool of available geniuses.
bool GeniusBar::releaseGenius() {
    if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
        number_of_available_geniuses_++;
        return true;
    }
    else {
        return false;
    }
}

//Update wait time method
//Update customer wait time from their current wait time by the increment.
bool GeniusBar::updateCustomersWaitTime() {
    if (number_of_customers_ > 0) {
        for (int x = 0; x < MAX_NUMBER_OF_CUSTOMERS; x++) {
            genius_bar_[x].updateWaitTime(genius_bar_[x].getWaitTime() + WAIT_TIME_INCREMENT);
        }
        return true;
    }
    else {
        return false;
    }
}
