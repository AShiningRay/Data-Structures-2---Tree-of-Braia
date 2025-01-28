#ifdef _WIN32
#include <windows.h>
#include <process.h>
#endif

// Overworld/Combat
void healSpot()
{
#ifdef __linux__
    ;
#elif _WIN32
    for(short int i = 0; i < 10; i++)
    {
        Beep(250*i, 120);
    }
    _endthread();
#endif
}

void footStep()
{
#ifdef __linux__
  ;
#elif _WIN32
    Beep(220, 200);
    _endthread();
#endif
}

void openMenu()
{
#ifdef __linux__
  ;
#elif _WIN32
    Beep(1000, 200);
    _endthread();
#endif
}

void openSkillMenu()
{
#ifdef __linux__
  ;
#elif _WIN32
    Beep(800, 200);
    _endthread();
#endif
}

void moveCombatCursor()
{
#ifdef __linux__
  ;
#elif _WIN32
    Beep(500, 200);
    _endthread();
#endif
}

void selectCombatAction()
{
#ifdef __linux__
  ;
#elif _WIN32
    Beep(1100, 100);
    _endthread();
#endif
}

void returnFromSkills()
{
#ifdef __linux__
  ;
#elif _WIN32
    Beep(850, 250);
    _endthread();
#endif
}

// Menu interactions
void moveCursor()
{
#ifdef __linux__
  ;
#elif _WIN32
  Beep(500, 200);
  _endthread();
#endif
}

void useItem()
{
#ifdef __linux__
  ;
#elif _WIN32
  for(short int i = 5; i < 12; i++)
  {
    Beep(250*i, 100);
  }
  _endthread();
#endif
}

void closeMenu()
{
#ifdef __linux__
  ;
#elif _WIN32
  Beep(700, 250);
  _endthread();
#endif
}


void endGame()
{
#ifdef __linux__
  ;
#elif _WIN32
  for(short int i = 6; i > 0; i--)
  {
    Beep(250*i, 140);
  }
  _endthread();
#endif
}

// BGM
void playBGMIntro()
{

}

void playBGMCredits()
{

}

void playBGMFight()
{

}

void playBGMBoss()
{

}

void playBGM1()
{

}

void playBGM2()
{

}

void playBGM3()
{

}

void playBGMHUB()
{

}