a
#include <list>
#include <iostream>
#include <string>
#include "bag.cpp"
#include "presidents.cpp"

using namespace std;

int main()

{

		void instructions();
	
		void totals(int& correctRef, int &wrongRef);
	
		void loadPresidents(bag& bagOfPresidents);
	
		int getGuess(Presidents& pres);

		void getTerm(int rand);
	
		void playPresidents();
	
		system("PAUSE");
		return 0;
}
