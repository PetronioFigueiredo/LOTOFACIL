#ifndef LOTOFACIL_H
#define LOTOFACIL_H
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<stdbool.h>
#include<unistd.h>
#include<stdint.h>


typedef struct Lotofacil
{
    unsigned short ID;
    unsigned short guesses[15];
    unsigned short max_hit;
    unsigned short min_hit;
    unsigned int atempt_number;
    unsigned short success;
    struct Lotofacil* next;
}Lotofacil;

/*  TO DO  */
void guesser();
/*  Function to Return an lotofaicl Struct setting all values to ZERO */
Lotofacil * CreateLF();

/*  Function to accelerate the refresh rate of srand() */
void randomize();
/*  Function to pritLotofacil() */
void printLotofacil(Lotofacil* toPrint);

/*  Function to sort a array */
void sortArray(short array[], short size);

/*  Function to add a newLotofacil to a liked list */
void append(Lotofacil* head, Lotofacil* newLink);

/*  Function to Return an array of 15 short ints between 1 and 25 */

int GuessComp(short *fix, short *target, int size); 

/*  Function that sets the min_hit, if newMinHint < target.min_hit */
void maxHit(Lotofacil* target, short new_min_hit);

/*  Function that sets the max_hit, if newMinHint < target.max_hit */
void minHint(Lotofacil* target, short new_max_hit);

/*  Function to incremment the number of thime a Lotofacil have been played */
void atemptINcrement(Lotofacil* incremented);

/*  Function to detect if the guesser() are returning an array that already exists in the LInked list*/
bool isRepeated(Lotofacil* target, short* new_guess);

/*  Function to check if and short already existis in a array */
bool isIn(short number, short size, short* array);

/*  Function to to check and return the number of right gesses */
short numHits();

/*  Function to crete a DataBase of Lotofacil */
void createLotofacilDataFile(char** file_name);

/*  Function to Display the DataBase of Lotofacil */
void displayLotofacilData(FILE* DataBase);

#endif
