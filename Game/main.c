#define MINIAUDIO_IMPLEMENTATION
#include "Audio Engine/audio.h"

//#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "gametiming.h"
#ifdef __linux__
#include "linux_keyboard.h"
#endif
#include "Console_Colors/atari.h"
//#include "../Combat/Combat.h"
#include "../Maps/Maps.h"

int main()
{
    initFPSLimit();
    if(initAudioEngine() == -1) { return -1; }
#ifdef __linux__
    setvbuf(stdout, NULL, _IONBF, 0);
    initKeyboard();
#elif _WIN32
    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 ); // Forces the console to Full Screen Mode.
#endif

    playBGM("Intro");
    showLogo();

    stopBGM("Intro");
    playBGM("NameInput");
    insertCharName(0);

    initEnemies();
    initNavAreas();

#ifdef _WIN32
    if(GetAsyncKeyState(VK_LCONTROL) != 0){} // Clears the CTRL input from the logo "START GAME" prompt
    if(GetAsyncKeyState(VK_RCONTROL) != 0){} // Clears the CTRL input from the logo "START GAME" prompt
    if(GetAsyncKeyState(VK_LSHIFT) != 0){}
#endif

    stopBGM("NameInput");
    area1();   //To Play the game, uncomment the area1(); function.
    ending();

    return 0;
}
