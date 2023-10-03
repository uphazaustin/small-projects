#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_number(string number);

int main(void)
{
    string number;
    do
    {
        number = get_string("Number:");

    }
    while(!check_number(number));

        int N = strlen(number);
        int sum_2 = 0;
        int sum = 0;
        char n_1;
        char n_2;
        int num;
        int num_2;
        if (N % 2 > 0)
        {
            for (int i = 0 ; i < N ; i += 2 )
            {
                n_1 = number[i];
                num = number[i] - '0';
                if (i == 0)
                {
                    sum += num;
                }
                else{

                num_2 = number[i - 1] - '0';
                if ((2*num_2) % 10 > 0)
                {
                    num_2 = 2*num_2;
                    int num_new_2 = (num_2 % 10) + (num_2 / 10);
                    sum_2 += num_new_2;
                }
                else{

                sum_2 += 2* (num_2);


                }

                sum += num;

                }
            }

        }
        if (N % 2 == 0)
        {
            for (int i = 0 ; i < N ; i += 2 )
            {
                num_2 = number[i] - '0';

                if ((2*num_2) >= 10)
                {
                    num_2 = 2*num_2;
                    int num_new_2 = (num_2 % 10) + (num_2 / 10);
                    sum_2 += num_new_2;
                }
                else{

                sum_2 += 2* (num_2);

                }

                num = number[i + 1] - '0';
                sum_2 += num;

                }

            }



        if ((sum + sum_2) % 10 == 0 )
        {
            int first_digit = number[0] - '0';
            int sec_digit = number[1] - '0';

            switch(first_digit){
                case 4:
                if (strlen(number) == 13 || strlen(number) == 16)
                {
                printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
                case 5:
                if ((sec_digit == 1 || sec_digit == 2 || sec_digit == 3 || sec_digit == 4 || sec_digit == 5) && strlen(number) == 16)
                {
                    printf("MASTERCARD\n");
                }
                else{
                printf("INVALID\n");
                }
                break;
                case 3:
                if ((sec_digit == 4 || sec_digit == 7) && strlen(number) == 15)
                {
                    printf("AMEX\n");
                    break;
                }
                else{
                printf("INVALID\n");
                break;
                }
                default:
                printf("INVALID\n");
                break;
                }
        }
        else
        {
        printf("INVALID\n");
        }

        return 0;
    }

bool check_number(string number)
{
    int digit;
    int length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(number[i]))
        {
            return false;
            break;
        }
    }
    return true;
}
