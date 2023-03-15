/*
 * functions.c
 *
 *  Created on: 30 de set de 2020
 *      Author: odair
 */
#include "header.h"

//============================================================================

//=============================================

//ALLOCATIONS =================================
double **DoubVet2D(int dim1, int dim2){
    // declaração de variável ponteiro para ponteiro
    double **vet2D;

    // alocando o vetor de ponteiros
    vet2D = (double**)malloc(dim1 * sizeof(double*));

    // alocando cada uma das linhas da matriz
    for(int i = 0; i < dim1; i++)
        vet2D[i] = (double*)malloc(dim2 * sizeof(double));
    return vet2D;
}

double* alocar1DDouble(int tamanho) {
	double *vetor;
	vetor = (double*) calloc(tamanho, sizeof(double));
	return vetor;
}
void desalocar1DDouble(double *vetor) {
	free(vetor);
}
//=============================================
int* alocar1DInteger(int tamanho) {
	int *vetor;
    vetor = (int*) calloc(tamanho, sizeof(int));
	return vetor;
}
void desalocar1DInteger(int *vetor) {
	free(vetor);
}
//=============================================

// MAIN FUNCTION ==============================
void FillingTheQuadratureStruct(int N) {
	//VETORES PREENCHIDOS [4 QUADRANTES]
	/*
	qt.w = GetWFullVector(N);
	qt.eta = GetEtaFullVector(N);
	qt.mi = GetMiFullVector(N);
	 */

	//TAMANHO DO VETOR COMPLETO [4 QUADRANTES]
	int size = N * (N + 2) / 2;
	int sizeQuad = size / 4;
	qt.w = alocar1DDouble(size);
	qt.eta = alocar1DDouble(size);
	qt.mi = alocar1DDouble(size);

	double *MIBase = GetMiBase(N);
	double *WBase = GetWBase(N);
	int *Mapping = GetMappingBase(N, sizeQuad);
	int Lin = N/2, Col = 1, n = 0;
	for(int l = 0; l < Lin; l++)
	{
		for(int c = 0; c < Col; c++)
		{
			//Q1 =========================
			qt.w[n] = WBase[Mapping[n]];
			qt.mi[n] = MIBase[c];
			qt.eta[n] = MIBase[Lin - l - 1];

			//Q2 =========================
			qt.w[n + sizeQuad] = WBase[Mapping[n]];
			qt.mi[n + sizeQuad] = -MIBase[c];
			qt.eta[n + sizeQuad] = MIBase[Lin - l - 1];

			//Q3 =========================
			qt.w[n + 2 * sizeQuad] = WBase[Mapping[n]];
			qt.mi[n + 2 * sizeQuad] = -MIBase[c];
			qt.eta[n + 2 * sizeQuad] = -MIBase[Lin - l - 1];

			//Q4 =========================
			qt.w[n + 3 * sizeQuad] = WBase[Mapping[n]];
			qt.mi[n + 3 * sizeQuad] = MIBase[c];
			qt.eta[n + 3 * sizeQuad] = -MIBase[Lin - l - 1];
			n++;
		}
		Col++;
	}
	//desalocar1DDouble(MIBase);
	//desalocar1DDouble(WBase);
	//desalocar1DInteger(Mapping);
/*
	for (int n = 0; n < size; n++) {
        //printf("ETA[%i] = %f - MI[%i] = %f - W[%i] = %f \n", n, qt.eta[n], n, qt.mi[n], n, qt.w[n]);
		if (n == sizeQuad - 1 || n == 2 * sizeQuad - 1
				|| n == 3 * sizeQuad - 1) {
            //printf("\n");
		}
	}
*/
	//=============================================
}

//BASE VECTOR'S ===============================
int* GetMappingBase(int N, int sizeQ) {
	int *map = alocar1DInteger(sizeQ);

	switch (N) {
	case 2:
		map[0] = 0;
		break;
	case 4:
		/*
			0
			0 0
		 */
		map[0] = 0;
		map[1] = 0;
		map[2] = 0;
		break;
	case 6:
		/*
			0
			1 1
			0 1 0
		 */
		map[0] = 0;

		map[1] = 1;
		map[2] = 1;

		map[3] = 0;
		map[4] = 1;
		map[5] = 0;
		break;
	case 8:
		/*
		    0
			1 1
			1 2 1
			0 1 1 0
		 */
		map[0] = 0;

		map[1] = 1;
		map[2] = 1;

		map[3] = 1;
		map[4] = 2;
		map[5] = 1;

		map[6] = 0;
		map[7] = 1;
		map[8] = 1;
		map[9] = 0;
		break;
	case 12:
		/*
			0
			1 1
			2 3 2
			2 4 4 2
			1 3 4 3 1
			0 1 2 2 1 0
		 */
		map[0] = 0;

		map[1] = 1;
		map[2] = 1;

		map[3] = 3;
		map[4] = 2;
		map[5] = 3;

		map[6] = 2;
		map[7] = 4;
		map[8] = 4;
		map[9] = 2;

		map[10] = 1;
		map[11] = 3;
		map[12] = 4;
		map[13] = 3;
		map[14] = 1;

		map[15] = 0;
		map[16] = 1;
		map[17] = 2;
		map[18] = 2;
		map[19] = 1;
		map[20] = 0;
	}

	return map;
}
//=============================================
double* GetMiBase(int N) {
	//DECLARA O PONTEIRO PARA O MI =================================
	double *Mi;
	//==============================================================

	//ALOCANDO E PREENCHENDO OS VETORES ============================
	switch (N) {
	case 2:
		Mi = alocar1DDouble(1);
		Mi[0] = 0.5773502692;
		break;
	case 4:
		Mi = alocar1DDouble(2);
		Mi[0] = 0.3500212;
		Mi[1] = 0.8688903;
		break;
	case 6:
		Mi = alocar1DDouble(3);
		Mi[0] = 0.2666355;
		Mi[1] = 0.6815076;
		Mi[2] = 0.9261808;
		break;
	case 8:
		Mi = alocar1DDouble(4);
		Mi[0] = 0.2182179;
		Mi[1] = 0.5773503;
		Mi[2] = 0.7867958;
		Mi[3] = 0.9511897;
		break;
	case 12:
		Mi = alocar1DDouble(6);
		Mi[0] = 0.1672126;
		Mi[1] = 0.4595476;
		Mi[2] = 0.6280191;
		Mi[3] = 0.7600210;
		Mi[4] = 0.8722706;
		Mi[5] = 0.9716377;
		break;
	}
	//==============================================================

	return Mi;
}
//=============================================

