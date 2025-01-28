#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "../Combat/Combat.h"
#include "../TAD_DialogHash/Dialogs_PlayerLines.h"
#include "../TAD_DialogHash/DialogsNPC.h"

void talkToMerchant();
void talkToNPC2();
void talkToNPC3();
void talkToNPC4();
void talkToNPC5();
void talkToNPC6();

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



char HUB[30][100] =
{
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"===========~~~~~~~~~~~~=============~~~===~~===================~~~~~~~~~~~~~~~~~~=========~~~~~",
"~=        ==============           ===== ====                 ==================== ;   ; ===~~~",
"~~=                                                                ;  ;  #####       ;  ; =~~~~",
"~~~=         ++++++++  |;; ;; ;; ;; ;;; ; ;;|               -------- ;  ####*##   ; ;  ; =~~~~~",
"~~~~=        |vvvvvv|  | ;; ;; ;; ;; ;; ;; ;|    :::        |wwwwww|;  ##*###*##;    ;  =~~~~~~",
"~~~~~=       |      |  |; ;; ;; ;; ;; ;; ;; |   :   :       |      | ;  ##|||##   ;    =~~~~~~~",
"~~~~=        | 1    |   ====================   :  R  :      |  2   |   ;  |||  ;   ;  =~~~~~~~~",
"~~~=         |----  |                           :   :       |----  | ; ;  |||    ;   =~~~~~~~~~",
"~~=  ========        ============================   ========        ==================~~~~~~~~~",
"=====                                                                                =~~~~~~~~~",
"P                                                                                     =~~~~~~~~",
"=====                     3                                                            =~~~~~~~",
"~~~~~=                                                                                  =~~~~~~",
"~~~~~~=                                                  5                               =~~~~~",
"~~~~~~~=                                                                                =~~~~~~",
"~~~~~~~~=            #####                                                               ======",
"~~~~~~~=            ####*##            4                                                      F",
"~~~~~~=  ^^^^^^    ##*####*#     ------------                 +++            6           ======",
"~~~~~~~==++++++=== ####*#### ===/~~~~~~~~~~~~/=======        +++++                 ======~~~~~~",
"~~~~~~=  xxxxxx   = # ||| # =   /~~~~~~~~~~~~/ ;    =  +++++++xxx+++++++++++++++  = ;    =~~~~~",
"~~~~~=   xxxxxx    = ;||| ;=    /~~~~~~~~~~~~/    ;  = ++++++xxxxx++++++++++++++ =       =~~~~~",
"~~~~=    |    |    =; |||; =     ------------ ;       =xxxxxxxxxxxxxxxxxxxxxxxxx=    ;  =~~~~~~",
"~~~=               = ; ;  ;=                    ;      xxxxxxxxxxxxxxxxxxxxxxxxx   ;   =~~~~~~~",
"~~=                 = ; ; =                  ;     ;   xxxxxx     xxxxxxxxxxxxxx      =~~~~~~~~",
"~~=             ;    =====       ;             ;                   ;      ;          ; =~~~~~~~",
"~~=                        ;                         ;     ;   ;       ;     ;   ;      =~~~~~~",
"~~~======================================================================================~~~~~~"
};

char MAP_1[28][100] =
{
"========",
"=      ?==~~~~~~~~~~~~~~~~       ~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"=         =~~~~~~~~~~~~~~~~~   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"=          =~~~===========~~~  ~~~=====================~~~~~~",
"=           ===           =~~~~~~=                     =~~~~~~",
"=                          =~~~~=                       =~~~~~",
"=                           ===                         =~~~",
"=                                                        =~~~",
"=                                        ====             =~~~~~~",
"=                                       =~~~~=             ====~~~~",
"=                                      =~~~~~~=                =~~~~~",
"=                                       =~~~~=                =====",
"=                                        ====                    F=",
"=                        ##############                       =====",
"=                      ####################                  =~~~~~~~~",
"=                    #########################                =~~~",
"=                   ###########################                =~~~~~~",
"=                  #############################                =~",
"=                 ##############################                =~~~",
"=                 #######     ||||   ##########              ===~~",
"=                             ||||                          =~~~",
"=                             ||||                         =~~~~",
"=                             ||||                        =~~~~~",
"=                            ;|EE|;                ======~~~~~~",
"=                                            ======~~~~~~~",
"=           __                              =~~~~~~~",
"= P        ;  :                            =~~~~~~",
"===========================================~~~~"
};

