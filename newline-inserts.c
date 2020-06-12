#include <stdio.h>

int main(int argc, char *argv[]) {
        FILE *pRead;    //File stream for reading
        FILE *pWrite;   //File stream for writing
        char c;         //Buffer for the current character we are reading

        pRead = fopen(*++argv, "r"); //Since argv is a pointer, we can refer to its elements with arithmetic.

        if(pRead == NULL) {
                printf("File opening failed. Check for typos or location errors.");
                return 1;
        }

        if(argc == 3) {
                pWrite = fopen(*++argv, "a"); //Create a stream for the output file.
        } else {
                pWrite = fopen("output.txt", "a"); //Default output filename.
        }

        //Read character by character, until we reach EOF
        while(!feof(pRead) && fscanf(pRead, "%c", &c)) {
                fputc(c, pWrite); //Write to the output file.
                if(c == '.' || c == '?' || c == '!') {
                        fscanf(pRead, "%c", &c);
                        if(!feof(pRead) && c != '\n') {
                                //If the next character is not a newline, write one.
                                fputc('\n', pWrite);
                        }
                }
                //Otherwise, continue to the next character.
        }

        fclose(pRead);
        fclose(pWrite);
        return 0;
}
