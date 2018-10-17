//Anton Goretsky
//CS 235
//Project 1
//Implementation of the Customer class

//imported objects, libraries , files.
#include <iostream>
#include <string>
#include "Customer.hpp"

//Using statements for later readibility
using std::string;
using std::cout;
using std::endl;

//Default constructor with no arguments
Customer::Customer() {
    name_ = "";
    defective_device_ = "unknown";
    wait_time_ = 0;
}

//3 argument constructor
//Parameterized constructor.
Customer::Customer(string name, string device, int wait_time) {
    name_ = name;
    defective_device_ = device;
    wait_time_ = wait_time;
}

//Simple get customer name method
string Customer::getName() {
    return name_;
}

//Simple get device name method
string Customer::getDevice() {
    return defective_device_;
}

//simple get customer wait time method
int Customer::getWaitTime() {
    return wait_time_;
}

//Simple update customer wait time with new wait time method.
void Customer::updateWaitTime(int new_wait_time) {
    wait_time_ = new_wait_time;
}

