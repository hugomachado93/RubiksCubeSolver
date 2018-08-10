/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC

/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: bl    Bruno Leão
		    ms    Mariana Salgueiro
		    pf    Pilar Fernandez
	     	gf    Gabriel Faria   
*
*  $HA Histórico de evolução:
*    Versão		Autor          Data			Observações
*	  7		  pf ms bl gf   03/maio/2018	finalização
*     6       pf ms bl gf   02/maio/2018	ajustes e continução do desenvolvimento
*     5       pf ms bl gf   01/maio/2018	ajustes e continuação do desenvolvimento
*	  4       pf ms bl gf   28/abr/2018		ajustes e continuação do desenvolvimento
*	  3       pf ms bl      27/abr/2018		ajustes e continuação do desenvolvimento
*	  2		  pf ms bl      26/abr/2018		ajustes e continuação do desenvolvimento
*     1       pf ms bl      25/abr/2018		início 
*
*
*
*  $ED Descrição do módulo
*		Implementa a primeira camada da resolução de um cubo mágico
*
*		O módulo implementa a representação de cubos mágicos de posição fixa
*			que são manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face terá sempre o mesmo valor.
*			O cubo deve ser inicializado com um vetor de inteiros, na ordem
*			definida na função de exibição.
*
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "CUBO.h"
#include "Camada1.h"
#include <string.h>

#define BRANCO 0
#define LARANJA 1
#define VERDE 2
#define VERMELHO 3
#define AZUL 4
#define AMARELO 5


/***************************************************************************
 *
 *  Funcão: fazCamada1
 *  
 ***************************************************************************/


