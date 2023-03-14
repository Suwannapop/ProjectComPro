    // system("Color 9");
    /*  0 = Black       8 = Gray
        1 = Blue        9 = Light Blue
        2 = Green       A = Light Green
        3 = Aqua        B = Light Aqua
        4 = Red         C = Light Red
        5 = Purple      D = Light Purple
        6 = Yellow      E = Light Yellow
        7 = White       F = Bright White */

#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int main() {
    system("cls");
    cout << "Color test " << endl;
    
    

    int i, j, n;
   
    for(i=1; i<=12; i++){
        n = 2;
        for(j=1; j<=6; j++){
            printf("%5dx%2d=%3d", n, i, n*i);
            n++;
        }
        printf("\n");
    }
   
    printf("\n\n");
   
    for(i=1; i<=12; i++){
        n = 8;
        for(j=1; j<=6; j++){
            printf("%5dx%2d=%3d", n, i, n*i);
            n++;
        }
        printf("\n");
    }
   
    printf("\n");

     
//รันสี
    for (int i = 0 ; i >= 0; i++)
    {
        system("Color 0");
        Sleep(1000);
        system("Color 1");
        Sleep(1000);
        system("Color 2");
        Sleep(1000);
        system("Color 3");
        Sleep(1000);
        system("Color 4");
        Sleep(1000);
        system("Color 5");
        Sleep(1000);
        system("Color 6");
        Sleep(1000);
        system("Color 7");
        Sleep(1000);
        system("Color 8");
        Sleep(1000);
        system("Color 9");
        Sleep(1000);
        system("Color A");
        Sleep(1000);
        system("Color B");
        Sleep(1000);
        system("Color C");
        Sleep(1000);
        system("Color D");
        Sleep(1000);
        system("Color E");
        Sleep(1000);
        system("Color F");
        Sleep(1000);
    }
    
    return 0;
}