#ifdef _WIN32
#include <windows.h>
#endif

void SetColor(int ForgC);

void SetColor(int ForgC)
{
#ifdef __linux__
    printf("%s", colorCodes[ForgC]);
#elif _WIN32
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
#endif
}
