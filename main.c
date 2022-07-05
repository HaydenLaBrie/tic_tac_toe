#include <stdio.h>
#include <stdlib.h>
char** print_board();

int main() {
    char** arr = print_board();
    printf("%s\n", *(arr+0));
    printf("%s\n", *(arr+1));
    printf("%s\n", *(arr+2));
    return 0;
}
char** print_board(){
    int y = 3, x = 11;
    char** arr = (char**)malloc(y*sizeof(char*)); // arr is the address of the address of the character, we clear 3 spots so that it can hold 3 addresses
    for(int i = 0; i < y; i++){
        arr[i] = (char*)malloc(x*sizeof(char)); // *arr is the address of the elements, we clear 11 spots that the pointer can hold
    } //thus we can say that each pointer can point to 11 elements and we can hold 3 pointers, 3*11=33
    *(*(arr + 0) + 0) = ' '; *(*(arr + 0) + 1) = ' '; *(*(arr + 0) + 2) = ' '; *(*(arr + 0) + 3) = '|'; *(*(arr + 0) + 4) = ' '; *(*(arr + 0) + 5) = ' '; *(*(arr + 0) + 6) = ' '; *(*(arr + 0) + 7) = '|';
            *(*(arr + 0) + 8) = ' '; *(*(arr + 0) + 9) = ' '; *(*(arr + 0) + 10) = '\0';

    *(*(arr + 1) + 0) = ' '; *(*(arr + 1) + 1) = ' '; *(*(arr + 1) + 2) = ' '; *(*(arr + 1) + 3) = '|'; *(*(arr + 1) + 4) = ' '; *(*(arr + 1) + 5) = ' '; *(*(arr + 1) + 6) = ' '; *(*(arr + 1) + 7) = '|';
            *(*(arr + 1) + 8) = ' '; *(*(arr + 1) + 9) = ' '; *(*(arr + 1) + 10) = '\0';

    *(*(arr + 2) + 0) = ' '; *(*(arr + 2) + 1) = ' '; *(*(arr + 2) + 2) = ' '; *(*(arr + 2) + 3) = '|'; *(*(arr + 2) + 4) = ' '; *(*(arr + 2) + 5) = ' '; *(*(arr + 2) + 6) = ' '; *(*(arr + 2) + 7) = '|';
            *(*(arr + 2) + 8) = ' '; *(*(arr + 2) + 9) = ' '; *(*(arr + 2) + 10) = '\0';

    return arr;
}