CUB_tpCondRet fazCamada1(CUB_tppCUBO pCubo, char Comandos[]){

	int j = 0; 	
	CUB_tpFaceDeCUBO pFace[8];
	int pLinha[8]; 
	int pColuna[8]; 
	if(pCubo == NULL){
		return CUB_CondRetCuboNaoExiste;
	}
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[0], &pLinha[0], &pColuna[0], pCubo, 0, 2); //branco e verde
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[1], &pLinha[1], &pColuna[1], pCubo, 0, 3); //branco e vermelho
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[2], &pLinha[2], &pColuna[2], pCubo, 0, 4); //branco e azul
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[3], &pLinha[3], &pColuna[3], pCubo, 0, 1); //branco e laranja
	
	while(!(j==4||(pFace[0] == 0 && pLinha[0] == 2 && pColuna[0] == 1) && (pFace[1] == 0 && pLinha[1] == 1 && pColuna[1] == 2) && (pFace[2] == 0 && pLinha[2] == 0 && pColuna[2] == 1) && (pFace[3] == 0 && pLinha[3] == 1 && pColuna[3] == 0)))
	{
		if(j == 0){ // branca e verde
			if (pFace[j] == CUB_faceSuperior && pLinha[j] == 0 && pColuna[j] == 1){ //U2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcpy(Comandos, "Girar 2x Face Traseira'h ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 0 && pColuna[j] == 1){ //B2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_EncontrarPosicaoDePecaDeAresta(&pFace[1], &pLinha[1], &pColuna[1], pCubo, 0, 3); //branco e vermelho
			}
			else if(pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 0){ //U4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 2){ //U6
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'a');
				strcat(Comandos, "Girar 2x Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face Frontal H, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 0 && pColuna[j] == 1){ //R2
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'a');
				strcat(Comandos, "Girar 2x Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 0 && pColuna[j] == 1){ //F2
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitalH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');	
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1) //D2
			{
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');				
				strcat(Comandos, "Girar Face DireitalH, ");				
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			} 
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face Frontala, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //L4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');	
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');	
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 0){ //D4
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');	
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');	
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
			}
		}
	
		if(j == 1){ // branca e vermelha
			CUB_EncontrarPosicaoDePecaDeAresta(&pFace[1], &pLinha[1], &pColuna[1], pCubo, 0, 3);
			if (pFace[j] == CUB_faceSuperior && pLinha[j] == 0 && pColuna[j] == 1){ //U2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 0 && pColuna[j] == 1){ //B2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 0){ //U4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 0 && pColuna[j] == 1){ //R2
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireiraA, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2xFace DireitaH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1){ //D2
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face Inferior, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');	
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 0){ //D4
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
			}
		}

		if(j == 2){ // branca e azul
			CUB_EncontrarPosicaoDePecaDeAresta(&pFace[2], &pLinha[2], &pColuna[2], pCubo, 0, 4); //branco e azul
			if(pFace[j] == CUB_faceTraseira && pLinha[j] == 0 && pColuna[j] == 1){ //B2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			if (pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 0){ //U4	
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'a');
				strcat(Comandos, "Girar 2x Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseriaA, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1){ //D2
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}

			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h'); 
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');	
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiralH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B5 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiroH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //L4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D4
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
		}

		if(j == 3){ // branca e laranja
			CUB_EncontrarPosicaoDePecaDeAresta(&pFace[3], &pLinha[3], &pColuna[3], pCubo, 0, 1); //branco e laranja
			if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face Esquerda, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1){ //D2
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');	
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');	
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "Girar Face DiretaH, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face Esquerda, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B6
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //L4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');	
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');	
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 0){ //D4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "Girar Face FrontalH, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
			}
		}
		j++;
	}	

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, 0, 2, 3); //Branca Verde Vermelha
	if((pFace[4] == CUB_faceTraseira && pLinha[4]  == 2 && pColuna[4] ==  2) || (pFace[4] == CUB_faceInferior && pLinha[4]  == 2  && pColuna[4] == 0) || (pFace[4] == CUB_faceEsquerda && pLinha[4]  == 2 && pColuna[4] == 0) )
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "Girar 2x Face InferiorH, ");
	}
	else if((pFace[4] == CUB_faceFrontal && pLinha[4] == 2 && pColuna[4] == 0) || (pFace[4] == CUB_faceInferior && pLinha[4] == 0 && pColuna[4] == 0) || (pFace[4] == CUB_faceEsquerda && pLinha[4] == 2 && pColuna[4] == 2) )
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
	}
	else if((pFace[4] == CUB_faceTraseira && pLinha[4] == 2 && pColuna[4] == 0) || (pFace[4] == CUB_faceInferior && pLinha[4] == 2 && pColuna[4] == 1) || (pFace[4] == CUB_faceDireita && pLinha[4] == 2 && pColuna[4] == 2) )
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
	}
	else if((pFace[4] == CUB_faceTraseira && pLinha[4] == 0 && pColuna[4] == 2) || (pFace[4] == CUB_faceSuperior && pLinha[4] == 0 && pColuna[4] == 0) || (pFace[4] == CUB_faceEsquerda && pLinha[4] == 0 && pColuna[4] == 0) )
	{
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "Girar Face EsquerdaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
		strcat(Comandos, "Girar 2x Face InferiorA, ");
	}
	else if((pFace[4] == CUB_faceTraseira && pLinha[4] == 0 && pColuna[4] == 0) || (pFace[4] == CUB_faceSuperior && pLinha[4] == 0 && pColuna[4] == 2) || (pFace[4] == CUB_faceDireita && pLinha[4] == 0 && pColuna[4] == 2)) {
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
		strcat(Comandos, "Girar Face DireitaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
		strcat(Comandos, "Girar Face DireitaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
	}
	else if((pFace[4] == CUB_faceFrontal && pLinha[4] == 0 && pColuna[4] == 0 ) || (pFace[4] == CUB_faceSuperior && pLinha[4] == 2 && pColuna[4] == 0 ) ||(pFace[4] == CUB_faceEsquerda && pLinha[4] == 0 && pColuna[4] == 2 ))
	{
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "Girar Face EsquerdaA, ");
	}

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, 0, 2, 3);
	while(!(pFace[4] == CUB_faceSuperior && pLinha[4] == 2 && pColuna[4] == 2)){
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
		strcat(Comandos, "Girar Face DireitaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
		strcat(Comandos, "Girar Face DireitaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, 0, 2, 3);
	}
	
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, 0, 3, 4); //branco, vermelho e azul;

	if((pFace[5] == CUB_faceEsquerda && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceInferior && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceTraseira && pLinha[5] == 2 && pColuna[5] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
	}
	else if((pFace[5] == CUB_faceInferior && pLinha[5] == 0 && pColuna[5] == 0) || (pFace[5] == CUB_faceFrontal && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceEsquerda && pLinha[5] == 2 && pColuna[5] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "Girar 2x Face InferiorH, ");
	}
	else if((pFace[5] == CUB_faceInferior && pLinha[5] == 0 && pColuna[5] == 2) || (pFace[5] == CUB_faceFrontal && pLinha[5] == 2 && pColuna[5] == 2) || (pFace[5] == CUB_faceDireita && pLinha[5] == 2 && pColuna[5] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar 2x Face InferiorH, ");
	}
	else if((pFace[5] == CUB_faceSuperior && pLinha[5] == 0 && pColuna[5] == 0) || (pFace[5] == CUB_faceTraseira && pLinha[5] == 0 && pColuna[5] == 2) || (pFace[5] == CUB_faceEsquerda && pLinha[5] == 0 && pColuna[5] == 0)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "Girar Face EsquerdaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaH, ");
	}
	else if((pFace[5] == CUB_faceSuperior && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceFrontal && pLinha[5] == 0 && pColuna[5] == 0) || (pFace[5] == CUB_faceEsquerda && pLinha[5] == 0 && pColuna[5] == 2)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "Girar 2x Face InferiorH, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');	
		strcat(Comandos, "Girar Face EsquerdaA, ");
	}

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, 0, 3, 4);

	while(!(pFace[5] == CUB_faceSuperior && pLinha[5] == 0 && pColuna[5] == 2)){
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
		strcat(Comandos, "Girar Face DireitaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
		strcat(Comandos, "Girar Face DireitaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, 0, 3, 4);
	}

	CUB_EncontrarPosicaoDePecaDeQuina (&pFace[6], &pLinha[6], &pColuna[6], pCubo, 0, 1, 4); // azul branco laranja

	if((pFace[6] == CUB_faceFrontal && pLinha[6] == 2 && pColuna[6] == 0) || (pFace[6] == CUB_faceInferior && pLinha[6] == 0 && pColuna[6] == 0) || (pFace[6] == CUB_faceEsquerda && pLinha[6] == 2 && pColuna[6] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior,1,'a');
		strcat(Comandos, "Girar Face InferiorA, ");
	}
	else if((pFace[6] == CUB_faceFrontal && pLinha[6] == 2 && pColuna[6] == 2) || (pFace[6] == CUB_faceInferior && pLinha[6] == 0 && pColuna[6] == 2) || (pFace[6] == CUB_faceDireita && pLinha[6] == 2 && pColuna[6] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior,2,'a');
		strcat(Comandos, "Girar 2x Face InferiorA, ");
	}
	else if ((pFace[6] == CUB_faceTraseira && pLinha[6] == 2 && pColuna[6] == 0) || (pFace[6] == CUB_faceInferior && pLinha[6] == 2 && pColuna[6] == 2) || (pFace[6] == CUB_faceDireita && pLinha[6] == 2 && pColuna[6] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
	}
	else if ((pFace[6] == CUB_faceFrontal && pLinha[6] == 0 && pColuna[6] == 0) || (pFace[6] == CUB_faceSuperior && pLinha[6] == 2 && pColuna[6] == 0) || (pFace[6] == CUB_faceEsquerda && pLinha[6] == 0 && pColuna[6] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "Girar 2x Face InferiorA, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "Girar Face EsquerdaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
	}


	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[6], &pLinha[6], &pColuna[6], pCubo, 0, 1, 4);
	while(!(pFace[6] == CUB_faceSuperior && pLinha[6] == 0 && pColuna[6] == 0)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "Girar Face EsquerdaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[6], &pLinha[6], &pColuna[6], pCubo, 0, 1, 4);
	}	

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, 0, 2, 1); //branco, verde e laranja;

	if((pFace[7] == CUB_faceInferior && pLinha[7] == 2 && pColuna[7] == 0) || (pFace[7] == CUB_faceTraseira && pLinha[7] == 2 && pColuna[7] == 2) || (pFace[7] == CUB_faceEsquerda && pLinha[7] == 2 && pColuna[7] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
	}
	else if((pFace[7] == CUB_faceInferior && pLinha[7] == 0 && pColuna[7] == 2) || (pFace[7] == CUB_faceFrontal && pLinha[7] == 2 && pColuna[7] == 2) || (pFace[7] == CUB_faceDireita && pLinha[7] == 2 && pColuna[7] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		}
	else if((pFace[7] == CUB_faceInferior && pLinha[7] == 2 && pColuna[7] == 2) || (pFace[7] == CUB_faceTraseira && pLinha[7] == 2 && pColuna[7] == 0) || (pFace[7] == CUB_faceDireita && pLinha[7] == 2 && pColuna[7] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');	
		strcat(Comandos, "Girar 2x Face InferiorH, ");
	}
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, 0, 2, 1);
	while(!(pFace[7] == CUB_faceSuperior && pLinha[7] == 2 && pColuna[7] == 0)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "Girar Face EsquerdaH, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "Girar Face InferiorH, ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "Girar Face EsquerdaA, ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "Girar Face InferiorA, ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, 0, 2, 1);
	}
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, 0, 2, 3);
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, 0, 3, 4);
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[6], &pLinha[6], &pColuna[6], pCubo, 0, 1, 4);
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, 0, 2, 1);
	return CUB_CondRetOk;
}