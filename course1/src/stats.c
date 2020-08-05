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
 * @file stats.c 
 * @brief The main file for program that does basic operations on data array.
 *
 * Contains functions that analyze an array of unsigned char data items and report array analytics on 
 * the maximum, minimum, mean and median of the dataset. Additionally, this data is reordered from large to 
 * small. Statistics are rounded donw to the nearest integer.
 *
 * @author Rohan Chinni
 * 
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char *data, unsigned int size){
  PRINTF("\nThe Median rounded off to integer is %d\n", find_median(data, SIZE));
  PRINTF("The Mean rounded off to integer is %d\n", find_mean(data, SIZE));
  PRINTF("The Maximum value is %d\n", find_maximum(data, SIZE));
  PRINTF("The Minimum value is %d\n", find_minimum(data, SIZE));
}

void print_array(unsigned char *data, unsigned int size){
  //Required compile time switch
  #ifdef VERBOSE
  int i;
  PRINTF("------------------------------\n");
  for(i=0;i<size;i++){
    PRINTF("Index[%d] = %d\t",i, data[i]);
        if((i+1)%4==0){
      printf("\n\n");
    }
  }
  PRINTF("------------------------------\n");
  #endif
}

unsigned int find_median(unsigned char *data, unsigned int size){
  sort_array(data, size);
  if(size%2!=0){
    return data[size/2];
  }
  else{
    return (data[size/2]+data[(size/2)+1])/2;
  }
}

unsigned int find_mean(unsigned char *data, unsigned int size){
  int i, sum=0;
  for(i=0;i<size;i++){
    sum += data[i];
  }
  return (sum/size);
}

unsigned int find_maximum(unsigned char *data, unsigned int size){
  sort_array(data, size);
  return data[0];
}

unsigned int find_minimum(unsigned char *data, unsigned int size){
  sort_array(data, size);
  return data[size-1];
}

void sort_array(unsigned char *data, unsigned int size){
  //implementing reverse bubblesort
  int i=1, j;
  unsigned int flag = 0;
   while (flag==0){   
     flag =1;     
       for (j = 0; j < (size-i); j++){ 
           if (data[j] < data[j+1]){
              swap(&data[j], &data[j+1]);
              flag=0;
           }
       }
       i++;
   }
}

void swap(unsigned char *first, unsigned char *second){
  unsigned char temp;
  temp = *first;
  *first = *second;
  *second = temp;
}
