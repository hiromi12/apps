/**
 * @file gpa.cpp
 * @author Hiromi Honda
 * @brief GPA Calculator
 * @date 2023-12-24
 * 
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "header.h"
using namespace std;

class classes
{
public:
  double getcurrentGPA();
  int getCurrentCH();
  void input(int cNum);
  void getCHour(int num, string text);
  void setCH(string text, int num);
  void numGrade(string text, int num);
  void calGPA(int cNum);
  void output(int cNum);

private:
  string className[50], grade[50], CHTemp[50];
  int cHours[50], numG[50];
  int curCH, totalCH, allCH;
  double curGPA, GPA, temp[50], allTemp;
  double totalTemp, finGPA;
};

double classes::getcurrentGPA()
{
  cout << endl;
  _headerText_(46, "GPA Calculator");
  cout << "\nYour current GPA: ";
  cin >> curGPA;
  return curGPA;
}
int classes::getCurrentCH()
{
  cout << "Credit Hours You Have Earned: ";
  cin >> curCH;
  return curCH;
}
void classes::input(int cNum)
{
  cout << endl;
  totalCH = 0;
  for (int i = 0; i < cNum; i++)
  {
    cin.ignore();
    cout << "Class Code: ";
    getline(cin, className[i]);

    cout << "Letter Grade: ";
    cin >> grade[i];

    getCHour(i, className[i]); // get credit hours
    numGrade(grade[i], i);     // change letter grade to number grade
    totalCH = totalCH + cHours[i];
  }
}
void classes::getCHour(int num, string text)
{
  CHTemp[num] = text.back();
  setCH(CHTemp[num], num);
}
void classes::setCH(string text, int num)
{
  if (text == "0")
  {
    cHours[num] = 0;
  }
  else if (text == "1")
  {
    cHours[num] = 1;
  }
  else if (text == "2")
  {
    cHours[num] = 2;
  }
  else if (text == "3")
  {
    cHours[num] = 3;
  }
  else if (text == "4")
  {
    cHours[num] = 4;
  }
}
void classes::numGrade(string text, int num)
{
  if (text == "A")
  {
    numG[num] = 4;
  }
  else if (text == "B")
  {
    numG[num] = 3;
  }
  else if (text == "C")
  {
    numG[num] = 2;
  }
  else if (text == "D")
  {
    numG[num] = 1;
  }
  else if (text == "F")
  {
    numG[num] = 0;
  }
}
void classes::calGPA(int cNum)
{
  totalTemp = 0;
  for (int i = 0; i < cNum; i++)
  {
    temp[i] = cHours[i] * numG[i];
    totalTemp = totalTemp + temp[i];
  }
  GPA = totalTemp / totalCH;

  allCH = curCH + totalCH;
  allTemp = (curCH * curGPA) + totalTemp;
  finGPA = allTemp / allCH;
}
void classes::output(int cNum)
{
  cout << endl
       << string(46, '-') << endl
       << endl;
  for (int i = 0; i < cNum; i++)
  {
    cout << "\t" << className[i] << " : " << grade[i] << endl;
  }

  cout << "\n\tCredit Hours: " << totalCH << "\n\tGPA: " << fixed << setprecision(3) << GPA << endl;
  cout << "\n\tTotal Credit Hours: " << curCH + totalCH << endl;
  cout << "\tTotal GPA: " << finGPA << endl;
  cout << endl
       << string(46, '*') << endl
       << endl;
}

int dataNum(int n);

int main()
{
  classes student;
  int n, c;
  double g;

  student.getcurrentGPA(); // current GPA

  student.getCurrentCH(); // credit hours user have earned

  int cNum = dataNum(n); // ask user the number of data

  student.input(cNum); // input data

  student.calGPA(cNum); // calculate GPA

  student.output(cNum); // output data

  return 0;
}

int dataNum(int n)
{
  cout << "The number of classes you take: ";
  cin >> n;
  return n;
}

/* Design

*************** GPA Calculator ***************

Your current GPA:
Credit Hours You Have Earned:
The number of classes you take:

Class Code :  (loop n times)
Letter Grade:

----------------------------------------------

[Course Code] : [Grade]
  COMS 2203   : A
  MATH 2924   : A
  MATH 2703   : A
  ELEG 2134   : B
  MUS 2003    : A

  Credit Hours:
  GPA:

  Total Credit Hours:
  Total GPA:

**********************************************

*/