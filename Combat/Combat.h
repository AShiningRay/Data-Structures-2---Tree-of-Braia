#include "../EnemyData/Enemies.h"
#include "../Maps/Combat_BGs.h"

#define MAGIC_SPELLS_PER_LINE 4
#define CLASS_SKILLS_PER_LINE 4
#define COMBAT_TEXT_MAXLEN 79

void enemyEncounter(int baseLevel, int levelCap);
void checkPlayerXP();
void characterLeveledUp(char charIndex, int leftOver_XP);

void renderCombatStartAnim();
void applyColorPalette(char check);

void renderArea1BG();
void renderEnemyCharacters(int charIndex[3], bool isBoss[3]);

void renderPlayerSkillMenu();
int renderPlayerCombatEnemyMenu();
int renderPlayerMagicSpellMenu();
void renderMainPartyStats(bool showCombatActions, char *combatText);
void renderPlayerSkillMenu();
void renderEnemyCombatStat();

int selectEnemy();
int playerAttackEnemy(char enemyIndex);
bool calculateCriticalHitChance(int luck);
bool playerUseSpell(char *spell, char enemyIndex);

void enemyAttackPlayer(char enemyIndex, char charIndex);
void enemyDozesOff(char enemyIndex);

void enemyAction();

short int thread;

void enemyEncounter(int baseLevel, int levelCap)
{
    stopBGM("Area1");
    stopBGM("Area2");
    stopBGM("Area3");
    stopBGM("HubWorld");

    playBGM("EnemyFight1");

    int enemiesToRender[3] = {-1, -1, -1}; // Sprite table indices
    bool enemyIsBoss[3] = {false, false, false}; // If the enemy is a boss UNUSED YET
    int spawnedEnemies = rand();
    
    if(spawnedEnemies % 3 == 0)      { enemiesInEncounter = 3; }
    else if(spawnedEnemies % 2 == 0) { enemiesInEncounter = 2; }
    else                             { enemiesInEncounter = 1; }

    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        int enemyLevel = baseLevel + 1 + (rand() % (levelCap-1)); // Enemy Level always goes from "baseLevel+1" to "levelCap"

        if(enemyLevel > 0 && enemyLevel < 5)
        {
            generateEnemy(enemyIndex, "YELLOW BLOB", enemyLevel);
            enemiesToRender[enemyIndex] = 0;
        }

        else if(enemyLevel >= 5 && enemyLevel < 10)
        {
            generateEnemy(enemyIndex, "RED BLOB", enemyLevel);
            enemiesToRender[enemyIndex] = 1;
        }

        else if(enemyLevel > 10 && enemyLevel <= 15)
        {
            generateEnemy(enemyIndex, "C-GUY", enemyLevel);
            enemiesToRender[enemyIndex] = 2;
        }

        else if(enemyLevel > 15 && enemyLevel < 20)
        {
            generateEnemy(enemyIndex, "BIG CHICKEN", enemyLevel);
            enemiesToRender[enemyIndex] = 3;
        }

        else if(enemyLevel > 20 && enemyLevel <= 25)
        {
            generateEnemy(enemyIndex, "ALIEN-V", enemyLevel);
            enemiesToRender[enemyIndex] = 4;
        }

        else if(enemyLevel > 25 && enemyLevel < 30)
        {
            generateEnemy(enemyIndex, "BIG-O", enemyLevel);
            enemiesToRender[enemyIndex] = 5;
        }
    }
    renderEnemyCharacters(enemiesToRender, enemyIsBoss);

    checkPlayerXP();
    stopBGM("EnemyFight1");
}

void fightBoss(int enemyLevel)
{
    stopBGM("Area1");
    stopBGM("Area2");
    stopBGM("Area3");
    stopBGM("HubWorld");



    playBGM("BossFight1");

    int enemiesToRender[3] = {-1, 0, 0};
    bool enemyIsBoss[3] = {true, false, false};

    if(enemyLevel == 10)
    {
        generateEnemy(0, "CURSED ARMOR", enemyLevel);
        enemiesToRender[0] = 0;
    }

    else if(enemyLevel == 20)
    {
        generateEnemy(0, "CYCLOPS", enemyLevel);
        enemiesToRender[0] = 1;
    }

    else if (enemyLevel == 30)
    {
        generateEnemy(0, "NONAME", enemyLevel);
        enemiesToRender[0] = 2;
    }

    renderEnemyCharacters(enemiesToRender, enemyIsBoss);
    checkPlayerXP();
    stopBGM("BossFight1");
}

