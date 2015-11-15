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

/*check func to check validity of the password
 *password string is passed
 *returns 0 if no char in password or space in passwor*/

int check(char *pn) {	/*check for valid password */
	int l = strlen(pn);
	if(l == 0)
		return 0;
	int i = 0;
	while(i < l) {
		if(pn[i] == ' ')
			return 0;
	i++;
	}
	return 1;
}

/*func to deal with password related data
 *pass file ptr of file in which password is stored
 *returns 0 if password do not match*/ 
	
int password(FILE *fp) {	/* password */
	char err[32], p[16], *p1, pn[16], pc[16];
	int n, op, c1, c2, count, count1, n1;
	a:system("clear");
	printheader();
	printf(BLUE"\n\n\tNOTE: DEFAULT PASSWORD FOR FIRST TIME LOG IN UNTIL USER CHANGES IS:=>"RESET GREEN" Test_123"RESET BLUE"\n\t"      			"      PASSWORD WILL NOT BE DISPLAYED ON SCREEN WHILE TYPING\n\n\n\n"RESET);
	printf(MAGENTA"\t\t1]Login to the system\t 2]Change the password\t 3]Show the password\t 4]Close\n\n"RESET);
	printf("\n\n\tEnter the option number:");
	n1 = scanf("%d", &op);
	if(n1 == 0) {
		op = 7;
		readline(err, 32);
	}
	switch(op) {
		case 1:count = 0;
			system("clear");
			printheader();
			printf(BLUE"\n\n\tNOTE: DEFAULT PASSWORD FOR FIRST TIME LOG IN UNTIL USER CHANGES IS:=>"RESET GREEN" Test_123"RESET 					BLUE"\n\t      PASSWORD WILL NOT BE DISPLAYED ON SCREEN WHILE TYPING\n\n"RESET);	
			fp = fopen("password.txt", "r");
			rewind(fp);
			n = fread(p, sizeof(char), 16, fp);
			p[n] = '\0';
			w:p1 = getpass(RED"\n\t\tEnter the password:"RESET);
			count++;
			if(strcmp(strcat(p1, "\n"), p) == 0) {
				return 1;
			}
			else {
				if(count <= 2) {
					system("clear");
					printheader();
					system("sleep 1");
					printf(BLUE"\n\n\tNOTE: DEFAULT PASSWORD FOR FIRST TIME LOG IN UNTIL USER CHANGES IS:=>"RESET GREEN 						"Test_123"RESET BLUE"\n\tPASSWORD WILL NOT BE DISPLAYED ON SCREEN WHILE TYPING\n\n"RESET);	
					printf(RED"\n\n\t\t\t\t***Incorrect password. Try again***\n\n\n"RESET);
					goto w;
				}
				else {
					printf(RED"\n\n\t\t\t\t***You made 3 wrong attempts - ACCESS DENIED***\n\n\n"RESET);
					exit(1);
				}
			}
			fclose(fp);
			break;
		case 2:count1 = 0;
			system("clear");
			printheader();
			printf(BLUE"\n\n\tNOTE: DEFAULT PASSWORD FOR FIRST TIME LOG IN UNTIL USER CHANGES IS:=>"RESET GREEN" Test_123"RESET 					BLUE"\n\t      PASSWORD WILL NOT BE DISPLAYED ON SCREEN WHILE TYPING\n\n"RESET);
			fp = fopen("password.txt", "r");
			d:rewind(fp);
			p1 = getpass(RED"\n\t\tEnter present password:"RESET);
			count1++;
			n = fread(p,sizeof(char), 16, fp);
			p[n] = '\0';
			if(strcmp(strcat(p1, "\n"), p) == 0) {
				fclose(fp);
				fp = fopen("password.txt", "w");
				readline(err, 1);
				m:b:printf(RED"\n\n\t\tEnter new password (Maximum 15 characters and no space allowed):"RESET);
				c1 = readline(pn, 16);
				c2 = check(pn);
				if(c1 == 0 || c2 == 0) {
					system("clear"); 
					printheader();
					if(c1 == 0) 
						printf(RED"\n\t\t\t\t\t***Password too long***\n"RESET);
					if(c2 == 0)
						printf(RED"\n\t\t\t\t\t***No space allowed***\n"RESET);
					printf(RED"\n\t\t\t\t***Password not valid, try again***\n\n"RESET);
					goto m;
				}
				printf(RED"\n\n\t\tConfirm new password:"RESET);
				readline(pc, 16);
				if(strcmp(pn, pc) == 0) {
					strcat(pn, "\n");
					fwrite(pn, sizeof(char), strlen(pn), fp);
					system("clear");
					printheader();
					printf(GREEN"\n\t\t\t\t***Password successfully changed***\n"RESET);
					fclose(fp);
					printf("\n\nPress enter key to continue");
					readline(err, 1);
					goto a;
				}
				else {
					printf(RED"\n\t\t\tPassword don't match\n"RESET);
					goto b;
				}
				fclose(fp);
			}
			else {
				if(count1 <= 2) {
					system("clear");
					printheader();
					system("sleep 1");
					printf(BLUE"\n\n\tNOTE: DEFAULT PASSWORD FOR FIRST TIME LOG IN UNTIL USER CHANGES IS:=>"RESET GREEN 						"Test_123"RESET BLUE"\n\t      PASSWORD WILL NOT BE DISPLAYED ON SCREEN WHILE TYPING\n"RESET);	
					printf(RED"\n\n\t\t\t\t***Incorrect password. Try again***\n\n\n"RESET);
					goto d;
				}
				else {
					fclose(fp);
					printf(RED"\n\n\t\t\t\t***You made 3 wrong attempts - ACCESS DENIED***\n\n\n"RESET);
					exit(1);
				}
			}
			break;
		case 3:system("clear");
			printheader();
			printf(BLUE"\n\n\tNOTE: DEFAULT PASSWORD FOR FIRST TIME LOG IN UNTIL USER CHANGES IS:=>"RESET GREEN" Test_123"RESET 					BLUE"\n\t      PASSWORD WILL NOT BE DISPLAYED ON SCREEN WHILE TYPING\n\n"RESET);
			fp = fopen("password.txt", "r");
			n = fread(p, sizeof(char), 16, fp);
			p[n] = '\0';
			printf(GREEN"\n\t\t\tPassword is:"RESET RED" %s\n"RESET, p);
			fclose(fp);
			printf(RESET"\n\nPress enter key to continue");
			readline(err, 1);
			readline(err, 1);
			goto a;
			break;
		case 4:system("clear");
			exit (1);
			break;
		default:printf(RED"\n\n\t\t\t***Incorrect option***\n"RESET);
			system("sleep 2");
			goto a;
			break;
	}
	return 0;
} 
