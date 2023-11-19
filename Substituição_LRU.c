#include <stdio.h>
#include <stdlib.h>

int frames, valor, i, j, page_fault = 0, LRU = 0, aux = 0, contLRU = 0;

int main()
{
	printf("Qual eh o limite de frames? ");
	scanf("%d", &frames);
	int vet_frames[frames];
	int vet_cont_uso[frames];
	contLRU = frames;
	for (i = 0; i < frames; i++)
	{
		vet_frames[i] = 0;
		vet_cont_uso[i] = frames;
	}
	printf("O limite de frames eh: %d\n", frames);
	int tam_vetor = sizeof(vet_frames) / sizeof(vet_frames[0]);
	while (1)
	{
		printf("Referencia da pagina (zero ou negativo para finalizar): ");
		scanf("%d", &valor);
		if (valor <= 0)
			break;
		else
		{
			for (i = 0; i < frames; i++)
			{
				if (vet_frames[i] == 0)
				{
					vet_frames[i] = valor;
					vet_cont_uso[i] = frames;
					printf("Page Fault!\n");
					page_fault++;
					for (j = 0; j < frames; j++)
					{
						if (i == j)
							;
						else
							vet_cont_uso[j]--;
					}
					aux = 0;
					break;
				}
				else if (vet_frames[i] == valor)
				{
					vet_frames[i] = valor;
					vet_cont_uso[i] = frames;
					printf("Nao houve Page Fault!\n");
					for (j = 0; j < frames; j++)
					{
						if (i == j)
							;
						else
							vet_cont_uso[j]--;
					}
					aux = 0;
					break;
				}
				else
				{
					aux++;
				}
			}
			if (aux == tam_vetor)
			{
				for (i = 0; i < frames; i++)
				{
					if (vet_cont_uso[i] < contLRU)
					{
						contLRU = vet_cont_uso[i];
						LRU = i;
					}
				}
				vet_frames[LRU] = valor;
				vet_cont_uso[LRU] = frames;
				for (j = 0; j < frames; j++)
				{
					if (j == LRU)
						;
					else
						vet_cont_uso[j]--;
				}
				printf("Page Fault!\n");
				page_fault++;
				contLRU = frames;
				aux = 0;
			}
		}
		printf("Pagina carregada:\n");
		for (i = 0; i < tam_vetor; i++)
		{
			printf("%d\n", vet_frames[i]);
		}
	}
	printf("\n\nPagina final carregada:\n");
	for (i = 0; i < tam_vetor; i++)
	{
		printf("%d\n", vet_frames[i]);
	}
	printf("\nPage Faults: %d", page_fault);
	return 0;
}
