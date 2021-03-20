#include <iostream>
#include <string>
#include <ctype.h>

//declaring the functions used to calculate the numbers of letters, words and sentances and the index
int letter_count(char text[]);
int word_count(char text[]);
int sentance_count(char text[]);
int cl_index(int lc, int wc, int sc);

int main()
{

    int l_count, w_count, s_count, index;
    char text[1000];

    // prompting the user for the text
    std::cout << "Text: ";
    std::cin.getline(text, 1000);

    // calling the function to count the number of letters
    l_count = letter_count(text);

    // calling the function to count the number of words
    w_count = word_count(text);

    // calling the function to count the number of sentances
    s_count = sentance_count(text);

    // calling the function to calculate the index
    index = cl_index(l_count, w_count, s_count);


    // checking the conditions to determine the grade of the text
    if (index < 1)
    {
        std::cout<<"Before Grade 1"<<std::endl;
    }

    else if (index < 16)
    {
        std::cout<<"Grade "<<index<<std::endl;
    }

    else
    {
        std::cout<<"Grade 16+"<<std::endl;
    }
   
}


// defining the function to count the number of letters
int letter_count(char text[])
{
    int count = 0;

    //counting letters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count ++;
        }

    }
    return count;
}

// defining the function to count the number of words
int word_count(char text[])
{
    int count = 1;

    //counting words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count ++;
        }

    }
    return count;
}

// defining the function to count the number of sentances
int sentance_count(char text[])
{
    int count = 0;

    //counting sentances
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count ++;
        }

    }
    return count;
}

// declaring the function which calculates the index of the text
int cl_index(int lc, int wc, int sc)
{

    float l = (lc / ((float) wc)) * 100;
    float s = (sc / ((float) wc)) * 100;

    // the Coleman-Liau index equation
    float indx = (0.0588 * l) - (0.296 * s) - 15.8;
    return round(indx);
}