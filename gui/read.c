/*
 * leitura.c
 *
 *  Created on: 9 de jul de 2020
 *      Author: viktor
 */

#include "header.h"

DadosLinha LinhaSplit(char str[], char split[]) {
	char *temp = 0;
	char **result = 0;
	unsigned int tamanho = 0;
	DadosLinha tmp;
	temp = strtok(str, split);

	if (temp) {
		result = malloc((tamanho + 1) * sizeof(char**));
		result[tamanho++] = temp;
	}

	while ((temp = strtok(0, split)) != 0) {
		result = realloc(result, (tamanho + 1) * sizeof(char**));
		result[tamanho++] = temp;
	}
	tmp.linha = result;
	tmp.dim = tamanho;
	return tmp;
}

DadosEntrada Ler(const char* nomeArquivo) {
	FILE *arq;
	DadosLinha linhaStruct;
    DadosEntrada Dados;
	// ABRE O ARQUIVO DE TEXTO PARA LEITURA
    arq = fopen(nomeArquivo, "rt");
	if (arq == NULL) {
		printf("Erro de Leitura.\n\nCaminho do Arquivo:%s",nomeArquivo);
		Dados.ordQuad = 0;
		exit(EXIT_FAILURE);
    }
	//===========================================================
	//LÊ O VALOR DAS LINHA
	char Linha[100];    
    Dados.texto = malloc(100 * sizeof (char**));
	//===========================================================

    fgets(Linha, 100, arq);
    Dados.ordQuad  = atoi(fgets(Linha, 100, arq));
    Dados.texto[0] = malloc(strlen(Linha) * sizeof(char*));
    strcpy(Dados.texto[0],Linha);


	fgets(Linha, 100, arq);
   //  strcpy(Dados.texto[1],Linha);
	Dados.numGrp  = atoi(fgets(Linha, 100, arq));
    Dados.texto[1] = malloc(strlen(Linha) * sizeof(char*));
    strcpy(Dados.texto[1],Linha);

	fgets(Linha, 100, arq);
  //   strcpy(Dados.texto[2],Linha);
	Dados.numZon  = atoi(fgets(Linha, 100, arq));
    Dados.texto[2] = malloc(strlen(Linha) * sizeof(char*));
    strcpy(Dados.texto[2],Linha);

	fgets(Linha, 100, arq);
 //    strcpy(Dados.texto[3],Linha);
	Dados.pot  = atof(fgets(Linha, 100, arq));
    Dados.texto[3] = malloc(strlen(Linha) * sizeof(char*));
    strcpy(Dados.texto[3],Linha);

	fgets(Linha, 100, arq);
//     strcpy(Dados.texto[4],Linha);
	Dados.cp1  = atof(fgets(Linha, 100, arq));
    Dados.texto[4] = malloc(strlen(Linha) * sizeof(char*));
    strcpy(Dados.texto[4],Linha);

	fgets(Linha, 100, arq);
//     strcpy(Dados.texto[5],Linha);
	Dados.cp2  = atof(fgets(Linha, 100, arq));
    Dados.texto[5] = malloc(strlen(Linha) * sizeof(char*));
    strcpy(Dados.texto[5],Linha);

	fgets(Linha, 100, arq);
 //   strcpy(Dados.texto[6],Linha);
    Dados.per  = atoi(fgets(Linha, 100, arq));
    //Dados.per = 1000;

	fgets(Linha, 100, arq);

	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
    Dados.texto[6] = malloc(strlen(linhaStruct.linha[0]) * sizeof(char*));
    strcpy(Dados.texto[6],Linha);
  //  strcpy(Dados.texto[7],Linha);
	Dados.cce = alocar1DDouble(Dados.numGrp);
	for(int i = 0; i < Dados.numGrp; i++){
        Dados.cce[i] = atof(linhaStruct.linha[i]);
	}

	fgets(Linha, 100, arq);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
    Dados.texto[7] = malloc(strlen(linhaStruct.linha[0]) * sizeof(char*));
    strcpy(Dados.texto[7],Linha);
	Dados.ccd = alocar1DDouble(Dados.numGrp);
	for(int i = 0; i < Dados.numGrp; i++){
	    Dados.ccd[i] = atof(linhaStruct.linha[i]);
	}

	fgets(Linha, 100, arq);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
    Dados.texto[8] = malloc(strlen(linhaStruct.linha[0]) * sizeof(char*));
    strcpy(Dados.texto[8],Linha);
	Dados.ccc = alocar1DDouble(Dados.numGrp);
	for(int i = 0; i < Dados.numGrp; i++){
	    Dados.ccc[i] = atof(linhaStruct.linha[i]);
	}

	fgets(Linha, 100, arq);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
    Dados.texto[9] = malloc(strlen(linhaStruct.linha[0]) * sizeof(char*));
    strcpy(Dados.texto[9],Linha);
	Dados.ccb = alocar1DDouble(Dados.numGrp);
	for(int i = 0; i < Dados.numGrp; i++){
	    Dados.ccb[i] = atof(linhaStruct.linha[i]);
	}

	fgets(Linha, 100, arq);
	fgets(Linha, 100, arq);

	Dados.numRegX  = atoi(fgets(Linha, 100, arq));
    Dados.texto[10] = malloc(strlen(linhaStruct.linha[0]) * sizeof(char*));
    strcpy(Dados.texto[10],Linha);


	fgets(Linha, 100, arq);


	Dados.numRegY  = atoi(fgets(Linha, 100, arq));
    Dados.texto[11] = malloc(strlen(linhaStruct.linha[0]) * sizeof(char*));
    strcpy(Dados.texto[11],Linha);

    //result = realloc(result, (tamanho + 1) * sizeof(char**));

	fgets(Linha, 100, arq);
    fgets(Linha, 100, arq);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
   //Dados.texto = realloc( Dados.texto, (linhaStruct.dim + 12) * sizeof(char*));
	Dados.tamRegX = alocar1DDouble(Dados.numRegX);
	for(int i = 0; i < Dados.numRegX; i++){
        Dados.texto[12+i] = malloc(strlen(linhaStruct.linha[i]) * sizeof(char*));
        strcpy(Dados.texto[12+i],linhaStruct.linha[i]);
	    Dados.tamRegX[i] = atof(linhaStruct.linha[i]);
        //Dados.texto[12+i] = linhaStruct.linha[i];
	}
    int tamanho = 12 +  Dados.numRegX;

	fgets(Linha, 100, arq);
 //    strcpy(Dados.texto[14],Linha);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	Dados.tamRegY = alocar1DDouble(Dados.numRegX);
	for(int i = 0; i < Dados.numRegX; i++){
        Dados.texto[tamanho+i] = malloc(strlen(linhaStruct.linha[i]) * sizeof(char*));
        strcpy(Dados.texto[tamanho+i],linhaStruct.linha[i]);
	    Dados.tamRegY[i] = atof(linhaStruct.linha[i]);
	}
    tamanho = tamanho +  Dados.numRegX;

	fgets(Linha, 100, arq);
	fgets(Linha, 100, arq);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	Dados.parRegX = alocar1DDouble(Dados.numRegX);
	for(int i = 0; i < Dados.numRegX; i++){
        Dados.texto[tamanho+i] = malloc(strlen(linhaStruct.linha[i]) * sizeof(char*));
        strcpy(Dados.texto[tamanho+i],linhaStruct.linha[i]);
	    Dados.parRegX[i] = atoi(linhaStruct.linha[i]);
	}

    tamanho = tamanho +  Dados.numRegX;

	fgets(Linha, 100, arq);
	linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	Dados.parRegY = alocar1DDouble(Dados.numRegX);
	for(int i = 0; i < Dados.numRegX; i++){
        Dados.texto[tamanho+i] = malloc(strlen(linhaStruct.linha[i]) * sizeof(char*));
        strcpy(Dados.texto[tamanho+i],linhaStruct.linha[i]);
	    Dados.parRegY[i] = atoi(linhaStruct.linha[i]);
	}

    tamanho = tamanho +  Dados.numRegX;

	// ==================================================================
	fgets(Linha, 100, arq);
	Dados.mapZona = alocar1DInteger(Dados.numRegY * Dados.numRegX);
	int cont = 0;
	for(int l = 0; l < Dados.numRegY; l++){
	    linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	    for(int c = 0; c < Dados.numRegX; c++){
            Dados.texto[tamanho+(cont)] = malloc(strlen(linhaStruct.linha[(c)]) * sizeof(char*));
            strcpy(Dados.texto[tamanho+(cont)],linhaStruct.linha[(c)]);
	        Dados.mapZona[cont] = atoi(linhaStruct.linha[c]);
	        cont++;
	    }
	}
     tamanho = tamanho +  Dados.numRegX*Dados.numRegY;
	// ==================================================================

	fgets(Linha, 100, arq);
	fgets(Linha, 100, arq);
	Dados.sigTotal = alocar1DDouble(Dados.numZon * Dados.numGrp);
	//printf("\n");
	cont = 0;

	for(int l = 0; l < Dados.numZon; l++){
	    linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	    for(int c = 0; c < Dados.numGrp; c++){
            Dados.texto[tamanho+(cont)] = malloc(strlen(linhaStruct.linha[(c)]) * sizeof(char*));
            strcpy(Dados.texto[tamanho+(cont)],linhaStruct.linha[(c)]);
	        Dados.sigTotal[cont] = atof(linhaStruct.linha[c]);
	        //printf("\t%e", Dados.sigTotal[cont]);
	        cont++;
	    }
	    //printf("\n");
	}
     tamanho = tamanho +  Dados.numZon*Dados.numGrp;

	fgets(Linha, 100, arq);
	fgets(Linha, 100, arq);
	cont = 0;
	Dados.sigfic = alocar1DDouble(Dados.numZon * Dados.numGrp);
	for(int l = 0; l < Dados.numZon; l++){
	    linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	    for(int c = 0; c < Dados.numGrp; c++){
            Dados.texto[tamanho+(cont)] = malloc(strlen(linhaStruct.linha[(c)]) * sizeof(char*));
            strcpy(Dados.texto[tamanho+(cont)],linhaStruct.linha[(c)]);
	        Dados.sigfic[cont] = atof(linhaStruct.linha[c]);
	        cont++;
	    }
	}
     tamanho = tamanho +  Dados.numZon*Dados.numGrp;

	fgets(Linha, 100, arq);

	cont = 0;
	Dados.sigEsp = alocar1DDouble(Dados.numZon * Dados.numGrp * Dados.numGrp);
	for(int z = 0; z < Dados.numZon; z++){
	    fgets(Linha, 100, arq);
	    for(int l = 0; l < Dados.numGrp; l++){
	        linhaStruct = LinhaSplit(fgets(Linha, 100, arq), " ");
	        for(int c = 0; c < Dados.numGrp; c++){                
                Dados.texto[tamanho+(cont)] = malloc(strlen(linhaStruct.linha[(c)]) * sizeof(char*));
                strcpy(Dados.texto[tamanho+(cont)],linhaStruct.linha[(c)]);
	            Dados.sigEsp[cont] = atof(linhaStruct.linha[c]);
	            cont++;
	        }
	    }
	}

	return Dados;
}


