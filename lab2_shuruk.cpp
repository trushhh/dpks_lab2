#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "getopt.h"

using namespace std;

int main(int argc, char* argv[]) {

	const int num = 4;
	const char* args = ":hil::d:";
	
	const struct option args_long[] = {
		{"help", no_argument, 0, 'h'},
		{"info", no_argument, 0, 'i'},
		{"list", optional_argument, 0, 'l'},
		{"disk", required_argument, 0, 'd'},
		{ 0, 0, 0, 0 }
	};

	int index;
	int a;
	
	/* variables to detect if argument already present */
	bool h_present = false;
	bool i_present = false;
	bool l_present = false;
	bool d_present = false;
	
	while ((a = getopt_long(argc, argv, args, args_long, &index)) != -1)
	{
		switch (a) {
		    
		case '?': {
			printf("Unknown option %c\n", optopt);
			break;
		}

		case ':': {
			printf("Required argument %c\n", optopt);
			break;
		}
		
		case 'h': {
			if (h_present == false)
			{
				printf("Help:\n");
				h_present = true;
			}
			break;
		};
		
		case 'i': {
			if (i_present == false)
			{
				printf("Info:\n");
				i_present = true;
			}
			break;
		};
		
		case 'l': {
			if (l_present == false)
			{
				if (optarg == NULL)
				{
					printf("List:\n"); //optional
					l_present = true;
				}
				else
				{
					printf("List = %s\n", optarg); //optional
					l_present = true;
				}
			}
			break;
		};
		
		case 'd': {
			if (d_present == false)
			{
				if ((optarg[0] < '0') || (optarg[0] > '9'))
				{
					printf("Argument required: --disk (-d)\n"); //required argument
					break;
				}
				else
				{
					printf("Disk = %s\n", optarg);
					d_present = true;
				}
			}
			break;
		};

		
		};
	};
	return 0;
};
