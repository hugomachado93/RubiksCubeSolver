/******************************************************************************
*
*  $MCD M�dulo de defini��o: CUB  Cubo m�gico
*
*  Arquivo gerado:              CUBO.h
*  Letras identificadoras:      CUB
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: dlas	Daniel Luca Alves da Silva
sgmpm	Sergio Gustavo Mendon�a Pyrrho Moreira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	  11	  dlas   02/maio/2018 ajustes e implementa��o
*	  10	  sgmpm  29/mar/2018 revis�o final
*	  9		  sgmpm	 28/mar/2018 formata��o e revis�o
*	  8		  dlas	 28/mar/2018 implementa��o fun��o busca quina
*	  7		  dlas	 26/mar/2018 implementa��o fun��o busca aresta
*	  6		  dlas	 25/mar/2018 implementa��o da fun��o giro
*	  5		  dlas	 19/mar/2018 Mudan�a do arquivo interface
*	  4		  sgmpm  18/mar/2018 Revisao
*	  3		  sgmpm	 16/mar/2018 Otimiza��o
*	  2		  dlas	 12/mar/2018 Implementa��o das fun��es
*     1       dlas   07/mar/2018 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*		Implementa Cubos m�gicos.
*
*		O m�dulo implementa a representa��o de cubos m�gicos de posi��o fixa
*			que s�o manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face ter� sempre o mesmo valor.
*			O cubo deve ser inicializado com um vetor de inteiros, na ordem
*			definida na fun��o de exibi��o.
*
******************************************************************************/

#include "CUBO.h"

#include <stdio.h>
#include <stdlib.h>

#define NUMERODEFACES 6
#define UNIDADESPOREIXO 3

typedef struct
{
	int lados[NUMERODEFACES];
} CUB_tpPecadeCubo; //Definindo a estrutura que compoe o cubo;

typedef struct
{
	CUB_tpPecadeCubo estrutura[27]; //Definindo a estrutura do cubo com suas faces detalhadas;
} CUB_tagCUBO;

/***** Prot�tipos das fun��es encapsuladas pelos modulo*****/

static void funcaoDebugger(CUB_tagCUBO* cubo); //Documentado dentro da fun��o;

static void matriz3DParaLinhaEColuna(int *linha, int *coluna, CUB_tpFaceDeCUBO face, int x, int y, int z); //Documentado dentro da fun��o;

static void preencherCuboVazio(CUB_tagCUBO* recipiente, int* configuracaoInicial); //Documentado dentro da fun��o;

static void preencherPosicao(CUB_tagCUBO* recipiente, int x, int y, int z, CUB_tpFaceDeCUBO face, int valor); //Documentado dentro da fun��o;

static void imprimirElemento(CUB_tagCUBO* cubo, int x, int y, int z, CUB_tpFaceDeCUBO face); //Documentado dentro da fun��o;

static CUB_tpPecadeCubo giroDePecaUnitarioEixoX(CUB_tpPecadeCubo peca); //Documentado dentro da fun��o
static CUB_tpPecadeCubo giroDePecaUnitarioEixoY(CUB_tpPecadeCubo peca); //Documentado dentro da fun��o
static CUB_tpPecadeCubo giroDePecaUnitarioEixoZ(CUB_tpPecadeCubo peca); //Documentado dentro da fun��o

static int calcularGirosUnitarios(int numeroDeGiros, CUB_tpFaceDeCUBO face); //Documentado dentro da fun��o

static int geraIndice(int x, int y, int z); //Documentado dentro da fun��o

static int geraIndiceEmBuffer(int a, int b); //Documentado dentro da fun��o

static int conjuntosSaoEquivalentes(int elementoA1, int elementoA2, int elementoB1, int elementoB2); //Documentado dentro da fun��o

static int configuracaoInicialEstaConsistente(CUB_tpConfiguracao configuracaoInicial);

static int obtemIndice(int* vetor, int tam, int chave);

static void zeraVetor(int* vetor, int tam);


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Func�o: CUB Criar cubo
*
***************************************************************************/