void renderEnemyCharacters(int charIndex[3], bool isBoss[3]) 
{
    int attackedEnemy = 0;
    bool allEnemiesKilled = false;
    do
    {
#ifdef __linux__
        system("clear");
#elif _WIN32
        system("cls");
#endif
        renderEnemyCombatStat();

        renderArea1BG();
        int enemyIndex = 0;
        for(enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
        { 
            if(isBoss[enemyIndex]) { charIndex[enemyIndex] += NUM_ENEMIES; }
        }

        char enemyHeight = 0;
        for(short int y = 0; y < BG_YSIZE-FIGHTSCREEN_Y_PADDING; y++)
        {
            // On the enemy sprite data, bosses are addressed after all normal enemies
            int charToRender = charIndex[0];

            int maxX = (enemiesInEncounter*ENEMY_X_SEPARATOR);
            int enemyXArea = maxX + FIGHTSCREEN_X_PADDING - 1;
            
            for(int x = 0; x < enemyXArea; x++) 
            {
                if(x-FIGHTSCREEN_X_PADDING >= 0)
                {
                    enemyIndex = floor((x-FIGHTSCREEN_X_PADDING)/ENEMY_X_SEPARATOR);
                    charToRender = charIndex[enemyIndex];
                    char pixelToDraw = enemySprites[charToRender][y][x-FIGHTSCREEN_X_PADDING-(ENEMY_X_SEPARATOR*enemyIndex)];
                    if(pixelToDraw != ' ' && Enemy[enemyIndex].current_HP > 0) 
                    {
                        applyColorPalette(pixelToDraw);
                        putchar(pixelToDraw); 
                    }
                    else // if the pixel is out of bounds, OR it's empty/transparent
                    {
                        if(enemyIndex > 0) // We might have to draw the previous enemy data instead, if there is one
                        {
                            char BGPixelToDraw = enemySprites[enemyIndex-1][y][x-FIGHTSCREEN_X_PADDING-(ENEMY_X_SEPARATOR*(enemyIndex))];
                            if(BGPixelToDraw != ' ' && Enemy[enemyIndex-1].current_HP > 0) 
                            {
                                applyColorPalette(BGPixelToDraw);
                                putchar(BGPixelToDraw); 
                            }
                            else // IF the previous enemy also has a transparent pixel here, draw the BG instead
                            {
                                applyColorPalette(Area1_BG[y+FIGHTSCREEN_Y_PADDING][x-FIGHTSCREEN_X_PADDING]);
                                putchar(Area1_BG[y+FIGHTSCREEN_Y_PADDING][x-FIGHTSCREEN_X_PADDING]);
                            }
                        }
                        else // Or the background
                        {
                            applyColorPalette(Area1_BG[y+FIGHTSCREEN_Y_PADDING][x-FIGHTSCREEN_X_PADDING]);
                            putchar(Area1_BG[y+FIGHTSCREEN_Y_PADDING][x-FIGHTSCREEN_X_PADDING]);
                        }
                        
                    }
                }
                else
                {
                    applyColorPalette(Area1_BG[y+FIGHTSCREEN_Y_PADDING][x]);
                    putchar(Area1_BG[y+FIGHTSCREEN_Y_PADDING][x]);
                }
                
                textcolor(WHITE);
                textbackground(BLACK);
            }
            putchar('\n');
            enemyHeight += 1;
        }
        
        for(int y = 0; y < BG_YSIZE - FIGHTSCREEN_Y_PADDING - enemySpriteRows[charIndex[enemiesInEncounter-1]]; y++) { putchar('\n'); }
        SetColor(15);
        attackedEnemy = renderPlayerCombatEnemyMenu();

        if(Enemy[attackedEnemy].current_HP <= 0)
        {
            char combatText[COMBAT_TEXT_MAXLEN];
            if(isBoss[attackedEnemy]) { playSFX("BossDefeated");}
            else { playSFX("EnemyDefeated"); }
            
            snprintf(combatText, COMBAT_TEXT_MAXLEN, " '%s' was defeated! Party gained %d XP points and +%d gold!", Enemy[attackedEnemy].name, Enemy[attackedEnemy].XP_given, Enemy[attackedEnemy].gold_given);
            renderMainPartyStats(true, combatText);
            printf("\x1B[10A");
            character[0].current_XP += Enemy[attackedEnemy].XP_given;
            character[0].gold += Enemy[attackedEnemy].gold_given;
            limitFPS(1000);
        }
        else if(character[0].current_HP <= 0)
        {
            char combatText[COMBAT_TEXT_MAXLEN];
            snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s died...", character[0].name);
            renderMainPartyStats(true, combatText);
            printf("\x1B[10A");
            break;
        }

        enemyAction();

        allEnemiesKilled = true;
        for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
        {
            if(Enemy[enemyIndex].current_HP > 0) { allEnemiesKilled = false; }
        }

        // Clear all player actions from the UI, as this turn is over
        for(int i = 0; i < partySize; i++) {strcpy(character[i].action,""); }
    } 
    while (!allEnemiesKilled && character[0].current_HP > 0);

    limitFPS(1000);
}

void checkPlayerXP()
{
    bool leveledUp = false;
    int leftOver_XP = 0;

    if(character[0].current_XP >= character[0].next_XP)
    {
        leveledUp = true;
        leftOver_XP = (character[0].current_XP - character[0].next_XP);
    }

    if(leveledUp == true && character[0].Level < 10)
    {
        characterLeveledUp(0, leftOver_XP);
    }
    else if(character[0].Level == 10) character[0].current_XP = (character[0].next_XP) - 1;
}

void characterLeveledUp(char charIndex, int leftOver_XP) 
{
    char combatText[COMBAT_TEXT_MAXLEN];
    playSFX("LevelUp");
    character[charIndex].Level += 1;
    character[charIndex].max_HP += 250;
    character[charIndex].current_HP = character[charIndex].max_HP;
    character[charIndex].max_MP += 80;
    character[charIndex].current_MP = character[charIndex].max_MP;
    character[charIndex].atk += 16;
    character[charIndex].def += 12;
    character[charIndex].inte += 10;
    character[charIndex].luck += 3;
    character[charIndex].next_XP *= 2;
    character[charIndex].current_XP = 0;
    character[charIndex].current_XP += leftOver_XP;

    snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s Leveled UP to Level %d!!! ", character[charIndex].name, character[charIndex].Level);

    if(character[charIndex].Level == 2)
    {
        learnSkill(character[charIndex].magtree, "AQUA STORM");
        strcat(combatText, " LEARNED AQUA STORM!");
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("AQUA STORM");
    }

    else if(character[charIndex].Level == 4)
    {
        learnSkill(character[charIndex].phystree, "STR BOOST");
        strcat(combatText, " LEARNED STR BOOST!");
        character[charIndex].atk *= 1.20;
        character[charIndex].learnedSkills += 1;
    }

    else if(character[charIndex].Level == 3)
    {
        learnSkill(character[charIndex].magtree, "WIND GUST");
        strcat(combatText, " LEARNED WIND GUST!");
        character[charIndex].luck *= 1.05;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("WIND GUST");
    }

    else if(character[charIndex].Level == 6)
    {
        learnSkill(character[charIndex].magtree, "SCORCH FLAME");
        strcat(combatText, " LEARNED SCORCH FLAME!");
        character[charIndex].inte *= 1.05;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("SCORCH FLAME");
    }

    else if(character[charIndex].Level == 7)
    {
        learnSkill(character[charIndex].phystree, "DEF BOOST");
        strcat(combatText, " LEARNED DEF BOOST!");
        character[charIndex].def *= 1.20;
        character[charIndex].learnedSkills += 1;
    }

    else if(character[charIndex].Level == 8)
    {
        learnSkill(character[charIndex].magtree, "BLIZZARD");
        strcat(combatText, " LEARNED BLIZZARD!");
        character[charIndex].atk *= 1.03;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("BLIZZARD");
    }

    else if(character[charIndex].Level == 9)
    {
        learnSkill(character[charIndex].magtree, "EARTH SMASH");
        strcat(combatText, " LEARNED EARTH SMASH!");
        character[charIndex].def *= 1.03;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("EARTH SMASH");
    }

    else if(character[charIndex].Level == 10)
    {
        learnSkill(character[charIndex].phystree, "INT BOOST");
        strcat(combatText, " LEARNED INT BOOST!");
        character[charIndex].inte *= 1.25;
        character[charIndex].learnedSkills += 1;
    }

    renderMainPartyStats(true, combatText);
    printf("\x1B[10A");
    limitFPS(1500);
}

void applyColorPalette(char check)
{

    // Same color Background and text
    if(check == '&')
    {
        textcolor(LIGHTGREEN);
        textbackground(LIGHTGREEN);
    }
    else if(check == '@')
    {
        textcolor(BROWN);
        textbackground(BROWN);
    }
    else if(check == '#')
    {
        textcolor(GREEN);
        textbackground(GREEN);
    }
    else if(check == '.')
    {
        textbackground(BLACK);
        textcolor(BLACK);
    }
    else if(check == 'W')
    {
        textcolor(WHITE);
        textbackground(WHITE);
    }
    else if(check == '0')
    {
        textcolor(DARKGRAY);
        textbackground(DARKGRAY);
    }
    else if(check == 'M')
    {
        textcolor(MAGENTA);
        textbackground(MAGENTA);
    }
    else if(check == 'P')
    {
        textcolor(LIGHTMAGENTA);
        textbackground(LIGHTMAGENTA);
    }
    else if(check == 'L')
    {
        textcolor(LIGHTRED);
        textbackground(LIGHTRED);
    }
    else if(check == 'R')
    {
        textcolor(RED);
        textbackground(RED);
    }
    else if(check == 'B')
    {
        textcolor(BLUE);
        textbackground(BLUE);
    }
    else if(check == 'K')
    {
        textcolor(YELLOW);
        textbackground(YELLOW);
    }
    else if (check == 'V')
    {
        textcolor(LIGHTBLUE);
        textbackground(LIGHTBLUE);
    }
    else if (check == '$')
    {
        textcolor(LIGHTCYAN);
        textbackground(LIGHTCYAN);
    }
    if(check == 'C')
    {
        textcolor(CYAN);
        textbackground(CYAN);
    }
    if(check == '+')
    {
        textcolor(LIGHTGRAY);
        textbackground(LIGHTGRAY);
    }

    // Different color background and text
    else if(check == '|')
    {
        textcolor(RED);
        textbackground(BLACK);
    }
    else if (check == '`')
    {
        textcolor(BLACK);
        textbackground(BROWN);
    }
    else if (check == ':')
    {
        textcolor(BROWN);
        textbackground(LIGHTGREEN);
    }
    else if (check == ';')
    {
        textcolor(LIGHTGREEN);
        textbackground(BROWN);
    }
    
}


// TODO: Also make this commonize all area BGs later on
void renderArea1BG() 
{
    for(short int y = 0; y <37; y++)
        {
            int xmax = strlen(Area1_BG[y]);

            for(int x = 0; x < xmax; x++)
                {
                    applyColorPalette(Area1_BG[y][x]);

                    putchar(Area1_BG[y][x]);
                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                putchar('\n');
        }
    printf("\x1B[%dA", BG_YSIZE-FIGHTSCREEN_Y_PADDING);
}

void renderEnemyCombatStat()
{
    short int lifepercent; // enemy life bar percentage calculus.
    SetColor(15);
    printf("\x1B[1m");
    printf("\t\t\t┌────────────────────────────────────────────────────────────────────────────────┐\n");

    // Enemy Names
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        if(enemyIndex == 0) { printf("\t\t\t│"); }
        // If there's only one enemy, show its name and lifebar on the center
        if(enemiesInEncounter == 1) 
        { 
            for(char j = 0; j < 26; j++) { putchar(' '); }
            printf("│");
        } 

        SetColor(14);
        for(char j = 0; j < (26 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
        printf("%s", Enemy[enemyIndex].name);

        for(char j = 0; j < (26 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
        if(strlen(Enemy[enemyIndex].name) % 2 == 1) { putchar(' '); } // Correction for when names aren't even in length
        SetColor(15);
        printf("│");

        // If we have two enemies, the center area of the life bars has to be empty (there's only a left and right enemy)
        // Additionally, if there's only one enemy, its stats will be shown on the center, so pad the right area as well.
        if(enemiesInEncounter % 2 == 0 && enemyIndex == 0 || enemiesInEncounter == 1) 
        { 
            for(char j = 0; j < 26; j++) { putchar(' '); } 
            printf("│");
        }
    }
    printf("\n");

    // Enemy HP Bars
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        if(enemyIndex == 0) { printf("\t\t\t│"); }

        if(enemiesInEncounter == 1) 
        { 
            for(char j = 0; j < 26; j++) { putchar(' '); }
            printf("│");
        } 
        printf(" HP:(");
        lifepercent = (int) (((float)Enemy[enemyIndex].current_HP / (float)Enemy[enemyIndex].max_HP) * 18);
        if(lifepercent < 0) { lifepercent = 0; } 

        printf("\x1B[0m");
        textbackground(RED);
        textcolor(RED);
        for(unsigned short int i = 0; i < lifepercent; i++) { printf("+"); }
        printf("\x1B[1m");
        textbackground(BLACK);
        textcolor(WHITE);

        for(short int i = 20 - lifepercent - 2; i > 0; i--) { printf(" "); }

        printf(")  │");
        if(enemiesInEncounter % 2 == 0 && enemyIndex == 0 || enemiesInEncounter == 1) 
        { 
            for(char j = 0; j < 26; j++) { putchar(' '); } 
            printf("│");
        }
    }
    printf("\n");

    
    printf("\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\x1B[0m");
}

int selectEnemy() 
{
    int selIndex = 0;

    bool enemyIsSelectable[3] = { false, false, false };

    // Start by having all generated enemies be selectable. If any have their HP below zero, they'll be ruled out below
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) { enemyIsSelectable[enemyIndex] = true; }

    while(true) 
    {
        renderMainPartyStats(true, "");
        SetColor(15);
        printf("\x1B[1m");
        printf("\t\t\t┌────────────────────────────────SELECT YOUR FOE─────────────────────────────────┐\n");

        // Enemy Names
        for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
        {            
            if(enemyIndex == 0) { printf("\t\t\t│"); }
            // If there's only one enemy, show its name and lifebar on the center
            if(enemiesInEncounter == 1) 
            { 
                for(char j = 0; j < 26; j++) { putchar(' '); }
                printf("│");
            }

            if(Enemy[enemyIndex].current_HP < 0) 
            {
                enemyIsSelectable[enemyIndex] = false;
                if(enemyIsSelectable[selIndex] == false) { selIndex++; }
            }
            
            if (selIndex == enemyIndex) 
            { 
                SetColor(14);
                printf(" ┼─ "); 
            }
            else { printf("    "); }
            for(char j = 0; j < (22 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
            
            if(Enemy[enemyIndex].current_HP < 0) { SetColor(8); }
            printf("%s", Enemy[enemyIndex].name); 

            for(char j = 0; j < (22 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
            if(strlen(Enemy[enemyIndex].name) % 2 == 1) { putchar(' '); } // Correction for when names aren't even in length
            SetColor(15);
            printf("│");

            if(enemiesInEncounter % 2 == 0 && enemyIndex == 0 || enemiesInEncounter == 1) 
            { 
                for(char j = 0; j < 26; j++) { putchar(' '); } 
                printf("│");
            }
        }
        printf("\n");
        printf("\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n\n");
        printf("\x1B[0m");
        printf("\x1B[14A");
        limitFPS(150);

        while(true)
        {
            if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                selIndex--;
                if(selIndex < 0) { selIndex = enemiesInEncounter-1; }
                break;
            }

            if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                selIndex++;
                if(selIndex >= enemiesInEncounter) { selIndex = 0; }
                break;
            }

            if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                playSFX("CombatCursorSelect");
                limitFPS(150);
                return selIndex;
            }

            if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                playSFX("ReturnFromMenu");
                return -1;
            }
            limitFPS(0);
        }
    }
}

int renderPlayerCombatEnemyMenu()
{
    bool atksel = true;
    bool spellsel = false;
    bool actsel = false; // TODO: Unused, as AP skills aren't implemented yet
    bool undosel = false; // TODO: Unused, as there has to be more than one character in the party
    char enemyAttacked = -1;
    int curcharacter = 0; // Only one character for now

    while(true)
    {
        renderMainPartyStats(true, "");

        SetColor(15);
        printf("\x1B[1m");
        printf("\t\t\t┌────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("\t\t\t┌──────────────────────────────SELECT YOUR COMMAND───────────────────────────────┐\n");
        printf("\t\t\t│ ");
        if(atksel) { SetColor(10); }
        printf("%s", (atksel ? "┼─" : "  "));
        printf(" BASIC ATTACK    ");
        SetColor(15);
        printf("│ ");
        if(spellsel) { SetColor(9); }
        printf("%s", (spellsel ? "┼─" : "  "));
        printf(" MAGIC SPELL    ");
        SetColor(15);
        printf("│ ");
        if(actsel) { SetColor(14); }
        printf("%s", (actsel ? "┼─" : "  "));
        printf(" CLASS SKILL    ");
        SetColor(15);
        printf("│ ");
        if(undosel) { SetColor(11); }
        else if(curcharacter == 0) { SetColor(8); }
        printf("%s", (undosel ? "┼─" : "  "));
        printf(" UNDO LAST      ");
        SetColor(15);
        printf("│");
        printf("\n\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");
        printf("\x1B[0m");
        printf("\x1B[14A");
        while(true)
        {
            if(GetAsyncKeyState (VK_LEFT) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                if(spellsel)
                {
                    spellsel = false;
                    atksel = true;
                }
                else if(actsel)
                {
                    actsel = false;
                    spellsel = true;
                }
                break;
            }

            if(GetAsyncKeyState (VK_RIGHT) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                if(atksel)
                {
                    atksel = false;
                    spellsel = true;
                }
                else if(spellsel)
                {
                    spellsel = false;
                    actsel = true;
                }
                break;
            }

            if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                playSFX("CombatCursorSelect");
                if(atksel)
                {
                    enemyAttacked = selectEnemy();
                    if(enemyAttacked != -1) 
                    {
                        strcpy(character[0].action,"ATK");
                        playerAttackEnemy(enemyAttacked);
                        return enemyAttacked;
                    }
                    
                }
                else
                {
                    enemyAttacked = renderPlayerMagicSpellMenu();
                    if(enemyAttacked != -1) { return enemyAttacked; }
                }
                limitFPS(250);
                break;
            }
            limitFPS(0);
        }
    }
    return -1; // This should never happen
}

// Party UI in combat
void renderMainPartyStats(bool showCombatActions, char *combatText)
{
    char charAt = 0;
    SetColor(15);
    printf("\x1B[1m");

    if(showCombatActions) 
    {
        printf("\t\t\t┌────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("\t\t\t│ %s", combatText);
        for(int pad = 0; pad < COMBAT_TEXT_MAXLEN - strlen(combatText); pad++) { printf(" "); }
        printf("│\n");
        printf("\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");

    }
    
    printf("\t\t\t┌───────────────┬────────────────┬────────────────┬────────────────%s\n", (showCombatActions ? "┬─────────────┐" : "┐"));
    
    // Names
    for(char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        SetColor(15);
        if(i == 0) { printf("\t\t\t│ "); }
        if(i < partySize) 
        {
            charAt = 0;
            while(character[i].name[charAt] != '\0') 
            { 
                putchar(character[i].name[charAt]); 
                charAt++; 
            }
            for(char i = 14 - (charAt+1); i > 0; i--) { printf(" "); }
        }
        else { printf(" ──────────────"); }
        SetColor(15);
        printf(" │");
    }
    if(showCombatActions) { printf(" KEY ACTIONS │"); }
    
    printf("\n");

    SetColor(15);
    printf("\t\t\t├───────────────┼────────────────┼────────────────┼────────────────%s\n", (showCombatActions ? "┼─────────────┤" : "┤"));

    // HP Stats
    for(char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        if(i == 0) { printf("\t\t\t│"); }

        SetColor(10);
        if(i < partySize)  { printf(" HP: %4d/%4d ",character[i].current_HP, character[i].max_HP); }
        else { printf(" ────────────── "); }
        SetColor(15);
        printf("│");
    }
    if(showCombatActions) { printf(" <^v> - MOVE │"); }
    printf("\n");

    // MP Stats
    for(char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        if(i == 0) { printf("\t\t\t│"); }
        
        SetColor(9);
        if(i < partySize)  { printf(" MP: %4d/%4d ",character[i].current_MP, character[i].max_MP); }
        else { printf(" ────────────── "); }
        SetColor(15);
        printf("│");
    }
    if(showCombatActions) { printf("CTRL - SELECT│"); }
    printf("\n");

    // AP Stats
    for(char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        if(i == 0) { printf("\t\t\t│"); }
        
        SetColor(14);
        if(i < partySize)  { printf(" AP: %3d/%d   ", 0, 100); } // character[0].current_AP, character[0].max_AP); // AP not implemented yetcharacter[i].current_AP, character[i].max_AP); }
        else { printf(" ────────────── "); }
        SetColor(15);
        printf("│");
    }
    if(showCombatActions) { printf("SHFT - RETURN│"); }
    printf("\n");

    
    printf("\t\t\t└──────%s──────┴────────────────┴────────────────┴────────────────%s\n", (strcmp(character[0].action, "") != 0 ? character[0].action : "───"), (showCombatActions ? "┴─────────────┘" : "┘"));
    printf("\x1B[0m");
}

int renderPlayerMagicSpellMenu()
{
    char spellsel = 0;
    char enemyIndex = 0;

    while(true)
    {
        renderMainPartyStats(true, "");
        SetColor(15);
        printf("\x1B[1m");
        printf("\t\t\t┌────────────────────────────────SELECT THE SPELL────────────────────────────────┐\n");
        
        // Max text len = 15
        //printf("\x1B[4B");
        printf("\t\t\t│");

        if(spellsel == 0) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[0]], false) == false) { printf("                    "); }
        else 
        {
            printf(" %s", (spellsel == 0 && character[0].learnedSpells > 0 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[0]]);
            for(int pad = 0; pad < 16-strlen(availableSpells[character[0].spellIndices[0]]); pad++) { putchar(' '); }
        }
        
        SetColor(15);
        printf("│");

        if(spellsel == 1) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[1]], false) == false) { printf("                   "); }
        else 
        {
            printf(" %s", (spellsel == 1 && character[0].learnedSpells > 1 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[1]]);
            for(int pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[1]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");

        if(spellsel == 2) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[2]], false) == false) { printf("                   "); }
        else 
        {
            printf(" %s", (spellsel == 2 && character[0].learnedSpells > 2 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[2]]);
            for(int pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[2]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");

        if(spellsel == 3) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[3]], false) == false) { printf("                   "); }
        else 
        {
            printf(" %s", (spellsel == 3 && character[0].learnedSpells > 3 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[3]]);
            for(int pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[3]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");

        printf("\n\t\t\t│"); // 4 magic spells per line (will be the same for class skils)

        if(spellsel == 4) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[4]], false) == false) { printf("                    "); }
        else 
        {
            printf(" %s", (spellsel == 4 && character[0].learnedSpells > 4 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[4]]);
            for(int pad = 0; pad < 16-strlen(availableSpells[character[0].spellIndices[4]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");

        if(spellsel == 5) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[5]], false) == false) { printf("                   "); }
        else 
        {
            printf(" %s", (spellsel == 5 && character[0].learnedSpells > 5 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[5]]);
            for(int pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[5]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");

        if(spellsel == 6) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[6]], false) == false) { printf("                   "); }
        else 
        {
            printf(" %s", (spellsel == 6 && character[0].learnedSpells > 6 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[6]]);
            for(int pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[6]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");

        if(spellsel == 7) { SetColor(10); }
        if(findSkill(character[0].magtree, availableSpells[character[0].spellIndices[7]], false) == false) { printf("                   "); }
        else 
        {
            printf(" %s", (spellsel == 7 && character[0].learnedSpells > 7 ? "┼─" : "  "));
            printf(" %s", availableSpells[character[0].spellIndices[7]]);
            for(int pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[7]]); pad++) { putchar(' '); }
        }

        SetColor(15);
        printf("│");
        

        // TODO: We can have up to 8 spells here, there's just not that many yet

        printf("\n\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");
        printf("\x1B[0m");
        printf("\x1B[14A");
        limitFPS(150);
        
        while(true)
        {
            if(character[0].learnedSpells > 0) // Only move the cursor of there's any spell to select
            {
                if(GetAsyncKeyState (VK_UP) != 0)
                {
                    if(spellsel > 3 && character[0].learnedSpells > 4) 
                    {
                        playSFX("CombatCursorMove");
                        spellsel -= MAGIC_SPELLS_PER_LINE; 
                        limitFPS(150);
                        break;
                    }
                }

                if(GetAsyncKeyState (VK_DOWN) != 0)
                {
                    if(spellsel < 4 && character[0].learnedSpells > 4) 
                    {
                        playSFX("CombatCursorMove");
                        spellsel += MAGIC_SPELLS_PER_LINE;
                        limitFPS(150);
                        break;
                    }
                }

                if(GetAsyncKeyState (VK_LEFT) != 0)
                {
                    if(spellsel > 0) 
                    { 
                        playSFX("CombatCursorMove");
                        spellsel -= 1; 
                        limitFPS(150);
                        break;
                    }
                }

                if(GetAsyncKeyState (VK_RIGHT) != 0)
                {
                    if(spellsel < (character[0].learnedSpells-1)) 
                    {
                        playSFX("CombatCursorMove");
                        spellsel += 1; 
                        limitFPS(150);
                        break;
                    }
                }
            }
            

            if(GetAsyncKeyState (VK_LCONTROL) != 0)
            {
                if(character[0].learnedSpells == 0) { break; } // Also only select spells if there are any available
                limitFPS(150);
                playSFX("CombatCursorSelect");
                enemyIndex = selectEnemy();
                if(enemyIndex == -1) { limitFPS(150); break; }

                strcpy(character[0].action,"MAG");            
                if(spellsel == 0)
                {
                    playerUseSpell(availableSpells[character[0].spellIndices[0]], enemyIndex);
                    return enemyIndex;
                }

                if(spellsel == 1)
                {
                    playerUseSpell(availableSpells[character[0].spellIndices[1]], enemyIndex);
                    return enemyIndex;
                }

                if(spellsel == 2)
                {
                    playerUseSpell(availableSpells[character[0].spellIndices[2]], enemyIndex);
                    return enemyIndex;
                }

                if(spellsel == 3)
                {
                    playerUseSpell(availableSpells[character[0].spellIndices[3]], enemyIndex);
                    return enemyIndex;
                }

                if(spellsel == 4)
                {
                    playerUseSpell(availableSpells[character[0].spellIndices[4]], enemyIndex);
                    return enemyIndex;
                }
            }

            if(GetAsyncKeyState (VK_LSHIFT) != 0)
            {
                playSFX("ReturnFromMenu");
                return -1;
            }

        }
    }

}