char MAP_1_int[12][18] =
{
"#################",
"#K       | ######",
"|##  |    #   ?#|",
"|  #####   #  ###",
"|           # |#|",
"|   |           |",
"|  |            |",
"|  |    P       |",
"|  |            |",
"-------EE--------"
};

char MAP_2[28][100] =
{
"        --        -----                ----                  --",
"       |P |      |  .  |              |   ?|                 |F|                |",
"      |   |     |  .    ---          |      |             |-|   -|             -|",
"     |     |---|  .  .  .  |----||--|--      |           -  -  -  |          -| |",
"    |    ?     |    .    .     ..  .   |      |         |          |       -|    |",
"   |            |   .    .    .   .   |        -|      |            |    -|     |",
"  |              |     .    .. . .   |           -|---|              |--|       |",
" |                |    .            |                                            |",
"  |                |---------------|                                              |",
"   |                                                                             |",
"    |                    *  ;:;  *                                                |",
"     |                    **;:;**                 *  ;:;  *                      |",
"    |                       ;:;                    **;:;**                        |",
"     |                      ;:;                      ;:;                           |",
"    |                              ---   ----        ;:;                          |",
"   |                              |~~~---~~~~|                                   |",
"  |                              |~~~~~~~~~~~~|                                   |",
" |                               |~~~~~~~~~~~~|             *  ;:;  *              |",
"  |         *  ;:;  *             |---~~~~---|               **;:;**                |",
"   |         **;:;**    |--------|    ----           |-----|   ;:;                 |",
"    |          ;:;     |~~~~~~~~~~|                 |~~~~~~~|  ;:;                |",
"   |           ;:;     |~~~~~~~~~~|                 |~~~~~~~|          -- --     |",
"  |                     |--------|                   |-----|          |     |    |",
"   |                   --------------                                |       |    |",
"    |                 |  .  .     .  |--        |-- ? |-----|         |     |    |",
"   |       | ---|    |    .     .    .  |-     |   |--       |----|    | K |    |",
"  |       |      |---  .    . .     .  .  |----                    |-----------|",
"   -------"
};