CUB_tpCondRet CUB_CriarCUBO(CUB_tppCUBO* pCubo, CUB_tpConfiguracao ConfiguracaoInicial) //Fun��o para cria��o do cubo
{
	CUB_tagCUBO* candidato; //Variavel auxiliar para cria��o da estrutura do cubo
	candidato = (CUB_tagCUBO*)malloc(sizeof(CUB_tagCUBO));
	if (!configuracaoInicialEstaConsistente(ConfiguracaoInicial))
		return CUB_CondRetConfiguracaoInvalida;
	if (candidato == NULL)
		return CUB_CondRetFaltouMemoria; //Retorna em caso de falta de espa�o na mem�ria
	preencherCuboVazio(candidato, ConfiguracaoInicial.cores);
	*pCubo = candidato;
	return CUB_CondRetOK; //Retorna em caso de inser��o bem sucedida da estrutura do cubo na mem�ria
}

/***************************************************************************
*
*  Func�o: CUB destroi cubo
*
***************************************************************************/

CUB_tpCondRet CUB_DestruirCUBO(CUB_tppCUBO pCubo) //Fun��o para destruir a estrutura do cubo
{
	free(pCubo);
	return CUB_CondRetOK; //Retorna positivamenta a destrui��o do cubo
}

/***************************************************************************
*
*  Func�o: CUB girar face do cubo
*
***************************************************************************/

CUB_tpCondRet CUB_GirarFace(CUB_tppCUBO pCubo, CUB_tpFaceDeCUBO faceGirada, int numGiros, char sentido) //Fun��o para girar as faces do cubo
{

	CUB_tagCUBO* cubo = pCubo;
	CUB_tpPecadeCubo peca;
	CUB_tpPecadeCubo buffer[9];
	int x, y, z;

	if (pCubo == NULL) return CUB_CondRetCuboInvalido; //Retorna caso o cubo inserido seja inv�lido e/ou inexistente

	numGiros = (sentido == 'a' || sentido == 'A') ? -abs(numGiros) : abs(numGiros);

	if (faceGirada > CUB_faceInferior || faceGirada < CUB_faceSuperior)
		return CUB_CondRetFaceInvalida; //Retorna caso a face especificada seja inv�lida e/ou inexistente

	if (faceGirada == CUB_faceFrontal || faceGirada == CUB_faceTraseira) //Caso o giro seja relacionado a face frontal ou face traseira
	{
		z = faceGirada == CUB_faceTraseira ? -1 : 1;
		numGiros = calcularGirosUnitarios(numGiros, faceGirada);
		while (numGiros--)
		{
			for (x = -1; x <= 1; x++)
			{
				for (y = -1; y <= 1; y++)
				{
					peca = giroDePecaUnitarioEixoZ(cubo->estrutura[geraIndice(x, y, z)]);
					buffer[geraIndiceEmBuffer(x, y)] = peca; //Gira a pe�a especificada e atualiza o indice junto
				}
			}
			for (x = -1; x <= 1; x++)
				for (y = -1; y <= 1; y++)
					cubo->estrutura[geraIndice(y, -x, z)] = buffer[geraIndiceEmBuffer(x, y)]; //Passa o indice gerado para estrutura do cubo
		}
	}

	if (faceGirada == CUB_faceSuperior || faceGirada == CUB_faceInferior) //Caso o giro seja relacionado a face superior ou face inferior
	{
		y = faceGirada == CUB_faceInferior ? -1 : 1;
		numGiros = calcularGirosUnitarios(numGiros, faceGirada);
		while (numGiros--)
		{
			for (x = -1; x <= 1; x++)
			{
				for (z = -1; z <= 1; z++)
				{
					peca = giroDePecaUnitarioEixoY(cubo->estrutura[geraIndice(x, y, z)]);
					buffer[geraIndiceEmBuffer(x, z)] = peca; //Gira a pe�a especificada e atualiza o indice junto
				}
			}
			for (x = -1; x <= 1; x++)
				for (z = -1; z <= 1; z++)
					cubo->estrutura[geraIndice(-z, y, x)] = buffer[geraIndiceEmBuffer(x, z)]; //Passa o indice gerado para estrutura do cubo
		}
	}

	if (faceGirada == CUB_faceDireita || faceGirada == CUB_faceEsquerda) //Caso o giro seja relacionado a face esquerda ou face direita
	{
		x = faceGirada == CUB_faceEsquerda ? -1 : 1;
		numGiros = calcularGirosUnitarios(numGiros, faceGirada);
		while (numGiros--)
		{
			for (y = -1; y <= 1; y++)
			{
				for (z = -1; z <= 1; z++)
				{
					peca = giroDePecaUnitarioEixoX(cubo->estrutura[geraIndice(x, y, z)]);
					buffer[geraIndiceEmBuffer(y, z)] = peca; //Gira a pe�a especificada e atualiza o indice junto
				}
			}
			for (y = -1; y <= 1; y++)
				for (z = -1; z <= 1; z++)
					cubo->estrutura[geraIndice(x, z, -y)] = buffer[geraIndiceEmBuffer(y, z)]; //Passa o indice gerado para estrutura do cubo
		}
	}

	return CUB_CondRetOK; //Retorna que o cubo foi girado com sucesso
}

