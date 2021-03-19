#include<iostream>
#include<ctype.h>
#include<string>

//declaring the function which returns the point
int get_point(char word[]);

int main()
{
    char pl1[16], pl2[16];

    //accepting and storing the input of Player1
    std::cout<< "Player1: ";
    std::cin>> pl1;

    //accepting and storing the input of Player2
    std::cout<< "Player2: ";
    std::cin>> pl2;

    //storing the scores via function call
    int score1 = get_point(pl1);
    int score2 = get_point(pl2);

    //checking if Player1 won 
    if (score1 > score2)
    {
        std::cout<< "Player1 wins!" << std::endl;
    } 

    //checking if Player2 won 
    else if (score1 < score2)
    {
        std::cout<< "Player2 wins!" << std::endl;
    } 

    //checking if it is a Tie 
    else
    {
        std::cout<< "Tie!" << std::endl;
    }
    return 0;

}

//defining the function which returns the total point scored by the player
int get_point(char word[])
{
    int ascii = 0, score = 0;

    //storing the points for each words in an array in order
    int point[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    //loop to find the point for each letter and store it in total
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        ascii = int(toupper(word[i]));

        if ((ascii >= 65) &&  (ascii <= 97))
        {
            score += point[ascii - 65];
        }
    }

    return score;
}