char MAP_3[28][50] =
{
"                                                ",
"",
"",
"",
"",
"",
"",
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"|~~|______________====________________~~|",
".|~~|            =    =               |~~|",
"|~~|               ==                 ?|~~|",
"~~|________     _==~~==________       |~~|",
"~~|. . .. .=   = . |~~| .   . .|     |~~~~|",
"|~~~~~~~~~~~=   =~~~~~~|________=   =~~~~~~|",
"|~~|_________=   =___~~~~~~~~~~~~=   =~~~~~|",
"~~|               |  |~~| ._______=   =___|",
"|~~|               ||~~|  |. __          |",
"~~|_____      ______|~~|_|. |~~|         |",
"~~| .  .|=   =. . .|~~| | . |~~|          |",
"~~~~~~~~~~=   =~~~~~~~~~~| . __ ?          |",
"~~~~~~~~~~~=   =~~~~~~~~~~~ _______=  =|____|",
"|~~|_______|=   = |~~|  |~~~~~~~~~~~=  =~~~~~|",
".|~~| . .  |   |___|~~|__|~~~~~~~~~~~=  =~~~~~|",
". |~~|.  .  |   | . |~~| .|___________=  =~~~~~|",
" . |~~|   . .|   |   |~~|    .  .  .  |=  =|~~~~|",
". . |~~|.  .  |   | . |~~| .  .   .  |     |~~~~|",
" ___|~~|______| P |___|~~|__________|   F   |~~~~",
"~~~~~~~~~~~~~~|___|~~~~~~~~~~~~~~~~~~_______~~~~~"
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
#ifdef __linux__

#elif _WIN32
    system("taskkill /F /T /IM wmplayer.exe");
#endif  

    limitFPS(100);
    
    playBGMHUB();

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

            showPlayerStats_Map();

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
#ifdef __linux__

#elif _WIN32
                                        _beginthread(footStep, 0, &thread);
#endif
                                        short int y2 = (y - 1);
                                        switch(HUB[y2][x])
                                        {
                                            case ' ':
                                            {
                                                HUB[y][x] = ' ';
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
                                                printf("%s GOT A HP POTION!", playerChar.name);
                                                limitFPS(1000);
                                                HUB[y-1][x] = ' ';
                                                playerChar.it.HPpotion += 1;
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
#ifdef __linux__

#elif _WIN32
                                        _beginthread(footStep, 0, &thread);
#endif
                                        short int y2 = (y + 1);
                                        switch(HUB[y2][x])
                                        {
                                            case ' ':
                                            {
                                                HUB[y][x] = ' ';
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
                                                printf("%s GOT A HP POTION!", playerChar.name);
                                                limitFPS(1000);
                                                HUB[y+1][x] = ' ';
                                                playerChar.it.HPpotion += 1;
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
#ifdef __linux__

#elif _WIN32
                                        _beginthread(footStep, 0, &thread);
#endif
                                        int x2 = (x - 1);
                                        switch(HUB[y][x2])
                                        {
                                            case ' ':
                                            {
                                                HUB[y][x] = ' ';
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
                                                printf("%s GOT A HP POTION!", playerChar.name);
                                                limitFPS(1000);
                                                HUB[y][x-1] = ' ';
                                                playerChar.it.HPpotion += 1;
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
#ifdef __linux__

#elif _WIN32
                                        _beginthread(footStep, 0, &thread);
#endif
                                        int x2 = (x + 1);
                                        switch(HUB[y][x2])
                                        {
                                            case ' ':
                                            {
                                                HUB[y][x] = ' ';
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
                                                printf("%s GOT A HP POTION!", playerChar.name);
                                                limitFPS(1000);
                                                HUB[y][x+1] = ' ';
                                                playerChar.it.HPpotion += 1;
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
#ifdef __linux__

#elif _WIN32
                                            _beginthread(openMenu, 0, &thread);
#endif
                                            moved = true;
                                            openInventory();
                                        }

                                    if(GetAsyncKeyState (VK_LSHIFT) != 0)
                                        {
#ifdef __linux__

#elif _WIN32
                                            _beginthread(openMenu, 0, &thread);
#endif
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
    int enemylevel = 0, playerX, playerY;
    playBGM1();
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
            int xmax = strlen(MAP_1[y]);

            for(int x = 0; x < xmax; x++)
            {
                if (MAP_1[y][x] == '#')
                {
                    textcolor(LIGHTGREEN);
                    textbackground(LIGHTGREEN);
                }
                if (MAP_1[y][x] == 'P')
                {
                    textcolor(CYAN);
                    playerX = x;
                    playerY = y;
                }
                if (MAP_1[y][x] == 'F')
                {
                    textcolor(RED);
                }
                if (MAP_1[y][x] == '|')
                {
                    textcolor(BLACK);
                    textbackground(BROWN);
                }
                if (MAP_1[y][x] == '`')
                {
                    textcolor(BROWN);
                    textbackground(BROWN);
                }
                if (MAP_1[y][x] == '?')
                {
                    textcolor(LIGHTRED);
                    textbackground(YELLOW);
                }
                if (MAP_1[y][x] == '~')
                {
                    textcolor(WHITE);
                    textbackground(CYAN);
                }
                if (MAP_1[y][x] == 'E')
                {
                    textcolor(DARKGRAY);
                }
                if (MAP_1[y][x] == '=')
                {
                    textbackground(WHITE);
                }

                putchar(MAP_1[y][x]);
                textcolor(WHITE);
                textbackground(BLACK);
            }
            putchar('\n');
        }

        showPlayerStats_Map();

        while (!moved) 
        {
            enemylevel = rand() % 6;

            if(GetAsyncKeyState (VK_UP) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY-1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                            
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[--playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        if(playerChar.key)
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                           
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[++playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        if(playerChar.key)
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[++playerY][playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                 
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][--playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        if(playerChar.key)
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[playerY][--playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                               
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][++playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        if(playerChar.key)
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[playerY][++playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }
            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                limitFPS(1000);
                openMenu();
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                limitFPS(1000);
                openMenu();
                moved = true;
                renderPlayerSkillMenu();
            }
            limitFPS(0);
        } // Ends the Move function
    }
}

void area1_int()
{
    short int encounterChance = 0;
    bool moved = false;
    int enemylevel = 0, playerX, playerY;

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

        showPlayerStats_Map();

        while (!moved) 
        {
            enemylevel = rand() % 6;

            if(GetAsyncKeyState (VK_UP) != 0)
            {
                footStep();
                encounterChance = rand() % 100;
                
                switch(MAP_1[playerY-1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                            
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
                        printf("%s GOT an MP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                           
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
                        printf("%s GOT an MP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                 
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
                        printf("%s GOT an MP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                               
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
                        printf("%s GOT an MP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.MPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                limitFPS(500);
                openMenu();
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                limitFPS(500);
                openMenu();
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
    int enemylevel = 0, playerX, playerY;
#ifdef __linux__

#elif _WIN32
    ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\Music7.ogg\",",NULL,SW_HIDE);
#endif        
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

            showPlayerStats_Map();

        while (!moved) 
        {
            enemylevel = (rand() % 8) + 11;
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY-1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                            
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                           
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[++playerY][playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                 
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[playerY][--playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                               
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
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[playerY][++playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }

                }
            }
            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                limitFPS(1000);
                openMenu();
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                limitFPS(1000);
                openMenu();
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
    int enemylevel = 0, playerX, playerY;
#ifdef __linux__

#elif _WIN32
    ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\Music5.ogg\",",NULL,SW_HIDE);
#endif        
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

            showPlayerStats_Map();

        while (!moved) 
        {
            enemylevel = (rand() % 8) + 21;
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY-1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                            
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[--playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        combat(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[--playerY][playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }
                    case 'K':
                    {
                    printf("\n%s Found the key, but it is being guarded by a Boss!", playerChar.name);
                    limitFPS(800);
                    combat(20);
                    playerChar.key = true;
                    MAP_3[--playerY][playerX] = ' ';
                    }

                }
            }

            else if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY+1][playerX])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                           
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[++playerY][playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        combat(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[++playerY][playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }
                    case 'K':
                    {
                        printf("\n%s Found the key, but it is being guarded by a Boss!", playerChar.name);
                        limitFPS(800);
                        combat(20);
                        playerChar.key = true;
                        MAP_3[++playerY][playerX] = ' ';
                    }
                }
            }

            else if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX-1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                                 
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][--playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        combat(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[playerY][--playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }
                    case 'K':
                    {
                        printf("\n%s Found the key, but it is being guarded by a Boss!", playerChar.name);
                        limitFPS(800);
                        combat(20);
                        playerChar.key = true;
                        MAP_3[playerY][--playerX] = ' ';
                    }
                }
            }

            else if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                footStep();
                encounterChance = rand() % 100;

                switch(MAP_1[playerY][playerX+1])
                {
                    case ' ':
                    {
                        if(encounterChance >= 80)
                            {
                                combat(enemylevel);
                                playBGM1();                               
                            }
                            MAP_1[playerY][playerX] = ' ';
                            MAP_1[playerY][++playerX] = 'P';
                            moved = true;
                    } break;
                    case 'F':
                    {
                        combat(30);
                        limitFPS(4000);
                        ending();
                    } break;
                    case '?':
                    {
                        moved = true;
                        printf("%s GOT A HP POTION!", playerChar.name);
                        limitFPS(1000);
                        MAP_1[playerY][++playerX] = ' ';
                        playerChar.it.HPpotion += 1;
                    }
                    case 'K':
                    {
                        printf("\n%s Found the key, but it is being guarded by a Boss!", playerChar.name);
                        limitFPS(800);
                        combat(20);
                        playerChar.key = true;
                        MAP_3[playerY][++playerX] = ' ';
                    }
                }
            }
            else if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                limitFPS(1000);
                openMenu();
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                limitFPS(1000);
                openMenu();
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
            if(playerChar.gold >= 250)
                {
                    SearchHash_NPC(NPCDialogs, 2, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                    playerChar.gold -= 250;
                    playerChar.it.HPpotion += 1;
                    playerChar.it.MPpotion += 1;
                }

            else if (playerChar.it.HPpotion == 9 || playerChar.it.MPpotion == 9)
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
    printf("\n\t\t%s%s", playerChar.name, pLine.speak);
    limitFPS(1200);
}

void talkToNPC3()
{
    SearchHash_NPC(NPCDialogs, 8, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 5, &pLine);
    printf("\n\t\t%s%s", playerChar.name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC4()
{
    SearchHash_NPC(NPCDialogs, 11, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 3, &pLine);
    printf("\n\t\t%s%s", playerChar.name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC5()
{
    SearchHash_NPC(NPCDialogs, 9, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 6, &pLine);
    printf("\n\t\t%s%s", playerChar.name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC6()
{
    SearchHash_NPC(NPCDialogs, 12, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 7, &pLine);
    printf("\n\t\t%s%s", playerChar.name, pLine.speak);
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
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCursor, 0, &thread);
#endif
                        if(yes)
                            {
                                yes = false;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_LEFT) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCursor, 0, &thread);
#endif
                        if(!yes)
                            {
                                yes = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_LCONTROL) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(openMenu, 0, &thread);
#endif
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
