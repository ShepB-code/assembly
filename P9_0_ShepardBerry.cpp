/*
 * Author: Shepard Berry
 * Assignment Title: P9_0, "Switch Case"
 * Assignment Description: Switch the case of every alphabetic character
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
void __declspec (naked) asmSwitchCase(char[]) {
    __asm {
            push ebp            // preserve base point
            mov ebp, esp        // set new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            pushfd              // preserve e-flags

            mov ebx, [ebp + 8]  // establish ptr to first character

    TOP:    mov eax, [ebx]      // move value at address into scratch
            cmp al, '\0'       // compare char to null
            je DONE             // jump to DONE if char == null

            cmp al, 'A'        // compare char to 'A'
            jl NEXT             // jump to NEXT if char < 'A'
            cmp al, 'Z'        // compare char to 'Z'
            jle FOUND           // jump to FOUND if char <= 'Z'
            cmp al, 'a'        // compare char to 'a'
            jl NEXT             // jump to NEXT if char < 'a'
            cmp al, 'z'        // compare char to 'z'
            jg NEXT             // jump to NEXT if char > 'z'
    FOUND:  xor al, 20h
            mov [ebx], al
    NEXT:   inc ebx
            jmp TOP

    DONE:   popfd                   // restore eflags
            pop ebx                 // restore ebx
            pop eax                 // restore eax
            mov ebp, esp            // dealloc local mem
            pop ebp                 // restore prev base ptr
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
    asmSwitchCase(str);

    // OUTPUT
    cout << "Your string, after it is converted:" << endl;
    cout << str << endl;

    return 0;
}