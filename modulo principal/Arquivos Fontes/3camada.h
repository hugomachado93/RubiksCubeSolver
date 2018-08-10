/******************************************************************************
*  $MCD M�dulo de defini��o: 3C		Terceira Camada
*
*  Arquivo gerado:              3camada.c
*  Letras identificadoras:      3C
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  Fl�vio B. Vilac
*  Autores:	 
*            AC - Ana Carolina Da Hora
*            FM - Felipe Alexandre Metson
*            MA - Michel An�sio Alemida
*            BHL - Bernardo Horner Lopes  
*			 TS - Tiago Sim�es	
*			 MMA - Mariela Mendonca de Andrade
*
*  $HA Hist�ico de evolu��o:
*     Vers�o  Autor    Data         Observa��es
*        0.1   MMA     23/05/18   implementacao da cruz e da acerta aresta
*        0.2   MMA     24/05/18   inicio implementacao posiciona peca de quina
*        0.3   MMA     25/05/18   finalizacao das funcoes
*		 0.4   FAM     29/05/18	  criacao .h e tornar fun��es statics
*
*
*  $ED Descri��o do m�dulo
*		Implementa 3 Camada do Cubo m�gico.
******************************************************************************/
/* Tipo refer�ncia para um Cubo */

typedef struct CUB_tagCUBO * CUB_tppCUBO;

/***********************************************************************
 *
 *  $TC Tipo de dados: TEC Condi���es de retorno
 *
 *
 *  $ED Descri��o do tipo
 *     Condi��es de retorno da fun��o da terceira camada
 *
 ***********************************************************************/

typedef enum {
    
    TEC_tpCondRetOK = 0 ,
    /* Executou corretamente */
    
    TEC_tpCondRetVazio = 1 ,
    /* Cubo vazio */
    
    TEC_tpCondRetAlgVazio = 2 ,
    /* Algor�timo vazio */
	
	TEC_tpCondRetCorInvalida = 3 ,
	/* Cor diferente da cor esperada */
	
	TEC_tpCondRetConfiguracaoInvalida = 4 ,
	/* Configura��o passada inv�lida */
    
    TEC_tpCondRetErro =  5 ,
    /* Qualquer condi���o de erro inesperada */
    
} TEC_tpCondRet ;

/**************************************************************************
*
*  $FC Fun��o: CUB  &Resolve Terceira Camada
*
*  $ED Descri��o da fun��o
*		Resolve terceira camada de um Cubo m�gico.
*		Recebe um cubo com a primeira e a segunda camada resolvida.
*		A fun��o � respons�vel por order de forma correta as pe�as
*		do CUBO e guardar os movimentos efetuados para tal.
*
*  $EP Par�metros
*					pCubo	-	Endere�o no qual a fun��o guardar� a
*								localiza��o do CUBO na mem�ria.
*  $FV Valor retornado
*		CUB_CondRetOK					- Cubo resolvido com sucesso.
*		CUB_CondRetCuboInvalido			- Cubo apontado para NULL.
*
**************************************************************************/
TEC_tpCondRet resolve3Camada(CUB_tppCUBO cubo, char **comandos);
