#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Programa que calcula descontos no salário CLT
Descontos:
    INSS (cálculo progressivo)
    IRR (considerar se há dependentes ou não)
    Outros descontos
*/

int inss(float grossSalary)
{
    float discount, netSalary;

    if (grossSalary <= 1045) //7,5%
    {
        discount = grossSalary * 0.075;
    }
    else if (grossSalary > 6101.06) // 713,10
    {
        discount = 713.10;
    }
    else if (grossSalary > 1045 && grossSalary <= 2089.6) //9%
    {
        discount = ((grossSalary - 1045) * 0.09) + 78.38;
    }
    else if (grossSalary > 2089.6 && grossSalary <= 3134.4) //12%
    {
        discount = ((grossSalary - 2089.6) * 0.12) + 172.39;
    }
    else if (grossSalary > 3134.4 && grossSalary <= 6101.06) //14%
    {
        discount = ((grossSalary - 3134.4) * 0.14) + 297.79;
    }

    netSalary = grossSalary - discount;

    return netSalary;
}

int irrf(float netSalary, int dependents)
{
    float calcBase, discount;
    /*
    Base de cálculo (R$)	Alíquota (%)	Parcela dedutível (R$)
    Até 1.903,98	0%	0,00
    De 1.903,99 até 2.826,65	7,5%	142,80
    De 2.826,66 até 3.751,05	15%	354,80
    De 3.751,06 até 4.664,68	22,5%	636,13
    Acima de 4.664,69	27,5%	869,36
    return 0;
    R$ 189,59 por dependente (calcular antes)
    */

    //Base de cálculo dependendo do número de dependentes
    calcBase = netSalary - dependents * 189.59;

    if (calcBase >= 1903.99 && calcBase <= 2826.65)
    {
        discount = calcBase * 0.075 - 142.80;
    }
    else if (calcBase >= 2826.66 && calcBase <= 3751.05)
    {
        discount = calcBase * 0.15 - 354.8;
    }
    else if (calcBase >= 3751.06 && calcBase <= 4664.68)
    {
        discount = calcBase * 0.225 - 354.8;
    }
    else if (calcBase > 4664.69)
    {
        discount = calcBase * 0.275 - 869.36;
    }

    netSalary = netSalary - discount;

    return netSalary;
}

int main()
{
    int dependents;
    float grossSalary, netSalary;
    printf("\nInsira o valor do salário bruto (ex: 1935.50): ");
    scanf("%f", &grossSalary);

    do
    {
        printf("\nInsira o número de dependentes: ");
        scanf("%d", &dependents);
        if (dependents < 0 || dependents > 20)
        {
            printf("\nNúmero inválido. Insira apenas números inteiros de 1 a 20.\n");
        }

    } while (dependents < 0 || dependents > 20);

    netSalary = inss(grossSalary);
    irrf(netSalary, dependents);

    return 0;
}