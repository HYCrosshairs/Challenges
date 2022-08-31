#include "filenameFinder.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* file = NULL;
    const char PATHS[] = "input.txt";
    char line[256];

    file = fopen(PATHS, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: cannot open %s file\n", PATHS);
        return EXIT_FAILURE;
    }    

    while (fgets(line, sizeof(line), file)) 
    {
        printf("Filename from `%s` -> %s", line, extract_filename_from_path(line));
    } 

    fclose(file);
    printf("\n");
    return 0;
}
