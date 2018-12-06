// 实验：getopt_long

/*
    实验 getopt_long

    $ ./longopt --init -l --file=fred.c 'hi there'
*/

#include <stdio.h>
#include <stdlib.h>

#define _GUN_SOURCE
#include <getopt.h>

int main(int argc, char *argv[])
{
    int opt;
    struct option longopts[] = {
        {"initialize", 0, NULL, 'i'},
        {"file", 1, NULL, 'f'},
        {"list", 0, NULL, 'l'},
        {"restart", 0, NULL, 'r'},
        {0, 0, 0, 0},
    };

    while ((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1) {
        switch(opt) {
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n", opt);
				break;
			case 'f':
				printf("filename: %s\n", optarg);
				break;
			case ':':
				printf("option[%c] needs a value\n", optopt);
				break;
			case '?':
				printf("unknow option: %c\n", optopt);
				break;
		}
    }

    for (; optind < argc; optind++)
		printf("argument: %s\n", argv[optind]);

    return 0;
}