int playerAttackEnemy(char enemyIndex)
{
    int damage = (character[0].atk - Enemy[enemyIndex].def);
    char combatText[COMBAT_TEXT_MAXLEN];
    bool gotCriticalHit = calculateCriticalHitChance(character[0].luck);

    if(gotCriticalHit) 
    { 
        damage *= 1.5;
        playSFX("CriticalHit");
    }
    else { playSFX("HitConfirm"); }

    if(damage > 0)
    {
        Enemy[enemyIndex].current_HP -= damage;
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s attacks... %s causes %d damage to '%s'.", character[0].name, (gotCriticalHit ? "CRITICAL HIT!!!" : "and"), damage, Enemy[enemyIndex].name);
        renderMainPartyStats(true, combatText);
        printf("\x1B[10A");
        limitFPS(1000);
    }
}

bool calculateCriticalHitChance(int luck) 
{
    float luckStat = (float)(luck - 100) / (999 - 100);
    float criticalHitChance = 0.025f + (luckStat * (0.325f - 0.025f));

    //printf("crit:%f", criticalHitChance);

    if (criticalHitChance < 0) { criticalHitChance = 0; }
    if (criticalHitChance > 0.3f) { criticalHitChance = 0.3f; }

    float scoredCriticalHit = (float)rand() / RAND_MAX;

    return scoredCriticalHit < criticalHitChance;
}

