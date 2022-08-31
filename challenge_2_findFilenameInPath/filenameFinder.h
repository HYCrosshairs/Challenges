#ifndef _FILENAME_FINDER_H
#define _FILENAME_FINDER_H

/**
 * @brief list files inside a directory recursively
 * @param folder Path to the directory to list.
 * @return Show all files and sub directories
 */
void list_paths_in_folder(char *folder);

/**
 * @brief Calculate the length of a string
 * @param str string to be processed
 * @return the length of the string
 */
unsigned int str_len(char *str);

/**
 * @brief Extract filename from paths
 * @param path Path to be processed
 * @return the filename if exist
 */
char* extract_filename_from_path(char* path);

#endif /*_FILENAME_FINDER_H*/
