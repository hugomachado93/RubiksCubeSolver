/******************************************************************************
*  $MCD M�dulo de defini��o: 3c		Terceira Camada
*
*  Arquivo gerado:              3camada.c
*  Letras identificadoras:      3c
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
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
*		 0.4   MMA     31/05/18   caso cubo resolvido para cima	
*
*
*  $ED Descri��o do m�dulo
*		Implementa 3 Camada do Cubo m�gico.
******************************************************************************/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "CUBO.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "3camada.h"

#define ALG 55
#define MAX 2000

#define CIMA 0
#define ESQUERDA 4
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define BAIXO 5

#define VERDE 1
#define VERMELHO 2
static int AMARELO;
#define AZUL 4
#define BRANCO 5
#define LARANJA 6

/* STRING GLOBAL QUE GUARDA OS COMANDOS */

char execute[MAX]= "";

/**************************
*  $FC Fun��o: 3C  executaAlgoritmo
*
*  $ED Descri��o da fun��o
*    Executa algoritmo recebido pela string
*		
*  $EPar�metros
*		$P cubo = estrutura CUB_tppCUBO populada
*       $P algoritmo = string de no m�ximo ALG elementos com comandos no estilo: "U R U' R' U' F' U U F F"
*  $FV Valor retornado
*       0 - sucesso
*       1 - entrada inv�lida
**************************/
int executaAlgoritmo(CUB_tppCUBO cubo, char* algoritmo) {

	int i = 0;
	int jump = 2;
	
	char comandos[ALG];

	strcat(execute, algoritmo);
	
	memset(comandos, '\0', sizeof(comandos));
	strcpy(comandos, algoritmo);

	while (comandos[i]) {

		char rot;
		int face;

		if (comandos[i + 1] == '\'') {
			rot = 'a';
			jump = 3;
		}
		else {
			rot = 'h';
			jump = 2;
		}

		switch (comandos[i]) {
		case 'U':
			face = 0;
			break;
		case 'L':
			face = 4;
			break;
		case 'F':
			face = 1;
			break;
		case 'R':
			face = 2;
			break;
		case 'B':
			face = 3;
			break;
		case 'D':
			face = 5;
			break;
		default:
			face = -1;
			break;
		}

		if (face < 0)
			return -1;

		if (CUB_GirarFace(cubo, face, 1, rot) != 0) { exit(10); }

		i += jump;
	}

	return 0;
}
/**************************
*  $FC Fun��o: 3C  resolvidoAcima
*
*  $ED Descri��o da fun��o
*	Verifica se cubo est� com a face branca para cima	
*  $EPar�metros
*		$P cubo			
*  $FV Valor retornado
*		1- cubo com branco para cima
*       0- cubo com branco para baixo
**************************/
int resolvidoAcima(CUB_tppCUBO cubo) {
	int corCima, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;

	if (CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA) != 0) { exit(11); }

	if (CUB_ChecarCorDaFace(&aux1, cubo, 0, 0, CIMA) != 0) { exit(11); }
	if (CUB_ChecarCorDaFace(&aux2, cubo, 0, 1, CIMA) != 0) { exit(12); }
	if (CUB_ChecarCorDaFace(&aux3, cubo, 0, 2, CIMA) != 0) { exit(13); }

	if (CUB_ChecarCorDaFace(&aux4, cubo, 1, 0, CIMA) != 0) { exit(14); }
	if (CUB_ChecarCorDaFace(&aux5, cubo, 1, 2, CIMA) != 0) { exit(15); }

	if (CUB_ChecarCorDaFace(&aux6, cubo, 2, 0, CIMA) != 0) { exit(16); }
	if (CUB_ChecarCorDaFace(&aux7, cubo, 2, 1, CIMA) != 0) { exit(17); }
	if (CUB_ChecarCorDaFace(&aux8, cubo, 2, 2, CIMA) != 0) { exit(18); }

	if (corCima == aux1 && aux1 == aux2 && aux2 == aux3 && aux3 == aux4 && aux4 == aux5 && aux5 == aux6 && aux6 == aux7 && aux7 == aux8) {
		return 1;
	}
	else {
		return 0;
	}
}
/**************************
*  $FC Fun��o: 3C  eAmarelo
*
*  $ED Descri��o da fun��o
*	Verifica se peca e amarela
*   $EPar�metros
*		$P cubo	
*		$P linha	
*		$P coluna	
*		$P face	
*  $FV Valor retornado
*		1- peca nao e amarela
*       0- peca e amarela
**************************/
int eAmarelo(CUB_tppCUBO cubo, int linha, int coluna, int face){
    int aux;
    CUB_ChecarCorDaFace(&aux, cubo, linha, coluna, face);

    if (aux == AMARELO){
        return 0;
    }
    return 1;
}
/**************************
*  $FC Fun��o: 3C  saoTodosAmarelos
*
*  $ED Descri��o da fun��o
*	Verifica se todas as pecas sao amarelas	
*  $EPar�metros
*		$P peca1
*		$P peca2	
*		$P peca3	
*		$P peca4
*  $FV Valor retornado
*		1- todas as pecas nao sao amarelas
*       0- todas as pecas sao amarelas
**************************/
int saoTodosAmarelos(int peca1, int peca2, int peca3, int peca4){
    if (peca4 != -1){  
        if (peca1 == AMARELO && peca2== AMARELO && peca3 == AMARELO && peca4 == AMARELO){
            return 0;          
        }
        else{
            return 1;
        }

    }

    else {
        if (peca1 == 0 && peca2==0 && peca3 == 0){ 
            return 0;
        }
        else{
             return 1;
        }
    }
} 
/**************************
*  $FC Fun��o: 3C  conjuntosEquivalentes
*
*  $ED Descri��o da fun��o
*	Verifica se as pecas de um conjunto sao equivalentes	
*  $EPar�metros
*		$P n1
*		$P n2	
*		$P n3	
*		$P m1
*		$P m2	
*		$P m3	
*  $FV Valor retornado
*		1- conjunto nao e equivalente
*       0- conjunto e equivalente
**************************/
int conjuntosSaoEquivalentes (int n1, int n2, int n3, int m1, int m2, int m3){ 

    if (n1 == m1 && n2 == m2 && n3 == m3){
        return 0;
    }

    else if (n1 == m1 && n2 == m3 && m3 == m2){
        return 0;

    }

    else if (n1 == m2 && n2 == m1 && n3 == m3){
        return 0;
    }

    else if (n1 == m2 && n2 == m3 && n3 == m1){
        return 0;
    }
    
    else if (n1 == m3 && n2 == m2 && n3 == m1){
        return 0;
    }

    else if (n1 == m3 && n2 == m1 && n3 == m2){
        return 0;
    }

    


    return 1;  
}
/**************************
*  $FC Fun��o: 3C  resolveCruz
*
*  $ED Descri��o da fun��o
*	Algoritmo para a efetuar a sequencia de movimentos necessária formar uma cruz na face
*  $EPar�metros
*		$P cubo			
*  $FV Valor retornado
*       0- cruz feita
**************************/
int resolveCruz(CUB_tppCUBO cubo){ 

    char* algoritmo;
    char* algoL;
    char* giraTopo;
    int u2, u4,u5, u6, u8;
	char* algoritmoBaixo;
    char* giraBaixo;
    int d2, d4,d5, d6, d8;
	int resolvidoPraCima = resolvidoAcima(cubo);

	

	if (resolvidoPraCima == 0){

		algoritmo = "F R U R' U' F'";
		algoL = "F U R U' R' F'";
		giraTopo = "U";

		u2 = eAmarelo(cubo, 0, 1, CIMA);
		u4 = eAmarelo(cubo, 1, 0, CIMA);
		u5 = eAmarelo(cubo, 1, 1, CIMA);
		u6 = eAmarelo(cubo, 1, 2, CIMA);
		u8 = eAmarelo(cubo, 2, 1, CIMA);

  
		if (u2 == 0 && u4 == 0 && u6 == 0 && u8 == 0) {  // caso cruz ja feita
			return 0;
		}    
		if (saoTodosAmarelos(u2, u5, u4, -1) == 0 || saoTodosAmarelos(u2, u5, u6, -1) == 0 || saoTodosAmarelos(u6, u5, u8, -1) == 0 ||saoTodosAmarelos(u4, u5, u8, -1) == 0 ) {  //caso L  
			while (saoTodosAmarelos(u2, u5, u4, -1) != 0 ){  //caso L nao esteja na posicao desejada
				executaAlgoritmo(cubo, giraTopo);
				u2 = eAmarelo(cubo, 0, 1, CIMA);  
				u4 = eAmarelo(cubo, 1, 0, CIMA);
				u5 = eAmarelo(cubo, 1, 1, CIMA);
			}
        	executaAlgoritmo(cubo, algoL);

		} 
		else if (saoTodosAmarelos(u4, u5, u6, -1) == 0 || saoTodosAmarelos(u2, u5, u8, -1) == 0) { //caso linha
			
			while (saoTodosAmarelos(u4, u5, u6, -1) != 0 ){  //caso L nao esteja na posicao desejada
            
				executaAlgoritmo(cubo, giraTopo);
				u4 = eAmarelo(cubo, 1, 0, CIMA);
				u5 = eAmarelo(cubo, 1, 1, CIMA);
				u6 = eAmarelo(cubo, 1, 2, CIMA);
			}
			executaAlgoritmo(cubo, algoritmo);
		}

		else  { //caso ponto
			
			executaAlgoritmo(cubo, algoritmo);
			while (saoTodosAmarelos(u2, u5, u4, -1) != 0 ){  
				executaAlgoritmo(cubo, giraTopo);
				u2 = eAmarelo(cubo, 0, 1, CIMA);  //atualiza u2,u4,u5 apos girada
				u4 = eAmarelo(cubo, 1, 0, CIMA);
				u5 = eAmarelo(cubo, 1, 1, CIMA);
			}
			executaAlgoritmo(cubo, algoritmo);
		}
	}

	else if (resolvidoPraCima == 1){
		algoritmoBaixo = "B R D R' D' B'";  // "F R U R' U' F'" //ok
		giraBaixo = "D'";

		d2 = eAmarelo(cubo, 0, 1, BAIXO);
		d4 = eAmarelo(cubo, 1, 0, BAIXO);
		d5 = eAmarelo(cubo, 1, 1, BAIXO);
		d6 = eAmarelo(cubo, 1, 2, BAIXO);
		d8 = eAmarelo(cubo, 2, 1, BAIXO);


		if (d2 == 0 && d4 == 0 && d6 == 0 && d8 == 0) {  // caso cruz ja feita
			
			return 0;
		}   


		if (saoTodosAmarelos(d2, d5, d4, -1) == 0 || saoTodosAmarelos(d2, d5, d6, -1) == 0 || saoTodosAmarelos(d6, d5, d8, -1) == 0 ||saoTodosAmarelos(d4, d5, d8, -1) == 0 ) {  //caso L  
			
			while (saoTodosAmarelos(d2, d5, d4, -1) != 0 ){  //caso L nao esteja na posicao desejada
				executaAlgoritmo(cubo, giraBaixo);
				d2 = eAmarelo(cubo, 0, 1, BAIXO);  
				d4 = eAmarelo(cubo, 1, 0, BAIXO);
				d5 = eAmarelo(cubo, 1, 1, BAIXO);
			}
			executaAlgoritmo(cubo, algoritmoBaixo);
			executaAlgoritmo(cubo, algoritmoBaixo);
		} 

		else if (saoTodosAmarelos(d4, d5, d6, -1) == 0 || saoTodosAmarelos(d2, d5, d8, -1) == 0) { //caso linha
			
			while (saoTodosAmarelos(d4, d5, d6, -1) != 0 ){  //caso linha nao esteja na posicao desejada
				executaAlgoritmo(cubo, giraBaixo);
				d4 = eAmarelo(cubo, 1, 0, BAIXO);
				d5 = eAmarelo(cubo, 1, 1, BAIXO);
				d6 = eAmarelo(cubo, 1, 2, BAIXO);
			}
			executaAlgoritmo(cubo, algoritmoBaixo);
		}
		else  { //caso ponto
			
			executaAlgoritmo(cubo, algoritmoBaixo);
			while (saoTodosAmarelos(d2, d5, d4, -1) != 0 ){  
				executaAlgoritmo(cubo, giraBaixo);
				d2 = eAmarelo(cubo, 0, 1, BAIXO);  
				d4 = eAmarelo(cubo, 1, 0, BAIXO);
				d5 = eAmarelo(cubo, 1, 1, BAIXO);
			}
			executaAlgoritmo(cubo, algoritmoBaixo);
		}
	}
    return 0;
}
/**************************
*  $FC Fun��o: 3C  acertaAresta
*
*  $ED Descri��o da fun��o
*	Algoritmo para a efetuar a sequencia de movimentos necessária acertar as arestas da face
*  $EPar�metros
*		$P cubo			
*  $FV Valor retornado
*       0-aresta acertada
**************************/
int acertaAresta(CUB_tppCUBO cubo){ //etapa 02

    int f2,f5, r2, r5, b2, b5, l2, l5;
    char* algoritmo; 
    char* algTraseiraDireita;
    char* algEsquerdaTraseira;
    char* algDireitaFrente;
    char* giraTopo;
	int resolvidoPraCima = resolvidoAcima(cubo);
	int f8,r8, b8, l8;
    char* algoritmoBaixo;  
    char* algTraseiraDireitaBaixo;
    char* algEsquerdaTraseiraBaixo;
    char* algDireitaFrenteBaixo;
    char* giraBaixo;
	


	if (resolvidoPraCima == 0){
		algoritmo = "R U R' U R U U R' U";
		algTraseiraDireita = "L U L' U L U U L' U";
		algEsquerdaTraseira = "F U F' U F U U F' U";
		algDireitaFrente = "B U B' U B U U B' U"; //ok

		giraTopo = "U";
 
		CUB_ChecarCorDaFace(&f2, cubo, 0, 1, FRENTE);
		CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); //cor do meio da face da frente
		CUB_ChecarCorDaFace(&r2, cubo, 0, 1, DIREITA);
		CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); //cor do meio da face da direita
		CUB_ChecarCorDaFace(&b2, cubo, 0, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA); //cor do meio da face da traseira
		CUB_ChecarCorDaFace(&l2, cubo, 0, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); //cor do meio da face da esquerda

		if ((f2 == f5)&& (r2 == r5) && (b2 == b5) && (l2 == l5)){
			
			return 0;
	   }

	   while((f2 != f5) || (r2 != r5) || (b2 != b5) || (l2 != l5) ){

			executaAlgoritmo(cubo, giraTopo);

			

			CUB_ChecarCorDaFace(&f2, cubo, 0, 1, FRENTE);
			CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); //cor do meio da face da frente
			CUB_ChecarCorDaFace(&r2, cubo, 0, 1, DIREITA);
			CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); //cor do meio da face da direita
			CUB_ChecarCorDaFace(&b2, cubo, 0, 1, TRASEIRA);
			CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA); //cor do meio da face da traseira
			CUB_ChecarCorDaFace(&l2, cubo, 0, 1, ESQUERDA);
			CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); //cor do meio da face da esquerda


			if ((f2 == l5 && l2 == f5) || (l2 == b5 && b2 == l5) || (b2 == r5 && r2 == b5) || (r2 == f5 && f2 == r5) ){  // testa caso adjacentes

				if (f2 == l5 && l2 == f5 && r2 == r5){
				
					executaAlgoritmo(cubo, algoritmo);
				}
				else if (l2 == b5 && b2 == l5 && r2 == r5){
					
					executaAlgoritmo(cubo, algEsquerdaTraseira);
				}
				else if (b2 == r5 && r2 == b5 && f2 == f5){
					
					executaAlgoritmo(cubo, algTraseiraDireita);
				}
				else if (r2 == f5 && f2 == r5 && b2 == b5){
					
					executaAlgoritmo(cubo, algDireitaFrente);
				}

			}

			else if ((f2 == f5 && b2 == b5 && r2 != r5) || (r2 == r5 && l2 == l5 && f2 != f5 ) ){    // testa caso oposto igual

				if (f2 == f5 && b2 == b5){ 
					
					executaAlgoritmo(cubo, algoritmo);
					executaAlgoritmo(cubo, algTraseiraDireita);
				}

				else if (r2 == r5 && l2 == l5){
					
					executaAlgoritmo(cubo, algTraseiraDireita);
					executaAlgoritmo(cubo, algoritmo); 
                
				}
			}

			CUB_ChecarCorDaFace(&f2, cubo, 0, 1, FRENTE);
			CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);
			CUB_ChecarCorDaFace(&r2, cubo, 0, 1, DIREITA);
			CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); 
			CUB_ChecarCorDaFace(&b2, cubo, 0, 1, TRASEIRA);
			CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA); 
			CUB_ChecarCorDaFace(&l2, cubo, 0, 1, ESQUERDA);
			CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); 
	   }
	}


	else if (resolvidoPraCima == 1){
		algoritmoBaixo = "R' D' R D' R' D' D' R D'";    // R U R' U R U U R' U  //OK
		algTraseiraDireitaBaixo = "L' D' L D' L' D' D' L D'"; // "L U L' U L U U L' U"
		algEsquerdaTraseiraBaixo = "F' D' F D' F' D' D' F D'"; // "F U F' U F U U F' U"    //OK
		algDireitaFrenteBaixo = "B' D' B D' B' D' D' B D'"; //B U B' U B U U B' U //OK
		giraBaixo = "D'";
 
		CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);
		CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); //cor do meio da face da frente
		CUB_ChecarCorDaFace(&r8, cubo, 2, 1, DIREITA);
		CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); //cor do meio da face da direita
		CUB_ChecarCorDaFace(&b8, cubo, 2, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA); //cor do meio da face da traseira
		CUB_ChecarCorDaFace(&l8, cubo, 2, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); //cor do meio da face da esquerda

		if ((f8 == f5)&& (r8 == r5) && (b8 == b5) && (l8 == l5)){
		
			return 0;
	   }
		//(f8 != f5) || (r8 != r5) || (b8 != b5) || (l8 != l5)
	   while((f8 != f5) || (r8 != r5) || (b8 != b5) || (l8 != l5)){

			executaAlgoritmo(cubo, giraBaixo);

			CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);
			CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); //cor do meio da face da frente
			CUB_ChecarCorDaFace(&r8, cubo, 2, 1, DIREITA);
			CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); //cor do meio da face da direita
			CUB_ChecarCorDaFace(&b8, cubo, 2, 1, TRASEIRA);
			CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA); //cor do meio da face da traseira
			CUB_ChecarCorDaFace(&l8, cubo, 2, 1, ESQUERDA);
			CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

			if ((f8 == l5 && l8 == f5) || (l8 == b5 && b8 == l5) || (b8 == r5 && r8 == b5) || (r8 == f5 && f8 == r5) ){  // testa caso adjacentes

				if (f8 == l5 && l8 == f5){
					
					executaAlgoritmo(cubo, algoritmoBaixo);
				}
				else if (l8 == b5 && b8 == l5){
					
					executaAlgoritmo(cubo, algEsquerdaTraseiraBaixo);
				}
				else if (b8 == r5 && r8 == b5){
				
					executaAlgoritmo(cubo, algTraseiraDireitaBaixo);
				}
				else if (r8 == f5 && f8 == r5){
					
					executaAlgoritmo(cubo, algDireitaFrenteBaixo);
					 
					
				}

			}

			else if ((f8 == f5 && b8 == b5 && r8 != r5) || (r8 == r5 && l8 == l5 && f8 != f5) ){    // testa caso oposto igual

				if (f8 == f5 && b8 == b5){ 
				
					executaAlgoritmo(cubo, algoritmoBaixo);
					executaAlgoritmo(cubo, algTraseiraDireitaBaixo);
					
				}

				else if (r8 == r5 && l8 == l5){
					
					executaAlgoritmo(cubo, algEsquerdaTraseiraBaixo);
					executaAlgoritmo(cubo, algoritmoBaixo); 
			
                
				}
			}

			CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);
			CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); 
			CUB_ChecarCorDaFace(&r8, cubo, 2, 1, DIREITA);
			CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); 
			CUB_ChecarCorDaFace(&b8, cubo, 2, 1, TRASEIRA);
			CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);
			CUB_ChecarCorDaFace(&l8, cubo, 2, 1, ESQUERDA);
			CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); 
			
		
		}
	}
    return 0;
}
/**************************
*  $FC Fun��o: 3C  posicionaPecadeQuina
*
*  $ED Descri��o da fun��o
*	Algoritmo para a efetuar a sequencia de movimentos necessária posicionar a peça de quina.
*  $EPar�metros
*		$P cubo			
*  $FV Valor retornado
*       0- Peca de Quina posicionada
**************************/
int posicionaPecadeQuina (CUB_tppCUBO cubo){ //etapa 03

	int resolvidoPraCima = resolvidoAcima(cubo);
    int u1, u3, u5, u7, u9, f1, f3, f5, r1, r3, r5, b1, b3, b5, l1, l3, l5;
    char* frenteSupDir;
    char* esqSupDir;
    char* trasSupDir;
    char* dirSupDir;
    char* algoritmo;
    char* giraTopo;

	int d1, d3, d5, d7, d9, f7, f9,r7, r9,b7, b9, l7, l9;
	char* frenteInfDirBaixo;
    char* esqInfDirBaixo;
    char* trasInfDirBaixo;
    char* dirInfDirBaixo;
    char* algoritmoBaixo;
    char* giraBaixo;
	


	if (resolvidoPraCima == 0){
		algoritmo = "U R U' L' U R' U' L";
		frenteSupDir = "U R U' L' U R' U' L";
		esqSupDir = "U F U' B' U F' U' B";  
		trasSupDir = "U L U' R' U L' U' R";
		dirSupDir = "U B U' F' U B' U' F";
		giraTopo = "U";

		CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
		CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
		CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
		CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 
		CUB_ChecarCorDaFace(&u9, cubo, 2, 2, CIMA); 

		CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
		CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
		CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

		CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
		CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
		CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

		CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
		CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
		CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

		CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
		CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
		CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);


		if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 && conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0
		&& conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 && conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) == 0){

			return 0;

		}

		else if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) != 0 && conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) != 0
		&& conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) != 0 && conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) != 0){

		
			executaAlgoritmo(cubo, algoritmo);
			CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
			CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
			CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
			CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

			CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
			CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
			CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

			CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
			CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
			CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

			CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
			CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
			CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

			CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
			CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
			CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
		}



		// dependendo de onde a posicao esta certa, faz alg em relacao a peca: se resolver, ok, senao faz alg mais uma vez

		if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 || conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0
		|| conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 || conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) == 0){

			
         

			if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 ){  //alg em relacao a face da frente
		
				executaAlgoritmo(cubo,  frenteSupDir);
				CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

				if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 && conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0
				&& conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 && conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) == 0){
				
					return 0;
				}
				else{
					executaAlgoritmo(cubo,  frenteSupDir);
					CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
				}

			}
			else if (conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0){ //alg em relacao a face da direita
			
				 executaAlgoritmo(cubo,  dirSupDir);
				 CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

				  if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 && conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0
				&& conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 && conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) == 0){
				
					return 0;
				}

				else{
					executaAlgoritmo(cubo,  dirSupDir);
					CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
				}
			}
			else if (conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 ){ //alg em relaca a face traseira
				
				executaAlgoritmo(cubo,  trasSupDir);
				CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

				 if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 && conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0
				&& conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 && conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) == 0){
					
					return 0;
				}

				else{
					executaAlgoritmo(cubo,  trasSupDir);
					CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
				}

 
			}
			else { //alg em relacao a face da direita
			
				executaAlgoritmo(cubo,  esqSupDir);
				CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
				CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
				CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
				CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

				CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
				CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
				CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

				CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
				CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
				CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

				CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
				CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
				CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

				CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
				CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
				CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

            
				if (conjuntosSaoEquivalentes(u9,f3,r1,u5,f5,r5) == 0 && conjuntosSaoEquivalentes(u3,r3,b1,u5,r5,b5) == 0
				&& conjuntosSaoEquivalentes(u1,b3,l1,u5,b5,l5) == 0 && conjuntosSaoEquivalentes(u7,l3,f1,u5,l5,f5) == 0){
				
					return 0;
				}

				else{
					executaAlgoritmo(cubo,  esqSupDir);
					CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
					CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA); 
					CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA);
					CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA); 

					CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
					CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
					CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
              
				}
			}       
		}
	}

	if (resolvidoPraCima == 1){

		algoritmoBaixo = "D' R' D L D' R D L'"; //FRENTE INF DIR BAIXO
		frenteInfDirBaixo = "D' R' D L D' R D L'"; //"U R U' L' U R' U' L" //OK
		esqInfDirBaixo = "D' F' D B D' F D B'";  //"U F U' B' U F' U' B"; //OK
		trasInfDirBaixo = "D' L' D R D' L D R'"; // "U L U' R' U L' U' R"; //OK
		dirInfDirBaixo = "D' B' D F D' B D F'"; //U B U' F' U B' U' F //OK
		giraBaixo = "D'";

		CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
		CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
		CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
		CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
		CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

		CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
		CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
		CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

		CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
		CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
		CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

		CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
		CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
		CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

		CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
		CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
		CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

		if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0 && conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5) == 0
		&& conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 && conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5)== 0){

			return 0;

		}

		else if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) != 0 && conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5) != 0
		&& conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5)!= 0 && conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5)!= 0){


			executaAlgoritmo(cubo, algoritmoBaixo);
			CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
			CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
			CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
			CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
			CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

			CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
			CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
			CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

			CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
			CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
			CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

			CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
			CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
			CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

			CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
			CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
			CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
        
		}

		//dependendo de onde a posicao esta certa, faz alg em relacao a peca: se resolver, ok, senao faz alg mais uma vez

		if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0 || conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5)  == 0
		|| conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 || conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5) == 0){

		
         

			if (conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5) == 0 ){  //alg em relacao a face da frente
			
				executaAlgoritmo(cubo,  frenteInfDirBaixo);
				CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
				CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
				CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
				CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
				CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

				CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
				CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
				CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

				CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
				CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
				CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

				CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
				CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
				CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

				CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
				CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
				CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); 
            

				 if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0 && conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5)  == 0
						&& conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 && conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5) == 0){

			
					return 0;
				}
				else{
					executaAlgoritmo(cubo,  frenteInfDirBaixo);
					CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
					CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
					CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
					CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
					CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

					CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
					CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
					CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); 
				}

			}

			else if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0){ //alg em relacao a face da direita
			
				executaAlgoritmo(cubo,  dirInfDirBaixo);
				CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
				CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
				CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
				CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
				CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

				CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
				CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
				CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

				CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
				CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
				CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

				CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
				CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
				CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

				CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
				CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
				CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

				if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0 && conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5)  == 0
				&& conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 && conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5) == 0){
				
					return 0;
				}

				else{
					executaAlgoritmo(cubo,  dirInfDirBaixo);
					CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
					CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
					CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
					CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
					CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

					CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
					CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
					CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
				}
			}

			else if (conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5) == 0 ){ //alg em relaca a face traseira
			
				executaAlgoritmo(cubo,  trasInfDirBaixo);
				CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
				CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
				CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
				CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
				CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

				CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
				CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
				CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

				CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
				CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
				CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

				CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
				CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
				CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

				CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
				CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
				CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

				 if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0 && conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5)  == 0
				&& conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 && conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5) == 0){
					
					return 0;
				}

				else{
					executaAlgoritmo(cubo,  trasInfDirBaixo);
					CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
					CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
					CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
					CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
					CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

					CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
					CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
					CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
				}

 
			}
			else if (conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 ){ //alg em relacao a face da direita
			
				executaAlgoritmo(cubo,  esqInfDirBaixo);
				CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
				CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
				CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
				CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
				CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

				CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
				CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
				CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

				CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
				CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
				CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

				CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
				CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
				CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

				CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
				CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
				CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

				if (conjuntosSaoEquivalentes(d9,b7,r9,d5,b5,r5) == 0 && conjuntosSaoEquivalentes(d3,r7,f9,d5,r5,f5)  == 0
				&& conjuntosSaoEquivalentes(d1,f7,l9,d5,f5,l5) == 0 && conjuntosSaoEquivalentes(d7,b9,l7,d5,b5,l5) == 0){
					
					return 0;
				}

				else{
				   executaAlgoritmo(cubo,  esqInfDirBaixo);
					CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
					CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO); 
					CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO);
					CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO); 
					CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

					CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
					CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE); 
					CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

					CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
					CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA); 
					CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

					CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
					CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA); 
					CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);

					CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
					CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA); 
					CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);
              
				}
			}       
		}

	}
    return 0;
}
/**************************
*  $FC Fun��o: 3C  acertaPecadeQuina
*
*  $ED Descri��o da fun��o
*	Algoritmo para a efetuar a sequencia de movimentos necessária posicionar a peça de quina
*	no local correto.
*  $EPar�metros
*		$P cubo			
*  $FV Valor retornado
*       0- Peca de Quina acertada
**************************/
int acertaPecadeQuina (CUB_tppCUBO cubo){ //etapa 04

    int u1, u3, u5, u7, u9, r1, f1, f2, f5, f8, f3, r3, r5, l1, l3, l5, b1, b3, b5;
    char* algoritmo;
    char* giraTopo;
	int resolvidoPraCima = resolvidoAcima(cubo);

	int d1, d3, d5, d7, d9, f7, f9, r7, r9, r8, b7, b9, b8, l7, l9, l8;
    char* algoritmoBaixo;
    char* giraBaixo;
	

	if (resolvidoPraCima == 0){
		giraTopo = "U";
		algoritmo = "R' D' R D";

		CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
		CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA);
		CUB_ChecarCorDaFace(&u5, cubo, 1, 1, CIMA); 
		CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA);
		CUB_ChecarCorDaFace(&u9, cubo, 2, 2, CIMA); 

		CUB_ChecarCorDaFace(&f1, cubo, 0, 0, FRENTE);
		CUB_ChecarCorDaFace(&f2, cubo, 0, 1, FRENTE);
		CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE);
		CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); 
		CUB_ChecarCorDaFace(&f8, cubo, 0, 2, FRENTE);

		CUB_ChecarCorDaFace(&r1, cubo, 0, 0, DIREITA);
		CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA);
		CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA);

		CUB_ChecarCorDaFace(&l1, cubo, 0, 0, ESQUERDA);
		CUB_ChecarCorDaFace(&l3, cubo, 0, 2, ESQUERDA);
		CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA);

		CUB_ChecarCorDaFace(&b1, cubo, 0, 0, TRASEIRA);
		CUB_ChecarCorDaFace(&b3, cubo, 0, 2, TRASEIRA);
		CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA);
		while(saoTodosAmarelos(u1, u3, u7, u9) != 0){ // comecar pela quina superior direita da face da frente

			CUB_ChecarCorDaFace(&r3, cubo, 0, 2, DIREITA);
			CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE);
			CUB_ChecarCorDaFace(&u9, cubo, 2, 2, CIMA); 
			CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE);
			CUB_ChecarCorDaFace(&f2, cubo, 0, 1, FRENTE);

			while (u9 != u5 || f3 != f2){
				executaAlgoritmo(cubo, algoritmo);     
				CUB_ChecarCorDaFace(&u9, cubo, 2, 2, CIMA); 
				CUB_ChecarCorDaFace(&f3, cubo, 0, 2, FRENTE);
				CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE);

			}

			executaAlgoritmo(cubo, giraTopo);
			CUB_ChecarCorDaFace(&u1, cubo, 0, 0, CIMA);
			CUB_ChecarCorDaFace(&u3, cubo, 0, 2, CIMA);
			CUB_ChecarCorDaFace(&u7, cubo, 2, 0, CIMA);
			CUB_ChecarCorDaFace(&u9, cubo, 2, 2, CIMA); 
		}

		while (f2 != f5){

			executaAlgoritmo(cubo, giraTopo);
			CUB_ChecarCorDaFace(&f2, cubo, 0, 1, FRENTE);

		}
	}

	else if (resolvidoPraCima == 1){

		giraBaixo = "D'";
		algoritmoBaixo = "R U R' U'";

		CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
		CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO);
		CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO); 
		CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO);
		CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 

		CUB_ChecarCorDaFace(&f5, cubo, 1, 1, FRENTE); 
		CUB_ChecarCorDaFace(&f7, cubo, 2, 0, FRENTE);
		CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE);
		CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);

		CUB_ChecarCorDaFace(&r5, cubo, 1, 1, DIREITA); 
		CUB_ChecarCorDaFace(&r7, cubo, 2, 0, DIREITA);
		CUB_ChecarCorDaFace(&r9, cubo, 2, 2, DIREITA);
		CUB_ChecarCorDaFace(&r8, cubo, 2, 1, DIREITA);

		CUB_ChecarCorDaFace(&b5, cubo, 1, 1, TRASEIRA); 
		CUB_ChecarCorDaFace(&b7, cubo, 2, 0, TRASEIRA);
		CUB_ChecarCorDaFace(&b9, cubo, 2, 2, TRASEIRA);
		CUB_ChecarCorDaFace(&b8, cubo, 2, 1, TRASEIRA);

		CUB_ChecarCorDaFace(&l5, cubo, 1, 1, ESQUERDA); 
		CUB_ChecarCorDaFace(&l7, cubo, 2, 0, ESQUERDA);
		CUB_ChecarCorDaFace(&l9, cubo, 2, 2, ESQUERDA);
		CUB_ChecarCorDaFace(&l8, cubo, 2, 1, ESQUERDA);
		while(saoTodosAmarelos(d1, d3, d7, d9) != 0){ 

			CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO);
			CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE);
			CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);

			while (d3 != d5 || f9 != f8){
				executaAlgoritmo(cubo, algoritmoBaixo);
				CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO);
				CUB_ChecarCorDaFace(&f9, cubo, 2, 2, FRENTE);
				CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);
			}

			executaAlgoritmo(cubo, giraBaixo);

			CUB_ChecarCorDaFace(&d1, cubo, 0, 0, BAIXO);
			CUB_ChecarCorDaFace(&d3, cubo, 0, 2, BAIXO);
			CUB_ChecarCorDaFace(&d5, cubo, 1, 1, BAIXO); 
			CUB_ChecarCorDaFace(&d7, cubo, 2, 0, BAIXO);
			CUB_ChecarCorDaFace(&d9, cubo, 2, 2, BAIXO); 
		}

		while (f8 != f5){

			executaAlgoritmo(cubo, giraBaixo);
			CUB_ChecarCorDaFace(&f8, cubo, 2, 1, FRENTE);

		}
	}
    return 0;
}
/**************************
*  $FC Fun��o: 3C  resolve3Camada
*
*  $ED Descri��o da fun��o
*	Algoritmo para a efetuar a sequencia de movimentos necessária para resolver a 3 camada do cubo
*  $EPar�metros
*		$P cubo
*		$P comandos
*  $FV Valor retornado
*       TEC_tpCondRetVazio- cubo vazio
*		TEC_tpCondRetOK - 3 camada resolvida
**************************/
TEC_tpCondRet resolve3Camada(CUB_tppCUBO cubo, char *comandos){

    int i, j = 0;
	comandos[0] = '\0';
	if (cubo == NULL)
		return  TEC_tpCondRetVazio;
	CUB_ChecarCorDaFace(&AMARELO, cubo, 1, 1, CUB_faceInferior);

	resolveCruz(cubo);

    acertaAresta(cubo); 

    posicionaPecadeQuina(cubo); 

    acertaPecadeQuina(cubo); 

	strcpy(comandos, execute);
    return TEC_tpCondRetOK;
}