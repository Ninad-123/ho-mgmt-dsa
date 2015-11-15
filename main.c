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

/*It has main funct*/

#include "header.h"

extern FILE *fa;

void main() {
	system("clear");
	FILE *fp;
	int r = password(fp);
	if(r == 1) {
		system("clear");
		printheader();
		system("sleep 1");
		printf(YELLOW"\n\n\t\t\t\t\t\t\t\t    WELCOME\n");
		system("sleep 1");
		printf("\n\n\n\n\n\t\t\t\t\t\t\tHOSPITAL RECORD MANAGEMENT SYSTEM\n");
		system("sleep 1");
		printf("\n\n\n\n\n\t\t\t\t\t\t\t    NINAD ARUNSINGH RAJPUT\n"RESET);
		system("sleep 1");
		system("clear");
		printheader();
		printmainmenu(); 	
	}
}
