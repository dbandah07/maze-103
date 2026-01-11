/* 
queue.cpp

Author:

Short description of this file:
*/
#include <cstdlib> // NULL
#include "queue.h"

// constructor for an (initially) empty queue
Queue::Queue() {
  // Complete this function
  head_ = nullptr;
}

// destructor. releases resources. C++ will call it automatically.
Queue::~Queue() {
  // Complete this function
  if (head_ == nullptr) {
    return;
  }

  LocItem* after = head_->next;
  delete head_;

  while (after != nullptr) {
    head_ = after;
    after = head_->next;
    delete head_;
  }
}

// insert a new Location at the end/back of our list   
void Queue::add_to_back(Location loc) {
   // Complete this function
   if (head_ == nullptr) {
    head_ = new LocItem{loc, nullptr};
    return;
   }

   LocItem* add = head_;
   // loops through list & finds last item;
   while (add->next != nullptr){
    add = add->next;
   }

   add->next = new LocItem{loc, nullptr};
}

// return and "remove" the oldest Location not already extracted
// If the queue is empty, return a Location with row and col both set to -1
Location Queue::remove_from_front() {
  // Complete this function
  LocItem* curr = head_;
  
  if (head_ == nullptr) {
    return Location {-1,-1};
  }

  Location loc = head_->loc;
  
  head_ = curr->next;
  delete curr;
  return loc;
}

// is this Queue empty? (did we extract everything added?)
// this is complete, you don't need to change it.
bool Queue::is_empty() const {
  // Complete this function
  if (head_ == nullptr) {
    return true;
  }

  return false;
}

