#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../Game/Console_Colors/Colors.h"

#define NUM_SPELLS 9
#define NUM_SKILLS 9

char availableSpells[NUM_SPELLS][15] = 
{
    "AQUA STORM",
    "BLIZZARD",
    "WIND GUST",
    "EARTH SMASH",
    "SCORCH FLAME",
    "NULL",
    "NULL",
    "NULL",
    "NULL" // This one shall always be null
};

/* char availableSkills[][15] = 
{
    TODO
}; */


struct Node
{
    char skillName[20];
    bool isLearned;
    struct Node *left, *right;
};

typedef struct Node* BinTree;

BinTree* generate_BinTree();
void insertMagSkills(BinTree* tree);
void insertPhysSkills(BinTree* tree);
int insert_Node(BinTree* root, char skillname[]);
void free_BinTree(BinTree *root);
int insert_BinTree(BinTree* root, char skillname[]);
void learnSkill(BinTree *root, char* skilltolearn);
bool findSkill(BinTree *root, char* skilltofind, bool check);
void print_skillTree(BinTree* root, int spacing);

BinTree* generate_BinTree()
{
    BinTree* root = (BinTree*) malloc(sizeof(BinTree));
    if(root != NULL)
        *root = NULL;

    return root;
}

int returnSpellIndex(char *spellName) 
{
    for(int i = 0; i < NUM_SPELLS-1; i++) 
    {
        if(strcmp(availableSpells[i], spellName) == 0) { return i; }
    }
    return -1; // Shouldn't happen
}

void insertMagSkills(BinTree* tree)
{
    insert_Node(tree, "MAGICAL");

    insert_Node(tree, "SCORCH FLAME");
    insert_Node(tree, "BLIZZARD");
    insert_Node(tree, "INT BOOST");
    insert_Node(tree, "WIND GUST");
    insert_Node(tree, "EARTH SMASH");
    insert_Node(tree, "AQUA STORM");
}

void insertPhysSkills(BinTree* tree)
{
    insert_Node(tree, "PHYSICAL");

    insert_Node(tree, "DEF BOOST");
    insert_Node(tree, "STR BOOST");
}

int insert_Node(BinTree* root, char skillname[20])
{
    if(root == NULL)
        return 0;

    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL)
        return 0;
    strcpy(newNode->skillName, skillname);
    newNode->isLearned = false;
    newNode->right = NULL;
    newNode->left = NULL;

    if(*root == NULL)
        {
            newNode->isLearned = true;
            *root = newNode;
        }

    else{
        struct Node* currentNode = *root;
        struct Node* previousNode = NULL;
        while(currentNode != NULL){
            previousNode = currentNode;
            if(skillname[0] == currentNode->skillName[0]) // If the Element already exists, free it.
                {
                free(newNode);
                return 0;
                }
            if(skillname[0] > currentNode->skillName[0])
                currentNode = currentNode->right;
            else
                currentNode = currentNode->left;
        }
        if(skillname[0] > previousNode->skillName[0])
            previousNode->right = newNode;
        else
            previousNode->left = newNode;
    }
    return 1;
}

void freeNode(struct Node* node)
{
    if(node == NULL)
        return;
    freeNode(node->left);
    freeNode(node->right);
    free(node);
    node = NULL;
}

void free_BinTree(BinTree* root)
{
    if(root == NULL)
        return;
    freeNode(*root); // Frees each of the Tree's nodes.
    free(root); // Frees the root itself (generates a "incompatible pointer" warning)
    printf("\nThe tree has been freed\n");
}

void learnSkill(BinTree *root, char* skilltolearn)
{
    if(root == NULL)
        return;
    if(*root != NULL)
        {
            if(strcmp(skilltolearn, (*root)->skillName) == 0)
                (*root)->isLearned = true;

            learnSkill(&((*root)->left), skilltolearn);
            learnSkill(&((*root)->right), skilltolearn);
            //printf("Skill Name: %s\n", (*root)->skillName);
        }
}

bool findSkill(BinTree *root, char* skilltofind, bool check)
{

    if(check) return true;

    if(root == NULL)
        return false;


    if(*root != NULL)
        {
            if(!check)
            {
                if(strcmp(skilltofind, (*root)->skillName) == 0)
                    if((*root)->isLearned == true) return true;

                check = findSkill(&((*root)->left), skilltofind, check);
                check = findSkill(&((*root)->right), skilltofind, check);
                //printf("Skill Name: %s\n", (*root)->skillName);
            }
        }

    if (check == true) return true;
    else return false;
}

void print_skillTree(BinTree* root, int spacing)
{
    if (*root == NULL)
        return;
    // Increase distance between levels
    spacing += 7;

    // Process right child first
    print_skillTree(&(*root)->right, spacing);
    // Print current node after space
    // count
    if((*root)->isLearned == true) SetColor(10);

    for (int i = 7; i < spacing; i++)
        {
            if(i < spacing - (7-3))printf(" ");
            else printf("-");
        }
    printf("(%s)\n\n", (*root)->skillName);
    SetColor(15);

    // Process left child
    print_skillTree(&(*root)->left, spacing);
}

