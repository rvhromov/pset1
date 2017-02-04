#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int coins;
    int counter = 0;
    
    do
    {
        printf("O hai! How much change is owed?\n");
        change = get_float();
    }
    while(change < 0);
    
    // Переводим в центы (количество монет)
    coins = (int)round(change * 100);
    
    // Жадный алгоритм
    while(coins != 0)
    {
        if(coins >= 25)
        {
            counter++;
            coins -= 25;
        }
        else if(coins >= 10)
        {
            counter++;
            coins -= 10;
        }
        else if(coins >= 5)
        {
            counter++;
            coins -= 5;
        }
        else if(coins >= 1)
        {
            counter++;
            coins -= 1;
        }
    }
    
    printf("%i\n", counter);
}