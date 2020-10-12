#include <stdio.h>
#include <stdlib.h>
#include "header.h"



void print_header(header program_header) {
	

	for(int r = 0; r != program_header.rows; ++r) {

		int c = 0;
		while(c!=program_header.cols) {

			if (r == PAD + 1 && c == PAD +1) {
				fputs(program_header.message, stdout);
				c+=MESSAGE_LENGTH;
			} else {

				if (r == 0 || r == program_header.rows -1 ||  c == 0 || c == program_header.cols -1) {
					putchar('*');
				} else {
					putchar(' ');
				}
				++c;

			}

		}

		printf("\n");
	}
	return;
}
