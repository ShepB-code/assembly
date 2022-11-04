/*
* Author: Shepard Berry
* Assignment Title: P8&9_1, "Relocate N"
* Assignment Description: Relocate a value N to front of the array
* Due Date: 11-4-2022
* Date Created: 11-1-2022
* Date Last Modified: 11-2-2022
*/

/*
 * Data Abstraction:
 *   An array of short values is declared
 *   A variable of type short is declared to contain N
 * Input:
 *   User inputs 10 values to populate the array
 *   User inputs N
 * Process:
 *   Value at N is moved to the front of the array and all elements N-1 are
 *      shifted up one position
 * Output:
 *   The new array is output
 * Assumptions:
 *   Assume all values are entered correctly
*/
#include <iostream>
using namespace std;

const int MAX = 10;
/*
 * description: Moves an element at N to position 0 and shifts the all
 *      elements N-1 one spot up
 * return: void
 * precondition: An array of shorts and a short are declared
 * postcondition: The array is changed to correspond with N
*/
void __declspec (naked) relocateN(short[], short) {
   __asm {
            push ebp            // preserve base point
            mov ebp, esp        // set new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            push ecx            // preserve ecx
            push edx            // preserve ebx
            pushfd              // preserve e-flags

            mov ebx, [ebp + 8]  // establish pointer to array
            mov ecx, [ebp + 12] // establish pointer to n (loop CDctr)

            mov eax, ecx        // move N to scratch to multiply it by 2
            add eax, eax        // calc 2 * N

            add ebx, eax        // move to position n in array
            mov eax, [ebx]      // move elem at N to scratch

            cmp ecx, 0          // compare CDctr to 0
            je DONE             // jump to DONE if N == 0

    TOP:    mov edx, [ebx - 2]  // move value at N-1 to scratch
            mov [ebx], dx       // move value at N-1 to N
            sub ebx, 2          // mov to N-1 in the array
            loop TOP            // decrement CDctr and loop if CDctr != 0
    DONE:
            mov [ebx], ax       // mov original value at n to front of array

            popfd               // restore eflags
            pop edx             // restore edx
            pop ecx             // restore ecx
            pop ebx             // restore ebx
            pop eax             // restore eax
            pop ebp             // restore ebp
            ret                 // return to calling code

   }
}

/*
* description: Main function for Relocating N
* return: void
* precondition: none
* postcondition: All input is entered correctly
*/
int main() {
   // DATA ABSTRACTION
   short arr[MAX];
   short n;

   // INPUT
   cout << "Please enter ten integer values:" << endl;
   for(int i = 0; i < 10; i++) {
       cin >> arr[i];
       cout << arr[i] << " ";
   }
   cout << endl;
   cout << "Enter the position of the value moving to the first position: ";
   cin >> n;
   cout << endl;

   // PROCESS
   relocateN(arr, n);

   // OUTPUT
   cout << "Your list of ten values, modified, is:" << endl;
   for(int i = 0; i < 10; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}