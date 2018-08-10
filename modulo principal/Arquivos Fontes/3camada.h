/******************************************************************************
*  $MCD MÛdulo de definiÁ„o: 3C		Terceira Camada
*
*  Arquivo gerado:              3camada.c
*  Letras identificadoras:      3C
*
*  Projeto: INF 1301 Cubo m·gico
*  Gestor:  Fl·vio B. Vilac
*  Autores:	 
*            AC - Ana Carolina Da Hora
*            FM - Felipe Alexandre Metson
*            MA - Michel AnÌsio Alemida
*            BHL - Bernardo Horner Lopes  
*			 TS - Tiago Simıes	
*			 MMA - Mariela Mendonca de Andrade
*
*  $HA HistÛico de evoluÁ„o:
*     Vers„o  Autor    Data         ObservaÁıes
*        0.1   MMA     23/05/18   implementacao da cruz e da acerta aresta
*        0.2   MMA     24/05/18   inicio implementacao posiciona peca de quina
*        0.3   MMA     25/05/18   finalizacao das funcoes
*		 0.4   FAM     29/05/18	  criacao .h e tornar funÁıes statics
*
*
*  $ED DescriÁ„o do mÛdulo
*		Implementa 3 Camada do Cubo m·gico.
******************************************************************************/
/* Tipo referÍncia para um Cubo */

typedef struct CUB_tagCUBO * CUB_tppCUBO;

/***********************************************************************
 *
 *  $TC Tipo de dados: TEC CondiçÁıes de retorno
 *
 *
 *  $ED Descrição do tipo
 *     Condições de retorno da função da terceira camada
 *
 ***********************************************************************/

typedef enum {
    
    TEC_tpCondRetOK = 0 ,
    /* Executou corretamente */
    
    TEC_tpCondRetVazio = 1 ,
    /* Cubo vazio */
    
    TEC_tpCondRetAlgVazio = 2 ,
    /* AlgorÌtimo vazio */
	
	TEC_tpCondRetCorInvalida = 3 ,
	/* Cor diferente da cor esperada */
	
	TEC_tpCondRetConfiguracaoInvalida = 4 ,
	/* ConfiguraÁ„o passada inv·lida */
    
    TEC_tpCondRetErro =  5 ,
    /* Qualquer condiçÁ„o de erro inesperada */
    
} TEC_tpCondRet ;

/**************************************************************************
*
*  $FC FunÁ„o: CUB  &Resolve Terceira Camada
*
*  $ED DescriÁ„o da funÁ„o
*		Resolve terceira camada de um Cubo m·gico.
*		Recebe um cubo com a primeira e a segunda camada resolvida.
*		A funÁ„o È respons·vel por order de forma correta as peÁas
*		do CUBO e guardar os movimentos efetuados para tal.
*
*  $EP Par‚metros
*					pCubo	-	EndereÁo no qual a funÁ„o guardar· a
*								localizaÁ„o do CUBO na memÛria.
*  $FV Valor retornado
*		CUB_CondRetOK					- Cubo resolvido com sucesso.
*		CUB_CondRetCuboInvalido			- Cubo apontado para NULL.
*
**************************************************************************/
TEC_tpCondRet resolve3Camada(CUB_tppCUBO cubo, char **comandos);
