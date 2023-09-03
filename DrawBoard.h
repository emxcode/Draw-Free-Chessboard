#ifndef DRAWBOARD_H
#define DRAWBOARD_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QString>
#include <QObject>
#include <string>
#include <iostream>
class DrawBoard : public QObject
{
    Q_OBJECT
public:
    DrawBoard();


    void setOutPutFolder(const QString &outPutFolder);
    void drawChessBoard();

    void setBlockSize(int blockSize);

    void setBlockNumber(int blockNumber);

private:
    QString m_outPutFolder;
    int m_blockSize;
    int m_blockNumber;

};

#endif // DRAWBOARD_H
