# UI MENU
# Kong - Delphis
--------------------------------------------------------------------------------------------------------------------------------------------<br>
#include<ctype.h> <br>
isdigit(ch) function <br>
เป็นฟังก์ชันที่ใช้กับข้อมูลที่มีชนิดเป็น single char (ใช้เนื้อที่ 1 byte) เท่านั้น <br>
เป็นฟังก์ชันที่ใช้ตรวจสอบว่าข้อมูลที่เก็บไว้ในตัวแปร ch เป็นตัวเลข 0 ถึง 9 หรือไม่ <br>
ถ้าใช่ฟังก์ชันนี้จะให้ค่าส่งกลับเป็นเลขจำนวนเต็มที่ไม่เท่ากับศูนย์  <br>
ถ้าไม่ใช่ฟังก์ชันนี้จะไม่มีการส่งค่ากลับ <br>
https://sites.google.com/site/porkaermlgc/fangkchan-ni-phasa-c/fangkchan-keiyw-kab-taw-xaksr-character-functions <br>
--------------------------------------------------------------------------------------------------------------------------------------------<br>
#include <conio.h> <br>
getch() function <br>
เป็นฟังก์ชันหนึ่งที่ใช้ในการรับข้อมูลจากคีย์บอร์ดที่เป็นตัวอักขระ <br>
เพียง 1 ตัวเท่านั้น แล้วโปรแกรมจะทำงานต่อทันที โดยที่ไม่มีการรอการกดปุ่ม Enter <br>
จากผู้ใช้งาน และตัวอักขระที่กรอกไปจะไม่แสดงผลบนจอภาพด้วย <br>
http://elearning.psru.ac.th/courses/158/file_13.pdf <br>
--------------------------------------------------------------------------------------------------------------------------------------------<br>
ANSI_escape_code <br>

![image](https://user-images.githubusercontent.com/120131543/225553666-8a863e9b-aa09-4611-8413-40316f8a0733.png) <br>

Cr.<br>
https://en.wikipedia.org/wiki/ANSI_escape_code <br>
--------------------------------------------------------------------------------------------------------------------------------------------<br>
I got stuck with this question and was not able to find a good solution, so decided to have some tinkering with the Mingw compiler I have.  <br>
I used C++ and getch() function in <conio.h> header file and pressed the arrow keys to find what value was assigned to these keys. <br>
As it turns out, they are assigned values as 22472, 22477, 22480, 22475 for up, right, down and left keys respectively. <br>
But wait, it does not work as you would expect. <br>
You have to ditch the 224 part and write only the last two digits for the software to recognize the correct key; <br>
and as you guessed, 72, 77, 80 and 75 are all preoccupied by other characters, <br>
but this works for me and I hope it works for you as well. If you want to run the C++ code for yourself and find out the values for yourself, <br>
run this code and press enter to get out of the loop: <br>
https://stackoverflow.com/questions/2876275/what-are-the-ascii-values-of-up-down-left-right <br>
--------------------------------------------------------------------------------------------------------------------------------------------<br>