//FULL VECTOR'S ===============================
double* GetMiFullVector(int N) {
	//TAMANHO DO VETOR COMPLETO [4 QUADRANTES]
	int size = N * (N + 2) / 2;
	//TAMANHO DO QUADRANTE
	int sizeQuad = size / 4;
	//TAMANHO DA PRIMEIRA COLUNA
	int colSize = N / 2;
	//TEMPORÃ�RIOS
	int ver = 0;

	//PADRÃƒO DE MI'S
	double *MIBase = GetMiBase(N);
	double *MI = alocar1DDouble(size);

	for (int n = 0; n < sizeQuad; n++) {
		if (ver == colSize) {
			colSize--;
			ver = 0;
		}
		//=============================
		MI[n] = MIBase[ver]; //  mi[0] = MI[0]
		//=============================
		MI[n + sizeQuad] = -MI[n];
		MI[n + 2 * sizeQuad] = -MI[n];
		MI[n + 3 * sizeQuad] = MI[n];
		//=============================
		ver++;
	}

	desalocar1DDouble(MIBase);

	return MI;
}
//=============================================
double* GetEtaFullVector(int N) {
	//TAMANHO DO VETOR COMPLETO [4 QUADRANTES]
	int size = N * (N + 2) / 2;
	//MI BASE
	double *MI = GetMiBase(N);
	double *ETA = alocar1DDouble(size);

	//TAMANHO DO QUADRANTE
	int sizeQuad = size / 4;
	//TAMANHO DA PRIMEIRA COLUNA
	int colSize = N / 2;

	//TEMPORÃ�RIOS
	int ver = 0;
	int x = 0;

	//INTERANDO E ARMAZENANDO OS ETA'S DE ACORDO COM O MAPEAMENTO DE MI'S
	for (int n = 0; n < sizeQuad; n++) {
		if (ver >= colSize) {
			x++;
			colSize--;
			ver = 0;
		}
		//=============================
		ETA[n] = MI[x];
		//=============================
		ETA[n + sizeQuad] = ETA[n];
		ETA[n + 2 * sizeQuad] = -ETA[n];
		ETA[n + 3 * sizeQuad] = -ETA[n];
		//=============================
		ver++;
	}

	desalocar1DDouble(MI);

	return ETA;
}
//=============================================
double* GetWFullVector(int N) {
	//TAMANHO DO VETOR
	int size = N * (N + 2) / 2;
	//TAMANHO DO QUADRANTE
	int sizeQuad = size / 4;

	//DECLARA OS PONTEIRO
	int *Mapping = GetMappingBase(N, sizeQuad);
	//double *W = alocar1DDouble(size);
	double *WBase;

	//ALOCANDO E PREENCHENDO OS VETORES DE PESO BASE
	switch (N) {
	case 2:
		WBase = alocar1DDouble(1);
		WBase[0] = 1;
		break;
	case 4:
		WBase = alocar1DDouble(1);
		WBase[0] = 0.3333333;
		break;
	case 6:
		WBase = alocar1DDouble(2);
		WBase[0] = 0.1761263;
		WBase[1] = 0.1572071;
		break;
	case 8:
		WBase = alocar1DDouble(3);
		WBase[0] = 0.1209877;
		WBase[1] = 0.0907407;
		WBase[2] = 0.0925926;
		break;
	case 12:
		WBase = alocar1DDouble(5);
		WBase[0] = 0.0707626;
		WBase[1] = 0.0558110;
		WBase[2] = 0.0373377;
		WBase[3] = 0.0502819;
		WBase[4] = 0.0258513;
		break;
	}
	/*
	//INTERANDO E ARMAZENANDO OS PESOS DE ACORDO COM O MAPEAMENTO ***** ERRADO!!!!! <<<<<<<
	for (int n = 0; n < sizeQuad; n++) {
		W[n] = WBase[Mapping[n]];
		//=============================
		W[n + sizeQuad] = W[n];
		W[n + 2 * sizeQuad] = W[n];
		W[n + 3 * sizeQuad] = W[n];
		//=============================
	}

	//DESALOCAÃ‡ÃƒO
	desalocar1DDouble(WBase);
	 */
	desalocar1DInteger(Mapping);

	return WBase;
}
//=============================================
double* GetWBase(int N) {
	//TAMANHO DO VETOR
	int size = N * (N + 2) / 2;
	//TAMANHO DO QUADRANTE
	int sizeQuad = size / 4;

	//DECLARA OS PONTEIRO
	int *Mapping = GetMappingBase(N, sizeQuad);
	//double *W = alocar1DDouble(size);
	double *WBase;

	//ALOCANDO E PREENCHENDO OS VETORES DE PESO BASE
	switch (N) {
	case 2:
		WBase = alocar1DDouble(1);
		WBase[0] = 1;
		break;
	case 4:
		WBase = alocar1DDouble(1);
		WBase[0] = 0.3333333;
		break;
	case 6:
		WBase = alocar1DDouble(2);
		WBase[0] = 0.1761263;
		WBase[1] = 0.1572071;
		break;
	case 8:
		WBase = alocar1DDouble(3);
		WBase[0] = 0.1209877;
		WBase[1] = 0.0907407;
		WBase[2] = 0.0925926;
		break;
	case 12:
		WBase = alocar1DDouble(5);
		WBase[0] = 0.0707626;
		WBase[1] = 0.0558110;
		WBase[2] = 0.0373377;
		WBase[3] = 0.0502819;
		WBase[4] = 0.0258513;
		break;
	}
	desalocar1DInteger(Mapping);

	return WBase;
}
//=============================================
double modulo(double modulo){
	if(modulo < 0){
		return -modulo;
	}

	return modulo;
}

