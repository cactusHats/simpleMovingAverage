// simpleMovingAverage.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

const int WINDOW_NUM = 5;
float data[WINDOW_NUM] = { 0,0,0,0,0 };

float simpleMovingAverage(float newData) {

    float ave = 0.0f;

    //--- キュー内の値を移動させる ---
    for (int i = 0; i < (WINDOW_NUM - 1); i++) {
        data[(WINDOW_NUM - 1) - i] = data[(WINDOW_NUM - 1) - i - 1];
    }
    data[0] = newData;

    //--- 平均計算 ---
    ave = 0.0f;
    for (int i = 0; i < WINDOW_NUM; i++) {
        ave += data[i];
    }
        
    ave /= WINDOW_NUM; //<<平滑化された値

    return ave;
}

int main()
{
    printf("移動平均=%.3f\n", simpleMovingAverage(10));
    printf("移動平均=%.3f\n", simpleMovingAverage(10));
    printf("移動平均=%.3f\n", simpleMovingAverage(10));
    printf("移動平均=%.3f\n", simpleMovingAverage(10));
    printf("移動平均=%.3f\n", simpleMovingAverage(10));
    
    while (1);
}