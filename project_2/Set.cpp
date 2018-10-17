// CSCI 235 Project 2
// Anton Goretsky
// Set template

#include <iostream>

//getIndexOf implementation template
template <class ItemType>
int Set<ItemType>::getIndexOf(const ItemType &target) const {
    for (int x = 0; x < item_count_; x++) {
        if (target == items_[x]) {
            return x;
        }
    }
    return -1;
}

//parameterized constructor template
template <class ItemType>
Set<ItemType>::Set() {
    item_count_ = 0; //Not necessary in c++ but I prefer including it.
    max_items_ = DEFAULT_SET_SIZE;
}

//getCurrentSize implementation template
template <class ItemType>
int Set<ItemType>::getCurrentSize() const {
    return item_count_;
}

//isEmpty implementation template
template <class ItemType>
bool Set<ItemType>::isEmpty() const {
    return item_count_ == 0;
}

//add implementation template
template <class ItemType>
bool Set<ItemType>::add(const ItemType &newEntry) {
    if (item_count_ < max_items_) {
        if (getIndexOf(newEntry) != -1) {
            return false;
        }
        items_[item_count_] = newEntry;
        item_count_++;
        return true;
    }
    return false;
}

//remove implementation template
template <class ItemType>
bool Set<ItemType>::remove(const ItemType &anEntry) {
    if (item_count_ == 0) {
        return false;
    }
    items_[getIndexOf(anEntry)] = items_[item_count_ - 1];
    item_count_--;
    return true;
}

//Clears set
//no need to remove all entries. Data will be overwritten if remaining.
template <class ItemType>
void Set<ItemType>::clear() {
    item_count_ = 0;
}

//contains implementation template
template <class ItemType>
bool Set<ItemType>::contains(const ItemType &anEntry) const {
    return getIndexOf(anEntry) != -1;
}

//toVector implementation template
template <class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
    std::vector<ItemType> allItems;
    for (int x = 0; x < item_count_; x++) {
        allItems.push_back(items_[x]);
    }
    return allItems;
}
