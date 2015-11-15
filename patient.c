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

/***************************************************** FUNC FOR DIFF MODULES ***************************************************/
/*functions for patient
 *All the following func are passed with file ptr of file in which patient data is stored
 *Func do not return any value- void*/

/*new pat*/
void new_pat(FILE *fp) {
	char yn, err[32], dat[16], tim[16];
	int flag = 0, reg, op, n;
	patient p;
	fseek(fp, 0, SEEK_END);
	yn = 'Y';
	while((yn == 'Y') || (yn == 'y')) {
		printf("\n--------------------------------------------------------------------------------\n");
		system("clear");		
		printheader();
		w: printf(RED"1]Add record\t 2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"\n\nEnter Registration number:"RESET);
		}
		else if(op == 2) {
			system("clear");
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &reg);
		rewind(fp);
		while(fread(&p, SIZE, 1, fp) == 1) {
			if(p.regn == reg) {
				printf(RED"\tERROR: Registration number already exists; type another one.\n\n"RESET);
				flag = 1; 
				goto w;
			}
		}
		if((flag == 0) || (fread(&p, SIZE, 1, fp) == 0)) {
			fseek(fp, 0, SEEK_END); /*taking ptr at the end of file to add new record*/
			p.regn = reg;
			printf(BLUE"\nName of the patient:"RESET);
			readline(err, 32);
			readline(p.name, 32);
			printf(BLUE"\nGender(M:Male/F:Female/O:Other):"RESET);
			readline(p.gender, 8);
			printf(BLUE"\nAge:"RESET);
			readline(p.age, 4);
			printf(BLUE"\nAddress:\n"RESET);
			printf(BLUE"\n\tHouse no.:"RESET);
			readline(p.a.house_no, 8);
			printf(BLUE"\n\tStreet name:"RESET);
			readline(p.a.street, 32);
			printf(BLUE"\n\tCity:"RESET);
			readline(p.a.city, 32);
			printf(BLUE"\n\tState:"RESET);
			readline(p.a.state, 32);
			printf(BLUE"\nContact no.:"RESET);
			readline(p.contact, 16);
			printf(BLUE"\nE-mail id:"RESET);
			readline(p.email, 32);
			printf(BLUE"\nType of patient:\n\tGovernment servant(G)\n\tMediclaim holder(M)\n\tOther(O)\n"RESET);
			readline(p.type, 16);
			printf(BLUE"\nBlood group:"RESET);
			readline(p.bg, 4);
			printf(BLUE"\nDisease/problem:"RESET);
			readline(p.disease, 64);
			printf(BLUE"\nName of the doctor to being referred:"RESET);
			readline(p.doc_name, 32);
			printf(BLUE"\nHistory of patient if any:"RESET);
			readline(p.history, 256);
			printf(BLUE"\nDate of enrollment(mm-dd-yyyy):"RESET);
			dt(dat, tim);
			strcpy(p.date, dat);
			printf("%s\n", p.date);
			strcpy(p.treatment, "Not Available");
			strcpy(p.med, "Not Available"RESET);
			printf(GREEN"\n\n\t\t\t***Successfully enrolled***\n\n"RESET);
				
			fwrite(&p, SIZE, 1, fp);
			printf(RED"Do you want to make another new entry(Y/N)?\n"RESET);
			scanf("%c", &yn);
		}
	}
	
}

