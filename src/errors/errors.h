#ifndef ERRORS
#define ERRORS

/**
 * @file errors.h
 * @brief Error handling and error messages.
 */

/**
 * @brief File errors
 */
#define FILE_NOT_SPECIFIED_NAME_ERROR "Error: Please specify file name"
#define FILE_READ_ERROR "Error: Failed to open the file"

/**
 * @brief Memory errors
 */
#define ALLOCATION_ERROR "Error: Failed to allocate memory"
#define REALLOCATION_ERROR "Error: Failed to reallocate memory"

/**
 * @brief Prints an error message and exits the program with a failure status.
 * 
 * @param message The error message to display.
 */
void throw_error(char* message);

/**
 * @brief Prints an error message and unexpected characher and exits the program with a failure status.
 * 
 * @param character. The unexpected character.
 */
void throw_unexpected_character_error(char character);

#endif
