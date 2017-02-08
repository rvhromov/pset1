#include <cs50.h>
#include <stdio.h>

int get_height();
void draw_spaces(int height, int i);
void draw_hashes(int i);

int main(void)
{
    // Высота пирамиды
    int height = get_height();
    
    // Рисуем пирамиду
    for(int i = 1; i <= height; i++)
    {
        draw_spaces(height, i);
        draw_hashes(i);
        printf("  ");
        draw_hashes(i);
        printf("\n");
    }
}

int get_height()
{
    int height;
   
    // Запрашиваем высоту, пока не выполнится условие height є [0; 23]
    do 
    {
        printf("Height: ");
        height = get_int(); 
    }
    while(height < 0 || height > 23);
    
    return height;
}

void draw_spaces(int height, int i)
{
    // Рисуем пробелы
    for(int j = height - i; j > 0; j--)
    {
        printf(" ");
    }
}

void draw_hashes(int i)
{
    // Рисуем решетки
    for(int k = 0; k < i; k++)
    {
        printf("#");
    }
}