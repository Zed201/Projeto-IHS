#include "7_seg.h"
#include "ioctl_cmds.h"
#include <stdio.h>
#include <unistd.h>	/* close() read() write() */
#include <fcntl.h>	/* open() */
#include <sys/ioctl.h>	/* ioctl() */

static int file_d = 0;

void init_7seg(int fd){
	file_d = fd;
	int reset = 0xffffffff;
	ioctl(file_d, WR_L_DISPLAY);
	write(file_d, &reset, sizeof(reset));
	
	ioctl(file_d, WR_R_DISPLAY);
	write(file_d, &reset, sizeof(reset));
}
int seven_seg_write(int number){
	
}

int convert_digit(int n){
	int ret = 0;
	switch (n){
		// segmentos estao na ordem gfedcba
		case 1:
			ret = 0b0000110;
			break;
		case 2:
			ret = 0b1011011;
			break;
		case 3:
			ret = 0b1001111;
			break;
		case 4:
			ret = 0b1100110;
			break;
		case 5:
			ret = 0b1101101;
			break;
		case 6:
			ret = 0b1111101;
			break;
		case 7:
			ret = 0b0000111;
			break;
		case 8:
			ret = 0b1111111;
			break;
		case 9:
			ret = 0b1100111;
			break;
		default:
			ret = 0b0111111;
			break;
	}
	return ~ret;
}
