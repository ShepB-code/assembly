// Author: Shepard Berry
// Assignment Title: P7_2, "Permutations"
// Assignment Description: Calculate a permutation
// Due Date: 10-22-2022
// Date Created: 10-21-2022
// Date Last Modified: 10-21-2022

#include <iostream>
using namespace std;


void __declspec(naked) asmPermutation(int, int, int&) {
    __asm {
START:
  mov ebx, [esp + 4]        // move n to scratch
  mov edx, [esp + 8]        // move k to scratch
  mov ecx, edx              // copy to scratch for calc n-k
  mov eax, 1                // init perm to 1
  cmp ecx, 0                // comp CDctr with 0
  jle RESULT                // jump to result if CDCtr <= 0
  cmp ecx, ebx              // calc k <= n
  jg RESULT                 // jump to result if k > n

PERM:
  mul ebx                   // multiply perm by n
  dec ebx                   // decrement n
  loop PERM                 // dec CDctr and jmp to PERM if CDctr != 0

RESULT:
  mov ebx, [esp + 12]       // mov result to ebx
  mov[ebx], eax             // move perm into result
  ret                       // return to calling code

  }
}
int main() {
    int n, k, result;

    // propmt user for n and k
    cout << "Enter positive integers n and k: ";

    // store input into memory
    cin >> n >> k;

    // echo print input
    cout << n << " " << k << endl;

    // calculate P(n, k)
    asmPermutation(n, k, result);

    // output result to stdout
    cout << "P(" << n << "," << k << ") = " << result << endl;

    return 0;

}