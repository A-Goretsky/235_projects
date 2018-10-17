//Anton Goretsky
//CSCI 235 - Project 4
//PlayList interface

#include <iostream>
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {

    public:
        PlayList();                             //default constructor
        PlayList(const Song& a_song);           //parameterized constructor
        PlayList(const PlayList& a_play_list);  //copy constructor
        ~PlayList();
        bool add(const Song& new_song) override;
        bool remove(const Song& a_song) override;
        void loop();
        void unloop();
        void displayPlayList();

    private:
        Node<Song>* tail_ptr_;                  //pointer to last node
        Node<Song>* getPointerToLastNode() const;
        Node<Song>* getPointerTo(const Song& target, Node<Song>* &previous_ptr) const;


};

