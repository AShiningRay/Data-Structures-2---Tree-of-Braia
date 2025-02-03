#include "Player.h"

void openInventory();
void showCaracterStats_Inventory();

void openInventory()
{
    bool openingInventory = true;
    bool moved = false;
    bool HPpotsel = true;
    bool HPincsel = false;
    bool MPpotsel = false;
    bool MPincsel = false;
    short int thread;

    limitFPS(1000);
    if(GetAsyncKeyState(VK_LMENU) != 0) {}

    while (1)
        {
            moved = false;
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
            showCaracterStats_Inventory();

            SetColor(15);
            printf("\x1B[1m");
            printf("\n\n");
            printf("\t┌───────────────────INVENTORY─────────────────────┐\n");
            printf("\t│");
            if(HPpotsel) { SetColor(9); }
            printf(" %s HP POTION : %d      ", (HPpotsel ? "┼─" : "  "), character[0].it.HPpotion);
            SetColor(15);
            printf("│");
            if(HPincsel) { SetColor(9); }
            printf(" %s HP MAX BOOSTER : %d   ", (HPincsel ? "┼─" : "  "), character[0].it.HPinc);
            SetColor(15);
            printf("│\n");
            printf("\t│                       │                         │\n");
            printf("\t│");
            if(MPpotsel) { SetColor(9); }
            printf(" %s MP POTION : %d      ", (MPpotsel ? "┼─" : "  "), character[0].it.MPpotion);
            SetColor(15);
            printf("│");
            if(MPincsel) { SetColor(9); }
            printf(" %s MP MAX BOOSTER : %d   ", (MPincsel ? "┼─" : "  "), character[0].it.MPinc);
            SetColor(15);
            printf("│\n");
            // End of selectable items
            printf("\t├────────────────────COMMANDS─────────────────────┤\n");
            printf("\t│  LSHIFT-USE ITEM      │  ARROWS- MOVE SELECTOR  │\n");
            printf("\t│  LALT-CLOSE GAME      │  LCTRL - CLOSE INVENTORY│\n");
            printf("\t├───────────────────────┴─────────────────────────┤\n");
            printf("\t├────────────────ITEM DESCRIPTION─────────────────┤\n");
            printf("\t├─────────────────────────────────────────────────┤\n");
            printf("\t│        HP POTION : RECOVER 20%% FROM MAX HP      │\n");
            printf("\t│        MP POTION : RECOVER 20%% FROM MAX MP      │\n");
            printf("\t│   HP MAX BOOSTER : INCREASES THE MAX HP BY 5%%   │\n");
            printf("\t│   MP MAX BOOSTER : INCREASES THE MAX MP BY 5%%   │\n");
            printf("\t└─────────────────────────────────────────────────┘\n");
            printf("\x1B[0m");

            if(openingInventory)
            {
                openingInventory = false;
                limitFPS(1000);
            }

            while(!moved)
            {
                 if(GetAsyncKeyState (VK_UP) != 0)
                    {
                        playSFX("MoveCursor");
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
                        playSFX("MoveCursor");
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
                        playSFX("MoveCursor");
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
                        playSFX("MoveCursor");
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
                        playSFX("ReturnFromMenu");
                        moved = true;
                        printf("\n\t\tClosing Inventory...");
                        limitFPS(1000);
                        return;
                    }

                if(GetAsyncKeyState (VK_LSHIFT) != 0)
                    {
                        if(HPpotsel)
                            if(character[0].it.HPpotion > 0 && character[0].current_HP < character[0].max_HP)
                            {
                                playSFX("UseItem");
                                moved = true;
                                int recov_hp = (character[0].max_HP * 0.2);
                                character[0].current_HP += recov_hp;

                                if(character[0].current_HP > character[0].max_HP)
                                    {
                                        int correct_hp = character[0].current_HP - character[0].max_HP;
                                        recov_hp -= correct_hp;
                                        character[0].current_HP = character[0].max_HP;
                                    }
                                printf("\n%s recovered %d HP.", character[0].name, recov_hp);
                                character[0].it.HPpotion -= 1;
                                limitFPS(800);
                            }

                        if(MPpotsel)
                            if(character[0].it.MPpotion > 0 && character[0].current_MP < character[0].max_MP)
                            {
                                playSFX("UseItem");
                                moved = true;
                                int recov_mp = (character[0].max_MP * 0.2);
                                character[0].current_MP += recov_mp;

                                if(character[0].current_MP > character[0].max_MP)
                                    {
                                        int correct_mp = character[0].current_MP - character[0].max_MP;
                                        recov_mp -= correct_mp;
                                        character[0].current_MP = character[0].max_MP;
                                    }
                                printf("\n%s recovered %d MP.", character[0].name, recov_mp);
                                character[0].it.MPpotion -= 1;
                                limitFPS(800);
                            }

                        if(HPincsel)
                            if(character[0].it.HPinc > 0)
                            {
                                playSFX("UseItem");
                                moved = true;
                                int increase_hp = (character[0].max_HP * 1.05) - character[0].max_HP;
                                printf("\n%s's max HP increased by %d points..", character[0].name, increase_hp);
                                character[0].max_HP *= 1.05;
                                character[0].current_HP += increase_hp;
                                character[0].it.HPinc -= 1;
                                limitFPS(800);
                            }

                        if(MPincsel)
                            if(character[0].it.MPinc > 0)
                            {
                                playSFX("UseItem");
                                moved = true;
                                int increase_mp = (character[0].max_MP * 1.05) - character[0].max_MP;
                                printf("\n%s's max MP increased by %d points.", character[0].name, increase_mp);
                                character[0].max_MP *= 1.05;
                                character[0].current_MP += increase_mp;
                                character[0].it.MPinc -= 1;
                                limitFPS(800);
                            }

                    }

                if(GetAsyncKeyState (VK_LMENU) != 0)
                {
                    playSFX("CloseGame");     
                    printf("\n\tTERMINATING THE GAME...");
                    limitFPS(1000);
                    exit(0);
                }
                limitFPS(0);
            }
        }
}

