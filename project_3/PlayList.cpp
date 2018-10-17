//Anton Goretsky
//CSCI 235 - Project 4
//PlayList implementaion

#include <iostream>
#include <cassert>
#include <utility>
#include "PlayList.h"

//default constructor
PlayList::PlayList() : tail_ptr_(nullptr) {}

//parameterized constructor
PlayList::PlayList(const Song &a_song) {
    add(a_song);
}

//copy constructor
PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list) {
    tail_ptr_ = getPointerToLastNode();
}

PlayList::~PlayList() {
    unloop();
}

Node<Song>* PlayList::getPointerToLastNode() const {
    Node<Song>* trav_node = head_ptr_;
    while (trav_node->getNext() != nullptr) {
        trav_node = trav_node->getNext();
    }
    return trav_node;
}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>* &previous_ptr) const {
    Node<Song>* prev_node = head_ptr_;
    Node<Song>* trav_node = prev_node;
    //trav_node is in the condition given that it might eventually become a null pointer.
    //nullptr will return false.
    while (trav_node && !(trav_node->getItem() == target)) {
        prev_node = trav_node;
        trav_node = trav_node->getNext();
    }
    //program safety
    assert(prev_node != nullptr);

    previous_ptr = prev_node;

    //std::cout << "SONG TITLE BEING REMOVED: " << target.getTitle() << "\n";
    //std::cout << "prev_node song title: " << prev_node->getItem().getTitle() << "\n";
    //std::cout << "trav_node song title: " << trav_node->getItem().getTitle() << "\n";
    return trav_node;

}

bool PlayList::add(const Song& new_song) {
    Node<Song>* created_node =  new Node<Song>(new_song);
    if (!(contains(new_song))) {
        //test if playlist is empty
        if (isEmpty()) {
            head_ptr_ = created_node;
            tail_ptr_ = head_ptr_;
        }
        else {
            tail_ptr_->setNext(created_node);
            tail_ptr_ = tail_ptr_->getNext();
        }
        item_count_++;
    }
    else {
        return false;
    }
    return true;
}

bool PlayList::remove(const Song& a_song) {
    Node<Song>* previous;
    Node<Song>* current = getPointerTo(a_song, previous);

    if (current == tail_ptr_) {
        tail_ptr_ = previous;
    }
    if (current == head_ptr_) {
        head_ptr_ = current->getNext();
        delete current;
        item_count_--;
        return true;
    }
    else {
        previous->setNext(current->getNext());
        delete current;
        item_count_--;
        return true;
    }
}

void PlayList::loop() {
    tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop() {
    tail_ptr_->setNext(nullptr);
}

void PlayList::displayPlayList(){
    loop();
    std::vector<Song> vector = toVector();
    for (int x = 0; x < getCurrentSize(); x++) {
        std::cout << "* Title: " << vector[x].getTitle() << " * Author: " << vector[x].getAuthor() << " * Album: " << vector[x].getAlbum() << " * " << "\n";
    }
    std::cout << "End of playlist" << "\n";
    unloop();
}
