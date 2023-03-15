#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QStringListModel>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <tgmath.h>
#include <string.h>
#include <QTabWidget>
#include <QTableView>
#include <QTableWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <QWindow>

extern "C"{
//#include "FAPERJ.c"
#include "header.h"
//#include  "IT_FAPERJ_2020.c"
}

DadosEntrada dadosInterface;
DadosEntrada dadosArquivo;
QString local =  "F:/TRABALHOS/viktor/";
QString nome = "exemplo1.txt";
QActionGroup *ag;




double maxInArray(double* array, int size){
    double aux = std::numeric_limits<double>::min();
    for (int i=0;i<size;i++){
        if (array[i] > aux){
            aux = array[i];
        }
    }
    return aux;
}

double minInArray(double* array, int size){
    double aux = std::numeric_limits<double>::max();
    for (int i=0;i<size;i++){
        if (array[i] < aux){
            aux = array[i];
        }
    }
    return aux;
}

double maxInMatrix(double** array, int I, int J){
    double aux = std::numeric_limits<double>::min();
    for (int i=0;i<I;i++){
        for (int j=0;j<J;j++){
            if (array[i][j] > aux){
                aux = array[i][j];
            }
        }
    }
    return aux;
}


void MainWindow::on_actionabrir_triggered(){


    QString filtro = "Todos os arquivos (*.*) ;; Arquivos de texto (*.txt)";
    QString abrirArquivo = QFileDialog::getOpenFileName(this,"Abrir arquivos","C://",filtro);


    QFile arquivo(abrirArquivo);
    if(!arquivo.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"ERRO","Erro ao abrir o arquivo!");
    }
    const std::string& stdS = abrirArquivo.toStdString();

   dadosArquivo = Ler(stdS.c_str());

    //ui->keffSerial->setText(GETDD2Dserial(dadosArquivo));
     //TODO: Colocar dados lidos do arquivo nos edits

     ui->txtOrdQuad->setText(dadosArquivo.texto[0]);
     ui->txtNumGrup->setText(dadosArquivo.texto[1]);
     ui->txtZonMat->setText(dadosArquivo.texto[2]);
     ui->txtPot->setText(dadosArquivo.texto[3]);
     ui->txtKeff->setText(dadosArquivo.texto[4]);
     ui->txtFluxo->setText(dadosArquivo.texto[5]);
     ui->txtE->setText(dadosArquivo.texto[6]);
     ui->txtD->setText(dadosArquivo.texto[7]);
     ui->txtCima->setText(dadosArquivo.texto[8]);
     ui->txtBaixo->setText(dadosArquivo.texto[9]);
     ui->txtRegX->setText(dadosArquivo.texto[10]);
     ui->txtRegY->setText(dadosArquivo.texto[11]);
      QString a ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
        a.append(dadosArquivo.texto[12 + i]);
        a.append(" ");
     }
     ui->txtTamX->setText(a);

     int tamanho = 12 +  dadosArquivo.numRegX;
        QString b ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
         // ui->txtTamY->setText(dados.texto[tamanho]);
         b.append(dadosArquivo.texto[tamanho+i]);
         b.append(" ");
     }
     ui->txtTamY->setText(b);
     tamanho = tamanho +  dadosArquivo.numRegX;
      QString c ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
         //ui->txtPartX->setText(dados.texto[tamanho]);
         c.append(dadosArquivo.texto[tamanho+i]);
         c.append(" ");
     }
     ui->txtPartX->setText(c);
     tamanho = tamanho +  dadosArquivo.numRegX;
      QString d ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
         //ui->txtPartY->setText(dados.texto[tamanho]);
         d.append(dadosArquivo.texto[tamanho+i]);
         d.append(" ");
     }
     ui->txtPartY->setText(d);
     tamanho = tamanho +  dadosArquivo.numRegX;
     QString m;
     int cont = 0;
     for (int l = 0; l < dadosArquivo.numRegY; l++ ) {
         for (int c = 0; c < dadosArquivo.numRegX-1; c++ ) {
             m.append(dadosArquivo.texto[tamanho+(cont)]);
             m.append(" ");
             cont++;
         }
         m.append(dadosArquivo.texto[tamanho+(cont)]);
         cont++;
     }
     ui->txtmaterial->setPlainText(m);
     tamanho = tamanho +  dadosArquivo.numRegX*dadosArquivo.numRegY;
     QString f;
     cont = 0;
     for(int l = 0; l < dadosArquivo.numZon; l++){
         for(int c = 0; c < dadosArquivo.numGrp; c++){
             f.append(dadosArquivo.texto[tamanho+(cont)]);
             cont++;
         }
         f.append("\n");
     }
     ui->txtST->setPlainText(f);
     tamanho = tamanho +  dadosArquivo.numZon*dadosArquivo.numGrp;
     QString t;
     cont = 0;
     for(int l = 0; l < dadosArquivo.numZon; l++){
         for(int c = 0; c < dadosArquivo.numGrp; c++){
             t.append(dadosArquivo.texto[tamanho+(cont)]);
             cont++;
         }
         t.append("\n");
     }
     ui->txtSF->setPlainText(t);
     tamanho = tamanho +  dadosArquivo.numZon*dadosArquivo.numGrp;
     QString s;
     cont = 0;
     for(int z = 0; z < dadosArquivo.numZon; z++){
         for(int l = 0; l < dadosArquivo.numGrp; l++){
             for(int c = 0; c < dadosArquivo.numGrp; c++){
                 s.append(dadosArquivo.texto[tamanho+(cont)]);
                 cont++;
             }
             s.append("\n");
         }
         s.append("\n");
     }
      ui->txtSS->setPlainText(s);

      //ui->actionabrir->setChecked(false);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ag = new QActionGroup(this);
    ag->addAction(ui->actionserial);
    ag->addAction(ui->actionParalelo_Total);
    ag->addAction(ui->actionParalelo_Sessoes);
    ag->addAction(ui->actionParalelo_Direcoes);
    ag->addAction(ui->actionParaleloTotal_X_Serial);
    ag->addAction(ui->actionParaleloSessoes_X_Serial);
    ag->addAction(ui->actionParaleloDirecoes_X_Serrial);
    ag->addAction(ui->actionabrir);





    ui->actionserial->setChecked(true);
    ui->tabWidget_2->setCurrentWidget(ui->tab_3);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_validarinicial_clicked()
{
    dadosInterface.ordQuad = atoi(ui->txtOrdQuad->text().toStdString().c_str());
    dadosInterface.numGrp = atoi(ui->txtNumGrup->text().toStdString().c_str());
    dadosInterface.numZon = atoi(ui->txtZonMat->text().toStdString().c_str());
    dadosInterface.pot = atof(ui->txtPot->text().toStdString().c_str());
    dadosInterface.cp1 = atof(ui->txtKeff->text().toStdString().c_str());
    dadosInterface.cp2 = atof(ui->txtFluxo->text().toStdString().c_str());


    ui->tabWidget_2->setCurrentWidget(ui->tab_5);
}

