#ifndef SEVEN_SEG
#define SEVEN_SEG


void init_7seg(int fd);
int seven_seg_write(int number);
int seven_seg_write_str(char* number);
int convert_digit(int n);

#endif
