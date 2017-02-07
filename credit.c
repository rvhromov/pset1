#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long cc_number;                // Номер кредитки
    int digit;                          // Текущая цифра номера кредитки
    int fraction_digit = 0;             // Дробная часть числа
    int first_to_last_digits_sum = 0;   // Сумма цифр не умножаемых на 2
    int second_to_last_digits_sum = 0;  // Сумма цифр умножаемых на 2
    int multi_by_two = 0;               // Текущая цифра умноженая на 2
    int total_sum = 0;                  // Общая сумма цифр кредитки после всех действий
    int amount_of_digits = 2;           // Количество цифр в номере кредитки
    long long card_type;                // Тип кредитки
    
    do
    {
        printf("Number: ");
        cc_number = get_long_long();
    }
    while(cc_number < 0);
    
    card_type = cc_number;
    
    while(cc_number > 0)
    {
        // Получаем последнюю цифру номера кредитки
        digit = cc_number % 10;
        // Суммируем
        first_to_last_digits_sum += digit;
        // Переходим на следующею цифру
        cc_number /= 10;

        digit = cc_number % 10;
        multi_by_two = digit * 2;
        
        // Если полученое число состоит из 1 цифры
        if(multi_by_two / 10 == 0)
        {
            // Суммируем
            second_to_last_digits_sum += multi_by_two;
        }
        // Иначе, разделяем число на отдельные цифры и суммируем их
        else
        {
            digit = multi_by_two / 10;
            fraction_digit = multi_by_two % 10;
            second_to_last_digits_sum += digit + fraction_digit;
        }
        
        // Переходим на следующею цифру
        cc_number /= 10;
    }
    
    total_sum = first_to_last_digits_sum + second_to_last_digits_sum;
    
    // Получаем 2 первых цифры и количество цифр кредитки
    while(card_type > 100)
    {
        card_type /= 10;
        amount_of_digits++;
    }
    
    // Проверяем является ли карточка действительной
    if(total_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    
    // Проверяем, что это карта AmericanExpress
    if(amount_of_digits == 15 && (card_type == 34 || card_type == 37))
    {
        printf("AMEX\n");
    }
    
    // Проверяем, что это карта MasterCard
    if(amount_of_digits == 16 && (card_type == 51 || card_type == 52 || card_type == 53 || card_type == 54 || card_type == 55))
    {
        printf("MASTERCARD\n");    
    }
    
    // Проверяем, что это карта Visa
    if((amount_of_digits == 13 || amount_of_digits == 16) && card_type / 10 == 4)
    {
        printf("VISA\n");
    }
}