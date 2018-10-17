// CSCI Project 2
// Anton Goretsky
// PlayList implementation

#include <iostream>
#include <vector>
#include "PlayList.h"
#include "Song.h"

//Using additions for readability
using std::cout;

//Base empty constructor
PlayList::PlayList() {}

//Parameterized constructor
PlayList::PlayList(const Song &a_song) {
    addSong(a_song);
}

//method implementations begin
int PlayList::getNumberOfSongs() const {
    return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const {
    return playlist_.isEmpty();
}

bool PlayList::addSong(const Song &new_song) {
    return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song &a_song) {
    return playlist_.remove(a_song);
}

void PlayList::clearPlayList() {
    return playlist_.clear();
}

void PlayList::displayPlayList() const {
    std::vector<Song> playlist = playlist_.toVector();
    for (int x = 0; x < playlist_.getCurrentSize(); x++) {
        cout << "* Title: " << playlist[x].getTitle() << " * Author: " << playlist[x].getAuthor() << " * Album: " << playlist[x].getAlbum() << " * " << "\n";
    }
    cout << "End of playlist" << "\n";
}

//
//
