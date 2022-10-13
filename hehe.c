#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define SMALL_LOWERCASE 0
#define BIG_LOWERCASE 1

extern char *optarg;
extern int optind, opterr, optopt;

void help();
void create_file(int mode, char* filename);


int main(int argc, char *argv[]) {
    int mode = SMALL_LOWERCASE;
    char* name = "hehe.txt";

    int opt;
    if (argc == 1) {
        help();
        return 0;
    }

    while ((opt = getopt(argc, argv, "hco:")) != -1) {
        switch (opt) {
            case 'h':
                help();
                return 0;
            case 'c':
                mode = BIG_LOWERCASE;
                break;
            case 'o':
                name = optarg;
                printf("%s", optarg);
                break;
        }
    }

    create_file(mode, name);

    return 0;
}


void help() {
    printf("NAME\n"
           "       hehe - write Danylo's favorite word into the file `hehe.txt`\n\n"
           "SYNOPSIS\n"
           "       ./hehe [OPTION]...\n\n"
           "DESCRIPTION\n"
           "       -c activate special mode, where the author's word will be written in capital letters\n\n"
           "       -h display this help and exit\n\n"
           "       -o specify output file\n\n"
           "AUTHOR\n"
           "       Written by Danylo Sydorenko from CS34.\n\n"
           "COPYRIGHT\n"
           "       Copyright  ©  2018  Free Foundation, Inc.  License\n"
           "       GPLv3+: GNU  GPL  version  3  or  later  <https://gnu.org/li‐\n"
           "       censes/gpl.html>.\n"
           "       This  is  free  software:  you  are free to change and redis‐\n"
           "       tribute it.  There is NO WARRANTY, to the extent permitted by\n"
           "       law.\n\n"
    );

}

void create_file(int mode, char* filename) {
    char *word = (mode == 1) ? "STOICISM\n" : "stoicism\n";

    FILE * fptr;
    fptr = fopen(filename, "w");
    for (int i = 0; word[i] != '\n'; i++) {
        fputc(word[i], fptr);
    }
    fputc('\n', fptr);
    fclose(fptr);
}