#include <iostream>
#include <windows.h>
#include <mmsystem.h>

int main(int argc, char** argv)
{
    PlaySound(TEXT("D:\\compro\\projcet_TT\\ProjectComPro\\Onii_chan_sound.wav"),NULL,SND_SYNC);
    return 0;
}

//D:\\compro\\projcet_TT\\ProjectComPro\\Onii_chan_sound.wav