#include <stdio.h>
#include "utils.c"

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

    // TODO: Attempt to open a CSV file given by the command line arguments.

    monster_s monsters[MAX_MONSTERS];
    int monster_count = load_monster(monsters, fp);


    // TODO: Load all the data with `load_monsters_csv`.

    for (int i = 0; i < monster_count; i++)
    {
        printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n",
            monsters[i].name, monsters[i].type, monsters[i].hp,
            monsters[i].ac, monsters[i].str, monsters[i].dex, monsters[i].con);
    }
    // TODO: Print the data to verify that it was loaded.

    fclose(fp);
    // TODO: Be sure to free any allocated memory.

    return 0;
}