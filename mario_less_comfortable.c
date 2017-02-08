#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
   
    // ����������� ������, ���� �e ���������� ������� height � [0; 23]
    do 
    {
        printf("Height: ");
        height = get_int(); 
    }
    while(height < 0 || height > 23);
    
    // ���������� ����� (������ ��������)
    for(int i = 1; i <= height; i++)
    {
        // �������
        for(int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        
        // �������
        for(int k = 0; k < (1 + i); k++)
        {
            printf("#");
        }
        
        // ������� �� ����� ������
        printf("\n");
    }
}