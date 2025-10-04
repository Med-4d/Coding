#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void invalid_option(int lng)
{
    if (lng == 1)
    {
        printf("\033[1;31mInvalid Option!\n\033[1;0m\033[1;33mRetry: \033[1;0m");
    }
    else
    {
        printf("\033[1;31mOption invalide!\n\033[1;0m\033[1;33mRefaire: \033[1;0m");
    }
}

int language()
{
    int lng, error;
    printf("\033[1;33m\nLanguage: \033[1;0m\n");
    printf("\n   1) EN\n   2) FR\n\n");
    do
    {
        error = 0;
        scanf("%d", &lng);
        switch (lng)
        {
        case 1:
            break;
        case 2:
            break;
        default:
            printf("\033[1;31mInvalid option!\n\033[1;0m");
            printf("\033[1;33mRetry:\033[1;0m");
            error = 1;
            break;
        }

    } while (error == 1);
    printf("lng in fnc=%d", lng);
    return (lng);
}

void intro_text(int lng)
{
    printf("\n\033[1;32m");
    printf(R"(            ____                           ______   _   _                               
           |  _ \                         |  ____| | | (_)                              
           | |_) |   __ _   ___    ___    | |__    | |  _   _ __    _ __     ___   _ __ 
           |  _ <   / _` | / __|  / _ \   |  __|   | | | | | '_ \  | '_ \   / _ \ | '__|
           | |_) | | (_| | \__ \ |  __/   | |      | | | | | |_) | | |_) | |  __/ | |   
           |____/   \__,_| |___/  \___|   |_|      |_| |_| | .__/  | .__/   \___| |_|   
                                                           | |     | |                  
                                                           |_|     |_|                  )");
    printf("\n\t\t\t\t\t\t\t\t\t\tBy Med Abidi");
    if (lng == 1)
    {
        printf("\033[1;33m\nSelect the base you want to convert from: \033[1;0m");
        printf("\n\n   1) Decimal\n   2) Hexadecimal\n   3) Binary\n   4) Ocatl\n   5) Custom Base\n\n");
    }
    else
    {
        printf("\033[1;33m\nSelectionnez la base a partir de laquelle vous souhaitez convertir: \033[1;0m");
        printf("\n\n   1) Decimal\n   2) Hexadecimal\n   3) Binaire\n   4) Ocatl\n   5) Base Personnalisee\n\n");
    }
}

int read_input_base(int lng)
{
    int input_option, input_base, error;

    do
    {
        scanf("%d", &input_option);
        error = 0;
        switch (input_option)
        {
        case 1:
            input_base = 10;
            break;
        case 2:
            input_base = 16;
            break;
        case 3:
            input_base = 2;
            break;
        case 4:
            input_base = 8;
            break;
        case 5:
            if (lng == 1)
            {
                printf("\033[1;33m\nEnter your custom base (max: 16): \033[1;0m");
            }
            else
            {
                printf("\033[1;33m\nEntrez votre base personnalisee (max: 16): \033[1;0m");
            }

            scanf("%d", &input_base);
            while (input_base < 2 || input_base > 16)
            {
                invalid_option(lng);
                scanf("%d", &input_base);
            }
            break;
        default:
            invalid_option(lng);
            error = 1;
        }
    } while (error == 1);
    return input_base;
}

void clear_input(char *input)
{
    int i = 0;
    for (i = 0; i < 16; i++)
    {
        input[i] = '0';
    }
}

void read_input(char *input, int lng)
{
    if (lng == 1)
    {
        printf("\n\033[1;33mEnter the Number to Convert (max 16 Digits): \033[1;0m");
    }
    else
    {
        printf("\n\033[1;33mEntrez le numero a convertir (max 16 chiffres): \033[1;0m");
    }

    scanf("%s", input);
}

int read_target_base(int lng)
{
    int error, input_option, target_base;
    do
    {
        error = 0;
        scanf("%d", &input_option);
        switch (input_option)
        {
        case 1:
            target_base = 10;
            break;
        case 2:
            target_base = 16;
            break;
        case 3:
            target_base = 2;
            break;
        case 4:
            target_base = 8;
            break;
        case 5:
            if(lng==1)
            {
            printf("\033[1;33m\nEnter your custom base(max 16): \033[1;0m");

            }
            else
            {
                printf("\033[1;33m\nEntrez votre base personnalisee(max 16): \033[1;0m");
            }
            scanf("%d", &target_base);
            while (target_base < 2 || target_base > 16)
            {
                invalid_option(lng);
                scanf("%d", &target_base);
            }
            break;
        default:
            invalid_option(lng);
            error = 1;
            break;
        }
    } while (error == 1);
    return (target_base);
}

void prep_input_conv(char *input, int *input_conv)
{
    int i = 0;
    for (i = 0; i < 16; i++)
    {
        switch (input[i])
        {
        case '0':
            input_conv[i] = 0;
            break;
        case '1':
            input_conv[i] = 1;
            break;
        case '2':
            input_conv[i] = 2;
            break;
        case '3':
            input_conv[i] = 3;
            break;
        case '4':
            input_conv[i] = 4;
            break;
        case '5':
            input_conv[i] = 5;
            break;
        case '6':
            input_conv[i] = 6;
            break;
        case '7':
            input_conv[i] = 7;
            break;
        case '8':
            input_conv[i] = 8;
            break;
        case '9':
            input_conv[i] = 9;
            break;
        case 'A':
        case 'a':
            input_conv[i] = 10;
            break;
        case 'B':
        case 'b':
            input_conv[i] = 11;
            break;
        case 'C':
        case 'c':
            input_conv[i] = 12;
            break;
        case 'D':
        case 'd':
            input_conv[i] = 13;
            break;
        case 'E':
        case 'e':
            input_conv[i] = 14;
            break;
        case 'F':
        case 'f':
            input_conv[i] = 15;
            break;
        default:
            break;
        }
    }
}

void prep_output_conv(int *output_conv, char *output, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        switch (output_conv[i])
        {
        case 0:
            output[i] = '0';
            break;
        case 1:
            output[i] = '1';
            break;
        case 2:
            output[i] = '2';
            break;
        case 3:
            output[i] = '3';
            break;
        case 4:
            output[i] = '4';
            break;
        case 5:
            output[i] = '5';
            break;
        case 6:
            output[i] = '6';
            break;
        case 7:
            output[i] = '7';
            break;
        case 8:
            output[i] = '8';
            break;
        case 9:
            output[i] = '9';
            break;
        case 10:
            output[i] = 'A';
            break;
        case 11:
            output[i] = 'B';
            break;
        case 12:
            output[i] = 'C';
            break;
        case 13:
            output[i] = 'D';
            break;
        case 14:
            output[i] = 'E';
            break;
        case 15:
            output[i] = 'F';
            break;
        default:
            break;
        }
    }
}

void show_output(char *output, int len)
{
    int i;
    for (i = (len - 1); i >= 0; i--)
        printf("\033[1;36m%c\033[1;0m", output[i]);
}

void convert(int input_base, int target_base, char *input, char *output, int *input_conv, int lng)
{

    int i, base10 = 0, output_conv[50], power = 0, len = 0;
    prep_input_conv(input, input_conv);
    i = 0;

    for (i = strlen(input) - 1; i >= 0; i--)
    {
        base10 += input_conv[i] * pow(input_base, power);
        power++;
    }

    i = 0;
    if (target_base != 10)
    {
        while (base10 != 0)
        {
            output_conv[i] = base10 % target_base;
            base10 = base10 / target_base;
            i++;
        }

        prep_output_conv(output_conv, output, i);
    }

    if (lng == 1)
    {
        printf("\n\033[1;32m %s \033[1;33mconverted from base\033[1;32m %d \033[1;33mto base\033[1;32m %d\033[1;33m is:\n   ", input, input_base, target_base, i, output);
    }
    else
    {
        printf("\n\033[1;32m %s \033[1;33mconverti a partir de la base\033[1;32m %d \033[1;33men base\033[1;32m %d\033[1;33m est:\n   ", input, input_base, target_base, i, output);
    }
    if (target_base != 10)
    {
        show_output(output, i);
    }
    else
    {
        printf("\033[1;36m%d\033[1;0m", base10);
    }
}

void main()
{

    // variables here:
    int lng, input_base, target_base;
    char input[16];
    char output[50];
    int input_conv[16];
    lng = language();
    printf("lng in main=%d", lng);
    intro_text(lng);                   // print out main text
    input_base = read_input_base(lng); // reading the input base from funtion
    clear_input(input);
    read_input(input, lng);
    if (lng == 1)
    {
        printf("\033[1;36m\nSelect the base you want to convert to: \033[1;0m");
        printf("\n\n   1) Decimal\n   2) Hexadecimal\n   3) Binary\n   4) Ocatl\n   5) Custom Base\n\n");
    }
    else
    {
        printf("\033[1;36m\nSelectionnez la base vers laquelle vous souhaitez convertir: \033[1;0m");
        printf("\n\n   1) Decimal\n   2) Hexadecimal\n   3) Binaire\n   4) Ocatl\n   5) Base Personnalisee\n\n");
    }
    target_base = read_target_base(lng);
    convert(input_base, target_base, input, output, input_conv, lng);
}
