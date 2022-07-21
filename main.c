#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char** make_board();
void print_board(char**);
int goes_first();
int put_x(int, char**);
int put_o(int, char**);
int cpu_rng();
int check_winner(char**);
int main() {
    char** arr = make_board();
    printf("Start of game. Board is empty. You are X. Computer is O\n");
    print_board(arr);
    int go = goes_first();
    int spot = -1;
    int counter = 0;
    while(counter < 9 && check_winner(arr) == 0){
        if(go == 1){
            //player goes first
            printf("...........................\n");
            printf("Your turn, pick spot: ");
            scanf("%d", &spot);//player chooses where to put x
            put_x(spot, arr);
            print_board(arr);
            go--;
        }
        else{
            printf("...........................\n");
            printf("Computers turn\n");
            spot = cpu_rng();
            int found = -1;
            if(put_o(spot, arr) == 0){
                found = 1;
            }
            else{
                found = 0;
            }
            int diff = 1;
            while(found == 0){
                if(put_o(spot + diff, arr) == 0){
                    found = 1;
                }
                else if(put_o(spot - diff, arr) == 0){
                    found = 1;
                }
                else{
                    ;
                }
                diff++;
            }
            print_board(arr);
            go++;
        }
        counter++;
    }
    printf("...........................\n");
    if(check_winner(arr) == 1){
        printf("You won!\n");
    }
    else if(check_winner(arr) == 2){
        printf("You lost :(\n");
    }
    else{
        printf("Tie!\n");
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

int put_x(int x, char** arr){
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

int put_o(int x, char** arr){
    if(x == 1 && *(*(arr + 0) + 1) == '1'){
        *(*(arr + 0) + 1) = 'O';
        return 0;
    }
    else if(x == 2 && *(*(arr + 0) + 5) == '2'){
        *(*(arr + 0) + 5) = 'O';
        return 0;
    }
    else if(x == 3 && *(*(arr + 0) + 9) == '3'){
        *(*(arr + 0) + 9) = 'O';
        return 0;
    }
    else if(x == 4 && *(*(arr + 1) + 1) == '4'){
        *(*(arr + 1) + 1) = 'O';
        return 0;
    }
    else if(x == 5 && *(*(arr + 1) + 5) == '5'){
        *(*(arr + 1) + 5) = 'O';
        return 0;
    }
    else if(x == 6 && *(*(arr + 1) + 9) == '6'){
        *(*(arr + 1) + 9) = 'O';
        return 0;
    }
    else if(x == 7 && *(*(arr + 2) + 1) == '7'){
        *(*(arr + 2) + 1) = 'O';
        return 0;
    }
    else if(x == 8 && *(*(arr + 2) + 5) == '8'){
        *(*(arr + 2) + 5) = 'O';
        return 0;
    }
    else if(x == 9 && *(*(arr + 2) + 9) == '9'){
        *(*(arr + 2) + 9) = 'O';
        return 0;
    }
    else{
        return 1;
    }
}

int cpu_rng(){
    srand(time(0));
    int num = rand() % 10;
    return num;
}

int check_winner(char** arr){ //no solution = 0, x wins = 1, o wins = 2
    //top horizontal
    if(*(*(arr + 0) + 1) == 'X' && *(*(arr + 0) + 5) == 'X' && *(*(arr + 0) + 9) == 'X'){
        return 1;
    }
    else if(*(*(arr + 0) + 1) == 'O' && *(*(arr + 0) + 5) == 'O' && *(*(arr + 0) + 9) == 'O'){
        return 2;
    }
    //middle horizontal
    else if(*(*(arr + 1) + 1) == 'X' && *(*(arr + 1) + 5) == 'X' && *(*(arr + 1) + 9) == 'X'){
        return 1;
    }
    else if(*(*(arr + 1) + 1) == 'O' && *(*(arr + 1) + 5) == 'O' && *(*(arr + 1) + 9) == 'O'){
        return 2;
    }
    //bottom horizontal
    else if(*(*(arr + 2) + 1) == 'X' && *(*(arr + 2) + 5) == 'X' && *(*(arr + 2) + 9) == 'X'){
        return 1;
    }
    else if(*(*(arr + 2) + 1) == 'O' && *(*(arr + 2) + 5) == 'O' && *(*(arr + 2) + 9) == 'O'){
        return 2;
    }
    //left vertical
    else if(*(*(arr + 0) + 1) == 'X' && *(*(arr + 1) + 1) == 'X' && *(*(arr + 2) + 1) == 'X'){
        return 1;
    }
    else if(*(*(arr + 0) + 1) == 'O' && *(*(arr + 1) + 1) == 'O' && *(*(arr + 2) + 1) == 'O'){
        return 2;
    }
    //middle vertical
    else if(*(*(arr + 0) + 5) == 'X' && *(*(arr + 1) + 5) == 'X' && *(*(arr + 2) + 5) == 'X'){
        return 1;
    }
    else if(*(*(arr + 0) + 5) == 'O' && *(*(arr + 1) + 5) == 'O' && *(*(arr + 2) + 5) == 'O'){
        return 2;
    }
    //right vertical
    else if(*(*(arr + 0) + 9) == 'X' && *(*(arr + 1) + 9) == 'X' && *(*(arr + 2) + 9) == 'X'){
        return 1;
    }
    else if(*(*(arr + 0) + 9) == 'O' && *(*(arr + 1) + 9) == 'O' && *(*(arr + 2) + 9) == 'O'){
        return 2;
    }
    //slope solution
    else if(*(*(arr + 0) + 1) == 'X' && *(*(arr + 1) + 5) == 'X' && *(*(arr + 2) + 9) == 'X'){
        return 1;
    }
    else if(*(*(arr + 0) + 1) == 'O' && *(*(arr + 1) + 5) == 'O' && *(*(arr + 2) + 9) == 'O'){
        return 2;
    }
    else if(*(*(arr + 0) + 9) == 'X' && *(*(arr + 1) + 5) == 'X' && *(*(arr + 2) + 1) == 'X'){
        return 1;
    }
    else if(*(*(arr + 0) + 9) == 'O' && *(*(arr + 1) + 5) == 'O' && *(*(arr + 2) + 1) == 'O'){
        return 2;
    }
    //no solution
    else
        return 0;
}