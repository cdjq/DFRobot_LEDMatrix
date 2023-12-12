/*!
 * @file DFRobot_LEDMatrix.cpp
 * @brief 这是DFRobot_LEDMatrix的方法实现文件
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version  V1.0
 * @date  2023-12-11
 * @url https://github.com/DFRobot/DFRobot_LEDMatrix
 */
#ifndef DFROBOT_LEDMATRIX_H
#define DFROBOT_LEDMATRIX_H
#include "Arduino.h"
#include "SPI.h"
#include "DFRobot_LEDMatrix_Font.h"


class DFRobot_LEDMatrix{
public:
    #define DECODE_MODE 0x09 ///<BCD编码配置
    #define INTENSITY 0x0A   ///<亮度寄存器
    #define SCAN_LIMIT 0x0B ///<扫描界限寄存器
    #define SHUTDOWN 0x0C   ///<关断模式寄存器
    #define DISPLAY_TEST 0x0F ///< 测试寄存器
    /**
     * @enum eImage_t
     * @brief 图标
     */
    typedef enum{
        eHeart,
        eSmallHeart,
        eYes,
        eNo,
        eHappy,
        eSad,
        eConfused,
        eAngry,
        eAsleep,
        eSurprised,
        eSilly,
        eFabulous,
        eMeh,
        eTShirt,
        eRollerskate,
        eDuck,
        eHouse,
        eTortoise,
        eButterfly,
        eStickFigure,
        eGhost,
        eSword,
        eGiraffe,
        eSkull,
        eUmbrella,
        eSnake,
        eRabbit,
        eCow,
        eQuarterNote,
        eEigthNote,
        ePitchfork,
        eTarget,
        eTriangle,
        eLeftTriangle,
        eChessboard,
        eDiamond,
        eSmallDiamond,
        eSquare,
        eSmallSquare,
        eScissors
    }eImage_t;
    /**
     * @fn DFRobot_LEDMatrix
     * @brief 构造函数
     * @param pspi  SPI对象
     * @param cs  CSy引脚
     * @return None 
     */
    DFRobot_LEDMatrix(SPIClass *pspi = &SPI,uint8_t cs = 4);
    /**
     * @fn begin
     * @brief 初始化模块
     * @param lum LED灯亮度,0~16
    */
    void begin(uint8_t lum);
    /**
     * @fn disPlay 
     * @brief 指定某一行那个灯点亮
     * @param line 行号 1~8
     * @param number 那个灯1~8
    */
    void disPlay(uint8_t line,uint8_t number);
    /**
     * @fn disPlay 
     * @brief 按矩阵中数据显示
     * @param numBuf 矩阵数据
    */
    void disPlay(byte *numBuf);
    /**
     * @fn disPlay 
     * @brief 用于滚动显示字符串
     * @param ch 需要显示的字符串
     * @param time 滚动速度 
    */
    void disPlay(const char* ch,uint16_t time);
    /**
     * @fn disPlay 
     * @brief 显示图标
     * @param image 图标
    */
    void disPlay(eImage_t image);
    /**
     * @fn disPlay 
     * @brief 清楚屏幕显示
    */
    void cleanDisPlay(void);
    
private:
void sendData(uint8_t address, uint8_t value);
void getBuf(uint8_t ascillValue,uint8_t* buf);
SPIClass *_pspi;
uint8_t _csPin;
};
#endif 
