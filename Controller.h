#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QObject>
#include <QFileDialog>

#include <MainWindow.h>
#include <DrawBoard.h>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();


private:
    void assignFolderPath();




    QString m_outputFolderPath;
    DrawBoard m_drawBoard;
    MainWindow m_mainWindow;

public Q_SLOTS:
    void sltSetOutputFolderPath();
    void sltSendParametersAndDraw(const QString& blockSize, const QString& blockNumber);


};

#endif // CONTROLLER_H
