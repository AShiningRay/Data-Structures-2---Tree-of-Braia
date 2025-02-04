#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "../Combat/Combat.h"
#include "../TAD_DialogHash/Dialogs_PlayerLines.h"
#include "../TAD_DialogHash/DialogsNPC.h"
#include "Area1_NavigationScreens.h"
#include "Minimaps.h"

void talkToMerchant();
void talkToNPC2();
void talkToNPC3();
void talkToNPC4();
void talkToNPC5();
void talkToNPC6();
void renderAreaNavigation(int areaIndex, int navIndex, int *playerX, int *playerY);

char logo[39][150] =
{
"================================================================================================================================================",
"                                      ######################################################################                                    ",
"                                 ######################################################################################                         ",
"                             ##################################################################################################                 ",
"              ################################################################################################################                  ",
"                     ######################################################################################################                     ",
"         ############################################################################################################################           ",
"       ##################################################################################################################################       ",
" #########  ________  _______   ________  ________         ______   ________        _______   _______    ______   ______   ______   #######     ",
"#########  |        ;|       ; |        ;|        ;       /      ; |        ;      |       ; |       ;  /      ; |      ; /      ;    #######   ",
"  ######    ;########| #######;| ########| ########      |  ######;| ########      | #######;| #######;|  ######; ;######|  ######;    #######  ",
"########      | ##   | ##__| ##| ##__    | ##__          | ##  | ##| ##__          | ##__/ ##| ##__| ##| ##__| ##  | ##  | ##__| ##     ######  ",
"########      | ##   | ##    ##| ##  ;   | ##  ;         | ##  | ##| ##  ;         | ##    ##| ##    ##| ##    ##  | ##  | ##    ##     ########",
" #######      | ##   | #######;| #####   | #####         | ##  | ##| #####         | #######;| #######;| ########  | ##  | ########     ########",
"#########     | ##   | ##  | ##| ##_____ | ##_____       | ##__/ ##| ##            | ##__/ ##| ##  | ##| ##  | ## _| ##_ | ##  | ##    ######## ",
"  ########    | ##   | ##  | ##| ##     ;| ##     ;       ;##    ##| ##            | ##    ##| ##  | ##| ##  | ##|   ## ;| ##  | ##   ######### ",
"    #######    ;##    ;##   ;## ;######## ;########        ;######  ;##             ;#######  ;##   ;## ;##   ;## ;###### ;##   ;##  #########  ",
"     #######                                                                                                                         ########## ",
"          ####                                    ######################################                                            ############",
"            ######################################                                      ##############################################          ",
"               ####################################################################################################################             ",
"                                              ################################################################                                  ",
"                                ##########################################################################################                      ",
"                                                   ###########################################################                                  ",
"                                        ###########################################################                                             ",
"                                                                 (||||||||||)                                                                   ",
"                                                                 (|||||||||)                                                                    ",
"                                                                 (||||||||)                                                                     ",
"                                                                 (||||||||)                                                                     ",
"                                                                 (||||||||)                                                                     ",
"                                                                 (||||||||)                                                                     ",
"                                                                 (||||||||)              >>  PRESS CTRL TO START THE GAME                       ",
"                                                                 (|||||||||)                                                                    ",
"                                                                 (||||||||||)                                                                   ",
"                                                                 (||||||||||||)                                                                 ",
"                                                                 (|||||||||||||)                                                                ",
"                                                                 (||||||||||||||)                                                               ",
"                                                                 (||||||||||||||||)                                                             ",
"================================================================================================================================================"
};

char credits[80][60] =
{
"",
"",
"",
"",
"               DEVELOPED BY BRAIA SOFTWORKS",
"",
"",
"",
"                      LEAD DEVELOPERS",
"",
"             Paulo Sousa      Game Designer                ",
"           Matheus Rondon      Game Designer               ",
"                                                           ",
"                           WRITING                         ",
"",
"            Kaio Nascimento    Main Writer                 ",
"            Paulo Sousa        Secondary Writer            ", ///////
"            Matheus Rondon     Secondary Writer            ",
"",
"                           ART",
"",
"           Matheus Rondon      Lead Artist                 ",
"            Paulo Sousa       Secondary Artist             ",
"           Wisley Kilder      Secondary Artist             ",
"                                                           ",
"                       PROGRAMMING",
"",
"            Paulo Sousa       Lead Programmer              ",
"            Matheus Rondon   Secondary Programmer          ",
"",
"                         TESTING",
"                                   ",
"             Tulio Estrela      Main playthrough tester    ",
"             Wisley Kilder      Main gameplay tester       ",
"             Kaio Nascimento    Secondary gameplay tester  ",
"",
"                    SOUND ENGINEERING",
"                                   ",
"             Paulo Sousa    Main Sound Developer     ",
"             Matheus Rondon    Secondary Sound Developer   ",
"             Matheus Rondon    Audio Engineer",
"",
"                    TAD DEVELOPMENT",
"                                   ",
"             Paulo Sousa    Main TAD Developer     ",
"             Matheus Rondon    Secondary TAD Developer    ",
"             Tulio Estrela   Main TAD Tester",
"             Kaio Nascimento Secondary TAD Tester",
};

