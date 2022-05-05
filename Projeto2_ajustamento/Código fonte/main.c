#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double tabela(int n, double *g0,double *g1, double *num2, double *u)
{
    int i, j;
    double matriz[2][2];
    double resultado[2];

    for(i = 0; i < 2; i++)
    {
        resultado[i] = 0;
        for(j = 0; j < 2; j++)
        {
            matriz[i][j] = 0;
        }
    }
    //definir a nossa matriz

    for(i = 0; i < n; i++)
    {
        matriz[0][0] = matriz[0][0] + g0[i]*g0[i];
        matriz[1][1] = matriz[1][1] + g1[i]*g1[i];
        matriz[0][1] = matriz[0][1] + g0[i]*g1[i];
        matriz[1][0] = matriz[0][1];
        resultado[0] = resultado[0] + num2[i]*g0[i];
        resultado[1] = resultado[1] + num2[i]*g1[i];
    }
    //pivotação parcial e eliminacao de gauss para definir o a e b

    if(matriz[1][0] != 0)
    {
        matriz[1][1] = matriz[1][1] - matriz[0][1]*matriz[1][0]/(matriz[0][0]);
        resultado[1] = resultado[1] - resultado[0]*matriz[1][0]/matriz[0][0];
        matriz[1][0] = 0;
    }


    u[1] = resultado[1]/matriz[1][1];
    u[0] = (resultado[0] - u[1]*matriz[0][1])/matriz[0][0];
}

double funcao1(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int j = 0;
    int k = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = 1;
        g1[i] = num1[i];
    }

    tabela(n, g0, g1, num2, u);
    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*num1[i] + u[0] - num2[i]), 2);
    }
    residuo = px;
    printf("%lf", u[0]);
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{1}(x) =  %.4lfE%d*x + %.4lfE%d           %.4lfE%d", u[1],k, u[0],j, px, w);

    return residuo;
}

