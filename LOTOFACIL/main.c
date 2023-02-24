#include "LOTOFACIL.h"

int main()
{
    system("clear");
    Lotofacil* head;
    head = CreateLF();
    guesser(head->guesses);
    append(head, CreateLF());
    guesser(head->next->guesses);

    printLotofacil(head);
    printLotofacil(head->next);

    printf("Number of number reapeated between structs: %d\n", GuessComp(head->guesses, head->next-> guesses,15));
    printf("Number of hit between games: %d", GuessComp(head->guesses, head->next->guesses,15));

    return 0;
}
