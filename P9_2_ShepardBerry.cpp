/*
* Author: Shepard Berry
* Assignment Title: P9_2, "Even Parity"
* Assignment Description: Make sure all characters in a str have even parity
* Due Date: 11-8-2022
* Date Created: 11-4-2022
* Date Last Modified: 11-4-2022
*/

/*
 * Data Abstraction:
 *   An array of chars is declared
 * Input:
 *   User inputs up to 80 characters to go into the array
 * Process:
 *   Every character in the array is checked for an even or odd number of bits.
 *   If odd, the even parity bit (8th or most significant) is set.
 * Output:
 *   The new array is output
 * Assumptions:
 *   Assume all values are entered correctly
*/
#include <iostream>
using namespace std;

const int MAX = 80;
/*
 * description: Checks to make sure all chars in a char array have an even
 *     number of bits. If not, the even parity bit is set
 * return: void
 * precondition: An array of chars is declared
 * postcondition: All chars in the array have an even number of bits
*/
void __declspec (naked) asmEvenParity(char[]) {
    __asm {
            push ebp            // preserve base point
            mov ebp, esp        // set new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            push ecx            // preserve ecx
            push edx            // preserve ebx
            pushfd              // preserve e-flags

            mov ebx, [ebp + 8]  // init pointer to char array

    TOP:    mov dl, [ebx]       // move char into scratch
            cmp dl, '\0'        // compare char to null
            je DONE             // jump to DONE if char == null
            mov ecx, 8          // move 8 into CDctr to prepare for count1
            sub al, al          // init count1 to 0

    COUNT:  shr dl, 1           // shift char bits to the right
            jnc NOTONE          // jump to NOTONE if CF == 0
            inc al              // increment 1 counter if 1 is found
    NOTONE: loop COUNT          // decrement CDctr and jump to COUNT

            test al, 0001h      // mod count by 2
            jz NEXT             // if count % 2  == 0 jump to TOP
            mov dl, [ebx]       // restore character
            or dl, 80h          // set the parity bit
            mov [ebx], dl       // move new char into memory
    NEXT:   inc ebx             // move to next char in the array
            jmp TOP             // jump to TOP

    DONE:   popfd               // restore eflags
            pop edx             // restore edx
            pop ecx             // restore ecx
            pop ebx             // restore ebx
            pop eax             // restore eax
            pop ebp             // restore ebp
            ret                 // return to calling code

    }
}

/*
* description: Main function for Even Parity
* return: void
* precondition: none
* postcondition: All input is entered correctly
*/
int main() {
    // DATA ABSTRACTION
    char str[MAX];


    // INPUT
    cout << "Enter message (<= characters): ";
    cin.getline(str, MAX, '\n');
    cout << endl;

    cout << "The character array BEFORE we implement even parity:" << endl;
    cout << str << endl;

    // PROCESS
    asmEvenParity(str);

    // OUTPUT
    cout << "The character array AFTER we implement even parity:" << endl;
    cout << str << endl;

    return 0;
}