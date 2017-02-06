#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
   
    // Запрашиваем высоту, пока не выполнится условие height є [0; 23]
    do 
    {
        printf("Height: ");
        height = get_int(); 
    }
    while(height < 0 || height > 23);
    
    // Количество строк (высота пирамиды)
    for(int i = 1; i <= height; i++)
    {
        // Пробелы для левой части пирамиды
        for(int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        
        // Решетки для левой части пирамиды
        for(int k = 0; k < i; k++)
        {
            printf("#");
        }
        
        // Пробелы между частями пирамиды
        printf("  ");
        
        // Решетки для правой части пирамиды
        for(int l = 0; l < i; l++)
        {
            printf("#");
        }
        
        // Переход на новую строку
        printf("\n");
    }
}