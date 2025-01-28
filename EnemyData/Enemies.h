#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Enemy
{
    char name[20];
    int gold_given;
    int max_HP;
    int current_HP;
    int atk;
    int def;
    int inte;
    int XP_given;
    char weakness[20];
    char resists[20];
}Enemy;

void generateEnemy(char* enemy);

void generateEnemy(char* enemy)
{
    if(strcmp(enemy, "YELLOW BLOB") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 300;
            Enemy.current_HP = 300;
            Enemy.atk = 160;
            Enemy.def = 60;
            Enemy.inte = 110;
            Enemy.XP_given = 125; // Base 30
            Enemy.gold_given = 12;
            strcpy(Enemy.weakness,"BLIZZARD");
            strcpy(Enemy.resists, "");
        }

    if(strcmp(enemy, "RED BLOB") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 450;
            Enemy.current_HP = 450;
            Enemy.atk = 185;
            Enemy.def = 70;
            Enemy.inte = 120;
            Enemy.XP_given = 45;
            Enemy.gold_given = 20;
            strcpy(Enemy.weakness, "AQUA STORM");
            strcpy(Enemy.resists, "EARTH SMASH");
        }

    if(strcmp(enemy, "CURSED ARMOR") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 870;
            Enemy.current_HP = 870;
            Enemy.atk = 210;
            Enemy.def = 95;
            Enemy.inte = 70;
            Enemy.XP_given = 640;
            Enemy.gold_given = 260;
            strcpy(Enemy.weakness, "WIND GUST");
            strcpy(Enemy.resists, "EARTH SMASH");
        }

    if(strcmp(enemy, "C-GUY") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 550;
            Enemy.current_HP = 550;
            Enemy.atk = 215;
            Enemy.def = 100;
            Enemy.inte = 90;
            Enemy.XP_given = 110;
            Enemy.gold_given = 40;
            strcpy(Enemy.weakness, "BLIZZARD");
            strcpy(Enemy.resists, "SCORCH FLAME");
        }

    if(strcmp(enemy, "BIG CHICKEN") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 660;
            Enemy.current_HP = 660;
            Enemy.atk = 235;
            Enemy.def = 100;
            Enemy.inte = 50;
            Enemy.XP_given = 150;
            Enemy.gold_given = 60;
            strcpy(Enemy.weakness, "SCORCH FLAME");
            strcpy(Enemy.resists, "WIND GUST");
        }

    if(strcmp(enemy, "CYCLOPS") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 1300;
            Enemy.current_HP = 1300;
            Enemy.atk = 295;
            Enemy.def = 125;
            Enemy.inte = 90;
            Enemy.XP_given = 1280;
            Enemy.gold_given = 400;
            strcpy(Enemy.weakness, "EARTH SMASH");
            strcpy(Enemy.resists, "BLIZZARD");
        }

    if(strcmp(enemy, "ALIEN-V") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 890;
            Enemy.current_HP = 890;
            Enemy.atk = 280;
            Enemy.def = 130;
            Enemy.inte = 120;
            Enemy.XP_given = 660;
            Enemy.gold_given = 120;
            strcpy(Enemy.weakness, "WIND GUST");
            strcpy(Enemy.resists, "EARTH SMASH");
        }

    if(strcmp(enemy, "BIG-O") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 930;
            Enemy.current_HP = 930;
            Enemy.atk = 255;
            Enemy.def = 135;
            Enemy.inte = 120;
            Enemy.XP_given = 700;
            Enemy.gold_given = 125;
            strcpy(Enemy.weakness, "WIND GUST");
            strcpy(Enemy.resists, "EARTH SMASH");
        }

    if(strcmp(enemy, "NONAME") == 0)
        {
            strcpy(Enemy.name, enemy);
            Enemy.max_HP = 1800;
            Enemy.current_HP = 1800;
            Enemy.atk = 295;
            Enemy.def = 150;
            Enemy.inte = 130;
            Enemy.XP_given = 99999;
            Enemy.gold_given = 999;
            strcpy(Enemy.weakness, "WIND GUST");
            strcpy(Enemy.resists, "EARTH SMASH");
        }
}
