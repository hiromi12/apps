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

int main()
{
  int b, y, m, d, mid, h, k, j;
  string day;

  cout << endl
       << "Enter your birthday (yyyymmdd): ";
  cin >> b;

  y = b / 10000;
  k = y % 100;
  j = y / 100;
  mid = b % 10000;
  m = mid / 100;
  d = mid % 100;

  cout << "Year: " << y << " (" << j << ", " << k << ")"
       << ", Month: " << m << ", Day: " << d << endl;

  // Modulo Formula
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

  cout << "h: " << h << endl;

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