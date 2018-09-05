#include <iostream>
#include <string>
#include "GeniusBar.hpp"

using std::string;
using std::cout;
using std::endl;

//Potentially leave empty as mentioned in class. 
GeniusBar::GeniusBar() {
    current_wait_time_ = 0;
    number_of_available_geniuses_ = 0;
    number_of_customers_ = 0;
}

bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
    if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
        genius_bar_[number_of_customers_] = new_customer;
        number_of_customers_++;
        current_wait_time_ += WAIT_TIME_INCREMENT;
        return true;
    }
    else {
        return false;
    }
}

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

bool GeniusBar::releaseGenius() {
    if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
        number_of_available_geniuses_++;
        return true;
    }
    else {
        return false;
    }
}

bool GeniusBar::updateCustomersWaitTime() {
    if (number_of_customers_ > 0) {
        for (int x = 0; x < MAX_NUMBER_OF_CUSTOMERS; x++) {
            genius_bar_[x].updateWaitTime(WAIT_TIME_INCREMENT);
        }
        return true;
    }
    else {
        return false;
    }
}
