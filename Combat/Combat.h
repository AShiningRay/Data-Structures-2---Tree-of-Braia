#include "../EnemyData/Enemies.h"

char combat_anim1[30][130] =
{
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"                                                          BBBB",
"                                                          BBBB",
"",
"",
"",
"",
"",
"",
};

char combat_anim2[30][130] =
{
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"                                                      BBBBBBBBBBBB",
"                                                      BBBBBBBBBBBB",
"                                                       BBBBBBBBBBB",
"",
"",
"",
"",
"",
};

char combat_anim3[30][130] =
{
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"                                                    BBBBBBBBBBBBBBBBB",
"                                            BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBB                   BBBBBBBB",
"                                          BB                                BB",
"                                          BBBBBBBBBBB             BBBBBBBBBBBB",
"                                            BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                                  BBBBBBBBBBBBBBBBBB",
"",
"",
"",
};

char combat_anim4[30][130] =
{
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"                                       BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                               BBBBBBBBBBBBBBBBB                     BBBBBBBBBBBBBBBBB",
"                           BBBBBBBBBB                                               BBBBBBBB",
"                         BBBBBB                                                           BBBBBB",
"                        BBB                                                                   BB",
"                        BB                                                                    BB",
"                        BBBBB                                                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_yellowBlob[30][130] =
{
"",
"",
"",
"",
"",
"",
"",
"                                                        KKKKKKKK",
"                                                   KKKKKKRRRRRRKKKK",
"                                               KKKKKKKRRRRRRRRRRRKKKKK",
"                                           KKKKKKKKRRRRRRRRLLRRRLKKKKKKKKK",
"                                        KKKKKKKKKKLRRRRRRRRRRRRRLLLLLKKKKKKKK",
"                                      KKKKKKKKKKKKKLRRRRRRRRRRRRRLLLLLLLLKKKKK",
"                                     KKKKKKKKKKKKKKRRRRRRRRRRRRRRLLLLLLLLKKKKKK",
"                                    KKKKKKKKKKKKKKKKRRRRRRRRRRRRRRLLLLLLLLKKKKKKK",
"                                   KKKKKKKKKKKKKKKKKKKKKKLLRRRRRRRRRRRRLLLKKKKKKKK",
"                                   KKKKKKKKKKKKKKKKKKKKKKKKKRRRRRRRRRRRRRKKKKKKKKK",
"                                   KKKKKKKKKKKKKKKKKKKKKKKKKKRRRRRRRRRRRKKKKKKKKK",
"                               BBBB KKKKKKKKKKKKKKKKKKKKKKKKKKKKRRRRRKKKKKKKKKKK BBBBB",
"                           BBBBBBBBBB KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK      BBBBBBBB",
"                         BBBBBB        KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK             BBBBBB",
"                        BBB          KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK              BB",
"                        BB       KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK          BB",
"                        BBBBB                                                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_redBlob[30][130] =
{
"",
"",
"",
"",
"",
"",
"",
"                                                        RRRRRRR",
"                                                   RRRRRRTTTTTTRRRR",
"                                               RRRRRRRTTTTTTTTTTTRRRRR",
"                                           RRRRRRRRRRRRRRRRIITTTIRRRRRRRR",
"                                        RRRRRRRRRRITTTTTTTTTTTTTIIIIRRRRRRRR",
"                                      RRRRRRRRRRRRRITTTTTTTTTTTTTIIIIIIIIRRRRR",
"                                     RRRRRRRRRRRRRRTTTTTTTTTTTTTTIIIIIIIIIRRRRRR",
"                                    RRRRRRRRRRRRRRRRTTTTTTTTTTTTTTIIIIIIIIRRRRRRR",
"                                   RRRRRRRRRRRRRRRRRRRRRRIITTTTTTTTTTTTIIIRRRRRRRR",
"                                   RRRRRRRRRRRRRRRRRRRRRRRRRTTTTTTTTTTTTTRRRRRRRRR",
"                                   RRRRRRRRRRRRRRRRRRRRRRRRRRTTTTTTTTTTTRRRRRRRRR",
"                               BBBB RRRRRRRRRRRRRRRRRRRRRRRRRRRRTTTTTRRRRRRRRRRR BBBBB",
"                           BBBBBBBBBB RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR      BBBBBBBB",
"                         BBBBBB        RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR             BBBBBB",
"                        BBB          RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR              BB",
"                        BB       RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR          BB",
"                        BBBBB                                                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_cursArmor[30][130] =
{
"                                          		 WWWWWWWG",
"                                                       WWWGLGWWWWG",
"                                                       WWGRWRGWWWG",
"                                                       WWGRWRGWWWG",
"                                                       WWGRWRGWWG",
"                                                       WWGRRRGWW",
"",
"                                               WWWWWWWWWWWWWWWWWWWGGWGWWWG",
"                                          W  DWWWWWWWWWWWWWWWWWWWWWWWWWWWD   GG",
"                                        DWWWDD   WWWWWWWWWWWWWWWWWWWWWW D  D WRGG",
"                                      GWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWRWDDWWWWWWRGG",
"                                    DWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWWWWG  DWWWWWWRGG",
"                                   WWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWG      DWWWWWWRGG",
"                                 WWWWWWWWW         WWWWWWWWWWWWWWWWWG          DWWWWWWWWWWGG",
"                                DWWWWWWWD          WWWWWWWWWWWWWWWWWG            DWWWWWD LWW",
"                             WWWWWGWWWD  WG        DWWWWWWWWWWWWWWWWG              GWWWWG",
"                            WWW  WWWWWW W          RDWWWWWWWWWWWWWWWG              GWG  WW",
"                               GWWG WWWWWWWW BBBBB WWWWWWWWWWWWWWWWGG BBBBBBBBBBBB    WWW",
"                              BBBBBB  W WWWWRRRL    LLRRRRRRRRRRGGG  BBBBBBBBBBBBBBBBB",
"                           BBBBBBBBBB D      LRRRRRL      L  R   R                  BBBBBBBB",
"                         BBBBBB                    LRRRRL      L                          BBBBBB",
"                        BBB                            LRRRL    R                             BB",
"                        BB                                                                    BB",
"                        BBBBB                                                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_CGuy[30][130] =
{
"  	                                            WWWWWWWWWWWWWWW",
"                                             WW###WWWWWWWWW###WW",
"                                            W######WWWWWWW######WW",
"                                           W########WWWWW########WW",
"                                          WW########WWW###########WW",
"                                         #####   *###WW####*  #####W",
"                                         ######_  ###WWW##   _#####W",
"                                         W##########WWWWW##########WW",
"                                         WW########WWWWWWW########WWW",
"                                          WWWW#####WWWWWWWWW#####WWWW",
"                                          WWWWWWWWWWWWWWWWWWWWWWWWWWW",
"                                          WWWWW=##############=WWWWW",
"                                            WWW#################WWW",
"                                             WW###***********###WW",
"                               BBBBBBBBBBBBBB  W*WWWWWWWWWWWWWWW*WBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBB            WWWWWWWWWWWWWWW           BBBBBBBBBBBB",
"                        BBBBB                      WWWWWWWWWWW                     BBBBBBB",
"                        BBBBB                        WWWWWW                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_BChicken[30][130] =
{
"                                           #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#",
"                                          #WWWWWW_##_WWWWWWWWWWWWW_##_WWWWW#",
"                             ####         #WWWWWW*##*WWWWWWWWWWWWW*##*WWWWWW#       ####",
"                          ###   ###      ##WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#       ###  ###",
"                        ###       ###     ##WWWWWWWW#####***#####WWWWWWW##      ###      ###",
"                      ###          ###     ##WWWWWW##WWWWWWWWWWW##WWWWWW#     ###           ###",
"                                     ###     ##WWWWWWWWWWWWWWWWWWWWWWW##    ###",
"                                       ####### *#######################*######",
"                                               @@@@@@@@@@@@@@@@@@@@@@@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                               BBBBBBBBBBBBBBBB@@@@BBBBBBBBBBBBBBBBB@@@@*BBBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBB   @@@@                 @@@@         BBBBBBBBBBBBBBB",
"                        BBBBB              @@@@    @@@@         @@@@    @@@@                BBBBBBB",
"                        BBBBB                  @@@@                 @@@@                     BBBBBB",
"                         BBBBBBBBBBB                                                  BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_Cyclops[30][130] =
{
"                                                     #############",
"                                                   ##################",
"                                                 ######################",
"                                                #######################",
"                                                ########.......########",
"                                                #######...(%)...########",
"                                                #######.........#######",
"                                                 #######.......#######",
"                                                &&&&&&&&&&&&&&&&&&&&&&&&&&",
"                                                 &&&&&&&&&     &&&&&&&&&",
"                                                &&&&&&&&&&&&&&&&&&&&&&&&&&",
"                                                       WWWWWWWWWWWW",
"                                                      WWWWWWWWWWWWWW",
"                                                    WWWWWWWWWWWWWWWWWW",
"                                                    WWWW          WWWW",
"                                                    WWWW          WWWW",
"                                                    WWWWWWWWWWWWWWWWWW",
"                                                    WWWWWWWWWWWWWWWWWW",
"                               BBBBBBBBBBBBBBBBBBBBBWWWWBBBBBBBBBWWWWWBBBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBBBB     WWWW         WWWW      BBBBBBBBBBBBBBBBB",
"                        BBBBB                       WWWW         WWWW                   BBBBBBB",
"                        BBBBB                       WWWW          WWWW                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_Noname[30][130] =
{
"                                                     WWWWWNNNWWWWWWW",
"                                                   WWWWOOOOOOOOOOOWWWW",
"                                                 WWWWOOOOOOOOOOOOOOOOWWWW",
"                                               WWWWOOOOOOOOOOOOOOOOOOOWWWW",
"                                              WWWWOOOOOOOOOOOOOOOOOOOOOOWWWW",
"                                             WWWWOOOOOOOOOOOOOOOOOOOOOOOOWWWW",
"                                             WWWWOOOOOOOOOOOOOOOOOOOOOOOOWWWW",
"                                              WWWWWWOOOOOOOOOOOOOOOOOOOWWWWW",
"                                                WWWW  ################ WWWW",
"                                              WWWWWWWW   WWWWWWWW  WWWWWWWWWW",
"                                             WWWW000000000000000000000000NNWWW",
"                                            WWWWW0000000:........:000000WWWWWWW",
"                                            WWWWNNNNNNN::________::NNNNNNNWWWWW",
"                                         WWWW*******************************WWWW",
"                                          WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"                               BBBBBBBBBBBBBBBBBBBBBWWWWBBBBBBBBBWWWWBBBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBBB      WWWW         WWWW        BBBBBBBBBBBBBBB",
"                        BBBBB                       WWWW         WWWW                   BBBBBBB",
"                        BBBBB                       WWWW          WWWW                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_AlienV[30][130] =
{
"                 ##########                                                                ##########",
"                   ##########                         ##########                        ##########",
"                      ##########                   ####################              ##########",
"                         ##########           ##########          ##########       ##########",
"                           ##########      ##########                ##########  ##########",
"                              ##########   ##########  LLLLLLLLLLL  ########## ##########",
"                                 ##########             LLLLLLLLL            ##########",
"                                   ##########            LLLLLL           ##########",
"                                     ##########            LL           ##########",
"                                       ##########                     ##########",
"                                          ##########                ##########",
"                               BBBBBBBBBBBB##########BBBBBBBBBBBBB##########BBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBB #########        ##########       BBBBBBBBBBBBBBB",
"                        BBBBB                   #######################                   BBBBBBB",
"                        BBBBB                     ####################                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_BigO[30][130] =
{
"                                     ||                   ######                  ||",
"                                      ||            ##############               ||",
"                                       ||         ######################        ||",
"                                        ||    ##########          #########    ||",
"                                         ##########                ############",
"                                       #########                      ##########",
"                                       #########                       ##########",
"                                                &&&&&&&&&&&&&&&&&&&&&&&",
"                                      ##########                       ##########",
"                                       ##########                     ##########",
"                                         ##########                ##########",
"                               BBBBBBBBBBBB##########BBBBBBBBBBBBB##########BBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBB #########        ##########       BBBBBBBBBBBBBBB",
"                        BBBBB                   #######################                   BBBBBBB",
"                        BBBBB                     ####################                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};


void combat(int randEnemy);
void checkPlayerXP();

void renderCombatStartAnim();
void setAnimColors(char check);

void fightYBlob();
void fightRBlob();
void fightCursArmor();
void fightCGuy();
void fightBChicken();
void fightCyclops();
void fightAlienV();
void fightBigO();
void fightNoname();

void renderBGFrame1();
void renderBGFrame2();
void renderBGFrame3();
void renderBGFrame4();

void renderBGCurs();
void renderBGYBlob();
void renderBGRBlob();
void renderCGuy();
void renderBChicken();
void renderCyclops();
void renderAlienV();
void renderBigO();
void renderNoname();

void renderPlayerSkillMenu();
void renderPlayerCombatEnemyMenu();
bool renderPlayerMagicEnemyMenu();
void renderPlayerCombatStat();
void renderPlayerSkillMenu();
void renderEnemyCombatStat();

void playerAttackEnemy();
bool playerUseAqua();
bool playerUseWind();
bool playerUseFlame();
bool playerUseBlizzard();
bool playerUseEarth();

void enemyAttackPlayer();
void enemyDozesOff();

void enemyAction();

short int thread;

void combat(int randEnemy)
{
#ifdef __linux__

#elif _WIN32
    system("taskkill /F /T /IM wmplayer.exe");
#endif  

    if(randEnemy > 0 && randEnemy < 5)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicWar.ogg\",",NULL,SW_HIDE);
#endif  
            fightYBlob();
        }

    else if(randEnemy >= 5 && randEnemy < 10)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicWar.ogg\",",NULL,SW_HIDE);
#endif  
            fightRBlob();
        }

    else if(randEnemy == 10)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\BossMusic.ogg\",",NULL,SW_HIDE);
#endif  
            fightCursArmor();
        }

    else if(randEnemy > 10 && randEnemy <= 15)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicWar.ogg\",",NULL,SW_HIDE);
#endif  
            fightCGuy();
        }

    else if(randEnemy > 15 && randEnemy < 20)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicWar.ogg\",",NULL,SW_HIDE);
#endif  
            fightBChicken();
        }

    else if(randEnemy == 20)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\BossMusic.ogg\",",NULL,SW_HIDE);