/***************************************************************************
*
*  Func�o: CUB checar cor da face do cubo
*
***************************************************************************/

CUB_tpCondRet CUB_ChecarCorDaFace(int * pCor, CUB_tppCUBO pCubo, int linha, int coluna, CUB_tpFaceDeCUBO faceInspecionada) //Fun��o para checar a cor da face em quest�o
{
	CUB_tagCUBO* cubo = pCubo;
	int x, y, z;

	if (pCubo == NULL) return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inv�lido e/ou inexistente

	if (linha < 0 || linha >= UNIDADESPOREIXO)
		return CUB_CondRetCoordenadasInvalidas; //Retorna caso as coordenadas especificadas sejam inv�lidas
	if (coluna < 0 || coluna >= UNIDADESPOREIXO)
		return CUB_CondRetCoordenadasInvalidas; //Retorna caso as coordenadas especificadas sejam inv�lidas
	switch (faceInspecionada)
	{
	case(CUB_faceSuperior): //Caso seja a face superior
		x = coluna - 1;
		y = 1;
		z = linha - 1;
		break;
	case(CUB_faceFrontal): //Caso seja a face frontal
		x = coluna - 1;
		y = 1 - linha;
		z = 1;
		break;
	case(CUB_faceDireita): //Caso seja a face da direita
		x = 1;
		y = 1 - linha;
		z = 1 - coluna;
		break;
	case(CUB_faceTraseira): //Caso seja a face traseira
		x = 1 - coluna;
		y = 1 - linha;
		z = -1;
		break;
	case(CUB_faceEsquerda): //Caso seja a face da esquerda
		x = -1;
		y = 1 - linha;
		z = coluna - 1;
		break;
	case(CUB_faceInferior): //Caso seja a face inferior
		x = coluna - 1;
		y = -1;
		z = 1 - linha;
		break;
	default:
		return CUB_CondRetFaceInvalida; //Retorna em caso da face especificada ser inv�lida
	}
	*pCor = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada];
	return CUB_CondRetOK; //Retorna o sucesso da fun��o
}

