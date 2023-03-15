#include "header.h"

int main(int argc, char *argv[]) {

	double start = omp_get_wtime();
	double tempoTotal;



	printf("\nINICIO\n");
	//============================================================================
	//DadosEntrada dado =	Ler("C:/Users/odair/Documents/GitHub/IT_FAPERJ_2020/IT_FAPERJ_2020_Windows/datafiler/Dados2.txt");
        DadosEntrada dado =	Ler("/home/viktor/Documentos/GitHub/IT_FAPERJ_2020/IT_FAPERJ_2020/datafiler/Dados4.txt");

	//============================================================================
	FillingTheQuadratureStruct(dado.ordQuad);
	//============================================================================

	//variaveis para o do
	double keff = 1; //mechi nessa aqui
	double errofi = 0;
	double errokeff = 0;
	//============================================================================
	//VARIAVEL PARA SOMA DOS NODOS DE X ==========================================
	int I = 0;
	for (int i = 0; i < dado.numRegX; i++){
		I += dado.parRegX[i];
	}
	//VARIAVEL PARA SOMA DOS NODOS DE Y ==========================================
	int J = 0;
	for (int j = 0; j < dado.numRegY; j++){
		J += dado.parRegY[j];
	}
	//VARIAVEL PARA O TOTAL DE NUMERO DE GRUPOS ==================================
	int G = dado.numGrp;
	//============================================================================
	int M = (dado.ordQuad * (dado.ordQuad + 2)) / 2;
	//============================================================================
	ps.psiT = alocar1DDouble(J * (I + 1) * M * G);
	ps.psiC = alocar1DDouble(I * (J + 1) * M * G);
	//double *psiBarra = alocar1DDouble(J * (I + 1) * M * G);
	double *fonteEspalhamento = alocar1DDouble(J * I * G);
	double *fonteFis = alocar1DDouble(J * I); // criada em G J I se organizando por linhas int idF = g * J * I + j*I + i;
	double *fiT = alocar1DDouble(G * J * I);

	//============================================================================
	int *mapX = alocar1DInteger(I);
	int *mapY = alocar1DInteger(J);
	double *hx = alocar1DDouble(I);
	double *hy = alocar1DDouble(J);
	//============================================================================
	int k = 0;		//variavel situacional somente para indice
	//MAPEAMENTO DAS REGIOES EM X
	for (int r = 0; r < dado.numRegX; r++) {
		double temp = dado.tamRegX[r] / dado.parRegX[r];
		for (int pR = 0; pR < dado.parRegX[r]; pR++) {
			hx[k] = temp;
			mapX[k] = r;
			//printf("%i", r);
			k++;
		}
		//printf("\n");
	}
	k = 0; //printf("\n");
	//MAPEAMENTO DAS REGIOES EM Y
	for (int r = 0; r < dado.numRegY; r++) {
		double temp = dado.tamRegY[r] / dado.parRegY[r];
		for (int pR = 0; pR < dado.parRegY[r]; pR++) {
			hy[k] = temp;
			mapY[k] = r;
			//printf("%i", r);
			k++;
		}
		//printf("\n");
	}
	//============================================================================

	//printf("\n MIDDLE");

	//PROGRAMAR ==================================================================
	// CONTROLE DE INDICE e MAPEAMENTO DO SIGMA TOTAL - FOI
	// A CONSTANTE E A FONTE
	//============================================================================

	//INFORMA��ES �TEIS ==========================================================
	//   I |-> Dados de X
	//   J |-> Dados de Y
	//============================================================================

	//D�VIDAS ====================================================================
	//PERGUNTAR SOBRE A ORDEM DAS VARREDURAS COM RELA��O AOS QUADRANTES
	//============================================================================

	//CALCULO DAS CONDI��ES DE CONTORNO ========================================
	/*
	 * (i+1,j) = 2  _______  (i+1,j+1) = 1
		 *         |       |
		 *     fiT |       |
		 *         |_______|
	 *    (ij) = 3   fiC    (i,j+1) = 4
	 * */

	//VARIAVEIS A SER SUBSTITUIDAS OTIMIZA��O ====================
	int j1 = J + 1;
	int i1 = I + 1;
	int JMI1 = J * (I + 1) * M;
	int IMJ1 = I * (J + 1) * M;
	int JI1 = J * (I + 1);
	int IJ1 = I * (J + 1);
	int M4 = M / 4;
	int M2 = M / 2;

	//condi�oes de contorno
	//ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,int j1,double *esquerda,double *direita,double *cima,double *baixo)
	//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

	/*psiT[0] = dado.cce[0];
	 psiT[I] = dado.ccd[0];
	 psiC[0] = dado.ccb[0];
	 psiC[J] = dado.ccc[0];*/
	//============================================================================
	int a = 0;

	// as fonte de fi�ao e espalhamento estao sendo iniciadas antes de entrar nos do para serem atualizadas ao final do mesmo
	// INICIALIZA�AO DA FONTE DE FI��O============================================
	double somSFK = 0.0;
	double somSFKold = 0.0;
	double KeffOLD;
	//fonte fiss�o esta sem o keff sendo igual ao S
	//for (int g = 0; g < G; g++) { vou deixar comentador para utilizar o chi como constante
	for (int j = 0; j < J; j++) {
		for (int i = 0; i < I; i++) {
			fonteFis[a] = 1;
			/*
			double tmp = 0;
			for (int gLin = 0; gLin < G; gLin++) {
				for (int m = 0; m < M; m++) {
					int idI = +(gLin * J * (I + 1) * M) + (m * J * (I + 1))
							+ (j * (I + 1) + i);
					tmp += (ps.psiT[idI + 1] + ps.psiT[idI]) * qt.w[m]; //calcula o dobro do psiBarra
				}
				int idZ = dado.mapZona[mapY[j] * dado.numRegX + mapX[i]];
				fonteFis[a] += dado.sigfic[idZ * G + gLin] * tmp;
			}
			fonteFis[a] *= 0.125; //corre��o do psi barra aqui
			*/
			somSFK += hx[mapX[i]] * hy[mapY[j]] * fonteFis[a];
			a++;
		}
	}
	//printf("\n valor de somSFK:%f", somSFK);
	//}
	//============================================================================
	// INICIALIZA�AO DA FONTE DE ESPALHAMENTO===================================== !!!!!!REVER C�LCULO DO FLUXO ESCALAR JUNDO A FONTE DE ESPALHAMENTO, ATENTAR PARA O G!!!!
	int fE = 0;		//variavel momentanea para controle de indice
	for (int g = 0; g < dado.numGrp; g++) {
		for (int j = 0; j < J; j++) {
			for (int i = 0; i < I; i++) {
				fonteEspalhamento[k] = 0;
				for (int gLin = 0; gLin < dado.numGrp; gLin++) {
					double tmp = 0;
					for (int m = 0; m < M; m++) { //substituir M por n
						int idI = (gLin * J * (I + 1) * M) + (m * J * (I + 1))
								+ (j * (I + 1) + i);
						tmp += (ps.psiT[idI + 1] + ps.psiT[idI]) * qt.w[m]; //calcula o dobro do psiBarra
					}
					int idZ = dado.mapZona[mapY[j] * dado.numRegX + mapX[i]];
					fonteEspalhamento[fE] += tmp
							* dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posi�ao do Glin se e antes ou depois do G
					int idfi = gLin * J * I + j * I + i;
					fiT[idfi] = tmp * 0.5;
				}
				fonteEspalhamento[fE] *= 0.125; //corre�ao do psiBarra para evitar multiplica�oes
				//printf("\n fonteEspalhamento[%i]: %f",fE,fonteEspalhamento[fE]);
				fE++;

			}
		}
	}
	int contKeff = 0;
	//============================================================================

	//double test = 0;
	//double varrer = omp_get_wtime();
	do {
		contKeff++;
		int contFluxo = 0;
		do {
			contFluxo++;
			//NO FOR DE g CONTEM TODA AS VARREDURAS NOS N SENTIDOS CONTENDO A VARREDURA EM SI
			for (int g = 0; g < G; g++) {
				double stmp = 0;
				// VARREDURA 31 SO --> NE ===========================================================
				for (int m = 0; m < M4; m++) {
					for (int j = 0; j < J; j++) {
						int jlin = mapY[j] * dado.numRegX;
						int fe = g * J * I + j * I;
						for (int i = 0; i < I; i++) {
							//VARIAVEIS DE IDENTIFICA��O =================================
							int idI = g * JMI1 + m * JI1 + j * i1 + i; //bloco + camada + linha + coluna
							int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
							int idZ = dado.mapZona[mapX[i] + jlin ];
							double divisor = qt.mi[m] / hx[i] + qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
							//============================================================
							//ATENTAR-SE NO FUTURO A EFICI�NCIA DA VERS�O SEM OS IF'S
							//EQUA��O 26 |SO - NE| =======================================

							ps.psiT[idI + 1] = ((qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI]
									+ 2 * qt.eta[m] * ps.psiC[idJ] / hy[j]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / divisor; //gatilho para 2 grupos

							//EQUA��O 27 |SO - NE| ========================================

							ps.psiC[idJ + 1] = ((-qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ]
									+ 2 * qt.mi[m] * ps.psiT[idI] / hx[i]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / divisor;
							stmp += ps.psiT[idI];
							//==================Condi��o de contorno a Acima===============
							if ((dado.ccc[g] < 0) && (j = J-1)) {
								int idq1 = g * IMJ1 + (m         ) * IJ1 + i * j1 + J;
								int idq4 = g * IMJ1 + (m + 3 * M4) * IJ1 + i * j1 + J;
								ps.psiC[idq4] = ps.psiC[idq1];
							}
							//==============================================================
						}
						//==================Condi��o de contorno a Direita=================
						if (dado.ccd[g] < 0) {
							int idq1 = g * JMI1 + (m         ) * JI1 + j * i1 + I;
							int idq2 = g * JMI1 + (m +     M4) * JI1 + j * i1 + I;
							ps.psiT[idq2] = ps.psiT[idq1];
						}
						//==================================================================
					}
				}

				//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
				//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

				//printf("VARREDURA 31: %f\n", stmp);
				stmp = 0;
				// VARREDURA 42 SE --> NO ===========================================================
				for (int m = M4; m < M2; m++) {
					for (int j = 0; j < J; j++) {
						int jlin = mapY[j] * dado.numRegX;
						int fe = g * J * I + j * I;
						for (int i = I-1; i >= 0; i--) {

							//VARIAVEIS DE IDENTIFICA��O =================================
							int idI = g * JMI1 + m * JI1 + j * i1 + i;
							int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
							int idZ = dado.mapZona[mapX[i] + jlin];
							double divisor = -qt.mi[m] / hx[i] + qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
							//============================================================
							//EQUA��O 28 |SE - NO| =======================================

							ps.psiT[idI] = ((-qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI + 1]
									+ 2 * qt.eta[m] * ps.psiC[idJ] / hy[j]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / divisor;

							//EQUA��O 29 |SE - NO| ========================================

							ps.psiC[idJ + 1] = ((qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ])	* ps.psiC[idJ]
									- 2 * qt.mi[m] * ps.psiT[idI + 1] / hx[i]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / (divisor);
							stmp += ps.psiT[idI];
							//printf("(%i - %.0f, %i - %.0f)\t", i, hx[i], j, hy[j]);
							//printf("(%i, %i) %d\t", j, i, fe + i);
							//printf("(%i, %i) %e\t", i, j, ps.psiT[idI + 1]);
							//test += ps.psiT[idI];
							//==============================================================

							//==================Condi��o de contorno a Acima==============
							if ((dado.ccc[g] < 0) && (j = J-1)) {
								int idq2 = g * IMJ1 + (m     ) * IJ1 + i * j1 + J;
								int idq3 = g * IMJ1 + (m + M4) * IJ1 + i * j1 + J;
								ps.psiC[idq3] = ps.psiC[idq2];
							}
							//==============================================================
						}
						//==================Condi��o de contorno a Esquerda=================
						if (dado.cce[g] < 0) {
							int idq1 = g * JMI1 + (m - M4) * JI1 + j * i1;
							int idq2 = g * JMI1 + (m     ) * JI1 + j * i1;
							ps.psiT[idq1] = ps.psiT[idq2];
						}
						//==================================================================
					}
				}
				//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
				//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);


				//printf("VARREDURA 42: %f\n", stmp);
				stmp = 0;
				// VARREDURA 13 NE --> SO ===========================================================
				for (int m = M2; m < 3 * M4; m++) {
					for (int j = J-1; j >= 0; j--) {
						int jlin = mapY[j] * dado.numRegX;
						int fe = g * J * I + j * I;
						for (int i = I-1; i >= 0; i--) {
							//VARIAVEIS DE IDENTIFICA��O =================================
							int idI = g * JMI1 + m * JI1 + j * i1 + i;
							int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
							int idZ = dado.mapZona[mapX[i] + jlin];
							double divisor = -qt.mi[m] / hx[i] - qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
							//============================================================
							//EQUA��O 26 |NE - SO| =======================================

							ps.psiT[idI] = ((-qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI + 1]
									- 2 * qt.eta[m] * ps.psiC[idJ + 1] / hy[j]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / (divisor);

							//EQUA��O 27 |NE - SO| ========================================

							ps.psiC[idJ] = ((qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ + 1]
									- 2 * qt.mi[m] * ps.psiT[idI + 1] / hx[i]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / (divisor);
							stmp += ps.psiT[idI];
							//==============================================================
							//printf("%i (%i, %i) %e\t",J, i, j, ps.psiT[idI + 1]);
							//==================Condi��o de contorno a Abaixo==============
							if ((dado.ccb[g] < 0) && (j == 0)) {
								int idq2 = g * IMJ1 + (m - M4) * IJ1 + i * j1;
								int idq3 = g * IMJ1 + (m     ) * IJ1 + i * j1;
								ps.psiC[idq2] = ps.psiC[idq3];
							}
							//==============================================================
						}
						//==================Condi��o de contorno a Esquerda=================
						if (dado.cce[g] < 0) {
							int idq3 = g * JMI1 + (m     ) * JI1 + j * i1;
							int idq4 = g * JMI1 + (m + M4) * JI1 + j * i1;
							ps.psiT[idq4] = ps.psiT[idq3];
						}
						//==================================================================
					}
				}
				//printf("VARREDURA 13: %f\n", stmp);
				stmp = 0;
				//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
				//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

				// VARREDURA 24 NO --> SE ===========================================================
				for (int m = 3 * M4; m < M; m++) {
					for (int j = J-1; j >= 0; j--) {
						int jlin = mapY[j] * dado.numRegX;
						int fe = g * J * I + j * I;
						for (int i = 0; i < I; i++) {

							//VARIAVEIS DE IDENTIFICA��O =================================
							int idI = g * JMI1 + m * JI1 + j * i1 + i;
							int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
							int idZ = dado.mapZona[mapX[i] + jlin];
							double divisor = qt.mi[m] / hx[i] - qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
							//============================================================
							//EQUA��O 28 |NO - SE| =======================================

							ps.psiT[idI + 1] = ((qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI]
									- 2 * qt.eta[m] * ps.psiC[idJ + 1] / hy[j]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / (divisor);

							//EQUA��O 29 |NO - SE| ========================================

							ps.psiC[idJ] = ((-qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ + 1]
									+ 2 * qt.mi[m] * ps.psiT[idI] /  hx[i]
									+ fonteEspalhamento[fe + i]
									+ (1-g) * fonteFis[j * I + i] / keff) / (divisor);
							//stmp += ps.psiT[idI + 1];
							//==================Condi��o de contorno a Abaixo==============
							if ((dado.ccb[g] < 0) && (j == 0)) {
								int idq1 = g * IMJ1 + (m - 3 * M4) * IJ1 + i * j1;
								int idq4 = g * IMJ1 + (m         ) * IJ1 + i * j1;
								ps.psiC[idq1] = ps.psiC[idq4];
							}
							//==============================================================
						}
						//==================Condi��o de contorno a Direita=================
						if (dado.ccd[g] < 0) {
							int idq1 = g * JMI1 + (m - 3 * M4) * JI1 + j * i1 + I;
							int idq4 = g * JMI1 + (m         ) * JI1 + j * i1 + I;
							ps.psiT[idq1] = ps.psiT[idq4];
						}
						//==================================================================
					}
				}
				//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
				//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

				//printf("VARREDURA 24: %f\n", stmp);

				// =======================================================================
			}
			//============================================================================
			//C�LCULO DO ERRO  agora feito junto ao ATUALIZADOR da fonte de espalhamento============================================================
			fE = 0;		//variavel momentanea para controle de indice
			errofi = 0;
			for (int g = 0; g < dado.numGrp; g++) {
				for (int j = 0; j < J; j++) {
					for (int i = 0; i < I; i++) {

						fonteEspalhamento[fE] = 0;
						for (int gLin = 0; gLin < dado.numGrp; gLin++) {
							double tmp = 0;
							for (int n = 0; n < M; n++) { //substituir M por n
								int idI = gLin * J * (I + 1) * M //bloco
										+ n * J * (I + 1)       //Camada
										+ j * (I + 1)          //linha
										+ i;                  //coluna
								tmp += (ps.psiT[idI + 1] + ps.psiT[idI]) * qt.w[n]; //calcula o dobro do psiBarra

							}
							int idZ = dado.mapZona[mapY[j] * dado.numRegX + mapX[i]];
							fonteEspalhamento[fE] += tmp * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posi�ao do Glin se e antes ou depois do G
							int idfi = gLin * J * I + j * I + i;

							double fitOld = fiT[idfi]; //fiT � fluxo escalar calculado usando o fluxo angular psiT.

							fiT[idfi] = tmp * 0.25;
							//printf(" \n erro do fluxo absoluto = %f", fiT[idfi] - fitOld);
							double tmperro = modulo(
									(fiT[idfi] - fitOld) / fiT[idfi]);

							if (errofi < tmperro)
								errofi = tmperro;
							//printf("%e\n",errofi);
						}
						fonteEspalhamento[fE] *= 0.125; //corre�ao do psiBarra para evitar multiplica�oes
						fE++;
					}
				}
			}
			// =======================================================================
			//printf(" \n erro do fluxo = %f", errofi);
			//printf(" \n teste = %f", test);
			//test = 0;
		} while (errofi > dado.cp2);
		//calculo da fonte velha
		//atualiza a fonte de ficao

		//ATUALIZA A FONTE DE FI�AO PARA RETORNAR AO DO DA VARREDURA==================
		int fF = 0;

		somSFKold = somSFK;
		somSFK = 0;
		//for (int g = 0; g < G; g++) { vou deixar comentador para utilizar o chi como constante
		for (int j = 0; j < J; j++) {
			for (int i = 0; i < I; i++) {
				fonteFis[fF] = 0;
				double tmp = 0;
				for (int gLin = 0; gLin < G; gLin++) {
					for (int m = 0; m < M; m++) {
						int idI = gLin * J * (I + 1) * M //bloco
								+ m * J * (I + 1)       //Camada
								+ j * (I + 1)          //linha
								+ i;                  //coluna
						tmp += (ps.psiT[idI + 1] + ps.psiT[idI]) * qt.w[m]; //calcula o dobro do psiBarra

					}
					int idZ = dado.mapZona[mapY[j] * dado.numRegX + mapX[i]];
					fonteFis[fF] += dado.sigfic[idZ *G + gLin] * tmp;

				}
				fonteFis[fF] *= 0.125;
				somSFK += hx[i] * hy[j] * fonteFis[fF];
				fF++;
			}
		}
		//printf(" \n Valor de keff = %f", somSFK);

		KeffOLD = keff;
		keff =  (KeffOLD * somSFK) / somSFKold    ;
		//keff= 1 / keff;
		errokeff = modulo(keff - KeffOLD) / keff;
		//printf("\n somSFK = %f",somSFK);

		//printf(" \n Valor de keff = %e", keff);
		//}
		//printf(" \n erro do cp = %f", dado.cp1);
		// =======================================================================
		//printf("  contFluxo = %i\n", contFluxo);


	} while (errokeff > dado.cp1);

	printf("\nkeff = %e", keff);
	/*
	 * C�lculo da pot�ncia do reator
	 */

	desalocar1DDouble( ps.psiC);
	desalocar1DDouble( fonteFis);
	desalocar1DDouble( fonteEspalhamento);
	int Lin = dado.numRegY, Col = dado.numRegX;
	double * Pot = alocar1DDouble(G * Lin * Col);
	double * tmpReg = alocar1DDouble(G * Lin * Col);
	double * potFalse = alocar1DDouble(G);
	printf("\n\n\n");
	for (int g = 0; g < G; g++) {
		potFalse[g] = 0;
		for (int j = 0; j < J; j++) {
			for (int i = 0; i < I; i++) {
				double tmp = 0;
				for (int m = 0; m < M; m++) {
					int idI = g * J * (I + 1) * M //bloco
							+ m * J * (I + 1)       //Camada
							+ j * (I + 1)          //linha
							+ i;                  //coluna
					tmp += (ps.psiT[idI + 1] + ps.psiT[idI]) * qt.w[m]; //calcula o dobro do psiBarra
					tmpReg[mapY[j] * dado.numRegX + mapX[i]] += (ps.psiT[idI + 1] + ps.psiT[idI]) * qt.w[m];
				}
				int idZ = dado.mapZona[mapY[j] * dado.numRegX + mapX[i]];
				potFalse[g] +=  hx[i] * hy[j] * dado.sigfic[idZ] * tmp;
			}
		}
		potFalse[g] *= 3.2 * 1E-11 * 0.125;
	}
	for (int g = 0; g < G; g++) {
		for (int l = Lin - 1; l >= 0; l--) {
			for (int c = 0; c < Col; c++) {
				int idZ = dado.mapZona[l * Col + c];
				double HX = dado.tamRegX[c] / dado.parRegX[c], HY = dado.tamRegY[l] / dado.parRegY[l];
				Pot[g * Lin * Col + l * Col + c] = 3.2 * 1E-5 * 0.125 * HX * HY * dado.sigfic[idZ] * tmpReg[l * Col + c] * dado.pot / potFalse[g];
				printf("%e\t",Pot[g * Lin * Col + l * Col + c]);
			}
			printf("\n");
		}
	}
	tempoTotal = omp_get_wtime() - start;
	//printf("\nTotal de tempo gasto para ler arquivo = %.7f\n",tempoTotal);
	//tempoTotal = omp_get_wtime() - varrer;
	//printf("\nTotal de tempo gasto nas varreduras = %.3f\n",tempoTotal);
	//tempoTotal = omp_get_wtime() - start;
	/*===============================================================================*/
	printf("\nTotal de tempo gasto  = %.3f\n",tempoTotal);
	printf("\nFIM\n");
	return 0;

}