#endif  
            fightCyclops();
        }

    else if(randEnemy > 20 && randEnemy <= 25)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicWar.ogg\",",NULL,SW_HIDE);
#endif  
            fightAlienV();
        }

    else if(randEnemy > 25 && randEnemy < 30)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\MusicWar.ogg\",",NULL,SW_HIDE);
#endif  
            fightBigO();
        }

    else if (randEnemy == 30)
        {
#ifdef __linux__

#elif _WIN32
            ShellExecute(NULL,"open","C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe" ,"/play \"C:\\Users\\paulo\\Desktop\\ED2 Project\\Game\\Audio Engine\\Samples\\BossMusic.ogg\",",NULL,SW_HIDE);
#endif  
            fightNoname();
        }

    checkPlayerXP();
#ifdef __linux__

#elif _WIN32
    system("taskkill /F /T /IM wmplayer.exe");
#endif  
}

void checkPlayerXP()
{
    bool leveledUp = false;
    int extra_XP = 0;

    if(playerChar.current_XP >= playerChar.next_XP)
        {
            leveledUp = true;
            extra_XP = (playerChar.current_XP - playerChar.next_XP);
        }


    if(leveledUp == true && playerChar.Level < 10)
        {
            SetColor(14);
            printf("\n\t\t%s Leveled UP\n", playerChar.name);
            SetColor(15);
            playerChar.Level += 1;
            playerChar.max_HP += 250;
            playerChar.current_HP = playerChar.max_HP;
            playerChar.max_MP += 80;
            playerChar.current_MP = playerChar.max_MP;
            playerChar.atk += 16;
            playerChar.def += 12;
            playerChar.inte += 10;
            playerChar.luck += 3;
            playerChar.next_XP *= 2;
            playerChar.current_XP = 0;
            playerChar.current_XP += extra_XP;

            if(playerChar.Level == 2)
                {
                    SetColor(10);
                    learnSkill(playerChar.magtree, "AQUA STORM");
                    printf("\t\t%s LEARNED AQUA STORM!\n", playerChar.name);
                    SetColor(15);
                }

            else if(playerChar.Level == 4)
                {
                    SetColor(10);
                    learnSkill(playerChar.phystree, "STR BOOST");
                    printf("\t\t%s LEARNED STR BOOST!\n", playerChar.name);
                    playerChar.atk *= 1.20;
                    SetColor(15);
                }

            else if(playerChar.Level == 3)
                {
                    SetColor(10);
                    learnSkill(playerChar.magtree, "WIND GUST");
                    printf("\t\t%s LEARNED WIND GUST!\n", playerChar.name);
                    playerChar.luck *= 1.05;
                    SetColor(15);
                }

            else if(playerChar.Level == 6)
                {
                    SetColor(10);
                    learnSkill(playerChar.magtree, "SCORCH FLAME");
                    printf("\t\t%s LEARNED SCORCH FLAME!\n", playerChar.name);
                    playerChar.inte *= 1.05;
                    SetColor(15);
                }

            else if(playerChar.Level == 7)
                {
                    SetColor(10);
                    learnSkill(playerChar.phystree, "DEF BOOST");
                    printf("\t\t%s LEARNED DEF BOOST!\n", playerChar.name);
                    playerChar.def *= 1.20;
                    SetColor(15);
                }

            else if(playerChar.Level == 8)
                {
                    SetColor(10);
                    learnSkill(playerChar.magtree, "BLIZZARD");
                    printf("\t\t%s LEARNED BLIZZARD!\n", playerChar.name);
                    playerChar.atk *= 1.03;
                    SetColor(15);
                }

            else if(playerChar.Level == 9)
                {
                    SetColor(10);
                    learnSkill(playerChar.magtree, "EARTH SMASH");
                    printf("\t\t%s LEARNED EARTH SMASH!\n", playerChar.name);
                    playerChar.def *= 1.03;
                    SetColor(15);
                }

            else if(playerChar.Level == 10)
                {
                    SetColor(10);
                    learnSkill(playerChar.phystree, "INT BOOST");
                    printf("\t\t%s LEARNED INT BOOST!\n", playerChar.name);
                    playerChar.inte *= 1.25;
                    SetColor(15);
                }
            limitFPS(700);
        }
    else if(playerChar.Level == 10) playerChar.current_XP = (playerChar.next_XP) - 1;
}


