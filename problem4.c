#include <stdio.h>

#include "utils.h"

void show_menu() {
    printf("--------------------------\n");
    printf("|      MONSTER LIST      |\n");
    printf("--------------------------\n");
    printf("| 1. Filter by name      |\n");
    printf("| 2. Filter by HP        |\n");
    printf("| 3. Filter by AC        |\n");
    printf("| 4. Filter by stats     |\n");
    printf("| 5. Exit                |\n");
    printf("--------------------------\n");
}

int compare_name(const void *elem1, const void *elem2)
{
    monster_s *m1 = (monster_s *)elem1;
    monster_s *m2 = (monster_s *)elem2;

    return strcmp(m1->name, m2->name);
}

int compare_hp(const void *elem1, const void *elem2)
{
    monster_s *m1 = (monster_s *)elem1;
    monster_s *m2 = (monster_s *)elem2;

    if (m1->hp > m2->hp)
    {
        return -1;
    }
    
    if (m1->hp < m2->hp)
    {
        return 1;
    }

    return 0;
}

int compare_ac(const void *elem1, const void *elem2)
{
    monster_s *m1 = (monster_s *)elem1;
    monster_s *m2 = (monster_s *)elem2;

    if (m1->ac > m2->ac)
    {
        return -1;
    }
    
    if (m1->ac < m2->ac)
    {
        return 1;
    }

    return 0;
}

int compare_stats(const void *elem1, const void *elem2)
{
    monster_s *m1 = (monster_s *)elem1;
    monster_s *m2 = (monster_s *)elem2;

    int m1_stats = m1->str + m1->dex + m1->con;
    int m2_stats = m2->str + m2->dex + m2->con;

    if (m1_stats > m2_stats)
    {
        return -1;
    }
    if (m1_stats < m2_stats)
    {
        return 1;
    }

    return 0;
}


int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Filename: %s.csv", argv[0]);
        return 1;
    }
    // TODO: Verify command line arguments.

    FILE* fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Could not open %s file.\n", argv[1]);
        return 1;
    }

    // TODO: Validate input arguments
    // TODO: Attempt to open file given by first command line argument
    FILE *fp = NULL;

    monster_s *monsters;
    int monster_count = load_monster_csv(&monsters, fp);

    // TODO: Load monsters

    // Run menu loop
    int choice = 0;
    while (choice != EXIT_CHOICE) {
        show_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                qsort(monsters, monster_count, sizeof(monster_s), compare_name);

                // TODO: Implement name filtering

                printf("Here is the filtered list: \n");

                for (int i = 0; i < monster_count; i++)
                {
                    printf("%s \n", monsters[i].name);
                }

                // TODO: Filter by name and print
                break;
            case 2:

                qsort(monsters, monster_count, sizeof(monster_s), compare_hp);

                // TODO: Implement HP filtering

                printf("Here is the filtered list: \n");

                for (int i = 0; i < monster_count; i++)
                {
                    printf("%s with %d HP \n", monsters[i].name, monsters[i].hp);
                }
                // TODO: Filter by HP and print
                break;
            case 3:

                qsort(monsters, monster_count, sizeof(monster_s), compare_hp);

                // TODO: Implement AC filtering

                printf("Here is the filtered list: \n");

                for (int i = 0; i < monster_count; i++)
                {
                    printf("%s with %d AC \n", monsters[i].name, monsters[i].ac);
                }
                // TODO: Filter by AC and print
                break;
            case 4:

                qsort(monsters, monster_count, sizeof(monster_s), compare_hp);

                // TODO: Implement stats filtering

                printf("Here is the filtered list: \n");

                for (int i = 0; i < monster_count; i++)
                {
                    printf("%s with %d STR, %d DEX, %d CON \n", monsters[i].name, monsters[i].str, monsters[i].dex, monsters[i].con);
                }
                // TODO: Filter by stats and print
                break;
            case 5:
                if (fp) {
                    fclose(fp);
                }
                break;
        }
    }
    return 0;
}