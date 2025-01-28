//#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "gametiming.h"
#ifdef __linux__
#include "linux_keyboard.h"
#endif
#include "Audio Engine/audio.h"
#include "Console_Colors/atari.h"
//#include "../Combat/Combat.h"
#include "../Maps/Maps.h"

int main()
{
    initFPSLimit();
#ifdef __linux__
    setvbuf(stdout, NULL, _IONBF, 0);
    initKeyboard();
#elif _WIN32
    ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicIntro.ogg\",",NULL,SW_HIDE);

    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 ); // Forces the console to Full Screen Mode.
#endif

    showLogo();

#ifdef _WIN32
    system("taskkill /F /T /IM wmplayer.exe");
    ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\Music4.ogg\",",NULL,SW_HIDE);
#endif

    insertPlayerName();

#ifdef _WIN32
    system("taskkill /F /T /IM wmplayer.exe");
    if(GetAsyncKeyState(VK_LCONTROL) != 0){} // Clears the CTRL input from the logo "START GAME" prompt
    if(GetAsyncKeyState(VK_RCONTROL) != 0){} // Clears the CTRL input from the logo "START GAME" prompt
    if(GetAsyncKeyState(VK_LSHIFT) != 0){}
#endif

    area1();   //To Play the game, uncomment the area1(); function.
    ending();

    return 0;
}
