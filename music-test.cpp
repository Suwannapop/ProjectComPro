#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main()
{
    const char* songPath = "Onii_chan_sound.wav";

    if (PlaySound(songPath, NULL, SND_FILENAME | SND_ASYNC) == 0)
    {
        std::cerr << "Error: could not play song\n";
        return 1;
    }

    std::cout << "Playing: " << songPath << std::endl;

    while (true)
    {
        // keep the program running while the song is playing
        if (PlaySound(NULL, NULL, 0) == 0)
            break;
    }

    return 0;
}





//D:\\compro\\projcet_TT\\ProjectComPro\\Onii_chan_sound.wav 