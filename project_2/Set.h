// CSCI 235 Project 2
// Anton Goretsky
// Set class header.

#ifndef SET_H
#define SET_H
#include "SetInterface.h"
template <class ItemType>

class Set : public SetInterface<ItemType> {

  public:
		Set();
		int getCurrentSize() const;
		bool isEmpty() const;
		bool add(const ItemType& newEntry);
		bool remove(const ItemType& anEntry);
		void clear();
		bool contains(const ItemType& anEntry) const;
		std::vector<ItemType> toVector() const;

  private:
		static const int DEFAULT_SET_SIZE = 4;
		ItemType items_[DEFAULT_SET_SIZE];
		int getIndexOf(const ItemType& target) const;
		int item_count_;
		int max_items_;
};

#include "Set.cpp"
#endif

//Useless extra comments
//
//
//
//
