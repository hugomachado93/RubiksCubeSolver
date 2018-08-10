#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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

	int corSuperior;
	int corEsquerda;
	int corFrente;
	int corDireita;
	int corTraseira;
	int corInferior;

	CUB_ChecarCorDaFace(&corSuperior, pCubo, 1, 1, CUB_faceSuperior);
	CUB_ChecarCorDaFace(&corEsquerda, pCubo, 1, 1, CUB_faceEsquerda);
	CUB_ChecarCorDaFace(&corFrente, pCubo, 1, 1, CUB_faceFrontal);
	CUB_ChecarCorDaFace(&corDireita, pCubo, 1, 1, CUB_faceDireita);
	CUB_ChecarCorDaFace(&corTraseira, pCubo, 1, 1, CUB_faceTraseira);
	CUB_ChecarCorDaFace(&corInferior, pCubo, 1, 1, CUB_faceInferior);

	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[0], &pLinha[0], &pColuna[0], pCubo, corSuperior, corFrente);
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[1], &pLinha[1], &pColuna[1], pCubo, corSuperior, corDireita); 
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[2], &pLinha[2], &pColuna[2], pCubo, corSuperior, corTraseira); 
	CUB_EncontrarPosicaoDePecaDeAresta(&pFace[3], &pLinha[3], &pColuna[3], pCubo, corSuperior, corEsquerda); 

	//resolvendo cruz na face de cima
	while(!(j==4||(pFace[0] == 0 && pLinha[0] == 2 && pColuna[0] == 1) && (pFace[1] == 0 && pLinha[1] == 1 && pColuna[1] == 2) && (pFace[2] == 0 && pLinha[2] == 0 && pColuna[2] == 1) && (pFace[3] == 0 && pLinha[3] == 1 && pColuna[3] == 0)))
	{
		if(j == 0){ //peça corSuperior e corFrente 
			if (pFace[j] == CUB_faceSuperior && pLinha[j] == 0 && pColuna[j] == 1){ //U2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 0 && pColuna[j] == 1){ //B2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 0){ //U4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 2){ //U6
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'a');
				strcat(Comandos, "R' R', ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 0 && pColuna[j] == 1){ //R2
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'a');
				strcat(Comandos, "R' R', ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 0 && pColuna[j] == 1){ //F2
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');	
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1) //D2
			{
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');				
				strcat(Comandos, "R ");				
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			} 
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //L4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');	
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');	
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 0){ //D4
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');	
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D d ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');	
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 2, 'h');
				strcat(Comandos, "F F ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
			}
		}

		if(j == 1){ // peça corSuperior e corDireita
			CUB_EncontrarPosicaoDePecaDeAresta(&pFace[1], &pLinha[1], &pColuna[1], pCubo, corSuperior, corDireita);
			if (pFace[j] == CUB_faceSuperior && pLinha[j] == 0 && pColuna[j] == 1){ //U2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 0 && pColuna[j] == 1){ //B2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 0){ //U4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 0 && pColuna[j] == 1){ //R2
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
				strcat(Comandos, "D' D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1){ //D2
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');	
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 0){ //D4
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
				strcat(Comandos, "D' D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceDireita, 2, 'h');
				strcat(Comandos, "R R ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
			}
		}

		if(j == 2){ // peça corSuperior e corTraseira
			CUB_EncontrarPosicaoDePecaDeAresta(&pFace[2], &pLinha[2], &pColuna[2], pCubo, corSuperior, corTraseira); //branco e azul
			if(pFace[j] == CUB_faceTraseira && pLinha[j] == 0 && pColuna[j] == 1){ //B2
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			if (pFace[j] == CUB_faceSuperior && pLinha[j] == 1 && pColuna[j] == 0){ //U4	
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'a');
				strcat(Comandos, "L' L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1){ //D2
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}

			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h'); 
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');	
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B5 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //L4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D4
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 2, 'h');
				strcat(Comandos, "B B ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'h');
				strcat(Comandos, "B ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceTraseira, 1, 'a');
				strcat(Comandos, "B' ");
			}
		}

		if(j == 3){ // peça corSuperior e corEsquerda
			CUB_EncontrarPosicaoDePecaDeAresta(&pFace[3], &pLinha[3], &pColuna[3], pCubo, corSuperior, corEsquerda); //branco e laranja
			if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 0 && pColuna[j] == 1){ //L2
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 2){ //L6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 0){ //F4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 0){ //R4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 1 && pColuna[j] == 2){ //F6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 0 && pColuna[j] == 1){ //D2
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceFrontal && pLinha[j] == 2 && pColuna[j] == 1){ //F8
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');	
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 0){ //B4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');	
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 1 && pColuna[j] == 2){ //R6 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
				strcat(Comandos, "R ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
				strcat(Comandos, "R' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 1 && pColuna[j] == 2){ //B6
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 1 && pColuna[j] == 0){ //L4 **caso especial("res=false")**
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
				strcat(Comandos, "L' ");
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 2 && pColuna[j] == 1){ //D8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');	
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceTraseira && pLinha[j] == 2 && pColuna[j] == 1){ //B8
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');	
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 0){ //D4
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceEsquerda && pLinha[j] == 2 && pColuna[j] == 1){ //L8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
				strcat(Comandos, "D ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceInferior && pLinha[j] == 1 && pColuna[j] == 2){ //D6
				CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
				strcat(Comandos, "D D ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
			else if(pFace[j] == CUB_faceDireita && pLinha[j] == 2 && pColuna[j] == 1){ //R8
				CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
				strcat(Comandos, "D' ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'h');
				strcat(Comandos, "F ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
				strcat(Comandos, "L ");
				CUB_GirarFace(pCubo, CUB_faceFrontal, 1, 'a');
				strcat(Comandos, "F' ");
				CUB_GirarFace(pCubo, CUB_faceEsquerda, 2, 'h');
				strcat(Comandos, "L L ");
			}
		}
		j++;
	}
	//resolvida a cruz

	//resolvendo cantos (peças de quina)
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, corSuperior, corFrente, corDireita); //peça corSuperior, corFrente e corDireita
	if((pFace[4] == CUB_faceTraseira && pLinha[4]  == 2 && pColuna[4] ==  2) || (pFace[4] == CUB_faceInferior && pLinha[4]  == 2  && pColuna[4] == 0) || (pFace[4] == CUB_faceEsquerda && pLinha[4]  == 2 && pColuna[4] == 0) )
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "D D ");
	}
	else if((pFace[4] == CUB_faceFrontal && pLinha[4] == 2 && pColuna[4] == 0) || (pFace[4] == CUB_faceInferior && pLinha[4] == 0 && pColuna[4] == 0) || (pFace[4] == CUB_faceEsquerda && pLinha[4] == 2 && pColuna[4] == 2) )
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
	}
	else if((pFace[4] == CUB_faceTraseira && pLinha[4] == 2 && pColuna[4] == 0) || (pFace[4] == CUB_faceInferior && pLinha[4] == 2 && pColuna[4] == 2) || (pFace[4] == CUB_faceDireita && pLinha[4] == 2 && pColuna[4] == 2) )
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
	}
	else if((pFace[4] == CUB_faceTraseira && pLinha[4] == 0 && pColuna[4] == 2) || (pFace[4] == CUB_faceSuperior && pLinha[4] == 0 && pColuna[4] == 0) || (pFace[4] == CUB_faceEsquerda && pLinha[4] == 0 && pColuna[4] == 0) )
	{
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "L' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'a');
		strcat(Comandos, "D' D' ");
	}
	else if((pFace[4] == CUB_faceTraseira && pLinha[4] == 0 && pColuna[4] == 0) || (pFace[4] == CUB_faceSuperior && pLinha[4] == 0 && pColuna[4] == 2) || (pFace[4] == CUB_faceDireita && pLinha[4] == 0 && pColuna[4] == 2)) {
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
		strcat(Comandos, "R ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
		strcat(Comandos, "R' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
	}
	else if((pFace[4] == CUB_faceFrontal && pLinha[4] == 0 && pColuna[4] == 0 ) || (pFace[4] == CUB_faceSuperior && pLinha[4] == 2 && pColuna[4] == 0 ) ||(pFace[4] == CUB_faceEsquerda && pLinha[4] == 0 && pColuna[4] == 2 ))
	{
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "L' ");
	}

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, corSuperior, corFrente, corDireita);
	while(!(pFace[4] == CUB_faceSuperior && pLinha[4] == 2 && pColuna[4] == 2)){
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
		strcat(Comandos, "R' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
		strcat(Comandos, "R ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, corSuperior, corFrente, corDireita);
	}
	
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, corSuperior, corDireita, corTraseira); //pela corSuperior, corDireita e corTraseira

	if((pFace[5] == CUB_faceEsquerda && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceInferior && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceTraseira && pLinha[5] == 2 && pColuna[5] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
	}
	else if((pFace[5] == CUB_faceInferior && pLinha[5] == 0 && pColuna[5] == 0) || (pFace[5] == CUB_faceFrontal && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceEsquerda && pLinha[5] == 2 && pColuna[5] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "D D ");
	}
	else if((pFace[5] == CUB_faceInferior && pLinha[5] == 0 && pColuna[5] == 2) || (pFace[5] == CUB_faceFrontal && pLinha[5] == 2 && pColuna[5] == 2) || (pFace[5] == CUB_faceDireita && pLinha[5] == 2 && pColuna[5] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D D ");
	}
	else if((pFace[5] == CUB_faceSuperior && pLinha[5] == 0 && pColuna[5] == 0) || (pFace[5] == CUB_faceTraseira && pLinha[5] == 0 && pColuna[5] == 2) || (pFace[5] == CUB_faceEsquerda && pLinha[5] == 0 && pColuna[5] == 0)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "L' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L ");
	}
	else if((pFace[5] == CUB_faceSuperior && pLinha[5] == 2 && pColuna[5] == 0) || (pFace[5] == CUB_faceFrontal && pLinha[5] == 0 && pColuna[5] == 0) || (pFace[5] == CUB_faceEsquerda && pLinha[5] == 0 && pColuna[5] == 2)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "D D ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');	
		strcat(Comandos, "L' ");
	}

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, corSuperior, corDireita, corTraseira);

	while(!(pFace[5] == CUB_faceSuperior && pLinha[5] == 0 && pColuna[5] == 2)){
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'h');
		strcat(Comandos, "R ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
		CUB_GirarFace(pCubo, CUB_faceDireita, 1, 'a');
		strcat(Comandos, "R' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, corSuperior, corDireita, corTraseira);
	}

	CUB_EncontrarPosicaoDePecaDeQuina (&pFace[6], &pLinha[6], &pColuna[6], pCubo, corSuperior, corEsquerda, corTraseira); //peça corSuperior, corTraseira e corEsquerda

	if((pFace[6] == CUB_faceFrontal && pLinha[6] == 2 && pColuna[6] == 0) || (pFace[6] == CUB_faceInferior && pLinha[6] == 0 && pColuna[6] == 0) || (pFace[6] == CUB_faceEsquerda && pLinha[6] == 2 && pColuna[6] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior,1,'a');
		strcat(Comandos, "D' ");
	}
	else if((pFace[6] == CUB_faceFrontal && pLinha[6] == 2 && pColuna[6] == 2) || (pFace[6] == CUB_faceInferior && pLinha[6] == 0 && pColuna[6] == 2) || (pFace[6] == CUB_faceDireita && pLinha[6] == 2 && pColuna[6] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior,2,'a');
		strcat(Comandos, "D' D' ");
	}
	else if ((pFace[6] == CUB_faceTraseira && pLinha[6] == 2 && pColuna[6] == 0) || (pFace[6] == CUB_faceInferior && pLinha[6] == 2 && pColuna[6] == 2) || (pFace[6] == CUB_faceDireita && pLinha[6] == 2 && pColuna[6] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
	}
	else if ((pFace[6] == CUB_faceFrontal && pLinha[6] == 0 && pColuna[6] == 0) || (pFace[6] == CUB_faceSuperior && pLinha[6] == 2 && pColuna[6] == 0) || (pFace[6] == CUB_faceEsquerda && pLinha[6] == 0 && pColuna[6] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');
		strcat(Comandos, "D' D' ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "L' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
	}


	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[6], &pLinha[6], &pColuna[6], pCubo, corSuperior, corEsquerda, corTraseira);
	while(!(pFace[6] == CUB_faceSuperior && pLinha[6] == 0 && pColuna[6] == 0)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "L' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[6], &pLinha[6], &pColuna[6], pCubo, corSuperior, corEsquerda, corTraseira);
	}	

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, corSuperior, corFrente, corEsquerda); //peça corSuperior, corEsquerda e corFrente

	if((pFace[7] == CUB_faceInferior && pLinha[7] == 2 && pColuna[7] == 0) || (pFace[7] == CUB_faceTraseira && pLinha[7] == 2 && pColuna[7] == 2) || (pFace[7] == CUB_faceEsquerda && pLinha[7] == 2 && pColuna[7] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
	}
	else if((pFace[7] == CUB_faceInferior && pLinha[7] == 0 && pColuna[7] == 2) || (pFace[7] == CUB_faceFrontal && pLinha[7] == 2 && pColuna[7] == 2) || (pFace[7] == CUB_faceDireita && pLinha[7] == 2 && pColuna[7] == 0))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		}
	else if((pFace[7] == CUB_faceInferior && pLinha[7] == 2 && pColuna[7] == 2) || (pFace[7] == CUB_faceTraseira && pLinha[7] == 2 && pColuna[7] == 0) || (pFace[7] == CUB_faceDireita && pLinha[7] == 2 && pColuna[7] == 2))
	{
		CUB_GirarFace(pCubo, CUB_faceInferior, 2, 'h');	
		strcat(Comandos, "D D ");
	}

	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, corSuperior, corFrente, corEsquerda);
	while(!(pFace[7] == CUB_faceSuperior && pLinha[7] == 2 && pColuna[7] == 0)){
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'h');
		strcat(Comandos, "L ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'h');
		strcat(Comandos, "D ");
		CUB_GirarFace(pCubo, CUB_faceEsquerda, 1, 'a');
		strcat(Comandos, "L' ");
		CUB_GirarFace(pCubo, CUB_faceInferior, 1, 'a');
		strcat(Comandos, "D' ");
		CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, corSuperior, corFrente, corEsquerda);
	}
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[4], &pLinha[4], &pColuna[4], pCubo, corSuperior, corFrente, corDireita);
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[5], &pLinha[5], &pColuna[5], pCubo, corSuperior, corDireita, corTraseira);
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[6], &pLinha[6], &pColuna[6], pCubo, corSuperior, corEsquerda, corTraseira);
	CUB_EncontrarPosicaoDePecaDeQuina(&pFace[7], &pLinha[7], &pColuna[7], pCubo, corSuperior, corFrente, corEsquerda);
	
	return CUB_CondRetOK;
}