void renderCombatStartAnim()
{
    renderBGFrame1();
    limitFPS(0);
    renderBGFrame2();
    limitFPS(0);
    renderBGFrame3();
    limitFPS(0);
    renderBGFrame4();
}

void setAnimColors(char check)
{
    if(check == '*')
    {
        textcolor(LIGHTGREEN);
        textbackground(LIGHTGREEN);
    }
    else if(check == '(' || check == ')')
    {
        textcolor(GREEN);
        textbackground(GREEN);
    }
    else if(check == ')')
    {
        textcolor(GREEN);
        textbackground(GREEN);
    }
    else if(check == '&')
    {
        textcolor(LIGHTGREEN);
        textbackground(LIGHTGREEN);
    }
    else if(check == '%')
    {
        textcolor(DARKGRAY);
        textbackground(DARKGRAY);
    }
    else if(check == '@')
    {
        textcolor(BROWN);
        textbackground(BROWN);
    }
    else if(check == ',') SetColor(0);
    else if(check == '#' || check == '=')
        {
        textcolor(BROWN);
        textbackground(BROWN);
        }
    else if(check == '/')
    {
        textcolor(GREEN);
        textbackground(GREEN);
    }
    else if(check == '.')
    {
        textcolor(BLACK);
    }
    else if(check == 'W' || check == ':')
    {
        textcolor(WHITE);
        textbackground(WHITE);
    }
    else if(check == 'G' || check == 'O' || check == '0')
    {
        textcolor(DARKGRAY);
        textbackground(DARKGRAY);
    }
    else if(check == 'D')
    {
        textcolor(MAGENTA);
        textbackground(MAGENTA);
    }
    else if(check == 'L')
    {
        textcolor(LIGHTRED);
        textbackground(LIGHTRED);
    }
    else if(check == 'R' || check == 'N' || check == '\'')
    {
        textcolor(RED);
        textbackground(RED);
    }
    else if(check == 'B')
    {
        textcolor(BLUE);
        textbackground(BLUE);
    }
    else if(check == 'K' || check == '_')
    {
        textcolor(YELLOW);
        textbackground(YELLOW);
    }
    else if(check == 'T' || check == '@')
    {
        textcolor(GREEN);
        textbackground(GREEN);
    }
    else if(check == 'I')
    {
        textcolor(LIGHTGREEN);
        textbackground(LIGHTGREEN);
    }
    else if(check == '%')
    {
        textcolor(LIGHTRED);
        textbackground(LIGHTRED);
    }
    else if(check == '|')
    {
        textcolor(LIGHTRED);
        textbackground(LIGHTRED);
    }
}


