#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Programa que calcula descontos no salário CLT
Descontos:
    INSS (cálculo progressivo)
    IRR (considerar se há dependentes ou não?)

*/

void inss(float grossSalary)
{
    float discount, netSalary;

    /*
    Salário mínimo: R$ 1.045,00	7,5% = 78.38
    De R$ 1.045,01 a R$ 2.089,60	9% = 94.01
    De R$ 2.089,61 a R$ 3.134,40	12% = 125.38
    De R$ 3.134,41 a R$ 6.101,06	14% = x 
    Acima: R$ 713,10

    Ex: salário 2.300
    1ª faixa salarial: 1.045,00 x 0,075 = 78,38
    2ª faixa salarial: [2.089,60 - 1.045,00] x 0,09 = 1.044,60 x 0,09 = 94,01
    Faixa que atinge o salário: [2.300,00 - 2.089,60] x 0,12 = 210,40 x 0,12 = 25,25
    Total a recolher: 25,25 + 94,01 + 78,38 = 197,64
    R$ 2.102,36 (R$ 2.300,00 - R$ 197,64)    
    */

    if (grossSalary <= 1045)
    {
        discount = grossSalary * 0.075;
    }
    else if (grossSalary > 6101.06)
    {
        discount = 713.10;
    }
    else if (grossSalary > 1045 && grossSalary <= 2089.6)
    {
        discount = ((grossSalary - 1045) * 0.09) + 78.38;
    }

    netSalary = grossSalary - discount;
    printf("\n%.2f\n", netSalary);
}

int irrf(float grossSalary)
{
    /*
    Base de cálculo (R$)	Alíquota (%)	Parcela dedutível (R$)
    Até 1.903,98	0%	0,00
    De 1.903,99 até 2.826,65	7,5%	142,80
    De 2.826,66 até 3.751,05	15%	354,80
    De 3.751,06 até 4.664,68	22,5%	636,13
    Acima de 4.664,69	27,5%	869,36
    return 0;
    R$ 189,59 por dependente
    */
}

int main()
{
    float grossSalary;
    printf("\nInsira o valor do salário bruto: ");
    scanf("%f", &grossSalary);
    inss(grossSalary);

    return 0;
}