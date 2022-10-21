//
// Created by shepa on 10/19/2022.
//
#include <iostream>
using namespace std;

const short MAX = 10;
short myArr[] = { 1, 9, -2, 4, 0, 1, 4, 5, 9, 1 };
short key;
short index;

void __declspec(naked) asmSearch() {
    __asm {
  START:
    movsx ecx, MAX
      jecxz DONE
      lea ebx, myArr
      mov dx, key
      TOP :
    cmp dx, [ebx]
      je DONE
      add ebx, 2
      loop TOP
      DONE :
    sub cx, MAX
      neg cx
      mov index, cx

      ret

    }
}
int main() {
    cout << "This program will search a list for a key, entered by you! \n\n";

    cout << "please enter a value to search for: ";
    cin >> key;
    asmSearch();

    cout << "Searched:" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "myArr[" << i << "] = " << myArr[i] << endl;
    }
    if (index == MAX) {
        cout << "Your key was not found" << endl;
    }
    else {
        cout << "Found at index = " << index << endl;
    }
    return 0;

}