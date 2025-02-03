#include "../TAD_SkillTree/Player_SkillTree.h"

#define MAX_PARTY_SIZE 4
#define MAX_NAME_SIZE 15

char partySize = 0;

typedef struct items
{
    short int HPpotion;
    short int MPpotion;
    short int HPinc;
    short int MPinc;
}items;

struct playerChar
{
    char name[MAX_NAME_SIZE];
    unsigned char Level; // Level will max out at 100.
    int gold;
    int max_HP;
    int current_HP;
    int max_MP;
    int current_MP;
    int atk;
    int def;
    int inte;
    int luck;
    bool key;
    int current_XP;
    int next_XP;
    BinTree* magtree;
    BinTree* phystree;
    items it;
    unsigned char learnedSpells; // It'll be impossible for a character to know more than 8 magic spells, or class skills
    unsigned char spellIndices[NUM_SPELLS-1];
    unsigned char learnedSkills;
    unsigned char skillIndices[NUM_SKILLS-1];

    // Combat-specific fields
    char action[4];
}character[4];

void insertCharName();
void createPlayer(int charIndex, char charName[MAX_NAME_SIZE]);

void insertCharName(int charIndex)
{
    char ch;
    char name[MAX_NAME_SIZE];
    int index = 0;
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    
    printf("\n\n\n\t\t\t|      BEFORE STARTING THE GAME...       |");
    printf("\n\t\t\t|  PLEASE INSERT YOUR CHARACTER'S NAME:  |");
    printf("\n\t\t\t\t|------------------------|");
    printf("\n\t\t\t\t|                        |");
    printf("\n\t\t\t\t|------------------------|");
    limitFPS(50);
    printf("\x1B[1A");
    printf("\x1B[25D");

    // Read input character by character
    while (index < sizeof(name) - 2) {
        ch = getchar(); // Read one character
        printf("%c", ch);
        
        // Check if we read a newline or EOF
        if (ch == '\n' || ch == EOF) {
            break; // Exit the loop on newline or EOF
        }

        // Store the character in the buffer if not a newline
        name[index++] = ch;
    }

    name[index] = '\0'; // Null-terminate the string
    createPlayer(charIndex, name);
}

void createPlayer(int charIndex, char charName[MAX_NAME_SIZE])
{
    character[charIndex].magtree = generate_BinTree();
    character[charIndex].phystree = generate_BinTree();
    insertMagSkills(character[charIndex].magtree);
    insertPhysSkills(character[charIndex].phystree);
    strcpy(character[charIndex].name, charName);

    character[charIndex].Level = 1;
    character[charIndex].gold = 0;
    character[charIndex].max_HP = 1050; // Base 1050
    character[charIndex].current_HP = 1050; // Base 1050
    character[charIndex].max_MP = 110; // Base 110
    character[charIndex].current_MP = 110; // Base 110
    character[charIndex].atk = 112; // Base 112
    character[charIndex].def = 122; // Base 122
    character[charIndex].inte = 102; // Base 102
    character[charIndex].luck = 115; // Base 115
    character[charIndex].current_XP = 0;
    character[charIndex].next_XP = 100;
    character[charIndex].key = false;
    character[charIndex].it.HPpotion = 0;
    character[charIndex].it.HPinc = 0;
    character[charIndex].it.MPpotion = 0;
    character[charIndex].it.MPinc = 0;

    character[charIndex].learnedSpells = 0;
    for(int i = 0; i < NUM_SPELLS-1; i++) 
    {
        character[charIndex].spellIndices[i] = NUM_SPELLS-1;
    }
    
    character[charIndex].learnedSkills = 0;
    for(int i = 0; i < NUM_SKILLS; i++) 
    {
        character[charIndex].skillIndices[i] = NUM_SKILLS-1;
    }

    strcpy(character[charIndex].action,"");

    if(partySize < MAX_PARTY_SIZE) { partySize++; } // Party will be a max of 4 characters, for UI tracking
}