void MainWindow::on_validarcontorno_clicked()
{
    /*   Alocando mémorias  */
    dadosInterface.cce = alocar1DDouble(dadosInterface.numGrp);
    dadosInterface.ccd = alocar1DDouble(dadosInterface.numGrp);
    dadosInterface.ccc = alocar1DDouble(dadosInterface.numGrp);
    dadosInterface.ccb = alocar1DDouble(dadosInterface.numGrp);

    QString texto = ui->txtE->text();
    dadosInterface.cce[0] = texto.toFloat();
    //QMessageBox::information(this,"digitado","sla"+c_str2);
    char* split = strdup(" ");
    split[0] = ' ';
    char* auxCA = strdup(ui->txtE->text().toStdString().c_str());
    DadosLinha linhaAux = LinhaSplit(auxCA, split);
    linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numGrp; i++){
        dadosInterface.cce[i] = atoi(linhaAux.linha[i]);
    }
    //linhaAux = LinhaSplit(auxCA, split);
    //char *linha = strtok(auxCA," ");
    //const char *texto  = linha;

    auxCA = strdup(ui->txtD->text().toStdString().c_str());
    linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numGrp; i++){
        dadosInterface.ccd[i] = atoi(linhaAux.linha[i]);
    }
    auxCA = strdup(ui->txtCima->text().toStdString().c_str());
    linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numGrp; i++){
        dadosInterface.ccc[i] = atoi(linhaAux.linha[i]);
    }
    auxCA = strdup(ui->txtBaixo->text().toStdString().c_str());
    linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numGrp; i++){
        dadosInterface.ccb[i] = atoi(linhaAux.linha[i]);
    }
    ui->tabWidget_2->setCurrentWidget(ui->tab_6);
}