/***************************************************************************
*
*  Func�o: CUB Encontrar posi��o de aresta do cubo
*
***************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeAresta(CUB_tpFaceDeCUBO * pFace, int * pLinha, int * pColuna, CUB_tppCUBO pCubo, int cor1, int cor2) //Fun��o que verifica a pe�a na aresta
{
	int x, y, z;
	CUB_tpFaceDeCUBO valorNaFace1, valorNaFace2, faceInspecionada1, faceInspecionada2;
	CUB_tagCUBO* cubo = pCubo;

	if (cubo == NULL)
		return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inv�lido e/ou inexistente

	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			for (z = -1; z <= 1; z++)
			{
				if (abs(x) + abs(y) + abs(z) == 2)
				{
					if (x < 0)
						faceInspecionada1 = CUB_faceEsquerda;
					else if (x > 0)
						faceInspecionada1 = CUB_faceDireita;
					else if (y < 0)
						faceInspecionada1 = CUB_faceInferior;
					else
						faceInspecionada1 = CUB_faceSuperior;

					if (z < 0)
						faceInspecionada2 = CUB_faceTraseira;
					else if (z > 0)
						faceInspecionada2 = CUB_faceFrontal;
					else if (y < 0)
						faceInspecionada2 = CUB_faceInferior;
					else
						faceInspecionada2 = CUB_faceSuperior;

					valorNaFace1 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada1];
					valorNaFace2 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada2];
					if (valorNaFace1 == cor1 && valorNaFace2 == cor2)
					{
						*pFace = faceInspecionada1;
						matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada1, x, y, z);
						return CUB_CondRetOK; //Retorna caso a pe�a foi encontrada com sucesso
					}
					else if (valorNaFace1 == cor2 && valorNaFace2 == cor1)
					{
						*pFace = faceInspecionada2;
						matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada2, x, y, z);
						return CUB_CondRetOK; //Retorna caso a pe�a foi encontrada com sucesso
					}
				}
			}
		}
	}
	return CUB_CondRetCorInvalida; //Retorna caso a cor especificada seja inv�lida
}

/***************************************************************************
*
*  Func�o: CUB encontrar posi��o da pe�a da quina
*
***************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeQuina(CUB_tpFaceDeCUBO * pFace, int * pLinha, int * pColuna, CUB_tppCUBO pCubo, int cor1, int cor2, int cor3) //Fun��o para busca de pe�a de quina de cubo
{
	int x, y, z, valorNaFace1, valorNaFace2, valorNaFace3;
	CUB_tpFaceDeCUBO faceInspecionada1, faceInspecionada2, faceInspecionada3;
	CUB_tagCUBO* cubo = pCubo;
	faceInspecionada1 = CUB_faceEsquerda;

	if (cubo == NULL)
		return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inv�lido


	for (x = -1; x <= 1; x = x + 2)
	{
		faceInspecionada2 = CUB_faceInferior;
		for (y = -1; y <= 1; y = y + 2)
		{
			faceInspecionada3 = CUB_faceTraseira;
			for (z = -1; z <= 1; z = z + 2)
			{
				valorNaFace1 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada1];
				valorNaFace2 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada2];
				valorNaFace3 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada3];


				if (valorNaFace1 == cor1 && conjuntosSaoEquivalentes(valorNaFace2, valorNaFace3, cor2, cor3))
				{
					*pFace = faceInspecionada1;
					matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada1, x, y, z);
					return CUB_CondRetOK; //Retorna caso a pe�a de quina seja encontrada com sucesso
				}
				else if (valorNaFace2 == cor1 && conjuntosSaoEquivalentes(valorNaFace1, valorNaFace3, cor2, cor3))
				{
					*pFace = faceInspecionada2;
					matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada2, x, y, z);
					return CUB_CondRetOK; //Retorna caso a pe�a de quina seja encontrada com sucesso
				}
				else if (valorNaFace3 == cor1 && conjuntosSaoEquivalentes(valorNaFace1, valorNaFace2, cor2, cor3))
				{
					*pFace = faceInspecionada3;
					matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada3, x, y, z);
					return CUB_CondRetOK; //Retorna caso a pe�a de quina seja encontrada com sucesso
				}

				faceInspecionada3 = CUB_faceFrontal;
			}
			faceInspecionada2 = CUB_faceSuperior;
		}
		faceInspecionada1 = CUB_faceDireita;
	}
	return CUB_CondRetCorInvalida; //Retorna caso a cor requisitada seja inv�lida
}

/***************************************************************************
*
*  Func�o: CUB exibir o cubo
*
***************************************************************************/

