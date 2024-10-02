#include <TXLib.h>
#include <stdio.h>
#include <math.h>

main()
{
    const int SIZE_Y = 18;
    const int SIZE_X = 45;
    const char text[SIZE_Y][SIZE_X] =  {"My uncle used to be so sound",
                                        "But after falling gravely ill",
                                        "Is craving homage, and has found",
                                        "That could not make a better deal."
                                        "It is for others a good lesson,",
                                        "But what a boredom is the session:",
                                        "To watch a sick man day and night",
                                        "And do not make a step aside!",
                                        "What mean deceitfulness it is:",
                                        "To feign compassion, dose the drugs,",
                                        "To set and fluff the pillows, thus,",
                                        "To entertain a half deceased,",
                                        "To show fake sympathy, then, sigh",
                                        "And think: Oh gosh, when will you die!",
                                        "It was what a young rake expected,",
                                        "When dusting post-chaise speeded him,",
                                        "By Zeus’s supreme will elected",
                                        "The only heir of all his kin."};

    int limiter = SIZE_X - 1;
    while (limiter > 0)      //SIZE_X - 1 раз отправляем max строчку в конец
    {
        ChangePLaceMaxLine(text, limiter);
        limiter--;
    }

    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            printf( "%s", *(text + i*SIZE_X + j))
        }
    }
}



ChangePlaceMaxLine(char* text, int limiter)
{
    for (int i = 0; i < limiter; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            if (text[i][j] > text[i][j+1])      //меняет 2 отличающиеся строки местами
            {
                for (int k = j; k < SIZE_X; k++)
                {
                    storage = *(text + i * SIZE_Y + k);                       //storage = text[i][k]
                    *(text + i * SIZE_Y + k) = *(text + (i+1) * SIZE_Y + k);  //text[i][k] = text[i+1][k]
                    *(text + (i+1) * SIZE_Y + k) = storage;                   //text[i+1][k] = storage
                    break;
                }
            }
        }
    }
}