void MainWindow::on_Validarreg_clicked()
{
    char* split = strdup(" ");
    split[0] = ' ';
    char* auxCA ;
    DadosLinha linhaAux ;

    dadosInterface.numRegX = atoi(ui->txtRegX->text().toStdString().c_str());
    dadosInterface.numRegY = atoi(ui->txtRegY->text().toStdString().c_str());

    /*   Alocando mémorias  */
    dadosInterface.tamRegX = alocar1DDouble(dadosInterface.numRegX);
    dadosInterface.parRegX = alocar1DDouble(dadosInterface.numRegX);
    dadosInterface.tamRegY = alocar1DDouble(dadosInterface.numRegY);
    dadosInterface.parRegY = alocar1DDouble(dadosInterface.numRegY);
    dadosInterface.mapZona = alocar1DInteger(dadosInterface.numRegY * dadosInterface.numRegX);
    /************************/

    auxCA = strdup(ui->txtTamX->text().toStdString().c_str());
     linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numRegX; i++){
        dadosInterface.tamRegX[i] = atof(linhaAux.linha[i]);
    }
    auxCA = strdup(ui->txtPartX->text().toStdString().c_str());
     linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numRegX; i++){
        dadosInterface.parRegX[i] = atoi(linhaAux.linha[i]);
    }

    auxCA = strdup(ui->txtTamY->text().toStdString().c_str());
     linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numRegY; i++){
        dadosInterface.tamRegY[i] = atof(linhaAux.linha[i]);
    }
    auxCA = strdup(ui->txtPartY->text().toStdString().c_str());
    linhaAux = LinhaSplit(auxCA, split);
    for(int i = 0; i < dadosInterface.numRegY; i++){
        dadosInterface.parRegY[i] = atoi(linhaAux.linha[i]);
    }

    ui->tabWidget_2->setCurrentWidget(ui->tab_7);
}

void MainWindow::on_pushButton_clicked()
{
    char* split = strdup(" ");
    split[0] = '\n';
    char* auxCA = strdup(ui->txtmaterial->toPlainText().toStdString().c_str());
    DadosLinha linhaAux = LinhaSplit(auxCA, split);
    split[0] = ' ';
    int cont = 0;double tmp;
    for (int j = 0;j < dadosInterface.numRegY; j++) {
        DadosLinha colAux= LinhaSplit(linhaAux.linha[j], split);
        for(int i = 0; i < dadosInterface.numRegX; i++){
            dadosInterface.mapZona[cont] = atoi(colAux.linha[i]);
            tmp = dadosInterface.mapZona[cont];
            cont++;
        }
    }

    ui->tabWidget_2->setCurrentWidget(ui->tab_4);
}

void MainWindow::on_pushButton_2_clicked()
{

    dadosInterface.sigTotal = alocar1DDouble(dadosInterface.numZon * dadosInterface.numGrp);
    dadosInterface.sigfic = alocar1DDouble(dadosInterface.numZon * dadosInterface.numGrp);
    dadosInterface.sigEsp = alocar1DDouble(dadosInterface.numZon * dadosInterface.numGrp * dadosInterface.numGrp);
    /************************/
    char* split = strdup(" ");
    split[0] = '\n';
    char* auxCA = strdup(ui->txtSF->toPlainText().toStdString().c_str());
    DadosLinha linhaAux = LinhaSplit(auxCA, split);
    int cont = 0;
    for (int j = 0;j < dadosInterface.numZon; j++) {
        for(int i = 0; i < dadosInterface.numGrp; i++){
            dadosInterface.sigfic[cont] = atof(linhaAux.linha[cont]);
            cont++;
        }
    }

    auxCA = strdup(ui->txtST->toPlainText().toStdString().c_str());
    linhaAux = LinhaSplit(auxCA, split);
    cont = 0;
    for (int j = 0;j < dadosInterface.numZon; j++) {
        for(int i = 0; i < dadosInterface.numGrp; i++){
            dadosInterface.sigTotal[cont] = atof(linhaAux.linha[cont]);
            cont++;
        }
    }

   // split = strdup(" ");
   // split[0] = '\n';
    auxCA = strdup(ui->txtSS->toPlainText().toStdString().c_str());
    linhaAux = LinhaSplit(auxCA, split);
    cont = 0;
    for (int z = 0; z < dadosInterface.numZon; z++) {
        for (int j = 0;j < dadosInterface.numGrp; j++) {
            for(int i = 0; i < dadosInterface.numGrp; i++){
                dadosInterface.sigEsp[cont] = atof(linhaAux.linha[cont]);
                cont++;
            }
        }
    }
    QString css = ( "background-color:#25e31c;color:000;");
    ui->exec->setStyleSheet(css);
    QMessageBox::information(this,"Parabens","Agora pode ser executado o calculo!");
    //ui->tabWidget_2->setCurrentWidget(ui->tabWidget);
    ui->exec->setEnabled(true);

   // ui->tabWidget_2->setCurrentWidget(ui->tab_8);
}