void showLogo();
void hub();
void area1();
void area1_int();
int area2();
void area3();
void ending();

bool drawSelectMenu();

short int thread;

Hash *playerDialogs = NULL; //InsertHashData();
Hash_NPC *NPCDialogs = NULL; //InsertHashDataNPC();



void showLogo()
{
    bool start = false;

    while(!start)
        {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
            for(short int y = 0; y <39; y++)
            {
                int xmax = strlen(logo[y]);

                for(int x = 0; x < xmax; x++)
                    {
                        if (logo[y][x] == '#')
                        {
                            textcolor(GREEN);
                            textbackground(GREEN);
                        }
                        if (logo[y][x] == '|')
                            {
                                textcolor(BROWN);
                                textbackground(BROWN);
                            }
                        if (logo[y][x] == '(')
                            {
                                textcolor(BROWN);
                                textbackground(BROWN);
                            }
                        if (logo[y][x] == ';')
                            {
                                textcolor(BROWN);
                                textbackground(BROWN);
                            }
                        if (logo[y][x] == '/')
                            {
                                textcolor(BROWN);
                                textbackground(BROWN);
                            }
                        if (logo[y][x] == '_')
                            {
                                textcolor(BROWN);
                                textbackground(BROWN);
                            }
                        if (logo[y][x] == ')')
                            {
                                textcolor(BROWN);
                                textbackground(BROWN);
                            }

                        if (logo[y][x] == '>') textcolor(BLUE);
                        if (logo[y][x] == 'P') textcolor(RED);
                        if (logo[y][x] == 'R') textcolor(RED);
                        if (logo[y][x] == 'E') textcolor(RED);
                        if (logo[y][x] == 'S') textcolor(RED);
                        if (logo[y][x] == 'C') textcolor(RED);
                        if (logo[y][x] == 'T') textcolor(RED);
                        if (logo[y][x] == 'L') textcolor(RED);
                        if (logo[y][x] == 'O') textcolor(RED);
                        if (logo[y][x] == 'A') textcolor(RED);
                        if (logo[y][x] == 'H') textcolor(RED);
                        if (logo[y][x] == 'G') textcolor(RED);
                        if (logo[y][x] == 'M') textcolor(RED);
                        if (logo[y][x] == 'E') textcolor(RED);
                        putchar(logo[y][x]);

                        textcolor(WHITE);
                        textbackground(BLACK);
                    }
                    putchar('\n');
            }

            while(1)
                {
                    if(GetAsyncKeyState (VK_LCONTROL) != 0)
                    {
                        return;
                    }
                }
        }
}

