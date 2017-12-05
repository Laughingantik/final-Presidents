//-----------------------------------------------------------------------
// file name: bag.h
//
// Defines and implements class bag
//-----------------------------------------------------------------------
#ifndef BAG_H
#define BAG_H
#include <iostream>
#include <vector>
using namespace std;

typedef string BAG_ELEMENT_TYPE;
const int DEFAULT_INITIAL_BAG_CAPACITY = 16;

class bag {
public:
	//--constructors
	bag();
	// post: Size of this bag is 0.
	//       Initial capacity == DEFAULT_INITIAL_BAG_CAPACITY

	bag(int initCapacity);
	// pre:  initCapacity >= 1  (remember you don't need to check for pre conditions)
	// pre conditions are requirments of the class that must be met before method is called, chapter 3, page 73
	// post: size of this bag is bag to 0 with the capacity
	//       to store initCapacity BAG_ELEMENT_TYPE objects

	//--modifiers
	void add(BAG_ELEMENT_TYPE newElement);
	// post: Add newElement to this bag and increase
	//       the size of this bag object increased by +1.
	//       Note: If capacity < size, the bag doubles it capacity

	bool remove(BAG_ELEMENT_TYPE removalCandidate);
	// post: If found, removalCandidate is removed from this bag.

	void sort();
	// post: sort in ascending order

	//--accessors

	int capacity() const;
	// post: return the maximum number of elements that could be stored in this bag

	int size() const;
	// post: return the number of elements that are currently in this bag
	//       the number of objects added but not removed.

	bool isEmpty() const;
	// post: Returns true if there are zero items in the bag.
	//       Returns false if there is one more added elements

	//--iterator functions

	void first() const;
	// post: my_index points to the first item

	// I made first() and next() const to show you a little trick to get around the meaning of
	//  const so even though the method is const, you can still modify the object by using a pointer
	// This is the only situation this trick should be used to subvert the meaning of const
	//((bag*)this)->my_index = 0;

	void next() const;
	// post: my_index points to the next item
	// ((bag*)this)->my_index++;

	bool isDone() const;
	// post: Returns true if the collection has been traversed

	void setIndex(int Number);
	//**********idk if this is right*******

	BAG_ELEMENT_TYPE currentItem() const;
	// pre:  ! isDone && my_size > 0  (remember you don't need to check for pre conditions)
	// post: Returns the item pointed to by the my_index

	int occurrencesOf(BAG_ELEMENT_TYPE matchValue) const;

private:
	int my_size;
	//I added my_capacity because you get conversion warnings when you compare an int to a vector capacity() class function.
	int my_capacity;
	int my_index;   // an internal cursor for iterating over all elements
	vector <BAG_ELEMENT_TYPE> my_element;  //The book calls this my_item, same vector different name.
};

#endif  // #ifndef BAG_H
