Update the bag class
I never remove methods / functions from a class as some time in the future, you may need that function.However, there are times when you do need to add a few functions.As we did in the grid class, we added turnAround() and turnRight().In the bag class it would be very handy to have a function where you could pass an int representing an index location to set the index location in the vector.So as we did with grid, you need to declare or prototype the function in the.h file and then define it in the.cpp file.I suggest calling the function setIndex().So setIndex() will be void and take one argument of an integer value.

void setIndex(int number)

All the function needs to do is set the current index location : my_index = number;

Later, when you write the main program, after you load all the presidents you need to create a variable called size and make it equal to the size of the president vector :

int size = bagOfPresidents.size();

Then in the do loop, generate a "unique" values, random number form one to size.


srand((unsigned)time(0));
randNumber = rand() % size;

Lastly set the index value for the bag of presidents to that random number :

bagOfPresidents.setIndex(randNumber);

Don't forget, every time you guess the president correctly, you remove the president from the bag and reduce size by one.



//*****************************************************8
How do I output all the Presidents values in one statement ?

Item
toString()

Since the Presidents class is a user defined class, you need to write a function that will display the object when you want to see if it was read in correctly or use at another time in your program.You need to take in account the endings for numbers like 1st, 2nd, 3rd, or 4th.Here is a possible toString function you can use depending on how you implement the other class functions.

string Presidents::toString() const
{
	string ending = "th";

	if (((presidentNumber % 10) == 1) && (presidentNumber != 11))
		ending = "st";
	else
	{
		if (((presidentNumber % 10 == 2)) && (presidentNumber != 12))
			ending = "nd";
		else
			if (((presidentNumber) % 10 == 3) && (presidentNumber != 13))
				ending = "rd";
	}

	//  You can't just output an int using the catenation operator.  First, you have to convert the int to a char array, then you can output the char array as a string.
	//  How to convert a number to a string in C++:  Use itoa() // int to ascii is the easiest

	char presNumber[10];
	itoa(getPresidentNumber(), presNumber, 10);  // if your compiler complains about itoa, try _itoa or _itoa_s, the last one worked in VS2013
	string str = presidentName + " was the " + presNumber + ending + " President\n\n"
		+ "  He lived from " + getDateBornDied() + '\n'
		+ "  He took office " + getDateTookOffice() + '\n'
		+ "  He left office on " + getDateLeftOffice() + '\n'
		+ "  His party was " + getParty() + '\n'
		+ "  His previous office held was " + getPreviousOffice() + '\n'
		+ "  His vice president was " + getVicePresident() + '\n';
	return str;
}

How to use :

Note your variable and object names will probably be different.So if you have a bag of presidents :

bag bagOfPresidents;

After you read in the President values from the file and create a president :

Presidents aPresidents(number, name, bdDates, dtOffice, dlOffice, party, pOffice, vPresident);

Then add the president to the bag(collection) :

	bagOfPresidents.add(aPresidents);

Or you could do it all in one step :

bagOfPresidents.add(Presidents(number, name, bdDates, dtOffice, dlOffice, party, pOffice, vPresident));

Now how to display, remember the bag functions, get the current item and call toString to convert the president object to a string and display it :

cout << bagOfPresidents.currentItem().toString();

OR

cout << aPresident.toString() << endl;

Item
Overriding the << operator to Output a President Object
C++ doesn't have toString, but << operator is pretty standard way of getting a string representation of an object. So to print out some object to console output, just do

cout << object;

First, declare a friend class function in the public area of your.h class to output a President by just calling object name


friend ostream& operator<<(ostream& os, const Presidents& pr);


Define the overloaded << operator for the class, here is a general form :

ostream& operator<<(ostream& out, const MyClass& x) {
	out << "(" << x.attribute << " " << x.attribute2 << ")";
	return out;
}

For now, if you want to test this instead of using toString(), then define the following.You can leave the toString() in the class, but if you want to output a president object in the main program without explicitly calling the toString, this is the code you need in the Presidents.cpp file :

ostream& operator<<(ostream& out, const Presidents& x)
{

	int pnum = x.getPresidentNumber();

	// another way to assign string endings using if statements
	string ending = "th";
	if (pnum == 1 || pnum == 21 || pnum == 31 || pnum == 41) ending = "st";
	if (pnum == 2 || pnum == 22 || pnum == 32 || pnum == 42) ending = "nd";
	if (pnum == 3 || pnum == 23 || pnum == 33 || pnum == 43) ending = "rd";

	// No conversion needed with using << output operator

	out << x.getPresidentName() << " was the " << x.getPresidentNumber() << ending << " President\n\n"
		<< "  He lived from " << x.getDateBornDied() << '\n'
		<< "  He took office " << x.getDateTookOffice() << '\n'
		<< "  He left office on " << x.getDateLeftOffice() << '\n'
		<< "  His party was " << x.getParty() << '\n'
		<< "  His previous office held was " << x.getPreviousOffice() << '\n'
		<< "  His vice president was " << x.getVicePresident() << '\n';
	return out;
}

So now every time you want to output a President object, instead of :

cout << aPresident.toString() << endl;

You can just :

cout << aPresident << endl;

OR

cout << bagOfPresidents.currentItem().toString();

Can just be :

cout << bagOfPresidents.currentItem();

Check out pages 683 - 684 for a little more detail.



//***************************************************************************88

Reading in Data by line from a file
I created a load function and then pass it the bag object I created in the main as a reference :

