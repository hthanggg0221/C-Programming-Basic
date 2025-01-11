#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 301

typedef struct Word
{
    char word[MAX_SIZE];
    int count;
} Word;

Word words[300];

void toLowerCase(char *string)
{
    for (int i = 0; string[i]; i++)
        string[i] = tolower(string[i]);
}

int compare(const void *a, const void *b)
{
    Word *word1 = (Word*)a;
    Word *word2 = (Word*)b;
    return strcmp(word1->word, word2->word);
}

int main()
{
    char s[300];
    int wordCount = 0;
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        words[i].word[0] = '\0';
        words[i].count = 0;
    }
    while (fgets(s, sizeof(s), stdin) != NULL)
    {
        int length = strlen(s);

        if (s[length - 1] == '\n') {
            s[length - 1] = '\0';
        }
        char *token = strtok(s, ",;? .\n\t\r");
        while (token != NULL)
        {
            toLowerCase(token);
            int check = 0;
            for (int i = 0; i < wordCount; ++i)
            {
                if (strcmp(token, words[i].word) == 0)
                {
                    words[i].count++;
                    check = 1;
                    break;
                }
            }
            if (!check)
            {
                strcpy(words[wordCount].word, token);
                words[wordCount].count = 1;
                wordCount++;
            }
            token = strtok(NULL, ",;? .\n\t\r");
        }
    }
    
    qsort(words, wordCount, sizeof(Word), compare);

    for (int i = 0; i < wordCount; ++i)
        printf("%s %d\n", words[i].word, words[i].count);

    return 0;
}