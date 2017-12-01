// Gavin Anderson, CIS127, Activity 11.2

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
{
	std::sort(((bag*)this)->my_element.begin(), ((bag*)this)->my_element.end());
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