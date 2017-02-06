#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
   
    // Запрашиваем высоту, пока нe выполнится условие height є [0; 23]
    do 
    {
        printf("Height: ");
        height = get_int(); 
    }
    while(height < 0 || height > 23);
    
    // Количество строк (высота пирамиды)
    for(int i = 1; i <= height; i++)
    {
        // Пробелы
        for(int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        
        // Решетки
        for(int k = 0; k < (1 + i); k++)
        {
            printf("#");
        }
        
        // Переход на новую строку
        printf("\n");
    }
}