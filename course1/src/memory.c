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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(unsigned char * ptr, unsigned int index, unsigned char value){
  ptr[index] = value;
}

void clear_value(unsigned char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

unsigned char get_value(unsigned char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(unsigned char * ptr, unsigned char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(unsigned char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	int i = 0;
	uint8_t temp[length];
	
	for(;i<length;i++){
		temp[i] = *(src + i);
		//PRINTF("%d to %d\n", *(src + i),temp[i]);
	}
	for(i=0;i<length;i++){
		*(dst + i) = temp[i];
	}
	
	return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	int i = 0;
	uint8_t temp[length];
	
	for(;i<length;i++){
		temp[i] = *(src + i);
		//PRINTF("%d to %d\n", *(src + i),temp[i]);
	}
	for(i=0;i<length;i++){
		*(dst + i) = temp[i];
	}
	
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	for(;length>0;length--){
		*(src + (length-1)) = value;
	}
	
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	for(;length>0;length--){
		*(src + (length-1)) = 0;
	}
	
	return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	int i;
	uint8_t tmp;

	for(i = 0; i < (length/2); i++){
		tmp = *(src + i);
		*(src + i) = *(src + length -i-1);
		*(src + length -i-1) = tmp;
	}

	return src;
}

int32_t * reserve_words(size_t length){
	int32_t *mem = (int32_t*)malloc(length * sizeof(int32_t));
	return mem;
}

void free_words(uint32_t * src){
	free(src);
}
