/* prog10.1.c Strings*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
	char name[30]; /* Full Name */
	unsigned
		birthday, /* 1...31 */
		birthmonth, /* 1...12 */
		birthyear; /* Four digits */
};

int main(int argc, char *argv[]) /*void*/
{
	   
	/* prog12.1.c Dynamic Memory Allocation */
	struct person *personlist = "";
	unsigned number_of_persons, num;
	char buffer[30];
	char *p;
	int year, month, day;
	int ok;
/*	char s[20];
	char ss[30];
	char *pfn;
/*	FILE *ffn = "testfile";

//	strcpy_s(s, s, "Strings");

	printf("s = %s\n", s);
	printf("s[3] = %c\n", s[3]);
	printf("s[7] = %d\n", s[7]);
	printf("strlen(s) = %lu\n", (unsigned long)strlen(s));
//	strcat_s(s, s, " program");
	printf("s now = %s\n", s);
	printf("strlen(s) = %lu\n", (unsigned long)strlen(s));

	/*prog10.2.c CMD arguments
	int i;
	printf("There are %d command line arguments\n", argc);

	for (i = 0; i < argc; i++)
	{
		printf("Command line argument number %d = %s\n", i, argv[i]);
	}

	/* prog11.1.c File Input Output

//	strcpy_s(ss, "file I/O test!", "ab");
	printf("%s\n", ss);
//	fopen_s(ffn, "testfile", "ab");
	if (ffn == NULL)
	{
		printf("Error: unable to open file for writing\n");
		return EXIT_FAILURE;
	}
	fputs(s, ffn);
	fclose(ffn);

//	strcpy_s(ss, "overwritten", "rb");
	printf("%s\n", ss);
//	fopen_s(ffn, "testfile", "rb");
	if (ffn == NULL)
	{
		printf("Error: unable to open file for reading\n");
		return EXIT_FAILURE;
	}

	if (fgets(ss, sizeof s, ffn) != NULL)
	{
		pfn = strchr(ss, '\n');
		if (pfn != NULL)
			*pfn = '\0';
		printf("%s\n", ss);
	}
	fclose(ffn);

	if (remove("testfile") != 0)
	{
		printf("Error: unable to remove file\n");
		return EXIT_FAILURE;
	}

	/* prog12.1.c Dynamic Memory Allocation */
	do
	{
		printf("Enter number of people: ");
		fflush(stdout);
		if(fgets(buffer,sizeof buffer, stdin) != NULL && sscanf_s(buffer, "%u", &number_of_persons) == 1)
		{
			ok = 1;
			if (number_of_persons>0)
			{
				personlist = malloc(number_of_persons * sizeof(struct person));
				if (personlist==NULL)
				{
					printf("Not enough memory for that many people!\n");
					ok = 0;
				}
			}
		}
		else
		{
			ok = 0;
			printf("Invalid number! Try again...");
		}
	} while (!ok);

	if (number_of_persons==0)
	{
		printf("Ok, another time!\n");
		return 0;
	}

	for (num=0; num<number_of_persons; num++)
	{
		printf("\nEnter Individuals Details #%u:\n", num);
		printf("Name: ");
		fflush(stdout);
		if (fgets(buffer, sizeof buffer, stdin) == NULL)
		{
			printf("Error: Reading stdin stresm; Input Aborted\n");
			number_of_persons = num;
			break;
		}
		p = strchr(buffer, '\n');
		if (p!=NULL)
			*p = '\0';
		if (strlen(buffer)==0)
		{
			printf("Input stopped\n");
			number_of_persons = num;
			break;
		}
		strcpy_s(personlist[num].name, sizeof buffer, buffer);
		do
		{
			printf("Birthday [YYYY-MM-DD]: ");
			fflush(stdout);
			if (fgets(buffer, sizeof buffer, stdin) != NULL
				&& sscanf_s(buffer, "%d-%d-%d", &year, &month, &day) == 3
				&& year>=1000 && year<=9999
				&& month>=1 && month<=12
				&& day>=1 && day<=31)
			{
				ok = 1;
			}
			else
			{
				ok = 0;
				printf("Invalid birth date! Try again...\n");
			}
		} while (!ok);
		personlist[num].birthyear = year;
		personlist[num].birthmonth = month;
		personlist[num].birthday = day;
	}
	printf("\nOk, Thank you\n");
	printf("\nDetail Entered:\n");
	printf("\n%-10s%-30s%s\n", "Number", "Name", "Birthday");

	for (num=0; num<number_of_persons; num++)
	{
		printf("%-10u%-30s%04d-%02d-%02d",
			num,
			personlist[num].name,
			personlist[num].birthyear,
			personlist[num].birthmonth,
			personlist[num].birthday);
	}
	free(personlist);
	//return EXIT_SUCCESS;
	return 3;
};