#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "Core/algorithms/round_robin.h"
#include "Utils/process_generator.h"
#include "UI/results_display.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAlgorithmSelectionChanged(); // Cambiar configuración dinámica
    void onExecuteButtonClicked();      // Ejecutar el algoritmo

private:
    Ui::MainWindow *ui;

    // Métodos auxiliares
    void setupProcessTable();           // Configurar tabla de procesos
    void setupResultsTable();           // Configurar tabla de resultados
    void generateRandomProcesses();     // Generar procesos aleatorios
};

#endif // MAINWINDOW_H