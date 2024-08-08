#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct args
{
    char *argv;
    int help;
};

struct args a;

int arguments(int argc, char *argv[])
{
    char word[300];
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "--stdin") == 0 || strcmp(argv[i], "-i") == 0)
            {
                if (fgets(word, sizeof(word), stdin) != NULL)
                {
                    a.argv = strdup(word);
                    a.argv[strcspn(a.argv, "\n")] = '\0';
                }
                break;
            }
            else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
            {
                a.help = 1;
                break;
            }
            else
            {
                a.argv = argv[i];
                break;
            }
        }
        return 1;
    }
    return 0;
}

void encoder(const char word[])
{
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    char enc[] = "nopqrstuvwxyzabcdefghijklm";
    char word_enc[strlen(word) + 1];

    for (int f = 0; f < strlen(word); f++)
    {
        if (word[f] == ' ' || word[f] == '\n')
        {
            word_enc[f] = ' ';
        }
        else if (word[f] == '.')
        {
            word_enc[f] = '.';
        }
        else if (word[f] == ',')
        {
            word_enc[f] = ',';
        }
        else
        {
            char lett = word[f];
            int found = 0;
            for (int i = 0; i < strlen(abc); i++)
            {
                if (lett == abc[i])
                {
                    word_enc[f] = enc[i];
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                word_enc[f] = lett;
            }
        }
    }
    word_enc[strlen(word)] = '\0';
    printf("%s\n", word_enc);
}

int main(int argc, char *argv[])
{
    int i = arguments(argc, argv);

    if (a.help == 1)
    {
        printf("Usa -i para entrada desde stdin\n");
        return 0;
    }
    else if (i == 0)
    {
        printf("No has puesto argumentos\n");
        return 1;
    }

    if (a.argv != NULL)
    {
        encoder(a.argv);
        free(a.argv);
    }
    else
    {
        printf("No se proporcionó un argumento válido\n");
    }

    return 0;
}
