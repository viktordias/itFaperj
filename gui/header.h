//CRIADO POR MATHEUS RIBEIRO | 26/JUN/2020 =====

//HEADERS ======================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <C:/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/9.2.0/include/omp.h>

#define MAX_THERREDS 4





//==============================================
typedef struct {
   double keff;
   double TempoTotal;
   double TempoVarredura;
   double **Potencia;
   int Lin;
   int Col;
   int interacoes;
}DadosSaida;

//STRUCT'S =====================================
typedef struct {
	double pot;								//potencia do gerador
	int ordQuad;                           //ordem de quadratura
	int numGrp;	                          //numero de grupos
	int numZon;	                         //numero de  zonas materias
	double cp1;                         //criterio de parada para o keff
	double cp2;		  				   //criterio de parada para o fluxo escalar
	int per;                          //periocidade dos nodos
	double *cce;	                 //contorno a esquerda
	double *ccd;	                //contorno a direita
	double *ccc;	               //contorno a cima
	double *ccb;	              //contorno a baixo
	int numRegX;	             //numero de regioes em x
	int numRegY;	            //numero de regioes em Y
	double *tamRegX;           //tamanho das regioes em X
	double *tamRegY;          //tamanho das regioes em Y
	double *parRegX;         //partiçoes das regioes em X
	double *parRegY;        //partiçoes das regioes em Y
	int *mapZona;          //matriz dos materiais
	double *sigTotal;     //matriz sigma total
	double *sigfic;      //matriz sigma fiçao
	double *sigEsp;     //matriz sigma espalhamento
    double *potencia;
    char **texto;
    char *print;

} DadosEntrada;
//==============================================
typedef struct {
	char **linha;
	int dim;
} DadosLinha;
DadosLinha LinhaSplit(char str[], char split[]);
//==============================================
typedef struct {
	double *mi;
	double *eta;
	double *w;
} quadratura;
quadratura qt;
//==============================================

//READING FUNCTION =============================
DadosEntrada Ler(const char* nomeArquivo);
void escrever(DadosEntrada Dados) ;
//==============================================

//MAIN FUNCTION ================================
void FillingTheQuadratureStruct(int N);
//==============================================
//PSIS==========================================
typedef struct {
	double *psiT;
	double *psiC;
} psis;
psis ps;

//BASE VECTOR'S ================================
int* GetMappingBase(int N, int sizeQ);
double* GetMiBase(int N);
double* GetWBase(int N);
//==============================================

//FULL VECTOR'S ================================
double* GetEtaFullVector(int N);
double* GetWFullVector(int N);
double* GetMiFullVector(int N);
//==============================================

//ALLOCATIONS ==================================
double* alocar1DDouble(int tamanho);
double **DoubVet2D(int dim1, int dim2);
int* alocar1DInteger(int tamanho);
void desalocar1DDouble(double *vetor);
void desalocar1DInteger(int *vetor);
//==============================================
//FUNÇOES AUXILIARES ===========================
double modulo(double modulo); // RETURN MODULO==

DadosSaida GETDD2Dserial(DadosEntrada dado);
DadosSaida GETDD2DparaleloDirecoes(DadosEntrada dado);
DadosSaida GETDD2DparaleloTotal(DadosEntrada dado);
DadosSaida GETDD2DparaleloSessoes(DadosEntrada dado);


double GETDD2Dviktor(DadosEntrada dado);


//CONDIÇOES DE CONTORNO========================
void ccinicial(int G,int M,int M4,int M2,int J,int I, int JMI1,int JI1,int i1,int IMJ1,int IJ1,
		int j1,double *esquerda,double *direita,double *cima,double *baixo);
//situacionais==========================================
void ccCima();
void ccBaixo();
void ccEsquerda();
void ccDireita();

