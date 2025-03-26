#include "7_seg.h"
#include "ioctl_cmds.h"
#include <stdio.h>
#include <unistd.h>	/* close() read() write() */
#include <fcntl.h>	/* open() */
#include <sys/ioctl.h>	/* ioctl() */

static int file_d = 0;
int current_R = 0;
int current_L = 0;

void init_7seg(int fd){
	file_d = fd;
	reset(0);
	reset(1);
}

void reset(int idx){
	int reset = 0xfffffff;
	// 0 vai ser o da direita da frente da placa e 1 o da esquerda
	if (idx) {
		ioctl(file_d, WR_R_DISPLAY);
	} else {
		ioctl(file_d, WR_L_DISPLAY);
	}
	write(file_d, &reset, sizeof(reset));
}
void seven_seg_write(int seg, int number, int _reset){ 
	// o seg e o index do seg comecando da direita de frente para a placa
	// em 0-7, o reset ele reseta os outros ou nao
	// R e L ta ao contrario, de costas para a placa, frente para as saidas de cabos
	// se reset 1 ele limpa se nao ele mantem os outros
	if (_reset){
		current_L = 0;
		current_R = 0;
		reset(1);
		reset(0);
	}
	if (seg > 7){
		return;
	}
		
	if(seg > 3){
		ioctl(file_d, WR_R_DISPLAY);
	} else {
		ioctl(file_d, WR_L_DISPLAY);
	}
	
	int d = convert_digit(number) << (7 * (seg % 4));
	int mask = ~(0xff << (7 * (seg % 4))); // para manter ou nao apenas o digto escolhido
	
	if (seg > 3){
		d = (current_L & mask) | d;
		current_L = d;
	} else {
		d = (current_R & mask) | d;
		current_R = d;
	} 
	
	d = ~d;
	write(file_d, &d, sizeof(d));

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
	return ret;
}