DadosSaida  GETDD2Dserial(DadosEntrada dado){
    DadosSaida saida;
    /*
        double tempoFisao = 0;
        double tempoEspalhamento = 0;
        double tempoF;
        double tempoVarredura = 0;
        double tempoTotal;
     */


    //============================================================================
    FillingTheQuadratureStruct(dado.ordQuad);
    //============================================================================

    //printf("\nINICIO\n");
    double start = omp_get_wtime();
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

    //INFORMAï¿½ï¿½ES ï¿½TEIS ==========================================================
    //   I |-> Dados de X
    //   J |-> Dados de Y
    //============================================================================

    //Dï¿½VIDAS ====================================================================
    //PERGUNTAR SOBRE A ORDEM DAS VARREDURAS COM RELAï¿½ï¿½O AOS QUADRANTES
    //============================================================================

    //CALCULO DAS CONDIï¿½ï¿½ES DE CONTORNO ========================================
    /*
     * (i+1,j) = 2  _______  (i+1,j+1) = 1
     *         |       |
     *     fiT |       |
     *         |_______|
     *    (ij) = 3   fiC       (i,j+1) = 4
     * */

    //VARIAVEIS A SER SUBSTITUIDAS OTIMIZAï¿½ï¿½O ====================
    int j1 = J + 1;
    int i1 = I + 1;
    int JMI1 = J * (I + 1) * M;
    int IMJ1 = I * (J + 1) * M;
    int JI1 = J * (I + 1);
    int IJ1 = I * (J + 1);
    int M4 = M / 4;
    int M2 = M / 2;

    //condiï¿½oes de contorno
    //ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,int j1,double *esquerda,double *direita,double *cima,double *baixo)
    //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

    /*psiT[0] = dado.cce[0];
         psiT[I] = dado.ccd[0];
         psiC[0] = dado.ccb[0];
         psiC[J] = dado.ccc[0];*/
    //============================================================================
    int a = 0;

    // as fonte de fiï¿½ao e espalhamento estao sendo iniciadas antes de entrar nos do para serem atualizadas ao final do mesmo
    // INICIALIZAï¿½AO DA FONTE DE FIï¿½ï¿½O============================================
    double somSFK = 0.0;
    double somSFKold = 0.0;
    double KeffOLD;
    //fonte fissï¿½o esta sem o keff sendo igual ao S
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
                fonteFis[a] *= 0.125; //correï¿½ï¿½o do psi barra aqui
             */
            somSFK += hx[mapX[i]] * hy[mapY[j]] * fonteFis[a];
            a++;
        }
    }
    //printf("\n valor de somSFK:%f", somSFK);
    //}
    //============================================================================
    // INICIALIZAï¿½AO DA FONTE DE ESPALHAMENTO===================================== !!!!!!REVER Cï¿½LCULO DO FLUXO ESCALAR JUNDO A FONTE DE ESPALHAMENTO, ATENTAR PARA O G!!!!
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
                            * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posiï¿½ao do Glin se e antes ou depois do G
                    int idfi = gLin * J * I + j * I + i;
                    fiT[idfi] = tmp * 0.5;
                }
                fonteEspalhamento[fE] *= 0.125; //correï¿½ao do psiBarra para evitar multiplicaï¿½oes
                //printf("\n fonteEspalhamento[%i]: %f",fE,fonteEspalhamento[fE]);
                fE++;

            }
        }
    }
    int contKeff = 0;
    //============================================================================

    double tempoVarerredura = 0;
    saida.interacoes = 0;
    do {
        contKeff++;
        int contFluxo = 0;
        saida.interacoes++;
        do {
            saida.interacoes++;
            contFluxo++;
            //NO FOR DE g CONTEM TODA AS VARREDURAS NOS N SENTIDOS CONTENDO A VARREDURA EM SI
            for (int g = 0; g < G; g++) {
                double tmpTime = omp_get_wtime();
                // VARREDURA 31 SO --> NE ===========================================================
                for (int m = 0; m < M4; m++) {
                    for (int j = 0; j < J; j++) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = 0; i < I; i++) {
                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i; //bloco + camada + linha + coluna
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin ];
                            double divisor = qt.mi[m] / hx[i] + qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //ATENTAR-SE NO FUTURO A EFICIï¿½NCIA DA VERSï¿½O SEM OS IF'S
                            //EQUAï¿½ï¿½O 26 |SO - NE| =======================================

                            ps.psiT[idI + 1] = ((qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI]
                                                                                                                            + 2 * qt.eta[m] * ps.psiC[idJ] / hy[j]
                                                                                                                                                                + fonteEspalhamento[fe + i]
                                                                                                                                                                                    + fonteFis[j * I + i] / keff) / divisor;

                            //EQUAï¿½ï¿½O 27 |SO - NE| ========================================

                            ps.psiC[idJ + 1] = ((-qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ]
                                                                                                                             + 2 * qt.mi[m] * ps.psiT[idI] / hx[i]
                                                                                                                                                                + fonteEspalhamento[fe + i]
                                                                                                                                                                                    + fonteFis[j * I + i] / keff) / divisor;
                            //==================Condiï¿½ï¿½o de contorno a Acima===============
                            if ((dado.ccc[g] < 0) && (j = J-1)) {
                                int idq1 = g * IMJ1 + (m         ) * IJ1 + i * j1 + J;
                                int idq4 = g * IMJ1 + (m + 3 * M4) * IJ1 + i * j1 + J;
                                ps.psiC[idq4] = ps.psiC[idq1];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Direita=================
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
                // VARREDURA 42 SE --> NO ===========================================================
                for (int m = M4; m < M2; m++) {
                    for (int j = 0; j < J; j++) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = I-1; i >= 0; i--) {

                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i;
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin];
                            double divisor = -qt.mi[m] / hx[i] + qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //EQUAï¿½ï¿½O 28 |SE - NO| =======================================

                            ps.psiT[idI] = ((-qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI + 1]
                                                                                                                         + 2 * qt.eta[m] * ps.psiC[idJ] / hy[j]
                                                                                                                                                             + fonteEspalhamento[fe + i]
                                                                                                                                                                                 + fonteFis[j * I + i] / keff) / divisor;

                            //EQUAï¿½ï¿½O 29 |SE - NO| ========================================

                            ps.psiC[idJ + 1] = ((qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ])	* ps.psiC[idJ]
                                                                                                                              - 2 * qt.mi[m] * ps.psiT[idI + 1] / hx[i]
                                                                                                                                                                     + fonteEspalhamento[fe + i]
                                                                                                                                                                                         + fonteFis[j * I + i] / keff) / (divisor);
                            //printf("(%i - %.0f, %i - %.0f)\t", i, hx[i], j, hy[j]);
                            //printf("(%i, %i) %d\t", j, i, fe + i);
                            //printf("(%i, %i) %e\t", i, j, ps.psiT[idI + 1]);
                            //test += ps.psiT[idI];
                            //==============================================================

                            //==================Condiï¿½ï¿½o de contorno a Acima==============
                            if ((dado.ccc[g] < 0) && (j = J-1)) {
                                int idq2 = g * IMJ1 + (m     ) * IJ1 + i * j1 + J;
                                int idq3 = g * IMJ1 + (m + M4) * IJ1 + i * j1 + J;
                                ps.psiC[idq3] = ps.psiC[idq2];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Esquerda=================
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
                // VARREDURA 13 NE --> SO ===========================================================
                for (int m = M2; m < 3 * M4; m++) {
                    for (int j = J-1; j >= 0; j--) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = I-1; i >= 0; i--) {
                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i;
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin];
                            double divisor = -qt.mi[m] / hx[i] - qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //EQUAï¿½ï¿½O 26 |NE - SO| =======================================

                            ps.psiT[idI] = ((-qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI + 1]
                                                                                                                         - 2 * qt.eta[m] * ps.psiC[idJ + 1] / hy[j]
                                                                                                                                                                 + fonteEspalhamento[fe + i]
                                                                                                                                                                                     + fonteFis[j * I + i] / keff) / (divisor);

                            //EQUAï¿½ï¿½O 27 |NE - SO| ========================================

                            ps.psiC[idJ] = ((qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ + 1]
                                                                                                                        - 2 * qt.mi[m] * ps.psiT[idI + 1] / hx[i]
                                                                                                                                                               + fonteEspalhamento[fe + i]
                                                                                                                                                                                   + fonteFis[j * I + i] / keff) / (divisor);
                            //==============================================================
                            //printf("%i (%i, %i) %e\t",J, i, j, ps.psiT[idI + 1]);
                            //==================Condiï¿½ï¿½o de contorno a Abaixo==============
                            if ((dado.ccb[g] < 0) && (j == 0)) {
                                int idq2 = g * IMJ1 + (m - M4) * IJ1 + i * j1;
                                int idq3 = g * IMJ1 + (m     ) * IJ1 + i * j1;
                                ps.psiC[idq2] = ps.psiC[idq3];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Esquerda=================
                        if (dado.cce[g] < 0) {
                            int idq3 = g * JMI1 + (m     ) * JI1 + j * i1;
                            int idq4 = g * JMI1 + (m + M4) * JI1 + j * i1;
                            ps.psiT[idq4] = ps.psiT[idq3];
                        }
                        //==================================================================
                    }
                }
                //printf("VARREDURA 13: %f\n", stmp);
                //ATUALIZAR AS CONDICOES DE CONTORNO=======================================
                //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

                // VARREDURA 24 NO --> SE ===========================================================
                for (int m = 3 * M4; m < M; m++) {
                    for (int j = J-1; j >= 0; j--) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = 0; i < I; i++) {

                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i;
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin];
                            double divisor = qt.mi[m] / hx[i] - qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //EQUAï¿½ï¿½O 28 |NO - SE| =======================================

                            ps.psiT[idI + 1] = ((qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI]
                                                                                                                            - 2 * qt.eta[m] * ps.psiC[idJ + 1] / hy[j]
                                                                                                                                                                    + fonteEspalhamento[fe + i]
                                                                                                                                                                                        + fonteFis[j * I + i] / keff) / (divisor);

                            //EQUAï¿½ï¿½O 29 |NO - SE| ========================================

                            ps.psiC[idJ] = ((-qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ + 1]
                                                                                                                         + 2 * qt.mi[m] * ps.psiT[idI] /  hx[i]
                                                                                                                                                             + fonteEspalhamento[fe + i]
                                                                                                                                                                                 + fonteFis[j * I + i] / keff) / (divisor);
                            //stmp += ps.psiT[idI + 1];
                            //==================Condiï¿½ï¿½o de contorno a Abaixo==============
                            if ((dado.ccb[g] < 0) && (j == 0)) {
                                int idq1 = g * IMJ1 + (m - 3 * M4) * IJ1 + i * j1;
                                int idq4 = g * IMJ1 + (m         ) * IJ1 + i * j1;
                                ps.psiC[idq1] = ps.psiC[idq4];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Direita=================
                        if (dado.ccd[g] < 0) {
                            int idq1 = g * JMI1 + (m - 3 * M4) * JI1 + j * i1 + I;
                            int idq4 = g * JMI1 + (m         ) * JI1 + j * i1 + I;
                            ps.psiT[idq1] = ps.psiT[idq4];
                        }
                        //==================================================================
                    }
                }
                tempoVarerredura += omp_get_wtime() - tmpTime;
                //ATUALIZAR AS CONDICOES DE CONTORNO=======================================
                //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

                //printf("VARREDURA 24: %f\n", stmp);

                // =======================================================================
            }
            //============================================================================
            //Cï¿½LCULO DO ERRO  agora feito junto ao ATUALIZADOR da fonte de espalhamento============================================================
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
                            fonteEspalhamento[fE] += tmp * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posiï¿½ao do Glin se e antes ou depois do G
                            int idfi = gLin * J * I + j * I + i;

                            double fitOld = fiT[idfi]; //fiT ï¿½ fluxo escalar calculado usando o fluxo angular psiT.

                            fiT[idfi] = tmp * 0.25;
                            //printf(" \n erro do fluxo absoluto = %f", fiT[idfi] - fitOld);
                            double tmperro = modulo(
                                    (fiT[idfi] - fitOld) / fiT[idfi]);

                            if (errofi < tmperro)
                                errofi = tmperro;
                            //printf("%e\n",errofi);
                        }
                        fonteEspalhamento[fE] *= 0.125; //correï¿½ao do psiBarra para evitar multiplicaï¿½oes
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

        //ATUALIZA A FONTE DE FIï¿½AO PARA RETORNAR AO DO DA VARREDURA==================
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
                    fonteFis[fF] += dado.sigfic[idZ * G + gLin] * tmp;// <==========Indice do sigfic atualizado 25/11/2020

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

    saida.keff = keff;

    //printf("\nkeff = %e", keff);
    /*
     * Cï¿½lculo da potï¿½ncia do reator
     */
    int Lin = dado.numRegY, Col = dado.numRegX;
    double * Pot = alocar1DDouble(G * Lin * Col);
    double * tmpReg = alocar1DDouble(G * Lin * Col);
    double * potFalse = alocar1DDouble(G);
    //printf("\n\n\n");
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

    saida.Potencia = DoubVet2D(Lin, Col);
    saida.Lin = Lin;
    saida.Col = Col;
    for (int g = 0; g < G; g++) {
        for (int l = Lin - 1; l >= 0; l--) {
            for (int c = 0; c < Col; c++) {
                int idZ = dado.mapZona[l * Col + c];
                double HX = dado.tamRegX[c] / dado.parRegX[c], HY = dado.tamRegY[l] / dado.parRegY[l];
                Pot[g * Lin * Col + l * Col + c] = 3.2 * 1E-5 * 0.125 * HX * HY * dado.sigfic[idZ] * tmpReg[l * Col + c] * dado.pot / potFalse[g];
                //printf("%e\t",Pot[g * Lin * Col + l * Col + c]);
                saida.Potencia[l][c] = Pot[g * Lin * Col + l * Col + c];
            }
            //printf("\n");
        }
    }
    double tempoTotal = omp_get_wtime() - start;
    saida.TempoTotal = tempoTotal;
    saida.TempoVarredura = tempoVarerredura;
    /*===============================================================================*/
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoTotal);
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoVarerredura);
    /*===============================================================================*/
    /*
    //printf("\nFIM\n");
    char * txtKeff;
    txtKeff = malloc(sizeof(double));
    sn//printf(txtKeff, 50, "%f", keff);
    */
    return saida;
}