void hub()
{
    playerDialogs = InsertHashData();
    NPCDialogs = InsertHashDataNPC();
    bool moved = false;
    limitFPS(100);
    
    playBGM("HubWorld");
    while(1)
        {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
            for(short int y = 0; y <28; y++)
            {
                moved = false;
                int xmax = strlen(HUB[y]);

                for(int x = 0; x < xmax; x++)
                    {
                        if (HUB[y][x] == '#')
                        {
                            textcolor(LIGHTGREEN);
                            textbackground(LIGHTGREEN);
                        }
                        if (HUB[y][x] == 'P')
                        {
                            textcolor(CYAN);
                        }
                        if (HUB[y][x] == 'F')
                        {
                            textcolor(RED);
                        }
                        if (HUB[y][x] == '|')
                        {
                            textcolor(BLACK);
                            textbackground(BROWN);
                        }
                        if (HUB[y][x] == '`')
                        {
                            textcolor(BROWN);
                            textbackground(BROWN);
                        }
                        if (HUB[y][x] == '+')
                        {
                            textcolor(RED);
                            textbackground(RED);
                        }
                        if (HUB[y][x] == '-')
                        {
                            textcolor(WHITE);
                            textbackground(WHITE);
                        }
                        if (HUB[y][x] == 'v')
                        {
                            textcolor(BLUE);
                        }
                        if (HUB[y][x] == '^')
                        {
                            textcolor(BLUE);
                        }
                        if (HUB[y][x] == 'w')
                        {
                            textcolor(RED);
                        }
                        if (HUB[y][x] == '*')
                        {
                            textcolor(LIGHTRED);
                            textbackground(LIGHTRED);
                        }
                        if (HUB[y][x] == ';')
                        {
                            textcolor(GREEN);
                        }
                        if (HUB[y][x] == 'x')
                        {
                            textcolor(BROWN);
                            textbackground(BROWN);
                        }
                        if (HUB[y][x] == ':')
                        {
                            textcolor(GREEN);
                            textbackground(GREEN);
                        }
                        if (HUB[y][x] == 'R')
                        {
                            textcolor(LIGHTGREEN);
                        }
                        if (HUB[y][x] == '?')
                        {
                            textcolor(LIGHTRED);
                            textbackground(YELLOW);
                        }
                        if (HUB[y][x] == '~')
                        {
                            textcolor(WHITE);
                            textbackground(CYAN);
                        }
                        if (HUB[y][x] == 'E')
                        {
                            textcolor(DARKGRAY);
                        }
                        if (HUB[y][x] == '=')
                        {
                            textbackground(WHITE);
                        }
                        if (HUB[y][x] == '/')
                        {
                            textbackground(WHITE);
                        }
                        if(HUB[y][x] == '1')
                        {
                            textcolor(LIGHTCYAN);
                        }
                        if(HUB[y][x] == '2')
                        {
                            textcolor(LIGHTCYAN);
                        }
                        if(HUB[y][x] == '3')
                        {
                            textcolor(LIGHTCYAN);
                        }
                        if(HUB[y][x] == '4')
                        {
                            textcolor(LIGHTCYAN);
                        }
                        if(HUB[y][x] == '5')
                        {
                            textcolor(LIGHTCYAN);
                        }
                        if(HUB[y][x] == '6')
                        {
                            textcolor(LIGHTCYAN);
                        }


                        putchar(HUB[y][x]);
                        textcolor(WHITE);
                        textbackground(BLACK);
                    }
                putchar('\n');
            }

            renderMainPartyStats(false, "");

            while (!moved) {

            for(short int y = 0; y < 28; y++)
            {
                for(short int x = 0; x < 100; x++)
                    {
                        switch(HUB[y][x])
                        {
                            case 'P':
                            {
                                 if(GetAsyncKeyState (VK_UP) != 0)
                                    {
                                        playBGM("FootStep");
                                        short int y2 = (y - 1);
                                        switch(HUB[y2][x])
                                        {
                                            case ':': case ';': case '.': case ' ':
                                            {
                                                 HUB[y][x] = HUB[y2][x];
                                                 y -=1;
                                                 HUB[y2][x] = 'P';
                                                 moved = true;
                                            } break;
                                            case 'F':
                                            {
                                                area2();
                                            } break;
                                            case '?':
                                            {
                                                moved = true;
                                                printf("%s GOT A HP POTION!", character[0].name);
                                                limitFPS(1000);
                                                HUB[y-1][x] = ' ';
                                                character[0].it.HPpotion += 1;
                                            }
                                            case '1' :
                                            {
                                                moved = true;
                                                talkToMerchant();
                                            } break;

                                            case '2' :
                                            {
                                                    moved = true;
                                                    talkToNPC2();
                                            } break;

                                            case '3' :
                                            {
                                                    moved = true;
                                                    talkToNPC3();
                                            } break;

                                            case '4' :
                                            {
                                                    moved = true;
                                                    talkToNPC4();
                                            } break;

                                            case '5' :
                                            {
                                                    moved = true;
                                                    talkToNPC5();
                                            } break;

                                            case '6' :
                                            {
                                                    moved = true;
                                                    talkToNPC6();
                                            } break;

                                        }
                                    }

                                if(GetAsyncKeyState (VK_DOWN) != 0)
                                    {
                                        playBGM("FootStep");
                                        short int y2 = (y + 1);
                                        switch(HUB[y2][x])
                                        {
                                            case ':': case ';': case '.': case ' ':
                                            {
                                                HUB[y][x] = HUB[y2][x];
                                                 y +=1;
                                                 HUB[y2][x] = 'P';
                                                 moved = true;
                                            } break;
                                            case 'F':
                                            {
                                                area2();
                                            } break;
                                            case '?':
                                            {
                                                moved = true;
                                                printf("%s GOT A HP POTION!", character[0].name);
                                                limitFPS(1000);
                                                HUB[y+1][x] = ' ';
                                                character[0].it.HPpotion += 1;
                                            }
                                            case '1' :
                                            {
                                                moved = true;
                                                talkToMerchant();
                                            } break;

                                            case '2' :
                                            {
                                                    moved = true;
                                                    talkToNPC2();
                                            } break;

                                            case '3' :
                                            {
                                                    moved = true;
                                                    talkToNPC3();
                                            } break;

                                            case '4' :
                                            {
                                                    moved = true;
                                                    talkToNPC4();
                                            } break;

                                            case '5' :
                                            {
                                                    moved = true;
                                                    talkToNPC5();
                                            } break;

                                            case '6' :
                                            {
                                                    moved = true;
                                                    talkToNPC6();
                                            } break;

                                        }
                                    }

                                if(GetAsyncKeyState (VK_LEFT) != 0)
                                    {
                                        playBGM("FootStep");
                                        int x2 = (x - 1);
                                        switch(HUB[y][x2])
                                        {
                                            case ':': case ';': case '.': case ' ':
                                            {
                                                HUB[y][x] = HUB[y][x2];
                                                 x -=1;
                                                 HUB[y][x2] = 'P';
                                                 moved = true;
                                            } break;
                                            case 'F':
                                            {
                                                area2();
                                            } break;
                                            case '?':
                                            {
                                                moved = true;
                                                printf("%s GOT A HP POTION!", character[0].name);
                                                limitFPS(1000);
                                                HUB[y][x-1] = ' ';
                                                character[0].it.HPpotion += 1;
                                            }
                                            case '1' :
                                            {
                                                moved = true;
                                                talkToMerchant();
                                            } break;

                                            case '2' :
                                            {
                                                    moved = true;
                                                    talkToNPC2();
                                            } break;

                                            case '3' :
                                            {
                                                    moved = true;
                                                    talkToNPC3();
                                            } break;

                                            case '4' :
                                            {
                                                    moved = true;
                                                    talkToNPC4();
                                            } break;

                                            case '5' :
                                            {
                                                    moved = true;
                                                    talkToNPC5();
                                            } break;

                                            case '6' :
                                            {
                                                    moved = true;
                                                    talkToNPC6();
                                            } break;

                                        }
                                    }

                                if(GetAsyncKeyState (VK_RIGHT) != 0)
                                    {
                                        playBGM("FootStep");
                                        int x2 = (x + 1);
                                        switch(HUB[y][x2])
                                        {
                                            case ':': case ';': case '.': case ' ':
                                            {
                                                HUB[y][x] = HUB[y][x2];
                                                 x +=1;
                                                 HUB[y][x2] = 'P';
                                                 moved = true;
                                            } break;
                                            case 'F':
                                            {
                                                area2();
                                            } break;
                                            case '?':
                                            {
                                                moved = true;
                                                printf("%s GOT A HP POTION!", character[0].name);
                                                limitFPS(1000);
                                                HUB[y][x+1] = ' ';
                                                character[0].it.HPpotion += 1;
                                            }
                                            case '1' :
                                            {
                                                moved = true;
                                                talkToMerchant();
                                            } break;

                                            case '2' :
                                            {
                                                    moved = true;
                                                    talkToNPC2();
                                            } break;

                                            case '3' :
                                            {
                                                    moved = true;
                                                    talkToNPC3();
                                            } break;

                                            case '4' :
                                            {
                                                    moved = true;
                                                    talkToNPC4();
                                            } break;

                                            case '5' :
                                            {
                                                    moved = true;
                                                    talkToNPC5();
                                            } break;

                                            case '6' :
                                            {
                                                    moved = true;
                                                    talkToNPC6();
                                            } break;

                                        }
                                    }
                                    if(GetAsyncKeyState (VK_LCONTROL) != 0)
                                        {
                                            playSFX("OpenMenu");
                                            moved = true;
                                            openInventory();
                                        }

                                    if(GetAsyncKeyState (VK_LSHIFT) != 0)
                                        {
                                            playSFX("OpenMenu");
                                            moved = true;
                                            renderPlayerSkillMenu();
                                        }

                            }
                        }

                    }
            }

        } // Ends the Move function
    }

}



