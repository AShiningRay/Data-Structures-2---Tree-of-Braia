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

void applyColorPalette(char character)
{

    // Same color Background and text
    if(character == '&')
    {
        textcolor(LIGHTGREEN);
        textbackground(LIGHTGREEN);
    }
    else if(character == '@')
    {
        textcolor(BROWN);
        textbackground(BROWN);
    }
    else if(character == '#')
    {
        textcolor(GREEN);
        textbackground(GREEN);
    }
    else if(character == '.')
    {
        textbackground(BLACK);
        textcolor(BLACK);
    }
    else if(character == 'W')
    {
        textcolor(WHITE);
        textbackground(WHITE);
    }
    else if(character == '0' || character == 'E')
    {
        textcolor(DARKGRAY);
        textbackground(DARKGRAY);
    }
    else if(character == 'M')
    {
        textcolor(MAGENTA);
        textbackground(MAGENTA);
    }
    else if(character == 'P')
    {
        textcolor(LIGHTMAGENTA);
        textbackground(LIGHTMAGENTA);
    }
    else if(character == 'L')
    {
        textcolor(LIGHTRED);
        textbackground(LIGHTRED);
    }
    else if(character == 'R')
    {
        textcolor(RED);
        textbackground(RED);
    }
    else if(character == 'B' || character == 'H')
    {
        textcolor(BLUE);
        textbackground(BLUE);
    }
    else if(character == 'K')
    {
        textcolor(YELLOW);
        textbackground(YELLOW);
    }
    else if (character == 'V')
    {
        textcolor(LIGHTBLUE);
        textbackground(LIGHTBLUE);
    }
    else if (character == '$')
    {
        textcolor(LIGHTCYAN);
        textbackground(LIGHTCYAN);
    }
    if(character == 'C')
    {
        textcolor(CYAN);
        textbackground(CYAN);
    }
    if(character == '+')
    {
        textcolor(LIGHTGRAY);
        textbackground(LIGHTGRAY);
    }

    // Different color background and text
    else if(character == '|')
    {
        textcolor(RED);
        textbackground(BLACK);
    }
    else if (character == '`')
    {
        textcolor(BLACK);
        textbackground(BROWN);
    }
    else if (character == ':')
    {
        textcolor(BROWN);
        textbackground(LIGHTGREEN);
    }
    else if (character == ';')
    {
        textcolor(LIGHTGREEN);
        textbackground(BROWN);
    }
    else if (character == '~')
    {
        textcolor(WHITE);
        textbackground(LIGHTBLUE);
    }

    else if (character == '=')
    {
        textcolor(WHITE);
        textbackground(BROWN);
    }
    
    // Player's Minimap Indicators
    else if (character == '>' || character == '<' || character == 'v' || character == '^')
    {
        textcolor(BLACK);
        textbackground(YELLOW);
    }

}