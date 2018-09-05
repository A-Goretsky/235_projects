#include <iostream>
#include <string>
#include "Customer.hpp"

using std::string;
using std::cout;
using std::endl;

//Potentially leave empty as mentioned in class.
Customer::Customer() {
    //name_ = "";
    //defective_device_ = "";
    //wait_time_ = 0;
}



Customer::Customer(string name, string device = "unknown", int wait_time = 0) {
    name_ = name;
    defective_device_ = device;
    wait_time_ = wait_time;
}

string Customer::getName() {
    return name_;
}

string Customer::getDevice() {
    return defective_device_;
}

int Customer::getWaitTime() {
    return wait_time_;
}

void Customer::updateWaitTime(int new_wait_time) {
    wait_time_ = new_wait_time;
}