void area1()
{
    short int encounterChance = 0;
    bool moved = false;
    int levelCap = 9, navIndex = 0, navIndexTmp = 0;
    int playerX = 0, playerY = 0;
    playBGM("Area1");
    while(1)
    {
#ifdef __linux__
        system("clear");
#elif _WIN32
        system("cls");
#endif

        renderAreaNavigation(0, navIndex, &playerX, &playerY);
        putchar('\n');

        renderMainPartyStats(false, "");

        moved = false;

        while (!moved) 
        {
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY-1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                limitFPS(0);
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1"); 
                            }
                            MAP_1[playerY][playerX] = MAP_1[playerY-1][playerX];
                            MAP_1[--playerY][playerX] = 'P';
                            moved = true;
                            do
                            {
                                navIndexTmp = rand() % 3;
                            } while (navIndexTmp == navIndex);
                            navIndex = navIndexTmp;
                    } break;
                    case 'F':
                    {
                        if(character[0].key)
                            hub();
                        else
                        {
                            SetColor(4);
                            printf("\nYou have not found the key yet!");
                            SetColor(15);
                            limitFPS(1500);
                        }
                    } break;
                    case 'E':
                    {
                        area1_int();
                    }break;
                    case '?':
                    {
                        moved = true;

                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                limitFPS(0);
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1");
                            }
                            MAP_1[playerY][playerX] = MAP_1[playerY+1][playerX];
                            MAP_1[++playerY][playerX] = 'P';
                            moved = true;
                            do
                            {
                                navIndexTmp = rand() % 3;
                            } while (navIndexTmp == navIndex);
                            navIndex = navIndexTmp;
                    } break;
                    case 'F':
                    {
                        if(character[0].key)
                            hub();
                        else
                        {
                            SetColor(4);
                            printf("\nYou have not found the key yet!");
                            SetColor(15);
                            limitFPS(1500);
                        }
                    } break;
                    case 'E':
                    {
                        area1_int();
                    }
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[++playerY][playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                limitFPS(0);
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1");
                            }
                            MAP_1[playerY][playerX] = MAP_1[playerY][playerX-1];
                            MAP_1[playerY][--playerX] = 'P';
                            moved = true;
                            do
                            {
                                navIndexTmp = rand() % 3;
                            } while (navIndexTmp == navIndex);
                            navIndex = navIndexTmp;
                    } break;
                    case 'F':
                    {
                        if(character[0].key)
                            hub();
                        else
                        {
                            SetColor(4);
                            printf("\nYou have not found the key yet!");
                            SetColor(15);
                            limitFPS(1500);
                        }
                    } break;
                    case 'E':
                    {
                        area1_int();
                    }
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[playerY][--playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                limitFPS(0);
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1");
                            }
                            MAP_1[playerY][playerX] = MAP_1[playerY][playerX+1];
                            MAP_1[playerY][++playerX] = 'P';
                            moved = true;
                            do
                            {
                                navIndexTmp = rand() % 3;
                            } while (navIndexTmp == navIndex);
                            navIndex = navIndexTmp;
                    } break;
                    case 'F':
                    {
                        if(character[0].key)
                            hub();
                        else
                        {
                            SetColor(4);
                            printf("\nYou have not found the key yet!");
                            SetColor(15);
                            limitFPS(1500);
                        }
                    } break;
                    case 'E':
                    {
                        area1_int();
                    }
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[playerY][++playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }
            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                renderPlayerSkillMenu();
            }
            limitFPS(0);
        } // Ends the Move function
    }
}

