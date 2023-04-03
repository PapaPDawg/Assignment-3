#include <string.h>
#include <stdlib.h>

#include "utils.h"


void swap_int(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void parse_monster(monster_s *monster, char *csv_line) {
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token) {
        switch(attr) {
            case 0:
                strcpy(monster->name, token);
                break;
            case 1:
                strcpy(monster->type, token);
                break;
            case 2:
                monster->hp = atoi(token);
                break;
            case 3:
                monster->ac = atoi(token);
                break;
            case 4:
                monster->str = atoi(token);
                break;
            case 5:
                monster->dex = atoi(token);
                break;
            case 6:
                monster->con = atoi(token);
                break;
        }

        token = strtok(NULL, ",");
        attr++;
    }
}

/*
 * Loads all monsters from a CSV file into memory.
 * Allocates memory pointed to by `*monsters_ptr`
 *
 * Args
 * ----
 *  monster_s **monsters_ptr - A double pointer to `monster_s`.
 *      Dereferencing this once (`*monsters_ptr`) returns the value to where the
 *      allocated memory should be stored. That is, you should assign the result
 *      of an allocation call to `*monsters_ptr`.
 *
 *  FILE *fp - A file pointer representing an open CSV file.
 *
 * Return
 * ------
 *  Returns an `int` representing the number of monsters loaded.
 */

int load_monster_csv(monster_s **monsters_ptr, FILE *fp) {
    char buffer[MAX_LEN] = { 0 };
    int num_read = 0;

    while (fgets(buffer, MAX_LEN, fp)) {
        trim(buffer);
        parse_monster(&monsters_ptr[num_read],buffer);
        // Complete the function by parsing the csv line and storing the data into each monster_s entry.

        num_read++;
        // For each item, you will need to reallocate the data to support 1 more.
    }

    return num_read;
}

void print_monster(monster_s* monsters, int monster_count)
{
    int max_name = 0;
    int max_type = 0;
    int max_hp = 0;
    int max_ac = 0;
    int max_str = 0;
    int max_dex = 0;
    int max_con = 0;

    for (int i = 0; i < monster_count; i++)
    {
        int name_len = strlen(monsters[i].name);
        if (max_name < name_len)
        {
            max_name = name_len;
        }

        int type_len = strlen(monsters[i].type);
        if (max_type < type_len)
        {
            max_type = type_len;
        }

        int hp_len = strlen(monsters[i].hp);
        if(max_hp < hp_len)
        {
            max_hp = hp_len;
        }

        int ac_len = strlen(monsters[i].ac);
        if (max_ac < ac_len)
        {
            max_ac = ac_len;
        }

        int str_len = strlen(monsters[i].str);
        if (max_str < str_len)
        {
            max_str = str_len;
        }

        int dex_len = strlen(monsters[i].dex);
        if (max_dex < dex_len)
        {
            max_dex = dex_len;
        }

        int con_len = strlen(monsters[i].con);
        if (max_con < con_len)
        {
            max_con = con_len;
        }

    }

    printf("| %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | \n", 
    max_name, "Name", max_type, "Type", max_hp, "HP", max_ac, "AC",
    max_str, "STR", max_dex, "DEX", max_con, "CON");

    for (int i = 0; i < max_name + max_type + max_hp + max_ac + max_str + max_dex + max_con + 8; i++)
    {
        printf("-");
    }

    printf("\n");

for (int i = 0; i < monster_count; i++)
{
    printf("| %-*s | %-*s | %*d | %*d | %*d | %*d | %*d | \n",
    max_name, monsters[i].name, max_type, monsters[i].type, max_hp, monsters[i].hp, 
    max_ac, monsters[i].ac, max_str, monsters[i].str, max_dex, monsters[i].dex,
    max_con, monsters[i].con);
}
    

}