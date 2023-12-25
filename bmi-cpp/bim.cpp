/**
 * @file bim.cpp
 * @author Hiromi Honda
 * @brief BIM Calculator
 * @date 2023-12-24
 *
 */

#include <iostream>
using namespace std;

bool validator(double num);
double BMI(double height, double weight);

int main()
{
  double height = 0, weight = 0;
  int counter = 0;
  bool heightChecker = false; // input validation
  bool weightChecker = false; // input validation

  do
  {
    if (counter >= 1)
    {
      cout << "Invalid input. Enter valid value." << endl;
    }
    cout << "Enter your height in meters: ";
    cin >> height;
    heightChecker = validator(height);
    counter++;
  } while (heightChecker == false);

  counter = 0;
  do
  {
    if (counter >= 1)
    {
      cout << "Invalid input. Enter valid value." << endl;
    }
    cout << "Enter your weight in kg: ";
    cin >> weight;
    weightChecker = validator(weight);

    counter++;
  } while (weightChecker == false);

  double result = BMI(height, weight);

  cout << "Your BMI is " << result << endl;

  return 0;
}

bool validator(double num)
{
  return num < 0 ? false : true;
}
double BMI(double height, double weight)
{
  return (weight / height) / height;
}