// simpleMovingAverage2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

const int WINDOW_NUM = 5;

//データを平滑化する関数
double smoothing(short* data, short newData) {
    double ave = 0.0;

    //平滑化処理
    for (int i = 0; i < (WINDOW_NUM-1); i++) {
        data[(WINDOW_NUM-1) - i] = data[(WINDOW_NUM-1) - i - 1];
    }
    data[0] = newData;

    //配列更新
    for (int i = 0; i < WINDOW_NUM; i++) {
        ave += data[i];
    }
    ave /= WINDOW_NUM;

    return ave;
}

int main()
{
    short data[3][WINDOW_NUM] = {
        {5,7,9,10,3},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };


    printf("移動平均=%.3f\n", smoothing(data[0], 10));
    printf("移動平均=%.3f\n", smoothing(data[0], 10));
    printf("移動平均=%.3f\n", smoothing(data[0], 10));
    printf("移動平均=%.3f\n", smoothing(data[0], 10));
    printf("移動平均=%.3f\n", smoothing(data[0], 10));

    while (1);
    
}
