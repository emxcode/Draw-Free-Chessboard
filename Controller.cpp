#include "Controller.h"

Controller::Controller()
{

    connect(&m_mainWindow, &MainWindow::sigSendParameters,
            this, &Controller::sltSendParametersAndDraw);

    connect(&m_mainWindow, &MainWindow::sigSetOutputFolderPath,
            this, &Controller::sltSetOutputFolderPath);

    m_mainWindow.show();
}

void Controller::assignFolderPath()
{
    m_outputFolderPath = QFileDialog::getExistingDirectory(nullptr, tr("Select Output Directory"), "");
    QDir directory(m_outputFolderPath);

    bool doesDirectoryExist = directory.exists();

    if(doesDirectoryExist == true)
    {
        m_mainWindow.unlockDarw();
        m_drawBoard.setOutPutFolder(m_outputFolderPath);
        m_mainWindow.setLablePath(m_outputFolderPath);
    }
}

void Controller::sltSetOutputFolderPath()
{
    assignFolderPath();
}

void Controller::sltSendParametersAndDraw(const QString &blockSize, const QString &blockNumber)
{
    m_drawBoard.setBlockNumber(blockNumber.toInt());
    m_drawBoard.setBlockSize(blockSize.toInt());
    m_drawBoard.drawChessBoard();
    m_mainWindow.throwMessage("Draw ChessBoard Completed succesfully");
}
