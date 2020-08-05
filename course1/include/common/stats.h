/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Header file for array analyses
 *
 * This file contains all the function declarations and descriptions of functions used in the project.
 * 
 * @author Rohan Chinni
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes as an input a pointer to the data array and size of the array and prints out
 * statistics using the other functions defined in this project.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return NULL | prints the statistics
 */
void print_statistics(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * This function takes as an input a pointer to the data array and size of the array and prints out
 * all the entries of the array in an orderly fashion.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return NULL | prints the array
 */
void print_array(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * This function takes as an input a pointer to the data array and size of the array and returns the
 * median value of the set of data.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return The median value calculated from the array
 */
unsigned int find_median(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean value
 *
 * This function takes as an input a pointer to the data array and size of the array and returns the
 * mean value of the set of data.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return The mean value calculated from the array
 */
unsigned int find_mean(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the maximum value
 *
 * This function takes as an input a pointer to the data array and size of the array and returns the
 * maximum value of the set of data.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return The maximum value calculated from the array
 */
unsigned int find_maximum(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the minimum value
 *
 * This function takes as an input a pointer to the data array and size of the array and returns the
 * minimum value of the set of data.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return The minimum value calculated from the array
 */
unsigned int find_minimum(unsigned char *data, unsigned int size);

/**
 * @brief Given an array of data with right and left indices, sorts the array from largest to smallest.
 *
 * This function takes as an input a pointer to the data array and size of the array and returns an
 * array sorted starting from largest value to the smallest using quick sort.
 *
 * @param data The pointer to data array
 * @param size The size of the data array
 * @return NULL | The array gets sorted
 */
void sort_array(unsigned char *data, unsigned int size);

/**
 * @brief Given two pointers, swaps their values.
 *
 * This function takes as an input two pointers and uses a temporary variable to swap their values.
 *
 * @param first The pointer to data array
 * @param second The left index of data array for quick sort
 * @return NULL | changes made from pointers.
 */
void swap(unsigned char *first, unsigned char *second);

#endif /* __STATS_H__ */
