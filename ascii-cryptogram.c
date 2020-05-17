#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void encrypt(char [], int);
void decrypt(char [], int);
void generateKey(int *);

int main(void) {
        char userString[41] = {'\0'};
        int userChoice = 0;
        int rand;

        srand(time(NULL));
        generateKey(&rand);

        while(userChoice != 4) {
                printf("\n\n1\tEncrypt Cleartext\n");
                printf("2\tDecrypt Ciphertext\n");
                printf("3\tGenerate New Key\n");
                printf("4\tQuit Program\n\n");

                scanf("%d", &userChoice);
                switch(userChoice) {
                        case 1:
                                printf("\nEnter cleartext to encrypt: ");
                                scanf("%s", userString);
                                encrypt(userString, rand);
                                break;
                        case 2:
                                printf("\nEnter ciphertext to decrypt: ");
                                scanf("%s", userString);
                                decrypt(userString, rand);
                                break;
                        case 3:
                                printf("\nNew key generated.");
                                generateKey(&rand);
                                break;
                }
        }


        return 0;
}

void encrypt(char cleartext[], int shift) {
        int x = 0;
        while(cleartext[x]) {
                cleartext[x] += shift;
                x++;
        }
        x = 0;
        printf("\nResult is: ");
        while(cleartext[x]) {
                printf("%c", cleartext[x]);
                x++;
        }
}

void decrypt(char ciphertext[], int shift) {
        int x = 0;
        while(ciphertext[x]) {
                ciphertext[x] = ciphertext[x] - shift;
                x++;
        }
        x = 0;
        printf("\nResult is: ");
        while(ciphertext[x]) {
                printf("%c", ciphertext[x]);
                x++;
        }
}

void generateKey(int *key) {
        *key = (rand() % 4) + 1;
}
