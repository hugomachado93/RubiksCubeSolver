/***************************************************************************
*  $MCI Módulo de implementação: TCUB Teste de Cubo
*
*  Arquivo gerado:              TESTCUB.c
*  Letras identificadoras:      TCUB
*
*  Nome da base de software:    ArcabouÁo para a automaÁ„o de testes de programas redigidos em C
*  Arquivo da base de software: D:\INF1301\TRAB1-1\FONTES
*
*  Projeto: INF 1301
*  Gestor:  Fl·vio B. Vilac
*  Autores: FM,MA
*
*  $HA HistÛrico de evoluÁ„o:
*     Vers„o  Autor    Data     ObservaÁıes
*     4       MMA      3/06/18    Casos de teste
*     3       FM,MA   17/abr/2018 tÈrmino de desenvolvimento
*     2       FM,MA   10/abr/2018 ajustes teste/script
*     1       FM,MA   03/abr/2018 inÌcio desenvolvimento
*
*  $ED DescriÁ„o do mÛdulo
*		Este mÛdulo contÈm as funÁıes especÌficas para o teste do
*     mÛdulo 3 camada.
*    
*  $EIU Interface com o usu·rio pessoa
*     Comandos de teste especÌficos para testar o mÛdulo:
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "TST_ESPC.h"
#include    "GENERICO.h"
#include    "LERPARM.h"
#include    "3camada.h"
#include    "CUBO.h"

#define CIMA 0
#define ESQUERDA 4
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define BAIXO 5

#define VERDE 1
#define VERMELHO 2
#define AMARELO 3
#define AZUL 4
#define BRANCO 5
#define LARANJA 6

/* Tabela dos nomes dos comandos de teste especÕficos */

#define     RESOLVE_3_CAMADA_VAZIO_CMD					 "=resolve" 


//cubos com branco para cima
#define     RESOLVE_3_CAMADA_BRANCO_CIMA_1_CMD			 "=resolveCaso1"  //num 0
#define     RESOLVE_3_CAMADA_BRANCO_CIMA_2_CMD			 "=resolveCaso2"  //num 1
#define     RESOLVE_3_CAMADA_BRANCO_CIMA_3_CMD			 "=resolveCaso3"  //numCub0 2
#define     RESOLVE_3_CAMADA_BRANCO_CIMA_4_CMD			 "=resolveCaso4"  //numcubo 3
#define     RESOLVE_3_CAMADA_BRANCO_CIMA_5_CMD			 "=resolveCaso8"  //numcubo 3
#define     RESOLVE_3_CAMADA_BRANCO_CIMA_6_CMD			 "=resolveCaso10"  //numcubo 3


//cubos com branco para baixo

#define     RESOLVE_3_CAMADA_BRANCO_BAIXO_1_CMD			 "=resolveCaso5"  //num 0
#define     RESOLVE_3_CAMADA_BRANCO_BAIXO_2_CMD			 "=resolveCaso6"  //num 1
#define     RESOLVE_3_CAMADA_BRANCO_BAIXO_3_CMD			 "=resolveCaso7"  //numCub0 2
#define     RESOLVE_3_CAMADA_BRANCO_BAIXO_4_CMD			 "=resolveCaso9"  //numCub0 2

