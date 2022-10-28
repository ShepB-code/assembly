/*
* Author: Shepard Berry
* Assignment Title: P8_0, "Sort Three"
* Assignment Description: Sort three integers
* Due Date: 10-28-2022
* Date Created: 10-26-2022
* Date Last Modified: 10-28-2022
*/

/*
 * Data Abstraction:
 *   Three integers are declared
 * Input:
 *   User enters values for the three integers
 * Process:
 *   Three integers are sorted in ascending order
 * Output:
 *   The integers are displayed in sorted order
 * Assumptions:
 *   Assume all values are entered correctly
*/
#include <iostream>
using namespace std;

/*
 * description: Sort three integers in ascending
 * return: void
 * precondition: Three integers are declared
 * postcondition: Three integers are sorted in ascending order
*/
void __declspec (naked) asmSortThree(int&, int&, int&) {
    __asm {
        push ebp            // preserve base point
        mov ebp, esp        // set new base pointer
        mov eax, [ebp + 8]  // move address of num1 into scratch
        mov eax, [eax]      // move value at address into scratch
        mov ebx, [ebp + 12]  // move address of num1 into scratch
        mov ebx, [ebx]      // move value at address into scratch
        mov ecx, [ebp + 16] // move address of num1 into scratch
        mov ecx, [ecx]      // move value at address into scratch


        cmp eax, ebx        // compare val 1 and val 2
        jl NEXT             // jump to next if val 1 < val 2 (in right position)
        xchg eax, ebx       // swap values if val 1 > val 2

NEXT:   cmp ebx, ecx        // compare val 2 and val 3
        jl DONE             // jump to done if val 2 < val 3
        xchg ebx, ecx       // swap values if val 2 > val 3
        cmp eax, ebx        // compare val 1 and val 2
        jl DONE             // jump to DONE if val 1 < val 2
        xchg eax, ebx       // swap values if val 1 > val 2
 DONE:
        mov edx, [ebp + 8]  // mov address of num 1 into scratch
        mov [edx], eax      // mov smallest value in value at address
        mov edx, [ebp + 12]  // mov address of num 2 into scratch
        mov [edx], ebx      // mov middle value in value at address
        mov edx, [ebp + 16] // mov address of num 3 into scratch
        mov [edx], ecx      // mov largest value in value at address
        pop ebp             // restore base pointer
        ret
    }
}

/*
 * description: main function for sorting three numbers
 * return: void
 * precondition: none
 * postcondition: Three integers are output in sorted order
*/
int main() {
    // OUTPUT
    int num1, num2, num3;

    // INPUT
    cout << "Enter 3 numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << num1 << " " << num2 << " " << num3 << endl;

    // PROCESS
    asmSortThree(num1, num2, num3);

    // OUTPUT
    cout << "Your three values, in ascending order:" << endl;
    cout << num1 << " " << num2 << " " << num3 << endl;

    return 0;
}