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

FILE *fa;

/*functions for employee*
 *All the following func are passed with file ptr of file in which employee data is stored*/
void new_emp(FILE *fe, FILE *fd, FILE *fa) {
	char yn, err[32], dat[16], tim[16];
	int flag = 0, id, op = 0, n;
	employee e;
	doc_avail a;
	fseek(fe, 0, SEEK_END);
	fseek(fd, 0, SEEK_END);
	fseek(fa, 0, SEEK_END);
	yn = 'Y';
	while((yn == 'Y') || (yn == 'y')) {
		op = 0;
		printf("\n--------------------------------------------------------------------------------\n");
		system("clear");		
		printheader();
		w:printf(RED"New employee: 1]Doctor or 2]Other employee 3]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1 || op == 2) {
			goto w1;
		}
		else if(op == 3) {
			system("clear");
			fclose(fe);
			fclose(fd);
			fclose(fa);
			emp_info(fe, fd, fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		w1: printf(BLUE"Enter the unique identification number:\n"RESET);
		scanf("%d", &id);
		rewind(fe);
		rewind(fd);
		while(fread(&e, SIZE2, 1, fe) == 1) {
			if(e.uid == id) {
				printf(RED"\tERROR: UID number already exists; type another one.\n"RESET);
				flag = 1; 
				goto w1;
			}
		}
		if((flag == 0) || (fread(&e, SIZE, 1, fe) == 0)) {
			fseek(fe, 0, SEEK_END); /*taking ptr at the end of file to add new record*/
			fseek(fd, 0, SEEK_END);
			fseek(fa, 0, SEEK_END);			
			e.uid = id;
			a.uid = id;
			printf(BLUE"\nName of the employee:"RESET);
			readline(err, 32);
			readline(e.name, 32);
			strcpy(a.doc_name, e.name);
			printf(BLUE"\nGender(M:Male/F:Female/O:Other):"RESET);
			readline(e.gender, 8);
			printf(BLUE"\nAge:"RESET);
			readline(e.age, 4);
			printf(BLUE"\nAddress:\n"RESET);
				printf(BLUE"\n\tHouse no.:"RESET);
				readline(e.b.house_no, 8);
				printf(BLUE"\n\tStreet name:"RESET);
				readline(e.b.street, 32);
				printf(BLUE"\n\tCity:"RESET);
				readline(e.b.city, 32);
				printf(BLUE"\n\tState:"RESET);
				readline(e.b.state, 32);
			printf(BLUE"\nContact no.:"RESET);
			readline(e.contact, 16);
			printf(BLUE"\nE-mail id:"RESET);
			readline(e.email, 32);
			printf(BLUE"\nBlood group:"RESET);
			readline(e.bg, 4);
			printf(BLUE"\nSalary: Rs."RESET);
			readline(e.salary, 8);
			printf(BLUE"\nDesignation:"RESET);
			readline(e.desig, 32);
			strcpy(a.desig, e.desig);
			if(op == 1) {
				printf(YELLOW"\nEnter availability of the doctor:\n"RESET);
					printf(BLUE"\tMonday:"RESET); readline(e.d.mon, 32); strcpy(a.d1.mon, e.d.mon);
					printf(BLUE"\tTuesday:"RESET); readline(e.d.tue, 32); strcpy(a.d1.tue, e.d.tue);
					printf(BLUE"\tWednesday:"RESET); readline(e.d.wed, 32); strcpy(a.d1.wed, e.d.wed);
					printf(BLUE"\tThursday:"RESET); readline(e.d.thu, 32); strcpy(a.d1.thu, e.d.thu);
					printf(BLUE"\tFriday:"RESET); readline(e.d.fri, 32); strcpy(a.d1.fri, e.d.fri);
					printf(BLUE"\tSaturday:"RESET); readline(e.d.sat, 32); strcpy(a.d1.sat, e.d.sat);
					printf(BLUE"\tSunday:"RESET); readline(e.d.sun, 32); strcpy(a.d1.sun, e.d.sun);
			}		
			printf(BLUE"\nDate of enrollment(mm-dd-yyyy):"RESET);
			dt(dat, tim);
			strcpy(e.date, dat);
			printf("%s\n", e.date);
			printf(GREEN"\n\n\t\t\t***Successfully enrolled***\n\n"RESET);
			if(op == 1) {
				fwrite(&e, SIZE2, 1, fd);
				fwrite(&a, SIZE3, 1, fa);
			}	
			fwrite(&e, SIZE2, 1, fe);
			printf(RED"\nDo you want to make another new entry(Y/N)?\n"RESET);
			scanf("%c", &yn);
		}
	}
	
}

void edit_emp(FILE *fe, FILE *fd) {
	char yn, err[32], dat[16], tim[16];
	employee e;
	int id, flag = 0, flag1 = 0, op, n;
	yn = 'Y';
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0, flag1 = 0;
		w:printf(RED"\n1]Edit data\t2]Return\n"RESET);
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
			fclose(fe);
			fclose(fd);
			emp_info(fe, fd, fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &id);
		rewind(fe);
		rewind(fd);
		while(fread(&e, SIZE2, 1, fe) == 1) {
			if(e.uid == id) {
				flag = 1;
				break;
			}
		}
		while(fread(&e, SIZE2, 1, fd) == 1) {
			if(e.uid == id) {
				flag1 = 1;
				break;
			}
		}
		if(flag == 0) {
			printf(RED"\tERROR: The employee is not registered\n"RESET);
			yn = 'N';
		}
		else { 
			printf(BLUE"\nName of the employee:"RESET);
			readline(err, 1);
			readline(e.name, 32);
			printf(BLUE"\nGender(M:Male/F:Female/O:Other):"RESET);
			readline(e.gender, 8);
			printf(BLUE"\nAge:");
			readline(e.age, 4);
			printf(BLUE"\nAddress:\n"RESET);
				printf(BLUE"\n\tHouse no.:"RESET);
				readline(e.b.house_no, 8);
				printf(BLUE"\n\tStreet name:"RESET);
				readline(e.b.street, 32);
				printf(BLUE"\n\tCity:"RESET);
				readline(e.b.city, 32);
				printf(BLUE"\n\tState:"RESET);
				readline(e.b.state, 32);
			printf(BLUE"\nContact no.:"RESET);
			readline(e.contact, 16);
			printf(BLUE"\nE-mail id:"RESET);
			readline(e.email, 32);
			printf(BLUE"\nBlood group:"RESET);
			readline(e.bg, 4);
			printf(BLUE"\nDesignation:"RESET);
			readline(e.desig, 32);
			printf(BLUE"\nSalary: Rs."RESET);
			readline(e.salary, 8);
			printf(BLUE"\nDate of update(mm-dd-yyyy):"RESET);
			dt(dat, tim);
			strcpy(e.date, dat);
			printf("%s\n", e.date);
			if(flag1 == 1) {
				fseek(fd, -SIZE2, SEEK_CUR);
				fwrite(&e, SIZE2, 1, fd);
			}				
			fseek(fe, -SIZE2, SEEK_CUR);
			fwrite(&e, SIZE2, 1, fe);
			printf(GREEN"\n\n\t\t\t***Successfully edited***\n\n"RESET);	
			printf(RED"Do you want edit any other registered entry(Y/N)?\n"RESET);
			scanf("%c", &yn);
		}
	}	
}

void search_emp(FILE *fe, FILE *fd) {
	char n[32], yn = 'Y', err[32];
	int id, op, f1 = 0, n1;
	employee e;
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
			readline(err, 1);			
			readline(n, 32);
			rewind(fe);
			while(fread(&e, SIZE2, 1, fe) == 1) {
				if(strcmp(e.name, n) == 0) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 2) {
			printf(BLUE"Enter the UID number:\n"RESET);
			scanf("%d", &id);
			rewind(fe); 
			while(fread(&e, SIZE2, 1, fe) == 1) {
				if(e.uid == id) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 3) {
			fclose(fe);
			emp_info(fe);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		if(f1 == 1) {
			system("clear");
			printf(RED"\n\t\t<<------------- DATA OF EMPLOYEE ------------>>\n\n"RESET);
			printf(BLUE"=> UID number of the employee:"RESET"\t%d\n\n", e.uid); 
			printf(BLUE"=> Name of the employee:"RESET"\t%s\n\n", e.name);
			printf(BLUE"=> Designation:"RESET"\t%s\n\n", e.desig);
			printf(BLUE"=> Gender:"RESET"\t%s\n\n", e.gender);
			printf(BLUE"=> Age:"RESET"\t%s years\n\n", e.age);
			printf(BLUE"=> Address:\n\n");
				printf(BLUE"\t> House no.:  "RESET"\t%s\n", e.b.house_no);
				printf(BLUE"\t> Street name:"RESET"\t%s\n", e.b.street);
				printf(BLUE"\t> City:       "RESET"\t%s\n", e.b.city);
				printf(BLUE"\t> State:      "RESET"\t%s\n\n", e.b.state);
			printf(BLUE"=> Contact no.:"RESET"\t%s\n\n", e.contact);
			printf(BLUE"=> E-mail id:"RESET"\t%s\n\n", e.email);
			printf(BLUE"=> Blood group:"RESET"\t%s\n\n", e.bg);
			printf(BLUE"=> Salary:\t"RESET"Rs.%s\n\n", e.salary);
			printf(BLUE"=> Date of last update:"RESET"\t%s\n\n", e.date);
			printf("--------------------------------------------------------------\n");
		}
		else
			printf(RED"\tERROR: Entry not found\n"RESET);
		printf(RED"\nDo you want to search any other registered entry(Y/N)?\n"RESET);
		scanf(" %c", &yn);
	}
		 
}

void list_emp(FILE *fe, FILE *fd) {
	char err[1];
	employee e;
	rewind(fe);
	printf("--------------------------------------------\n");
	printf(RED"Registered employee:\n"RESET);
	printf("--------------------------------------------\n\n\n");
	while(fread(&e, SIZE2, 1, fe) == 1) {
		printf(BLUE"=> UID number of the employee:"RESET"\t%d\n", e.uid); 
		printf(BLUE"=> Name of the employee:"RESET"\t%s\n", e.name);
		printf(BLUE"=> Designation:"RESET"\t%s\n", e.desig);
		printf(BLUE"--------------------------------------------\n\n");
	}
	printf("Press enter key to continue");
	readline(err, 1);
	readline(err, 1);
}

void close_emp(FILE *fe, FILE *fd) {
	employee e;
	char yn = 'Y', err[32];
	int id, flag = 0, flag1 = 0, op, n;
	FILE *tmp1, *tmp2;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = flag1 = 0;
		rewind(fe);
		rewind(fd);
		tmp1 = fopen("temporary1.txt", "wb+");	
		tmp2 = fopen("temporary2.txt", "wb+");	
		w:printf(RED"\n1]Close the record\t2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"\n\nUID number to be closed:"RESET);
		}
		else if(op == 2) {
			system("clear");
			fclose(fe);
			fclose(fd);
			fclose(fa);
			emp_info(fe, fd, fa);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &id);
		while(fread(&e, SIZE2, 1, fe) == 1) {
			if(e.uid != id) {
				fseek(tmp1, 0, SEEK_END);
				fwrite(&e, SIZE2, 1, tmp1);
			}
			else
				flag = 1;
		}
		while(fread(&e, SIZE2, 1, fd) == 1) {
			if(e.uid != id) {
				fseek(tmp2, 0, SEEK_END);
				fwrite(&e, SIZE2, 1, tmp2);
			}
			else
				flag1 = 1;
		}

		if(flag == 1) {
			fclose(tmp1);
			fclose(fe);
			fe = fopen("employee.txt", "wb+");
			tmp1 = fopen("temporary1.txt", "rb+");
			while(fread(&e, SIZE2, 1, tmp1) == 1) {
					fseek(fe, 0, SEEK_END);
					fwrite(&e, SIZE2, 1, fe);
			}
			fclose(tmp1);	
			fclose(fe);
			fe = fopen("employee.txt", "rb+");
			if(flag1 == 1) {
				fclose(tmp2);
				fclose(fd);
				fd = fopen("doctor.txt", "wb+");
				tmp2 = fopen("temporary2.txt", "rb+");
				while(fread(&e, SIZE2, 1, tmp2) == 1) {
						fseek(fd, 0, SEEK_END);
						fwrite(&e, SIZE2, 1, fd);
				}
				fclose(tmp2);	
				fclose(fd);
				fd = fopen("doctor.txt", "rb+");
			}
			printf(GREEN"\n\t\t\t***Successfully closed***\n\n"RESET);
		}
		else
			printf(RED"\tERROR: UID number does not exis\n");	
		printf(RED"Do you want to close any other record(Y/N):\n"RESET);
		scanf(" %c", &yn);
	}
}
/***********************/
/*employee info
 *This func passed with file ptr
 *It returns errno if file do not open else return 0*/

int emp_info() {
	FILE *fe, *fd;
	fe = fopen("employee.txt", "rb+");
	fd = fopen("doctor.txt",  "rb+");
	fa = fopen("availability.txt", "rb+");
	if(fe == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}
	if(fd == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}
	if(fa == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}

	int op, n;
	char err[32];
	while(1) {
		printempmenu();
		c:printf("\n\n\n\tEnter the option number:");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}

		switch(op) {
			case 1:system("clear");
				printheader();
				new_emp(fe, fd, fa);
				break;
			case 2:system("clear");
				printheader();
				edit_emp(fe, fd);
				break;
			case 3:system("clear");
				printheader();
				search_emp(fe, fd);
				break;
			case 4:system("clear");
				printheader();
				list_emp(fe, fd);
				break;
			case 5:system("clear");
				printheader();
				close_emp(fe, fd);
				break;
			case 6:fclose(fa);
				fclose(fd);
				fclose(fe);
				system("clear");
				printheader();
				printmainmenu();
				break;
			default:printf(RED"\n\n\t***Invalid entry***"RESET);
				goto c;		
				break;		
		}
	}
	return 0;
}
