#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum turn{
    horizon = 0,
    vertical
};

int main(void){
    
    int ary[100][100] = {0}; // 목표 2차원 배열
    int i = 0; // 행
    int j = 0; // 열
    int num = 0; // 인풋값
    scanf("%d", &num); // 인풋 받음

    int turn = horizon; // 수평부터 진행
    int count = 1; // 카운트 값.
    int max = num;
    int xdir = 1; // x진행방향
    int ydir = 1; // y진행방향
    while(count<=num*num){
        if(turn == horizon){
            while(){
                ary[i][j] = count;
                j = j+xdir*1;
                count ++;
            }
        xdir *= -1;
        turn = vertical;
        }

        if(turn == vertical){
            while(i<=num){
                ary[i][j] = count;
                i = i+ydir*1;
                count ++;
            }
        ydir *= -1;
        turn = horizon;
        }
    }
    for(int i = 0 ; i <num ; i++){
        for(int j = 0 ; j < num ; j++){
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}
