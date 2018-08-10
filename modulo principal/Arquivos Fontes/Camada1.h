/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:              camada1.c
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
*     Versão		Autor          Data			Observações
*		1       pf ms bl gf      28/abr/2018	início 
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
#include "CUBO.h"
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: CUB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do cubo
*
***********************************************************************/

 typedef enum {
 
         CUB_CondRetOk = 0 ,
               /* Executou corretamente */
 
         CUB_CondRetFaltaMemoria = 1 ,
               /* Faltou memoria ao alocar dados */
  
  } CUB_tpCondRet ;


/**************************************************************************
*
*  $FC Função: fazCamada1
*
*  $ED Descrição da função
*     Recebe um cubo com sua configuração inicial e uma lista de comandos,
*	  preenchida durante a execução.
*     A função é responsável por resolver a primeira camada do cubo, onde, 
*     ao final terá a mesma cor.
*     
*  $EP Parâmetros
*              pCubo -  Endereço no qual a função guardará a
*                       localização do CUBO na memória. Essa
*                       localização identifica um único cubo
*                       e deve ser usada para manipulá-lo.
*
*			   comandos - Lista de comandos preenchida durante
*						  a execução.
*
*  $FV Valor retornado
*     CUB_CondRetOK         - Criou um cubo com sucesso.
*     CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*                          memória.
*
**************************************************************************/

//AE: Recebe um protótipo de cubo desordenado não vazio e uma lista de comandos 
//preenchida durante a execução
//AS: Retorna um protótipo de cubo com a primeira camada resolvida

 CUB_tpCondRet fazCamada1(CUB_tppCUBO pCubo, char Comandos[]);




