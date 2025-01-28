#ifdef _WIN32
#include <windows.h>
#endif
#include "conio2.h"
#include <stdio.h>

#ifdef _WIN32
static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;
#endif

void
textbackground (int color)
{
#ifdef __linux__
printf("%s", bgColorCodes[color]);
#elif _WIN32
    __BACKGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (color << 4));
#endif
}


void
textcolor (int color)
{
#ifdef __linux__
printf("%s", colorCodes[color]);
#elif _WIN32
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      color + (__BACKGROUND << 4));
#endif
}
