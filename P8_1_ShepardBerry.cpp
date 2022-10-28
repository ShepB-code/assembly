// Author: Shepard Berry
// Assignment Title : P8_0, "Sort Three"
// Assignment Description: Sort three integers in ascending order
// Due Date: 10-28-2022
// Date Created: 10-26-2022
// Date Last Modified: 10-26-2022

#include <iostream>
using namespace std;

const int MAX = 100;

void __declspec(naked) asmPalindrome(const char[ ], short, bool&) {
    __asm {
            push ebp            // preserve base pointer
            move ebp, esp       // establish new base pointer
            push eax            // preserve eax
            push ebx            // preserve ebx
            push ecx            // preserve ecx
            push edx            // preserve edx
            pushfd              // preserve eflags

            mov ebx, [ebp + 8]  // establish ptr to first character in str
            mov ecx, [ebp + 12] // establish ptr to size
            mov edx, ebx        // copy str pointer into scratch
            add edx, ecx        // add size to pointer to move it to the end of str

            cmp ecx, 0          // compare size to zero
            je DONE             // jump if size == 0
    TOP:    mov al, [ebx]       // copy char from ptr1 into scratch
            cmp al, [edx]       // compare char at ptr 1 to char at ptr 2
            jne NOTPAL
            inc ebx
            dec edx
            cmp ebx, edx
            jg DONE
            jmp TOP

    NOTPAL: mov eax, [ebp + 16] // establish ptr to isPalindrome
            mov [eax], 0

    DONE:   popfd                   // restore eflags
            pop edx                 // restore edx
            pop ebx                 // restore ebx
            pop eax                 // restore eax
            mov ebp, esp            // dealloc local mem
            pop ebp                 // restore prev base ptr
            ret                     // return to calling code
    }
}


int main() {
    bool isPalindrome = true;
    short size;
    char str[MAX];

    cout << "Enter a string of characters: ";
    cin >> str;
    cout << endl;

    size = strlen(str);
    asmPalindrome(str, size, isPalindrome);

    if(isPalindrome) {
        cout << "Your string is a palindrome." << endl;
    } else {
        cout << "Your string is NOT a palindrome." << endl;
    }

}