void area1_int() // TODO: Progression temporarily blocked here. The KEY interaction should start a boss fight.
{
    short int encounterChance = 0;
    bool moved = false;
    int levelCap = 9, playerX, playerY;

    while(1)
        {
#ifdef __linux__
        system("clear");
#elif _WIN32
        system("cls");
#endif
        for(short int y = 0; y <12; y++)
        {
            moved = false;
            short int xmax = strlen(MAP_1_int[y]);

            for(short int x = 0; x < xmax; x++)
            {
                if (MAP_1_int[y][x] == '#')
                    {
                        textcolor(GREEN);
                        textbackground(GREEN);
                    }
                if (MAP_1_int[y][x] == 'P') 
                { 
                    textcolor(CYAN);
                    playerX = x;
                    playerY = y;
                }
                if (MAP_1_int[y][x] == '|')
                {
                    textcolor(BROWN);
                    textbackground(BROWN);
                }
                if (MAP_1_int[y][x] == 'E') textcolor(DARKGRAY);

                if (MAP_1_int[y][x] == 'K') textcolor(LIGHTMAGENTA);

                if (MAP_1_int[y][x] == '-')
                {
                    textcolor(BROWN);
                    textbackground(BROWN);
                }

                if (MAP_1_int[y][x] == '?')
                {
                    textcolor(BLUE);
                    textbackground(YELLOW);
                }

                putchar(MAP_1_int[y][x]);
                textcolor(WHITE);
                textbackground(BLACK);
            }
            putchar('\n');
        }

        renderMainPartyStats(false, "");

        while (!moved) 
        {
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;
                
                switch(MAP_1[playerY-1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1"); 
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[--playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'E':
                    {
                        return;
                    }break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT an MP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[++playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'E':
                    {
                        return;
                    }break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT an MP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][--playerX] = 'P';
                            moved = true;
                    } break;
                    case 'E':
                    {
                        return;
                    }break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT an MP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area1");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][++playerX] = 'P';
                            moved = true;
                    } break;
                    case 'E':
                    {
                        return;
                    }break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT an MP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                renderPlayerSkillMenu();
            }
            limitFPS(0);
        } // Ends the Move function
    }
}

