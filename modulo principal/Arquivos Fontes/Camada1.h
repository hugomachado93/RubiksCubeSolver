/******************************************************************************
*
*  $MCD M�dulo de defini��o: Primeira camada cubo m�gico
*
*  Arquivo gerado:              camada1.c
*  Letras identificadoras:      PCC

/******************************************************************************
*
*  $MCD M�dulo de defini��o: Primeira camada cubo m�gico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: bl    Bruno Le�o
		    ms    Mariana Salgueiro
		    pf    Pilar Fernandez
	     	gf    Gabriel Faria   
*
*  $HA Hist�rico de evolu��o:
*     Vers�o		Autor          Data			Observa��es
*		1       pf ms bl gf      28/abr/2018	in�cio 
*
*
*  $ED Descri��o do m�dulo
*		Implementa a primeira camada da resolu��o de um cubo m�gico
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

/***********************************************************************
*
*  $TC Tipo de dados: CUB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do cubo
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
*  $FC Fun��o: fazCamada1
*
*  $ED Descri��o da fun��o
*     Recebe um cubo com sua configura��o inicial e uma lista de comandos,
*	  preenchida durante a execu��o.
*     A fun��o � respons�vel por resolver a primeira camada do cubo, onde, 
*     ao final ter� a mesma cor.
*     
*  $EP Par�metros
*              pCubo -  Endere�o no qual a fun��o guardar� a
*                       localiza��o do CUBO na mem�ria. Essa
*                       localiza��o identifica um �nico cubo
*                       e deve ser usada para manipul�-lo.
*
*			   comandos - Lista de comandos preenchida durante
*						  a execu��o.
*
*  $FV Valor retornado
*     CUB_CondRetOK         - Criou um cubo com sucesso.
*     CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*                          mem�ria.
*
**************************************************************************/

//AE: Recebe um prot�tipo de cubo desordenado n�o vazio e uma lista de comandos 
//preenchida durante a execu��o
//AS: Retorna um prot�tipo de cubo com a primeira camada resolvida

 CUB_tpCondRet fazCamada1(CUB_tppCUBO pCubo, char Comandos[]);