void MainWindow::on_validarfisao_clicked()
{

}
/*
void MainWindow::on_btn_abrirArquivo_clicked()
{
    QString filtro = "Todos os arquivos (*.*) ;; Arquivos de texto (*.txt)";
    QString abrirArquivo = QFileDialog::getOpenFileName(this,"Abrir arquivos","C://",filtro);


    QFile arquivo(abrirArquivo);
    if(!arquivo.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"ERRO","Erro ao abrir o arquivo!");
    }
    const std::string& stdS = abrirArquivo.toStdString();

   dadosArquivo = Ler(stdS.c_str());
    //ui->keffSerial->setText(GETDD2Dserial(dadosArquivo));
     //TODO: Colocar dados lidos do arquivo nos edits

     ui->txtOrdQuad->setText(dadosArquivo.texto[0]);
     ui->txtNumGrup->setText(dadosArquivo.texto[1]);
     ui->txtZonMat->setText(dadosArquivo.texto[2]);
     ui->txtPot->setText(dadosArquivo.texto[3]);
     ui->txtKeff->setText(dadosArquivo.texto[4]);
     ui->txtFluxo->setText(dadosArquivo.texto[5]);
     ui->txtE->setText(dadosArquivo.texto[6]);
     ui->txtD->setText(dadosArquivo.texto[7]);
     ui->txtCima->setText(dadosArquivo.texto[8]);
     ui->txtBaixo->setText(dadosArquivo.texto[9]);
     ui->txtRegX->setText(dadosArquivo.texto[10]);
     ui->txtRegY->setText(dadosArquivo.texto[11]);
      QString a ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
        a.append(dadosArquivo.texto[12 + i]);
        a.append(" ");
     }
     ui->txtTamX->setText(a);

     int tamanho = 12 +  dadosArquivo.numRegX;
        QString b ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
         // ui->txtTamY->setText(dados.texto[tamanho]);
         b.append(dadosArquivo.texto[tamanho+i]);
         b.append(" ");
     }
     ui->txtTamY->setText(b);
     tamanho = tamanho +  dadosArquivo.numRegX;
      QString c ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
         //ui->txtPartX->setText(dados.texto[tamanho]);
         c.append(dadosArquivo.texto[tamanho+i]);
         c.append(" ");
     }
     ui->txtPartX->setText(c);
     tamanho = tamanho +  dadosArquivo.numRegX;
      QString d ;
     for (int i = 0; i < dadosArquivo.numRegX ; i++ ) {
         //ui->txtPartY->setText(dados.texto[tamanho]);
         d.append(dadosArquivo.texto[tamanho+i]);
         d.append(" ");
     }
     ui->txtPartY->setText(d);
     tamanho = tamanho +  dadosArquivo.numRegX;
     QString m;
     int cont = 0;
     for (int l = 0; l < dadosArquivo.numRegY; l++ ) {
         for (int c = 0; c < dadosArquivo.numRegX-1; c++ ) {
             m.append(dadosArquivo.texto[tamanho+(cont)]);
             m.append(" ");
             cont++;
         }
         m.append(dadosArquivo.texto[tamanho+(cont)]);
         cont++;
     }
     ui->txtmaterial->setPlainText(m);
     tamanho = tamanho +  dadosArquivo.numRegX*dadosArquivo.numRegY;
     QString f;
     cont = 0;
     for(int l = 0; l < dadosArquivo.numZon; l++){
         for(int c = 0; c < dadosArquivo.numGrp; c++){
             f.append(dadosArquivo.texto[tamanho+(cont)]);
             cont++;
         }
     }
     ui->txtSF->setPlainText(f);
     tamanho = tamanho +  dadosArquivo.numZon*dadosArquivo.numGrp;
     QString t;
     cont = 0;
     for(int l = 0; l < dadosArquivo.numZon; l++){
         for(int c = 0; c < dadosArquivo.numGrp; c++){
             t.append(dadosArquivo.texto[tamanho+(cont)]);
             cont++;
         }
     }
     ui->txtST->setPlainText(t);
     tamanho = tamanho +  dadosArquivo.numZon*dadosArquivo.numGrp;
     QString s;
     cont = 0;
     for(int z = 0; z < dadosArquivo.numZon; z++){
         for(int l = 0; l < dadosArquivo.numGrp; l++){
             for(int c = 0; c < dadosArquivo.numGrp; c++){
                 s.append(dadosArquivo.texto[tamanho+(cont)]);
                 cont++;
             }
         }
         s.append("\n");
     }
      ui->txtSS->setPlainText(s);
/*
    ui->tabWidget->setCurrentWidget(ui->tab_2);

    QString keff = GETDD2Dserial(dados);
    ui->keffSerial->setText(keff);

    // ui->txtTamY->setText(dados.texto[13]);






}

*/


