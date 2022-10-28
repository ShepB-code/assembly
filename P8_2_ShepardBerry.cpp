/*
 * Author: Shepard Berry
 * Assignment Title: P8_2, "Combinations"
 * Assignment Description: Calculate a combination
 * Due Date: 10-28-2022
 * Date Created: 10-26-2022
 * Date Last Modified: 10-28-2022
*/

/*
 * Data Abstraction:
 *   5 integers are declared to store use input and calculations
 * Input:
 *   User is prompted to input values for n and k
 * Process:
 *   Factorial, Permutation, and Combination are calculated
 * Output:
 *   Permuation and Combination for n and k are output to stdout
 * Assumptions:
 *   Assume all values are entered correctly
*/

#include <iostream>
using namespace std;

/*
 * description: Calculate factorial of k
 * return: void
 * precondition: two integers are declared
 * postcondition: factorial is calculated and stored in memory
*/
void __declspec(naked) asmFactorial(int, int&) {
    __asm {
            push ebp                // preserve base pointer
            mov ebp, esp            // establish new base pointer
            push eax                // preserve eax
            push ecx                // preserve ecx
            pushfd                  // preserve eflags

            mov ecx, [ebp + 8]      // init counter to k
            mov eax, 1              // init factorial result
            cmp ecx, 0              // compare CDctr to 0
            je DONE                 // jump to DONE if CDctr == 0
    TOP:    mul ecx                 // multiply factorial by counter
            loop TOP                // decrement counter and loop TOP if CDctr != 0
    DONE:   mov ecx, [ebp + 12]     // move result into scratch
            mov [ecx], eax          // move factorial into result
            popfd                   // restore eflags
            pop ecx                 // restore ecx
            pop eax                 // restore eax
            pop ebp                 // restore base pointer
            ret                     // return to calling code

ret
    }
}

/*
 * description: Calculate permutation of n and k
 * return: void
 * precondition: three integers are declared
 * postcondition: permutation is calculated and stored in memory
*/
void __declspec(naked) asmPermutation(int, int, int&) {
    __asm {
            push ebp                // preserve base pointer
            mov ebp, esp            // establish new base pointer
            push eax                // preserve eax
            push ebx                // preserve ebx
            push edx                // preserve edx
            push ecx                // preserve ecx
            pushfd                  // preserve eflags

    START:  mov ebx, [ebp + 8]      // move n to scratch
            mov edx, [ebp + 12]     // move k to scratch
            mov ecx, edx            // copy to scratch for calc n-k
            mov eax, 1              // init perm to 1
            cmp ecx, 0              // comp CDctr with 0
            jle RESULT              // jump to result if CDCtr <= 0
            cmp ecx, ebx            // calc k <= n
            jg RESULT               // jump to result if k > n


    PERM:   mul ebx                 // multiply perm by n
            dec ebx                 // decrement n
            loop PERM               // dec CDctr and jmp to PERM if CDctr != 0

    RESULT: mov ebx, [ebp + 16]     // mov result to ebx
            mov[ebx], eax           // move perm into result

            popfd                   // restore eflags
            pop edx                 // restore edx
            pop ecx                 // restore ecx
            pop ebx                 // restore ebx
            pop eax                 // restore eax
            pop ebp                 // restore base pointer
            ret                     // return to calling code
    }
}

/*
 * description: Calculate combination of n and k
 * return: void
 * precondition: three integers are declared
 * postcondition: combination is calculated and stored in memory
*/
void __declspec(naked) asmCombination(int, int, int&) {
    __asm {
        push ebp                    // preserve base pointer
        mov ebp, esp                // establish new base pointer
        push eax                    // preserve eax
        push ebx                    // preserve ebx
        pushfd                      // preserve eflags

        mov eax, [ebp + 8]          // move permutation of n and k into scratch
        mov ebx, [ebp + 12]         // move factorial of k into scratch
        cdq                         // prepare dividend
        div ebx                     // divide permutation by factorial
        mov ebx, [ebp + 16]         // move result into scratch
        mov [ebx], eax              // move result into memory
        popfd                       // restore eflags
        pop ebx                     // restore ebx
        pop eax                     // restore eax
        pop ebp                     // restore base pointer
        ret                         // return to calling code
    }
}

/*
 * description: Prompt user for input and calculates the permutation and
 *                  combination of n and k
 * return: void
 * precondition: none
 * postcondition: permutation and combination and calculated and output
*/
int main() {

    // DATA ABSTRACTION
    int n, k, factorialOfK, permutationOfNK, combinationOfNK;

    // INPUT
    cout << "Enter positive integers n and k: ";  // prompt user for input
    cin >> n >> k;                                // get user input from stdin
    cout << n << " " << k << endl;                // echo print input

    // PROCESS
    asmPermutation(n, k, permutationOfNK);    // calc permutation of n k
    asmFactorial(k, factorialOfK);            // calc factorial of n k
    asmCombination(permutationOfNK, factorialOfK, combinationOfNK);
    // calc combination of n k

    // OUTPUT
    cout << "P(" << n << "," << k << ") = " << permutationOfNK << endl;
    cout << "C(" << n << "," << k << ") = " << combinationOfNK << endl;

    return 0;

}