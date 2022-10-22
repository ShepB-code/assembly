// Author: Shepard Berry
// Assignment Title : P7_0, "Modified Sequential Search"
// Assignment Description: Search for last occurrence of a key
// Due Date: 10-22-2022
// Date Created: 10-21-2022
// Date Last Modified: 10-21-2022

#include <iostream>
using namespace std;

const short MAX = 10;
short myArr[MAX];
short key;
short index;

void __declspec(naked) asmSearch() {
    __asm {
  START:
    movsx ecx, MAX                // mov CTdown control into scratch
    jecxz DONE                    // jump to done if CTdown is 0
    lea ebx, myArr + 18           // init a pointer to the end of the array
    mov dx, key                   // move the search key into scratch
  TOP:
    cmp dx, [ebx]                 // comp the search key with curr array elem
    je DONE                       // if key == array elem then jump to done
    sub ebx, 2                    // mov down the array to next item
    loop TOP                      // dec ecx and jump to TOP if cx > 0
  DONE:
    dec cx                        // dec cx to get correct index where key is
    mov index, cx                 // mov index into memory
    ret                           // ret to calling code
    }
}
int main() {
    //prompt user for 10 values
    cout << "Enter an array of ten 16-bit values: " << endl;

    for (int i = 0; i < 10; i++) {
        // get user input and store it into array
        cin >> myArr[i];

        // echo print user input
        cout << myArr[i] << endl;
    }
    cout << endl;


    // prompt user for search key
    cout << "Enter a search key: ";

    // store user input into memory
    cin >> key;

    // echo print key
    cout << key << endl;

    // call search function
    asmSearch();

    // if index == -1 no key was found
    if (index == -1) {
        cout << "The last occurence of the search key was NOT found in this list."
             << endl;
    }
    // key found
    else {
        cout << "Thel ast occurrence of the search key wqas at  " << index << "."
             << endl;
    }
    return 0;

}