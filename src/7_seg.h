#ifndef SEVEN_SEG
#define SEVEN_SEG


void init_7seg(int fd);
void seven_seg_write(int seg, int number, int reset);
int seven_seg_write_str(char* number);
int convert_digit(int n);
void reset(int idx);

#endif
