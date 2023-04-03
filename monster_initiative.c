#include <stdio.h>
#include<stdlib.h>
#include "utils.h"

int main (int  argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Filename: %s.csv", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    
    if (fp == NULL)
    {
        printf("Could not open %s file.\n", argv[1]);
        return 1;
    }

    monster_s monsters[MAX_MONSTERS];
    int monster_count = load_monster_csv(monsters,fp);

    monster_s **turn_order = NULL;
    int turn_count = 0;
    int input, used;

    while (1)
    {
        printf("What monster would you like to select? \n");
        
        for (int i = 0; i < monster_count; i++)
        {
            printf("%d. %s \n",i + 1, monsters[i].name);
        }

        printf("Press C to Continue\n");

        scanf("%d", &input);

        if (input == 'c')
        {
            break;
        }
        else if (input >= 1 && input <= monster_count)
        {
            for (int i = 0; i < turn_count; i++)
            {
                if (turn_order[i] == &monsters[input - 1])
                {
                    used++;
                    break;
                }
            }

            if (!used)
            {
                turn_order = realloc(turn_order,sizeof(monster_s *) * (turn_count + 1));
            }
            else
            {
                printf("Already in use. Please try again.\n");
            }
        }
        else
        {
            printf("I'm sorry, but that was an invalid option. Please try again. \n");
        }
    }

    fclose(fp);

    printf("\nHere is the turn order: \n");

    for (int i = 0; i < turn_count; i++)
    {
        printf("%s\n", turn_order[i]->name);
    }

    free(turn_order);
    
    return 0;
}