CUB_tpCondRet CUB_ExibirCUBO(CUB_tppCUBO pCubo) //Fun��o que exibe o cubo em seu estado atual
{
	int x, y, z;
	CUB_tagCUBO* cubo = pCubo;

	if (pCubo == NULL) return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inv�lido

													   // Printando Face Superior
	for (z = -1; z <= 1; z++)
	{
		printf("\t\t\t");
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, x, 1, z, CUB_faceSuperior);
		printf("\n");
	}
	//Printando linha a linha as diferentes faces intermediarias
	for (y = 1; y >= -1; y--)
	{
		for (z = -1; z <= 1; z++)
			imprimirElemento(cubo, -1, y, z, CUB_faceEsquerda);
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, x, y, 1, CUB_faceFrontal);
		for (z = -1; z <= 1; z++)
			imprimirElemento(cubo, 1, y, -z, CUB_faceDireita);
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, -x, y, -1, CUB_faceTraseira);
		printf("\n");
	}
	//Printando a face Inferior
	for (z = -1; z <= 1; z++)
	{
		printf("\t\t\t");
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, x, -1, -z, CUB_faceInferior);
		printf("\n");
	}

	return CUB_CondRetOK; //Retorna caso a exibi��o do cubo tenha sido realizada com �xito
}

/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***************************************************************************
*
*  Func�o: CUB conjunto sao equivalentes
*
***************************************************************************/

int conjuntosSaoEquivalentes(int elementoA1, int elementoA2, int elementoB1, int elementoB2) //Fun��o que determina se conjuntos s�o ou n�o equivalentes
{
	if ((elementoA1 == elementoB1 && elementoA2 == elementoB2)
		|| (elementoA1 == elementoB2 && elementoA2 == elementoB1))
		return 1; //Retorna caso os conjuntos sejam equivalentes
	return 0; //Retorna caso n�o haja conjuntos equivalentes
}

/***************************************************************************
*
*  Func�o: CUB calcular giros unitarios
*
***************************************************************************/

int calcularGirosUnitarios(int numeroDeGiros, CUB_tpFaceDeCUBO face) //Fun��o de c�lculo de giros unit�rios a serem realizados
{
	// Primeiramente s�o eliminadas as redund�ncias dos giros de 360�
	int equivalente = numeroDeGiros % 4;
	// Em seguida � necess�rio adequar os giros em rela��o � face
	if (face == CUB_faceTraseira || face == CUB_faceEsquerda || face == CUB_faceInferior)
		equivalente = 4 - equivalente;
	return equivalente < 0 ? equivalente + 4 : equivalente; //Retorna o numero de giros unit�rios a serem realizados
}

/***************************************************************************
*
*  Func�o: CUB preecher cubo
*
***************************************************************************/

void preencherCuboVazio(CUB_tagCUBO* recipiente, int* configuracaoInicial) //Fun��o de preenchimento do cubo vazio
{
	int x, y, z;
	int *chaveAtual = configuracaoInicial;
	for (z = -1; z <= 1; z++)
	{
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, x, 1, z, CUB_faceSuperior, *chaveAtual++);
		}
	}
	for (y = 1; y >= -1; y--)
	{
		for (z = -1; z <= 1; z++)
		{
			preencherPosicao(recipiente, -1, y, z, CUB_faceEsquerda, *chaveAtual++);
		}
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, x, y, 1, CUB_faceFrontal, *chaveAtual++);
		}
		for (z = -1; z <= 1; z++)
		{
			preencherPosicao(recipiente, 1, y, -z, CUB_faceDireita, *chaveAtual++);
		}
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, -x, y, -1, CUB_faceTraseira, *chaveAtual++);
		}
	}
	for (z = -1; z <= 1; z++)
	{
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, x, -1, -z, CUB_faceInferior, *chaveAtual++);
		}
	}
} //Fun��o apenas preenche o cubo com as cores em suas respectivas posi��es assim como declaradas em sua inser��o

  /***************************************************************************
  *
  *  Func�o: CUB gerar o indice
  *
  ***************************************************************************/

int geraIndice(int x, int y, int z) //Fun��o que gera o indice de localiza��o de cada elemento do cubo
{
	// Somar 1 em cada coordenada equivale � uma transforma��o afim
	x = x + 1;
	y = y + 1;
	z = z + 1;
	return UNIDADESPOREIXO * (UNIDADESPOREIXO * z + y) + x; //Retorna o indice inicializado e preenchido
}