// TODO: These should also be commonized. Tons of duplicated code...
bool playerUseSpell(char *spell, char enemyIndex)
{
    int damage = (character[0].atk - Enemy[enemyIndex].def);
    char combatText[COMBAT_TEXT_MAXLEN];

    damage *= (character[0].inte/100);

    playSFX("AquaStorm");
    if(strcmp(Enemy[enemyIndex].weakness, spell) == 0) damage *= 2;
    else if (strcmp(Enemy[enemyIndex].resists, spell) == 0) damage *= 0.7;

    if(damage > 0)
    {
        Enemy[enemyIndex].current_HP -= damage;
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s used %s... and caused %d damage to '%s'.", character[0].name, spell, damage, Enemy[enemyIndex].name);
        renderMainPartyStats(true, combatText);
        printf("\x1B[10A");
        limitFPS(1000);
    }

    character[0].current_MP -=30;

    return true;
}

// TODO: Attacking party characters, though we need more than a party member for that
void enemyAttackPlayer(char enemyIndex, char charIndex)
{
    int damage = (Enemy[enemyIndex].atk - character[charIndex].def);
    char combatText[COMBAT_TEXT_MAXLEN];

    playSFX("PlayerHit");
    if(damage > 0)
    {
        character[charIndex].current_HP -= damage;
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s attacks... it caused %d damage to '%s'.", Enemy[enemyIndex].name, damage, character[charIndex].name);
        renderMainPartyStats(true, combatText);
        printf("\x1B[10A");
        limitFPS(1000);
    }
}

void enemyDozesOff(char enemyIndex)
{
    char combatText[COMBAT_TEXT_MAXLEN];
    snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s enemy dozed off...", Enemy[enemyIndex].name);
    renderMainPartyStats(true, combatText);
    printf("\x1B[10A");
    limitFPS(1000);
}

void enemyAction()
{
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        if(Enemy[enemyIndex].current_HP > 0) 
        {
            short int randaction = rand() % 100;
            if(randaction <= 75) { enemyAttackPlayer(enemyIndex, 0); }
            else { enemyDozesOff(enemyIndex); }
        }
    }
}
