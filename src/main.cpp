#include <stdio.h>	/* printf */
#include <stdlib.h>	/* malloc, atoi, rand... */
#include <string.h>	/* memcpy, strlen... */
#include <stdint.h>	/* uints types */
#include <sys/types.h>	/* size_t ,ssize_t, off_t... */
#include <unistd.h>	/* close() read() write() */
#include <fcntl.h>	/* open() */
#include <sys/ioctl.h>	/* ioctl() */
#include <errno.h>	/* error codes */

// ioctl commands defined for the pci driver header
#include "ioctl_cmds.h"
#include "lcd.h"
#include "7_seg.h"

int main(int argc, char** argv)
{
	int fd, retval;
	fd = open("/dev/mydev", O_RDWR);

	unsigned int data = 0b00000000000000000000100000010000;

	ioctl(fd, RD_PBUTTONS);
	retval = read(fd, &data, sizeof(data));
	printf("new data: 0x%X\n", data);
	printf("read %d bytes\n", retval);
	
	seg7_init(fd);
	//lcd_init (fd);
	//lcd_clear();
	//lcd_set_cursor(1, 0);
	//lcd_string ("hello word");
	
	/*ioctl(fd, WR_RED_LEDS);
	retval = write(fd, &data, sizeof(data));
	printf("wrote %d bytes\n", retval);

	for (int i = 1; i < (1 << 8); i = i << 1) {
		ioctl(fd, WR_GREEN_LEDS);
		retval = write(fd, &i, sizeof(i));
		sleep(1);
	}*/
	
	//lcd_set_cursor(2, 0);
	//lcd_string ("finalizado!");
	int d = 0;
	for(int i =0; i <= 0xf; i++){
		d = ~seg7_convert_digit(i);
		printf("%d\n",d);
		write(fd, &d, sizeof(d));
		sleep(1);
	}
	/*ioctl(fd, RD_SWITCHES);
	retval = read(fd, &data, sizeof(data));
	printf("new data: 0x%X\n", data);
	printf("read %d bytes\n", retval);*/
	close(fd);
	return 0;
}