int populaCubo(int *config, int numCubo) {
	if (numCubo == 0){  
		// Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = LARANJA;
		config[23] = LARANJA;

		config[33] = AMARELO;
		config[34] = LARANJA;
		config[35] = VERDE;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERMELHO;
		config[37] = VERMELHO;
		config[38] = AZUL;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = AMARELO;
		config[40] = AZUL;
		config[41] = VERDE;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AMARELO;
		config[43] = VERDE;
		config[44] = LARANJA;

		// Down Face 5
		config[45] = AMARELO;
		config[46] = AMARELO;
		config[47] = VERMELHO;

		config[48] = AMARELO;
		config[49] = AMARELO;
		config[50] = AMARELO;

		config[51] = AZUL;
		config[52] = AMARELO;
		config[53] = LARANJA;

	}

	else if (numCubo == 1){      
		
		// Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = LARANJA;
		config[23] = LARANJA;

		config[33] = VERMELHO;
		config[34] = AZUL;
		config[35] = AMARELO;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = LARANJA;
		config[37] = VERMELHO;
		config[38] = AZUL;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = LARANJA;
		config[40] = AMARELO;
		config[41] = AZUL;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AMARELO;
		config[43] = AMARELO;
		config[44] = VERDE;

		// Down Face 5
		config[45] = VERDE;
		config[46] = AMARELO;
		config[47] = AMARELO;

		config[48] = AMARELO;
		config[49] = AMARELO;
		config[50] = LARANJA;

		config[51] = AMARELO;
		config[52] = VERDE;
		config[53] = VERMELHO;
	}

	else if (numCubo == 2){
		
		// Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = LARANJA;
		config[23] = LARANJA;

		config[33] = AZUL;
		config[34] = LARANJA;
		config[35] = AMARELO;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERDE;
		config[37] = AMARELO;
		config[38] = VERDE;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = AMARELO;
		config[40] = AMARELO;
		config[41] = AZUL;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = LARANJA;
		config[43] = VERDE;
		config[44] = VERMELHO;

		// Down Face 5
		config[45] = VERMELHO;
		config[46] = VERMELHO;
		config[47] = LARANJA;

		config[48] = AMARELO;
		config[49] = AMARELO;
		config[50] = AZUL;

		config[51] = AMARELO;
		config[52] = AMARELO;
		config[53] = AMARELO;


	}

	else if (numCubo == 3){

			 // Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = LARANJA;
		config[23] = LARANJA;

		config[33] = VERDE;
		config[34] = AZUL;
		config[35] = AMARELO;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = AZUL;
		config[37] = AMARELO;
		config[38] = VERDE;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = VERMELHO;
		config[40] = LARANJA;
		config[41] = AZUL;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AMARELO;
		config[43] = AMARELO;
		config[44] = LARANJA;

		// Down Face 5
		config[45] = LARANJA;
		config[46] = VERMELHO;
		config[47] = AMARELO;

		config[48] = AMARELO;
		config[49] = AMARELO;
		config[50] = AMARELO;

		config[51] = AMARELO;
		config[52] = VERDE;
		config[53] = VERMELHO;
	}


	//cubos com branco para baixo

	else if (numCubo == 4){
		// Up Face 0
		config[0] = LARANJA;
		config[1] = AMARELO;
		config[2] = AZUL;

		config[3] = AMARELO;
		config[4] = AMARELO;
		config[5] = AMARELO;

		config[6] = VERMELHO;
		config[7] = AMARELO;
		config[8] = AMARELO;

		// Left Face 4
		config[9] = VERDE;
		config[10] = AZUL;
		config[11] = AMARELO;

		config[21] = VERMELHO;
		config[22] = VERMELHO;
		config[23] = VERMELHO;

		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = AZUL;
		config[13] = VERMELHO;
		config[14] = VERMELHO;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = VERDE;
		config[16] = LARANJA;
		config[17] = AMARELO;

		config[27] = LARANJA;
		config[28] = LARANJA;
		config[29] = LARANJA;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = LARANJA;
		config[19] = VERDE;
		config[20] = AMARELO;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;

	}

	else if (numCubo == 5){

		// Up Face 0
		config[0] = VERMELHO;
		config[1] = VERDE;
		config[2] = AMARELO;

		config[3] = LARANJA;
		config[4] = AMARELO;
		config[5] = AMARELO;

		config[6] = AMARELO;
		config[7] = AMARELO;
		config[8] = VERDE;

		// Left Face 4
		config[9] = AZUL;
		config[10] = AMARELO;
		config[11] = LARANJA;

		config[21] = VERMELHO;
		config[22] = VERMELHO;
		config[23] = VERMELHO;

		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = AZUL;
		config[13] = VERMELHO;
		config[14] = LARANJA;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = AMARELO;
		config[16] = AZUL;
		config[17] = VERMELHO;

		config[27] = LARANJA;
		config[28] = LARANJA;
		config[29] = LARANJA;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = VERDE;
		config[19] = AMARELO;
		config[20] = AMARELO;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;

	}

	else if (numCubo == 6){

			   // Up Face 0
		config[0] = VERDE;
		config[1] = LARANJA;
		config[2] = AZUL;

		config[3] = AMARELO;
		config[4] = AMARELO;
		config[5] = AMARELO;

		config[6] = AZUL;
		config[7] = VERMELHO;
		config[8] = VERDE;

		// Left Face 4
		config[9] = VERMELHO;
		config[10] = VERDE;
		config[11] = AMARELO;

		config[21] = VERMELHO;
		config[22] = VERMELHO;
		config[23] = VERMELHO;
    
		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = LARANJA;
		config[13] = AMARELO;
		config[14] = LARANJA;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = AMARELO;
		config[16] = AZUL;
		config[17] = VERMELHO;

		config[27] = LARANJA;
		config[28] = LARANJA;
		config[29] = LARANJA;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = AMARELO;
		config[19] = AMARELO;
		config[20] = AMARELO;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;

	}

	else if (numCubo == 7){

		
		 // Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = LARANJA;
		config[23] = LARANJA;

		config[33] = AZUL;
		config[34] = AZUL;
		config[35] = VERDE;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERMELHO;
		config[37] = AMARELO;
		config[38] = AZUL;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = AMARELO;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = VERDE;
		config[43] = AMARELO;
		config[44] = AMARELO;

		// Down Face 5
		config[45] = AMARELO;
		config[46] = VERDE;
		config[47] = VERMELHO;

		config[48] = AMARELO;
		config[49] = AMARELO;
		config[50] = AMARELO;

		config[51] = LARANJA;
		config[52] = VERMELHO;
		config[53] = AMARELO;






	}

	else if (numCubo == 8){
			 // Up Face 0
		config[0] = VERMELHO;
		config[1] = AMARELO;
		config[2] = VERMELHO;

		config[3] = VERMELHO;
		config[4] = AMARELO;
		config[5] = AZUL;

		config[6] = AMARELO;
		config[7] = AMARELO;
		config[8] = AMARELO;

		// Left Face 4
		config[9] = AMARELO;
		config[10] = AMARELO;
		config[11] = VERDE;

		config[21] = VERMELHO;
		config[22] = VERMELHO;
		config[23] = VERMELHO;

		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = LARANJA;
		config[13] = VERDE;
		config[14] = LARANJA;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = AZUL;
		config[16] = AMARELO;
		config[17] = AMARELO;

		config[27] = LARANJA;
		config[28] = LARANJA;
		config[29] = LARANJA;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = AZUL;
		config[19] = LARANJA;
		config[20] = VERDE;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;


	}

	else if (numCubo == 9){

		// Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = LARANJA;
		config[23] = LARANJA;

		config[33] = AMARELO;
		config[34] = AZUL;
		config[35] = AZUL;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = VERDE;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = LARANJA;
		config[37] = VERMELHO;
		config[38] = VERDE;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = AMARELO;
		config[40] = VERDE;
		config[41] = AZUL;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AZUL;
		config[31] = AZUL;
		config[32] = AZUL;

		config[42] = AMARELO;
		config[43] = LARANJA;
		config[44] = VERMELHO;

		// Down Face 5
		config[45] = AMARELO;
		config[46] = AMARELO;
		config[47] = LARANJA;

		config[48] = AMARELO;
		config[49] = AMARELO;
		config[50] = AMARELO;

		config[51] = VERDE;
		config[52] = AMARELO;
		config[53] = VERMELHO;



	}


	return 0;

}


