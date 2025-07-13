#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Центральный виджет
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Основной layout
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Горизонтальный layout для "Период" + SpinBox
    QHBoxLayout *inputLayout = new QHBoxLayout();

    QLabel *labeltext = new QLabel("Период");
    inputLayout->addWidget(labeltext);

    spinBox = new QSpinBox();
    spinBox->setRange(1, 100000);
    inputLayout->addWidget(spinBox);

    mainLayout->addLayout(inputLayout);

    // Метка вывода
    outputLabel = new QLabel("Введите период");
    mainLayout->addWidget(outputLabel);

    // Подключение сигнала
    connect(spinBox, &QSpinBox::valueChanged, this, &MainWindow::spinValueChanged);
}

void MainWindow::spinValueChanged() {
    int period = spinBox->value();
    outputLabel->setText("Текущий период: " + QString::number(period));
}
