#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar señales y slots
    connect(ui->radioButton_fcfs, &QRadioButton::toggled, this, &MainWindow::onAlgorithmSelectionChanged);
    connect(ui->radioButton_sjf, &QRadioButton::toggled, this, &MainWindow::onAlgorithmSelectionChanged);
    connect(ui->radioButton_rr, &QRadioButton::toggled, this, &MainWindow::onAlgorithmSelectionChanged);
    connect(ui->radioButton_priority, &QRadioButton::toggled, this, &MainWindow::onAlgorithmSelectionChanged);
    connect(ui->pushButton_ejecutar, &QPushButton::clicked, this, &MainWindow::onExecuteButtonClicked);

    // Configurar tablas
    setupProcessTable();
    setupResultsTable();

    // Generar procesos aleatorios
    generateRandomProcesses();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupProcessTable()
{
    ui->tableWidget_procesos->setColumnCount(4);
    ui->tableWidget_procesos->setHorizontalHeaderLabels({"ID", "Llegada", "Ráfaga", "Prioridad"});
}

void MainWindow::setupResultsTable()
{
    ui->tableWidget_resultados->setColumnCount(4);
    ui->tableWidget_resultados->setHorizontalHeaderLabels({"ID", "Retorno", "Espera", "Respuesta"});
}

void MainWindow::generateRandomProcesses()
{
    process_generator generator;
    auto procesos = generator.generate_random_processes(10);

    ui->tableWidget_procesos->setRowCount(procesos.size());
    for (int i = 0; i < procesos.size(); ++i) {
        ui->tableWidget_procesos->setItem(i, 0, new QTableWidgetItem(QString::number(procesos[i].get_id())));
        ui->tableWidget_procesos->setItem(i, 1, new QTableWidgetItem(QString::number(procesos[i].get_arrival_time())));
        ui->tableWidget_procesos->setItem(i, 2, new QTableWidgetItem(QString::number(procesos[i].get_burst_time())));
        ui->tableWidget_procesos->setItem(i, 3, new QTableWidgetItem(QString::number(procesos[i].get_priority())));
    }
}

void MainWindow::onAlgorithmSelectionChanged()
{
    if (ui->radioButton_rr->isChecked()) {
        ui->stackedWidget_config->setCurrentIndex(0); // Configuración de Round Robin
    } else {
        ui->stackedWidget_config->setCurrentIndex(1); // Configuración de otros algoritmos
    }
}

void MainWindow::onExecuteButtonClicked()
{
    if (ui->radioButton_rr->isChecked()) {
        // Capturar el quantum
        bool ok;
        int quantum = ui->quantumInput->text().toInt(&ok);
        if (!ok || quantum <= 0) {
            QMessageBox::warning(this, "Error", "Ingrese un quantum válido.");
            return;
        }

        // Configurar Round Robin
        round_robin rr(quantum);
        for (int i = 0; i < ui->tableWidget_procesos->rowCount(); ++i) {
            int id = ui->tableWidget_procesos->item(i, 0)->text().toInt();
            int arrival = ui->tableWidget_procesos->item(i, 1)->text().toInt();
            int burst = ui->tableWidget_procesos->item(i, 2)->text().toInt();
            rr.add_process(process(id, arrival, burst, 0));
        }

        // Ejecutar el algoritmo
        rr.execute();

        // Mostrar resultados individuales
        const auto& procesos = rr.get_processes();
        ui->tableWidget_resultados->setRowCount(procesos.size());
        for (int i = 0; i < procesos.size(); ++i) {
            ui->tableWidget_resultados->setItem(i, 0, new QTableWidgetItem(QString::number(procesos[i].get_id())));
            ui->tableWidget_resultados->setItem(i, 1, new QTableWidgetItem(QString::number(procesos[i].get_turnaround_time())));
            ui->tableWidget_resultados->setItem(i, 2, new QTableWidgetItem(QString::number(procesos[i].get_waiting_time())));
            ui->tableWidget_resultados->setItem(i, 3, new QTableWidgetItem(QString::number(procesos[i].get_response_time())));
        }
    }
}