double funcao2(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int j = 0;
    int k = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = num1[i];
        g1[i] = num1[i]*num1[i];
    }
    tabela(n, g0, g1, num2, u);
    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*num1[i]*num1[i] + u[0]*num1[i] - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{2}(x) =  %.4lfE%d*x^2 + %.4lfE%d*x        %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao3(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int j = 0;
    int k = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = num1[i];
        g1[i] = num1[i]*num1[i]*num1[i];
    }
    tabela(n, g0, g1, num2, u);
    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*num1[i]*num1[i]*num1[i] + u[0]*num1[i] - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{3}(x) =  %.4lfE%d*x^3 + %.4lfE%d*x       %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao4(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int j = 0;
    int k = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = num1[i]*num1[i];
        g1[i] = num1[i]*num1[i]*num1[i];
    }
    tabela(n, g0, g1, num2, u);
    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*num1[i]*num1[i]*num1[i] + u[0]*num1[i]*num1[i] - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{4}(x) =  %.4lfE%d*x^3 + %.4lfE%d*x^2     %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao5(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int k = 0;
    int j = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = num1[i];
        g1[i] = 1;
        num2[i] = log(num2[i]);
    }
    tabela(n, g0, g1, num2, u);
    for(i = 0; i < n; i++)
    {
        num2[i] = exp(num2[i]);
    }

    u[1] = exp(u[1]);
    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*exp(u[0]*num1[i]) - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{5}(x) =  %.4lfE%dexp(%.4lfE%d*x)          %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao6(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int k = 0;
    int j = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = log(num1[i]);
        g1[i] = 1;
        num2[i] = log(num2[i]);
    }
    tabela(n, g0, g1, num2, u);
    u[1] = exp(u[1]);

    for(i = 0; i < n; i++)
    {
        num2[i] = exp(num2[i]);
    }
    // residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*pow(num1[i], u[0]) - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{6}(x) =  %.4lfE%d*x^(%.4lfE%d)            %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao7(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int k = 0;
    int j = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = 1/num1[i];
        g1[i] = log(num1[i]);
    }
    tabela(n, g0, g1, num2, u);

    // residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*log(num1[i]) + u[0]/num1[i] - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{7}(x) =  %.4lfE%dln(x) + %.4lfE%d/x     %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao8(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int k = 0;
    int j = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = 1/num1[i];
        g1[i] = num1[i];
    }
    tabela(n, g0, g1, num2, u);

    // residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*num1[i] + u[0]/num1[i] - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{8}(x) =  %.4lfE%d*x + %.4lfE%d/x         %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao9(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int k = 0;
    int j = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = num1[i];
        g1[i] = cos(num1[i]);
    }
    tabela(n, g0, g1, num2, u);

    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((u[1]*cos(num1[i]) + u[0]*num1[i] - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{9}(x) =  %.4lfE%dcos(x) + %.4lfE%d*x      %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}

double funcao10(int n, double *g0,double *g1, double *num1, double *num2, double *u)
{
    int i;
    int k = 0;
    int j = 0;
    int w = 0;
    double px = 0;
    double residuo;

    for(i = 0; i < n; i++)
    {
        g0[i] = exp(num1[i]);
        g1[i] = sin(num1[i]);
    }
    tabela(n, g0, g1, num2, u);

    //residuo
    for(i = 0; i < n; i++)
    {
        px = px + pow((1/(u[1]*sin(num1[i]) + u[0]*exp(num1[i])) - num2[i]), 2);
    }
    residuo = px;
    while(fabs(u[0]) < 1)
    {
        u[0] = u[0]*10;
        j--;
    }
    while(fabs(u[1]) < 1)
    {
        u[1] = u[1]*10;
        k--;
    }
    while(fabs(px) < 1)
    {
        px = px*10;
        w--;
    }
    while(fabs(u[0]) > 10)
    {
        u[0] = u[0]/10;
        j++;
    }
    while(fabs(u[1]) > 10)
    {
        u[1] = u[1]/10;
        k++;
    }
    while(fabs(px) > 10)
    {
        px = px/10;
        w++;
    }
    printf("\nf_{10}(x) =  1/(%.4lfE%dsen(x) + %.4lfE%dexp(x))      %.4lfE%d", u[1], k, u[0], j, px, w);

    return residuo;
}


int main()
{
    FILE *entrada;
    char nome_do_arquivo[20], iniciar_fechar, ponto;
    int a, n, exp1, exp2, i, j;
    double *num1;
    double *num2;
    double *g0;
    double *g1;
    double *u;
    double *px;
    int menor;
    char c;

    do                                              /*menu inicial, "a" para selecionar o arquivo, "b" para fechar*/
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
        fscanf(entrada, "%d", &n);
        /*recebendo do arquivo o numero de funções*/
        num1 = (double*)malloc(n*sizeof(double));
        num2 = (double*)malloc(n*sizeof(double));
        g0 = (double*)malloc(n*sizeof(double));
        g1 = (double*)malloc(n*sizeof(double));
        px = (double*)malloc(10*sizeof(double));
        u = (double*)malloc(2*sizeof(double));
        printf("numero de pontos avaliados sera: %d\n", n);
        for (i = 0; i < n; i++)
        {
            fscanf(entrada, "%lf,%lf", &num1[i], &num2[i]);// recebendo numero 1
        }
        px[0] = funcao1(n, g0, g1, num1, num2, u);
        px[1] = funcao2(n, g0, g1, num1, num2, u);
        px[2] = funcao3(n, g0, g1, num1, num2, u);
        px[3] = funcao4(n, g0, g1, num1, num2, u);
        px[4] = funcao5(n, g0, g1, num1, num2, u);
        px[5] = funcao6(n, g0, g1, num1, num2, u);
        px[6] = funcao7(n, g0, g1, num1, num2, u);
        px[7] = funcao8(n, g0, g1, num1, num2, u);
        px[8] = funcao9(n, g0, g1, num1, num2, u);
        px[9] = funcao10(n, g0, g1, num1, num2, u);
        menor = 0;
        for(i = 1; i < 10; i++)
        {
            if(fabs(px[i]) < fabs(px[menor]))
            {
                menor = i;
            }
        }
        menor++;
        printf("\n\nA melhor funcao de ajustamento:");

        if(menor == 1)
        {
            px[0] = funcao1(n, g0, g1, num1, num2, u);
        }
        else if(menor == 2)
        {
            px[0] = funcao2(n, g0, g1, num1, num2, u);
        }
        else if(menor == 3)
        {
            px[0] = funcao3(n, g0, g1, num1, num2, u);
        }
        else if(menor == 4)
        {
            px[0] = funcao4(n, g0, g1, num1, num2, u);
        }
        else if(menor == 5)
        {
            px[0] = funcao5(n, g0, g1, num1, num2, u);
        }
        else if(menor == 6)
        {
            px[0] = funcao6(n, g0, g1, num1, num2, u);
        }
        else if(menor == 7)
        {
            px[0] = funcao7(n, g0, g1, num1, num2, u);
        }
        else if(menor == 8)
        {
            px[0] = funcao8(n, g0, g1, num1, num2, u);
        }
        else if(menor == 9)
        {
            px[0] = funcao9(n, g0, g1, num1, num2, u);
        }
        else if(menor == 10)
        {
            px[0] = funcao10(n, g0, g1, num1, num2, u);
        }
        printf("\n");
    }
    return 0;
}
