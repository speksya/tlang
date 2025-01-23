#ifndef IO
#define IO

/**
 * @file io.h
 * @brief File input/output operations.
 */

/**
 * @brief Reads a file into a dynamically allocated string.
 * 
 * @param name The name of the file to read.
 * @return A pointer to the dynamically allocated string containing the file content.
 *         Returns NULL if the file cannot be read or memory allocation fails.
 */
char* io_read(const char* name);

#endif
