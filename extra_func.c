/*****************************************************************************
 * Copyright (C) Ninad A. Rajput rajput.ninad4@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "header.h"

/************************************************** EXTRA FUNCT *************************************************/
/*read the string
 *i/p- char *string- array of char in which string to be stored; int n- max no. of char in the string
 *returns no. of char stored in string*/

int readline(char *string, int n) {	
	int i = 0;
	char ch, err[16];
	ch = getchar();
	while(i < n && ch != '\n') {
		string[i] = ch;
		ch = getchar();
		i++;	
	}
	if(i == n) { 	/*chk fr password > 15*/
		readline(err, 16);
		return 0;
	}
	string[i] = '\0';
	return 1;
}

/*date nd time func
 *i/p-char *date- to store system date; *time- store system data
 *do not return any val*/
 
void dt(char *dat, char *tim) {	
	time_t t;
        struct tm *tmp;
	t = time(NULL);
	tmp = localtime(&t);
	strftime(dat, 16, "%x", tmp);
	strftime(tim, 16, "%X", tmp);
}

