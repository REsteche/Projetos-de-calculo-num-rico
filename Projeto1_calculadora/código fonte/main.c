#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimirNum(int num[], char sinal, int exp, int significativo)
{
    int i;
    if(num[significativo]>5 || (num[significativo] == 5 && num[significativo-1]%2 == 0)) //arredondamento
    {
        num[significativo-1] += 1;
    }
    for (i = significativo-1; i >= 0; i--) //para se algum dos algarismos for arrendodado de 9 pra 10
    {
        if(num[i] == 10 && i<significativo)
        {
            num[i]=0;
            num[i-1] = num[i-1] + 1;
            if(num[0]==0)
            {
                num[0]=1;
                exp= exp+1;
            }
        }

    }
    for (i=0; i <significativo; i++)    //imprime os algarismos
    {
        if(i==0)    //primeiro algarismo e ponto
        {
            printf("%c%d.", sinal, num[0]);
        }
        else    //restantes algarismos
        {
            printf("%d", num[i]);
        }
    }

    printf("E");
    if (exp >= 0)
    {
        printf("+");
    }
    printf("%d", exp);
    printf(";");
}

void soma(int num1[], int num2[], int exp1, int exp2, char sinal1, char sinal2, int significativo, char op, int emax, int emin)
{
    int intermediario[16];
    int resultado[15];
    char sinalres;
    int stack = 0;
    int i, j;
    int k = 0;
    int sinaltest = 0;
    int a = 0;
    int flow = 0;

    for (j = 0; j <= 14; j++)
    {
        if (num1[j] > num2[j]) // se num1[j] > num2[j] sai do ciclo
        {
            j = 15;
        }
        else if (num1[j] < num2[j]) //o resultado a = 1 será utilizado posteriormente
        {
            a = 1;
        }
    }
    if (sinal1 == '-')
    {
        for (j = 0; j <= 14; j++)
        {
            num1[j] = -1 * num1[j];
        }
    }
    if ((sinal2 == '-' && op == '+') || (sinal2 == '+' && op == '-'))
    {
        for (j = 0; j <= 14; j++)
        {
            num2[j] = -1 * num2[j];
        }
    }
    for (j = 14; j >= 0; j--)
    {
        resultado[j] = num1[j] + num2[j] + stack;
        stack = 0;

        if (resultado[j] >= 10 && j > 0)
        {
            stack = resultado[j] / 10;
            resultado[j] = resultado[j] % 10;
        }
        else if ((resultado[j] < 0 && resultado[j] > -10) && j > 0)
        {
            if (a == 0) 
            {
                stack = -1;
                resultado[j] = 10 + resultado[j];
            }
            else if (a == 1) 
            {
                resultado[j] = -1 * resultado[j];
            }
        }
    }
    if (resultado[0] >= 10 || resultado[0] <= -10)
    {
        stack = resultado[0] / 10;
        resultado[0] = resultado[0] % 10;
        intermediario[0] = stack;
        exp1 = exp1 + 1;
        for (i = 0; i <= 14; i++)
        {
            intermediario[i + 1] = resultado[i];
            resultado[i] = intermediario[i];
            
        }
    }
    else if (resultado[0] < 0)
    {
        sinaltest = 1;
        resultado[0] = -1 * resultado[0];
    }

    while (resultado[k] == 0)
    {
        k = k + 1;
    }
    if (k != 0)
    {
        exp1 = exp1 - k;
        for (i = 0; i <= k; i++)
        {
            resultado[i] = resultado[i + k];
        }
    }
    if (sinaltest == 1)
    {
        sinalres = '-';
    }
    else
    {
        sinalres = '+';
    }

    if(exp1 > emax)     //verifica se o resultado deu Overflow
    {
        flow = 1;
        printf("%c; resultado: overflow", op);
    }
    else if(exp1 < emin)    //verifica se o resultado deu Underflow
    {
        flow = 1;
        printf("%c; resultado: underflow", op);
    }
    if(flow == 0)   //Se o resultado não está em Underflow ou Overflow imprime normalmente o resultado
    {

        printf("%c; resultado: ", op);
        imprimirNum(resultado, sinalres, exp1, significativo);
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "");
    FILE *entrada;

    char nome_do_arquivo[20], iniciar_fechar, op, sinal1, sinal2, ponto;
    int a, n, t, emin, emax, mant1[15], mant2[15], exp1, exp2, i, j, mantissa1, mantissa2, expres;
    int flow = 0;

    do
    {
        printf("Digite 'a' ou 'b':\n a) Digitar o nome do arquivo de entrada para iniciar o programa.\n b) Fechar o programa.\n");
        scanf("%c", &iniciar_fechar);
    }
    while (iniciar_fechar != 'a' && iniciar_fechar != 'b');

    if (iniciar_fechar == 'a')
    {
        printf("Digite o nome do arquivo(nomedoarquivo.txt):\n");
        scanf("%s", nome_do_arquivo);
        entrada = fopen(nome_do_arquivo, "r");
        while (entrada == NULL)
        {
            printf("Tente novamente.\n");
            scanf("%s", nome_do_arquivo);
            entrada = fopen(nome_do_arquivo, "r");
        }

        fscanf(entrada, " %d%*c%d%*c%d%*c%d", &t, &emin, &emax, &n); /*recebendo a máquina(10, t, emin, emáx) e quantas operações
                                                                    serão feitas*/
        printf("F(10, %d, %d, %d)\n", t,emin, emax);
        printf("nº de operações.: %d\n", n);
        for (i = 0; i < n; i++)
        {
            flow = 0;

            fscanf(entrada, " %c%d%*c%d%*c%d%*c", &sinal1, &mant1[0], &mantissa1, &exp1);// recebendo numero 1



            fscanf(entrada, " %c%d%*c%d%*c%d%*c", &sinal2, &mant2[0], &mantissa2, &exp2);// recebendo numero 2


            fscanf(entrada, " %c", &op); // recebendo operacão a ser realizada


            for (j = 6; j > 0; j--) //passar cada algarismo da mantissa para um espaço do vetor mant1[]
            {
                mant1[j] = mantissa1 % 10;
                mantissa1 = mantissa1 / 10;
            }

            for (j = 6; j > 0; j--) //passar cada algarismo da mantissa para um espaço do vetor mant2[]
            {
                mant2[j] = mantissa2 % 10;
                mantissa2 = mantissa2 / 10;
            }

            for (j = 7; j <= 14; j++)   //limpa o resto do vetor
            {
                mant1[j] = 0;
                mant2[j] = 0;
            }
            imprimirNum(mant1, sinal1, exp1, t);    //imprime o primeiro número
            imprimirNum(mant2, sinal2, exp2, t);    //imprime o segundo número

            if(exp1 > emax) // verifica Overflow no primeiro número
            {
                flow = 1;
                printf("%c; resultado: parcela 1 invalida, overflow\n");
            }
            else if(exp1 < emin)   // verifica Underflow no primeiro número
            {
                flow = 1;
                printf("%c; resultado: parcela 1 invalida, underflow\n");
            }
            else  if(exp2 > emax)   //verifica Overflow no segundo número
            {
                printf("%c; resultado: parcela 2 invalida, overflow\n");
                flow = 1;
            }
            else if(exp2 < emin)    //verifica Underflow no segundo número
            {
                flow = 1;
                printf("%c; resultado: parcela 2 invalida, underflow\n");
            }
            if(flow == 0) //se não houver Underflow ou Overflow:
            {
                //renormaliza os números caso os expoentes sejam diferentes
                if (exp1 > exp2)
                {
                    expres = exp1 - exp2;
                    exp2 = exp1;
                    for (j = 6; j >= 0; j--)
                    {
                        mant2[j + expres] = mant2[j];
                    }
                    for (j = 0; j < expres; j++)
                    {
                        mant2[j] = 0;
                    }
                }
                else if (exp1 < exp2)
                {
                    expres = exp2 - exp1;
                    exp1 = exp2;
                    for (j = 6; j >= 0; j--)
                    {
                        mant1[j + expres] = mant1[j];
                    }
                    for (j = 0; j < expres; j++)
                    {
                        mant1[j] = 0;
                    }
                }
                soma(mant1, mant2, exp1, exp2, sinal1, sinal2, t, op, emax, emin); //chama a função soma, que ao fim já imprime o resultado
            }
        }
        system("pause");
        fclose(entrada);

        return 0;
    }
    else
    {
        return 0;
    }
}
