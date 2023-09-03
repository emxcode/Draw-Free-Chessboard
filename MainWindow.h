#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setLablePath(const QString& path);
    void unlockDarw();
    void throwMessage(const QString& text);

private slots:



    void on_pushButtonSetPath_clicked();

    void on_pushButtonDraw_clicked();

    void on_pushButtonReset_clicked();

private:
    Ui::MainWindow *ui;

    void resetUi();


Q_SIGNALS:
    void sigSetOutputFolderPath();
    void sigSendParameters(const QString& blockSize, const QString& blockNumber);
};
#endif // MAINWINDOW_H
