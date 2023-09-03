#include "DrawBoard.h"

DrawBoard::DrawBoard()
{

}


void DrawBoard::setOutPutFolder(const QString &outPutFolder)
{
    m_outPutFolder = outPutFolder;
}

void DrawBoard::drawChessBoard()
{
    int blockSize= m_blockSize;
    int imageSize=blockSize*m_blockNumber;
    cv::Mat chessBoard(imageSize,imageSize,CV_8UC3,cv::Scalar::all(0));
    unsigned char color=0;

    for (int i = 0; i < imageSize; i = i+blockSize)
    {
        color = ~color;

        for (int j = 0; j < imageSize; j = j+blockSize)
        {
            cv::Mat ROI=chessBoard(cv::Rect(i,j,blockSize,blockSize));
            ROI.setTo(cv::Scalar::all(color));
            color = ~color;
        }
    }

    std::string path = m_outPutFolder.toStdString();
    path += "/Chessboard.bmp";
    cv::imwrite(path, chessBoard);
}

void DrawBoard::setBlockSize(int blockSize)
{
    m_blockSize = blockSize;
}

void DrawBoard::setBlockNumber(int blockNumber)
{
    m_blockNumber = blockNumber;
}


