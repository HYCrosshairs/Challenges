#include "filenameFinder.h"

#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"

void list_file_dir(const char *path)
{
    DIR *directory;
    struct dirent *dir;
    directory = opendir(path);

    if (!directory)
    {
        fprintf(stderr, "Error when opening directory %s\n", path);
        return;
    }

    while ((dir = readdir(directory)) != NULL)
    {
        if (dir->d_type != DT_DIR)
        {
            // list_paths_in_folder(dir->d_name);
            fprintf(stdout, "%s%s\n", GREEN, dir->d_name);
        }
        else if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
        {
            fprintf(stdout, "%s%s\n", BLUE, dir->d_name);
            char path_child[255];
            sprintf(path_child, "%s", dir->d_name);
            list_file_dir(path_child);
        }
    }
    closedir(directory);
}
