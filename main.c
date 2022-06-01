#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define eleitores 15
#define num_candidatos 27   //0 sendo branco e ultima posicao sendo nulo

/*Uma empresa especializada em marketing eleitoral contratou os seus servicos de programador
para registrar a opinião de 700.000 eleitores sobre o candidato favorito na eleicao para presidente. Cada eleitor deve
apenas responder um numero de 1 a 25 pois cada numero corresponde a um candidato de um total de 25.
 Ao final o programa devera informar a quantidade de votos que cada candidato obteve. Use a estrategia modular.*/
typedef struct
{
    int candidato[num_candidatos];
} votacao;
int validacao_voto (int voto, int minimo_voto, int maximo_voto);
votacao iniciar_votacao (void);
void resultado(votacao votos);


int main()
{
    setlocale(LC_ALL, "portuguese");
    votacao votos;
    votos=iniciar_votacao();
    resultado (votos);

}

int validacao_voto(int voto, int minimo_voto, int maximo_voto)
{
    char nulo;
    while (voto <minimo_voto || voto>maximo_voto)
    {
        printf("\nO voto digitado não corresponde a nenhum dos canditados de 1 a 25");
        printf("\nVocê gostaria de votar em branco ou nulo ?\n(s)im ou (n)ão.\n");
        fflush(stdin);
        scanf("%c",&nulo);
        if (nulo=='s' || nulo=='S')
        {
            printf("\nVocê quer votar em branco(0) ou em nulo(1)\n");
            scanf("%d",&voto);
            if (voto)
            {
                voto=num_candidatos- 1;
            }
            break;
        }
        printf("\nDigite novamente o seu candidato :");
        scanf("%d",&voto);

    }
    return voto;
}
votacao iniciar_votacao (void)
{
    votacao votos= {.candidato={0}};
    int contador,escolha;
    printf("\nIniciando votação");
    for (contador=1; contador<=eleitores; contador++)
    {
        printf("\nOs números de candidatos são de 1 a %d ou 0 para em branco",num_candidatos-2);
        printf("\nEleitor %d ,digite o seu voto: ",contador);//ultima posição válida (-1)ultimo candidato válido (-2)
        scanf("%d",&escolha);//o numero da escolha é o numero da posição vetor
        escolha=validacao_voto(escolha,1,num_candidatos-2);
        votos.candidato[escolha]++;//variavel candidatos que está dentro da variavel votos,e a posição escolha do vetor é o voto no canditado
    }
    return votos;
}
void resultado(votacao votos)
{
    printf("\nA votação chegou ao final");
    printf("\nA quantidade de votos em branco foi: %d",votos.candidato[0]);
    int i;
    for (i=1; i<num_candidatos-1; i++)
    {
        printf("\nA quantidade de votos do canditado %d foi de %d.",i,votos.candidato[i]);
    }
    i++;
    printf("\nOs votos em nulo foram: %d",votos.candidato[i]);

}
