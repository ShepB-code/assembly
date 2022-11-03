/*
* Author: Shepard Berry
* Assignment Title: P9_?, "Hate Odd Numbers"
* Assignment Description: Change all odd numbers in an array to even
* Due Date: 11-8-2022
* Date Created: 11-2-2022
* Date Last Modified: 11-3-2022
*/

/*
 * Data Abstraction:
 *   An array of 16-bit values is declared
 *   A 16-bit value is initialized to store the size of the array
 * Input:
 *   User inputs 10 16-bit values to populate the array
 * Process:
 *   Every value in the array is made even
 * Output:
 *   The new array is output
 * Assumptions:
 *   Assume all values are entered correctly
*/
#include <iostream>
using namespace std;

const int MAX = 10;
/*
 * description: Change all values in an array of 16-bit values to even
 * return: void
 * precondition: An array of 16-bit values is declared
 * postcondition: Every value is made even in the array
*/
void __declspec (naked) asmChangeOddToEven(short[], short) {
    __asm {
            push ebp            // preserve base point
            mov ebp, esp        // set new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            push ecx            // preserve ecx
            pushfd              // preserve e-flags

            mov ebx, [ebp + 8]  // establish pointer to array
            mov ecx, [ebp + 12] // mov counter to CDctr

    TOP:    mov eax, [ebx]      // move current value to scratch
            test ax, 0001h      // calculate mod 2
            jz NEXT             // jump to NEXT if value is even
            and eax, 4294967294 // change value to even (value is fffffffeh)
            mov [ebx], ax       // move value into memory
    NEXT:   add ebx, 2          // move to next value in the array
            loop TOP            // decrement CDctr and jump to TOP if CDctr != 0

            popfd               // restore eflags
            pop ecx             // restore ecx
            pop ebx             // restore ebx
            pop eax             // restore eax
            pop ebp             // restore ebp
            ret                 // return to calling code

    }
}

/*
* description: Main function for changeOddToEven
* return: void
* precondition: none
* postcondition: All input is entered correctly
*/
int main() {
    // DATA ABSTRACTION
    short arr[] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    short length = MAX;

    // INPUT
    cout << "Please enter 10 values (-32,768 to 32,767):" << endl;
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    // PROCESS
    asmChangeOddToEven(arr, length);

    // OUTPUT
    cout << "The values, after modification, are:" << endl;
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}