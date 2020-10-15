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

void results(float discountINSS, float discountIRRF, float discountOthers, float grossSalary)
{

}

int main()
{
    int dependents;
    float grossSalary, netSalary, discountINSS, discountIRRF, discountOthers, Calcbase;

    grossSalary = salaryInput();//Recebendo input do salário
    dependents = dependentsInput();//Recebendo input de dependentes
    discountOthers = otherInput();

    discountINSS = inss(grossSalary);          //Calculando o desconto do INSS
    Calcbase = grossSalary - discountINSS;     //Salário para cálculo do desconto do IRRF
    
    discountIRRF = irrf(Calcbase, dependents); //Calculando desconto do IRRF + dependentes
    netSalary = grossSalary - discountOthers - discountINSS - discountIRRF;
    
    
    printf("%.2f, %.2f, %.2f", discountINSS, discountIRRF, discountOthers);
    
    
    printf("\nO salário líquido é: %.2f\n", netSalary);

    


    return 0;
}