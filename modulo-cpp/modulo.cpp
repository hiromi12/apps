/**
 * @file modulo.cpp
 * @author Hiromi Honda
 * @brief Modulo Calculator
 * @date 2022-12-27
 *
 */

#include <iostream>
#include <string>
using namespace std;

bool leapYearValidation(int y)
{
  if (y % 4 == 0)
  {
    if (y % 100 == 0)
    {
      if (y % 400 == 0)
        return true;
      else
        return false;
    }
    else
      return true;
  }
}

bool validation(string n)
{
  // validate if the number of characters are exactry 8 digits
  int length = n.length();
  if(length != 8)
  {
    cout << endl;
    cout << "Invalid input." << endl;
    cout << "Enter your birth date in format yyyymmdd." << endl;
    return false;
  }

  // validate if the input is number.
  for (char c : n)
  {
    if (!isdigit(c))
    {
      cout << endl;
      cout << "Invalid input." << endl;
      cout << "Enter your birth date in format yyyymmdd." << endl;
      return false;
    }
  }

  int y = stoi(n.substr(0, 4)); // year
  int j = stoi(n.substr(0, 2));
  int k = stoi(n.substr(2, 2));
  int m = stoi(n.substr(4, 2)); // month
  int d = stoi(n.substr(6, 2)); // day

  // leap year validation
  bool leap = leapYearValidation(y);

  if ((m <= 0 || d <= 0 || m > 12 || d > 31) || (leap == true && m == 2 && d >= 30) || (leap == false && m == 2 && d >= 29))
  {
    cout << "Invalid input." << endl;
    cout << "Enter valid month or day." << endl;
    return false;
  }
  return true;
}

int moduloCalculator(string n)
{
  int h;
  int y = stoi(n.substr(0, 4)); // year
  int j = stoi(n.substr(0, 2));
  int k = stoi(n.substr(2, 2));
  int m = stoi(n.substr(4, 2)); // month
  int d = stoi(n.substr(6, 2)); // day

  // modulo formula
  h = (d + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;

  if (h < 0)
  {
    switch (h)
    {
    case -1:
      h = 6;
      break;
    case -2:
      h = 5;
      break;
    case -3:
      h = 4;
      break;
    case -4:
      h = 3;
      break;
    case -5:
      h = 2;
      break;
    case -6:
      h = 1;
      break;
    default:
      break;
    }
  }

  cout << "Year: " << y << ", Month: " << m << ", Day: " << d << endl;

  return h;
}

string getDay(int h)
{
  string day;
  switch (h)
  {
  case 0:
    day = "Saturday";
    break;
  case 1:
    day = "Sunday";
    break;
  case 2:
    day = "Monday";
    break;
  case 3:
    day = "Tuesday";
    break;
  case 4:
    day = "Wednesday";
    break;
  case 5:
    day = "Thursday";
    break;
  case 6:
    day = "Friday";
    break;
  }

  return day;
}

int main()
{
  int h;
  string day, date;

  // get user input
  do
  {
    cout << endl
         << "Enter your birthday (yyyymmdd): ";
    cin >> date;
  } while (validation(date) == false);

  // call calculator
  h = moduloCalculator(date);

  // get the day
  day = getDay(h);

  cout << "The day was " << day << "." << endl
       << endl;

  return 0;
}

/**
 * Modulo:
 *
 *    h = (d + ((26 * (m + 1)) / 10 ) + k + (k / 4) + (j / 4) - 2 * j) % 7
 *
 */