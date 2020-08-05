#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Convert std int into ASCII string
 *
 * String is NULL terminated.
 *
 * @param data Data to be converted
 * @param ptr Pointer to converted string
 * @param base Base 2-16 supported
 *
 * @return Length of converted data including NULL terminator
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert ASCII string std int
 *
 * String is NULL terminated.
 *
 * @param digits Length of string
 * @param ptr Pointer to string
 * @param base Base 2-16 supported
 *
 * @return Integer value of the ASCII string
 */
uint32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif
