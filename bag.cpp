// Gavin Anderson, CIS127, Activity 11.2

#include <algorithm>
#include "bag.h"
using namespace std;

bag::bag()
{
	((bag*)this)->my_size = 0;
	((bag*)this)->my_capacity = DEFAULT_INITIAL_BAG_CAPACITY;
	((bag*)this)->my_index = 0;
}

void bag::add(BAG_ELEMENT_TYPE newElement)
{
	((bag*)this)->my_element.push_back(newElement);
	((bag*)this)->my_size++;
}

BAG_ELEMENT_TYPE bag::currentItem() const
{
	return ((bag*)this)->my_element[((bag*)this)->my_index];
}

void bag::first() const
{
	((bag*)this)->my_index = 0;
}

void bag::next() const
{
	((bag*)this)->my_index++;
}

bool bag::isDone() const
{
	return ((bag*)this)->my_index >= ((bag*)this)->my_size;
}
void bag::setIndex(int number)
{
	//**********hmmmm this doesnt seem right, but a change here************
	//going to need my_index = number; in the main .cpp file according to teacher " All the function needs to do is set the current index location: my_index = number;"
	// Later, when you write the main program, after you load all the presidents you need to create a 
	//variable called size and make it equal to the size of the president vector: int size = bagOfPresidents.size();

	/*Then in the do loop,  generate a "unique" values, random number form one to size.
	srand((unsigned)time(0));
	randNumber = rand() % size;
	*/
	/*Lastly set the index value for the bag of presidents to that random number:
	bagOfPresidents.setIndex(randNumber);
	Don't forget, every time you guess the president correctly, you remove the president from the bag and reduce size by one.
	*/
}

int bag::size() const
{
	return ((bag*)this)->my_size;
}

int bag::capacity() const
{
	return ((bag*)this)->my_capacity;
}

int bag::occurrencesOf(BAG_ELEMENT_TYPE matchValue) const
{
	int matches = 0;
	for (first(); !isDone(); next())
	{
		if (currentItem() == matchValue)
			matches++;
	}
	return matches;
}

void bag::sort()
{																				// adding include algorithm stopped the other errors but
	std::sort(((bag*)this)->my_element.begin(), ((bag*)this)->my_element.end());  //still getting errors here: "bag::sort function does not take 2 arguments" & "sort: is not a member of std
}

bool bag::remove(BAG_ELEMENT_TYPE removalCandidate)
{
	bool found = false;
	for (first(); !isDone(); next())
	{
		if (currentItem() == removalCandidate)
			found = true;
		if (found && my_index + 1 < my_size)
			((bag*)this)->my_element[my_index] = ((bag*)this)->my_element[my_index + 1];
	}
	if (found)
	{
		((bag*)this)->my_element.pop_back();
		((bag*)this)->my_size--;
	}
	return found;
}