/*edit pat*/
void edit_pat(FILE *fp) {
	char yn, err[32], dat[16], tim[16];
	patient p;
	int reg, flag = 0, op, n;
	yn = 'Y';
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		w:printf(RED"\n1]Edit record\t 2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"\n\nEnter Registration number:"RESET);
		}
		else if(op == 2) {
			system("clear");
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &reg);
		rewind(fp);
		while(fread(&p, SIZE, 1, fp) == 1) {
			if(p.regn == reg) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			printf(RED"\tERROR: The patient is not registered\n"RESET);
			yn = 'N';
		}
		else { 
			printf(BLUE"\nName of the patient:"RESET);
			readline(err, 32);
			readline(p.name, 32);
			printf(BLUE"\nGender(M:Male/F:Female/O:Other):"RESET);
			readline(p.gender, 8);
			printf(BLUE"\nAge:"RESET);
			readline(p.age, 4);
			printf(BLUE"\nAddress:\n"RESET);
				printf(BLUE"\n\tHouse no.:"RESET);
				readline(p.a.house_no, 8);
				printf(BLUE"\n\tStreet name:"RESET);
				readline(p.a.street, 32);
				printf(BLUE"\n\tCity:"RESET);
				readline(p.a.city, 32);
				printf(BLUE"\n\tState:"RESET);
				readline(p.a.state, 32);
			printf(BLUE"\nContact no.:"RESET);
			readline(p.contact, 16);
			printf(BLUE"\nE-mail id:"RESET);
			readline(p.email, 32);
			printf(BLUE"\nType of patient:\n\tGovernment servant(G)\n\tMediclaim holder(M)\n\tOther(O)"RESET);
			readline(p.type, 16);
			printf(BLUE"\nBlood group:"RESET);
			readline(p.bg, 4);
			printf(BLUE"\nDisease/problem:"RESET);
			readline(p.disease, 64);
			printf(BLUE"\nName of the doctor to being referred:"RESET);
			readline(p.doc_name, 32);
			printf(BLUE"\nHistory of patient if any:"RESET);
			readline(p.history, 256);
			printf(BLUE"\nDate of update(mm-dd-yyyy):"RESET);
			dt(dat, tim);
			strcpy(p.date, dat);
			printf("%s\n", p.date);
			printf(BLUE"\nTreatment done:"RESET);
			readline(p.treatment, 32);
			printf(BLUE"\nMedicines suggested:"RESET);
			readline(p.med, 32);
			fseek(fp, -SIZE, SEEK_CUR);
			fwrite(&p, SIZE, 1, fp);
			printf(GREEN"\n\n\t\t\t***Successfully edited***\n\n"RESET);	
			printf(RED"Do you want edit any other registered entry(Y/N)?\n"RESET);
			scanf("%c", &yn);
		}
	}	
}

/*search pat*/
void search_pat(FILE *fp) {
	char n[32], yn = 'Y', err[32];
	int reg, op, f1 = 0, n1;
	patient p;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		f1 = 0;
		w:printf(RED"\nSearch by 1]Name 2]Registration number 3]Return:\n\n"RESET);
		n1 = scanf("%d", &op);
		if(n1 == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"Enter the name of patient:\n"RESET);
			readline(err, 32);			
			readline(n, 32);
			rewind(fp);
			while(fread(&p, SIZE, 1, fp) == 1) {
				if(strcmp(p.name, n) == 0) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 2) {
			printf(BLUE"Enter the registration number:\n"RESET);
			scanf("%d", &reg);
			rewind(fp); 
			while(fread(&p, SIZE, 1, fp) == 1) {
				if(p.regn == reg) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 3) {
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf(RED"\t***Invalid entry***\n"RESET);
			goto w;
		}
		if(f1 == 1) {
			system("clear");
			printf(RED"\n\t\t<<------------- DATA OF PATIENT ------------>>\n\n"RESET);
			printf(BLUE"=> Registration number of the patient:"RESET"\t%d\n\n", p.regn); 
			printf(BLUE"=> Name of the patient:"RESET"\t%s\n\n", p.name);
			printf(BLUE"=> Gender:"RESET"\t%s\n\n", p.gender);
			printf(BLUE"=> Age:"RESET"\t%s years\n\n", p.age);
			printf(BLUE"=> Address:\n\n"RESET);
				printf(BLUE"\t> House no.:"RESET"  \t%s\n", p.a.house_no);
				printf(BLUE"\t> Street name:"RESET"\t%s\n", p.a.street);
				printf(BLUE"\t> City:"RESET"       \t%s\n", p.a.city);
				printf(BLUE"\t> State:"RESET"      \t%s\n\n", p.a.state);
			printf(BLUE"=> Contact no.:"RESET"\t%s\n\n", p.contact);
			printf(BLUE"=> E-mail id:"RESET"\t%s\n\n", p.email);
			printf(BLUE"=> Type of patient:\t"RESET);
			if(strcmp(p.type, "G") == 0 || strcmp(p.type, "g") == 0)
				printf("Government servant\n\n");
			else if(strcmp(p.type, "M") == 0 || strcmp(p.type, "m") == 0)
				printf("Mediclaim holder\n\n");
			else
				printf("Other\n\n");
		
			printf(BLUE"=> Blood group:"RESET"\t%s\n\n", p.bg);
			printf(BLUE"=> Disease/problem:"RESET"\t%s\n\n", p.disease);
			printf(BLUE"=> Name of the doctor to being referred:"RESET"\t%s\n\n"RESET, p.doc_name);
			printf(BLUE"=> History of patient:"RESET"\t%s\n\n", p.history);
			printf(BLUE"=> Date of last visit:"RESET"\t%s\n\n", p.date);
			printf(BLUE"=> Treatment done:"RESET"\t%s\n\n", p.treatment);
			printf(BLUE"=> Medicines suggested:"RESET"\t%s\n\n", p.med);
			printf("--------------------------------------------------------------\n");
		}
		else
			printf("\tERROR: Entry not found\n"RESET);
		printf(RED"\nDo you want to search any other registered entry(Y/N)?\n"RESET);
		scanf(" %c", &yn);
	}
		 
}

