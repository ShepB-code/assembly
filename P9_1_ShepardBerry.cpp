/*
* Author: Shepard Berry
* Assignment Title: P9_1, "Relocate N"
* Assignment Description: Relocate a value N to front of the array
* Due Date: 11-4-2022
* Date Created: 11-1-2022
* Date Last Modified: 11-1-2022
*/

/*
* Data Abstraction:
*   One character array is declared
* Input:
*   User inputs a string of characters
* Process:
*   All alphabetic character cases are switched
* Output:
*   The new string is output
* Assumptions:
*   Assume all values are entered correctly
*/
#include <iostream>
using namespace std;

const int MAX = 100;
/*
* description: Switches the case of every alphabetic character in a string
* return: void
* precondition: A string is declared
* postcondition: All alphabetic characters are changed to a different case
*/
void __declspec (naked) switchCase(char[]) {
   __asm {
            push ebp            // preserve base point
            mov ebp, esp        // set new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            pushfd              // preserve e-flags

            mov ecx, [ebp + 8]
            mov ebx, [ebp + 12]


            ret                     // return to calling code

   }
}

/*
* description: Main function for switching case
* return: void
* precondition: none
* postcondition: All input is entered correctly
*/
int main() {
   // DATA ABSTRACTION
   char str[MAX];

   // INPUT
   cout << "Please enter a string of characters: " << endl;
   cin.getline(str, MAX, '\n');
   cout << str << endl;

   // PROCESS
   switchCase(str);

   // OUTPUT
   cout << "Your string, after it is converted:" << endl;
   cout << str << endl;

   return 0;
}