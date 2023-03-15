#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Calcular();
    void on_validarinicial_clicked();

    void on_validarcontorno_clicked();

    void on_Validarreg_clicked();

     void on_actionabrir_triggered();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_validarfisao_clicked();

    void on_pushButton_3_clicked();

    void on_exec_clicked();

    void on_btn_abrirArquivo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
