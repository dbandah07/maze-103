/* 
queue.h
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "location.h"

//============================
// You may NOT change the public interface of this class.
// But you may add private data members (and private functions if you desire).
//============================
struct LocItem {
  Location loc;
  LocItem* next;

};

// a class that stores Locations in a queue (first-in first-out)
class Queue {
public: // API:
   
  // constructor (You may not change this)
  Queue();
  
  // destructor. releases resources.
  ~Queue();
  
  // insert a new Location at the end/back of our list in O(1)
  void add_to_back(Location loc); // (You may not change this)

  // return and remove the front/oldest Location in O(1)
  // If the queue is empty, return a Location with row and col both set to -1
  Location remove_from_front();  // (You may not change this)

  // is this Queue empty? (in O(1))
  bool is_empty() const; // (You may not change this)

private:
  LocItem* head_;
  // Add private data members and private functions here
  // if you so choose
};

#endif