/***************************************************************************
*
*  Func�o: CUB gerar o indice para o buffer
*
***************************************************************************/

int geraIndiceEmBuffer(int a, int b) //Fun��o que gera o �ndice em um 'buffer' voltado para acesso r�pido
{
	a = a + 1;
	b = b + 1;
	return UNIDADESPOREIXO * b + a; //Retorna o indice inicializado no 'buffer'
}

/***************************************************************************
*
*  Func�o: CUB imprimir elemento
*
***************************************************************************/

void imprimirElemento(CUB_tagCUBO* cubo, int x, int y, int z, CUB_tpFaceDeCUBO face) //Fun��o que imprime o elemento especificado do cubo
{
	CUB_tpPecadeCubo unidadeDeCubo = cubo->estrutura[geraIndice(x, y, z)];
	int valor = unidadeDeCubo.lados[face];
	printf("\t%d", valor < 0 ? -1 : valor);
} //Fun��o n�o possui retorno, apenas realiza a impress�o do elemento especificado

  /***************************************************************************
  *
  *  Func�o: CUB preencher a posi��o
  *
  ***************************************************************************/

void preencherPosicao(CUB_tagCUBO* recipiente, int x, int y, int z, CUB_tpFaceDeCUBO face, int valor) //Fun��o que preenche uma posi��o no cubo
{
	int indice = geraIndice(x, y, z);
	recipiente->estrutura[indice].lados[face] = valor;
} //N�o h� retorno, apenas preenche elementos dentro da matriz do cubo

  /***************************************************************************
  *
  *  Func�o: CUB giro de pe�a unitario no eixo X
  *
  ***************************************************************************/

CUB_tpPecadeCubo giroDePecaUnitarioEixoX(CUB_tpPecadeCubo peca) //Fun��o de giro no eixo 'X'
{
	int aux;
	aux = peca.lados[CUB_faceSuperior];
	peca.lados[CUB_faceSuperior] = peca.lados[CUB_faceFrontal];
	peca.lados[CUB_faceFrontal] = peca.lados[CUB_faceInferior];
	peca.lados[CUB_faceInferior] = peca.lados[CUB_faceTraseira];
	peca.lados[CUB_faceTraseira] = aux;
	return peca; //Retorna a nova posi��o da pe�a no eixo 'X'
}

/***************************************************************************
*
*  Func�o: CUB giro de pe�a unitario no eixo Y
*
***************************************************************************/

CUB_tpPecadeCubo giroDePecaUnitarioEixoY(CUB_tpPecadeCubo peca) //Fun��o de giro no eixo 'Y'
{
	int aux;
	aux = peca.lados[CUB_faceTraseira];
	peca.lados[CUB_faceTraseira] = peca.lados[CUB_faceEsquerda];
	peca.lados[CUB_faceEsquerda] = peca.lados[CUB_faceFrontal];
	peca.lados[CUB_faceFrontal] = peca.lados[CUB_faceDireita];
	peca.lados[CUB_faceDireita] = aux;
	return peca; //Retorna a nova posi��o da pe�a no eixo 'Y'
}

/***************************************************************************
*
*  Func�o: CUB giro de pe�a unitario no eixo Z
*
***************************************************************************/

CUB_tpPecadeCubo giroDePecaUnitarioEixoZ(CUB_tpPecadeCubo peca) //Fun��o de giro no eixo 'Z'
{
	int aux;
	aux = peca.lados[CUB_faceSuperior];
	peca.lados[CUB_faceSuperior] = peca.lados[CUB_faceEsquerda];
	peca.lados[CUB_faceEsquerda] = peca.lados[CUB_faceInferior];
	peca.lados[CUB_faceInferior] = peca.lados[CUB_faceDireita];
	peca.lados[CUB_faceDireita] = aux;
	return peca; //Retorna a nova posi��o da pe�a no eixo 'Z'
}

/***************************************************************************
*
*  Func�o: CUB matriz 3d para linha e coluna
*
***************************************************************************/