void MainWindow::on_exec_clicked()
{    
    ui->exec->setStyleSheet("background-color:#ff0000;color:000;");
    ui->exec->setText("Calculando");
    ui->exec->setEnabled(false);
    QMessageBox::warning(this,"calculando","Aguarde ate que o resultado seja exebido");
    //setWindowState(omp_pause_resource(omp_pause_soft,2));
    //setWindowState();
    Calcular();
}

void MainWindow::Calcular(){

    bool serial = ui->actionserial->isChecked();
    bool paraleloT = ui->actionParalelo_Total->isChecked();
    bool paraleloS = ui -> actionParalelo_Sessoes -> isChecked();
    bool paraleloD = ui -> actionParalelo_Direcoes -> isChecked();
    bool paraTxSerial = ui->actionParaleloTotal_X_Serial->isChecked();
    bool paraSxSerial = ui->actionParaleloSessoes_X_Serial->isChecked();
    bool paraDxSerial = ui->actionParaleloDirecoes_X_Serrial->isChecked();

    //ui->exec->setText(this,"CALCULANDO");
    if(serial == true){
            DadosSaida saidaSerial = GETDD2Dserial(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Serial\n\nValor do Keff = "
                        + QString::number(saidaSerial.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaSerial.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaSerial.Col; c++)
                  str.append(QString::number(saidaSerial.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaSerial.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaSerial.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes = \t " + QString::number(saidaSerial.interacoes,'i', 0));
            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);





    }

    if(paraleloT == true){

            DadosSaida saidaParalela = GETDD2DparaleloTotal(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Paralelo\n\nValor do Keff = "
                        + QString::number(saidaParalela.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaParalela.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaParalela.Col; c++)
                  str.append(QString::number(saidaParalela.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaParalela.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaParalela.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes = \t " + QString::number(saidaParalela.interacoes,'i', 0));
            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);



        }

    if(paraleloS == true){

            DadosSaida saidaParalela = GETDD2DparaleloSessoes(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Paralelo Sessoes\n\nValor do Keff = "
                        + QString::number(saidaParalela.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaParalela.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaParalela.Col; c++)
                  str.append(QString::number(saidaParalela.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaParalela.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaParalela.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes =  \t " + QString::number(saidaParalela.interacoes,'i', 0));
            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);



        }

    if(paraleloD == true){

            DadosSaida saidaParalela = GETDD2DparaleloDirecoes(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Paralelo Direções\n\nValor do Keff = "
                        + QString::number(saidaParalela.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaParalela.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaParalela.Col; c++)
                  str.append(QString::number(saidaParalela.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaParalela.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaParalela.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes =  \t " + QString::number(saidaParalela.interacoes,'i', 0));
            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);



        }

    if(paraTxSerial == true){

            DadosSaida saidaSerial = GETDD2Dserial(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Serial\n\nValor do Keff = "
                        + QString::number(saidaSerial.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaSerial.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaSerial.Col; c++)
                  str.append(QString::number(saidaSerial.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaSerial.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaSerial.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes = \t "+ QString::number(saidaSerial.interacoes,'i', 0));


            DadosSaida saidaParalela = GETDD2DparaleloTotal(dadosInterface);

            str.append("\n\nResultados da Simulação para a Versão de Código Paralelo\n\nValor do Keff = "
                       + QString::number(saidaParalela.keff,'e', 8)
                       +"\n\nTempos da Simulação para a Versão de Código Paralelo\nTempo total = \t\t"
                       + QString::number(saidaParalela.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaParalela.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes = \t" + QString::number(saidaParalela.interacoes,'i', 0)
                       +"\n\n\nA EFICIÊNCIA ALCANÇADA FOI DE\nTotal = \t"
                       + QString::number(100 * (saidaSerial.TempoTotal - saidaParalela.TempoTotal)/saidaSerial.TempoTotal,'f', 3)
                       + "%\nParcial = \t"
                       + QString::number(100 * (saidaSerial.TempoVarredura - saidaParalela.TempoVarredura)/saidaSerial.TempoVarredura,'f', 3) + "%");

            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);

        }

    if(paraDxSerial == true){

            DadosSaida saidaSerial = GETDD2Dserial(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Serial\n\nValor do Keff = "
                        + QString::number(saidaSerial.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaSerial.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaSerial.Col; c++)
                  str.append(QString::number(saidaSerial.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaSerial.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaSerial.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes =  \t" + QString::number(saidaSerial.interacoes,'i', 0));


            DadosSaida saidaParalela = GETDD2DparaleloDirecoes(dadosInterface);

            str.append("\n\nResultados da Simulação para a Versão de Código Paralelo\n\nValor do Keff = "
                       + QString::number(saidaParalela.keff,'e', 8)
                       +"\n\nTempos da Simulação para a Versão de Código Paralelo\nTempo total = \t\t"
                       + QString::number(saidaParalela.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t \t" + QString::number(saidaParalela.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes =  \t " +  QString::number(saidaParalela.interacoes,'i', 0)
                       +"\n\n\nA EFICIÊNCIA ALCANÇADA FOI DE\nTotal = \t"
                       + QString::number(100 * (saidaSerial.TempoTotal - saidaParalela.TempoTotal)/saidaSerial.TempoTotal,'f', 3)
                       + "%\nParcial = \t"
                       + QString::number(100 * (saidaSerial.TempoVarredura - saidaParalela.TempoVarredura)/saidaSerial.TempoVarredura,'f', 3) + "%");

            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);

        }

    if(paraSxSerial == true){

            DadosSaida saidaSerial = GETDD2Dserial(dadosInterface);
            QString str;
            str.append("Resultados da Simulação para a Versão de Código Serial\n\nValor do Keff = "
                        + QString::number(saidaSerial.keff,'e', 8) + "\n\nValor da Potência por Região\n");
            for(int l = saidaSerial.Lin - 1; l >= 0; l--)
            {
                for(int c = 0; c < saidaSerial.Col; c++)
                  str.append(QString::number(saidaSerial.Potencia[l][c],'e', 8)+"\t");
                str.append("\n");
            }
            str.append("\nTempo total = \t\t" + QString::number(saidaSerial.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaSerial.TempoVarredura,'f', 3)
                        + "\nTotal de interacoes = \t " + QString::number(saidaSerial.interacoes,'i', 0)
                       );


            DadosSaida saidaParalela = GETDD2DparaleloSessoes(dadosInterface);
            str.append("\n\nResultados da Simulação para a Versão de Código Paralelo\n\nValor do Keff = "
                       + QString::number(saidaParalela.keff,'e', 8)
                       +"\n\nTempos da Simulação para a Versão de Código Paralelo\nTempo total = \t\t"
                       + QString::number(saidaParalela.TempoTotal,'f', 3)
                       + "\nTempo de Varredura = \t" + QString::number(saidaParalela.TempoVarredura,'f', 3)
                       + "\nTotal de interacoes =  \t " +  QString::number(saidaParalela.interacoes,'i', 0)
                       +"\n\n\nA EFICIÊNCIA ALCANÇADA FOI DE\nTotal = \t"
                       + QString::number(100 * (saidaSerial.TempoTotal - saidaParalela.TempoTotal)/saidaSerial.TempoTotal,'f', 3)
                       + "%\nParcial = \t"
                       + QString::number(100 * (saidaSerial.TempoVarredura - saidaParalela.TempoVarredura)/saidaSerial.TempoVarredura,'f', 3) + "%");

            ui->txtSaida->setPlainText(str);
            ui->tabWidget->setCurrentWidget(ui->tab_2);



    }

    ui->exec->setStyleSheet("background-color:#25e31c;color:000;");
    ui->exec->setText("Executar");
    ui->exec->setEnabled(true);
}
