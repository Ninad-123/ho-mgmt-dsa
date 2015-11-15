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
/*func to print manual how to use the system*/
 
void manual() {
	system("clear");
	char err[1];
	printf("-------------------------------------"
		"-----------------------------------------------------------------------------------------------------------\n\n");
	printf(RED"\t\t\t\t<------------ MANUAL PAGE ------------->\n\n"RESET);
	printf(GREEN"This project is designed to have HOSPITAL RECORD MANAGEMENT SYSTEM. It helps you to store data of patients, employees," 		"\navailability of doctors and payment information. There is MAIN MENU that consists of 4 main options\n"RESET);
	printf(BLUE"\n\t#option 1:"RESET MAGENTA" PATIENT helps you to store data about patients. It consists of:\n"RESET);
	printf(BLUE"\t\t>> option 1:"RESET MAGENTA"Add new record of a patient. Fill the details according to fields \n\t\tdisplayed on the screen.\n"RESET);
	printf(BLUE"\t\t>> option 2:"RESET MAGENTA"Edit existing record of a patient. If u want to change the stored data, \n\t\tchoose this option and fill the" 			" data again.\n"RESET);
	printf(BLUE"\t\t>> option 3:"RESET MAGENTA"Display data of a particular patient. This option displays all the stored\n\t\tdata of a particular patient." 			" Search is done by name or registration number.\n"RESET);
	printf(BLUE"\t\t>> option 4:"RESET MAGENTA"List all existing records of patients. This option displays name\n\t\tand registration number of all stored" 			" patients in list form.\n"RESET);
	printf(BLUE"\t\t>> option 5:"RESET MAGENTA"Delete existing record of a patient. If you want to close record\n\t\tof a patient use this option.\n"RESET);

	printf(BLUE"\n\t#option 2:"RESET MAGENTA" EMPLOYEE helps you to store data about employees of the hospital.\n\tIt consists of:\n"RESET);
	printf(BLUE"\t\t>> option 1:"RESET MAGENTA"Add new record of a employee. Fill the details according to fields \n\t\tdisplayed on the screen.\n"RESET);
	printf(BLUE"\t\t>> option 2:"RESET MAGENTA"Edit existing record of a employee Fill the details according to fields \n\t\tdisplayed on the screen.\n"RESET);
	printf(BLUE"\t\t>> option 3:"RESET MAGENTA"Display data of a particular employee. This option displays all the\n\t\tstored data of a particular" 			"employee. Search is done by name or UID number.\n"RESET);
	printf(BLUE"\t\t>> option 4:"RESET MAGENTA"List all existing records of employees. This option displays name\n\t\tand UID number of all registered " 			"employee in list form.\n"RESET);
	printf(BLUE"\t\t>> option 5:"RESET MAGENTA"Delete existing record of a employee. If you want to close record \n\t\tof a employee use this option.\n"RESET);

	printf(BLUE"\n\t#option 3:"RESET MAGENTA" PAYMENT helps you to do payment of fees. It provides you with payment\n\treceipt that shows details of all" 			" fees to be paid.\n"RESET);

	printf(BLUE"\n\t#option 4:"RESET MAGENTA" AVAILABILITY helps you to store data about availability of doctors.\n\tAvailability is stored according to"  			" days of week and timing for each day. It consists of:\n"RESET);
	printf(BLUE"\t\t>> option 1:"RESET MAGENTA"Add new availability record of a doctor.\n"RESET);
	printf(BLUE"\t\t>> option 2:"RESET MAGENTA"Search and display availability of particular doctor.\n"RESET);
	printf(BLUE"\t\t>> option 3:"RESET MAGENTA"Edit availability data of a particular doctor.\n"RESET);
	printf(BLUE"\t\t>> option 4:"RESET MAGENTA"Delete availabilty data of particular doctor.\n"RESET);
	printf(BLUE"\t\t>> option 5:"RESET MAGENTA"List availability of all doctors. If you dont know the name of the doctor,\n\t\tthis option displays the"  			" whole list.\n"RESET);

	printf("\n\nPress enter key to continue");
	readline(err, 1);
	readline(err, 1);
	system("clear");
	printheader();
	printmainmenu();
}
