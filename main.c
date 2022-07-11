//need to make it switch between user and computer untill a winner or all spots are taken
//need to create the computer pick a spot, simple random seeded by time
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char** make_board();
void print_board(char**);
int goes_first();
int change_map(int, char**);

int main() {
    char** arr = make_board();
    print_board(arr);
    int go = goes_first();
    int spot = -1;
    if(go == 1){
        //player goes first
        printf("You are X! Enter where you would like to place your X: ");
        scanf("%d", &spot);//player chooses where to put x
        change_map(spot, arr);
        print_board(arr);
    }
    else{
        //computer goes first
    }
    return 0;
}
char** make_board(){
    int y = 3, x = 11;
    char** arr = (char**)malloc(y*sizeof(char*)); // arr is the address of the address of the character, we clear 3 spots so that it can hold 3 addresses
    for(int i = 0; i < y; i++){
        arr[i] = (char*)malloc(x*sizeof(char)); // *arr is the address of the elements, we clear 11 spots that the pointer can hold
    } //thus we can say that each pointer can point to 11 elements and we can hold 3 pointers, 3*11=33
    *(*(arr + 0) + 0) = ' '; *(*(arr + 0) + 1) = '1'; *(*(arr + 0) + 2) = ' '; *(*(arr + 0) + 3) = '|'; *(*(arr + 0) + 4) = ' '; *(*(arr + 0) + 5) = '2'; *(*(arr + 0) + 6) = ' '; *(*(arr + 0) + 7) = '|';
            *(*(arr + 0) + 8) = ' '; *(*(arr + 0) + 9) = '3'; *(*(arr + 0) + 10) = '\0';

    *(*(arr + 1) + 0) = ' '; *(*(arr + 1) + 1) = '4'; *(*(arr + 1) + 2) = ' '; *(*(arr + 1) + 3) = '|'; *(*(arr + 1) + 4) = ' '; *(*(arr + 1) + 5) = '5'; *(*(arr + 1) + 6) = ' '; *(*(arr + 1) + 7) = '|';
            *(*(arr + 1) + 8) = ' '; *(*(arr + 1) + 9) = '6'; *(*(arr + 1) + 10) = '\0';

    *(*(arr + 2) + 0) = ' '; *(*(arr + 2) + 1) = '7'; *(*(arr + 2) + 2) = ' '; *(*(arr + 2) + 3) = '|'; *(*(arr + 2) + 4) = ' '; *(*(arr + 2) + 5) = '8'; *(*(arr + 2) + 6) = ' '; *(*(arr + 2) + 7) = '|';
            *(*(arr + 2) + 8) = ' '; *(*(arr + 2) + 9) = '9'; *(*(arr + 2) + 10) = '\0';

    return arr;
}

void print_board(char** arr){
    printf("%s\n", *(arr+0));
    printf("%s\n", *(arr+1));
    printf("%s\n", *(arr+2));
}

int goes_first(){
    srand(time(0));
    if((rand() % 2) == 0){
        //user goes first
        return 1;
    }
    else{
        //computer goes first
        return 0;
    }
}

int change_map(int x, char** arr){
    if(x == 1 && *(*(arr + 0) + 1) == '1'){
        *(*(arr + 0) + 1) = 'X';
        return 0;
    }
    else if(x == 2 && *(*(arr + 0) + 5) == '2'){
        *(*(arr + 0) + 5) = 'X';
        return 0;
    }
    else if(x == 3 && *(*(arr + 0) + 9) == '3'){
        *(*(arr + 0) + 9) = 'X';
        return 0;
    }
    else if(x == 4 && *(*(arr + 1) + 1) == '4'){
        *(*(arr + 1) + 1) = 'X';
        return 0;
    }
    else if(x == 5 && *(*(arr + 1) + 5) == '5'){
        *(*(arr + 1) + 5) = 'X';
        return 0;
    }
    else if(x == 6 && *(*(arr + 1) + 9) == '6'){
        *(*(arr + 1) + 9) = 'X';
        return 0;
    }
    else if(x == 7 && *(*(arr + 2) + 1) == '7'){
        *(*(arr + 2) + 1) = 'X';
        return 0;
    }
    else if(x == 8 && *(*(arr + 2) + 5) == '8'){
        *(*(arr + 2) + 5) = 'X';
        return 0;
    }
    else if(x == 9 && *(*(arr + 2) + 9) == '9'){
        *(*(arr + 2) + 9) = 'X';
        return 0;
    }
    else{
        return 1;
    }
}