void escrever(DadosEntrada Dados) {

    //===========================================================
printf("\n________________________________________________________________\n");

    printf(" ordem de quadratura = %i" ,Dados.ordQuad);
printf("\n________________________________________________________________\n");
   //  strcpy(Dados.texto[1],Linha);
    printf(" Numero de grupos = %i" , Dados.numGrp);

printf("\n________________________________________________________________\n");
  //   strcpy(Dados.texto[2],Linha);
       printf(" numero de zonas = %i" ,Dados.numZon);

printf("\n________________________________________________________________\n");
 //    strcpy(Dados.texto[3],Linha);
    printf(" potencia do reator = %f" , Dados.pot  );


printf("\n________________________________________________________________\n");
//     strcpy(Dados.texto[4],Linha);
    printf("criterio de parada 1 = %f" , Dados.cp1  );

printf("\n________________________________________________________________\n");
//     strcpy(Dados.texto[5],Linha);
     printf("criterio de parada 2 = %f" ,Dados.cp2  );
printf("\n________________________________________________________________\n");

 //   strcpy(Dados.texto[6],Linha);
      printf("periodicidade = %i" ,Dados.per);
    //Dados.per = 1000;


printf("\n________________________________________________________________\n");
  //  strcpy(Dados.texto[7],Linha);
   // Dados.cce = alocar1DDouble(Dados.numGrp);
      printf("CCE\n");
    for(int i = 0; i < Dados.numGrp; i++){
           printf(" %f" ,Dados.cce[i]);
    }

printf("\n________________________________________________________________\n");
    //Dados.ccd = alocar1DDouble(Dados.numGrp);
    printf("CCD\n");
    for(int i = 0; i < Dados.numGrp; i++){
          printf(" %lf" ,Dados.ccd[i]);
    }

printf("\n________________________________________________________________\n");
   // Dados.ccc = alocar1DDouble(Dados.numGrp);
     printf("CCCn");
    for(int i = 0; i < Dados.numGrp; i++){
       printf(" %lf" ,  Dados.ccc[i] );
    }

printf("\n________________________________________________________________\n");
   // Dados.ccb = alocar1DDouble(Dados.numGrp);
     printf("CCB\n");
    for(int i = 0; i < Dados.numGrp; i++){
       printf(" %lf" ,  Dados.ccb[i] );
    }

printf("\n________________________________________________________________\n");
     printf("Numero de regioes em X= %i" ,Dados.numRegX  );
printf("\n________________________________________________________________\n");
     printf("Numero de regioes em Y= %i" ,Dados.numRegY  );

    //result = realloc(result, (tamanho + 1) * sizeof(char**));

printf("\n________________________________________________________________\n");
   // Dados.tamRegX = alocar1DDouble(Dados.numRegX);
     printf(" tamanho em X\n");
    for(int i = 0; i < Dados.numRegX; i++){
         printf(" %lf" , Dados.tamRegX[i]  );
        //Dados.texto[12+i] = linhaStruct.linha[i];
    }


printf("\n________________________________________________________________\n");
 //    strcpy(Dados.texto[14],Linha);
     printf(" tamanho em Y\n");
    //Dados.tamRegY = alocar1DDouble(Dados.numRegX);
    for(int i = 0; i < Dados.numRegX; i++){
        printf(" %lf" , Dados.tamRegY[i]);
    }
printf("\n________________________________________________________________\n");
   // Dados.parRegX = alocar1DDouble(Dados.numRegX);
    printf(" partiçoes em X\n");
    for(int i = 0; i < Dados.numRegX; i++){
       printf(" %lf" , Dados.parRegX[i]  );
    }

printf("\n________________________________________________________________\n");

    printf(" partiçoes em Y\n");
   // Dados.parRegY = alocar1DDouble(Dados.numRegX);
    for(int i = 0; i < Dados.numRegX; i++){
        printf(" %lf" , Dados.parRegY[i]);
    }

printf("\n________________________________________________________________\n");
    // ==================================================================
     printf(" map da zona\n");
    //Dados.mapZona = alocar1DInteger(Dados.numRegY * Dados.numRegX);
    int cont = 0;
    for(int l = 0; l < Dados.numRegY; l++){
        for(int c = 0; c < Dados.numRegX; c++){
            printf(" %i" , Dados.mapZona[cont]);
            cont++;
        }
        printf("\n");
    }

    // ==================================================================

printf("\n________________________________________________________________\n");
   // Dados.sigTotal = alocar1DDouble(Dados.numZon * Dados.numGrp);
    //printf("\n");
    cont = 0;
    for(int l = 0; l < Dados.numZon; l++){

        for(int c = 0; c < Dados.numGrp; c++){

            printf("\t%e", Dados.sigTotal[cont]);
            cont++;
        }
        printf("\n");
    }
printf("\n________________________________________________________________\n");
    cont = 0;
   // Dados.sigfic = alocar1DDouble(Dados.numZon * Dados.numGrp);
    for(int l = 0; l < Dados.numZon; l++){

        for(int c = 0; c < Dados.numGrp; c++){
             printf("\t%e", Dados.sigfic[cont]);
            cont++;
        }
        printf("\n");
    }

printf("\n________________________________________________________________\n");

    cont = 0;
    //Dados.sigEsp = alocar1DDouble(Dados.numZon * Dados.numGrp * Dados.numGrp);
    for(int z = 0; z < Dados.numZon; z++){

        for(int l = 0; l < Dados.numGrp; l++){

            for(int c = 0; c < Dados.numGrp; c++){
                 printf("\t%e", Dados.sigEsp[cont]);
                cont++;
            }
            printf("\n");
        }
        printf("\n");
    }


}