/***********************************************************************
*
*  $FC FunÁ„o: T3C &Testar 3 Camada
*  $ED DescriÁ„o da funÁ„o
*     FunçÁ„o para testar a resoluçÁ„o da terceira camada de um cubo.
*
*  $EP Par‚metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	CUB_tppCUBO cubo;	
	TEC_tpCondRet CondRetEsperada , CondRetObtido;
    int numLidos;
	int config[54],numCubo;

	/* CASO cubo vazio */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_VAZIO_CMD	 ) == 0 )
	{
		CUB_tppCUBO cubo;
		cubo = NULL;

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");
	} /* fim ativa: Caso cubo vazio*/



	/*********************************** Casos cubo com branco para cima ************************************/

	/* CASO: acerta Aresta algoritmo baixo e quina certa d1, f7, l9 */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_CIMA_1_CMD ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 0);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");
	} /* fim ativa: CASO: acerta Aresta algoritmo baixo e quina certa d1, f7, l9  */

	/* CASO: acerta Aresta esquerda traseira baixo e quina certa d7, b9, l7 */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_CIMA_2_CMD ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 1);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada (cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /* fim ativa: CASO: acerta Aresta esquerda traseira baixo e quina certa d7, b9, l7 */

	/* CASO: acerta Aresta direita frente baixo e quina certa d7, b9, l7 */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_CIMA_3_CMD ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 2);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /* fim ativa: CASO: acerta Aresta direita frente baixo e quina certa d7, b9, l7  */

	/* CASO: acerta Aresta certo e quina certa d9, b7, r9 */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_CIMA_4_CMD ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 3);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /* fim ativa: CASO: acerta Aresta certo e quina certa d9, b7, r9 */

	/* CASO: acerta Aresta esquerda traseira baixo e quina certa d7, b9, l7 */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_CIMA_5_CMD ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 7);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada (cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /* fim ativa: CASO: acerta Aresta esquerda traseira baixo e quina certa d7, b9, l7 */


	/* CASO: acerta Aresta algoritmo baixo + traseira direita baixo */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_CIMA_6_CMD ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 9);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /* fim ativa: acerta Aresta algoritmo baixo + traseira direita baixo */



	
	/*********************************** Casos cubo com branco para baixo ************************************/


	/* fim ativa: CASO: acerta Aresta algoritmo DIREITA FRENTE e quina certa U3, F3, B1 */
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_BAIXO_1_CMD	 ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 4);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");
	} /* fim ativa: CASO: acerta Aresta algoritmo DIREITA FRENTE e quina certa U3, F3, B1 */


	/* CASO: acerta Aresta algoritmo TRASEIRA DIREITA e quina POSICIONADA*/
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_BAIXO_2_CMD	 ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 5);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /* fim ativa: CASO: acerta Aresta certo e quina certa d9, b7, r9 */

		/* CASO: acerta Aresta algoritmo ESQUERDA TRASEIRA e quina U7, L3, F1*/
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_BAIXO_3_CMD	 ) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 6);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /*  fim ativa: CASO: acerta Aresta algoritmo ESQUERDA TASEIRA e quina U7, L3, F1*/

	/* CASO: acerta Aresta algoritmo DIREITA FRENTE + FRENTE ESQUERDA e quina D3, R7, F9*/
	if ( strcmp( ComandoTeste , RESOLVE_3_CAMADA_BRANCO_BAIXO_4_CMD) == 0 )
	{
		CUB_tppCUBO cubo;
		CUB_tpConfiguracao cuboaux;
		populaCubo(cuboaux.cores, 8);
		CUB_CriarCUBO(&cubo, cuboaux);

        numLidos = LER_LerParametros("i",&CondRetEsperada);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		//CondRetObtido = resolve3Camada(cubo);
		CondRetObtido = resolve3camada(cubo);
		CUB_DestruirCUBO(cubo);

		return TST_CompararInt(CondRetObtido, CondRetEsperada, "Retorno errado testa camada");

	} /*  fim ativa: CASO: acerta Aresta algoritmo DIREITA FRENTE + FRENTE ESQUERDA e quina D3, R7, F9*/

	







	return TST_CondRetNaoConhec ;

} /* Fim função: TCUB &Testar 3 camada */