int area2()
{
    short int encounterChance = 0;
    bool moved = false;
    int levelCap = 19, playerX, playerY;

    playBGM("Area2");
    while (1)
            {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
                for(short int y = 0; y <28; y++)
                {
                    moved = false;
                    short int xmax = strlen(MAP_2[y]);

                    for(short int x = 0; x < xmax; x++)
                        {
                            if (MAP_2[y][x] == '#')
                        {
                            textcolor(LIGHTGREEN);
                            textbackground(LIGHTGREEN);
                        }
                        if (MAP_2[y][x] == 'P')
                        {
                            textcolor(CYAN);
                        }
                        if (MAP_2[y][x] == 'F')
                        {
                            textcolor(RED);
                        }
                        if (MAP_2[y][x] == '|')
                        {
                            textcolor(BLACK);
                            textbackground(BROWN);
                        }
                        if (MAP_2[y][x] == '`')
                        {
                            textcolor(BROWN);
                            textbackground(BROWN);
                        }
                        if (MAP_2[y][x] == '?')
                        {
                            textcolor(LIGHTRED);
                            textbackground(YELLOW);
                        }
                        if (MAP_2[y][x] == '~')
                        {
                            textcolor(WHITE);
                            textbackground(CYAN);
                        }
                        if (MAP_2[y][x] == 'E')
                        {
                            textcolor(DARKGRAY);
                        }
                        if (MAP_2[y][x] == '=')
                        {
                            textbackground(WHITE);
                        }
                        if  (MAP_2[y][x] == ';')
                        {
                            textcolor(GREEN);
                        }
                        if  (MAP_2[y][x] == ':')
                        {
                            textbackground(GREEN);
                            textcolor(BLACK);
                        }
                        if  (MAP_2[y][x] == '*')
                        {
                            textcolor(GREEN);
                        }
                        if  (MAP_2[y][x] == '.')
                        {
                            textcolor(YELLOW);
                        }
                        if  (MAP_2[y][x] == '-')
                        {
                            textbackground(BROWN);
                            textcolor(BLACK);
                        }
                        if (MAP_2[y][x] == 'K') textcolor(LIGHTMAGENTA);

                            putchar(MAP_2[y][x]);
                            textcolor(WHITE);
                            textbackground(BLACK);
                        }
                        putchar('\n');
                }

            renderMainPartyStats(false, "");

        while (!moved) 
        {
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY-1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area2"); 
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[--playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        area3();
                        moved = true;
                        return 1;
                    }
                    case 'E':
                    {
                        area1_int();
                    }break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area2");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[++playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        area3();
                        moved = true;
                        return 1;
                    }
                    case 'E':
                    {
                        area1_int();
                    }
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[++playerY][playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area2");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][--playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        area3();
                        moved = true;
                        return 1;
                    }
                    case 'E':
                    {
                        area1_int();
                    }
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[playerY][--playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area2");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][++playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        area3();
                        moved = true;
                        return 1;
                    }
                    case 'E':
                    {
                        area1_int();
                    }
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[playerY][++playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }

                }
            }
            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                renderPlayerSkillMenu();
            }
            limitFPS(0);
        } // Ends the Move function
    }
}

