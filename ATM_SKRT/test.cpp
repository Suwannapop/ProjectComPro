#include <iostream>
#include <conio.h>

void myFunction() {
  std::cout << "The 'H' key was pressed!\n";
}

int main() {
  int key = 0;

  while (true) {
    if (_kbhit()) {
      key = _getch();
      if (key == 'H' || key == 'h') { 
        myFunction();
      }
    }
  }
  return 0;
}
