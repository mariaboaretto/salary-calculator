#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float salaryInput()
{
    float grossSalary;
    do
    {
        //Printando msg e recebendo valor do salário bruto
        printf("\nInsira o valor do salário bruto (ex: 1935.50): ");
        scanf("%f", &grossSalary);
        //Se salário bruto for inválido
        if (grossSalary < 0)
        {
            printf("\nValor inválido. Insira apenas números maiores do que 0.\n");
        }

    } while (grossSalary < 0);

    return grossSalary;
}

int dependentsInput()
{
    int dependents;
    do
    {
        //Printando msg e recebendo número de dependentes
        printf("\nInsira o número de dependentes: ");
        scanf("%d", &dependents);
        //Se o número for inválido
        if (dependents < 0 || dependents > 20)
        {
            printf("\nNúmero inválido. Insira apenas números inteiros de 1 a 20.\n");
        }

    } while (dependents < 0 || dependents > 20);

    return dependents;
}

float inss(float grossSalary)
{
    float discountINSS, netSalary;

    if (grossSalary <= 1045) //7,5%
    {
        discountINSS = grossSalary * 0.075;
    }
    else if (grossSalary > 6101.06) // 713,10
    {
        discountINSS = 713.10;
    }
    else if (grossSalary > 1045 && grossSalary <= 2089.6) //9%
    {
        discountINSS = ((grossSalary - 1045) * 0.09) + 78.375;
    }
    else if (grossSalary > 2089.6 && grossSalary <= 3134.4) //12%
    {
        discountINSS = ((grossSalary - 2089.6) * 0.12) + 94.014 + 78.375;
    }
    else if (grossSalary > 3134.4 && grossSalary <= 6101.06) //14%
    {
        discountINSS = ((grossSalary - 3134.4) * 0.14) + 125.376 + 94.014 + 78.375;
    }

    return discountINSS;
}

float irrf(float calcBase, int dependents)
{
    float discountIRRF;

    calcBase = calcBase - (dependents * 189.59);

    if (calcBase < 1903.99)
    {
        discountIRRF = 0;
    }

    else if (calcBase >= 1903.99 && calcBase <= 2826.65)
    {
        discountIRRF = (calcBase * 0.075) - 142.80;
    }
    else if (calcBase >= 2826.66 && calcBase <= 3751.05)
    {
        discountIRRF = (calcBase * 0.15) - 354.8;
    }
    else if (calcBase >= 3751.06 && calcBase <= 4664.68)
    {
        discountIRRF = (calcBase * 0.225) - 636.13;
    }
    else if (calcBase > 4664.69)
    {
        discountIRRF = (calcBase * 0.275) - 869.36;
    }

    return discountIRRF;
}

float otherInput()
{
    float discountOthers;
    do
    {
        printf("\nInsira o valor de outros descontos, se houver: ");
        scanf("%f", &discountOthers);
        if (discountOthers < 0)
        {
            printf("\nValor inválido. Insira números maiores do que 0.\n");
        }

    } while (discountOthers < 0);

    return discountOthers;
}

void resultsHeader()
{
    int columns = 32;
    int lines = 3;

    printf("\n");

    //Percorrendo as linhas
    for (int i = 1; i <= lines; i++)
    {
        //Percorrendo as colunas
        for (int j = 1; j < columns; j++)
        {
            //Se for 1ª, 7ª ou 9ª linha
            if (i == 1 || i == lines)
            {
                if (j >= 1 || j <= columns)
                {
                    printf("-");
                }
            }
            else
            {
                if (j == 4)
                {
                    printf("Descontos");
                }
                else if (j == 16)
                {
                    printf("Valor");
                }
                else
                {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }
}

void resultsDisplay(float grossSalary, float discountINSS, float discountIRRF, float discountOthers)
{
    int lines = 6;
    int columns = 32;

    for (int i = 1; i <= lines; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            if (i == 4 || i == lines)
            {
                if (j >= 1 || j <= columns)
                {
                    printf("-");
                }
            }
            else if (i == 1)
            {
                if (j == 4)
                {
                    printf("INSS");
                }
                else if (j == 20)
                {
                    printf("-%.2f", discountINSS);
                }
                else
                {
                    printf(" ");
                }
            }
            else if (i == 2)
            {
                if (j == 4)
                {
                    printf("IRFF");
                }
                else if (j == 20)
                {
                    printf("-%.2f", discountIRRF);
                }
                else
                {
                    printf(" ");
                }
            }
            else if (i == 3)
            {
                if (j == 4)
                {
                    printf("Outros");
                }
                else if (j == 18)
                {
                    printf("-%.2f", discountOthers);
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if (j == 4)
                {
                    printf("Salário líquido");
                }
                else if (j == 10)
                {
                    printf("%.2f", grossSalary - discountINSS - discountIRRF - discountOthers);
                }
                else
                {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    int dependents;
    float grossSalary, discountINSS, discountIRRF, discountOthers, Calcbase;

    grossSalary = salaryInput();    //Recebendo input do salário
    dependents = dependentsInput(); //Recebendo input de dependentes
    discountOthers = otherInput();

    discountINSS = inss(grossSalary);      //Calculando o desconto do INSS
    Calcbase = grossSalary - discountINSS; //Salário para cálculo do desconto do IRRF

    discountIRRF = irrf(Calcbase, dependents); //Calculando desconto do IRRF + dependentes

    resultsHeader();
    resultsDisplay(grossSalary, discountINSS, discountIRRF, discountOthers);

    return 0;
}