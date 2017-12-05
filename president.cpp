#include "president.h"


Presidents::Presidents()
{
  // ...
}

Presidents::Presidents(int presidentNumber, string presidentName, string birthDeathDates,
    string dateTookOffice, string dateLeftOffice,
    string party, string previousOffice, string vicePresident)
{
  ((Presidents*)this)->presidentNumber = presidentNumber;
  ((Presidents*)this)->presidentName = presidentName;
  ((Presidents*)this)->birthDeathDates = birthDeathDates;
  ((Presidents*)this)->dateTookOffice = dateTookOffice;
  ((Presidents*)this)->dateLeftOffice = dateLeftOffice;
  ((Presidents*)this)->party = party;
  ((Presidents*)this)->previousOffice = previousOffice;
  ((Presidents*)this)->vicePresident = vicePresident;
}

string Presidents::getPresidentName() const
{
  return ((Presidents*)this)->presidentName;
}

int Presidents::getPresidentNumber() const
{
  return ((Presidents*)this)->presidentNumber;
}

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
