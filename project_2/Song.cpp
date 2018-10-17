// CSCI 235
// Anton Goretsky
// Song implementation

#include "Song.h"
#include <iostream>

//Default constructor
Song::Song() {}

//Parameterized constructor
Song::Song(const std::string &title, const std::string &author, const std::string &album) {
    title_ = title;
    author_ = author;
    album_ = album;
}

///////// Basic Set Methods /////////
void Song::setTitle(std::string title) {
    title_ = title;
}

void Song::setAuthor(std::string author) {
    author_ = author;
}

void Song::setAlbum(std::string album) {
    album_ = album;
}

//////// Basic Get Methods /////////
std::string Song::getTitle() const {
    return title_;
}

std::string Song::getAuthor() const {
    return author_;
}

std::string Song::getAlbum() const {
    return album_;
}

// Custom == overload
bool operator==(const Song &lhs, const Song &rhs) {
    return ( lhs.getTitle() == rhs.getTitle() && 
             lhs.getAuthor() == rhs.getAuthor() && 
             lhs.getAlbum() == rhs.getAlbum() );
}

//Useless extra comment
