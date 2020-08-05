#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	int i = 0; 
	int length = 0;
    bool isNegative = false; 

  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (data == 0) 
    { 
        *ptr++ = '0'; 
        *ptr = '\0'; 
        return 1; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (data < 0) 
    { 
        isNegative = true; 
        data = -data; 
    } 
  
    // Process individual digits 
    for (i=0;data!= 0;i++) 
    { 
        int rem = data % base; 
        *(ptr+i) = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        data = data/base; 
		length++;
    } 
  
    // If number is negative, append '-' 
    if (isNegative){
        *(ptr+i) = '-'; 
		length++;
	}
  
    *(ptr+i+1) = '\0'; // Append string terminator 
	length++;
  
    // Reverse the string 
    ptr = my_reverse(ptr, length-1); 
	
	return length;
}

uint32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	uint32_t result = 0; // Initialize result 
	bool isNegative = false;	

	if (*ptr == '-') 
    { 
        isNegative = true;
		//skip the '-' sign 
		ptr++;
    }

    // Iterate through all characters of input string and 
    // update result 
	for (int i = 0; *(ptr+i) != '\0'; ++i) 
	{
		if(*(ptr+i)<55)
		{
        	result = result * base + *(ptr+i) - '0';
		}
		else
		{
			result = result * base + *(ptr+i) + 10 - 'a';
		}
	}

	if(isNegative)
	{
		result *= -1;
		//return the pointer to original location	
		ptr--;
  	}
    // return result. 
    return result; 
	
}
