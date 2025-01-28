#include "Player.h"

void openInventory();
void showPlayerStats_Map();

void openInventory()
{
    bool openingInventory = true;
    bool moved = false;
    bool HPpotsel = true;
    bool HPincsel = false;
    bool MPpotsel = false;
    bool MPincsel = false;
    short int thread;

    if(GetAsyncKeyState(VK_LMENU) != 0) {}

    while (1)
        {
            moved = false;
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
            showPlayerStats_Map();

            if(HPpotsel)
            {
                printf("\n\n\t===================================================\n");
                printf("\t====================Inventory======================\n");
                printf("\t|   ");
                SetColor(12);
                printf(">>");
                SetColor(15);
                printf("HP POTION : %d     |     HP MAX BOOSTER : %d  |\n", playerChar.it.HPpotion, playerChar.it.HPinc);
                printf("\t|                       |                         |\n");
                printf("\t|     MP POTION : %d     |     MP MAX BOOSTER : %d  |\n", playerChar.it.MPpotion, playerChar.it.MPinc);
                printf("\t|____________________COMMANDS_____________________|\n");
                printf("\t|  LSHIFT-USE ITEM      |  ARROWS- MOVE SELECTOR  |\n");
                printf("\t|  LALT-CLOSE GAME      |  LCTRL - CLOSE INVENTORY|\n");
                printf("\t|_______________________|_________________________|\n");
                printf("\t|_______________ ITEM DESCRIPTION ________________|\n");
                printf("\t|_________________________________________________|\n");
                printf("\t|        HP POTION : RECOVER 20%% FROM MAX HP      |\n");
                printf("\t|        MP POTION : RECOVER 20%% FROM MAX MP      |\n");
                printf("\t|   HP MAX BOOSTER : INCREASES THE MAX HP BY 5%%   |\n");
                printf("\t|   MP MAX BOOSTER : INCREASES THE MAX MP BY 5%%   |\n");
                printf("\t|_________________________________________________|\n");
            }

            else if(HPincsel)
            {
                printf("\n\n\t===================================================\n");
                printf("\t====================Inventory======================\n");
                printf("\t|     HP POTION : %d     |   ",playerChar.it.HPpotion);
                SetColor(12);
                printf(">>");
                SetColor(15);
                printf("HP MAX BOOSTER : %d  |\n", playerChar.it.HPinc);
                printf("\t|                       |                         |\n");
                printf("\t|     MP POTION : %d     |     MP MAX BOOSTER : %d  |\n", playerChar.it.MPpotion, playerChar.it.MPinc);
                printf("\t|____________________COMMANDS_____________________|\n");
                printf("\t|  LSHIFT-USE ITEM      |  ARROWS- MOVE SELECTOR  |\n");
                printf("\t|  LALT-CLOSE GAME      |  LCTRL - CLOSE INVENTORY|\n");
                printf("\t|_______________________|_________________________|\n");
                printf("\t|_______________ ITEM DESCRIPTION ________________|\n");
                printf("\t|_________________________________________________|\n");
                printf("\t|        HP POTION : RECOVER 20%% FROM MAX HP      |\n");
                printf("\t|        MP POTION : RECOVER 20%% FROM MAX MP      |\n");
                printf("\t|   HP MAX BOOSTER : INCREASES THE MAX HP BY 5%%   |\n");
                printf("\t|   MP MAX BOOSTER : INCREASES THE MAX MP BY 5%%   |\n");
                printf("\t|_________________________________________________|\n");
            }

            if(MPpotsel)
            {
                printf("\n\n\t===================================================\n");
                printf("\t====================Inventory======================\n");
                printf("\t|   ");
                printf("  HP POTION : %d     |     HP MAX BOOSTER : %d  |\n", playerChar.it.HPpotion, playerChar.it.HPinc);
                printf("\t|                       |                         |\n");
                printf("\t|   ");
                SetColor(12);
                printf(">>");
                SetColor(15);
                printf("MP POTION : %d     |     MP MAX BOOSTER : %d  |\n", playerChar.it.MPpotion, playerChar.it.MPinc);
                printf("\t|____________________COMMANDS_____________________|\n");
                printf("\t|  LSHIFT-USE ITEM      |  ARROWS- MOVE SELECTOR  |\n");
                printf("\t|  LALT-CLOSE GAME      |  LCTRL - CLOSE INVENTORY|\n");
                printf("\t|_______________________|_________________________|\n");
                printf("\t|_______________ ITEM DESCRIPTION ________________|\n");
                printf("\t|_________________________________________________|\n");
                printf("\t|        HP POTION : RECOVER 20%% FROM MAX HP      |\n");
                printf("\t|        MP POTION : RECOVER 20%% FROM MAX MP      |\n");
                printf("\t|   HP MAX BOOSTER : INCREASES THE MAX HP BY 5%%   |\n");
                printf("\t|   MP MAX BOOSTER : INCREASES THE MAX MP BY 5%%   |\n");
                printf("\t|_________________________________________________|\n");
            }

            else if(MPincsel)
            {
                printf("\n\n\t===================================================\n");
                printf("\t====================Inventory======================\n");
                printf("\t|     HP POTION : %d     |    ",playerChar.it.HPpotion);
                printf(" HP MAX BOOSTER : %d  |\n", playerChar.it.HPinc);
                printf("\t|                       |                         |\n");
                printf("\t|     MP POTION : %d     |   ", playerChar.it.MPpotion);
                SetColor(12);
                printf(">>");
                SetColor(15);
                printf("MP MAX BOOSTER : %d  |\n", playerChar.it.MPinc);
                printf("\t|____________________COMMANDS_____________________|\n");
                printf("\t|  LSHIFT-USE ITEM      |  ARROWS- MOVE SELECTOR  |\n");
                printf("\t|  LALT-CLOSE GAME      |  LCTRL - CLOSE INVENTORY|\n");
                printf("\t|_______________________|_________________________|\n");
                printf("\t|_______________ ITEM DESCRIPTION ________________|\n");
                printf("\t|_________________________________________________|\n");
                printf("\t|        HP POTION : RECOVER 20%% FROM MAX HP      |\n");
                printf("\t|        MP POTION : RECOVER 20%% FROM MAX MP      |\n");
                printf("\t|   HP MAX BOOSTER : INCREASES THE MAX HP BY 5%%   |\n");
                printf("\t|   MP MAX BOOSTER : INCREASES THE MAX MP BY 5%%   |\n");
                printf("\t|_________________________________________________|\n");
            }

            if(openingInventory)
            {
                openingInventory = false;
                limitFPS(1000);
            }

            while(!moved)
            {
                 if(GetAsyncKeyState (VK_UP) != 0)
                    {
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCursor, 0, &thread);
#endif
                        moved = true;
                        if(MPpotsel)
                            {
                                MPpotsel = false;
                                HPpotsel = true;
                                break;
                            }
                        if(MPincsel)
                            {
                                MPincsel = false;
                                HPincsel = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_DOWN) != 0)
                    {
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCursor, 0, &thread);
#endif
                        moved = true;
                        if(HPpotsel)
                            {
                                HPpotsel = false;
                                MPpotsel = true;
                                break;
                            }
                        if(HPincsel)
                            {
                                HPincsel = false;
                                MPincsel = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_LEFT) != 0)
                    {
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCursor, 0, &thread);
#endif
                        moved = true;
                        if(MPincsel)
                            {
                                MPincsel = false;
                                MPpotsel = true;
                                break;
                            }

                        if(HPincsel)
                            {
                                HPincsel = false;
                                HPpotsel = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_RIGHT) != 0)
                    {
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCursor, 0, &thread);
#endif
                        moved = true;
                        if(MPpotsel)
                            {
                                MPpotsel = false;
                                MPincsel = true;
                                break;
                            }

                        if(HPpotsel)
                            {
                                HPpotsel = false;
                                HPincsel = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_LCONTROL) != 0)
                    {
#ifdef __linux__

#elif _WIN32
                        _beginthread(closeMenu, 0, &thread);
#endif
                        moved = true;
                        printf("\n\t\tClosing Inventory...");
                        limitFPS(1000);
                        return;
                    }

                if(GetAsyncKeyState (VK_LSHIFT) != 0)
                    {
                        if(HPpotsel)
                            if(playerChar.it.HPpotion > 0 && playerChar.current_HP < playerChar.max_HP)
                            {
#ifdef __linux__

#elif _WIN32
                        _beginthread(useItem, 0, &thread);
#endif
                                moved = true;
                                int recov_hp = (playerChar.max_HP * 0.2);
                                playerChar.current_HP += recov_hp;

                                if(playerChar.current_HP > playerChar.max_HP)
                                    {
                                        int correct_hp = playerChar.current_HP - playerChar.max_HP;
                                        recov_hp -= correct_hp;
                                        playerChar.current_HP = playerChar.max_HP;
                                    }
                                printf("\n%s recovered %d HP.", playerChar.name, recov_hp);
                                playerChar.it.HPpotion -= 1;
                                limitFPS(800);
                            }

                        if(MPpotsel)
                            if(playerChar.it.MPpotion > 0 && playerChar.current_MP < playerChar.max_MP)
                            {
#ifdef __linux__

#elif _WIN32
                        _beginthread(useItem, 0, &thread);
#endif
                                moved = true;
                                int recov_mp = (playerChar.max_MP * 0.2);
                                playerChar.current_MP += recov_mp;

                                if(playerChar.current_MP > playerChar.max_MP)
                                    {
                                        int correct_mp = playerChar.current_MP - playerChar.max_MP;
                                        recov_mp -= correct_mp;
                                        playerChar.current_MP = playerChar.max_MP;
                                    }
                                printf("\n%s recovered %d MP.", playerChar.name, recov_mp);
                                playerChar.it.MPpotion -= 1;
                                limitFPS(800);
                            }

                        if(HPincsel)
                            if(playerChar.it.HPinc > 0)
                            {
#ifdef __linux__

#elif _WIN32
                        _beginthread(useItem, 0, &thread);
#endif
                                moved = true;
                                int increase_hp = (playerChar.max_HP * 1.05) - playerChar.max_HP;
                                printf("\n%s's max HP increased by %d points..", playerChar.name, increase_hp);
                                playerChar.max_HP *= 1.05;
                                playerChar.current_HP += increase_hp;
                                playerChar.it.HPinc -= 1;
                                limitFPS(800);
                            }

                        if(MPincsel)
                            if(playerChar.it.MPinc > 0)
                            {
#ifdef __linux__

#elif _WIN32
                        _beginthread(useItem, 0, &thread);
#endif
                                moved = true;
                                int increase_mp = (playerChar.max_MP * 1.05) - playerChar.max_MP;
                                printf("\n%s's max MP increased by %d points.", playerChar.name, increase_mp);
                                playerChar.max_MP *= 1.05;
                                playerChar.current_MP += increase_mp;
                                playerChar.it.MPinc -= 1;
                                limitFPS(800);
                            }

                    }

                if(GetAsyncKeyState (VK_LMENU) != 0)
                {
#ifdef __linux__

#elif _WIN32
                        _beginthread(endGame, 0, &thread);
#endif             
                    printf("\n\tTERMINATING THE GAME...");
                    limitFPS(1000);
#ifdef __linux__

#elif _WIN32
    system("taskkill /F /T /IM wmplayer.exe");
#endif  
                    exit(0);
                }
                limitFPS(0);
            }
        }
}

