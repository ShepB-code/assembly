/*
* Author: Shepard Berry
* Assignment Title: P8_1, "Palindrome"
* Assignment Description: Determine if a string is a palindrome
* Due Date: 10-28-2022
* Date Created: 10-26-2022
* Date Last Modified: 10-28-2022
*/

/*
 * Data Abstraction:
 *   Variables are declared to determine if a char array is a palindrome
 * Input:
 *   The string is input from the user
 * Process:
 *   isPalindrome is run
 * Output:
 *   A message displaying if a string is a palindrome
 * Assumptions:
 *   Assume all values are entered correctly
*/
#include <iostream>
using namespace std;

const int MAX = 100;

/*
 * description: Determines if a string is a palindrome
 * return: void
 * precondition: A char array, short, and bool are declared. Bool is set to true
 * postcondition: bool is changed if char array is not a palindrome
*/
void __declspec(naked) asmPalindrome(const char[ ], short, bool&) {
    __asm {
            push ebp            // preserve base pointer
            mov ebp, esp       // establish new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            push ecx            // preserve ecx
            push edx            // preserve edx
            pushfd              // preserve eflags

            mov ebx, [ebp + 8]  // establish ptr to first character in str
            mov ecx, [ebp + 12] // establish ptr to size
            mov edx, ebx        // copy str pointer into scratch
            add edx, ecx        // add size to pointer to move it to the end of str
            dec edx             // 2nd ptr initiated to end of array

            cmp ecx, 0          // compare size to zero
            je DONE             // jump if size == 0
    TOP:    mov al, [ebx]       // copy char from ptr1 into scratch
            cmp al, [edx]       // compare char at ptr 1 to char at ptr 2
            jne NOTPAL
            inc ebx
            dec edx
            cmp ebx, edx
            ja DONE
            jmp TOP

    NOTPAL: mov eax, [ebp + 16] // establish ptr to isPalindrome
            mov [eax], 0

    DONE:   popfd                   // restore eflags
            pop edx                 // restore edx
            pop ecx                 // restore ecx
            pop ebx                 // restore ebx
            pop eax                 // restore eax
            mov ebp, esp            // dealloc local mem
            pop ebp                 // restore prev base ptr
            ret                     // return to calling code
    }
}

/*
 * description: main function for isPalindrome
 * return: void
 * precondition: none
 * postcondition: isPalindrome is output
*/
int main() {
    // DATA ABSTRACTION
    bool isPalindrome = true;
    short size;
    char str[MAX];


    // INPUT
    cout << "Enter a string of characters: ";
    cin >> str;
    cout << str << endl;

    // PROCESS
    size = strlen(str);
    asmPalindrome(str, size, isPalindrome);

    // OUTPUT
    if(isPalindrome) {
        cout << "Your string is a palindrome." << endl;
    } else {
        cout << "Your string is NOT a palindrome." << endl;
    }

}
