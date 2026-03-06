#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int cmpfunc(const void *a, const void *b) { //https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm godbless
    return (*(int *)a - *(int *)b);
}

int commandQuestion(int from, int to, int *arr) {
    
    int lenght;
    lenght = ((to - from) + 1);
    int *array_compare = (int *) malloc( sizeof (*array_compare) * lenght);
    int compare_i;
    compare_i = 0;

    for (int i = from; i <= to; i++) {
        array_compare[compare_i++] = arr[i];
    }

    qsort(array_compare, lenght, sizeof(int), cmpfunc);

    int j = 1;
    for ( int g = 0; g <= lenght-2; g++) {
        if(array_compare[g] != array_compare[g+1]) {
            j++;
        }
    }
    printf("> %d / %d\n", j, lenght);
    free(array_compare);
    return 1;
}

int main() {
    int array_main[1000000]; //Normally id create a dynamic array that doubles its capacity whenever needed but this time we dont have any memory limit so its free for all.
    char command[2]; //Array for the operation whether it is "+ " or "? "
    int num, from, to, i;
    bool continuous_input = true;
    i = 0;
    int array_unique_or_not[1000000];
    printf("Requests:\n");

    while(continuous_input == true) {
         ///////////////END OF INPUT////////////////
        command[0] = getchar(); //EOF Standart 
        if (command[0] == EOF) {
            return 1;
        }

        if(command[0] == '\n' || command[0] == ' ') { //NewLine and Whitespace leads to EOF
            command[0] = getchar();
        if (command[0] == EOF) {
            return 1;
        }}
        ///////////////////////////////////////////

        switch(command[0]) {
        case '+':
            if(scanf(" %d", &num) != 1) { printf("Invalid input.\n"); return 0; }
            array_main[i] = num;
            i++;
            array_unique_or_not[num] += 1;
            break;

        case '?':
            if(scanf(" %d %d", &from, &to) != 2 || from > to || from < 0 || to > (i - 1)) { printf("Invalid input.\n"); return 0; }
            break;

        default:
            printf("Invalid input.\n"); 
            return 0;
    }//Switch Bracket End

    if(num > 99999 || num < 0 || i > 1000000) { printf("Invalid input.\n"); return 0; }
    if(command[0] != '?' && command[0] != '+') { printf("Invalid input.\n"); return 0; }

    if(command[0] == '?'){
            commandQuestion(from, to, array_main);
        }

    if(command[0] == '+'){
        if (array_unique_or_not[num] == 1) { printf("> first visit\n"); }
        if (array_unique_or_not[num] > 1) { printf("> visit #%d\n", array_unique_or_not[num]); }

    } //if(command[0] == '+') Bracket
    } //Continuous Input Bracket
    return 0;
}
