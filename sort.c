#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 200000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int troca = 0;
void preenche (int *vetor)
{
	int i;
	for (i=0; i<TAM; i++)
	{
		vetor[i]=rand()%501;
		printf("%d\t", vetor[i]);
	}
}
void bolha(int *vetor)
{
	printf("Ordenando o vetor... \n");
	int i, j, aux;
	for( i = 0; i < TAM; i++ )
	{
    	for( j = i + 1; j < TAM; j++ )
    	{      
      		if (vetor[i] > vetor[j])
      		{
         	aux = vetor[i];
         	vetor[i] = vetor[j];
         	vetor[j] = aux;
         	troca++;
      		}
    	}
  	}
}
void selecao (int *vetor)
{
	printf("Ordenando o vetor... \n");
	int i,j, min, aux;
	for (i=0;i<TAM-1;i++)
	{
		min = i;
		for (j=i+1;j<TAM;j++)
		{
			if (vetor[j] < vetor[min])
			{
				min = j;
			}
		}
		aux=vetor[i];
		vetor[i]=vetor[min];
		vetor[min]=aux;
		troca++;
	}
}
void insercao (int *vetor)
{
	printf("Ordenando o vetor... \n");
	int i,j, chave;
	for (i=1;i<TAM;i++)
	{
		chave=vetor[i];
		j=i-1;
		while ((j>=0)&&(vetor[j]>chave))
		{
			vetor[j+1]=vetor[j];
			j=j-1;
		}
		vetor[j+1]=chave;
		troca++;
	}
}
void decisao(int *vetor)
{
	int opcao, tempo;
	int escolha = 1;
	while (escolha == 1)
	{
		printf("\nEscolha qual método de ordenação será utilizado: ");
		printf("\n1: Bubble sort; 2: Selection sort; 3: Insertion sort ");	
		scanf("%d", &opcao);
		switch (opcao)
		{
   		case 1:
   			tempo = GetTickCount();
			bolha(vetor);
			tempo = GetTickCount() - tempo;		
			printf("Tempo de ordenação: %d milisegundos\n",tempo);
			escolha = 0;			
   		break;

   		case 2:
   			tempo = GetTickCount();
			selecao(vetor);
			tempo = GetTickCount() - tempo;		
			printf("Tempo de ordenação: %d milisegundos\n",tempo);
			escolha = 0;
   		break;

   		case 3:
   			tempo = GetTickCount();
			insercao(vetor);
			tempo = GetTickCount() - tempo;		
			printf("Tempo de ordenação: %d milisegundos\n",tempo);
			escolha = 0;
    	break;
    
    	default:
    		printf("Escolha inválida!\n");
    		escolha = 1;
		}
	}
	system("pause");
}
void mostra(int *vetor)
{	
	printf("\nVetor ordenado:\n");
	int i;
	for(i=0;i<TAM;i++)
	{
		printf("%d\t",vetor[i]);
	}
	printf("\nPressione enter para ver a quantidade de trocas realizadas.");
	getch();
	printf("\nNúmero de trocas: %d trocas\n", troca);
}
void busca_bin(int *vetor) 
{
	int achou = 0, inicio = 0, fim = TAM-1, meio, busca;
	printf("\nEntre com o inteiro a ser pesquisado: ");
	scanf("%d", &busca);
	while(inicio<=fim)
	{
		meio = (inicio+fim)/2;
		if (vetor[meio]==busca)
			achou = 1;
		if (busca<vetor[meio])
			fim = meio-1;
		else
			inicio = meio+1;
	}
	if (achou==1)
		printf("\nAchou o valor %d \n ", busca);
	else
		printf("\nNão achou o valor\n ");
}
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int vetor[TAM];	
	printf("Vetor com %d números. Pressione enter para gerar os valores.\n",TAM);
	system("pause");
	preenche(vetor);
	decisao(vetor);
	mostra(vetor);
	system ("pause");
	busca_bin(vetor);
	
	return 0;
}
