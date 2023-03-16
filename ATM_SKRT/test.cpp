#include <iostream>
#include <conio.h>

void myFunction() {
  std::cout << "The 'H' key was pressed!\n";
}

int home() {
  int key = 0;

  while (true) {
    if (_kbhit()) {  // Check if a key has been pressed
      key = _getch();  // Get the ASCII code of the pressed key
      if (key == 'H' || key == 'h') {  // Check if the key is 'H' or 'h'
        myFunction();  // Call the function
      }
    }
  }
  return 0;
}