void loadPresidents(bag& bagOfPresidents)
{
	ifstream inFile("PresidentDataBase.txt");
	if (!inFile)
		cout << "File not found" << endl;
	else
	{
		cout << "File found!!" << endl;
		int pnumber;
		string number, name, bdDates, dtOffice, dlOffice, party, pOffice, vPresident;

		while (!inFile.eof())  // while not end of file
		{
			getline(inFile, number);  // then convert to a int before calling add() below
			getline(inFile, name);
			getline(inFile, bdDates);
			// etc for the other 5 parts of the presidents

			// convert number from a string to an int
			pnumber = atoi(number.c_str());
			bagOfPresidents.add(Presidents(pnumber, name, bdDates, dtOffice, dlOffice, party, pOffice, vPresident));
		}
		//  go to the first element in the bag which is a record element, not a president, and remove it
	}
}






//*****************************************************88




Changing Console Colors
system("cls");  // clears the console screen

system("Color 3E");  // example

Here are the colors :

system("Color [background][text]");

In the above example 3 is the background color and E is the color of the text

0 - black
1 - blue
2 - green
3 - aqua
4 - red
5 - purple
6 - yellow
7 - white
8 - gray
9 - light blue
a - light green
b - light aqua
c - light read
d - light purple
e - light yellow
f - bright white

Item
Changing Console Size and a little extra
These are sample window setting you can change to modify your DOS window.You can add them to an appropriate location in your program.

#include <windows.h>  // for changing window title

// changes name of title bar 
SetConsoleTitle(L"Student Name - CIS127 - 01/01/16");  // requires  #include <windows.h>

What is the L for ? To get a normal C literal string to assign to a LPCWSTR, you need to prefix it with L.LPCWSTR stands for "Long Pointer to Constant Wide String".The W stands for Wide and means that the string is stored in a 2 byte character vs.the normal char.Common for any C / C++ code that has to deal with non - ASCII only strings.
// changes color of background and font
system("color D");

// changes height of window
system("mode con lines=25");

// changes width of window
system("mode con cols=80");

// sets the console window size, width and height
system("mode con:cols=80 lines=35");


This is just a sample heading function you could add to always display your name and current date.

void Heading()
{

	// heading
	system("cls");

	// Display the current date
	system("date /t");
	cout << endl << endl;

}



//*********************************************************************




Random Numbers
To use srand, you will need to :

#include <ctime>

then you can use srand to generate a random number.Note you must declare size, randNumber; and any other values you use before you use them in your program.This is just an excerpt showing you how to use srand and rand to generate a random number :

// generate n "unique" values...
srand((unsigned)time(0));
randNumber = rand() % size;                           // get random number from 1 to size


Now that we have a setIndex function in bag, we can use it to get the president without searching for the president :


bagOfPresidents.setIndex(randNumber);

// next line is for testing purposes ONLY, it shows that pres # and random number are not the same you have to get the pres# from the president at the randNumber index :
cout << "randNumber: " << randNumber << "   Pres#: " << bagOfPresidents.currentItem().getPresidentNumber() << endl;
//  TODO:  get current president
//  TODO:  get user guess
if (guess == -1)
{
	break;
}
if (bagOfPresidents.currentItem().getPresidentNumber() == guess)
{
	// congratulations stuff 
	// display president by calling toString()
	// remove president from bag
	// decrement the size by one for the random number to be generated
	// increment correct count and display totals
}
else
{
	// wrong  stuff 
	// display president by calling toString()  or using overloaded ouput operator <<
	// increment wrong count
	// display totals
}
if (size == 0)
{
	// clear screen
	// output the totals
	// put out a congratulations message
	// pause the program so player can read message
	break;
}


The final thing you need to do is put the above code in a do while loop

do {

	// the above code

} while (guess != -1 || size == 0);



//****************************************************************************88




Auxiliary Functions
If you remember back with the BankAccount class there were 6 auxiliary functions defined.These were user defined functions so that you could compare one BankAccount object with another to see if they were equal, less than, greater than, not equal, less than or equal and greater than or equal.In the Presidents class, since it is a user defined class you will need a similar set of functions.The prototype is given at the bottom of the.h file.At the bottom of the Presidents.cpp file, after you define all the class functions, you need to define the auxiliary functions.Back in week 4 in the "Read this before you do 4.2 and 4.3" in the second table, we briefly looked at auxiliary functions "Auxiliary functions in the Bank Account class".So if need be, go back and take a few minutes to check that out.Also check out pages 679 - 683.

If you continue on in CIS227, you will learn more about auxiliary function.Auxiliary functions are like the neighbor who comes over uninvited and helps themselves to a beer out of your refrigerator.An auxiliary function has direct access to private data, even though it is not technically part of the class.

The 6 auxiliary functions are overloading different operators so that you can do comparisons :

	less than
	test for equality
	not equal
	greater than
	greater than or equal
	less than or equal
	I will give these to you so just copy and paste them to the bottom of your Presidents.cpp file.Note all comparison is being done using the getPresidentName() class function :

	//--auxiliary  functions

	//  These non-member functions may be required by standard C++ 
	//  container classes such as list. Without all six defined, you will 
	//  likely get many cryptic compile time error messages.

	bool operator < (const Presidents & left, const Presidents & right)
{
	return left.getPresidentName() < right.getPresidentName();
}

bool operator == (const Presidents & left, const Presidents & right)
{
	return left.getPresidentName() == right.getPresidentName();
}

bool operator != (const Presidents & left, const Presidents & right)
{
	return left.getPresidentName() != right.getPresidentName();
}

bool operator > (const Presidents & left, const Presidents & right)
{
	return left.getPresidentName() > right.getPresidentName();
}

bool operator >= (const Presidents & left, const Presidents & right)
{
	return left.getPresidentName() >= right.getPresidentName();
}

bool operator <= (const Presidents & left, const Presidents & right)
{
	return left.getPresidentName() <= right.getPresidentName();
}



//*********************************************************************8
