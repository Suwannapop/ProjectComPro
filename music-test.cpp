#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    // Open the directory containing the music files
    DIR* dir = opendir("./music");
    if (dir == NULL) {
        printf("Could not open music directory\n");
        return 1;
    }

    // Loop through each file in the directory
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Only play files with the .mp3 extension
        if (strstr(entry->d_name, "Onii_chan_sound.wav") != NULL) {
            // Construct the full path to the music file
            char path[256];
            snprintf(path, 256, "./music/%s", entry->d_name);

            // Load the music file
            Mix_Music* music = Mix_LoadMUS(path);
            if (music == NULL) {
                printf("Failed to load music file %s\n", path);
            } else {
                // Play the music file
                printf("Playing music file %s\n", path);
                Mix_PlayMusic(music, -1);

                // Wait for the music to finish
                while (Mix_PlayingMusic()) {
                    SDL_Delay(100);
                }

                // Free the music file
                Mix_FreeMusic(music);
            }
        }
    }

    // Close the directory
    closedir(dir);

    // Quit SDL_mixer and SDL
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}


//D:\\compro\\projcet_TT\\ProjectComPro\\Onii_chan_sound.wav