typedef struct address {
	char house_no[8];
	char street[32];
	char city[32];
	char state[32];
}address;

typedef struct patient {
	int regn;
	char name[32];
	char gender[8];
	char age[4];
	address a;
	char contact[16];
	char email[32];
	char type[16];
	char bg[4];
	char disease[64];
	char doc_name[32];
	char history[256];
	char date[16];
	char treatment[32];
	char med[32];
}patient;
 
#define SIZE sizeof(patient)

typedef struct days {
	char mon[32];
	char tue[32];
	char wed[32];
	char thu[32];
	char fri[32];
	char sat[32];
	char sun[32];
}days;	
typedef struct employee {
	char name[32];
	int uid;
	char gender[8];
	char age[4];
	address b;
	days d;
	char contact[16];
	char email[32];
	char bg[4];
	char date[16];
	char salary[8];
	char desig[32];
}employee;
#define SIZE2 sizeof(employee)

typedef struct payment {
	char name[32];
	char date[16];
	char type[16];
	int reg;
	float doc_fee;
	float reg_fee;
	float med_fee;
	float tot_fee;
	char status[32];
}payment;

#define SIZE1 sizeof(payment)

typedef struct doc_avail {
	char doc_name[32];
	int uid;
	char desig[32];
	days d1;
}doc_avail;

#define SIZE3 sizeof(doc_avail)