void showPlayerStats_Map()
{
    printf("\t  Player:");
    SetColor(3);
    printf("%s",playerChar.name);
    SetColor(15);
    printf("\n\t  Level:");
    SetColor(14);
    printf("%d", playerChar.Level);
    SetColor(15);
    printf("  Gold:");
    SetColor(6);
    printf("%d", playerChar.gold);
    SetColor(15);
    printf("  Got Key:");
    SetColor(2);
    printf("%s \n", playerChar.key ? " Yes" : " No");
    SetColor(15);
    printf("\t|___________________________________|  |\t  STRATEGY GUIDE  \t|\n");
    printf("\t|        cur / max       cur/max    |  |P-CHAR E-ENTRANCE F-FINISH K-KEY|\n");
    printf("\t|");
    SetColor(10);
    printf("    HP: %d/%d",playerChar.current_HP, playerChar.max_HP);
    SetColor(15);
    printf(" | ");
    SetColor(9);
    printf("MP: %d/%d    ", playerChar.current_MP, playerChar.max_MP);
    SetColor(15);
    printf("|  | B-BOSS ?-ITEM N-NPC M-MERCHANT |\n");
    printf("\t|___________________________________|  |____________COMMANDS____________|\n");
    SetColor(11);
    printf("\t|atk: %d",playerChar.atk);
    SetColor(15);
    printf("|");
    SetColor(13);
    printf("def: %d", playerChar.def);
    SetColor(15);
    printf("|");
    SetColor(1);
    printf("int: %d", playerChar.inte);
    SetColor(15);
    printf("|");
    SetColor(5);
    printf("lck: %d", playerChar.luck);
    SetColor(15);
    printf("|  |  ARROWS-MOVE  LCTRL-INVENTORY  |\n");

    printf("\t|XP:(");


    short int percent; // XP bar calculus, has a conditional structure to prevent XP overflow(from level 2 to 3, the XP increase caused a infinite loop on print).
    if(playerChar.Level > 1)
        percent = (int) (((float)playerChar.current_XP / (float)playerChar.next_XP) * 31);
    else
        percent = (int) (((float)playerChar.current_XP / (float)playerChar.next_XP) * 32);

        SetColor(14);
    for(unsigned short int i = 0; i < percent; i++) printf(">");

      SetColor(15);

    for(short int i = 32 - percent - 2; i > 0; i--)
    printf(" ");

    printf(")|  |      LSHIFT-OPEN SKILLTREE     |");
}