void area3()
{
    short int encounterChance = 0;
    bool moved = false;
    int levelCap = 29, playerX, playerY;

    playBGM("Area3");   
    while (1)
            {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
                for(short int y = 0; y <28; y++)
                {
                    moved = false;
                    short int xmax = strlen(MAP_3[y]);

                    for(short int x = 0; x < xmax; x++)
                        {
                        if (MAP_3[y][x] == '#')
                        {
                            textcolor(LIGHTGREEN);
                            textbackground(LIGHTGREEN);
                        }
                        if (MAP_3[y][x] == 'P')
                        {
                            textcolor(CYAN);
                        }
                        if (MAP_3[y][x] == 'F')
                        {
                            textcolor(RED);
                        }
                        if (MAP_3[y][x] == '|')
                        {
                            textcolor(BLACK);
                            textbackground(BLUE);
                        }
                        if (MAP_3[y][x] == '_')
                        {
                            textcolor(BLACK);
                            textbackground(BLUE);
                        }
                        if (MAP_3[y][x] == '`')
                        {
                            textcolor(BROWN);
                            textbackground(BROWN);
                        }
                        if (MAP_3[y][x] == '?')
                        {
                            textcolor(LIGHTRED);
                            textbackground(YELLOW);
                        }
                        if (MAP_3[y][x] == '~')
                        {
                            textcolor(WHITE);
                            textbackground(CYAN);
                        }
                        if (MAP_3[y][x] == 'E')
                        {
                            textcolor(DARKGRAY);
                        }
                        if (MAP_3[y][x] == '=')
                        {
                            textbackground(WHITE);
                        }
                        if  (MAP_3[y][x] == ';')
                        {
                            textcolor(GREEN);
                        }
                        if  (MAP_3[y][x] == ':')
                        {
                            textbackground(GREEN);
                            textcolor(BLACK);
                        }
                        if  (MAP_3[y][x] == '*')
                        {
                            textcolor(GREEN);
                        }
                        if  (MAP_3[y][x] == '.')
                        {
                            textcolor(CYAN);
                        }
                        if  (MAP_3[y][x] == '-')
                        {
                            textbackground(BROWN);
                            textcolor(BLACK);
                        }
                        if (MAP_3[y][x] == 'K') textcolor(LIGHTMAGENTA);

                            putchar(MAP_3[y][x]);
                            textcolor(WHITE);
                            textbackground(BLACK);
                        }
                        putchar('\n');
                }

            renderMainPartyStats(false, "");

        while (!moved) 
        {
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY-1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area3"); 
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[--playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        fightBoss(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }
                    case 'K':
                    {
                    printf("\n%s Found the key, but it is being guarded by a Boss!", character[0].name);
                    limitFPS(800);
                    fightBoss(20);
                    character[0].key = true;
                    MAP_3[--playerY][playerX] = ' ';
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area3");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[++playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        fightBoss(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[++playerY][playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }
                    case 'K':
                    {
                        printf("\n%s Found the key, but it is being guarded by a Boss!", character[0].name);
                        limitFPS(800);
                        fightBoss(20);
                        character[0].key = true;
                        MAP_3[++playerY][playerX] = ' ';
                    }
                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area3");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][--playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        fightBoss(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[playerY][--playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }
                    case 'K':
                    {
                        printf("\n%s Found the key, but it is being guarded by a Boss!", character[0].name);
                        limitFPS(800);
                        fightBoss(20);
                        character[0].key = true;
                        MAP_3[playerY][--playerX] = ' ';
                    }
                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87)
                            {
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM("Area3");
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][++playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        fightBoss(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        MAP_1[playerY][++playerX] = ' ';
                        character[0].it.HPpotion += 1;
                    }
                    case 'K':
                    {
                        printf("\n%s Found the key, but it is being guarded by a Boss!", character[0].name);
                        limitFPS(800);
                        fightBoss(20);
                        character[0].key = true;
                        MAP_3[playerY][++playerX] = ' ';
                    }
                }
            }
            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                renderPlayerSkillMenu();
            }
            limitFPS(0);
        } // Ends the Move function
    }
}


