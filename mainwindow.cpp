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

        // Solo mostrar prioridades si el algoritmo seleccionado es el de prioridad
        if (ui->radioButton_priority->isChecked()) {
            ui->tableWidget_procesos->setItem(i, 3, new QTableWidgetItem(QString::number(procesos[i].get_priority())));
        } else {
            ui->tableWidget_procesos->setItem(i, 3, new QTableWidgetItem("-")); // Sin prioridad
        }
    }
}

void MainWindow::onAlgorithmSelectionChanged()
{
    if (ui->radioButton_priority->isChecked()) {
        ui->stackedWidget_config->setCurrentIndex(1); // Configuración de Prioridad
    } else if (ui->radioButton_rr->isChecked()) {
        ui->stackedWidget_config->setCurrentIndex(0); // Configuración de Round Robin
    } else {
        ui->stackedWidget_config->setCurrentIndex(2); // Configuración de otros algoritmos
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

        // Calcular y mostrar métricas
        double avg_turnaround = rr.get_avg_turnaround_time();
        double avg_waiting = rr.get_avg_waiting_time();
        double cpu_utilization = rr.get_cpu_utilization();

        updateMetrics(avg_turnaround, avg_waiting, cpu_utilization);
    }

    if (ui->radioButton_priority->isChecked()) {
        // Determinar si es con o sin desalojo
        bool preemptive = (ui->comboBox_prioridad->currentText() == "Con Desalojo");

        // Configurar el algoritmo de prioridad
        priority pr(preemptive);
        for (int i = 0; i < ui->tableWidget_procesos->rowCount(); ++i) {
            int id = ui->tableWidget_procesos->item(i, 0)->text().toInt();
            int arrival = ui->tableWidget_procesos->item(i, 1)->text().toInt();
            int burst = ui->tableWidget_procesos->item(i, 2)->text().toInt();
            int priority_value = ui->tableWidget_procesos->item(i, 3)->text().toInt();
            pr.add_process(process(id, arrival, burst, priority_value));
        }

        // Ejecutar el algoritmo
        pr.execute();

        // Mostrar resultados individuales
        const auto& procesos = pr.get_processes();
        ui->tableWidget_resultados->setRowCount(procesos.size());
        for (int i = 0; i < procesos.size(); ++i) {
            ui->tableWidget_resultados->setItem(i, 0, new QTableWidgetItem(QString::number(procesos[i].get_id())));
            ui->tableWidget_resultados->setItem(i, 1, new QTableWidgetItem(QString::number(procesos[i].get_turnaround_time())));
            ui->tableWidget_resultados->setItem(i, 2, new QTableWidgetItem(QString::number(procesos[i].get_waiting_time())));
            ui->tableWidget_resultados->setItem(i, 3, new QTableWidgetItem(QString::number(procesos[i].get_response_time())));
        }

        // Calcular y mostrar métricas
        double avg_turnaround = pr.get_avg_turnaround_time();
        double avg_waiting = pr.get_avg_waiting_time();
        double cpu_utilization = 100.0; // Para prioridad, asumimos 100% de utilización

        updateMetrics(avg_turnaround, avg_waiting, cpu_utilization);
    }
}

void MainWindow::updateMetrics(double avg_turnaround, double avg_waiting, double cpu_utilization)
{
    ui->label_avg_turnaround_time->setText("Tiempo promedio de retorno: " + QString::number(avg_turnaround));
    ui->label_avg_waiting_time->setText("Tiempo promedio de espera: " + QString::number(avg_waiting));
    ui->label_cpu_utilization->setText("Utilización de la CPU: " + QString::number(cpu_utilization) + "%");
}