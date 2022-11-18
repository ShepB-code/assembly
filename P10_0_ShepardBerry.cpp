/*
 * Author: Shepard Berry
 * Assignment Title: P10_0, "Volume of an Egg"
 * Assignment Description: Calculate the volume of an egg
 * Date Created: 11/18/2022
 * Due Date: 11/18/2022
 * Date Last Modified: 11/18/2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

/* Description: Calculates the volume of an egg
 * Return: void
 * Precondition: 3 floating point values are initialized
 * Postcondition: Volume is stored in memory
*/
void __declspec (naked) asmEggVolume(float, float, float&) {
    __asm {
       push ebp                   // preserve base pointer
       mov ebp, esp               // est stack frame
       push 6                     // push 6 onto stack
       push eax                   // preserve eax
       pushfd                     // preserve e-flags

       finit                      // init fp stack

       fldpi                      // push pi onto fp stack
       fild DWORD PTR [esp + 8]   // push 6 onto fp stack
       fdiv                       // calc pi / 6 pi

       fld  DWORD PTR [ebp + 8]   // push length onto fp stack
       fmul                       // calc length * (pi / 6)

       fld DWORD PTR [ebp + 12]   // push diameter onto fp stack
       fmul st, st                // calc D^2
       fmul                       // calc length * (pi / 6) * D^2

       mov  eax, [ebp + 16]       // establish pointer to volume
       fstp DWORD PTR [eax]       // store volume in memory

       popfd                      // restore e-flags
       pop eax                    // restore eax
       mov esp, ebp               // deallocate local mem
       pop ebp                    // restore base pointer
       ret                        // ret to call code
    }
}

/*
 * description: Main function for Volume of an Egg
 * return: void
 * precondition: none
 * postcondition: All input is entered correctly
*/
int main() {
    // DATA ABSTRACTION
    float diameter, length, volume;

    // INPUT
    cout << " Enter the length of the egg: " << endl;
    cin >> length;
    cout << length << endl;

    cout << "Enter the maximum diameter of the egg: " << endl;
    cin >> diameter;
    cout << diameter << endl;

    // PROCESS
    asmEggVolume(length, diameter, volume);

    // OUTPUT
    cout << "The volume of the egg is: " << endl;
    cout << fixed << setprecision(2) << volume << endl;


    return 0;
}