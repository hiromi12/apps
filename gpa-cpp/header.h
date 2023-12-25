#include<iostream>
#include<string>
using namespace std;

void _headerText_(int lineLength, string s)
{
  int a;
  if(s.size() >= lineLength - 2 || lineLength <= 0)
    return;
  a = lineLength - s.size() - 2;
  cout << string(a/2,'*');
  cout << " " << s << " ";
  cout << string(a/2,'*');
  cout << endl;
}

/**
 * if lineLength is 40 and string is "Hello World!",
 * output will look like below:
 * 
 * 1234567890123456789012345678901234567890
 * 
 * ************* Hello World! *************
 * 
 * First, check the length of the string and lineLength.
 *    "Hello World!".size() = 12
 * 
 * this is < 40 and valid to operate with this function.
 * We assume the string length as 14 to insert spaces first and end of the string.
 * then, the length that we fill with '*' is a = 40 - 14 = 26
 * so, the loop goes a/2 times
 * 
 */
