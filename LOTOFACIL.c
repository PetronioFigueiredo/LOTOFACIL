#include"LOTOFACIL.h"

/*  CONSTANTS */

/*  Function to Return an lotofaicl Struct setting all values to ZERO */
Lotofacil * CreateLF()
{
    Lotofacil*  newLotofacil = malloc(sizeof(Lotofacil));
    newLotofacil->ID = 0;

    for(int i = 0; i < 15; i++)
        newLotofacil->guesses[i] = 0;

    newLotofacil->max_hit = 0;
    newLotofacil->min_hit = 0;
    newLotofacil->atempt_number = 0;
    newLotofacil->success = 0;
    newLotofacil->next = NULL;

    return newLotofacil;


}

/*  Function to add a newLotofacil to a liked list */

void append(Lotofacil* head, Lotofacil* newLink)
{
    Lotofacil* temp = head;
    Lotofacil* toAppend = newLink;
    while(temp->next != NULL)
    {
        temp = temp->next;

    }

    temp->next = toAppend;

    
}

/*  Function to jpritLotofacil() */
void printLotofacil(Lotofacil* toPrint)
{
    printf("Lotofacil ID: %d\n", toPrint->ID);
    printf("GUESSES:");
    int i, j , h;
    h = 0;
    for(j = 0;j < 3; j++)
    {
        for(i =0 ; i < 5; i++, h++)
        {
         printf(" [%02d]", toPrint->guesses[h]);

        }
        printf("\n\t");
    }
    printf("\n");
    printf("MAX HIT: %d | MIN HIT: %d\n", toPrint->max_hit, toPrint->min_hit);
    printf("SUCCESS TIMES: %d\n",toPrint->success);
    printf("-----------------------------------------\n");
}
/*  Function to Return an array of 15 random short ints between 1 and 25 */
void randomize()
{
    uint32_t seed = 0;
    FILE* devrnd =fopen("/dev/random", "r");
    fread(&seed, 4,1, devrnd);
    fclose(devrnd);
    srand(seed);
}
void guesser(unsigned short*array)
{
    randomize();//refresh the seed of srand()
    int i;
    unsigned short x;

    for(i = 0; i < 15; ++i)
        array[i] = 0;
    for(i = 0; i < 15; ++i)
    {
        x = rand() % 25 + 1;
        if(isIn(x ,15 ,array))
        {
            i--;
            continue;
        }
        else
        {
            array[i] = x;
        }
    }
    sortArray(array, 15);

}

/*  Function to sort a array */
void sortArray(short array[], short size)
{
    for(int i =0; i < size -1; i++)
    {
        for(int j = 0; j < size -i -1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/*  Function to check the number of correct gesses in a Lotofacil.Guesses[array] */

int GuessComp(short fix[15], short target[15], int size)
{
    int hit_count = 0;
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(fix[i] == target[j]) hit_count++;
        }
    }

    return hit_count;

}

/*  Function that sets the min_hit, if newMinHint < target.min_hit */
void maxHit(Lotofacil* target, short new_min_hit)
{
    if (target->min_hit > new_min_hit)
        target->min_hit = new_min_hit;
}

/*  Function that sets the max_hit, if newMinHint < target.max_hit */
void minHint(Lotofacil* target, short new_max_hit)
{
    if (target->max_hit < new_max_hit)
        target->max_hit = new_max_hit;
}


/*  Function to incremment the number of thime a Lotofacil have been played */
void atemptINcrement(Lotofacil* incremented)
{
    incremented->atempt_number = incremented->atempt_number + 1;
}


/*  Function to detect if the guesser() are returning an array that already exists in the LInked list*/
bool isRepeated(Lotofacil* target, short* new_guess)
{
}

/*  Function to check if and short already existis in a array */
bool isIn(short number, short size, short* array)
{
    /*  temporary counter to debug */
    for(int i =0; i < size; i++)
    {
        if(array[i] == number) return true;
    }
    return false;

}

/*  Function to to check and return the number of right gesses */
short numHits()
{
}

/*  Function to crete a DataBase of Lotofacil */
void createLotofacilDataFile(char** file_name)
{

}