void showCaracterStats_Inventory()
{
    printf("\x1B[1m");
    
    printf("\t  Player:");
    SetColor(3);
    printf("%s",character[0].name);
    SetColor(15);
    printf("\n\t  Level:");
    SetColor(14);
    printf("%d", character[0].Level);
    SetColor(15);
    printf("  Gold:");
    SetColor(6);
    printf("%d", character[0].gold);
    SetColor(15);
    printf("  Got Key:");
    SetColor(2);
    printf("%s \n", character[0].key ? " Yes" : " No");
    SetColor(15);
    printf("\t├───────────────────────────────────────────┤  │\t  STRATEGY GUIDE  \t│\n");
    printf("\t│    cur / max      cur / max       cur/max │  │P-CHAR E-ENTRANCE F-FINISH K-KEY│\n");
    printf("\t│");
    SetColor(10);
    printf(" HP:%4d/%4d",character[0].current_HP, character[0].max_HP);
    SetColor(15);
    printf(" │ ");
    SetColor(9);
    printf("MP:%4d/%4d ", character[0].current_MP, character[0].max_MP);
    SetColor(15);
    printf(" │ ");
    SetColor(14);
    printf("AP:%3d/%d ", 0, 100); // character[0].current_AP, character[0].max_AP); // AP not implemented yet
    SetColor(15);
    printf("│  │ B-BOSS ?-ITEM N-NPC M-MERCHANT │\n");
    printf("\t├───────────────────────────────────────────┤  ├────────────COMMANDS────────────┤\n");
    printf("\t│");
    SetColor(11);
    printf("  atk:%3d",character[0].atk);
    SetColor(15);
    printf("│");
    SetColor(13);
    printf("def:%3d", character[0].def);
    SetColor(15);
    printf("│");
    SetColor(1);
    printf("int:%3d", character[0].inte);
    SetColor(15);
    printf("│");
    SetColor(5);
    printf("lck:%3d", character[0].luck);
    SetColor(15);
    printf("│");
    SetColor(10);
    printf("spd:%3d  ", 0); // character[0].spd); //SPD stat not implemented
    SetColor(15);
    printf("│  │  ARROWS-MOVE  LCTRL-INVENTORY  │\n");

    printf("\t│XP:(");


    short int percent; // XP bar calculus, has a conditional structure to prevent XP overflow(from level 2 to 3, the XP increase caused a infinite loop on print).
    if(character[0].Level > 1)
        percent = (int) (((float)character[0].current_XP / (float)character[0].next_XP) * 31);
    else
        percent = (int) (((float)character[0].current_XP / (float)character[0].next_XP) * 32);

        SetColor(14);
    for(unsigned short int i = 0; i < percent; i++) printf(">");

      SetColor(15);

    for(short int i = 40 - percent - 2; i > 0; i--) { printf(" "); }

    printf(")│  │      LSHIFT-OPEN SKILLTREE     │");

    printf("\x1B[0m");
}


// TODO: This needs an overhaul
void renderPlayerSkillMenu()
{
    bool moved = false;
    moved = false;
    limitFPS(1000);
    while (1)
        {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
            printf("\t┌──────────────────────────────────────────────────────────────────────────┐\n");
            printf("\t│  Player:");
            SetColor(3);
            printf("%s\n", character[0].name);
            SetColor(15);
            printf("\t│___________________________________________________\n\n");
            print_skillTree((character[0].magtree), 20);
            printf("\n\t(Skills)\n\n");
            print_skillTree((character[0].phystree), 20);
            printf("\t|\tPRESS LSHIFT TO CLOSE THE MENU");
            printf("\n\t│___________________________________________________\n");

            while(!moved)
            {
                 if(GetAsyncKeyState (VK_LSHIFT) != 0)
                    {
                        moved = true;
                        printf("\n\tCLOSING THE MENU...");
                        limitFPS(1000);
                        return;
                    }
            }
        }
}