void matriz3DParaLinhaEColuna(int *linha, int *coluna, CUB_tpFaceDeCUBO face, int x, int y, int z) //Fun��o de cria��o da matriz 3D para estrutura do cubo
{
	switch (face)
	{
	case(CUB_faceSuperior):
		*linha = z + 1;
		*coluna = x + 1;
		break;

	case(CUB_faceFrontal):
		*linha = 1 - y;
		*coluna = x + 1;
		break;

	case(CUB_faceDireita):
		*linha = 1 - y;
		*coluna = 1 - z;
		break;

	case(CUB_faceTraseira):
		*linha = 1 - y;
		*coluna = 1 - x;
		break;

	case(CUB_faceEsquerda):
		*linha = 1 - y;
		*coluna = z + 1;
		break;

	case(CUB_faceInferior):
		*linha = 1 - z;
		*coluna = x + 1;

		break;
	}
} // Realiza a cria��o da matriz tridimensional apenas

  /***************************************************************************
  *
  *  Func�o: CUB debugger
  *
  ***************************************************************************/

void funcaoDebugger(CUB_tagCUBO* cubo) //Fun��o de exibi��o teste para o cubo
{
	int i, f;
	char* strings[] = { "CUB_faceSuperior",		"CUB_faceFrontal",		"CUB_faceDireita",
		"CUB_faceTraseira",		"CUB_faceEsquerda",		"CUB_faceInferior" };
	//string contendo todas as faces do cubo em seu atual estado;
	for (f = 0; f < 27; f++)
	{
		for (i = CUB_faceSuperior; i <= CUB_faceInferior; i++)
		{
			printf("Peca numero %d, ", f);
			printf(strings[i]);
			printf(": %d\n", cubo->estrutura[f].lados[i] < 0 ? -1 : cubo->estrutura[f].lados[i]);
		} //Fun��o que imprime cada um dos lados do cubo, ou seja, exibe todas as faces menores com suas configura��es atuais;
	}
	printf("\n\n");
} //Apenas uma fun��o de teste para visualiza��o das pe�as em suas respectivas posi��es no cubo

  /***************************************************************************
  *
  *  Func�o: CUB Obtem indice do vetor
  *
  ***************************************************************************/

int obtemIndice(int* vetor, int tam, int chave)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		if (vetor[i] == chave)
			return i;
	}
	return -1;
}

/***************************************************************************
*
*  Func�o: CUB Zera vetor
*
***************************************************************************/

void zeraVetor(int* vetor, int tam)
{
	int i;
	for (i = 0; i < tam; i++)
		vetor[i] = 0;
}

/***************************************************************************
*
*  Func�o: CUB Configura��o inicial esta consistente
*
***************************************************************************/

int configuracaoInicialEstaConsistente(CUB_tpConfiguracao configuracaoInicial)
{
	int i, pos, cor;
	int coresEncontradas[NUMERODEFACES];
	int ocorrencias[NUMERODEFACES];
	int numDeCoresEncontradas = 0;

	zeraVetor(ocorrencias, NUMERODEFACES);
	for (i = 0; i < NUMERODEFACES*UNIDADESPOREIXO*UNIDADESPOREIXO; i++)
	{
		cor = configuracaoInicial.cores[i];
		pos = obtemIndice(coresEncontradas, numDeCoresEncontradas, cor);
		if (pos < 0) // Cor nao encontrada no vetor nesse momento
		{
			if (numDeCoresEncontradas >= NUMERODEFACES)
				return 0; // O cubo cont�m mais do que 6 cores
			coresEncontradas[numDeCoresEncontradas] = cor;
			ocorrencias[numDeCoresEncontradas] += 1;
			numDeCoresEncontradas++;
		}
		else
		{
			ocorrencias[pos] += 1;
			if (ocorrencias[pos] > UNIDADESPOREIXO*UNIDADESPOREIXO)
				return 0; // A cor possui mais de 9 ocorr�ncias
		}
	}
	return 1;
} //Funcao que checa se o vetor est� com 6 cores de 9 ocorr�ncias cada