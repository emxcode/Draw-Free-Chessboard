#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resetUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLablePath(const QString &path)
{
    ui->labelPath->clear();
    ui->labelPath->setText(path);
}

void MainWindow::unlockDarw()
{
    ui->lineEditBlockSize->setReadOnly(false);

    ui->lineEditBlockNumber->setReadOnly(false);

    ui->pushButtonDraw->setEnabled(true);

}

void MainWindow::throwMessage(const QString &text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setModal(true);
    msgBox.exec();
}




void MainWindow::on_pushButtonSetPath_clicked()
{
    Q_EMIT sigSetOutputFolderPath();
}

void MainWindow::on_pushButtonDraw_clicked()
{
    QString blockSize = ui->lineEditBlockSize->text();
    QString blockNumber = ui->lineEditBlockNumber->text();

    Q_EMIT sigSendParameters(blockSize, blockNumber);
}

void MainWindow::resetUi()
{
    ui->lineEditBlockSize->setText("0");
    ui->lineEditBlockSize->setReadOnly(true);

    ui->lineEditBlockNumber->setText("0");
    ui->lineEditBlockNumber->setReadOnly(true);

    ui->pushButtonDraw->setEnabled(false);
    ui->labelPath->setText("None");
}

void MainWindow::on_pushButtonReset_clicked()
{
    resetUi();
}
