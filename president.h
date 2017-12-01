//Assignment: Final Project - President Programming Scenario

#ifndef PRESIDENTS_H   // Avoid redeclaring class Presidents.
#define PRESIDENTS_H   // This code is compiled only once
#include <string>      // for class string

using namespace std; // avoid having to write std:: as in std::string

class Presidents
{
public:  // class member functions

        //--constructors
   Presidents();
   Presidents(int presidentNumber, string presidentName, string birthDeathDates,
       string dateTookOffice, string dateLeftOffice,
       string party, string previosOffice, string vicePresident);

   //--accessors

   int getPresidentNumber() const;
   // post: return the President's number
   string getPresidentName() const;
   // post: return the President's name
   string getDateBornDied() const;
   // post: return the President's birth and/or death dates
   string getDateTookOffice() const;
   // post: return the President's date s/he took office
   string getDateLeftOffice() const;
   // post: return the President's date s/he left office

   string getParty() const;
   // post: return the President's party(s)

   string getPreviousOffice() const;
   // post: return the President's previous office held

   string getVicePresident() const;
   // post: return the President's Vice President(s)

   string toString() const;
   // need a friend to output a President by just calling object name
   friend ostream& operator<<(ostream& os, const Presidents& pr);
   //--modifiers - not required at this time

private:
   int presidentNumber;
   string presidentName;
   string birthDeathDates;
   string dateTookOffice;
   string dateLeftOffice;
   string party;
   string previousOffice;
   string vicePresident;

};


//--Auxilliary functions

// With these functions, Presidents objects can be
// sorted and searched by the standard algorithms
// currently we only use the overloaded == operater
bool operator <  (const Presidents & left, const Presidents & right); //  aPres < aPres2
bool operator == (const Presidents & left, const Presidents & right);
bool operator != (const Presidents & left, const Presidents & right);
bool operator <= (const Presidents & left, const Presidents & right);
bool operator >  (const Presidents & left, const Presidents & right);
bool operator >= (const Presidents & left, const Presidents & right);

#endif   // ifndef PRESIDENTS_H
