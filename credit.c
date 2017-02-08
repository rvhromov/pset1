#include <cs50.h>
#include <stdio.h>

long long get_card_number();
int get_digits_sum(long long cc_number);
void get_type_card(int total_sum, int digits, long long cc_number);

int main(void)
{
    long long cc_number;                // Номер кредитки
    int amount_of_digits = 2;           // Количество цифр в номере кредитки
    int total_sum = 0;                  // Сумма цифр кредитки по алгоритму Луна
    
    cc_number = get_card_number();
    total_sum = get_digits_sum(cc_number);
    
    // Получаем 2 первых цифры и количество цифр кредитки
    // для подальшего определения типа кредитки
    while(cc_number > 100)
    {
        cc_number /= 10;
        amount_of_digits++;
    }
    
    get_type_card(total_sum, amount_of_digits, cc_number);
}

long long get_card_number()
{
    long long cc_number;    // Номер кредитки
    
    do
    {
        printf("Number: ");
        cc_number = get_long_long();
    }
    while(cc_number < 0);
    
    return cc_number;
}

int get_digits_sum(long long cc_number)
{
    int digit;                          // Текущая цифра номера кредитки
    int fraction_digit = 0;             // Дробная часть числа
    int first_to_last_digits_sum = 0;   // Сумма цифр не умножаемых на 2
    int second_to_last_digits_sum = 0;  // Сумма цифр умножаемых на 2
    int multi_by_two = 0;               // Текущая цифра умноженая на 2
    
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
    
    return first_to_last_digits_sum + second_to_last_digits_sum;
}

void get_type_card(int total_sum, int digits, long long cc_number)
{
    // Проверяем является ли карточка действительной
    if(total_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    
    // Проверяем, что это карта AmericanExpress
    if(digits == 15 && (cc_number == 34 || cc_number== 37))
    {
        printf("AMEX\n");
    }
    
    // Проверяем, что это карта MasterCard
    if(digits == 16 && (cc_number == 51 || cc_number == 52 || cc_number == 53 || cc_number == 54 || cc_number == 55))
    {
        printf("MASTERCARD\n");    
    }
    
    // Проверяем, что это карта Visa
    if((digits == 13 || digits == 16) && cc_number / 10 == 4)
    {
        printf("VISA\n");
    }
}