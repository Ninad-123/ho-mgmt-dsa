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

/*discount
 *pass int total- total payment fee
 *returns modified total after discount*/

int discount(float total) {	
	float con;	
	con = total * 20 / 100;
	total = total - con;
	return total;
}


/*Pay info- returns errno if any related file donot have access*/
int pay_info() {
	payment pay;
	patient p;
	char n[32], dat[16], tim[16], err[32], yn, f, f1 = 0;
	int reg, op, n1;
	FILE *fp1, *fp;
	fp = fopen("patient.txt", "rb+");
	if(fp == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}
	fp1 = fopen("payment.txt", "rb+");
	if(fp1 == NULL) {
		perror(RED"Sorry, file cannot be accessed:"RESET);
		return errno;
	}
	rewind(fp);
	rewind(fp1);
	system("clear");
	printheader();
	w:printf(RED"Search by 1]registration number or 2]name of the patient  3]Return\n"RESET);
	n1 = scanf("%d", &op);
	if(n1 == 0) {
		op = 7;
		readline(err, 32);
	}
	f = 0;
	if(op == 1) {
		printf(BLUE"\nEnter registration number of the patient:\n"RESET);
		scanf("%d", &reg);
		f = 1;
	}
	else if(op == 2) {
		printf(BLUE"\nEnter name of the patient:\n"RESET);
		readline(err, 1);
		readline(n, 32);
		f = 1;
	}
	else if(op == 3) {
		fclose(fp);
		fclose(fp1);
		system("clear");
		printheader();
		printmainmenu();
	}
	else {
		printf(RED"\n\t***Invalid Entry***\n\n"RESET);
		goto w;
	}
	if(f == 1) {
		while(fread(&p, SIZE, 1, fp) == 1) {
			f1 = 0;
			if(strcmp(p.name, n) == 0 || p.regn == reg) {
				f1 = 1;
				break;
			}
		}
		if(f1 == 1) {
			pay.reg = p.regn;
			strcpy(pay.name, p.name);
			strcpy(pay.type, p.type);	
			dt(dat, tim);
			strcpy(pay.date, dat);
			printf(BLUE"Enter registration fee:"RESET" Rs.");
			scanf("%f", &pay.reg_fee);
			printf(BLUE"Enter doctor fee:"RESET" Rs.");
			scanf("%f", &pay.doc_fee);
			printf(BLUE"Enter medicine fee:"RESET" Rs.");
			scanf("%f", &pay.med_fee);
			pay.tot_fee = pay.reg_fee + pay.doc_fee + pay.med_fee;
			if((strcmp(p.type, "G") == 0 || strcmp(p.type, "g") == 0) || (strcmp(p.type, "M") == 0 || strcmp(p.type,"m") == 0)) {
				pay.tot_fee = discount(pay.tot_fee);
			} 
			printf(BLUE"Total payment amount:"RESET"\tRs.%f\n", pay.tot_fee); 
			printf(BLUE"Payment received(Y/N)\n"RESET);
			scanf(" %c", &yn);
			if(yn = 'y' || yn == 'Y') 
				strcpy(pay.status, "Payment done\n");
			else
				strcpy(pay.status, "Payment not done\n");
			fseek(fp1, 0, SEEK_END);
			fwrite(&pay, SIZE1, 1, fp1);
		}
		else {
			printf(RED"\tERROR: Entry not found\n"RESET);
			goto g;
		}	
		system("clear");
		printheader();
		printf(RED"\t\t<<------------ PAYMENT RECCEIPT ------------>>\n\n"RESET);
		printf(BLUE"Date:"RESET MAGENTA"%s\n\n"RESET, dat);
		printf(BLUE"\tPatient Name:"RESET MAGENTA"\t%s\n\n"RESET, p.name);
		printf(BLUE"\tRegistration number:"RESET MAGENTA"\t%d\n\n"RESET, p.regn);
		printf(BLUE"\tType of patient:"RESET MAGENTA"\t");
			if(strcmp(p.type, "G") == 0 || strcmp(p.type, "g") == 0)
				printf("Government Servant\n\n"RESET);
			else if(strcmp(p.type, "M") == 0 || strcmp(p.type, "m") == 0)
				printf("Mediclaim Holder\n\n"RESET);
			else
				printf("Other\n\n"RESET);
		printf(BLUE"\tPayment details:\n\n");
		printf(RED"\t\tRegistration fee:"RESET MAGENTA"\tRs.%f\n\n"RESET, pay.reg_fee);
		printf(RED"\t\tDoctor fee:"RESET MAGENTA"      \tRs.%f\n\n"RESET, pay.doc_fee);
		printf(RED"\t\tMedical fee:"RESET MAGENTA"     \tRs.%f\n\n"RESET, pay.med_fee);
		printf("\t\t----------------------------------------\n");
		printf("\t\tTotal fee:"RESET MAGENTA"      \tRs.%f\n"RESET, pay.tot_fee);
		printf("\t\t----------------------------------------\n\n");
		printf(BLUE"\tStatus:"RESET MAGENTA"\t%s\n\n"RESET, pay.status);
		printf(GREEN"\t(20 percent discount for Government Servant and Mediclaim Holder)\n"RESET);
	}
	g:printf("\nPress enter key to continue\n");
	readline(err, 1);	
	readline(err, 1);
	fclose(fp);
	fclose(fp1);
}
