//This program emulates the Unix wordcount (wc) utility with a more verbose output and is adapted from K&R.
#include <stdio.h>

//Preprocessor directives that help explain the concept of state: are we currently inside or outside of a word?
#define IN      1
#define OUT     0

int main(int argc, char *argv[]) {
        FILE *pRead;
        pRead = fopen(*++argv, "r");
        if(pRead == NULL) {
                printf("File opening failed!");
                return 1;
        }

        int c, nl, nw, nc, state;
        state = OUT;
        nl = nw = nc = 0;

        //Since both of these return values and get executed when evaluated, they can be used in a boolean expression.
        while(!feof(pRead) && fscanf(pRead,"%c", &c)) {
                //I am slightly breaking my usual bracketing style for the sake of brevity.
                ++nc;
                if(c == '\n')
                        ++nl;
                if(c == ' ' || c == '\n' || c == '\t')
                        state = OUT;
                else if(state == OUT) {
                        state = IN;
                        ++nw;
                }
                //Otherwise, move on to the next character
        }
        printf("Line count\t%d\n", nl);
        printf("Word count\t%d\n", nw);
        printf("Character count\t%d\n", nc);

        fclose(pRead);
        return 0;
}
