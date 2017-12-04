#include <list>
#include <iostream>
#include <string>

using namespace std;

void printInstructions()
{
  cout << "Presidents' Game" << endl;
  cout << "Guess the number of each President" << endl;
  cout << "(Guess -1 to exit the game)" << endl;
}

int getPresidentNumber(string presidentName)
{
  int presidentNumber;
  cout << "> What is the president number of " << presidentName << "? ";
  cin >> presidentNumber;
  return presidentNumber;
}

int main()
{
  printInstructions();
  int presidentNumber;
  do {
    presidentNumber = getPresidentNumber("Barack Obama");
  } while (presidentNumber != -1);
  return 0;
}
