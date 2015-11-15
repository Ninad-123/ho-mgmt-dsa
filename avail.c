
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

/*It has availability of doctor related functn*/

#include "header.h"

FILE *fa;

/*availability funct
 *All the following func are passed with file ptr of file in which availabilty data is stored
 *Func do not return any value- void*/

/*add new availability*/
void new_avail(FILE *fa) {
	char yn, err[32], dat[16], tim[16];
	int flag = 0, id, op, n;
	doc_avail a;
	fseek(fa, 0, SEEK_END);
	yn = 'Y';
	while((yn == 'Y') || (yn == 'y')) {
		printf("\n--------------------------------------------------------------------------------\n");
		system("clear");		
		printheader();
		w1:printf(RED"1]Add availability\t2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			goto w;
		}
		else if(op == 2) {
			system("clear");
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w1;
		}

		w: printf(BLUE"Enter the UID number:\n"RESET);
		scanf("%d", &id);
		rewind(fa);
		while(fread(&a, SIZE3, 1, fa) == 1) {
			if(a.uid == id) {
				printf(RED"\tERROR: UID number already exists; type another one.\n"RESET);
				flag = 1; 
				goto w;
			}
		}
		if((flag == 0) || (fread(&a, SIZE3, 1, fa) == 0)) {
			fseek(fa, 0, SEEK_END); /*taking ptr at the end of file to add new record*/
			a.uid = id;
			printf(BLUE"\nName of the doctor:"RESET);
			readline(err, 32);
			readline(a.doc_name, 32);
			printf(BLUE"\nDesignation:"RESET);
			readline(a.desig, 32);
			printf(BLUE"\nEnter availability of the doctor:\n"RESET);
				printf(RED"\n\tMonday:"RESET); readline(a.d1.mon, 16);
				printf(RED"\n\tTuesday:"RESET); readline(a.d1.tue, 32);
				printf(RED"\n\tWednesday:"RESET); readline(a.d1.wed, 32);
				printf(RED"\n\tThursday:"RESET); readline(a.d1.thu, 32);
				printf(RED"\n\tFriday:"RESET); readline(a.d1.fri, 32);
				printf(RED"\n\tSaturday:"RESET); readline(a.d1.sat, 32);
				printf(RED"\n\tSunday:"RESET); readline(a.d1.sun, 32);
			
			printf(GREEN"\n\n\t\t\t***Successfully enrolled***\n\n"RESET);
			fwrite(&a, SIZE3, 1, fa);
			printf(RED"Do you want to make another new entry(Y/N)?\n"RESET);
			scanf("%c", &yn);
		}
	}
	
}

/*searches the availability of doctor*/
		
void search_avail(FILE *fa) {
	char n[32], yn = 'Y', err[32];
	int id, op, f1 = 0, n1;
	doc_avail a;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		f1 = 0;
		w:printf(RED"\nSearch by 1]Name 2]UID number 3]Return:\n\n"RESET);
		n1 = scanf("%d", &op);
		if(n1 == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"Enter the name of employee:\n"RESET);
			readline(err, 32);			
			readline(n, 32);
			rewind(fa);
			while(fread(&a, SIZE3, 1, fa) == 1) {
				if(strcmp(a.doc_name, n) == 0) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 2) {
			printf(BLUE"Enter the UID number:\n"RESET);
			scanf("%d", &id);
			rewind(fa); 
			while(fread(&a, SIZE3, 1, fa) == 1) {
				if(a.uid == id) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 3) {
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		if(f1 == 1) {
			system("clear");
			printf(RED"\n\t\t<<------------- AVAILABILITY OF DOCTOR ------------>>\n\n"RESET);
			printf(BLUE"=> UID number of the doctor:"RESET"\t%d\n\n", a.uid); 
			printf(BLUE"=> Name of the doctor:"RESET"\t%s\n\n", a.doc_name);
			printf(BLUE"=> Designation:"RESET"\t%s\n\n", a.desig);
			printf(BLUE"=> Availability:\n\n"RESET);
				printf(YELLOW"\t\t=> Monday:"RESET"    %s\n\n", a.d1.mon);
				printf(YELLOW"\t\t=> Tuesday:"RESET"   %s\n\n", a.d1.tue);
				printf(YELLOW"\t\t=> Wednesday:"RESET" %s\n\n", a.d1.wed);
				printf(YELLOW"\t\t=> Thursday:"RESET"  %s\n\n", a.d1.thu);
				printf(YELLOW"\t\t=> Friday:"RESET"    %s\n\n", a.d1.fri);
				printf(YELLOW"\t\t=> Saturday:"RESET"  %s\n\n", a.d1.sat);
				printf(YELLOW"\t\t=> Sunday:"RESET"    %s\n\n", a.d1.sun);
			printf("--------------------------------------------------------------\n");
		}
		else
			printf(RED"\tERROR: Entry not found\n"RESET);
		printf(RED"\nDo you want to search any other registered entry(Y/N)?\n"RESET);
		scanf(" %c", &yn);
	}
		 
}

/*Edits the availability of doctor*/
	
void edit_avail(FILE *fa) {
	char yn, err[32];
	doc_avail a;
	doc_avail a1;
	int id, flag = 0, op, n;
	yn = 'Y';
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		w:printf(RED"\n1]Edit availability\t2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"\n\nEnter Existing UID number:"RESET);
		}
		else if(op == 2) {
			system("clear");
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &id);
		rewind(fa);
		while(fread(&a, SIZE3, 1, fa) == 1) {
			if(a.uid == id) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			printf(RED"\tERROR: The doctor availability is not present\n"RESET);
			yn = 'N';
		}
		else { 
			strcpy(a1.doc_name, a.doc_name);
			strcpy(a1.desig, a.desig);
			a1.uid = a.uid;
			printf(BLUE"Edit availability of the doctor:\n"RESET);
				printf(RED"\tMonday:"RESET); readline(err, 32); readline(a1.d1.mon, 16);
				printf(RED"\n\tTuesday:"RESET); readline(a1.d1.tue, 32);
				printf(RED"\n\tWednesday:"RESET); readline(a1.d1.wed, 32);
				printf(RED"\n\tThursday:"RESET); readline(a1.d1.thu, 32);
				printf(RED"\n\tFriday:"RESET); readline(a1.d1.fri, 32);
				printf(RED"\n\tSaturday:"RESET); readline(a1.d1.sat, 32);
				printf(RED"\n\tSunday:"RESET); readline(a1.d1.sun, 32);
			fseek(fa, -SIZE3, SEEK_CUR);
			fwrite(&a1, SIZE3, 1, fa);
			printf(GREEN"\n\t\t\t***Successfully edited***\n\n"RESET);	
			printf(RED"Do you want edit any other registered entry(Y/N)?\n"RESET);
			scanf("%c", &yn);
		}
	}	
}

