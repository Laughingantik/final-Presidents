#include "president.h"


Presidents::Presidents()
{
  // ...
}

Presidents::Presidents(int presidentNumber, string presidentName, string birthDeathDates,
    string dateTookOffice, string dateLeftOffice,
    string party, string previosOffice, string vicePresident)
{
  // ...
}

string Presidents::getPresidentName() const
{
  return "Barack Obama";
}

int Presidents::getPresidentNumber() const
{
  return 42;
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
