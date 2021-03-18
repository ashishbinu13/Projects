#include <stdio.h>
#include <iostream>
#include<math.h>


int main()
{

    //declaring variables to store the number and for counting
    long long num, temp;
    int count, first_num =0, s_num = 0;

    //loop to check if the decalred value follows the rules
    do
    {
        std::cout<< "Number: "<<std::endl;
        std::cin>>num;
    }
    //loop keeps going till a valid number is entered
    while (num<0);


    temp = num;
    count = 0;

    //counting the number of digits in the value entered
    while (temp != 0)
    {
        temp = temp / 10;
        count ++;
    }

    //calculating the first and second digits of the number
    
    first_num = num / pow(10, (count - 1));
    s_num = num / pow(10, (count - 2));

    //calculating the first sum as per the rules
    int rem = 0, rem2 = 0, sum1 = 0;
    temp = num / 10;

    while (temp != 0)
    {
        rem = temp % 10;
        rem2 = rem * 2;

        //adding the digits of two digit numbers
        if ((rem2 / 10) != 0)
        {
            rem2 = (rem2 % 10) + (rem2 / 10);
        }

        sum1 = sum1 + rem2;
        temp /= 100;
    }

    //calculating second sum as per the rules
    rem = 0;
    int sum2 = 0;
    temp = num;

    while (temp != 0)
    {
        rem = temp % 10;
        sum2 = sum2 + rem;
        temp /= 100;
    }

    //calculating total sum
    int sum = sum1 + sum2;

    //checking if sum is valid and the type of the valid card

    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
    }

    else if(std::isdigit(num) == false)
    {
         printf("INVALID\n");
    }

    else
    {
        //condition for AMEX
        if (first_num == 3)
        {
            if (count != 15)
            {
                printf("INVALID\n");
            }

            else if (s_num == 34 || s_num == 37)
            {
                printf("AMEX\n");
            }
    
            else
            {
                printf("INVALID\n");
            }
        }

        //condition for VISA
        if (first_num == 4)
        {
            if ((count != 16) && (count != 13))
            {
                printf("INVALID\n");
            }
            else
            {
                printf("VISA\n");
            }
        }

        //condition for MASTERCARD
        if (first_num == 5)
        {
            if (count != 16)
            {
                printf("INVALID\n");
            }

            else if (s_num == 51 || s_num == 52 ||
                s_num == 53 || s_num == 54 ||
                s_num == 55)
            {
                printf("MASTERCARD\n");
            }
           
            else
            {
                printf("INVALID\n");
            }
        }
    }
    return 0;
}