void list_pat(FILE *fp) {
	char err[1];
	patient p;
	rewind(fp);
	printf("--------------------------------------------\n");
	printf(RED"Registered patients:\n"RESET);
	printf("--------------------------------------------\n\n\n");
	while(fread(&p, SIZE, 1, fp) == 1) {
		printf(BLUE"=> Registration number of the patient:"RESET"\t%d\n", p.regn); 
		printf(BLUE"=> Name of the patient:"RESET"\t%s\n", p.name);
		printf(BLUE"=> Date of last update:"RESET"\t%s\n\n", p.date);
		printf("--------------------------------------------\n\n");
	}
	printf("Press enter key to continue");
	readline(err, 1);
	readline(err, 1);
}

void close_pat(FILE *fp) {
	patient p;
	char yn = 'Y', err[32];
	int reg, flag = 0, op, n;
	FILE *tmp;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		rewind(fp);
		tmp = fopen("temporary.txt", "wb+");		
		w:printf(RED"\n1]Close record\t 2]Return\n"RESET);
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf(BLUE"\n\nEnter Registration number:"RESET);
		}
		else if(op == 2) {
			system("clear");
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf(RED"\n\t***Invalid entry***\n"RESET);
			goto w;
		}
		scanf("%d", &reg);
		while(fread(&p, SIZE, 1, fp) == 1) {
			if(p.regn != reg) {
				fseek(tmp, 0, SEEK_END);
				fwrite(&p, SIZE, 1, tmp);
			}
			else
				flag = 1;
		}
		if(flag == 1) {
		fclose(tmp);
		fclose(fp);
		fp = fopen("patient.txt", "wb+");
		tmp = fopen("temporary.txt", "rb+");
		while(fread(&p, SIZE, 1, tmp) == 1) {
				fseek(fp, 0, SEEK_END);
				fwrite(&p, SIZE, 1, fp);
		}
		fclose(tmp);	
		fclose(fp);
		fp = fopen("patient.txt", "rb+");
		printf(GREEN"\n\t\t\t***Successfully closed***\n\n"RESET);
		}
		else
			printf(RED"\tERROR: Registration number does not exis\n"RESET);	
		printf(RED"\nDo you want to close any other record(Y/N):\n"RESET);
		scanf(" %c", &yn);
		
	}
}
/***********************/
/*This func passed with file ptr
 *It returns errno if file do not open else return 0*/

int pat_info() {
	FILE *fp;
	fp = fopen("patient.txt", "rb+");
	if(fp == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}
	int op, n;
	char err[32];
	while(1) {
		printpatmenu();
		b:printf("\n\n\n\tEnter the option number:");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		switch(op) {
			case 1:system("clear");
				printheader();
				new_pat(fp);
				break;
			case 2:system("clear");
				printheader();
				edit_pat(fp);
				break;
			case 3:system("clear");
				printheader();
				search_pat(fp);
				break;
			case 4:system("clear");
				printheader();
				list_pat(fp);
				break;
			case 5:system("clear");
				printheader();
				close_pat(fp);
				break;
			case 6:system("clear");
				fclose(fp);
				printheader();
				printmainmenu();
				break;
			default:printf(RED"\n\n\t***Invalid entry***"RESET);
				goto b;		
				break;		
		}
	}
	return 0;
}
