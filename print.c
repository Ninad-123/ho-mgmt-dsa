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
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110#1301, USA.
 *****************************************************************************/

#include "header.h"
FILE *fa;
/*header#prints header on screen*/
void printheader() {
	char dat[16], tim[16];
	system("clear");
	dt(dat, tim);
	printf("#####################################"
		"###########################################################################################################\n");
	printf(MAGENTA"\t%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s"RESET, dat, tim);
	printf(RED"\n\t\t\t\t\t\t\t\tSAHYADRI HOSPITAL\t\t\t\n\t\t\t\t\t\t\t\t#################\n\t\t\t\t\t\t\t\tSHIVAJINAGAR, Pune.\n"RESET);
	printf("\n###############################################"
		"#################################################################################################\n\n");
}


/*main menu*/
void printmainmenu() {
	printf("\n\t\t\t\t\t\t\t\t#############\n"
		CYAN"\t\t\t\t\t\t\t\t| MAIN MENU |\n"RESET
		"\t\t\t\t\t\t\t\t#############\n\n\n"
		BLUE"\t\t\t\t\t\t\t\t1] PATIENT\n\n"
	        "\t\t\t\t\t\t\t\t2] EMPLOYEE/DOCTOR\n\n"
	        "\t\t\t\t\t\t\t\t3] PAYMENT\n\n"
		"\t\t\t\t\t\t\t\t4] AVAILABILITY OF DOCTOR\n\n"
		"\t\t\t\t\t\t\t\t5] MANUAL PAGE\n\n"
		"\t\t\t\t\t\t\t\t6] EXIT\n\n\n"RESET);
	int c, n;
	char err[32];
	a:printf("\n\n\n\tEnter the option number:");
	n = scanf("%d", &c);
	if(n == 0) {
		c = 7;
		readline(err, 32);
	}
	
	/*cases for main menu*/
	switch(c) {
		case 1:pat_info();
			break;
		case 2:emp_info(fa);
			break;
		case 3:pay_info();
			system("clear");
			printheader();
			printmainmenu();
			break;
		case 4:avail_info(fa);
			break;
		case 5:manual();
			break;
		case 6:system("clear");
			exit(1);
			break;
		default:printf(RED"\n\t***Invalid entry***\n"RESET);
			goto a;
			break;
	}
}

/*patient menu*/
void printpatmenu() {
	system("clear");
	printheader();
	printf("\n\t\t###########\n"
		CYAN"\t\t| PATIENT |:\n"RESET
		"\t\t###########\n\n\n"
		BLUE"\t\t\t1] Enroll a new patient\n\n"
		"\t\t\t2] Edit existing entry\n\n"
		"\t\t\t3] Display record of particular patient\n\n"
		"\t\t\t4] List of all registered patients\n\n"
		"\t\t\t5] Close the enrollment of patient\n\n"
		"\t\t\t6] Return to main menu\n\n"RESET);
}

/*employee menu*/
void printempmenu() {
	system("clear");
	printheader();
	printf("\n\t\t############\n"
		CYAN"\t\t| EMPLOYEE |:\n"
		"\t\t############\n\n"
		BLUE"\t\t\t1] Add a record of new employee/doctor\n\n"
		"\t\t\t2] Edit existing record\n\n"
		"\t\t\t3] Display record of particular employee/doctor\n\n"
		"\t\t\t4] List of all registered employee\n\n"
		"\t\t\t5] Close the enrollment of employee\n\n"
		"\t\t\t6] Return to main menu\n"RESET);
}

/*avail menu*/
void printavailmenu() {
	system("clear");
	printheader();
	printf("\n\t\t################\n"
		CYAN"\t\t| AVAILABILITY |:\n"RESET
		"\t\t################\n\n\n"
		BLUE"\t\t\t1] Add availability of doctor\n\n"
		"\t\t\t2] Search availability of particular doctor\n\n"
		"\t\t\t3] Edit availablity\n\n"
		"\t\t\t4] Delete availability data\n\n"
		"\t\t\t5] List availability of all doctors\n\n"
		"\t\t\t6] Return to main menu\n"RESET);
}
/****************************************************************************************************************/	