DadosSaida  GETDD2DparaleloDirecoes(DadosEntrada dado){
    DadosSaida saida;
    /*
        double tempoFisao = 0;
        double tempoEspalhamento = 0;
        double tempoF;
        double tempoVarredura = 0;
        double tempoTotal;
     */


    //============================================================================
    FillingTheQuadratureStruct(dado.ordQuad);
    //============================================================================

    //printf("\nINICIO\n");
    double start = omp_get_wtime();
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

    //INFORMAï¿½ï¿½ES ï¿½TEIS ==========================================================
    //   I |-> Dados de X
    //   J |-> Dados de Y
    //============================================================================

    //Dï¿½VIDAS ====================================================================
    //PERGUNTAR SOBRE A ORDEM DAS VARREDURAS COM RELAï¿½ï¿½O AOS QUADRANTES
    //============================================================================

    //CALCULO DAS CONDIï¿½ï¿½ES DE CONTORNO ========================================
    /*
     * (i+1,j) = 2  _______  (i+1,j+1) = 1
     *         |       |
     *     fiT |       |
     *         |_______|
     *    (ij) = 3   fiC       (i,j+1) = 4
     * */

    //VARIAVEIS A SER SUBSTITUIDAS OTIMIZAï¿½ï¿½O ====================
    int j1 = J + 1;
    int i1 = I + 1;
    int JMI1 = J * (I + 1) * M;
    int IMJ1 = I * (J + 1) * M;
    int JI1 = J * (I + 1);
    int IJ1 = I * (J + 1);
    int M4 = M / 4;
    int M2 = M / 2;

    //condiï¿½oes de contorno
    //ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,int j1,double *esquerda,double *direita,double *cima,double *baixo)
    //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

    /*psiT[0] = dado.cce[0];
         psiT[I] = dado.ccd[0];
         psiC[0] = dado.ccb[0];
         psiC[J] = dado.ccc[0];*/
    //============================================================================
    int a = 0;

    // as fonte de fiï¿½ao e espalhamento estao sendo iniciadas antes de entrar nos do para serem atualizadas ao final do mesmo
    // INICIALIZAï¿½AO DA FONTE DE FIï¿½ï¿½O============================================
    double somSFK = 0.0;
    double somSFKold = 0.0;
    double KeffOLD;
    //fonte fissï¿½o esta sem o keff sendo igual ao S
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
                fonteFis[a] *= 0.125; //correï¿½ï¿½o do psi barra aqui
             */
            somSFK += hx[mapX[i]] * hy[mapY[j]] * fonteFis[a];
            a++;
        }
    }
    //printf("\n valor de somSFK:%f", somSFK);
    //}
    //============================================================================
    // INICIALIZAï¿½AO DA FONTE DE ESPALHAMENTO===================================== !!!!!!REVER Cï¿½LCULO DO FLUXO ESCALAR JUNDO A FONTE DE ESPALHAMENTO, ATENTAR PARA O G!!!!
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
                            * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posiï¿½ao do Glin se e antes ou depois do G
                    int idfi = gLin * J * I + j * I + i;
                    fiT[idfi] = tmp * 0.5;
                }
                fonteEspalhamento[fE] *= 0.125; //correï¿½ao do psiBarra para evitar multiplicaï¿½oes
                //printf("\n fonteEspalhamento[%i]: %f",fE,fonteEspalhamento[fE]);
                fE++;

            }
        }
    }
    int contKeff = 0;
    //============================================================================

    double tempoVarerredura = 0;
    saida.interacoes = 0;
    do {
        saida.interacoes++;
        contKeff++;
        int contFluxo = 0;
        do {
            saida.interacoes++;
            contFluxo++;
            //NO FOR DE g CONTEM TODA AS VARREDURAS NOS N SENTIDOS CONTENDO A VARREDURA EM SI
            for (int g = 0; g < G; g++) {
                double tmpTime = omp_get_wtime();
                // VARREDURA 31 SO --> NE ===========================================================
                #pragma omp parallel for
                for (int m = 0; m < M4; m++) {
                    for (int j = 0; j < J; j++) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = 0; i < I; i++) {
                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i; //bloco + camada + linha + coluna
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin ];
                            double divisor = qt.mi[m] / hx[i] + qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //ATENTAR-SE NO FUTURO A EFICIï¿½NCIA DA VERSï¿½O SEM OS IF'S
                            //EQUAï¿½ï¿½O 26 |SO - NE| =======================================

                            ps.psiT[idI + 1] = ((qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI]
                                                                                                                            + 2 * qt.eta[m] * ps.psiC[idJ] / hy[j]
                                                                                                                                                                + fonteEspalhamento[fe + i]
                                                                                                                                                                                    + fonteFis[j * I + i] / keff) / divisor;

                            //EQUAï¿½ï¿½O 27 |SO - NE| ========================================

                            ps.psiC[idJ + 1] = ((-qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ]
                                                                                                                             + 2 * qt.mi[m] * ps.psiT[idI] / hx[i]
                                                                                                                                                                + fonteEspalhamento[fe + i]
                                                                                                                                                                                    + fonteFis[j * I + i] / keff) / divisor;
                            //==================Condiï¿½ï¿½o de contorno a Acima===============
                            if ((dado.ccc[g] < 0) && (j = J-1)) {
                                int idq1 = g * IMJ1 + (m         ) * IJ1 + i * j1 + J;
                                int idq4 = g * IMJ1 + (m + 3 * M4) * IJ1 + i * j1 + J;
                                ps.psiC[idq4] = ps.psiC[idq1];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Direita=================
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
                // VARREDURA 42 SE --> NO ===========================================================
                #pragma omp parallel for
                for (int m = M4; m < M2; m++) {
                    for (int j = 0; j < J; j++) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = I-1; i >= 0; i--) {

                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i;
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin];
                            double divisor = -qt.mi[m] / hx[i] + qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //EQUAï¿½ï¿½O 28 |SE - NO| =======================================

                            ps.psiT[idI] = ((-qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI + 1]
                                                                                                                         + 2 * qt.eta[m] * ps.psiC[idJ] / hy[j]
                                                                                                                                                             + fonteEspalhamento[fe + i]
                                                                                                                                                                                 + fonteFis[j * I + i] / keff) / divisor;

                            //EQUAï¿½ï¿½O 29 |SE - NO| ========================================

                            ps.psiC[idJ + 1] = ((qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ])	* ps.psiC[idJ]
                                                                                                                              - 2 * qt.mi[m] * ps.psiT[idI + 1] / hx[i]
                                                                                                                                                                     + fonteEspalhamento[fe + i]
                                                                                                                                                                                         + fonteFis[j * I + i] / keff) / (divisor);
                            //printf("(%i - %.0f, %i - %.0f)\t", i, hx[i], j, hy[j]);
                            //printf("(%i, %i) %d\t", j, i, fe + i);
                            //printf("(%i, %i) %e\t", i, j, ps.psiT[idI + 1]);
                            //test += ps.psiT[idI];
                            //==============================================================

                            //==================Condiï¿½ï¿½o de contorno a Acima==============
                            if ((dado.ccc[g] < 0) && (j = J-1)) {
                                int idq2 = g * IMJ1 + (m     ) * IJ1 + i * j1 + J;
                                int idq3 = g * IMJ1 + (m + M4) * IJ1 + i * j1 + J;
                                ps.psiC[idq3] = ps.psiC[idq2];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Esquerda=================
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
                // VARREDURA 13 NE --> SO ===========================================================
                #pragma omp parallel for
                for (int m = M2; m < 3 * M4; m++) {
                    for (int j = J-1; j >= 0; j--) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = I-1; i >= 0; i--) {
                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i;
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin];
                            double divisor = -qt.mi[m] / hx[i] - qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //EQUAï¿½ï¿½O 26 |NE - SO| =======================================

                            ps.psiT[idI] = ((-qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI + 1]
                                                                                                                         - 2 * qt.eta[m] * ps.psiC[idJ + 1] / hy[j]
                                                                                                                                                                 + fonteEspalhamento[fe + i]
                                                                                                                                                                                     + fonteFis[j * I + i] / keff) / (divisor);

                            //EQUAï¿½ï¿½O 27 |NE - SO| ========================================

                            ps.psiC[idJ] = ((qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ + 1]
                                                                                                                        - 2 * qt.mi[m] * ps.psiT[idI + 1] / hx[i]
                                                                                                                                                               + fonteEspalhamento[fe + i]
                                                                                                                                                                                   + fonteFis[j * I + i] / keff) / (divisor);
                            //==============================================================
                            //printf("%i (%i, %i) %e\t",J, i, j, ps.psiT[idI + 1]);
                            //==================Condiï¿½ï¿½o de contorno a Abaixo==============
                            if ((dado.ccb[g] < 0) && (j == 0)) {
                                int idq2 = g * IMJ1 + (m - M4) * IJ1 + i * j1;
                                int idq3 = g * IMJ1 + (m     ) * IJ1 + i * j1;
                                ps.psiC[idq2] = ps.psiC[idq3];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Esquerda=================
                        if (dado.cce[g] < 0) {
                            int idq3 = g * JMI1 + (m     ) * JI1 + j * i1;
                            int idq4 = g * JMI1 + (m + M4) * JI1 + j * i1;
                            ps.psiT[idq4] = ps.psiT[idq3];
                        }
                        //==================================================================
                    }
                }
                //printf("VARREDURA 13: %f\n", stmp);
                //ATUALIZAR AS CONDICOES DE CONTORNO=======================================
                //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

                // VARREDURA 24 NO --> SE ===========================================================
                #pragma omp parallel for
                for (int m = 3 * M4; m < M; m++) {
                    for (int j = J-1; j >= 0; j--) {
                        int jlin = mapY[j] * dado.numRegX;
                        int fe = g * J * I + j * I;
                        for (int i = 0; i < I; i++) {

                            //VARIAVEIS DE IDENTIFICAï¿½ï¿½O =================================
                            int idI = g * JMI1 + m * JI1 + j * i1 + i;
                            int idJ = g * IMJ1 + m * IJ1 + i * j1 + j;
                            int idZ = dado.mapZona[mapX[i] + jlin];
                            double divisor = qt.mi[m] / hx[i] - qt.eta[m] / hy[j] + 0.5 * dado.sigTotal[idZ];
                            //============================================================
                            //EQUAï¿½ï¿½O 28 |NO - SE| =======================================

                            ps.psiT[idI + 1] = ((qt.mi[m] / hx[i] + qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiT[idI]
                                                                                                                            - 2 * qt.eta[m] * ps.psiC[idJ + 1] / hy[j]
                                                                                                                                                                    + fonteEspalhamento[fe + i]
                                                                                                                                                                                        + fonteFis[j * I + i] / keff) / (divisor);

                            //EQUAï¿½ï¿½O 29 |NO - SE| ========================================

                            ps.psiC[idJ] = ((-qt.mi[m] / hx[i] - qt.eta[m] / hy[j] - 0.5 * dado.sigTotal[idZ]) * ps.psiC[idJ + 1]
                                                                                                                         + 2 * qt.mi[m] * ps.psiT[idI] /  hx[i]
                                                                                                                                                             + fonteEspalhamento[fe + i]
                                                                                                                                                                                 + fonteFis[j * I + i] / keff) / (divisor);
                            //stmp += ps.psiT[idI + 1];
                            //==================Condiï¿½ï¿½o de contorno a Abaixo==============
                            if ((dado.ccb[g] < 0) && (j == 0)) {
                                int idq1 = g * IMJ1 + (m - 3 * M4) * IJ1 + i * j1;
                                int idq4 = g * IMJ1 + (m         ) * IJ1 + i * j1;
                                ps.psiC[idq1] = ps.psiC[idq4];
                            }
                            //==============================================================
                        }
                        //==================Condiï¿½ï¿½o de contorno a Direita=================
                        if (dado.ccd[g] < 0) {
                            int idq1 = g * JMI1 + (m - 3 * M4) * JI1 + j * i1 + I;
                            int idq4 = g * JMI1 + (m         ) * JI1 + j * i1 + I;
                            ps.psiT[idq1] = ps.psiT[idq4];
                        }
                        //==================================================================
                    }
                }
                tempoVarerredura += omp_get_wtime() - tmpTime;
                //ATUALIZAR AS CONDICOES DE CONTORNO=======================================
                //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

                //printf("VARREDURA 24: %f\n", stmp);

                // =======================================================================
            }
            //============================================================================
            //Cï¿½LCULO DO ERRO  agora feito junto ao ATUALIZADOR da fonte de espalhamento============================================================
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
                            fonteEspalhamento[fE] += tmp * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posiï¿½ao do Glin se e antes ou depois do G
                            int idfi = gLin * J * I + j * I + i;

                            double fitOld = fiT[idfi]; //fiT ï¿½ fluxo escalar calculado usando o fluxo angular psiT.

                            fiT[idfi] = tmp * 0.25;
                            //printf(" \n erro do fluxo absoluto = %f", fiT[idfi] - fitOld);
                            double tmperro = modulo(
                                    (fiT[idfi] - fitOld) / fiT[idfi]);

                            if (errofi < tmperro)
                                errofi = tmperro;
                            //printf("%e\n",errofi);
                        }
                        fonteEspalhamento[fE] *= 0.125; //correï¿½ao do psiBarra para evitar multiplicaï¿½oes
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

        //ATUALIZA A FONTE DE FIï¿½AO PARA RETORNAR AO DO DA VARREDURA==================
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
                    fonteFis[fF] += dado.sigfic[idZ * G + gLin] * tmp;// <==========Indice do sigfic atualizado 25/11/2020

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

    saida.keff = keff;

    //printf("\nkeff = %e", keff);
    /*
     * Cï¿½lculo da potï¿½ncia do reator
     */
    int Lin = dado.numRegY, Col = dado.numRegX;
    double * Pot = alocar1DDouble(G * Lin * Col);
    double * tmpReg = alocar1DDouble(G * Lin * Col);
    double * potFalse = alocar1DDouble(G);
    //printf("\n\n\n");
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

    saida.Potencia = DoubVet2D(Lin, Col);
    saida.Lin = Lin;
    saida.Col = Col;
    for (int g = 0; g < G; g++) {
        for (int l = Lin - 1; l >= 0; l--) {
            for (int c = 0; c < Col; c++) {
                int idZ = dado.mapZona[l * Col + c];
                double HX = dado.tamRegX[c] / dado.parRegX[c], HY = dado.tamRegY[l] / dado.parRegY[l];
                Pot[g * Lin * Col + l * Col + c] = 3.2 * 1E-5 * 0.125 * HX * HY * dado.sigfic[idZ] * tmpReg[l * Col + c] * dado.pot / potFalse[g];
                //printf("%e\t",Pot[g * Lin * Col + l * Col + c]);
                saida.Potencia[l][c] = Pot[g * Lin * Col + l * Col + c];
            }
            //printf("\n");
        }
    }
    double tempoTotal = omp_get_wtime() - start;
    saida.TempoTotal = tempoTotal;
    saida.TempoVarredura = tempoVarerredura;
    /*===============================================================================*/
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoTotal);
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoVarerredura);
    /*===============================================================================*/
    /*
    //printf("\nFIM\n");
    char * txtKeff;
    txtKeff = malloc(sizeof(double));
    sn//printf(txtKeff, 50, "%f", keff);
    */
    return saida;
}


