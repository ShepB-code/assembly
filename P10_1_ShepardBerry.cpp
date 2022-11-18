/*
 * Author: Shepard Berry
 * Assignment Title: P10_1, "Cube Root Approximation"
 * Assignment Description: Approximate the Cubed Root of a Number
 * Date Created: 11/18/2022
 * Due Date: 11/18/2022
 * Date Last Modified: 11/18/2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Description: Approximates the cubed root of a number
 * Return: void
 * Precondition: 3 floats are declared
 * Postcondition: Approximated root stored in memory
*/
void __declspec(naked) asmCubeRoot(float, float, float&) {
   __asm {
       push ebp                     // preserve base pointer
       mov ebp, esp                 // est stack frame
       push 3                       // push 3 to stack
       push eax                     // preserve eax
       pushfd                       // preserve e-flags

       finit					    // init fp stack
       fld DWORD PTR[ebp + 12]	    // push smallVal onto fp stack
       fld1					        // push 1.0 onto fp stack as root

   TOP:
       fld st					    // push prev root onto fp stack
       fld st					    // push copy of root on fp stack
       fmul st(2), st		        // calc root^2

       fadd st, st 		            // calc root * 2.0

       fld DWORD PTR[ebp + 8]       // push x onto the fp stack
       fdivrp st(3), st			    // calc (x / root^2)
       faddp st(2), st              // calc root * 2.0 + (x / root^2)

       fild DWORD PTR [esp + 8]    // push 3 onto the fp stack
       fdivp st(2), st		        // calc (root * 2.0 + (x / root^2)) / 3


       fld st(1)			        // store copy of new root
       fsubr						// calc root - oldRoot
       fabs						    // get |root - oldRoot|

       fcomp st(2)				    // comp |root - oldroot| to smallVal
       fstsw ax					    // sends comparison to ax
       sahf						    // updates flags
       jnb TOP					    // jump TOP if >= smallVal

       mov eax, [ebp + 16]		    // est pointer to result
       fstp DWORD PTR[eax]		    // store in result in mem

       popfd                        // restore e-flags
       pop ebx                      // restore eax
       mov esp, ebp                 // deallocate local mem
       pop ebp                      // restore base pointer
       ret                          // ret to call code
   }
}

/*
* description: Main function for Cubed Root Approximation
* return: void
* precondition: none
* postcondition: All input is entered correctly
*/
int main() {
   // DATA ABSTRACTION
   float x, smallVal = .00001, root;

   // INPUT
   cout << " Enter number to approximate cube root: " << endl;
   cin >> x;
   cout << x << endl;

   // PROCESS
   asmCubeRoot(x, smallVal, root);

   // OUTPUT
   cout << fixed << setprecision(3) <<  "The cube root is: " << endl;
   cout << root << endl;

   return 0;
}