/*List all the availability*/

void list_avail(FILE *fa) {
	char err[1];	
	doc_avail a;
	system("clear");
	printf(RED"\n\t<<------------- AVAILABILITY OF ALL DOCTORS ------------>>\n\n"RESET);
	rewind(fa);
	printf("--------------------------------------------------------------\n");
	while(fread(&a, SIZE3, 1, fa) == 1) {
		printf(BLUE"=> UID number of the doctor:"RESET"\t%d\n", a.uid); 
		printf(BLUE"=> Name of the doctor:"RESET"\t%s\n", a.doc_name);
		printf(BLUE"=> Designation:"RESET"\t%s\n", a.desig);
		printf(BLUE"=> Availability:\n"RESET);
			printf(YELLOW"\t\t=> Monday:"RESET"    %s\n", a.d1.mon);
			printf(YELLOW"\t\t=> Tuesday:"RESET"   %s\n", a.d1.tue);
			printf(YELLOW"\t\t=> Wednesday:"RESET" %s\n", a.d1.wed);
			printf(YELLOW"\t\t=> Thursday:"RESET"  %s\n", a.d1.thu);
			printf(YELLOW"\t\t=> Friday:"RESET"    %s\n", a.d1.fri);
			printf(YELLOW"\t\t=> Saturday:"RESET"  %s\n", a.d1.sat);
			printf(YELLOW"\t\t=> Sunday:"RESET"    %s\n", a.d1.sun);
		printf("--------------------------------------------------------------\n");
	}
	printf("\nPress enter key to continue\n");
	readline(err, 1);
	readline(err, 1);
}

/*delete the availability*/

void delete_avail(FILE *fa) {
	doc_avail a;
	char yn = 'Y', err[32];
	int id, flag = 0, op, n;
	FILE *tmp3;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		rewind(fa);
		tmp3 = fopen("temporary3.txt", "wb+");		
		w:printf(RED"\n1]Delete availability\t 2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"\n\nEnter the UID number whose availability to be deleted:"RESET);
		}
		else if(op == 2) {
			system("clear");
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &id);
		while(fread(&a, SIZE3, 1, fa) == 1) {
			if(a.uid != id) {
				fseek(tmp3, 0, SEEK_END);
				fwrite(&a, SIZE3, 1, tmp3);
			}
			else
				flag = 1;
		}
		if(flag == 1) {
		fclose(tmp3);
		fclose(fa);
		fa = fopen("availability.txt", "wb+");
		tmp3 = fopen("temporary3.txt", "rb+");
		while(fread(&a, SIZE3, 1, tmp3) == 1) {
				fseek(fa, 0, SEEK_END);
				fwrite(&a, SIZE3, 1, fa);
		}
		fclose(tmp3);	
		fclose(fa);
		fa = fopen("availability.txt", "rb+");
		printf(GREEN"\n\t\t\t***Successfully closed***\n\n"RESET);
		}
		else
			printf(RED"\tERROR: UID number does not exis\n"RESET);	
		printf(RED"Do you want to delete any other availability(Y/N):\n"RESET);
		scanf(" %c", &yn);
		
	}
}
	
/***********************/
/*avail info
 *This func passed with file ptr
 *It returns errno if file do not open else return 0*/
int avail_info(FILE *fa){
	fa = fopen("availability.txt", "rb+");
	if(fa == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}

	int op, n;
	char err[32];
	while(1) {
		printavailmenu();
		d:printf("\n\n\n\tEnter the option number:");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		switch(op) {
			case 1:system("clear");
				printheader();
				new_avail(fa);
				break;
			case 2:system("clear");
				printheader();
				search_avail(fa);
				break;
			case 3:system("clear");
				printheader();
				edit_avail(fa);
				break;
			case 4:system("clear");
				printheader();
				delete_avail(fa);
				break;
			case 5:system("clear");
				printheader();
				list_avail(fa);
				break;
			case 6:fclose(fa);
				system("clear");
				printheader();
				printmainmenu();
				break;
			default:printf(RED"\n\n\t***Invalid entry***"RESET);
				goto d;		
				break;		
		}
	}
	return 0;
}
