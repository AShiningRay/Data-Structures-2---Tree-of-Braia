#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "EnemySprites.h"

#define MAX_ENEMY_NAME_SIZE 24

// Enemy positioning on screen, for when there are more than one
#define CENTERPOS 0
#define LEFTPOS 1
#define RIGHTPOS 2

char enemiesInEncounter = 1;

struct Enemy
{
    char name[MAX_ENEMY_NAME_SIZE];
    int gold_given;
    int max_HP;
    int current_HP;
    int atk;
    int def;
    int inte;
    int XP_given;
    char weakness[20];
    char resists[20];
}Enemy[3];

// Bosses have fixed levels, so whenever you don't see enemyLevel multipliers, it means the enemy is a boss
void generateEnemy(char enemyIndex, char* enemy, int enemyLevel)
{

    if(strcmp(enemy, "YELLOW BLOB") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 200 + 14*enemyLevel;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 140 + 3*enemyLevel;
        Enemy[enemyIndex].def = 40 + 2*enemyLevel;
        Enemy[enemyIndex].inte = 10 + 2*enemyLevel;
        Enemy[enemyIndex].XP_given = 45 + 10*enemyLevel;
        Enemy[enemyIndex].gold_given = 6 + 2*enemyLevel;
        strcpy(Enemy[enemyIndex].weakness,"BLIZZARD");
        strcpy(Enemy[enemyIndex].resists, "EARTH SMASH");
    }

    if(strcmp(enemy, "RED BLOB") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 250 + 18*enemyLevel;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 155 + 5*enemyLevel;
        Enemy[enemyIndex].def = 45 + 4*enemyLevel;
        Enemy[enemyIndex].inte = 10 + 2*enemyLevel;
        Enemy[enemyIndex].XP_given = 65 + 15*enemyLevel;
        Enemy[enemyIndex].gold_given = 8 + 3*enemyLevel;
        strcpy(Enemy[enemyIndex].weakness, "AQUA STORM");
        strcpy(Enemy[enemyIndex].resists, "EARTH SMASH");
    }
    // TODO: Rework everything from here on, as those current enemies just don't match the new system
    if(strcmp(enemy, "CURSED ARMOR") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 870;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 210;
        Enemy[enemyIndex].def = 95;
        Enemy[enemyIndex].inte = 70;
        Enemy[enemyIndex].XP_given = 640;
        Enemy[enemyIndex].gold_given = 260;
        strcpy(Enemy[enemyIndex].weakness, "WIND GUST");
        strcpy(Enemy[enemyIndex].resists, "EARTH SMASH");
    }

    if(strcmp(enemy, "C-GUY") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 550;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 215;
        Enemy[enemyIndex].def = 100;
        Enemy[enemyIndex].inte = 90;
        Enemy[enemyIndex].XP_given = 110;
        Enemy[enemyIndex].gold_given = 40;
        strcpy(Enemy[enemyIndex].weakness, "BLIZZARD");
        strcpy(Enemy[enemyIndex].resists, "SCORCH FLAME");
    }

    if(strcmp(enemy, "BIG CHICKEN") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 660;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 235;
        Enemy[enemyIndex].def = 100;
        Enemy[enemyIndex].inte = 50;
        Enemy[enemyIndex].XP_given = 150;
        Enemy[enemyIndex].gold_given = 60;
        strcpy(Enemy[enemyIndex].weakness, "SCORCH FLAME");
        strcpy(Enemy[enemyIndex].resists, "WIND GUST");
    }

    if(strcmp(enemy, "CYCLOPS") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 1300;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 295;
        Enemy[enemyIndex].def = 125;
        Enemy[enemyIndex].inte = 90;
        Enemy[enemyIndex].XP_given = 1280;
        Enemy[enemyIndex].gold_given = 400;
        strcpy(Enemy[enemyIndex].weakness, "EARTH SMASH");
        strcpy(Enemy[enemyIndex].resists, "BLIZZARD");
    }

    if(strcmp(enemy, "ALIEN-V") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 890;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 280;
        Enemy[enemyIndex].def = 130;
        Enemy[enemyIndex].inte = 120;
        Enemy[enemyIndex].XP_given = 660;
        Enemy[enemyIndex].gold_given = 120;
        strcpy(Enemy[enemyIndex].weakness, "WIND GUST");
        strcpy(Enemy[enemyIndex].resists, "EARTH SMASH");
    }

    if(strcmp(enemy, "BIG-O") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 930;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 255;
        Enemy[enemyIndex].def = 135;
        Enemy[enemyIndex].inte = 120;
        Enemy[enemyIndex].XP_given = 700;
        Enemy[enemyIndex].gold_given = 125;
        strcpy(Enemy[enemyIndex].weakness, "WIND GUST");
        strcpy(Enemy[enemyIndex].resists, "EARTH SMASH");
    }

    if(strcmp(enemy, "NONAME") == 0)
    {
        snprintf(Enemy[enemyIndex].name, MAX_ENEMY_NAME_SIZE, "%s Lv.%d", enemy, enemyLevel);
        Enemy[enemyIndex].max_HP = 1800;
        Enemy[enemyIndex].current_HP = Enemy[enemyIndex].max_HP;
        Enemy[enemyIndex].atk = 295;
        Enemy[enemyIndex].def = 150;
        Enemy[enemyIndex].inte = 130;
        Enemy[enemyIndex].XP_given = 99999;
        Enemy[enemyIndex].gold_given = 999;
        strcpy(Enemy[enemyIndex].weakness, "WIND GUST");
        strcpy(Enemy[enemyIndex].resists, "EARTH SMASH");
    }
}
