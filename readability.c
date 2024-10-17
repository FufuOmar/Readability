#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int countLetters(string t, const int a);
int countWords(string t, const int a);
int countSentences(string t, const int a);
float avgNumLetters(int letters, int words);
float avgNumSentences(int words, int sentences);
int index(float L, float S);

int main()
{
    string text = get_string("Text: ");
    const int textLENGTH = strlen(text);

    int numLetters = countLetters(text, textLENGTH);

    int numWords = countWords(text, textLENGTH);

    int numSentences = countSentences(text, textLENGTH);


    //printf("Grade %i\n", );
    int gradeLevel = index(avgNumLetters(numLetters, numWords), avgNumSentences(numWords, numSentences));
    if (gradeLevel < 1)
    printf("Before Grade 1\n");
    else if (gradeLevel >= 16)
    printf("Grade 16+\n");
    else
    printf("Grade %i\n", gradeLevel);
}

int countLetters(string t, const int a)
{
    int letterCount = 0;

    for(int i = 0; i < a; i++)
    {
        if (isalpha(t[i]))
        letterCount++;
    }
    return letterCount;
}

int countWords(string t, const int a)
{
    int wordCount = 1;

    for(int i = 0; i < a; i++) //counts white space, which equals word
    {
        if (t[i]==' ')
        wordCount++;
    }
    return wordCount;
}

int countSentences(string t, const int a)
{
    int sentenceCount = 0;
    for(int i = 0; i < a; i++) //counts white space, which equals word
    {
        if (t[i]=='.' || t[i]=='!' || t[i]=='?')
        sentenceCount++;
    }
    return sentenceCount;
}

float avgNumLetters(int letters, int words)
{
    return (letters/(float)words)*100;
}

float avgNumSentences(int words, int sentences)
{
    return (sentences/(float)words)*100;
}

int index(float L, float S){
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int grade1 = round(grade);
    return grade1;
}

