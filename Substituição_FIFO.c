#include <stdio.h>
#include <stdlib.h>

int frames, valor, page_fault = 0, i = 0, FIFO = 0, aux = 0;

int main()
{
	printf("Qual eh o limite de frames? ");
	scanf("%d", &frames);
	int vet_frames[frames];
	for (i = 0; i < frames; i++)
		vet_frames[i] = 0;
	printf("O limite de frames eh: %d\n", frames);
	int tam_vetor = sizeof(vet_frames) / sizeof(vet_frames[0]);
	while (1)
	{
		printf("Referencia da pagina (zero ou negativo para finalizar): ");
		scanf("%d", &valor);
		if (valor < 0)
			break;
		else
		{
			for (i = 0; i < frames; i++)
			{
				if (vet_frames[i] == 0)
				{
					vet_frames[i] = valor;
					printf("Page Fault!\n");
					page_fault++;
					aux = 0;
					break;
				}
				else if (vet_frames[i] == valor)
				{
					vet_frames[i] = valor;
					printf("Nao houve Page Fault!\n");
					aux = 0;
					break;
				}
				else
					aux++;
			}
			if (aux == tam_vetor)
			{
				vet_frames[FIFO] = valor;
				printf("Page Fault!\n");
				page_fault++;
				FIFO++;
				if (FIFO == tam_vetor)
					FIFO = 0;
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
	printf("Page Faults: %d", page_fault);
	return 0;
}
