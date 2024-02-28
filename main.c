
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define USE_BUSY_SLEEPING
#define BUF_SIZE 65536

bool isFeatureEnabled (const int argc, char *argv[], char FeatureName[]) {
    for (int CurrentArg = 1; CurrentArg < argc; ++CurrentArg) {
        if (strcmp(argv[CurrentArg],FeatureName) != 0){
            return true;
        }
    }

    return false;
}

int count_lines(FILE* file)
{
    char buf[BUF_SIZE];
    int counter = 0;
    for(;;)
    {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file))
            return -1;

        int i;
        for(i = 0; i < res; i++)
            if (buf[i] == '\n')
                counter++;

        if (feof(file))
            break;
    }

    return counter;
}


void sleep_for_millisecs(unsigned Millisecs) {
    printf("%s%d%s\n", "Sleeping for ", Millisecs, " milliseconds");
    fflush(stdout);
    sleep(1);
}

static bool __attribute__((feature_variable("F1"))) F1;
static bool __attribute__((feature_variable("F2"))) F2;
static bool __attribute__((feature_variable("F3"))) F3;

int main(const int argc, char *argv[])
{

    F1 = isFeatureEnabled(argc, argv, "--f1");
    F2 = isFeatureEnabled(argc, argv, "--f2");
    F3 = isFeatureEnabled(argc, argv, "--f3");





    if (argc < 1) {
        printf("Please specify a file");
    }
    const char* filename = "";


    for (int CurrentArg = 1; CurrentArg < argc; ++CurrentArg) {
        char* argument = argv[CurrentArg];
        if (strstr(argument, ".txt") != NULL) {
            filename = argument;
        }
    }



    FILE *fp = fopen(filename,"r");

    int ch=0;
    int lines=1;

    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }



    if (lines % 3 == 0) {
        if (F1) {
            sleep_for_millisecs(375);
        }
        if (F2) {
            sleep_for_millisecs(275);
        }
        if (F3) {
            sleep_for_millisecs(185);
        }
        if (F1 && F2) {
            sleep_for_millisecs(421);
        }
        if (F1 && F2 || F3) {
            sleep_for_millisecs(267);
        }
        if (F1 || F2 || F3) {
            sleep_for_millisecs(180);
        }
        if (F1 || F2 && F3) {
            sleep_for_millisecs(264);
        }
    }
    if (lines % 2 == 0) {
        if (F1) {
            sleep_for_millisecs(250);
        }
        if (F2) {
            sleep_for_millisecs(123);
        }
        if (F3) {
            sleep_for_millisecs(321);
        }
        if (F1 && F2) {
            sleep_for_millisecs(140);
        }
        if (F1 && F2 || F3) {
            sleep_for_millisecs(247);
        }
        if (F1 || F2 || F3) {
            sleep_for_millisecs(362);
        }
        if (F1 || F2 && F3) {
            sleep_for_millisecs(126);
        }
    }

    if (lines % 2 != 0 && lines % 3 != 0) {
        if (F1) {
            sleep_for_millisecs(321);
        }
        if (F2) {
            sleep_for_millisecs(378);
        }
        if (F3) {
            sleep_for_millisecs(295);
        }
        if (F1 && F2) {
            sleep_for_millisecs(185);
        }
        if (F1 && F2 || F3) {
            sleep_for_millisecs(289);
        }
        if (F1 || F2 || F3) {
            sleep_for_millisecs(164);
        }
        if (F1 || F2 && F3) {
            sleep_for_millisecs(290);
        }
    }


    if (F1) {
        sleep_for_millisecs(200);
    }

    sleep_for_millisecs(111);

    if (F2) {
        sleep_for_millisecs(300);
    }

    sleep_for_millisecs(111);

    if (F3) {
        sleep_for_millisecs(400);
    }

    sleep_for_millisecs(111);

    if (F1 && F2) {
        sleep_for_millisecs(120);
    }

    sleep_for_millisecs(111);

    if (F1 || F2) {
        sleep_for_millisecs(210);
    }

    sleep_for_millisecs(111);

    if (F1 && F2 || F3) {
        sleep_for_millisecs(132);
    }

    sleep_for_millisecs(111);

    if (F1 || F2 && F3) {
        sleep_for_millisecs(213);
    }

    sleep_for_millisecs(111);

    if (F1 && F2 && F3) {
        sleep_for_millisecs(123);
    }

    sleep_for_millisecs(111);

    if (F1 || F2 || F3) {
        sleep_for_millisecs(321);
    }

    return 0;
}