DadosSaida  GETDD2DparaleloTotal(DadosEntrada dado){
    DadosSaida saida;
    /*
        double tempoFisao = 0;
        double tempoEspalhamento = 0;
        double tempoF;
        double tempoVarredura = 0;
        double tempoTotal;
     */


    //============================================================================
    FillingTheQuadratureStruct(dado.ordQuad);
    //============================================================================

    //printf("\nINICIO\n");
    double start = omp_get_wtime();
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

    //INFORMAï¿½ï¿½ES ï¿½TEIS ==========================================================
    //   I |-> Dados de X
    //   J |-> Dados de Y
    //============================================================================

    //Dï¿½VIDAS ====================================================================
    //PERGUNTAR SOBRE A ORDEM DAS VARREDURAS COM RELAï¿½ï¿½O AOS QUADRANTES
    //============================================================================

    //CALCULO DAS CONDIï¿½ï¿½ES DE CONTORNO ========================================
    /*
     * (i+1,j) = 2  _______  (i+1,j+1) = 1
     *         |       |
     *     fiT |       |
     *         |_______|
     *    (ij) = 3   fiC       (i,j+1) = 4
     * */

    //VARIAVEIS A SER SUBSTITUIDAS OTIMIZAï¿½ï¿½O ====================
    int j1 = J + 1;
    int i1 = I + 1;
    int JMI1 = J * (I + 1) * M;
    int IMJ1 = I * (J + 1) * M;
    int JI1 = J * (I + 1);
    int IJ1 = I * (J + 1);
    int M4 = M / 4;
    int M2 = M / 2;

    //condiï¿½oes de contorno
    //ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,int j1,double *esquerda,double *direita,double *cima,double *baixo)
    //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

    /*psiT[0] = dado.cce[0];
         psiT[I] = dado.ccd[0];
         psiC[0] = dado.ccb[0];
         psiC[J] = dado.ccc[0];*/
    //============================================================================
    int a = 0;

    // as fonte de fiï¿½ao e espalhamento estao sendo iniciadas antes de entrar nos do para serem atualizadas ao final do mesmo
    // INICIALIZAï¿½AO DA FONTE DE FIï¿½ï¿½O============================================
    double somSFK = 0.0;
    double somSFKold = 0.0;
    double KeffOLD;
    //fonte fissï¿½o esta sem o keff sendo igual ao S
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
                fonteFis[a] *= 0.125; //correï¿½ï¿½o do psi barra aqui
             */
            somSFK += hx[mapX[i]] * hy[mapY[j]] * fonteFis[a];
            a++;
        }
    }
    //printf("\n valor de somSFK:%f", somSFK);
    //}
    //============================================================================
    // INICIALIZAï¿½AO DA FONTE DE ESPALHAMENTO===================================== !!!!!!REVER Cï¿½LCULO DO FLUXO ESCALAR JUNDO A FONTE DE ESPALHAMENTO, ATENTAR PARA O G!!!!
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
                            * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posiï¿½ao do Glin se e antes ou depois do G
                    int idfi = gLin * J * I + j * I + i;
                    fiT[idfi] = tmp * 0.5;
                }
                fonteEspalhamento[fE] *= 0.125; //correï¿½ao do psiBarra para evitar multiplicaï¿½oes
                //printf("\n fonteEspalhamento[%i]: %f",fE,fonteEspalhamento[fE]);
                fE++;

            }
        }
    }
    int contKeff = 0;
    //============================================================================

    double tempoVarerredura = 0;
    saida.interacoes = 0;
	do {
        saida.interacoes++;
		contKeff++;

		do {
            saida.interacoes++;
			//contFluxo++;
			//NO FOR DE g CONTEM TODA AS VARREDURAS NOS N SENTIDOS CONTENDO A VARREDURA EM SI
			//tempo = omp_get_wtime();
			for (int g = 0; g < G; g++) {
                double tmpTime = omp_get_wtime();
//#pragma omp parallel
				{
#pragma omp sections
					{
						// VARREDURA 31 SO --> NE ===========================================================
#pragma omp section
						{
#pragma omp parallel for
							for (int m = 0; m < M4; m++) {
//#pragma omp parallel for
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
						}
						//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
						//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

                        //printf("VARREDURA 31: %f\n", stmp);

						// VARREDURA 42 SE --> NO ===========================================================
#pragma omp section
						{
#pragma omp parallel for
							for (int m = M4; m < M2; m++) {
//#pragma omp parallel for
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
						}
						//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
						//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);


                        //printf("VARREDURA 42: %f\n", stmp);

						// VARREDURA 13 NE --> SO ===========================================================
#pragma omp section
						{
#pragma omp parallel for
							for (int m = M2; m < 3 * M4; m++) {
//#pragma omp parallel for
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
						}
						//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
						//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

						// VARREDURA 24 NO --> SE ===========================================================
#pragma omp section
						{
#pragma omp parallel for
							for (int m = 3 * M4; m < M; m++) {
//#pragma omp parallel for
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
						}
					}
                    //printf("VARREDURA 24: %f\n", stmp);
                   
					// =======================================================================
				}
                 tempoVarerredura += omp_get_wtime() - tmpTime;
			}
			//tempoF  = omp_get_wtime();
			//tempoVarredura +=tempoF - tempo;
			//============================================================================
			//C�LCULO DO ERRO  agora feito junto ao ATUALIZADOR da fonte de espalhamento============================================================
			fE = 0;		//variavel momentanea para controle de indice
			errofi = 0;
			//tempo = 0;
			//tempo = omp_get_wtime();
			for (int g = 0; g < dado.numGrp; g++) {
				//#pragma omp parallel for
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
			//tempoF = omp_get_wtime();
			//tempoEspalhamento += tempoF - tempo;
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
		//tempo = 0;
		//tempo = omp_get_wtime();
		//#pragma omp parallel for
		for (int j = 0; j < J; j++) {
			//#pragma omp parallel for
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
		//tempoF = omp_get_wtime();
		//tempoFisao += tempoF - tempo;
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



	} while (errokeff > dado.cp1);

    saida.keff = keff;

    //printf("\nkeff = %e", keff);
    /*
     * Cï¿½lculo da potï¿½ncia do reator
     */
    int Lin = dado.numRegY, Col = dado.numRegX;
    double * Pot = alocar1DDouble(G * Lin * Col);
    double * tmpReg = alocar1DDouble(G * Lin * Col);
    double * potFalse = alocar1DDouble(G);
    //printf("\n\n\n");
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

    saida.Potencia = DoubVet2D(Lin, Col);
    saida.Lin = Lin;
    saida.Col = Col;
    for (int g = 0; g < G; g++) {
        for (int l = Lin - 1; l >= 0; l--) {
            for (int c = 0; c < Col; c++) {
                int idZ = dado.mapZona[l * Col + c];
                double HX = dado.tamRegX[c] / dado.parRegX[c], HY = dado.tamRegY[l] / dado.parRegY[l];
                Pot[g * Lin * Col + l * Col + c] = 3.2 * 1E-5 * 0.125 * HX * HY * dado.sigfic[idZ] * tmpReg[l * Col + c] * dado.pot / potFalse[g];
                //printf("%e\t",Pot[g * Lin * Col + l * Col + c]);
                saida.Potencia[l][c] = Pot[g * Lin * Col + l * Col + c];
            }
            //printf("\n");
        }
    }
    double tempoTotal = omp_get_wtime() - start;
    saida.TempoTotal = tempoTotal;
    saida.TempoVarredura = tempoVarerredura;
    /*===============================================================================*/
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoTotal);
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoVarerredura);
    /*===============================================================================*/
    /*
    //printf("\nFIM\n");
    char * txtKeff;
    txtKeff = malloc(sizeof(double));
    sn//printf(txtKeff, 50, "%f", keff);
    */
    return saida;
}


DadosSaida  GETDD2DparaleloSessoes(DadosEntrada dado){
    DadosSaida saida;
    /*
        double tempoFisao = 0;
        double tempoEspalhamento = 0;
        double tempoF;
        double tempoVarredura = 0;
        double tempoTotal;
     */


    //============================================================================
    FillingTheQuadratureStruct(dado.ordQuad);
    //============================================================================

    //printf("\nINICIO\n");
    double start = omp_get_wtime();
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

    //INFORMAï¿½ï¿½ES ï¿½TEIS ==========================================================
    //   I |-> Dados de X
    //   J |-> Dados de Y
    //============================================================================

    //Dï¿½VIDAS ====================================================================
    //PERGUNTAR SOBRE A ORDEM DAS VARREDURAS COM RELAï¿½ï¿½O AOS QUADRANTES
    //============================================================================

    //CALCULO DAS CONDIï¿½ï¿½ES DE CONTORNO ========================================
    /*
     * (i+1,j) = 2  _______  (i+1,j+1) = 1
     *         |       |
     *     fiT |       |
     *         |_______|
     *    (ij) = 3   fiC       (i,j+1) = 4
     * */

    //VARIAVEIS A SER SUBSTITUIDAS OTIMIZAï¿½ï¿½O ====================
    int j1 = J + 1;
    int i1 = I + 1;
    int JMI1 = J * (I + 1) * M;
    int IMJ1 = I * (J + 1) * M;
    int JI1 = J * (I + 1);
    int IJ1 = I * (J + 1);
    int M4 = M / 4;
    int M2 = M / 2;

    //condiï¿½oes de contorno
    //ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,int j1,double *esquerda,double *direita,double *cima,double *baixo)
    //ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

    /*psiT[0] = dado.cce[0];
         psiT[I] = dado.ccd[0];
         psiC[0] = dado.ccb[0];
         psiC[J] = dado.ccc[0];*/
    //============================================================================
    int a = 0;

    // as fonte de fiï¿½ao e espalhamento estao sendo iniciadas antes de entrar nos do para serem atualizadas ao final do mesmo
    // INICIALIZAï¿½AO DA FONTE DE FIï¿½ï¿½O============================================
    double somSFK = 0.0;
    double somSFKold = 0.0;
    double KeffOLD;
    //fonte fissï¿½o esta sem o keff sendo igual ao S
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
                fonteFis[a] *= 0.125; //correï¿½ï¿½o do psi barra aqui
             */
            somSFK += hx[mapX[i]] * hy[mapY[j]] * fonteFis[a];
            a++;
        }
    }
    //printf("\n valor de somSFK:%f", somSFK);
    //}
    //============================================================================
    // INICIALIZAï¿½AO DA FONTE DE ESPALHAMENTO===================================== !!!!!!REVER Cï¿½LCULO DO FLUXO ESCALAR JUNDO A FONTE DE ESPALHAMENTO, ATENTAR PARA O G!!!!
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
                            * dado.sigEsp[idZ * G * G + g * G + gLin]; //lembrar de ver a posiï¿½ao do Glin se e antes ou depois do G
                    int idfi = gLin * J * I + j * I + i;
                    fiT[idfi] = tmp * 0.5;
                }
                fonteEspalhamento[fE] *= 0.125; //correï¿½ao do psiBarra para evitar multiplicaï¿½oes
                //printf("\n fonteEspalhamento[%i]: %f",fE,fonteEspalhamento[fE]);
                fE++;

            }
        }
    }
    int contKeff = 0;
    //============================================================================

    double tempoVarerredura = 0;
    saida.interacoes = 0;
	do {
		contKeff++;
        saida.interacoes++;
		do {
         saida.interacoes++;
			//contFluxo++;
			//NO FOR DE g CONTEM TODA AS VARREDURAS NOS N SENTIDOS CONTENDO A VARREDURA EM SI
			//tempo = omp_get_wtime();
			for (int g = 0; g < G; g++) {
                double tmpTime = omp_get_wtime();
//#pragma omp parallel
				{
#pragma omp sections
					{
						// VARREDURA 31 SO --> NE ===========================================================
#pragma omp section
						{
//#pragma omp parallel for
							for (int m = 0; m < M4; m++) {
//#pragma omp parallel for
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
						}
						//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
						//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

                        //printf("VARREDURA 31: %f\n", stmp);

						// VARREDURA 42 SE --> NO ===========================================================
#pragma omp section
						{
//#pragma omp parallel for
							for (int m = M4; m < M2; m++) {
//#pragma omp parallel for
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
						}
						//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
						//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);


                        //printf("VARREDURA 42: %f\n", stmp);

						// VARREDURA 13 NE --> SO ===========================================================
#pragma omp section
						{
//#pragma omp parallel for
							for (int m = M2; m < 3 * M4; m++) {
//#pragma omp parallel for
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
						}
						//ATUALIZAR AS CONDICOES DE CONTORNO=======================================
						//ccinicial(G, M, M4, M2, J, I, JMI1, JI1, i1, IMJ1, IJ1, j1, dado.cce, dado.ccd, dado.ccc, dado.ccb);

						// VARREDURA 24 NO --> SE ===========================================================
#pragma omp section
						{
//#pragma omp parallel for
							for (int m = 3 * M4; m < M; m++) {
//#pragma omp parallel for
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
						}
					}
                    //printf("VARREDURA 24: %f\n", stmp);
                   
					// =======================================================================
				}
                 tempoVarerredura += omp_get_wtime() - tmpTime;
			}
			//tempoF  = omp_get_wtime();
			//tempoVarredura +=tempoF - tempo;
			//============================================================================
			//C�LCULO DO ERRO  agora feito junto ao ATUALIZADOR da fonte de espalhamento============================================================
			fE = 0;		//variavel momentanea para controle de indice
			errofi = 0;
			//tempo = 0;
			//tempo = omp_get_wtime();
			for (int g = 0; g < dado.numGrp; g++) {
				//#pragma omp parallel for
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
			//tempoF = omp_get_wtime();
			//tempoEspalhamento += tempoF - tempo;
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
		//tempo = 0;
		//tempo = omp_get_wtime();
		//#pragma omp parallel for
		for (int j = 0; j < J; j++) {
			//#pragma omp parallel for
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
		//tempoF = omp_get_wtime();
		//tempoFisao += tempoF - tempo;
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



	} while (errokeff > dado.cp1);

    saida.keff = keff;

    //printf("\nkeff = %e", keff);
    /*
     * Cï¿½lculo da potï¿½ncia do reator
     */
    int Lin = dado.numRegY, Col = dado.numRegX;
    double * Pot = alocar1DDouble(G * Lin * Col);
    double * tmpReg = alocar1DDouble(G * Lin * Col);
    double * potFalse = alocar1DDouble(G);
    //printf("\n\n\n");
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

    saida.Potencia = DoubVet2D(Lin, Col);
    saida.Lin = Lin;
    saida.Col = Col;
    for (int g = 0; g < G; g++) {
        for (int l = Lin - 1; l >= 0; l--) {
            for (int c = 0; c < Col; c++) {
                int idZ = dado.mapZona[l * Col + c];
                double HX = dado.tamRegX[c] / dado.parRegX[c], HY = dado.tamRegY[l] / dado.parRegY[l];
                Pot[g * Lin * Col + l * Col + c] = 3.2 * 1E-5 * 0.125 * HX * HY * dado.sigfic[idZ] * tmpReg[l * Col + c] * dado.pot / potFalse[g];
                //printf("%e\t",Pot[g * Lin * Col + l * Col + c]);
                saida.Potencia[l][c] = Pot[g * Lin * Col + l * Col + c];
            }
            //printf("\n");
        }
    }
    double tempoTotal = omp_get_wtime() - start;
    saida.TempoTotal = tempoTotal;
    saida.TempoVarredura = tempoVarerredura;
    /*===============================================================================*/
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoTotal);
    //printf("\nTotal de tempo gasto  = %.3f\n",tempoVarerredura);
    /*===============================================================================*/
    /*
    //printf("\nFIM\n");
    char * txtKeff;
    txtKeff = malloc(sizeof(double));
    sn//printf(txtKeff, 50, "%f", keff);
    */
    return saida;
}


//condiÃ§oes de contorno iniciais ==============
void ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,int j1,double *esquerda,double *direita,double *cima,double *baixo){
	//condicÃ§oes de contorno ==================== contornoPrescrito() contornoReflexivo()
	for (int g = 0; g < G; g++) {
		for (int m = 0; m < M4; m++) {
			for (int j = 0; j < J; j++) {
				if (esquerda[0] > 0) {
					int idq1 = g * JMI1 + m * JI1 + j * i1;
					int idq4 = g * JMI1 + (m + 3 * M4) * JI1 + j * i1;
					ps.psiT[idq1] = esquerda[g];
					ps.psiT[idq4] = esquerda[g];
				} else {
					int idq1 = g * JMI1 + m * JI1 + j * i1;
					int idq4 = g * JMI1 + (m + 3 * M4) * JI1 + j * i1;
					int idq2 = g * JMI1 + (m + M4) * JI1 + j * i1 + I;
					int idq3 = g * JMI1 + (m + M2) * JI1 + j * i1 + I;
					ps.psiT[idq1] = ps.psiT[idq2];
					ps.psiT[idq4] = ps.psiT[idq3];
				}
				if (direita[0] > 0) {
					int idq2 = g * JMI1 + (m + M4) * JI1 + j * i1 + I;
					int idq3 = g * JMI1 + (m + M2) * JI1 + j * i1 + I;
					ps.psiT[idq2] = direita[g];
					ps.psiT[idq3] = direita[g];
				} else {
					int idq1 = g * JMI1 + m * JI1 + j * i1;
					int idq4 = g * JMI1 + (m + 3 * M4) * JI1 + j * i1;
					int idq2 = g * JMI1 + (m + M4) * JI1 + j * i1 + I;
					int idq3 = g * JMI1 + (m + M2) * JI1 + j * i1 + I;
					ps.psiT[idq2] = ps.psiT[idq1];
					ps.psiT[idq3] = ps.psiT[idq4];
				}
			}
			for (int i = 0; i < I; i++) {
				if (baixo[0] > 0) {
					int idq1 = g * IMJ1 + m * IJ1 + i * j1;
					int idq2 = g * IMJ1 + (m + M4) * IJ1 + i * j1;
					ps.psiC[idq1] = baixo[0];
					ps.psiC[idq2] = baixo[0];
				} else {
					int idq1 = g * IMJ1 + m * IJ1 + i * j1;
					int idq2 = g * IMJ1 + (m + M4) * IJ1 + i * j1;
					int idq3 = g * IMJ1 + (m + M2) * IJ1 + i * j1 + J;
					int idq4 = g * IMJ1 + (m + 3 * M4) * IJ1 + i * j1 + J;
					ps.psiC[idq2] = ps.psiC[idq3];
					ps.psiC[idq1] = ps.psiC[idq4];
				}

				if (cima[0] > 0) {
					int idq3 = g * IMJ1 + (m + M2) * IJ1 + i * j1 + J;
					int idq4 = g * IMJ1 + (m + 3 * M4) * IJ1 + i * j1 + J;
					ps.psiC[idq3] = cima[0];
					ps.psiC[idq4] = cima[0];
				} else {
					int idq1 = g * IMJ1 + m * IJ1 + i * j1;
					int idq2 = g * IMJ1 + (m + M4) * IJ1 + i * j1;
					int idq3 = g * IMJ1 + (m + M2) * IJ1 + i * j1 + J;
					int idq4 = g * IMJ1 + (m + 3 * M4) * IJ1 + i * j1 + J;
					ps.psiC[idq3] = ps.psiC[idq2];
					ps.psiC[idq4] = ps.psiC[idq1];
				}
			}
		}
	}
}
//===========================================================

//=============================================

