#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "CUBO.h"
#include "Camada1.h"
#include "2camada.h"
#include "3camada.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GIROS 1000

void EmbaralhaCubo(CUB_tppCUBO cubo, int giros) {
	int i, val;

	srand(time(NULL));

	for (i = 0; i < giros; i++) {
		val = rand() % 6;
		CUB_GirarFace(cubo, val, 1, 'h');
	}
}

enum cor
{
	BR,
	LA,
	VD,
	VM,
	AZ,
	AM
};

int configREG[] = {
			 BR,AZ,AZ,
			 AM,AZ,LA,
			 LA,LA,AZ,
	AZ,VM,VD,BR,VD,AM,LA,AZ,LA,BR,BR,VM,
	AZ,BR,VM,VD,VM,LA,BR,AM,BR,VD,LA,AM,
	VM,AM,AM,LA,VM,VM,VD,VM,VD,VM,LA,AM,
			 VD,AZ,BR,
			 VD,VD,BR,
			 AZ,AM,AM
};

void testChecarCorDaFace(CUB_tppCUBO cubo)
{
	char perg = 'y';
	int i, j, face, cor;
	CUB_GirarFace(cubo, CUB_faceSuperior, 1, 'a');
	CUB_GirarFace(cubo, CUB_faceSuperior, 1, 'a');
	CUB_GirarFace(cubo, CUB_faceFrontal, 1, 'h');
	printf("\n");
	CUB_ExibirCUBO(cubo);
	while (perg == 'y')
	{
		printf("Digite Face: ");
		scanf(" %d", &face);
		printf("Digite linha: ");
		scanf(" %d", &i);
		printf("Digite coluna: ");
		scanf(" %d", &j);

		i = CUB_ChecarCorDaFace(&cor, cubo, i, j, face);
		printf("ret: %d -- Cor: %d\n", i, cor);
		printf("continuar? (y/n) ");
		scanf(" %c", &perg);
	}
}

void testEncontrarPecaDeAresta(CUB_tppCUBO cubo)
{
	int i, j, face, cor1, cor2, ret;
	char perg = 'y';
	while (perg == 'y')
	{
		printf("Digite Cor1: ");
		scanf(" %d", &cor1);
		printf("Digite Cor2: ");
		scanf(" %d", &cor2);

		ret = CUB_EncontrarPosicaoDePecaDeAresta(&face, &i, &j, cubo, cor1, cor2);
		printf("ret: %d -- Face: %d, linha: %d, coluna:%d\n", ret, face, i, j);
		printf("continuar? (y/n) ");
		scanf(" %c", &perg);
	}

}

void testEncontrarPecaDeQuina(CUB_tppCUBO cubo)
{
	int i, j, face, cor1, cor2, cor3, ret;
	char perg = 'y';
	while (perg == 'y')
	{
		printf("Digite Cor1: ");
		scanf(" %d", &cor1);
		printf("Digite Cor2: ");
		scanf(" %d", &cor2);
		printf("Digite Cor3: ");
		scanf(" %d", &cor3);

		ret = CUB_EncontrarPosicaoDePecaDeQuina(&face, &i, &j, cubo, cor1, cor2, cor3);
		printf("ret: %d -- Face: %d, linha: %d, coluna:%d\n", ret, face, i, j);
		printf("continuar? (y/n) ");
		scanf(" %c", &perg);
	}

}

void copiaVetor(int* fonte, int*destino, int tam)
{
	int i;
	for (i = 0; i < tam; i++)
		destino[i] = fonte[i];
}

void programaPrincipal()
{
	int ret;
	char relatorio[2000],relatorio2[2000],relatorio3[2000];
	relatorio[0] = '\0';

	CUB_tppCUBO cubo;
	CUB_tpConfiguracao x;

	copiaVetor(configREG, x.cores, 54);
	ret = CUB_CriarCUBO(&cubo, x);
	printf("Configuracao inicial do cubo:\n");

	printf("Criacao do cubo: %s\n", ret != CUB_CondRetOK ?
		"Configuracao invalida" : "Configuracao OK");
	CUB_ExibirCUBO(cubo);


	ret = fazCamada1(cubo, relatorio);
	printf("%s\n", ret == CUB_CondRetOK ? "Primeira camada resolvida!" :
		"Nao deu pra resolver a primeira camada :(");
	CUB_ExibirCUBO(cubo);
	printf("\nRelatorio da primeira camada: %s\n\n", relatorio);
	

	ret = resolve2camada(cubo, relatorio2);
	printf("%s\n", ret == C2C_CondRetOK ? "Segunda camada tambem resolvida!" :
		"Nao deu pra resolver a segunda camada ;(");
	CUB_ExibirCUBO(cubo);
	printf("\nRelatorio da segunda camada: %s\n\n", relatorio2);
	

	ret = resolve3Camada(cubo, relatorio3);
	printf("%s\n", ret == TEC_tpCondRetOK ? "Terceira camada resolvida!" :
		"Nao deu pra resolver a terceira camada ;-(");
	CUB_ExibirCUBO(cubo);
	printf("\nRelatorio da terceira camada: %s\n\n", relatorio3);
	
}

void main()
{
	programaPrincipal();

	system("pause");
}