// Animations below are the actual combat animations (X starts at 2 to enable damage animations "dislocation, similar to older pok�mon games")
void renderBGFrame1()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_anim1[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_anim1[y][x]);

                    putchar(combat_anim1[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
}

void renderBGFrame2()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_anim2[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_anim2[y][x]);

                    putchar(combat_anim2[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
}

void renderBGFrame3()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_anim3[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_anim3[y][x]);

                    putchar(combat_anim3[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
}

void renderBGFrame4()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_anim4[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_anim4[y][x]);

                    putchar(combat_anim4[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
}


void renderBGCurs()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();
        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_cursArmor[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_cursArmor[y][x]);

                    putchar(combat_cursArmor[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s defeated the Boss and gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}


void renderBGYBlob()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_yellowBlob[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_yellowBlob[y][x]);

                    putchar(combat_yellowBlob[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}


void renderBGRBlob()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();
        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_redBlob[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_redBlob[y][x]);

                    putchar(combat_redBlob[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}

void renderCGuy()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_CGuy[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_CGuy[y][x]);

                    putchar(combat_CGuy[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}

void renderBChicken()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_BChicken[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_BChicken[y][x]);

                    putchar(combat_BChicken[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}

void renderCyclops()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_Cyclops[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_Cyclops[y][x]);

                    putchar(combat_Cyclops[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s defeated the boss and gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}

void renderAlienV()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_AlienV[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_AlienV[y][x]);

                    putchar(combat_AlienV[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}

void renderBigO()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_BigO[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_BigO[y][x]);

                    putchar(combat_BigO[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}

void renderNoname()
{
    do
    {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    renderEnemyCombatStat();

        for(short int y = 0; y <30; y++)
        {
            int xmax = strlen(combat_Noname[y]);

            for(int x = 2; x < xmax; x++)
                {
                    setAnimColors(combat_Noname[y][x]);

                    putchar(combat_Noname[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    renderPlayerCombatEnemyMenu();
    enemyAction();
    } while (Enemy.current_HP > 0 && playerChar.current_HP > 0);

    if(Enemy.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s gained %d XP points!", playerChar.name, Enemy.XP_given);
            playerChar.current_XP += Enemy.XP_given;
            playerChar.gold += Enemy.gold_given;
        }
    else if(playerChar.current_HP <= 0)
        {
            printf("\033[2B");
            printf("\n\t\t%s died...", playerChar.name);
        }

    limitFPS(700);
}


void fightRBlob()
{
    generateEnemy("RED BLOB");
    renderCombatStartAnim();
    renderBGRBlob();
}

void fightYBlob()
{
    generateEnemy("YELLOW BLOB");
    renderCombatStartAnim();
    renderBGYBlob();
}

void fightCursArmor()
{
    generateEnemy("CURSED ARMOR");
    renderCombatStartAnim();
    renderBGCurs();
}

void fightCGuy()
{
    generateEnemy("C-GUY");
    renderCombatStartAnim();
    renderCGuy();
}

void fightBChicken()
{
    generateEnemy("BIG CHICKEN");
    renderCombatStartAnim();
    renderBChicken();
}

void fightCyclops()
{
    generateEnemy("CYCLOPS");
    renderCombatStartAnim();
    renderCyclops();
}

void fightAlienV()
{
    generateEnemy("ALIEN-V");
    renderCombatStartAnim();
    renderAlienV();
}

void fightBigO()
{
    generateEnemy("BIG-O");
    renderCombatStartAnim();
    renderBigO();
}

void fightNoname()
{
    generateEnemy("NONAME");
    renderCombatStartAnim();
    renderNoname();
}

void renderEnemyCombatStat()
{
    printf("\t\t\t/____________________________________________________________________\n");
    printf("\t\t\t|\t\t  Enemy:");
    SetColor(14);
    printf("%s\n", Enemy.name);
    SetColor(15);
    printf("\t\t\t|   HP:(");
    short int lifepercent; // enemy life bar percentage calculus.

        lifepercent = (int) (((float)Enemy.current_HP / (float)Enemy.max_HP) * 60);

        textbackground(RED);
        textcolor(RED);
    for(unsigned short int i = 0; i < lifepercent; i++) printf("+");

      textbackground(BLACK);
      textcolor(WHITE);


    for(short int i = 60 - lifepercent - 2; i > 0; i--)
    printf(" ");

    printf(")|\n");
    printf("\t\t\t|____________________________________________________________________|\n\n");
}

// Player UI in the map


void renderPlayerSkillMenu()
{
    bool moved = false;
    moved = false;
    limitFPS(250);
    while (1)
        {
#ifdef __linux__
            system("clear");
#elif _WIN32
            system("cls");
#endif
            printf("\t|___________________________________________________|\n");
            printf("\t|  Player:");
            SetColor(3);
            printf("%s\n", playerChar.name);
            SetColor(15);
            printf("\t|___________________________________________________\n\n");
            print_skillTree((playerChar.magtree), 20);
            printf("\n\t(Skills)\n\n");
            print_skillTree((playerChar.phystree), 20);
            printf("\t|\tPRESS LSHIFT TO CLOSE THE MENU");
            printf("\n\t|___________________________________________________\n");

            while(!moved)
            {
                 if(GetAsyncKeyState (VK_LSHIFT) != 0)
                    {
                        moved = true;
                        printf("\n\tCLOSING THE MENU...");
                        limitFPS(300);
                        return;
                    }
            }
        }
}

void renderPlayerCombatEnemyMenu()
{
    bool moved = false;
    bool atksel = true;
    bool skisel = false;
    bool magicused = false;

    while (1)
    {
        moved = false;
        renderPlayerCombatStat();

        if(atksel)
        {
            printf("\t|====ACTION====/\n");
            printf("\t| ");
            SetColor(12);
            printf(">>");
            SetColor(15);
            printf(" ATTACK   |\n");
            printf("\t|-------------|\n");
            printf("\t|    SKILL    |\n");
        }

        else if(skisel)
        {
            printf("\t|====ACTION====/\n");
            printf("\t|    ATTACK   |\n");
            printf("\t|-------------|\n");
            printf("\t| ");
            SetColor(12);
            printf(">>");
            SetColor(15);
            printf(" SKILL    |\n");
        }

        printf("\033[11A");
        while(!moved)
        {
            if(GetAsyncKeyState (VK_UP) != 0)
            {
                moved = true;
#ifdef __linux__

#elif _WIN32
                _beginthread(moveCombatCursor, 0, &thread);
#endif
                if(skisel)
                    {
                        skisel = false;
                        atksel = true;
                        break;
                    }
            }

            if(GetAsyncKeyState (VK_DOWN) != 0)
            {
                moved = true;
#ifdef __linux__

#elif _WIN32
                _beginthread(moveCombatCursor, 0, &thread);
#endif
                if(atksel)
                    {
                        atksel = false;
                        skisel = true;
                        break;
                    }
            }

            if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                moved = true;
#ifdef __linux__

#elif _WIN32
                _beginthread(moveCombatCursor, 0, &thread);
#endif
                if(atksel)
                    {
                        playerAttackEnemy();
                        return;
                    }

                else
                    {
                        magicused = renderPlayerMagicEnemyMenu();
                        if(magicused) return;
                    }
                limitFPS(250);
                break;
            }
            limitFPS(0);
        }
    }
}

// Player UI in combat

void renderPlayerCombatStat()
{
    printf("\t|___________________________________________________________________________|\n");
    printf("\t|  Player:");
    SetColor(3);
    printf("%s\n", playerChar.name);
    SetColor(15);
    printf("\t|____________________________________________________________________________\n");
    SetColor(10);
    printf("\t| HP: %d/%d |",playerChar.current_HP, playerChar.max_HP);
    SetColor(15);
    printf("__________________________COMMANDS__________________________|\n");
    SetColor(15);
    SetColor(9);
    printf("\t| MP: %d/%d   |", playerChar.current_MP, playerChar.max_MP);
    SetColor(15);
    printf("  CONTROL -> USE ACTION    LSHIFT -> RETURN TO ACTION SELECT|\n");
    printf("\t|---------------|");
    printf("              ARROWS -> MOVE BETWEEN ACTIONS                |\n");
    printf("\t|_______________|____________________________________________________________|\n");
}

bool renderPlayerMagicEnemyMenu()
{
    bool moved = false;
    short int skisel = 0;
    bool magicused = false;

    if(findSkill(playerChar.magtree, "AQUA STORM", false) == false)
        {
            renderPlayerCombatStat();
            printf("\033[5B");
            printf("\n\n\tYOU HAVE NO SKILLS YET!");
            printf("\033[14A");
            printf("\033[32D");

            limitFPS(1000);
            return false;
        }


    while (1)
        {
            moved = false;
            renderPlayerCombatStat();
            printf("\033[4B");

            if(skisel == 0)
            {
                printf("\t|=================MAGIC SELECTION=================||====MAGIC MP USE====|\n");
                printf("\t| ");
                SetColor(12);
                printf(">>");
                SetColor(10);
                printf(" 1-AQUA STORM");
                SetColor(15);
                if(findSkill(playerChar.magtree, "WIND GUST", false) == false) SetColor(0);
                printf("    2-WIND GUST");
                if(findSkill(playerChar.magtree, "SCORCH FLAME", false) == false) SetColor(0);
                printf("    3-SCORCH FLAME");
                SetColor(15);
                printf("|| 1-30    2-45   3-70|\n");
                printf("\t|    ");
                if(findSkill(playerChar.magtree, "BLIZZARD", false) == false) SetColor(0);
                printf("4-BLIZZARD  ");
                if(findSkill(playerChar.magtree, "EARTH SMASH", false) == false)SetColor(0);
                printf("    5-EARTH SMASH                ");
                SetColor(15);
                printf("|| 4-110   5-150      |\n");
            }

            else if(skisel == 1)
            {
                printf("\t|=================MAGIC SELECTION=================||\n");
                printf("\t| ");
                printf("   1-AQUA STORM ");
                SetColor(12);
                printf(">>");
                SetColor(10);
                printf(" 2-WIND GUST");
                SetColor(15);
                if(findSkill(playerChar.magtree, "SCORCH FLAME", false) == false) SetColor(0);
                printf("    3-SCORCH FLAME");
                SetColor(15);
                printf("|\n");
                printf("\t|");
                if(findSkill(playerChar.magtree, "BLIZZARD", false) == false)SetColor(0);
                printf("    4-BLIZZARD  ");
                if(findSkill(playerChar.magtree, "EARTH SMASH", false) == false)SetColor(0);
                printf("    5-EARTH SMASH");
                SetColor(15);
                printf("                |\n");
            }
            if(skisel == 2)
            {
                printf("\t|=================MAGIC SELECTION=================||\n");
                printf("\t| ");
                printf("   1-AQUA STORM");
                printf("    2-WIND GUST ");
                SetColor(12);
                printf(">>");
                SetColor(10);
                printf(" 3-SCORCH FLAME");
                SetColor(15);
                printf("|\n\t|");
                if(findSkill(playerChar.magtree, "BLIZZARD", false) == false)SetColor(0);
                printf("    4-BLIZZARD  ");
                if(findSkill(playerChar.magtree, "EARTH SMASH", false) == false)SetColor(0);
                printf("    5-EARTH SMASH");
                printf("                |\n");
            }
            if(skisel == 3)
            {
                printf("\t|=================MAGIC SELECTION=================||\n");
                printf("\t| ");
                printf("   1-AQUA STORM");
                printf("    2-WIND GUST");
                printf("    3-SCORCH FLAME|\n");
                printf("\t| ");
                SetColor(12);
                printf(">>");
                SetColor(10);
                printf(" 4-BLIZZARD  ");
                SetColor(15);
                if(findSkill(playerChar.magtree, "EARTH SMASH", false) == false)SetColor(0);
                printf("    5-EARTH SMASH");
                printf("                |\n");
            }
            if(skisel == 4)
            {
                printf("\t|=================MAGIC SELECTION=================||\n");
                printf("\t| ");
                printf("   1-AQUA STORM");
                printf("    2-WIND GUST");
                printf("    3-SCORCH FLAME||\n");
                printf("\t|    4-BLIZZARD   ");
                SetColor(12);
                printf(">>");
                SetColor(10);
                printf(" 5-EARTH SMASH");
                SetColor(15);
                printf("                |\n");
            }

            limitFPS(150);
            printf("\033[14A");
            while(!moved)
            {
                 if(GetAsyncKeyState (VK_UP) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCombatCursor, 0, &thread);
#endif
                        if(skisel == 3) skisel = 0;
                        if(skisel == 4) skisel = 1;
                    }

                if(GetAsyncKeyState (VK_DOWN) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCombatCursor, 0, &thread);
#endif
                        if(skisel == 0 && findSkill(playerChar.magtree, "BLIZZARD", false) == true) skisel = 3;
                        else if(skisel == 1 && findSkill(playerChar.magtree, "EARTH SMASH", false) == true) skisel = 4;
                    }

                if(GetAsyncKeyState (VK_LEFT) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCombatCursor, 0, &thread);
#endif
                        if(skisel == 1) skisel = 0;
                        else if(skisel == 2) skisel = 1;
                        else if(skisel == 3) skisel = 2;
                        else if(skisel == 4) skisel = 3;
                    }

                if(GetAsyncKeyState (VK_RIGHT) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(moveCombatCursor, 0, &thread);
#endif
                        if(skisel == 0 && findSkill(playerChar.magtree, "WIND GUST", false) == true) skisel = 1;
                        else if(skisel == 1 && findSkill(playerChar.magtree, "SCORCH FLAME", false) == true) skisel = 2;
                        else if(skisel == 2 && findSkill(playerChar.magtree, "BLIZZARD", false) == true) skisel = 3;
                        else if(skisel == 3 && findSkill(playerChar.magtree, "EARTH SMASH", false) == true) skisel = 4;
                    }

                if(GetAsyncKeyState (VK_LCONTROL) != 0)
                    {
                        moved = true;
#ifdef __linux__

#elif _WIN32
                        _beginthread(selectCombatAction, 0, &thread);
#endif
                        if(skisel == 0)
                            {
                                magicused = playerUseAqua();
                                return magicused;
                            }

                        if(skisel == 1)
                            {
                                magicused = playerUseWind();
                                return magicused;
                            }

                        if(skisel == 2)
                            {
                                magicused = playerUseFlame();
                                return magicused;
                            }

                        if(skisel == 3)
                            {
                                magicused = playerUseBlizzard();
                                return magicused;
                            }

                        if(skisel == 4)
                            {
                                magicused = playerUseEarth();
                                return magicused;
                            }
                        limitFPS(250);
                        break;
                    }

                if(GetAsyncKeyState (VK_LSHIFT) != 0)
                    {
#ifdef __linux__

#elif _WIN32
                        _beginthread(returnFromSkills, 0, &thread);
#endif
                        moved = true;
                        printf("\033[11B");
                        printf("                                                                                    \n");
                        printf("                                                                                    \n");
                        printf("                                                                                    \n");
                        printf("                                                                                    \n");
                        printf("\033[15A");
                        printf("\033[92D");
                        return false;
                    }

            }
        }

}

void playerAttackEnemy()
{
    int damage = (playerChar.atk - Enemy.def);

    if(damage > 0)
        {
            Enemy.current_HP -= damage;
            printf("\033[11B");
            printf("\n\t%s attacks... and causes %d damage to the enemy.", playerChar.name, damage);
            printf("\033[14A");
            limitFPS(700);
        }
}

bool playerUseAqua()
{
    int damage = (playerChar.atk - Enemy.def);
    damage *= (playerChar.inte/100);
    damage *= 1.1;

    if(strcmp(Enemy.weakness, "AQUA STORM") == 0) damage *= 2;
    else if (strcmp(Enemy.resists, "AQUA STORM") == 0) damage *= 0.7;

    if(damage > 0)
        {
            Enemy.current_HP -= damage;
            printf("\033[14B");
            printf("\n\t%s used aqua storm... and causes %d damage to the enemy.", playerChar.name, damage);
            limitFPS(700);
            printf("\033[5A");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("\033[15A");
            printf("\033[92D");
        }

    playerChar.current_MP -=30;

    return true;
}

bool playerUseWind()
{
    int damage = (playerChar.atk - Enemy.def);
    damage *= (playerChar.inte/100);
    damage *= 1.15;

    if(strcmp(Enemy.weakness, "WIND GUST") == 0) damage *= 2;
    else if (strcmp(Enemy.resists, "WIND GUST") == 0) damage *= 0.8;

    if(damage > 0)
        {
            Enemy.current_HP -= damage;
            printf("\033[14B");
            printf("\n\t%s used wind gust... and causes %d damage to the enemy.", playerChar.name, damage);
            limitFPS(700);
            printf("\033[5A");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("\033[15A");
            printf("\033[92D");
        }

    playerChar.current_MP -=45;

    return true;
}

bool playerUseFlame()
{
    int damage = (playerChar.atk - Enemy.def);
    damage *= (playerChar.inte/100);
    damage *= 1.3;

    if(strcmp(Enemy.weakness, "SCORCH FLAME") == 0) damage *= 2;
    else if (strcmp(Enemy.resists, "SCORCH FLAME") == 0) damage *= 0.9;

    if(damage > 0)
        {
            Enemy.current_HP -= damage;
            printf("\033[14B");
            printf("\n\t%s used scorch flame... and causes %d damage to the enemy.", playerChar.name, damage);
            limitFPS(700);
            printf("\033[5A");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("\033[15A");
            printf("\033[92D");
        }

    playerChar.current_MP -=70;

    return true;
}

bool playerUseBlizzard()
{
    int damage = (playerChar.atk - Enemy.def);
    damage *= (playerChar.inte/100);
    damage *= 1.45;

    if(strcmp(Enemy.weakness, "BLIZZARD") == 0) damage *= 2;
    else if (strcmp(Enemy.resists, "BLIZZARD") == 0) damage *= 0.8;

    if(damage > 0)
        {
            Enemy.current_HP -= damage;
            printf("\033[14B");
            printf("\n\t%s used blizzard... and causes %d damage to the enemy.", playerChar.name, damage);
            limitFPS(700);
            printf("\033[5A");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("\033[15A");
            printf("\033[92D");
        }

    playerChar.current_MP -=110;

    return true;
}

bool playerUseEarth()
{
    int damage = (playerChar.atk - Enemy.def);
    damage *= (playerChar.inte/100);
    damage *= 1.6;

    if(strcmp(Enemy.weakness, "EARTH SMASH") == 0) damage *= 2;
    else if (strcmp(Enemy.resists, "EARTH SMASH") == 0) damage *= 0.9;

    if(damage > 0)
        {
            Enemy.current_HP -= damage;
            printf("\033[14B");
            printf("\n\t%s used earth smash... and causes %d damage to the enemy.", playerChar.name, damage);
            limitFPS(700);
            printf("\033[5A");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("                                                                                    \n");
            printf("\033[15A");
            printf("\033[92D");
        }

    playerChar.current_MP -=150;

    return true;
}

void enemyAttackPlayer()
{
    int damage = (Enemy.atk - playerChar.def);

    if(damage > 0)
        {
            playerChar.current_HP -= damage;
            printf("\033[16B");
            printf("\n\tThe enemy attacks... it caused %d damage to %s.", damage, playerChar.name);
            limitFPS(700);
        }
}

void enemyDozesOff()
{
            printf("\033[16B");
            printf("\n\tThe enemy dozed off...");
            limitFPS(700);
}

void enemyAction()
{
    short int randaction = rand() % 100;
    if(randaction <= 75)
        enemyAttackPlayer();

    else enemyDozesOff();
}