void talkToMerchant()
{
    SearchHash_NPC(NPCDialogs, 1, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    bool buy = drawSelectMenu();
    if(buy)
        {
            if(character[0].gold >= 250)
                {
                    SearchHash_NPC(NPCDialogs, 2, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                    character[0].gold -= 250;
                    character[0].it.HPpotion += 1;
                    character[0].it.MPpotion += 1;
                }

            else if (character[0].it.HPpotion == 9 || character[0].it.MPpotion == 9)
                {
                    SearchHash_NPC(NPCDialogs, 6, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                }
            else
                {
                    SearchHash_NPC(NPCDialogs, 5, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                }

        }
    else
        {
            SearchHash_NPC(NPCDialogs, 3, &npcLine);
            printf("\n\t\t%s", npcLine.speak);
        }
    limitFPS(700);
    SearchHash_NPC(NPCDialogs, 4, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(2000);
}

void talkToNPC2()
{
    SearchHash_NPC(NPCDialogs, 10, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 4, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(1200);
}

void talkToNPC3()
{
    SearchHash_NPC(NPCDialogs, 8, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 5, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC4()
{
    SearchHash_NPC(NPCDialogs, 11, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 3, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC5()
{
    SearchHash_NPC(NPCDialogs, 9, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 6, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC6()
{
    SearchHash_NPC(NPCDialogs, 12, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 7, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

bool drawSelectMenu()
{
    bool moved = false;
    bool yes = true;
    while (1)
        {
            moved = false;

            if(yes)
            {
                printf("\t [ ");
                SetColor(12);
                printf(">> ");
                SetColor(15);
                printf("Yes      No ]");
                printf("\033[20D");
            }

            else
            {
                printf("\t [    Yes   ");
                SetColor(12);
                printf(">> ");
                SetColor(15);
                printf("No ]");
                printf("\033[20D");
            }
            limitFPS(150);
            while(!moved)
            {
                if(GetAsyncKeyState (VK_RIGHT) != 0)
                    {
                        moved = true;
                        playSFX("CursorMove");
                        if(yes)
                            {
                                yes = false;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_LEFT) != 0)
                    {
                        moved = true;
                        playSFX("CursorMove");
                        if(!yes)
                            {
                                yes = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_LCONTROL) != 0)
                    {
                        moved = true;
                        playSFX("OpenMenu");
                        if(yes) return 1;
                        else return 0;
                    }

            }
        }

    return 0;
}

void ending()
{
    short int ymax = 1;
    while(ymax !=50)
        {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
                for(short int y = 0; y <ymax; y++)
                {
                    int xmax = strlen(credits[y]);

                    for(short int x = 0; x < xmax; x++)
                        {
                            putchar(credits[y][x]);
                            textcolor(WHITE);
                            textbackground(BLACK);
                        }
                    putchar('\n');
                }
            ymax++;
        }
}

void renderAreaNavigation(int areaIndex, int navIndex, int *playerX, int *playerY)
{
    // Update player map position first
    for(unsigned char y = 0; y <28; y++)
    {
        short int xmax = strlen(MAP_1[y]);

        for(unsigned char x = 0; x < xmax; x++)
        {

            if (MAP_1[y][x] == 'P')
            {
                *playerX = x;
                *playerY = y;
            }
        }
    }
    if(areaIndex == 1) { navIndex += 9; }
    printf("  ┌─────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    for(int y = 0; y < NAVAREA_YSIZE; y++) 
    {
        printf("  │");
        for(int x = 0; x < NAVAREA_XSIZE; x++) 
        {
            char pixelToDraw = navAreas[navIndex][y][x];
            applyColorPalette(pixelToDraw);
            putchar(pixelToDraw);
            textcolor(WHITE);
            textbackground(BLACK);
        }
        printf("│");

        // Draw the mini-map at the side
        if(y == (NAVAREA_YSIZE/2) - 8) { printf("  ┌─────────────────┐"); }
        else if(y == (NAVAREA_YSIZE/2) - 7 || y == (NAVAREA_YSIZE/2) + 7) { printf("  │                 │");}
        else if(y > (NAVAREA_YSIZE/2) - 7 && y < (NAVAREA_YSIZE/2) + 7)
        {
            printf("  │ ");
            int minimapY = *playerY - 7 + (y - (NAVAREA_YSIZE/2) + 7);
            //printf("minimapY:%d", minimapY);
            for(int minimapX = 0; minimapX < 15; minimapX++) 
            {
                if(minimapY*(strlen(MAP_1[0])) + *playerX - 7 + minimapX < 0 ||
                minimapY*(strlen(MAP_1[0])) + *playerX - 7 + minimapX > sizeof(MAP_1) ||
                *playerX - 7 + minimapX < 0 || minimapY >= sizeof(MAP_1) / sizeof(MAP_1[0]) ||
                *playerX - 7 + minimapX >= strlen(MAP_1[minimapY]))
                {
                    textcolor(WHITE);
                    textbackground(BLACK);
                    putchar(' ');
                }
                else 
                {
                    char pixelToDraw = MAP_1[minimapY][*playerX - 7 + minimapX];
                    applyColorPalette(pixelToDraw);
                    putchar(pixelToDraw);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
            }
            printf(" │");
        }
        else if (y == (NAVAREA_YSIZE/2) + 8) { printf("  └─────────────────┘"); }

        printf("\n");
    }
    printf("  └─────────────────────────────────────────────────────────────────────────────────────────────────────┘");

}