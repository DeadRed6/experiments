#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct deck {
        char suit[10];
        int number;
        short used;
} aDeck;

void shuffle(aDeck *); //passing by reference to alter the state outside of the scope it was declared in.

int main(void) {
        int x, y;
        aDeck myDeck[52]; //Creates an array, of type aDeck, and name myDeck.

        srand(time(NULL)); //Sets the current time as the seed for future pseudorandom generation.

        //Fill out the struct entries of the array with data, creating a sorted deck of cards.
        for(x = 0; x < 4; x++) {
                for(y = 0; y < 13; y++) {
                        switch(x) {
                                case 0:
                                        strcpy(myDeck[y].suit, "Diamonds");
                                        myDeck[y].number = y;
                                        myDeck[y].used = 0;
                                        break;
                                case 1:
                                        strcpy(myDeck[y + 13].suit, "Clubs");
                                        myDeck[y + 13].number = y;
                                        myDeck[y + 13].used = 0;
                                        break;
                                case 2:
                                        strcpy(myDeck[y + 26].suit, "Hearts");
                                        myDeck[y + 26].number = y;
                                        myDeck[y + 26].used = 0;
                                        break;
                                case 3:
                                        strcpy(myDeck[y + 39].suit, "Spades");
                                        myDeck[y + 39].number = y;
                                        myDeck[y + 39].used = 0;
                                        break;
                        }
                }
        }

        shuffle(myDeck); //The array is passed in by reference. Since an array name is a pointer, we don't need to use &

        return 0;
}

//I strongly dislike this method of shuffling. It can be improved, but for the moment it works as an exercise of understanding
void shuffle(aDeck *thisDeck) {
        int x;
        int iRand;
        int found = 0;
        system("clear"); //Send the 'clear' command to the system, as a bit of a visual gimmick

        printf("\nYour five cards are: \n\n");
        while(found < 5) {
                iRand = rand() % 52; //Generates a random integer between 0 and 51. (conveniently the indices of the array)
                if(!thisDeck[iRand].used) {
                        switch(thisDeck[iRand].number) {
                                case 12:
                                        printf("Ace of %s\n", thisDeck[iRand].suit);
                                        break;
                                case 11:
                                        printf("King of %s\n", thisDeck[iRand].suit);
                                        break;
                                case 10:
                                        printf("Queen of %s\n", thisDeck[iRand].suit);
                                        break;
                                case 9:
                                        printf("Jack of %s\n", thisDeck[iRand].suit);
                                        break;
                                default:
                                        printf("%d of %s\n", thisDeck[iRand].number + 2, thisDeck[iRand].suit);
                                        break;
                        }
                        thisDeck[iRand].used = 1;
                        found++;
                }
        }

}
